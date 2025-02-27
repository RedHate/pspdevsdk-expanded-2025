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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/stat.h>



#include "kirk_engine.h"
#include "pspcipher.h"


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

int kirk7(u8* prx, u32 size, u32 scramble_code)
{
	int ret;

	((u32 *) prx)[0] = 5;
	((u32 *) prx)[1] = 0;
	((u32 *) prx)[2] = 0;
	((u32 *) prx)[3] = scramble_code;
	((u32 *) prx)[4] = size;

	ret = sceUtilsBufferCopyWithRange (prx, size + 20, prx, size + 20, 7);

	return ret;
}

void prx_xor_key_into(u8 *dstbuf, u32 size, u8 *srcbuf, u8 *xor_key)
{
	u32 i;

	i = 0;

	while (i < size) {
		dstbuf[i] = srcbuf[i] ^ xor_key[i];
		++i;
	}
}

void prx_xor_key_large(u8 *buf, u32 size, u8 *xor_key)
{
	u32 i;

	i = 0;

	while (i < size) {
		buf[i] = buf[i] ^ xor_key[i];
		++i;
	}
}

void prx_xor_key(u8 *buf, u32 size, u8 *xor_key1, u8 *xor_key2)
{
	u32 i;

	i =0;
	while (i < size) {
		if (xor_key2 != NULL) {
			buf[i] = buf[i] ^ xor_key2[i&0xf];
		}

		buf[i] = buf[i] ^ xor_key1[i&0xf];
		++i;
	}
}

void prx_xor_key_single(u8 *buf, u32 size, u8 *xor_key)
{
	return prx_xor_key(buf, size, xor_key, NULL);
}

int uprx_decrypt(user_decryptor *pBlock)
{
	int i;
	int ret = -1;

	if (pBlock == NULL)
		return -1;

	if (pBlock->prx == NULL || pBlock->newsize == NULL)
		return -2;

	if (pBlock->size < 0x160)
		return -202;

	/** buf1 = 0x8fc0 */
	u8 buf1[0x150];
	/** buf2 = 0x91c0 */
	u8 buf2[0x150];
	/** buf3 = 0x9110 */
	u8 buf3[0x90];
	/** buf4 = 0x9340 */
	u8 buf4[0xb4];

	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));
	memset(buf3, 0, sizeof(buf3));
	memset(buf4, 0, sizeof(buf4));

	memcpy(buf1, pBlock->prx, 0x150);
	hex_dump("EBOOT header", buf1, 0x150);


	/* zero check */
	if (pBlock->type == 2) {
		u8 *p = buf1+0xd4;
		for(i=0; i<0x58; i++){
			if(p[i])
				break;
		}
		if(i!=0x58)
			return -12;
	}

	u32 elf_size_comp =  *(u32*)(buf1+0xb0);
	*pBlock->newsize = elf_size_comp;
	if (pBlock->size - 50 < elf_size_comp)
		return -206;

	for(i=0; i<9; i++){
		memcpy(buf2+0x14+(i*16), pBlock->key, 0x10);
		buf2[0x14+(i*16)] = i;
	}

	ret = kirk7(buf2, 0x90, pBlock->code);
	if(ret<0)
		return ret;
	hex_dump("tag_key:", buf2, 0x90);

	// save tag_key to buf3
	memcpy(buf3, buf2, 0x90);

	// reorder buf1 to buf2
	memcpy(buf2       , buf1 +  0xd0, 0x5C);
	memcpy(buf2 + 0x5c, buf1 + 0x140, 0x10);
	memcpy(buf2 + 0x6c, buf1 + 0x12c, 0x14);
	memcpy(buf2 + 0x80, buf1 +  0x80, 0x30);
	memcpy(buf2 + 0xb0, buf1 +  0xc0, 0x10);
	memcpy(buf2 + 0xc0, buf1 +  0xb0, 0x10);
	memcpy(buf2 + 0xd0, buf1        , 0x80);
	hex_dump("reorder buf1 to buf2", buf2, 0x150);

	// decrypt buf2+0x5c
	memcpy(buf4 + 0x14, buf2 + 0x5c, 0x60);
	if (kirk7(buf4, 0x60, pBlock->code) < 0) {
		return -5;
	}
	memcpy(buf2 + 0x5c, buf4, 0x60);
	hex_dump("decrypt buf2+0x5c", buf2, 0x150);

	// saved SHA1 hash
	memcpy(buf4, buf2 + 0x6c, 0x14);
	hex_dump("saved SHA1 hash", buf4, 0x14);

	// overwrite SHA1 part
	memcpy(buf2+0x70, buf2+0x5C, 0x10);
	memset(buf2+0x18, 0, 0x58);
	hex_dump("overwrite SHA1 part", buf2, 0x150);


	memcpy(buf2+0x04, buf2, 0x04);
	*((u32*)buf2) = 0x014C;
	memcpy(buf2+0x08, buf3, 0x10);	
	hex_dump("before SHA1", buf2, 0x150);

	// SHA1 hash
	ret = sceUtilsBufferCopyWithRange (buf2, 0x150, buf2, 0x150, 0xB);
	if(ret!=0)
		return -6;
	if (memcmp(buf2, buf4, 0x14))
		return -8;

	prx_xor_key_large(buf2+0x80, 0x40, buf3+0x10);
	hex_dump("xor_large", buf2, 0x150);
	if (kirk7(buf2+0x6C, 0x40, pBlock->code) < 0)
		return -7;

	hex_dump("xor_large kirk7", buf2+0x6c, 0x40);
	prx_xor_key_into(pBlock->prx+0x40, 0x40, buf2+0x6c, buf3+0x50);

	memset(pBlock->prx+0x40+0x40, 0, 0x30);
	memcpy(pBlock->prx+0x40+0x70, buf2+0xc0, 0x10);
	memset(pBlock->prx+0x40+0x80, 0, 0x10);
	memcpy(pBlock->prx+0x40+0x90, buf2+0xd0, 0x80);

	((u8*)pBlock->prx)[0x40+0x60] = 1;

	// The real decryption
	hex_dump("kirk1", pBlock->prx+0x40, 0x200);
	if (sceUtilsBufferCopyWithRange(pBlock->prx, pBlock->size, pBlock->prx+0x40, pBlock->size-0x40, 0x1) != 0)
		return -9;

	return 0;
}


