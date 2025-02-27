/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsha384.h - Prototypes for the libsha384
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBSHA384_H__
#define __LIBSHA384_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SHA384_HASH_LEN 48

typedef struct {
	unsigned int       h[5];
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long ulTotalLen;
	unsigned char      buf[64];
} sceSha384Context;

/*E basic hash computing */
/*E all data must be in memory */
int  sceSha384Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);

/*E splitable hash computing */
int  sceSha384BlockInit(sceSha384Context *pContext);
int  sceSha384BlockUpdate(sceSha384Context *pContext, const unsigned char *plain, unsigned int len);
int  sceSha384BlockResult(sceSha384Context *pContext, unsigned char *digest);

#ifdef __cplusplus
}
#endif

#endi
