/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspbase64.h - Prototypes for the libbase64 library
 *
 * Copyright (c) 2025 ultros
 *
 */
 
#ifndef __LIBBASE64_H__
#define __LIBBASE64_H__

#ifdef __cplusplus
extern "C" {
#endif

int   sceBase64Encoder(unsigned char *pDst, const unsigned char *pSrc, unsigned int uiSize);
int   sceBase64Decoder(unsigned char *pDst, const unsigned char *pSrc, unsigned int uiSize);

#ifdef __cplusplus
}
#endif

#endif

