
/*
 *  sign_eboot.c  -- sign your prx use game tag
 *                   writen by tpu.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kirk_engine.h"
#include "psp_headers.h"


/*************************************************************/

int WriteFile(const char *file, void *buf, int size)
{
	FILE *fp;
	int written;

	fp = fopen(file, "wb");
	if(fp==NULL)
		return -1;
	written = fwrite(buf, 1, size, fp);
	fclose(fp);

	return written;
}

void hex_dump(char *str, u8 *buf, int size)
{
	int i;

	if(str)
		printf("%s:", str);

	for(i=0; i<size; i++){
		if((i%16)==0){
			printf("\n%4x:", i);
		}
		printf(" %02x", buf[i]);
	}
	printf("\n\n");
}


void dump_psp_header(PSP_Header2 *h)
{
	int i;

	printf("       sig: %08x\n", h->signature);
	printf("  mod_attr: %04x\n", h->mod_attribute);
	printf(" comp_attr: %04x\n", h->comp_attribute);
	printf(" modver_lo: %02x\n", h->module_ver_lo);
	printf(" modver_hi: %02x\n", h->module_ver_hi);
	printf("   modname: %s\n"  , h->modname);
	printf("modversion: %02x\n", h->mod_version);
	printf("  segments: %02x\n", h->nsegments);
	printf("  elf_size: %08x\n", h->elf_size);
	printf(" file_size: %08x\n", h->psp_size);
	printf("boot_entry: %08x\n", h->boot_entry);
	printf("modinfo_pt: %08x\n", h->modinfo_offset);
	printf("  bss_size: %08x\n", h->bss_size);
	for(i=0; i<4; i++){
		printf("    seg[%d]: align %04x  addr %08x  size %08x\n", i, h->seg_align[i], h->seg_address[i], h->seg_size[i]);
	}

	printf("  devkit_ver: %08x\n", h->devkit_version);
	printf("decrypt_mode: %02x\n", h->decrypt_mode);
	printf("     padding: %02x\n", h->padding);
	printf("overlap_size: %04x\n", h->overlap_size);

}

/*************************************************************/

char *strtable;
int e_shnum;
Elf32_Shdr *section;

Elf32_Shdr *find_section(char *name)
{
	int i;

	for(i=0; i<e_shnum; i++){
		if(strcmp(name, strtable+section[i].sh_name)==0)
			return &section[i];
	}

	return NULL;
}

void fix_reloc7(u8 *ebuf)
{
	Elf32_Rel *rel;
	int i, j, count;

	count = 0;
	for(i=0; i<e_shnum; i++){
		if(section[i].sh_type==0x700000A0){
			rel = (Elf32_Rel*)(ebuf+section[i].sh_offset);
			for(j=0; j<section[i].sh_size/sizeof(Elf32_Rel); j++){
				if((rel[j].r_info&0xFF)==7){
					rel[j].r_info = 0;
					count++;
				}
			}
		}
	}
}


void build_psp_header(PSP_Header2 *psph, u8 *ebuf, int esize)
{
	Elf32_Ehdr *elf;
	Elf32_Shdr *sh;
	Elf32_Phdr *ph;
	SceModuleInfo *modinfo;
	int i;

	elf = (Elf32_Ehdr*)(ebuf);
	section = (Elf32_Shdr *)(ebuf+elf->e_shoff);
	e_shnum = elf->e_shnum;
	strtable = (char*)(ebuf+section[elf->e_shstrndx].sh_offset);

	fix_reloc7(ebuf);

	memset(psph, 0, sizeof(PSP_Header2));

	psph->signature = 0x5053507E;
	psph->mod_attribute = 0;
	psph->comp_attribute = 0;
	psph->module_ver_lo = 1;
	psph->module_ver_hi = 1;
	psph->mod_version = 1;
	psph->devkit_version = 0x06020010;
	psph->decrypt_mode = 9;
	psph->overlap_size = 0;

	psph->comp_size = esize;
	psph->_80 = 0x80;

	psph->nsegments = elf->e_phnum;
	psph->boot_entry = elf->e_entry;
	psph->elf_size = esize;
	psph->psp_size = ((esize+15)&0xfffffff0)+0x150;

	sh = find_section(".bss");
	if(sh==NULL){
		printf("Cannot find .bss!\n");
		exit(-1);
	}
	psph->bss_size = sh->sh_size;

	sh = find_section(".rodata.sceModuleInfo");
	if(sh==NULL){
		printf("Cannot find .rodata.sceModuleInfo!\n");
		exit(-1);
	}
	modinfo = (SceModuleInfo*)(ebuf+sh->sh_offset);
	psph->modinfo_offset = sh->sh_offset;
	strcpy(psph->modname, modinfo->modname);

	ph = (Elf32_Phdr*)(ebuf+elf->e_phoff);
	for(i=0; i<elf->e_phnum; i++){
		psph->seg_align[i]   = ph[i].p_align;
		psph->seg_address[i] = ph[i].p_vaddr;
		psph->seg_size[i]    = ph[i].p_memsz;
	}

}

/*************************************************************/

typedef struct {
	u32 tag;
	u8  key[16];
	u32 code;
	u32 type;
}TAG_KEY;

TAG_KEY key_d91613f0 = {
	0xd91613f0,	{0xEB, 0xFF, 0x40, 0xD8, 0xB4, 0x1A, 0xE1, 0x66, 0x91, 0x3B, 0x8F, 0x64, 0xB6, 0xFC, 0xB7, 0x12}, 0x5d,	2,
};

TAG_KEY key_d91609f0 = {
	0xd91609f0,	{0xD0, 0x36, 0x12, 0x75, 0x80, 0x56, 0x20, 0x43, 0xC4, 0x30, 0x94, 0x3E, 0x1C, 0x75, 0xD1, 0xBF}, 0x5d,	2,
};


u8 tag_key[0x100];
int tag_code;
int tag_value;

void build_tag_key(TAG_KEY *tk)
{
	int i;
	u32 *k7 = (u32*)tag_key;

	tag_code = tk->code;
	tag_value = tk->tag;

	for(i=0; i<9; i++){
		memcpy(tag_key+0x14+(i*16), tk->key, 0x10);
		tag_key[0x14+(i*16)] = i;
	}

	k7[0] = KIRK_MODE_DECRYPT_CBC;
	k7[1] = 0;
	k7[2] = 0;
	k7[3] = tk->code;
	k7[4] = 0x90;

	kirk_CMD7(tag_key, tag_key, 0x90+0x14);
	//hex_dump("tag_keys", tag_key, 0x100);

}

/*************************************************************/

u8 test_kirk1[32] = {
	0xca, 0x03, 0x84, 0xb1, 0xd9, 0x63, 0x47, 0x92, 0xce, 0xc7, 0x01, 0x23, 0x43, 0x72, 0x68, 0xac,
	0x77, 0xea, 0xec, 0xba, 0x6d, 0xaa, 0x97, 0xdf, 0xfe, 0x91, 0xb9, 0x39, 0x70, 0x99, 0x8b, 0x3a,
};

void build_psp_kirk1(u8 *kbuf, u8 *pbuf, int esize)
{
	KIRK_CMD1_HEADER *k1 = (KIRK_CMD1_HEADER *)kbuf;
	int i;

	memcpy(kbuf, test_kirk1, 32);

	k1->mode = KIRK_MODE_CMD1;
	k1->data_size = esize;
	k1->data_offset = 0x80;
	memcpy(kbuf+0x90, pbuf, 0x80);

	if(esize%16){
		for(i=0; i<(16-(esize%16)); i++){
			kbuf[0x110+esize+i] = 0xFF-i*0x11;
		}
	}

	kirk_CMD0(kbuf, kbuf, esize);
	//hex_dump("after kirk0", kbuf, 0x200);

}

u8 test_k140[16] = {
	0x35, 0xfe, 0x4c, 0x96, 0x00, 0xb2, 0xf6, 0x7e, 0xf5, 0x83, 0xa6, 0x79, 0x1f, 0xa0, 0xe8, 0x86,
};

void build_psp_SHA1(u8 *ebuf, u8 *pbuf)
{
	u8 tmp[0x150];
	u32 *k4 = (u32*)tmp;
	int i;

	memset(tmp, 0, 0x150);

	for(i=0; i<0x40; i++){
		tmp[0x14+i] = ebuf[0x40+i]^tag_key[0x50+i];
	}
	memcpy(tmp+0xd0, pbuf, 0x80);
	//hex_dump("xor from:", tmp+0x14, 0x40);

	k4[0] = KIRK_MODE_ENCRYPT_CBC;
	k4[1] = 0;
	k4[2] = 0;
	k4[3] = tag_code;
	k4[4] = 0x40;
	kirk_CMD4(tmp+0x80-0x14, tmp, 0x40+0x14);
	//hex_dump("kirk4:", tmp, 0x100);

	for(i=0; i<0x40; i++){
		tmp[0x80+i] ^=  tag_key[0x10+i];
	}

	memcpy(tmp+0xd0, pbuf, 0x80);
	memcpy(tmp+0xc0, pbuf+0xb0, 0x10);
	memcpy(tmp+0x70, test_k140, 0x10);
	memset(tmp, 0, 0x70);
	memcpy(tmp+0x08, tag_key, 0x10);
	k4[0] = 0x014c;
	k4[1] = tag_value;

	//hex_dump("before SHA1:", tmp, 0x150);
	kirk_CMD11(tmp, tmp, 0x150);
	//hex_dump("after SHA1:", tmp, 0x150);


	memcpy(tmp+0x5c, test_k140, 0x10);
	memcpy(tmp+0x6c, tmp, 0x14);


	k4 = (u32*)(tmp+0x48);
	k4[0] = KIRK_MODE_ENCRYPT_CBC;
	k4[1] = 0;
	k4[2] = 0;
	k4[3] = tag_code;
	k4[4] = 0x60;
	kirk_CMD4(tmp+0x5c-0x14, tmp+0x48, 0x60+0x14);

	memset(tmp, 0, 0x5c);
	k4 = (u32*)tmp;
	k4[0] = tag_value;

	//hex_dump("reorder:", tmp, 0x150);

	memcpy(ebuf+0x000, tmp+0xd0, 0x80);
	memcpy(ebuf+0x080, tmp+0x80, 0x30);
	memcpy(ebuf+0x0b0, tmp+0xc0, 0x10);
	memcpy(ebuf+0x0c0, tmp+0xb0, 0x10);
	memcpy(ebuf+0x0d0, tmp+0x00, 0x5c);
	memcpy(ebuf+0x12c, tmp+0x6c, 0x14);
	memcpy(ebuf+0x140, tmp+0x5c, 0x10);

	//hex_dump("PSP header:", ebuf, 0x150);
}

/*************************************************************/



PSP_Header2 psp_header;


int main(int argc, char *argv[])
{
	FILE *fp;
	u8 *ebuf;
	int esize;

	fp = fopen(argv[1], "rb");
	if(fp==NULL){
		printf("Open file %s failed!\n", argv[1]);
		exit(-1);
	}
	fseek(fp, 0, SEEK_END);
	esize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	ebuf = malloc(esize+4096);
	memset(ebuf, 0, esize+4096);

	fread(ebuf+0x150, esize, 1, fp);
	fclose(fp);

	if(*(u32*)(ebuf+0x150)!=0x464c457f){
		printf("%s: not a ELF file.\n", argv[1]);
		return -1;
	}

	printf("Load %s ...\n", argv[1]);

	build_psp_header(&psp_header, ebuf+0x150, esize);

	build_psp_kirk1(ebuf+0x40, (u8*)&psp_header, esize);

	build_tag_key(&key_d91613f0);

	build_psp_SHA1(ebuf, (u8*)&psp_header);

	esize = (esize+15)&~15;

	WriteFile(argv[1], ebuf, esize+0x150);
	printf("Save %s .\n", argv[1]);

	return 0;
}

