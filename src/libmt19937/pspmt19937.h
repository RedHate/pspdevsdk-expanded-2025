/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * psppsmf.h - Prototypes for the libpsmf psuedo random number library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBMT19937_H__
#define __LIBMT19937_H__

#ifdef __cplusplus
extern "C" {
#endif

/* type definition */
typedef struct sceMt19937Context {
	unsigned int count;
	unsigned int state[624];
} sceMt19937Context;

/* prototype */
int sceMt19937Init(sceMt19937Context *pCtx, unsigned int seed);
unsigned int sceMt19937UInt(sceMt19937Context *pCtx);

#ifdef __cplusplus
}
#endif

#endif
