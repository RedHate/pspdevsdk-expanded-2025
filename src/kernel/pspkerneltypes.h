/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspkerneltypes.h - PSP kernel types and definitions.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 */

#ifndef PSPKERNELTYPES_H
#define PSPKERNELTYPES_H

#include <psptypes.h>

/** UIDs are used to describe many different kernel objects. */
#define SceUID_NAME_MAX         31
typedef int SceUID;

/* Misc. kernel types. */
typedef unsigned int    SceSize;
typedef int             SceSSize;

typedef unsigned char   SceUChar;
typedef unsigned int    SceUInt;

/* File I/O types. */
typedef int             SceMode;
typedef long long       SceOff;
typedef long long       SceIores;

#endif /* PSPKERNELTYPES_H */
