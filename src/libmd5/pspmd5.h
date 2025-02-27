/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspmd5.h - Prototypes for the libmd5 library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBMD5_H__
#define __LIBMD5_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	unsigned int       h[4];
	unsigned int       pad;
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long ulTotalLen;
	unsigned char      buf[64];
} sceMd5Context;

/* Get full MD5 digest with one pass */
int  sceMd5Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);

/* Initialize digest value */
int  sceMd5BlockInit(sceMd5Context *pContext);

/* MD5 digest value compute segment */
int  sceMd5BlockUpdate(sceMd5Context *pContext, const unsigned char *plain, unsigned int len);

/* Get MD5 digest */
int  sceMd5BlockResult(sceMd5Context *pContext, unsigned char *digest);


#ifdef __cplusplus
}
#endif

#endif
