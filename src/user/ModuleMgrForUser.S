	.set noreorder

#include "pspimport.s"

#ifdef F_ModuleMgrForUser_0000
	IMPORT_START	"ModuleMgrForUser",0x40010000
#endif
#ifdef F_ModuleMgrForUser_0001
	IMPORT_FUNC	"ModuleMgrForUser",0xB7F46618,sceKernelLoadModuleByID
#endif
#ifdef F_ModuleMgrForUser_0002
	IMPORT_FUNC	"ModuleMgrForUser",0x977DE386,sceKernelLoadModule
#endif
#ifdef F_ModuleMgrForUser_0003
	IMPORT_FUNC	"ModuleMgrForUser",0x710F61B5,sceKernelLoadModuleMs
#endif
#ifdef F_ModuleMgrForUser_0004
	IMPORT_FUNC	"ModuleMgrForUser",0xF9275D98,sceKernelLoadModuleBufferUsbWlan
#endif
#ifdef F_ModuleMgrForUser_0005
	IMPORT_FUNC	"ModuleMgrForUser",0x50F0C1EC,sceKernelStartModule
#endif
#ifdef F_ModuleMgrForUser_0006
	IMPORT_FUNC	"ModuleMgrForUser",0xD1FF982A,sceKernelStopModule
#endif
#ifdef F_ModuleMgrForUser_0007
	IMPORT_FUNC	"ModuleMgrForUser",0x2E0911AA,sceKernelUnloadModule
#endif
#ifdef F_ModuleMgrForUser_0008
	IMPORT_FUNC	"ModuleMgrForUser",0xD675EBB8,sceKernelSelfStopUnloadModule
#endif
#ifdef F_ModuleMgrForUser_0009
	IMPORT_FUNC	"ModuleMgrForUser",0xCC1D3699,sceKernelStopUnloadSelfModule
#endif
#ifdef F_ModuleMgrForUser_0010
	IMPORT_FUNC	"ModuleMgrForUser",0x748CBED9,sceKernelQueryModuleInfo
#endif
#ifdef F_ModuleMgrForUser_0011
	IMPORT_FUNC "ModuleMgrForUser", 0x644395E2,sceKernelGetModuleIdList
#endif
#ifdef F_ModuleMgrForUser_0012
	IMPORT_FUNC "ModuleMgrForUser",0xD8B73127,sceKernelGetModuleIdByAddress
#endif
#ifdef F_ModuleMgrForUser_0013
	IMPORT_FUNC	"ModuleMgrForUser",0xF32A2940,sceKernelModuleFromUID
#endif
#ifdef F_ModuleMgrForUser_0014
	IMPORT_FUNC	"ModuleMgrForUser",0xCD0F3BAC,sceKernelCreateModule
#endif
#ifdef F_ModuleMgrForUser_0015
	IMPORT_FUNC	"ModuleMgrForUser",0x6B2371C2,sceKernelDeleteModule
#endif
#ifdef F_ModuleMgrForUser_0016
	IMPORT_FUNC	"ModuleMgrForUser",0x7320D964,sceKernelModuleAssign
#endif
#ifdef F_ModuleMgrForUser_0017
	IMPORT_FUNC	"ModuleMgrForUser",0x44B292AB,sceKernelAllocModule
#endif
#ifdef F_ModuleMgrForUser_0018
	IMPORT_FUNC	"ModuleMgrForUser",0xBD61D4D5,sceKernelFreeModule
#endif
#ifdef F_ModuleMgrForUser_0019
	IMPORT_FUNC	"ModuleMgrForUser",0xAE7C6E76,sceKernelRegisterModule
#endif
#ifdef F_ModuleMgrForUser_0020
	IMPORT_FUNC	"ModuleMgrForUser",0x74CF001A,sceKernelReleaseModule
#endif
#ifdef F_ModuleMgrForUser_0021
	IMPORT_FUNC	"ModuleMgrForUser",0xCF8A41B1,sceKernelFindModuleByName
#endif
#ifdef F_ModuleMgrForUser_0022
	IMPORT_FUNC	"ModuleMgrForUser",0xFB8AE27D,sceKernelFindModuleByAddress
#endif
#ifdef F_ModuleMgrForUser_0023
	IMPORT_FUNC	"ModuleMgrForUser",0xCCE4A157,sceKernelFindModuleByUID
#endif
#ifdef F_ModuleMgrForUser_0024
	IMPORT_FUNC	"ModuleMgrForUser",0x82CE54ED,sceKernelModuleCount
#endif
#ifdef F_ModuleMgrForUser_0025
	IMPORT_FUNC	"ModuleMgrForUser",0xC0584F0C,sceKernelGetModuleList
#endif
