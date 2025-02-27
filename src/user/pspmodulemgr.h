/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspmodulemgr.h - Prototypes to manage modules.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 */

/* Note: Some of the structures, types, and definitions in this file were
   extrapolated from symbolic debugging information found in the Japanese
   version of Puzzle Bobble. */

#ifndef __MODLOAD_H__
#define __MODLOAD_H__

#include <pspkerneltypes.h>
#include <pspsysmem.h>
#include <psploadcore.h>

/** @defgroup ModuleMgr Module Manager Library
  * This module contains the imports for the kernel's module management routines.
  */

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup ModuleMgr Module Manager Library */
/**@{*/

#define PSP_MEMORY_PARTITION_KERNEL 	1
#define PSP_MEMORY_PARTITION_USER 		2

/* module allocate type */
#define SCE_KERNEL_LM_POS_Low			SCE_KERNEL_SMEM_Low
#define SCE_KERNEL_LM_POS_High			SCE_KERNEL_SMEM_High
#define SCE_KERNEL_LM_POS_Addr			SCE_KERNEL_SMEM_Addr

/*for backward compatiblity */
#define SCE_KERNEL_LMWO_POS_Low			SCE_KERNEL_LM_POS_Low
#define SCE_KERNEL_LMWO_POS_High		SCE_KERNEL_LM_POS_High
#define SCE_KERNEL_LMWO_POS_Addr		SCE_KERNEL_LM_POS_Addr

/* file access type     */
#define SCE_KERNEL_LM_ACCESS_NOSEEK		(1)

/*for backward compatiblity */
#define SCE_KERNEL_LMWO_ACCESS_NOSEEK	SCE_KERNEL_LM_ACCESS_NOSEEK

typedef struct SceKernelLMOption {
	SceSize				size;			/* size of SceKernelLMOption data */
	SceUID				mpidtext;		/* partition text */
	SceUID				mpiddata;		/* partition data */
	unsigned int		flags;			
	char				position;		
	char				access;			
	char				creserved[2];	
} SceKernelLMOption;

typedef struct SceKernelSMOption {
	SceSize				size;			/* size of SceKernelSMOption data */
	SceUID				mpidstack;		/* partition stack */
	SceSize				stacksize;      /* stack size in bytes */
	int					priority;		/* thread priority */
	unsigned int		attribute;		/* thread attribute */
} SceKernelSMOption;


/**
  * Load a module.
  * @note This function restricts where it can load from (such as from flash0) 
  * unless you call it in kernel mode. It also must be called from a thread.
  * 
  * @param path - The path to the module to load.
  * @param flags - Unused, always 0 .
  * @param option  - Pointer to a mod_param_t structure. Can be NULL.
  *
  * @return The UID of the loaded module on success, otherwise one of ::PspKernelErrorCodes.
  */
SceUID sceKernelLoadModule(const char *path, int flags, SceKernelLMOption *option);

/**
  * Load a module from MS.
  * @note This function restricts what it can load, e.g. it wont load plain executables.
  * 
  * @param path - The path to the module to load.
  * @param flags - Unused, set to 0.
  * @param option  - Pointer to a mod_param_t structure. Can be NULL.
  *
  * @return The UID of the loaded module on success, otherwise one of ::PspKernelErrorCodes.
  */
SceUID sceKernelLoadModuleMs(const char *path, int flags, SceKernelLMOption *option);

/**
 * Load a module from the given file UID.
 *
 * @param fid - The module's file UID.
 * @param flags - Unused, always 0.
 * @param option - Pointer to an optional ::SceKernelLMOption structure.
 *
 * @return The UID of the loaded module on success, otherwise one of ::PspKernelErrorCodes.
 */
SceUID sceKernelLoadModuleByID(SceUID fid, int flags, SceKernelLMOption *option);

/**
 * Load a module from a buffer using the USB/WLAN API.
 *
 * Can only be called from kernel mode, or from a thread that has attributes of 0xa0000000.
 *
 * @param bufsize - Size (in bytes) of the buffer pointed to by buf.
 * @param buf - Pointer to a buffer containing the module to load.  The buffer must reside at an
 *              address that is a multiple to 64 bytes.
 * @param flags - Unused, always 0.
 * @param option - Pointer to an optional ::SceKernelLMOption structure.
 *
 * @return The UID of the loaded module on success, otherwise one of ::PspKernelErrorCodes.
 */
SceUID sceKernelLoadModuleBufferUsbWlan(SceSize bufsize, void *buf, int flags, SceKernelLMOption *option);

/**
  * Start a loaded module.
  *
  * @param modid - The ID of the module returned from LoadModule.
  * @param argsize - Length of the args.
  * @param argp - A pointer to the arguments to the module.
  * @param status - Returns the status of the start.
  * @param option - Pointer to an optional ::SceKernelSMOption structure.
  *
  * @return ??? on success, otherwise one of ::PspKernelErrorCodes.
  */
int sceKernelStartModule(SceUID modid, SceSize argsize, void *argp, int *status, SceKernelSMOption *option);

/**
 * Stop a running module.
 *
 * @param modid - The UID of the module to stop.
 * @param argsize - The length of the arguments pointed to by argp.
 * @param argp - Pointer to arguments to pass to the module's module_stop() routine.
 * @param status - Return value of the module's module_stop() routine.
 * @param option - Pointer to an optional ::SceKernelSMOption structure.
 *
 * @return ??? on success, otherwise one of ::PspKernelErrorCodes.
 */
int sceKernelStopModule(SceUID modid, SceSize argsize, void *argp, int *status, SceKernelSMOption *option);

/**
 * Unload a stopped module.
 *
 * @param modid - The UID of the module to unload.
 *
 * @return ??? on success, otherwise one of ::PspKernelErrorCodes.
 */
int sceKernelUnloadModule(SceUID modid);

/**
 * Stop and unload the current module.
 *
 * @param unknown - Unknown (I've seen 1 passed).
 * @param argsize - Size (in bytes) of the arguments that will be passed to module_stop().
 * @param argp - Pointer to arguments that will be passed to module_stop().
 *
 * @return ??? on success, otherwise one of ::PspKernelErrorCodes.
 */
int sceKernelSelfStopUnloadModule(int unknown, SceSize argsize, void *argp);

/**
 * Stop and unload the current module.
 *
 * @param argsize - Size (in bytes) of the arguments that will be passed to module_stop().
 * @param argp - Poitner to arguments that will be passed to module_stop().
 * @param status - Return value from module_stop().
 * @param option - Pointer to an optional ::SceKernelSMOption structure.
 *
 * @return ??? on success, otherwise one of ::PspKernelErrorCodes.
 */
int sceKernelStopUnloadSelfModule(SceSize argsize, void *argp, int *status, SceKernelSMOption *option);


typedef struct SceKernelModuleInfo {
	SceSize 		size;
	char 			nsegment;
	char 			reserved[3];
	int 			segmentaddr[4];
	int 			segmentsize[4];
	unsigned int 	entry_addr;
	unsigned int 	gp_value;
	unsigned int 	text_addr;
	unsigned int 	text_size;
	unsigned int 	data_size;
	unsigned int 	bss_size;
	/* The following is only available in the v1.5 firmware and above,
	   but as sceKernelQueryModuleInfo is broken in v1.0 is doesn't matter ;) */
	unsigned short  attribute;
	unsigned char   version[2];
	char            name[28];
} SceKernelModuleInfo;

typedef struct sceKernelModuleInfoV0 {
	SceSize				size;
	char				nsegment;
	char				reserved[3];
	int					segmentaddr[SCE_KERNEL_MAX_MODULE_SEGMENT];
	int					segmentsize[SCE_KERNEL_MAX_MODULE_SEGMENT];
	unsigned int		entry_addr;
	unsigned int		gp_value;
	unsigned int		text_addr;
	unsigned int		text_size;
	unsigned int		data_size;
	unsigned int		bss_size;
} sceKernelModuleInfoV0;

typedef struct sceKernelModuleInfo {
	/* version v0 */
	SceSize				size;
	char				nsegment;
	char				reserved[3];
	int					segmentaddr[SCE_KERNEL_MAX_MODULE_SEGMENT];
	int					segmentsize[SCE_KERNEL_MAX_MODULE_SEGMENT];
	unsigned int		entry_addr;
	unsigned int		gp_value;
	unsigned int		text_addr;
	unsigned int		text_size;
	unsigned int		data_size;
	unsigned int		bss_size;

	/* version v1 */
	unsigned short		modattribute;
	unsigned char		modversion[2];	/* minor, magor, etc... */
										/* minor 0 - major 1 */
	char				modname[SCE_KERNEL_MODULE_NAME_LEN];
	char				terminal;
} sceKernelModuleInfoV1;

/**
  * Query the information about a loaded module from its UID.
  * @note This fails on v1.0 firmware (and even it worked has a limited structure)
  * so if you want to be compatible with both 1.5 and 1.0 (and you are running in 
  * kernel mode) then call this function first then ::pspSdkQueryModuleInfoV1 
  * if it fails, or make separate v1 and v1.5+ builds.
  *
  * @param modid - The UID of the loaded module.
  * @param info - Pointer to a ::SceKernelModuleInfo structure.
  * 
  * @return 0 on success, otherwise one of ::PspKernelErrorCodes.
  */
int sceKernelQueryModuleInfo(SceUID modid, SceKernelModuleInfo *info);

SceUID	sceKernelGetModuleId(void);

/**
 * Get the ID of the module occupying the address
 *
 * @param moduleAddr - A pointer to the module
 *
 * @return >= 0 on success, otherwise one of ::PspKernelErrorCodes
 */
int sceKernelGetModuleIdByAddress(const void *moduleAddr);

/**
  * Get a list of module IDs. NOTE: This is only available on 1.5 firmware
  * and above. For V1 use ::pspSdkGetModuleIdList.
  *
  * @param readbuf - Buffer to store the module list.
  * @param readbufsize - Number of elements in the readbuffer.
  * @param idcount - Returns the number of module ids
  *
  * @return >= 0 on success
  */
int sceKernelGetModuleIdList(SceUID *readbuf, int readbufsize, int *idcount);

/** @addtogroup LoadCore Interface to the LoadCoreForKernel library. */
/**@{*/

/** Describes a module.  This structure could change in future firmware revisions. */
typedef struct SceModule {
	struct SceModule	*next;
	unsigned short		attribute;
	unsigned char		version[2];
	char				modname[SCE_KERNEL_MODULE_NAME_LEN];
	char				terminal;
	unsigned int		unknown1;
	unsigned int		unknown2;
	SceUID				modid;
	unsigned int		unknown3[4];
	void *				ent_top;
	unsigned int		ent_size;
	void *				stub_top;
	unsigned int		stub_size;
	unsigned int		unknown4[4];
	unsigned int		entry_addr;
	unsigned int		gp_value;
	unsigned int		text_addr;
	unsigned int		text_size;
	unsigned int		data_size;
	unsigned int		bss_size;
	unsigned int		nsegment;
	unsigned int		segmentaddr[SCE_KERNEL_MAX_MODULE_SEGMENT];
	unsigned int		segmentsize[SCE_KERNEL_MAX_MODULE_SEGMENT];
} __attribute__((packed)) SceModule;

/** Defines a library and its exported functions and variables.  Use the len
    member to determine the real size of the table (size = len * 4). */
typedef struct SceLibraryEntryTable {
	/**The library's name. */
	const char *		libname;
	/** Library version. */
	unsigned char		version[2];
	/** Library attributes. */
	unsigned short		attribute;
	/** Length of this entry table in 32-bit WORDs. */
	unsigned char		len;
	/** The number of variables exported by the library. */
	unsigned char		vstubcount;
	/** The number of functions exported by the library. */
	unsigned short		stubcount;
	/** Pointer to the entry table; an array of NIDs followed by
	    pointers to functions and variables. */
	void *				entrytable;
} SceLibraryEntryTable;

/** Specifies a library and a set of imports from that library.  Use the len
    member to determine the real size of the table (size = len * 4). */
typedef struct SceLibraryStubTable {
	/* The name of the library we're importing from. */
	const char *		libname;
	/** Minimum required version of the library we want to import. */
	unsigned char		version[2];
	/* Import attributes. */
	unsigned short		attribute;
	/** Length of this stub table in 32-bit WORDs. */
	unsigned char		len;
	/** The number of variables imported from the library. */
	unsigned char		vstubcount;
	/** The number of functions imported from the library. */
	unsigned short		stubcount;
	/** Pointer to an array of NIDs. */
	unsigned int *		nidtable;
	/** Pointer to the imported function stubs. */
	void *				stubtable;
	/** Pointer to the imported variable stubs. */
	void *				vstubtable;
} SceLibraryStubTable;


/**
 * Find a module by it's name.
 *
 * @param modname - The name of the module.
 *
 * @return Pointer to the ::SceModule structure if found, otherwise NULL.
 */
SceModule * sceKernelFindModuleByName(const char *modname);

/**
 * Find a module from an address.
 *
 * @param addr - Address somewhere within the module.
 *
 * @return Pointer to the ::SceModule structure if found, otherwise NULL.
 */
SceModule * sceKernelFindModuleByAddress(unsigned int addr);

/**
 * Find a module by it's UID.
 *
 * @param modid - The UID of the module.
 *
 * @return Pointer to the ::SceModule structure if found, otherwise NULL.
 */
SceModule * sceKernelFindModuleByUID(SceUID modid);

/**
 * Return the count of loaded modules.
 *
 * @return The count of loaded modules.
 */
int sceKernelModuleCount(void);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
