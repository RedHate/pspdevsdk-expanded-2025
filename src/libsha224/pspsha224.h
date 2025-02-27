/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsha224.h - Prototypes for the libsha224
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBSHA224_H__
#define __LIBSHA224_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SHA224_HASH_LEN 28

typedef struct {
	unsigned int       h[5];
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long ulTotalLen;
	unsigned char      buf[64];
} sceSha224Context;

/*E basic hash computing */
/*E all data must be in memory */
int  sceSha224Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);

/*E splitable hash computing */
int  sceSha224BlockInit(sceSha224Context *pContext);
int  sceSha224BlockUpdate(sceSha224Context *pContext, const unsigned char *plain, unsigned int len);
int  sceSha224BlockResult(sceSha224Context *pContext, unsigned char *digest);

#ifdef __cplusplus
}
#endif

#endif
