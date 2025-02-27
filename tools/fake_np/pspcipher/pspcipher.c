/*
 * This file is part of pspcipher.
 *
 * Copyright (C) 2008 hrimfaxi (outmatch@gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <malloc.h>

#include "kirk_engine.h"
#include "pspcipher.h"

typedef struct {
	u32 tag;
	u8 *key;
	u8 *xor;
	u32 code;
	u32 type;
} Cipher;

//////////////////////////////////////////////////////////////////////////////////////////////////
// User keys in 6.20 mesg_led_02g.prx

u8 key_d91609f0[16] = {
	0xD0, 0x36, 0x12, 0x75, 0x80, 0x56, 0x20, 0x43, 0xC4, 0x30, 0x94, 0x3E, 0x1C, 0x75, 0xD1, 0xBF
};

u8 key_d91613f0[16] = {
	0xEB, 0xFF, 0x40, 0xD8, 0xB4, 0x1A, 0xE1, 0x66, 0x91, 0x3B, 0x8F, 0x64, 0xB6, 0xFC, 0xB7, 0x12 
};

u8 key_2e5e10f0[16] = {
	0x9D, 0x5C, 0x5B, 0xAF, 0x8C, 0xD8, 0x69, 0x7E, 0x51, 0x9F, 0x70, 0x96, 0xE6, 0xD5, 0xC4, 0xE8
};

u8 xor_2e5e10f0[16] = {
	0x69, 0xBA, 0x55, 0x34, 0xF0, 0xC0, 0xD6, 0x71, 0xE3, 0x1F, 0xDB, 0x97, 0xE0, 0x7C, 0xD2, 0x2A
};

u8 key_2e5e12f0[16] = {
	0x8A, 0x7B, 0xC9, 0xD6, 0x52, 0x58, 0x88, 0xEA, 0x51, 0x83, 0x60, 0xCA, 0x16, 0x79, 0xE2, 0x07
};

u8 key_d91612f0[16] = {
	0x9e, 0x20, 0xe1, 0xcd, 0xd7, 0x88, 0xde, 0xc0, 0x31, 0x9b, 0x10, 0xaf, 0xc5, 0xb8, 0x73, 0x23
};

u8 key_380210f0[16] = {
	0x32, 0x2C, 0xFA, 0x75, 0xE4, 0x7E, 0x93, 0xEB, 0x9F, 0x22, 0x80, 0x85, 0x57, 0x08, 0x98, 0x48
};

u8 key_407810f0[16] = {
	0xAF, 0xAD, 0xCA, 0xF1, 0x95, 0x59, 0x91, 0xEC, 0x1B, 0x27, 0xD0, 0x4E, 0x8A, 0xF3, 0x3D, 0xE7
};

u8 xor_407810f0[16] = {
	0x84, 0x7B, 0xF5, 0xFE, 0xE8, 0x4D, 0xAD, 0x7A, 0xB5, 0x06, 0x28, 0x0E, 0x09, 0xFA, 0x81, 0xE1
};

u8 data[16] = {
	0x3C, 0x2C, 0x58, 0x97, 0xA4, 0x3B, 0x45, 0x28, 0xCE, 0xF4, 0x17, 0x4E, 0x8B, 0x8D, 0xCD, 0x7C
};

u8 key_2fd312f0[16] = {
	0xC5, 0xFB, 0x69, 0x03, 0x20, 0x7A, 0xCF, 0xBA, 0x2C, 0x90, 0xF8, 0xB8, 0x4D, 0xD2, 0xF1, 0xDE
};

u8 key_2fd30bf0[16] = {
	0xD8, 0x58, 0x79, 0xF9, 0xA4, 0x22, 0xAF, 0x86, 0x90, 0xAC, 0xDA, 0x45, 0xCE, 0x60, 0x40, 0x3F
};

u8 key_2fd311f0[16] = {
	0x3A, 0x6B, 0x48, 0x96, 0x86, 0xA5, 0xC8, 0x80, 0x69, 0x6C, 0xE6, 0x4B, 0xF6, 0x04, 0x17, 0x44
};

u8 xor_2fd30bf0[16] = {
	0xA9, 0x1E, 0xDD, 0x7B, 0x09, 0xBB, 0x22, 0xB5, 0x9D, 0xA3, 0x30, 0x69, 0x13, 0x6E, 0x0E, 0xD8
};

u8 xor_2fd311f0[16] = {
	0xA9, 0x1E, 0xDD, 0x7B, 0x09, 0xBB, 0x22, 0xB5, 0x9D, 0xA3, 0x30, 0x69, 0x13, 0x6E, 0x0E, 0xD8
};

u8 xor_2fd312f0[16] = {
	0xA9, 0x1E, 0xDD, 0x7B, 0x09, 0xBB, 0x22, 0xB5, 0x9D, 0xA3, 0x30, 0x69, 0x13, 0x6E, 0x0E, 0xD8
};

u8 key_0b000000[16] = {
	0x0b, 0x01, 0x1c, 0xe7, 0x31, 0x15, 0x6b, 0x83, 0x3e, 0x26, 0x0d, 0xcc, 0x69, 0x36, 0x12, 0xcb
};

u8 key_4c941df0[16] = {
	0x1D, 0x13, 0xE9, 0x50, 0x04, 0x73, 0x3D, 0xD2, 0xE1, 0xDA, 0xB9, 0xC1, 0xE6, 0x7B, 0x25, 0xA7
};

u8 key_adf305f0[16] = {
	0x12, 0x99, 0x70, 0x5E, 0x24, 0x07, 0x6C, 0xD0, 0x2D, 0x06, 0xFE, 0x7E, 0xB3, 0x0C, 0x11, 0x26
};

Cipher g_cipher[] = {
	{ 0x4c941df0, key_4c941df0, NULL, 0x43, 2},
	{ 0x0b000000, key_0b000000, NULL, 0x4e, 0},
	{ 0x2fd30bf0, key_2fd30bf0, xor_2fd30bf0, 0x47, 5},
	{ 0x2fd312f0, key_2fd312f0, xor_2fd312f0, 0x47, 5},
	{ 0x2fd311f0, key_2fd311f0, xor_2fd311f0, 0x47, 5},
	{ 0x407810f0, key_407810f0, xor_407810f0, 0x6a, 5},
	{ 0x2e5e10f0, key_2e5e10f0, xor_2e5e10f0, 0x48, 5},
	{ 0x2e5e12f0, key_2e5e12f0, xor_2e5e10f0, 0x48, 5},
	{ 0x380210f0, key_380210f0, NULL, 0x5a, 2},
	{ 0xadf305f0, key_adf305f0, NULL, 0x60, 2},
	{ 0xd91612f0, key_d91612f0, NULL, 0x5d, 2},
	{ 0xd91613f0, key_d91613f0, NULL, 0x5d, 2},
	{ 0xd91609f0, key_d91609f0, NULL, 0x5d, 2},
};
//////////////////////////////////////////////////////////////////////////////////////////////////

extern int pspDecompress(const u8 *inbuf, u8 *outbuf, u32 outcapacity);

Cipher *GetCipherByTag(u32 tag)
{
	int i;

	for(i=0; i<sizeof(g_cipher) / sizeof(g_cipher[0]); ++i) {
		if (g_cipher[i].tag == tag)
			return &g_cipher[i];
	}

	return NULL;
}

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

void ErrorExit(int milisecs, char *fmt, ...)
{
	va_list list;
	char msg[256];	

	va_start(list, fmt);
	vsprintf(msg, fmt, list);
	va_end(list);

	printf(msg);
	
	exit(-1);	
}


void disp_info(char *fn, u8 *prx)
{
	char *modname = (char*)(prx + 0x0a);
	u32 dec_size = *(u32*)(prx+0xb0);
	u32 tag = *(u32*)(prx+0xd0);

	if (strrchr(fn, '/') != NULL) {
		fn = strrchr(fn, '/') + 1;
	}

	printf("%s modname(%s) dec_size(%d) tag(0x%08X)\n", fn, modname, dec_size, tag);
}

int dec(u32 tag, u8 *prx, u32 cbFile, char *szDataPath, u32 is_user)
{
	int ret; 
	u32 cbDecrypted = 0;
	u8 *dec_buf = NULL;

	if(is_user) {
		user_decryptor myb = { 0 };
		Cipher *cipher = GetCipherByTag(tag);

		if (cipher == NULL) {
			printf("Unknown key tag: 0x%08x\n", tag);
			goto exit;
		}

		myb.tag = &tag;
		myb.key = cipher->key;
		myb.code = cipher->code;
		myb.prx = prx;
		myb.size  = cbFile;
		myb.newsize = &cbDecrypted;
		myb.use_polling = 0;
		myb.blacklist = NULL;
		myb.blacklistsize = 0;
		myb.type = cipher->type;
		myb.xor_key1 = cipher->xor;
		myb.xor_key2 = NULL;
		ret = uprx_decrypt(&myb);

		if (ret != 0) {
			printf("uprx_decrypt failed@0x%08x(%d)\r\n", ret, ret);
			goto exit;
		}
	}
	else {
/*
		kernel_decryptor myb2 = { 0 };

		myb2.prx = prx;
		myb2.size = cbFile;
		myb2.newsize = &cbDecrypted;
		myb2.use_polling = 0;
		ret = kprx_decrypt(&myb2);

		if (ret != 0) {
			printf("kprx_decrypt failed@0x%08x(%d)\r\n", ret, ret);
			goto exit;
		} else {
			printf("kprx_decrypt OK!\n");
		}
*/
	}

//	ret = CipherBridgeDecrypt(&myb);
//	ret = CipherBridge_0A443BB4(prx, cbFile, &cbDecrypted, data);

	if ((prx[0] == 0x1F && prx[1] == 0x8B) || memcmp(prx, "2RLZ", 4) == 0 || memcmp(prx, "KL4E", 4) == 0) {
		printf("Decompress not implenment!\n");
#if 0
		u32 moresize = 2 * 1024 * 1024L;
		int cbExp; 

		dec_buf = memalign(64, cbDecrypted + moresize);

		if (dec_buf == NULL) {
			printf("Cannot allocate dec_buf\n");
			goto exit;
		}

		cbExp = pspDecompress(prx, dec_buf, cbDecrypted + moresize);

		while (cbExp < 0) {
			free(dec_buf);
			printf("too small memory, increase 1MB...\n");
			moresize += 1024 * 1024L;
			dec_buf = memalign(64, cbDecrypted + moresize);

			if (dec_buf == NULL) {
				printf("Cannot allocate dec_buf\n");
				goto exit;
			}

			cbExp = pspDecompress(prx, dec_buf, cbDecrypted + moresize);
		}

		if (cbExp > 0) {
			prx = dec_buf;
			cbDecrypted = cbExp;
		}
		else
		{
			printf("Decompress error 0x%08X\n", cbExp);
			goto exit;
		}
#endif
	}

	if (cbDecrypted > 0)
	{
		printf("Writing %d bytes\r\n", cbDecrypted);

		mkdir("dec");

		if (WriteFile(szDataPath, prx, cbDecrypted) != cbDecrypted)
		{
			ErrorExit(5000, "Error writing %s.\n", szDataPath);
		}

		printf("Decryption saved to %s!\r\n", szDataPath);
	} else {
		printf("Decryption failed\r\n");
	}

exit:
	if (dec_buf)
		free(dec_buf);

	return 0;
}

int main(int argc, char *argv[])
{
	int fd;
	u8 *prx_file = NULL, *prx = NULL;
	char fn[128];
	char szDataPath[128];
	
    printf("PSPCipher by liquidzigong@a9vg.com\n");

	if (argc >= 2) {
		sprintf(fn, "%s", argv[1]);

		if (strrchr(argv[1], '/')) {
			sprintf(szDataPath, "dec/%s", strrchr(argv[1], '/') + 1);
		} else {
			sprintf(szDataPath, "dec/%s", argv[1]);
		}
	} else {
		sprintf(fn, "enc/%s", "EBOOT.BIN");
		sprintf(szDataPath, "dec/%s", "EBOOT.BIN");
	}

	fd = open(fn, O_RDONLY);
	if(fd<0){
		printf("open %s failed!\n", fn);
		return -1;
	}
	
	int cbFile = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);

	prx_file = malloc(cbFile * 2);

	if (prx_file == NULL) {
		ErrorExit(5000, "Not enough memory\n");
	}

	if (read(fd, prx_file, cbFile) <= 0)
	{
		ErrorExit(5000, "Error Reading EBOOT.BIN.\n");
	}

	close(fd);
	
	if (!memcmp(prx_file, "~SCE", 4)) {
		prx = prx_file + 0x40;
	} else if (!memcmp(prx_file, "\x00PSPEDATA", 8)) {
		prx = prx_file;
		memmove(prx, prx + 0x90, cbFile - 0x90);
	} else {
		prx = prx_file;
	}

	disp_info(fn, prx);
	dec(*(u32*)(prx+0xd0), prx, cbFile, szDataPath, 1);

//exit:
	if (prx_file)
		free(prx_file);

    return 0;
}

