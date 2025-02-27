/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspiofilemgr_kernel.h - Interface to the kernel mode library for IoFileMgr.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 */

#ifndef PSPIOFILEMGR_KERNEL_H
#define PSPIOFILEMGR_KERNEL_H

#include <psptypes.h>
#include <pspkerneltypes.h>
#include <pspiofilemgr.h>

/** @defgroup IoFileMgr_Kernel Driver interface to IoFileMgr
 *  This module contains the imports for the kernel's IO routines.
 */

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup IoFileMgr_Kernel Driver interface to IoFileMgr */
/**@{*/

struct SceIoDrv;

/** Structure passed to the init and exit functions of the io driver system */
typedef struct SceIoDrvArg
{
	/** Pointer to the original driver which was added */
	struct SceIoDrv *drv;
	/** Pointer to a user defined argument (if written by the driver will preseve across calls */
	void *arg;
} SceIoDrvArg;

/** Structure passed to the file functions of the io driver system */
typedef struct SceIoDrvFileArg
{
	/** Unknown */
	u32 unk1;
	/** The file system number, e.g. if a file is opened as host5:/myfile.txt this field will be 5 */
	u32 fs_num;
	/** Pointer to the driver structure */
	SceIoDrvArg *drv;
	/** Unknown, again */
	u32 unk2;
	/** Pointer to a user defined argument, this is preserved on a per file basis */
	void *arg;
} SceIoDrvFileArg;

/** Structure to maintain the file driver pointers */
typedef struct SceIoDrvFuncs
{
	int (*IoInit)(SceIoDrvArg* arg);
	int (*IoExit)(SceIoDrvArg* arg); 
	int (*IoOpen)(SceIoDrvFileArg *arg, char *file, int flags, SceMode mode); 
	int (*IoClose)(SceIoDrvFileArg *arg); 
	int (*IoRead)(SceIoDrvFileArg *arg, char *data, int len); 
	int (*IoWrite)(SceIoDrvFileArg *arg, const char *data, int len); 
	SceOff (*IoLseek)(SceIoDrvFileArg *arg, SceOff ofs, int whence); 
	int (*IoIoctl)(SceIoDrvFileArg *arg, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen);
	int (*IoRemove)(SceIoDrvFileArg *arg, const char *name); 
	int (*IoMkdir)(SceIoDrvFileArg *arg, const char *name, SceMode mode); 
	int (*IoRmdir)(SceIoDrvFileArg *arg, const char *name);
	int (*IoDopen)(SceIoDrvFileArg *arg, const char *dirname); 
	int (*IoDclose)(SceIoDrvFileArg *arg);
	int (*IoDread)(SceIoDrvFileArg *arg, SceIoDirent *dir);
	int (*IoGetstat)(SceIoDrvFileArg *arg, const char *file, SceIoStat *stat);
	int (*IoChstat)(SceIoDrvFileArg *arg, const char *file, SceIoStat *stat, int bits);
	int (*IoRename)(SceIoDrvFileArg *arg, const char *oldname, const char *newname); 
	int (*IoChdir)(SceIoDrvFileArg *arg, const char *dir); 
	int (*IoMount)(SceIoDrvFileArg *arg); 
	int (*IoUmount)(SceIoDrvFileArg *arg); 
	int (*IoDevctl)(SceIoDrvFileArg *arg, const char *devname, unsigned int cmd, void *indata, int inlen, void *outdata, int outlen); 
	int (*IoUnk21)(SceIoDrvFileArg *arg); 
} SceIoDrvFuncs;

typedef struct SceIoDrv
{
	/** The name of the device to add */
	const char *name;
	/** Device type, this 0x10 is for a filesystem driver */
	u32 dev_type;
	/** Unknown, set to 0x800 */
	u32 unk2;
	/** This seems to be the same as name but capitalised :/ */
	const char *name2;
	/** Pointer to a filled out functions table */
	SceIoDrvFuncs *funcs;
} SceIoDrv;

/** 
  * Adds a new IO driver to the system.
  * @note This is only exported in the kernel version of IoFileMgr
  * 
  * @param drv - Pointer to a filled out driver structure
  * @return < 0 on error.
  *
  * @par Example:
  * @code
  * SceIoDrvFuncs host_funcs = { ... };
  * SceIoDrv host_driver = { "host", 0x10, 0x800, "HOST", &host_funcs };
  * sceIoDelDrv("host");
  * sceIoAddDrv(&host_driver);
  * @endcode
  */
int sceIoAddDrv(SceIoDrv *drv);

/**
  * Deletes a IO driver from the system.
  * @note This is only exported in the kernel version of IoFileMgr
  *
  * @param drv_name - Name of the driver to delete.
  * @return < 0 on error
  */
int sceIoDelDrv(const char *drv_name);

/**
  * Reopens an existing file descriptor.
  *
  * @param file - The new file to open.
  * @param flags - The open flags.
  * @param mode - The open mode.
  * @param fd - The old filedescriptor to reopen
  *
  * @return < 0 on error, otherwise the reopened fd.
  */
int sceIoReopen(const char *file, int flags, SceMode mode, SceUID fd);

/**
 * Get the current working directory for a thread.
 *
 * @param uid - The UID of the thread
 * @param dir - A character buffer in which to store the cwd
 * @param len - The length of the buffer
 *
 * @return Number of characters written to buf, if no cwd then 0 is 
 * returned.
 */
int sceIoGetThreadCwd(SceUID uid, char *dir, int len);

/**
 * Set the current working directory for a thread
 *
 * @param uid - The UID of the thread
 * @param dir - The directory to set
 *
 * @return 0 on success, < 0 on error
 */
int sceIoChangeThreadCwd(SceUID uid, char *dir);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* PSPIOFILEMGR_KERNEL_H */
