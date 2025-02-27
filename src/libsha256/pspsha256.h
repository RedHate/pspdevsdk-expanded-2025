/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsha256.h - Prototypes for the libsha256
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBSHA256_H__
#define __LIBSHA256_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SHA256_HASH_LEN 32

typedef struct {
	unsigned int       h[5];
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long ulTotalLen;
	unsigned char      buf[64];
} sceSha256Context;

/*E basic hash computing */
/*E all data must be in memory */
int  sceSha256Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);

/*E splitable hash computing */
int  sceSha256BlockInit(sceSha256Context *pContext);
int  sceSha256BlockUpdate(sceSha256Context *pContext, const unsigned char *plain, unsigned int len);
int  sceSha256BlockResult(sceSha256Context *pContext, unsigned char *digest);

#ifdef __cplusplus
}
#endif

#endi
