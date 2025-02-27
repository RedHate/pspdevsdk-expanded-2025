/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspmsstor.h - Memory stick storage functions
 *
 * Copyright (c) 2006 Adrahil
 *
 */
#ifndef PSPFATMS_H
#define PSPFATMS_H

#include <pspiofilemgr.h>

#ifdef __cplusplus
extern "C" {
#endif


//		File attribute							
#define SCE_EATRO   	0x01                    // read only 					
#define SCE_EATHD		0x02					// hide							
#define SCE_EATSY		0x04					// system						
#define SCE_EATVL		0x08					// volume label					
#define SCE_EATDR		0x10					// sub-directory 				
#define SCE_EATAR		0x20					// archives						
#define SCE_EATALL		0x80					// for fsfirst function			
#define SCE_EMODRO  	(SCE_EATRO | SCE_EATVL | SCE_EATDR)
												// attribute for write protected 
#define SCE_ELONG		0x0F					// long file neme entry			

//	     For iob private data                   
typedef struct SceFatMsDirentPrivate {
	char FileName[13];
	char LongName[256];
} SceFatMsDirentPrivate;

#define		SceFatMSULong		unsigned long
//		file information table for APL			
typedef struct SceDevInf {
	SceFatMSULong		cls;			// max logical cluster par unit		
	SceFatMSULong		ecl;			// empty cluster number				
	SceFatMSULong		ebc;			// cluster of empty logical block	
	int			        bps;			// bytes par logical sector			
	int			        spc;			// sector par cluster				
} SceDevInf;

#define SCE_IOCTL_DEVICE_FAT_MS  (0x24)
#define _SCE_FAT_MS_CTLCODE(dst, src, priv, cache, wait, devctl, funcno) \
((SCE_IOCTL_DEVICE_FAT_MS << 20) | \
 ((dst    & 1) << 17)   | \
 ((src    & 1) << 16)   | \
 ((priv   & 1) << 15)   | \
 ((cache  & 1) << 14)   | \
 ((wait   & 3) << 12)   | \
 ((devctl & 1) << 11)   | \
 ((funcno << 0) & 0x07ff))

// SCE_PR_GETDEV 
#define SCE_PR_GETDEV       _SCE_FAT_MS_CTLCODE(1, 0, 0, 1, 1, 1, 0x18)
typedef struct Sce_getdev_command_t {
	SceDevInf *dev_inf;
}Sce_getdev_command_t;

#define SCE_FATMS_ALIAS_NAME	"ms0:"
#define SCE_FATMS_ASSIGN_NAME	SCE_FATMS_ALIAS_NAME

// Medium attached/detached and Assign/Unassign callback 
// Medium attached and Assign done
#define SCE_PR_REGISTER_CALLBACK       _SCE_FAT_MS_CTLCODE(0, 1, 0, 1, 1, 1, 0x21)
// Medium detached and Unassign done
#define SCE_PR_UNREGISTER_CALLBACK     _SCE_FAT_MS_CTLCODE(0, 1, 0, 1, 1, 1, 0x22)
// callback command pattern 
#define SCE_FATMS_NOTIFY_ASSIGNED    (1<<0)   // FatMS assiged 
#define SCE_FATMS_NOTIFY_UNASSIGNED  (1<<1)   // FatMS unassiged 

// macro for registering callback of Assign/Unassign notification 
static __inline__ int sceFatmsRegisterNotifyCallback(SceUID uidCB)
{
	return sceIoDevctl("fatms0:", SCE_PR_REGISTER_CALLBACK, &uidCB, sizeof(uidCB), 0, 0);
}
// macro for unregistering callback of  Assign/Unassign notification 
static __inline__ int sceFatmsUnRegisterNotifyCallback(SceUID uidCB)
{
	return sceIoDevctl("fatms0:", SCE_PR_UNREGISTER_CALLBACK, &uidCB, sizeof(uidCB), 0, 0);
}

#ifdef __cplusplus
}
#endif

#endif
