/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspadler.h - Prototypes for the pspadler library
 *
 * Copyright (c) 2025 ultros
 *
 */
 
#ifndef __LIBADLER_H__
#define __LIBADLER_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
Adler-32 checksum
*/
unsigned int sceAdler32(unsigned int uiAdler, const unsigned char *pSrc, unsigned int uiSize);

#ifdef __cplusplus
}
#endif

#endif

