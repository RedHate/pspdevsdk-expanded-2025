/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspqpcode.h - Prototypes for the libqpcode
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBQPCODE_H__
#define __LIBQPCODE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define	SCE_QPCODE_OUT_OF_MEMORY	0x80434022
#define SCE_QPCODE_INVALID_VALUE	0x804341FE
#define	SCE_QPCODE_INVALID_FORMAT	0x80434108

int sceQPrintableLineDecoder(unsigned char *out, const unsigned char *in, SceSize src_len, SceSize *require, SceSize prepare);
int sceQPrintableEncoder(unsigned char *out, const unsigned char *in, SceSize src_len, SceSize *require, SceSize prepare);

#ifdef __cplusplus
}
#endif

#endif
