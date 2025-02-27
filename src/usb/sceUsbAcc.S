	.set noreorder

#include "pspimport.s"

#ifdef F_sceUsbAcc_0000
	IMPORT_START	"sceUsbAcc",0x40010000
#endif
#ifdef F_sceUsbAcc_0001
	IMPORT_FUNC	"sceUsbAcc",0xAE5DE6AF,sceUsbAccGetInfo
#endif
#ifdef F_sceUsbAcc_0002
	IMPORT_FUNC	"sceUsbAcc",0xC2464FA0,sceUsbAccUnregisterType
#endif
#ifdef F_sceUsbAcc_0003
	IMPORT_FUNC	"sceUsbAcc",0xC21645A4,sceUsbAccRegisterType
#endif
#ifdef F_sceUsbAcc_0004
	IMPORT_FUNC	"sceUsbAcc",0x4E537366,sceUsbAccGetAuthStat
#endif
