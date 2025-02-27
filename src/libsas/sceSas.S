	.set noreorder

#include "pspimport.s"

#ifdef F_sceSas_0000
	IMPORT_START "sceSas", 0x00010011
#endif
#ifdef F_sceSas_0001
	IMPORT_FUNC	"sceSas", 0x95753375, sceSasInit
#endif
#ifdef F_sceSas_0002
	IMPORT_FUNC	"sceSas", 0xA9EE1EB0, sceSasExit
#endif
#ifdef F_sceSas_0003
	IMPORT_FUNC	"sceSas", 0x44D0F1CD, sceSasCore
#endif
#ifdef F_sceSas_0004
	IMPORT_FUNC	"sceSas", 0x14D3B51B, sceSasSetKeyOn
#endif
#ifdef F_sceSas_0005
	IMPORT_FUNC	"sceSas", 0x5E2A61FF, sceSasSetKeyOff
#endif
#ifdef F_sceSas_0006
	IMPORT_FUNC	"sceSas", 0x019A0EA6, sceSasSetVolume
#endif
#ifdef F_sceSas_0007
	IMPORT_FUNC	"sceSas", 0xE1F3768C, sceSasSetPitch
#endif
#ifdef F_sceSas_0008
	IMPORT_FUNC	"sceSas", 0x63DDD6B6, sceSasSetVoice
#endif
#ifdef F_sceSas_0009
	IMPORT_FUNC	"sceSas", 0x60CCE850, sceSasSetNoise
#endif
#ifdef F_sceSas_0010
	IMPORT_FUNC	"sceSas", 0xE8F52AC1, sceSasSetADSR
#endif
#ifdef F_sceSas_0011
	IMPORT_FUNC	"sceSas", 0xB1340102, sceSasSetADSRmode
#endif
#ifdef F_sceSas_0012
	IMPORT_FUNC	"sceSas", 0x02A54B9A, sceSasSetSL
#endif
#ifdef F_sceSas_0013
	IMPORT_FUNC	"sceSas", 0xCFEC4438, sceSasSetSimpleADSR
#endif
#ifdef F_sceSas_0014
	IMPORT_FUNC	"sceSas", 0xE87C4818, sceSasGetEndFlag
#endif
#ifdef F_sceSas_0015
	IMPORT_FUNC	"sceSas", 0x7EA3C731, sceSasGetEnvelope
#endif
#ifdef F_sceSas_0016
	IMPORT_FUNC	"sceSas", 0x8F237E10, sceSasSetEffect
#endif
#ifdef F_sceSas_0017
	IMPORT_FUNC	"sceSas", 0x25852A23, sceSasSetEffectVolume
#endif
#ifdef F_sceSas_0018
	IMPORT_FUNC	"sceSas", 0x23CC59FC, sceSasSetEffectType
#endif
#ifdef F_sceSas_0019
	IMPORT_FUNC	"sceSas", 0xD03476B6, sceSasSetEffectParam
#endif


#ifdef __cplusplus
}
#endif
