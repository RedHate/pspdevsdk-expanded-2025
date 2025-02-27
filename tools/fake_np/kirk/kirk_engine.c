/* 
	KIRK ENGINE CODE
	Thx for kgsws, Mathieulh, SilverSpring, Davee
*/
#include <openssl/aes.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include "kirk_engine.h"
#include "cmac.h"

/* ------------------------- KEY VAULT ------------------------- */

u8 kirk1_key[] =   {0x98, 0xC9, 0x40, 0x97, 0x5C, 0x1D, 0x10, 0xE8, 0x7F, 0xE6, 0x0E, 0xA3, 0xFD, 0x03, 0xA8, 0xBA};

u8 kirk7_key03[] = {0x98, 0x02, 0xC4, 0xE6, 0xEC, 0x9E, 0x9E, 0x2F, 0xFC, 0x63, 0x4C, 0xE4, 0x2F, 0xBB, 0x46, 0x68};
u8 kirk7_key04[] = {0x99, 0x24, 0x4C, 0xD2, 0x58, 0xF5, 0x1B, 0xCB, 0xB0, 0x61, 0x9C, 0xA7, 0x38, 0x30, 0x07, 0x5F};
u8 kirk7_key05[] = {0x02, 0x25, 0xD7, 0xBA, 0x63, 0xEC, 0xB9, 0x4A, 0x9D, 0x23, 0x76, 0x01, 0xB3, 0xF6, 0xAC, 0x17};
u8 kirk7_key0C[] = {0x84, 0x85, 0xC8, 0x48, 0x75, 0x08, 0x43, 0xBC, 0x9B, 0x9A, 0xEC, 0xA7, 0x9C, 0x7F, 0x60, 0x18};
u8 kirk7_key0D[] = {0xB5, 0xB1, 0x6E, 0xDE, 0x23, 0xA9, 0x7B, 0x0E, 0xA1, 0x7C, 0xDB, 0xA2, 0xDC, 0xDE, 0xC4, 0x6E};
u8 kirk7_key0E[] = {0xC8, 0x71, 0xFD, 0xB3, 0xBC, 0xC5, 0xD2, 0xF2, 0xE2, 0xD7, 0x72, 0x9D, 0xDF, 0x82, 0x68, 0x82};
u8 kirk7_key0F[] = {0x0A, 0xBB, 0x33, 0x6C, 0x96, 0xD4, 0xCD, 0xD8, 0xCB, 0x5F, 0x4B, 0xE0, 0xBA, 0xDB, 0x9E, 0x03};
u8 kirk7_key10[] = {0x32, 0x29, 0x5B, 0xD5, 0xEA, 0xF7, 0xA3, 0x42, 0x16, 0xC8, 0x8E, 0x48, 0xFF, 0x50, 0xD3, 0x71};
u8 kirk7_key11[] = {0x46, 0xF2, 0x5E, 0x8E, 0x4D, 0x2A, 0xA5, 0x40, 0x73, 0x0B, 0xC4, 0x6E, 0x47, 0xEE, 0x6F, 0x0A};
u8 kirk7_key12[] = {0x5D, 0xC7, 0x11, 0x39, 0xD0, 0x19, 0x38, 0xBC, 0x02, 0x7F, 0xDD, 0xDC, 0xB0, 0x83, 0x7D, 0x9D};
u8 kirk7_key38[] = {0x12, 0x46, 0x8D, 0x7E, 0x1C, 0x42, 0x20, 0x9B, 0xBA, 0x54, 0x26, 0x83, 0x5E, 0xB0, 0x33, 0x03}; // BBMac type 2
u8 kirk7_key39[] = {0xC4, 0x3B, 0xB6, 0xD6, 0x53, 0xEE, 0x67, 0x49, 0x3E, 0xA9, 0x5F, 0xBC, 0x0C, 0xED, 0x6F, 0x8A};
u8 kirk7_key3A[] = {0x2C, 0xC3, 0xCF, 0x8C, 0x28, 0x78, 0xA5, 0xA6, 0x63, 0xE2, 0xAF, 0x2D, 0x71, 0x5E, 0x86, 0xBA}; // BBMac type 3
u8 kirk7_key4B[] = {0x0C, 0xFD, 0x67, 0x9A, 0xF9, 0xB4, 0x72, 0x4F, 0xD7, 0x8D, 0xD6, 0xE9, 0x96, 0x42, 0x28, 0x8B}; // 1.xx game eboot.bin
u8 kirk7_key53[] = {0xAF, 0xFE, 0x8E, 0xB1, 0x3D, 0xD1, 0x7E, 0xD8, 0x0A, 0x61, 0x24, 0x1C, 0x95, 0x92, 0x56, 0xB6};
u8 kirk7_key57[] = {0x1C, 0x9B, 0xC4, 0x90, 0xE3, 0x06, 0x64, 0x81, 0xFA, 0x59, 0xFD, 0xB6, 0x00, 0xBB, 0x28, 0x70};
u8 kirk7_key5D[] = {0x11, 0x5A, 0x5D, 0x20, 0xD5, 0x3A, 0x8D, 0xD3, 0x9C, 0xC5, 0xAF, 0x41, 0x0F, 0x0F, 0x18, 0x6F};
u8 kirk7_key63[] = {0x9C, 0x9B, 0x13, 0x72, 0xF8, 0xC6, 0x40, 0xCF, 0x1C, 0x62, 0xF5, 0xD5, 0x92, 0xDD, 0xB5, 0x82}; // BBMac result for type 3
u8 kirk7_key64[] = {0x03, 0xB3, 0x02, 0xE8, 0x5F, 0xF3, 0x81, 0xB1, 0x3B, 0x8D, 0xAA, 0x2A, 0x90, 0xFF, 0x5E, 0x61};



// Spock cmd 0x09 (Spock's "Master key"): 
u8 spock_key09[] = {0x9F, 0x46, 0xF9, 0xFC, 0xFA, 0xB2, 0xAD, 0x05, 0x69, 0xF6, 0x88, 0xD8, 0x79, 0x4B, 0x92, 0xBA};

// Kirk cmd 0x11 key: 
u8 kirk11_key0[] = {0x47, 0x5E, 0x09, 0xF4, 0xA2, 0x37, 0xDA, 0x9B, 0xEF, 0xFF, 0x3B, 0xC0, 0x77, 0x14, 0x3D, 0x8A};


// Kirk cmd 0x12 ECDSA PUB Keys (likely as they are yet to be tested): 
u8 kirk12_keys[] = {
    // certSig0
    0x40, 0x04, 0xC8, 0x0B, 0xD9, 0xC8, 0xBA, 0x38,
    0x22, 0x10, 0x65, 0x92, 0x3E, 0x32, 0x4B, 0x5F,
    0x0E, 0xC1, 0x65, 0xED, 0x6C, 0xFF, 0x7D, 0x9F,
    0x2C, 0x42, 0x0B, 0x84, 0xDF, 0xDA, 0x6E, 0x96,
    0xC0, 0xAE, 0xE2, 0x99, 0x27, 0xBC, 0xAF, 0x1E,
     
    // certSig1
    0x06, 0x48, 0x5F, 0xD0, 0x29, 0x85, 0x3B, 0x55,
    0x2F, 0x7E, 0xFD, 0xD6, 0x7A, 0x2D, 0xE7, 0xA1,
    0xA4, 0xE2, 0x55, 0x37, 0xB2, 0x45, 0x9D, 0x87,
    0x86, 0x42, 0x6D, 0x5B, 0x27, 0xEF, 0xA5, 0xA9,
    0x31, 0x1C, 0xB8, 0xAB, 0xAB, 0xFA, 0x0E, 0xCE,

    // certSig2
    0x3F, 0x8C, 0x34, 0xF2, 0x10, 0xAE, 0xC4, 0x8E,
    0x15, 0x20, 0xFF, 0x2A, 0x44, 0x89, 0x9E, 0x05,
    0x4A, 0x0D, 0xA3, 0x3D, 0xF8, 0xB9, 0x75, 0x4B,
    0x09, 0xC0, 0xEC, 0x7E, 0x61, 0x86, 0x7A, 0x51,
    0x26, 0xFE, 0x69, 0x26, 0x97, 0x21, 0x96, 0xF5,
    
    // certSig3
    0xCC, 0xB3, 0x44, 0x0D, 0xC4, 0x83, 0x6D, 0xD5,
    0x19, 0xE1, 0x3B, 0x28, 0x05, 0xB3, 0x08, 0x70,
    0xDC, 0xAE, 0xE4, 0x62, 0x13, 0x6B, 0x38, 0x88,
    0x65, 0x1A, 0x98, 0xE0, 0x2B, 0x29, 0xFA, 0x0C,
    0xD3, 0x4F, 0x16, 0x16, 0xF1, 0xED, 0x57, 0x86,
    
    // certSig4
    0x08, 0xB3, 0x36, 0x92, 0x5C, 0x2B, 0x44, 0x5D,
    0x03, 0xA9, 0xBE, 0x51, 0xB9, 0xAA, 0xBF, 0x54,
    0xE4, 0xCC, 0x14, 0x2E, 0xA7, 0x2A, 0x23, 0xBB,
    0x80, 0x60, 0xB0, 0x3B, 0x71, 0xCD, 0xE0, 0x77,
    0x2D, 0xE8, 0x2A, 0xD8, 0x93, 0x16, 0x48, 0xD6,
    
    // certSig5
    0x4F, 0x0A, 0x2B, 0xC9, 0x98, 0x76, 0x40, 0x86,
    0x0E, 0x22, 0xEE, 0x5D, 0x86, 0x08, 0x7C, 0x96,
    0x92, 0x47, 0x0B, 0xDF, 0x59, 0xDC, 0x4C, 0x1F,
    0x2E, 0x38, 0xF9, 0x2C, 0xE7, 0xB6, 0x68, 0x75,
    0xB5, 0x9E, 0xD1, 0x0C, 0x9D, 0x84, 0xFA, 0x6A,
};






/* ------------------------- KEY VAULT END ------------------------- */

/* ------------------------- INTERNAL STUFF ------------------------- */

typedef struct header_keys
{
    u8 AES[16];
    u8 CMAC[16];
}header_keys;  //small struct for temporary keeping AES & CMAC key from CMD1 header

u8 fuseID[16]; //Emulate FUSEID	

u8 ivec[16]; //IV always 0 for all commands

AES_KEY aes_kirk1; //global

/* ------------------------- INTERNAL STUFF END ------------------------- */



/* ------------------------- IMPLEMENTATION ------------------------- */

int kirk_CMD0(void* outbuff, void* inbuff, int size)
{
	KIRK_CMD1_HEADER* header = (KIRK_CMD1_HEADER*)outbuff;
	int chk_size;

	memcpy(outbuff, inbuff, sizeof(KIRK_CMD1_HEADER));
	if(header->mode != KIRK_MODE_CMD1)
		return KIRK_INVALID_MODE;

	header_keys *keys = (header_keys *)outbuff; //0-15 AES key, 16-31 CMAC key

	//ENCRYPT DATA
	chk_size = header->data_size;
	if(chk_size % 16) chk_size += 16 - (chk_size % 16);

	AES_KEY k1;
	AES_set_encrypt_key(keys->AES, 128, &k1);
	memset(ivec, 0, sizeof(ivec));
	AES_cbc_encrypt(inbuff+0x90+header->data_offset, outbuff+0x90+header->data_offset, chk_size, &k1, ivec, AES_ENCRYPT);

	//CMAC HASHES
	u8 cmac_header_hash[16];
	u8 cmac_data_hash[16];

	AES_CMAC(keys->CMAC, outbuff+0x60, 0x30, cmac_header_hash);

	//Make sure data is 16 aligned
	chk_size = header->data_size;
	if(chk_size % 16) chk_size += 16 - (chk_size % 16);
	chk_size += 0x30+header->data_offset;

	AES_CMAC(keys->CMAC, outbuff+0x60, chk_size, cmac_data_hash);

	memcpy(header->CMAC_header_hash, cmac_header_hash, 16);
	memcpy(header->CMAC_data_hash, cmac_data_hash, 16);
	
	//ENCRYPT KEYS
	AES_set_encrypt_key(kirk1_key, 128, &aes_kirk1);
	memset(ivec, 0, sizeof(ivec));
	AES_cbc_encrypt(inbuff, outbuff, 16*2,  &aes_kirk1, ivec, AES_ENCRYPT); //decrypt AES & CMAC key to temp buffer
	return KIRK_OPERATION_SUCCESS;
}

int kirk_CMD1(void* outbuff, void* inbuff, int size)
{
    KIRK_CMD1_HEADER* header = (KIRK_CMD1_HEADER*)inbuff;
	if(header->mode != KIRK_MODE_CMD1) return KIRK_INVALID_MODE;
	
	header_keys keys; //0-15 AES key, 16-31 CMAC key

	memset(ivec, 0, sizeof(ivec));
	AES_set_decrypt_key(kirk1_key, 128, &aes_kirk1);
	AES_cbc_encrypt(inbuff, (u8*)&keys, 16*2, &aes_kirk1, ivec, AES_DECRYPT); //decrypt AES & CMAC key to temp buffer
	
    int ret = kirk_CMD10(inbuff, size);
    if(ret != KIRK_OPERATION_SUCCESS) return ret;
	
	AES_KEY k1;
	AES_set_decrypt_key(keys.AES, 128, &k1);
	
	memset(ivec, 0, sizeof(ivec));
	AES_cbc_encrypt(inbuff+sizeof(KIRK_CMD1_HEADER)+header->data_offset, outbuff, header->data_size, &k1, ivec, AES_DECRYPT);	
	
	return KIRK_OPERATION_SUCCESS;
}

int kirk_CMD4(void* outbuff, void* inbuff, int size)
{
	AES_KEY aesKey;
	KIRK_AES128CBC_HEADER *header;
	u8 *key;

	header = (KIRK_AES128CBC_HEADER*)inbuff;
	if(header->mode != KIRK_MODE_ENCRYPT_CBC)
		return KIRK_INVALID_MODE;
	if(header->data_size == 0)
		return KIRK_DATA_SIZE_ZERO;

	key = kirk_4_7_get_key(header->keyseed);
	if(key == NULL)
		return KIRK_INVALID_SIZE;

	memset(ivec, 0, sizeof(ivec));
	AES_set_encrypt_key(key, 128, &aesKey);
	AES_cbc_encrypt(inbuff+0x14, outbuff+0x14, header->data_size, &aesKey, ivec, AES_ENCRYPT);
	memcpy(outbuff, inbuff, 0x14);
	*(u32*)outbuff = KIRK_MODE_DECRYPT_CBC;

	return KIRK_OPERATION_SUCCESS;
}

int kirk_CMD7(void* outbuff, void* inbuff, int size)
{
	AES_KEY aesKey;
	KIRK_AES128CBC_HEADER *header;
	u8 *key;

	header = (KIRK_AES128CBC_HEADER*)inbuff;
	if(header->mode != KIRK_MODE_DECRYPT_CBC)
		return KIRK_INVALID_MODE;
	if(header->data_size == 0)
		return KIRK_DATA_SIZE_ZERO;

	key = kirk_4_7_get_key(header->keyseed);
	if(key == NULL)
		return KIRK_INVALID_SIZE;

	memset(ivec, 0, sizeof(ivec));
	AES_set_decrypt_key(key, 128, &aesKey);
	AES_cbc_encrypt(inbuff+0x14, outbuff, header->data_size, &aesKey, ivec, AES_DECRYPT);

	return KIRK_OPERATION_SUCCESS;
}

int kirk_CMD10(void* inbuff, int insize)
{
	header_keys keys; //0-15 AES key, 16-31 CMAC key
	KIRK_CMD1_HEADER *header;
	u8 cmac_header_hash[16];
	u8 cmac_data_hash[16];
	int chk_size;

	header = (KIRK_CMD1_HEADER*)inbuff;
	if(!(header->mode == KIRK_MODE_CMD1 || header->mode == KIRK_MODE_CMD2 || header->mode == KIRK_MODE_CMD3))
		return KIRK_INVALID_MODE;
	if(header->data_size == 0)
		return KIRK_DATA_SIZE_ZERO;

	if(header->mode == KIRK_MODE_CMD1){
		memset(ivec, 0, sizeof(ivec));
		AES_set_decrypt_key(kirk1_key, 128, &aes_kirk1);
        AES_cbc_encrypt(inbuff, (u8*)&keys, 32, &aes_kirk1, ivec, AES_DECRYPT); //decrypt AES & CMAC key to temp buffer

		AES_CMAC(keys.CMAC, inbuff+0x60, 0x30, cmac_header_hash);

		//Make sure data is 16 aligned
		chk_size = header->data_size;
		if(chk_size % 16)
			chk_size += 16 - (chk_size % 16);
		chk_size += 0x30+header->data_offset;

		AES_CMAC(keys.CMAC, inbuff+0x60, chk_size, cmac_data_hash);

		if(memcmp(cmac_header_hash, header->CMAC_header_hash, 16) != 0){
            printf("header hash invalid\n");
            return KIRK_HEADER_HASH_INVALID;
        }

		if(memcmp(cmac_data_hash, header->CMAC_data_hash, 16) != 0){
            printf("data hash invalid\n");
            return KIRK_DATA_HASH_INVALID;
        }

		return KIRK_OPERATION_SUCCESS;
	}

	return KIRK_SIG_CHECK_INVALID; //Checks for cmd 2 & 3 not included right now
}

/*
void kirk_CMD17(SomeStructure *ss, int *b, u8 *out)
{
	AES_KEY ctx, ctx2; // sp+0x20
	int i, j;
	u8 sg_key1[0x10], sg_key2[0x10]; // sp, sp+0x10

	AES_set_encrypt_key(kirk11_key0, 128, &ctx);
	AES_set_decrypt_key(kirk11_key0, 128, &ctx2);

	for(i=0; i<16; i++){
		sg_key1[i] = sg_key2[i] = ss->buf1[i%8];
	}

	for(i=0; i<3; i++){
		AES_encrypt(sg_key2, sg_key2, &ctx);
		AES_decrypt(sg_key1, sg_key1, &ctx2);
	}

	AES_set_encrypt_key(sg_key2, 128, &ctx);

	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			AES_encrypt(sg_key1, sg_key1, &ctx);
  		}
		memcpy(out+(i*16), sg_key1, 0x10);      
	}

	memcpy(out+0x30, ss->buf1, 8);
	memcpy(out+0x38, b, 4);

	P1(out);
}
*/

int kirk_CMD11(void* outbuff, void* inbuff, int size)
{
	SHA_CTX c;
	u32 data_size;

	data_size = *(u32*)(inbuff);

	SHA1_Init(&c);
	SHA1_Update(&c, inbuff+4, data_size);
	SHA1_Final(outbuff, &c);

	return KIRK_OPERATION_SUCCESS;
}

u8* kirk_4_7_get_key(int key_type)
{
    switch(key_type)
	{
		case(0x03): return kirk7_key03; break;
		case(0x04): return kirk7_key04; break;
		case(0x05): return kirk7_key05; break;
		case(0x0C): return kirk7_key0C; break;
		case(0x0D): return kirk7_key0D; break;
		case(0x0E): return kirk7_key0E; break;
		case(0x0F): return kirk7_key0F; break;
		case(0x10): return kirk7_key10; break;
		case(0x11): return kirk7_key11; break;
		case(0x12): return kirk7_key12; break;
		case(0x38): return kirk7_key38; break;
		case(0x39): return kirk7_key39; break;
		case(0x3A): return kirk7_key3A; break;
		case(0x4B): return kirk7_key4B; break;
		case(0x53): return kirk7_key53; break;
		case(0x57): return kirk7_key57; break;
		case(0x5D): return kirk7_key5D; break;
		case(0x63): return kirk7_key63; break;
		case(0x64): return kirk7_key64; break;
		default:
			return NULL; //need to get the real error code for that, placeholder now :)
	}
}

int sceUtilsSetFuseID(void*fuse)
{
	memcpy(fuseID, fuse, 16);
	return 0;
}

int sceUtilsBufferCopyWithRange(void* outbuff, int outsize, void* inbuff, int insize, int cmd)
{
    switch(cmd){
	case KIRK_CMD_DECRYPT_PRIVATE:
		return kirk_CMD1(outbuff, inbuff, insize);
	case KIRK_CMD_ENCRYPT_IV_0:
		return kirk_CMD4(outbuff, inbuff, insize);
	case KIRK_CMD_DECRYPT_IV_0:
		return kirk_CMD7(outbuff, inbuff, insize);
	case KIRK_CMD_PRIV_SIG_CHECK:
		return kirk_CMD10(inbuff, insize);
	case KIRK_CMD_SHA1_HASH:
		return kirk_CMD11(outbuff, inbuff, insize);
	}

	printf("sceUtilsBufferCopyWithRange: cmd %d unknow!\n", cmd);
	return -1;
}

