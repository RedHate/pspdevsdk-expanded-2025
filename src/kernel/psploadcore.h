/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * psploadcore.h - Interface to LoadCoreForKernel.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 */

#ifndef PSPLOADCORE_H
#define PSPLOADCORE_H

#include <pspkerneltypes.h>

/** @defgroup LoadCore Interface to the LoadCoreForKernel library.
 */

#ifdef __cplusplus
extern "C" {
#endif

//defs for kernel loadcore
#define SCE_KERNEL_MAX_MODULE_SEGMENT   4
#define SCE_KERNEL_MODULE_NAME_LEN      27
//start return values
#define SCE_KERNEL_START_RESIDENT       (0)
#define SCE_KERNEL_START_NO_RESIDENT    (1)
#define SCE_KERNEL_START_SUCCESS        (0)
#define SCE_KERNEL_START_FAIL           (1)
//resident return values
#define SCE_KERNEL_RESIDENT             (0)
#define SCE_KERNEL_NO_RESIDENT          (1)
//stop return values
#define SCE_KERNEL_STOP_SUCCESS         (0)
#define SCE_KERNEL_STOP_FAIL            (1)

/* backword compatibility */
#define SCE_KERNEL_RESIDENT_END         SCE_KERNEL_RESIDENT
#define SCE_KERNEL_NO_RESIDENT_END      SCE_KERNEL_NO_RESIDENT

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* PSPLOADCORE_H */
