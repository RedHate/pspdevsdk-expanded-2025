/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsha512.h - Prototypes for the libsha512
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBSHA512_H__
#define __LIBSHA512_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SHA512_HASH_LEN 64

typedef struct {
	unsigned int       h[5];
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long ulTotalLen;
	unsigned char      buf[64];
} sceSha512Context;

/*E basic hash computing */
/*E all data must be in memory */
int  sceSha512Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);

/*E splitable hash computing */
int  sceSha512BlockInit(sceSha512Context *pContext);
int  sceSha512BlockUpdate(sceSha512Context *pContext, const unsigned char *plain, unsigned int len);
int  sceSha512BlockResult(sceSha512Context *pContext, unsigned char *digest);

#ifdef __cplusplus
}
#endif

#endi
