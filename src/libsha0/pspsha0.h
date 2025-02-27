/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsha0.h - Prototypes for the libsha0
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBSHA0_H__
#define __LIBSHA0_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SHA0_HASH_LEN 20

typedef struct {
	unsigned int       h[5];
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long ulTotalLen;
	unsigned char      buf[64];
} sceSha0Context;

/*E basic hash computing */
/*E all data must be in memory */
int  sceSha0Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);

/*E splitable hash computing */
int  sceSha0BlockInit(sceSha0Context *pContext);
int  sceSha0BlockUpdate(sceSha0Context *pContext, const unsigned char *plain, unsigned int len);
int  sceSha0BlockResult(sceSha0Context *pContext, unsigned char *digest);

#ifdef __cplusplus
}
#endif

#endi
