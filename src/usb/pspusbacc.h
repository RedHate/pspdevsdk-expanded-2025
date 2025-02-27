/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspusbacc.h - Prototypes for the sceUsbAcc library
 *
 * Copyright (c) 2007 dot_blank
 *
 */
#ifndef __PSPUSBACC_H__
#define __PSPUSBACC_H__

#ifdef __cplusplus
extern "C" {
#endif

#define PSP_USBACC_DRIVERNAME	"USBAccBaseDriver"

int sceUsbAccGetInfo();
int sceUsbAccUnregisterType(int type);
int sceUsbAccRegisterType(int type);
int sceUsbAccGetAuthStat();

#ifdef __cplusplus
}
#endif

#endif 

