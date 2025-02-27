/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspkerror.h - Definitions for the kernel error codes
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 */
 

 
#ifndef PSPKERROR_H
#define PSPKERROR_H

#include <stdio.h>

enum SceErrorCodes{
    SCE_OK	 										= 0,
    SCE_ERROR_NOT_INITIALIZED						= 0x80000001,
    SCE_ERROR_UNMATECHED_VERSION					= 0x80000002,
    SCE_ERROR_NOT_IMPLEMENTED						= 0x80000003,
    SCE_ERROR_NOT_SUPPORTED							= 0x80000004,
    SCE_ERROR_ALREADY								= 0x80000020,
    SCE_ERROR_BUSY									= 0x80000021,
    SCE_ERROR_OUT_OF_MEMORY							= 0x80000022,
    SCE_ERROR_PRIV_REQUIRED							= 0x80000023,
    SCE_ERROR_TIMEOUT								= 0x80000024,
    SCE_ERROR_NOT_FOUND								= 0x80000025,
    SCE_ERROR_ILLEGAL_CONTEXT						= 0x80000030,
    SCE_ERROR_CPUDI									= 0x80000031,
    SCE_ERROR_THREAD								= 0x80000040,
    SCE_ERROR_SEMAPHORE								= 0x80000041,
    SCE_ERROR_EVENTFLAG								= 0x80000042,
    SCE_ERROR_TIMER									= 0x80000043,
    SCE_ERROR_ALARM									= 0x80000044,
    SCE_ERROR_INVALID_ID							= 0x80000100,
    SCE_ERROR_INVALID_NAME							= 0x80000101,
    SCE_ERROR_INVALID_INDEX							= 0x80000102,
    SCE_ERROR_INVALID_POINTER						= 0x80000103,
    SCE_ERROR_INVALID_SIZE							= 0x80000104,
    SCE_ERROR_INVALID_FLAG							= 0x80000105,
    SCE_ERROR_INVALID_COMMAND						= 0x80000106,
    SCE_ERROR_INVALID_MODE							= 0x80000107,
    SCE_ERROR_INVALID_FORMAT						= 0x80000108,
    SCE_ERROR_INVALID_VALUE							= 0x800001FE,
    SCE_ERROR_INVALID_ARG							= 0x800001FF,
    SCE_ERROR_NOENT									= 0x80000202,
    SCE_ERROR_BADF									= 0x80000209,
    SCE_ERROR_ACCES									= 0x8000020D,
    SCE_ERROR_EXIST									= 0x80000211,
    SCE_ERROR_INVAL									= 0x80000216,
    SCE_ERROR_MFILE									= 0x80000218,
    SCE_ERROR_NOSPC									= 0x8000021C,
    SCE_ERROR_DFUNC			    					= 0x800002FF,
    SCE_ERROR_ERRNO_EPERM							= 0x80010001,
    SCE_ERROR_ERRNO_ENOENT							= 0x80010002,
    SCE_ERROR_ERRNO_EIO								= 0x80010005,
    SCE_ERROR_ERRNO_E2BIG							= 0x80010007,
    SCE_ERROR_ERRNO_EBADF							= 0x80010009,
    SCE_ERROR_ERRNO_EAGAIN							= 0x8001000B,
    SCE_ERROR_ERRNO_ENOMEM							= 0x8001000C,
    SCE_ERROR_ERRNO_EACCESS							= 0x8001000D,
    SCE_ERROR_ERRNO_EFAULT							= 0x8001000E,
    SCE_ERROR_ERRNO_EBUSY							= 0x80010010,
    SCE_ERROR_ERRNO_EEXIST							= 0x80010011,
    SCE_ERROR_ERRNO_EXDEV							= 0x80010012,
    SCE_ERROR_ERRNO_ENODEV							= 0x80010013,
    SCE_ERROR_ERRNO_ENOTDIR							= 0x80010014,
    SCE_ERROR_ERRNO_EISDIR							= 0x80010015,
    SCE_ERROR_ERRNO_EINVAL							= 0x80010016,
    SCE_ERROR_ERRNO_EMFILE							= 0x80010018,
    SCE_ERROR_ERRNO_EFBIG							= 0x8001001B,
    SCE_ERROR_ERRNO_ENOSPC							= 0x8001001C,
    SCE_ERROR_ERRNO_EROFS							= 0x8001001E,
    SCE_ERROR_ERRNO_ENAMETOOLONG					= 0x80010024,
    SCE_ERROR_ERRNO_EPROTO							= 0x80010047,
    SCE_ERROR_ERRNO_ENOTEMPTY						= 0x8001005A,
    SCE_ERROR_ERRNO_ELOOP							= 0x8001005C,
    SCE_ERROR_ERRNO_EADDRINUSE						= 0x80010062,
    SCE_ERROR_ERRNO_ECONNABORTED					= 0x80010067,
    SCE_ERROR_ERRNO_ECONNRESET						= 0x80010068,
    SCE_ERROR_ERRNO_ENOBUFS							= 0x80010069,
    SCE_ERROR_ERRNO_ETIMEDOUT						= 0x8001006E,
    SCE_ERROR_ERRNO_ENOMEDIUM						= 0x8001007B,
    SCE_ERROR_ERRNO_EMEDIUMTYPE 					= 0x8001007C,
    SCE_ERROR_ERRNO_EDQUOT							= 0x80010084,
    SCE_ERROR_ERRNO_ENOTSUP         				= 0x8001B000,
    SCE_ERROR_ERRNO_NOMAIN_ADDR     				= 0x8001B001,
    SCE_ERROR_ERRNO_EUNIT           				= 0x8001B002,
    SCE_ERROR_ERRNO_EFSIZE          				= 0x8001B003,
    SCE_ERROR_ERRNO_EFLAG							= 0x8001B004,
    SCE_ERROR_ERRNO_ENOCACHE						= 0x8001B005
};

enum SceKernelErrorCodes{
	SCE_KERNEL_ERROR_OK	 							= 0,	
	SCE_KERNEL_ERROR_ERROR	 						= 0x80020001,	
	SCE_KERNEL_ERROR_NOTIMP							= 0x80020002,	
	SCE_KERNEL_ERROR_ILLEGAL_EXPCODE				= 0x80020032,	
	SCE_KERNEL_ERROR_EXPHANDLER_NOUSE				= 0x80020033,	
	SCE_KERNEL_ERROR_EXPHANDLER_USED				= 0x80020034,	
	SCE_KERNEL_ERROR_SYCALLTABLE_NOUSED				= 0x80020035,	
	SCE_KERNEL_ERROR_SYCALLTABLE_USED				= 0x80020036,	
	SCE_KERNEL_ERROR_ILLEGAL_SYSCALLTABLE			= 0x80020037,	
	SCE_KERNEL_ERROR_ILLEGAL_PRIMARY_SYSCALL_NUMBER	= 0x80020038,	
	SCE_KERNEL_ERROR_PRIMARY_SYSCALL_NUMBER_INUSE	= 0x80020039,	
	SCE_KERNEL_ERROR_ILLEGAL_CONTEXT				= 0x80020064,	
	SCE_KERNEL_ERROR_ILLEGAL_INTRCODE				= 0x80020065,	
	SCE_KERNEL_ERROR_CPUDI							= 0x80020066,	
	SCE_KERNEL_ERROR_FOUND_HANDLER					= 0x80020067,	
	SCE_KERNEL_ERROR_NOTFOUND_HANDLER				= 0x80020068,	
	SCE_KERNEL_ERROR_ILLEGAL_INTRLEVEL				= 0x80020069,	
	SCE_KERNEL_ERROR_ILLEGAL_ADDRESS				= 0x8002006a,	
	SCE_KERNEL_ERROR_ILLEGAL_INTRPARAM				= 0x8002006b,	
	SCE_KERNEL_ERROR_ILLEGAL_STACK_ADDRESS			= 0x8002006c,	
	SCE_KERNEL_ERROR_ALREADY_STACK_SET				= 0x8002006d,	
	SCE_KERNEL_ERROR_NO_TIMER						= 0x80020096,	
	SCE_KERNEL_ERROR_ILLEGAL_TIMERID				= 0x80020097,	
	SCE_KERNEL_ERROR_ILLEGAL_SOURCE					= 0x80020098,	
	SCE_KERNEL_ERROR_ILLEGAL_PRESCALE				= 0x80020099,	
	SCE_KERNEL_ERROR_TIMER_BUSY						= 0x8002009a,	
	SCE_KERNEL_ERROR_TIMER_NOT_SETUP				= 0x8002009b,	
	SCE_KERNEL_ERROR_TIMER_NOT_INUSE				= 0x8002009c,	
	SCE_KERNEL_ERROR_UNIT_USED						= 0x800200a0,	
	SCE_KERNEL_ERROR_UNIT_NOUSE						= 0x800200a1,	
	SCE_KERNEL_ERROR_NO_ROMDIR						= 0x800200a2,	
	SCE_KERNEL_ERROR_IDTYPE_EXIST					= 0x800200c8,	
	SCE_KERNEL_ERROR_IDTYPE_NOT_EXIST				= 0x800200c9,	
	SCE_KERNEL_ERROR_IDTYPE_NOT_EMPTY				= 0x800200ca,	
	SCE_KERNEL_ERROR_UNKNOWN_UID					= 0x800200cb,	
	SCE_KERNEL_ERROR_UNMATCH_UID_TYPE				= 0x800200cc,	
	SCE_KERNEL_ERROR_ID_NOT_EXIST					= 0x800200cd,	
	SCE_KERNEL_ERROR_NOT_FOUND_UIDFUNC				= 0x800200ce,	
	SCE_KERNEL_ERROR_UID_ALREADY_HOLDER				= 0x800200cf,	
	SCE_KERNEL_ERROR_UID_NOT_HOLDER					= 0x800200d0,	
	SCE_KERNEL_ERROR_ILLEGAL_PERM					= 0x800200d1,	
	SCE_KERNEL_ERROR_ILLEGAL_ARGUMENT				= 0x800200d2,	
	SCE_KERNEL_ERROR_ILLEGAL_ADDR					= 0x800200d3,	
	SCE_KERNEL_ERROR_OUT_OF_RANGE					= 0x800200d4,	
	SCE_KERNEL_ERROR_MEM_RANGE_OVERLAP				= 0x800200d5,	
	SCE_KERNEL_ERROR_ILLEGAL_PARTITION				= 0x800200d6,	
	SCE_KERNEL_ERROR_PARTITION_INUSE				= 0x800200d7,	
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCKTYPE			= 0x800200d8,	
	SCE_KERNEL_ERROR_MEMBLOCK_ALLOC_FAILED			= 0x800200d9,	
	SCE_KERNEL_ERROR_MEMBLOCK_RESIZE_LOCKED			= 0x800200da,	
	SCE_KERNEL_ERROR_MEMBLOCK_RESIZE_FAILED			= 0x800200db,	
	SCE_KERNEL_ERROR_HEAPBLOCK_ALLOC_FAILED			= 0x800200dc,	
	SCE_KERNEL_ERROR_HEAP_ALLOC_FAILED				= 0x800200dd,	
	SCE_KERNEL_ERROR_ILLEGAL_CHUNK_ID				= 0x800200de,	
	SCE_KERNEL_ERROR_NOCHUNK						= 0x800200df,	
	SCE_KERNEL_ERROR_NO_FREECHUNK					= 0x800200e0,	
	SCE_KERNEL_ERROR_LINKERR						= 0x8002012c,	
	SCE_KERNEL_ERROR_ILLEGAL_OBJECT					= 0x8002012d,	
	SCE_KERNEL_ERROR_UNKNOWN_MODULE					= 0x8002012e,	
	SCE_KERNEL_ERROR_NOFILE							= 0x8002012f,	
	SCE_KERNEL_ERROR_FILEERR						= 0x80020130,	
	SCE_KERNEL_ERROR_MEMINUSE						= 0x80020131,	
	SCE_KERNEL_ERROR_PARTITION_MISMATCH				= 0x80020132,	
	SCE_KERNEL_ERROR_ALREADY_STARTED				= 0x80020133,	
	SCE_KERNEL_ERROR_NOT_STARTED					= 0x80020134,	
	SCE_KERNEL_ERROR_ALREADY_STOPPED				= 0x80020135,	
	SCE_KERNEL_ERROR_CAN_NOT_STOP					= 0x80020136,	
	SCE_KERNEL_ERROR_NOT_STOPPED					= 0x80020137,	
	SCE_KERNEL_ERROR_NOT_REMOVABLE					= 0x80020138,	
	SCE_KERNEL_ERROR_EXCLUSIVE_LOAD					= 0x80020139,	
	SCE_KERNEL_ERROR_LIBRARY_NOT_YET_LINKED			= 0x8002013a,	
	SCE_KERNEL_ERROR_LIBRARY_FOUND					= 0x8002013b,	
	SCE_KERNEL_ERROR_LIBRARY_NOTFOUND				= 0x8002013c,	
	SCE_KERNEL_ERROR_ILLEGAL_LIBRARY				= 0x8002013d,	
	SCE_KERNEL_ERROR_LIBRARY_INUSE					= 0x8002013e,	
	SCE_KERNEL_ERROR_ALREADY_STOPPING				= 0x8002013f,	
	SCE_KERNEL_ERROR_ILLEGAL_OFFSET					= 0x80020140,	
	SCE_KERNEL_ERROR_ILLEGAL_POSITION				= 0x80020141,	
	SCE_KERNEL_ERROR_ILLEGAL_ACCESS					= 0x80020142,	
	SCE_KERNEL_ERROR_MODULE_MGR_BUSY				= 0x80020143,	
	SCE_KERNEL_ERROR_ILLEGAL_FLAG					= 0x80020144,	
	SCE_KERNEL_ERROR_CANNOT_GET_MODULELIST			= 0x80020145,	
	SCE_KERNEL_ERROR_PROHIBIT_LOADMODULE_DEVICE		= 0x80020146,	
	SCE_KERNEL_ERROR_PROHIBIT_LOADEXEC_DEVICE		= 0x80020147,	
	SCE_KERNEL_ERROR_UNSUPPORTED_PRX_TYPE			= 0x80020148,	
	SCE_KERNEL_ERROR_ILLEGAL_PERM_CALL				= 0x80020149,	
	SCE_KERNEL_ERROR_CANNOT_GET_MODULE_INFORMATION	= 0x8002014a,	
	SCE_KERNEL_ERROR_ILLEGAL_LOADEXEC_BUFFER		= 0x8002014b,	
	SCE_KERNEL_ERROR_ILLEGAL_LOADEXEC_FILENAME		= 0x8002014c,	
	SCE_KERNEL_ERROR_NO_EXIT_CALLBACK				= 0x8002014d,	
	SCE_KERNEL_ERROR_NO_MEMORY						= 0x80020190,	
	SCE_KERNEL_ERROR_ILLEGAL_ATTR					= 0x80020191,	
	SCE_KERNEL_ERROR_ILLEGAL_ENTRY					= 0x80020192,	
	SCE_KERNEL_ERROR_ILLEGAL_PRIORITY				= 0x80020193,	
	SCE_KERNEL_ERROR_ILLEGAL_STACK_SIZE				= 0x80020194,	
	SCE_KERNEL_ERROR_ILLEGAL_MODE					= 0x80020195,	
	SCE_KERNEL_ERROR_ILLEGAL_MASK					= 0x80020196,	
	SCE_KERNEL_ERROR_ILLEGAL_THID					= 0x80020197,	
	SCE_KERNEL_ERROR_UNKNOWN_THID					= 0x80020198,	
	SCE_KERNEL_ERROR_UNKNOWN_SEMID					= 0x80020199,	
	SCE_KERNEL_ERROR_UNKNOWN_EVFID					= 0x8002019a,	
	SCE_KERNEL_ERROR_UNKNOWN_MBXID					= 0x8002019b,	
	SCE_KERNEL_ERROR_UNKNOWN_VPLID					= 0x8002019c,	
	SCE_KERNEL_ERROR_UNKNOWN_FPLID					= 0x8002019d,	
	SCE_KERNEL_ERROR_UNKNOWN_MPPID					= 0x8002019e,	
	SCE_KERNEL_ERROR_UNKNOWN_ALMID					= 0x8002019f,	
	SCE_KERNEL_ERROR_UNKNOWN_TEID					= 0x800201a0,	
	SCE_KERNEL_ERROR_UNKNOWN_CBID					= 0x800201a1,	
	SCE_KERNEL_ERROR_DORMANT						= 0x800201a2,	
	SCE_KERNEL_ERROR_SUSPEND						= 0x800201a3,	
	SCE_KERNEL_ERROR_NOT_DORMANT					= 0x800201a4,	
	SCE_KERNEL_ERROR_NOT_SUSPEND					= 0x800201a5,	
	SCE_KERNEL_ERROR_NOT_WAIT						= 0x800201a6,	
	SCE_KERNEL_ERROR_CAN_NOT_WAIT					= 0x800201a7,	
	SCE_KERNEL_ERROR_WAIT_TIMEOUT					= 0x800201a8,	
	SCE_KERNEL_ERROR_WAIT_CANCEL					= 0x800201a9,	
	SCE_KERNEL_ERROR_RELEASE_WAIT					= 0x800201aa,	
	SCE_KERNEL_ERROR_NOTIFY_CALLBACK				= 0x800201ab,	
	SCE_KERNEL_ERROR_THREAD_TERMINATED				= 0x800201ac,	
	SCE_KERNEL_ERROR_SEMA_ZERO						= 0x800201ad,	
	SCE_KERNEL_ERROR_SEMA_OVF						= 0x800201ae,	
	SCE_KERNEL_ERROR_EVF_COND						= 0x800201af,	
	SCE_KERNEL_ERROR_EVF_MULTI						= 0x800201b0,	
	SCE_KERNEL_ERROR_EVF_ILPAT						= 0x800201b1,	
	SCE_KERNEL_ERROR_MBOX_NOMSG						= 0x800201b2,	
	SCE_KERNEL_ERROR_MPP_FULL						= 0x800201b3,	
	SCE_KERNEL_ERROR_MPP_EMPTY						= 0x800201b4,	
	SCE_KERNEL_ERROR_WAIT_DELETE					= 0x800201b5,	
	SCE_KERNEL_ERROR_ILLEGAL_MEMBLOCK				= 0x800201b6,	
	SCE_KERNEL_ERROR_ILLEGAL_MEMSIZE				= 0x800201b7,	
	SCE_KERNEL_ERROR_ILLEGAL_SPADADDR				= 0x800201b8,	
	SCE_KERNEL_ERROR_SPAD_INUSE						= 0x800201b9,	
	SCE_KERNEL_ERROR_SPAD_NOT_INUSE					= 0x800201ba,	
	SCE_KERNEL_ERROR_ILLEGAL_TYPE					= 0x800201bb,	
	SCE_KERNEL_ERROR_ILLEGAL_SIZE					= 0x800201bc,	
	SCE_KERNEL_ERROR_ILLEGAL_COUNT					= 0x800201bd,	
	SCE_KERNEL_ERROR_UNKNOWN_VTID					= 0x800201be,	
	SCE_KERNEL_ERROR_ILLEGAL_VTID					= 0x800201bf,	
	SCE_KERNEL_ERROR_ILLEGAL_KTLSID					= 0x800201c0,	
	SCE_KERNEL_ERROR_KTLS_FULL						= 0x800201c1,	
	SCE_KERNEL_ERROR_KTLS_BUSY						= 0x800201c2,	
	SCE_KERNEL_ERROR_PM_INVALID_PRIORITY			= 0x80020258,	
	SCE_KERNEL_ERROR_PM_INVALID_DEVNAME				= 0x80020259,	
	SCE_KERNEL_ERROR_PM_UNKNOWN_DEVNAME				= 0x8002025a,	
	SCE_KERNEL_ERROR_PM_PMINFO_REGISTERED			= 0x8002025b,	
	SCE_KERNEL_ERROR_PM_PMINFO_UNREGISTERED			= 0x8002025c,	
	SCE_KERNEL_ERROR_PM_INVALID_MAJOR_STATE			= 0x8002025d,	
	SCE_KERNEL_ERROR_PM_INVALID_REQUEST				= 0x8002025e,	
	SCE_KERNEL_ERROR_PM_UNKNOWN_REQUEST				= 0x8002025f,	
	SCE_KERNEL_ERROR_PM_INVALID_UNIT				= 0x80020260,	
	SCE_KERNEL_ERROR_PM_CANNOT_CANCEL				= 0x80020261,	
	SCE_KERNEL_ERROR_PM_INVALID_PMINFO				= 0x80020262,	
	SCE_KERNEL_ERROR_PM_INVALID_ARGUMENT			= 0x80020263,	
	SCE_KERNEL_ERROR_PM_ALREADY_TARGET_PWRSTATE		= 0x80020264,	
	SCE_KERNEL_ERROR_PM_CHANGE_PWRSTATE_FAILED		= 0x80020265,	
	SCE_KERNEL_ERROR_PM_CANNOT_CHANGE_DEVPWR_STATE	= 0x80020266,	
	SCE_KERNEL_ERROR_PM_NO_SUPPORT_DEVPWR_STATE		= 0x80020267,	
	SCE_KERNEL_ERROR_DMAC_REQUEST_FAILED			= 0x800202bc,	
	SCE_KERNEL_ERROR_DMAC_REQUEST_DENIED			= 0x800202bd,	
	SCE_KERNEL_ERROR_DMAC_OP_QUEUED					= 0x800202be,	
	SCE_KERNEL_ERROR_DMAC_OP_NOT_QUEUED				= 0x800202bf,	
	SCE_KERNEL_ERROR_DMAC_OP_RUNNING				= 0x800202c0,	
	SCE_KERNEL_ERROR_DMAC_OP_NOT_ASSIGNED			= 0x800202c1,	
	SCE_KERNEL_ERROR_DMAC_OP_TIMEOUT				= 0x800202c2,	
	SCE_KERNEL_ERROR_DMAC_OP_FREED					= 0x800202c3,	
	SCE_KERNEL_ERROR_DMAC_OP_USED					= 0x800202c4,	
	SCE_KERNEL_ERROR_DMAC_OP_EMPTY					= 0x800202c5,	
	SCE_KERNEL_ERROR_DMAC_OP_ABORTED				= 0x800202c6,	
	SCE_KERNEL_ERROR_DMAC_OP_ERROR					= 0x800202c7,	
	SCE_KERNEL_ERROR_DMAC_CHANNEL_RESERVED			= 0x800202c8,	
	SCE_KERNEL_ERROR_DMAC_CHANNEL_EXCLUDED			= 0x800202c9,	
	SCE_KERNEL_ERROR_DMAC_PRIVILEGE_ADDRESS			= 0x800202ca,	
	SCE_KERNEL_ERROR_DMAC_NO_ENOUGHSPACE			= 0x800202cb,	
	SCE_KERNEL_ERROR_DMAC_CHANNEL_NOT_ASSIGNED		= 0x800202cc,	
	SCE_KERNEL_ERROR_DMAC_CHILD_OPERATION			= 0x800202cd,	
	SCE_KERNEL_ERROR_DMAC_TOO_MUCH_SIZE				= 0x800202ce,	
	SCE_KERNEL_ERROR_DMAC_INVALID_ARGUMENT			= 0x800202cf,	
	SCE_KERNEL_ERROR_MFILE							= 0x80020320,	
	SCE_KERNEL_ERROR_NODEV							= 0x80020321,	
	SCE_KERNEL_ERROR_XDEV							= 0x80020322,	
	SCE_KERNEL_ERROR_BADF							= 0x80020323,	
	SCE_KERNEL_ERROR_INVAL							= 0x80020324,	
	SCE_KERNEL_ERROR_UNSUP							= 0x80020325,	
	SCE_KERNEL_ERROR_ALIAS_USED						= 0x80020326,	
	SCE_KERNEL_ERROR_CANNOT_MOUNT					= 0x80020327,	
	SCE_KERNEL_ERROR_DRIVER_DELETED					= 0x80020328,	
	SCE_KERNEL_ERROR_ASYNC_BUSY						= 0x80020329,	
	SCE_KERNEL_ERROR_NOASYNC						= 0x8002032a,	
	SCE_KERNEL_ERROR_REGDEV							= 0x8002032b,	
	SCE_KERNEL_ERROR_NOCWD							= 0x8002032c,	
	SCE_KERNEL_ERROR_NAMETOOLONG					= 0x8002032d,	
	SCE_KERNEL_ERROR_NXIO							= 0x800203e8,	
	SCE_KERNEL_ERROR_IO								= 0x800203e9,	
	SCE_KERNEL_ERROR_NOMEM							= 0x800203ea,	
	SCE_KERNEL_ERROR_STDIO_NOT_OPENED				= 0x800203eb,	
	SCE_KERNEL_ERROR_CACHE_ALIGNMENT				= 0x8002044c,	
	SCE_KERNEL_ERROR_ERRORMAX						= 0x8002044d
};

extern unsigned int CheckKernelError(unsigned int error_code);

#endif /* PSPKERROR_H */
