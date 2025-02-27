/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsha1.h - Prototypes for the libsha1
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBSHA1_H__
#define __LIBSHA1_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SHA1_HASH_LEN 20

typedef struct {
	unsigned int       h[5];
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long ulTotalLen;
	unsigned char      buf[64];
} sceSha1Context;

int  sceSha1Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);
int  sceSha1BlockInit(sceSha1Context *pContext);
int  sceSha1BlockUpdate(sceSha1Context *pContext, const unsigned char *plain, unsigned int len);
int  sceSha1BlockResult(sceSha1Context *pContext, unsigned char *digest);

#ifdef __cplusplus
}
#endif

#endif
