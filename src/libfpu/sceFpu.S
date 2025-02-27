	.set noreorder

#include "pspimport.s"

#ifdef F_sceFpu_0000
	IMPORT_START "sceFpu", 0x00010011
#endif
#ifdef F_sceFpu_0001
	IMPORT_FUNC	"sceFpu", 0x6CF7A73F,sceFpuGetFCR31
#endif
#ifdef F_sceFpu_0002
	IMPORT_FUNC	"sceFpu", 0xB9EEFCEA,sceFpuSetFCR31
#endif
#ifdef F_sceFpu_0003
	IMPORT_FUNC	"sceFpu", 0x5810B6C0,sceFpuAbs
#endif
#ifdef F_sceFpu_0004
	IMPORT_FUNC	"sceFpu", 0x8F3D00D1,sceFpuCeil
#endif
#ifdef F_sceFpu_0005
	IMPORT_FUNC	"sceFpu", 0x74161A40,sceFpuFloor
#endif
#ifdef F_sceFpu_0006
	IMPORT_FUNC	"sceFpu", 0x481F6EAF,sceFpuMax
#endif
#ifdef F_sceFpu_0007
	IMPORT_FUNC	"sceFpu", 0x8CAFBA79,sceFpuMin
#endif
#ifdef F_sceFpu_0008
	IMPORT_FUNC	"sceFpu", 0x2A0CEBD8,sceFpuNeg
#endif
#ifdef F_sceFpu_0009
	IMPORT_FUNC	"sceFpu", 0x3AF6984A,sceFpuRound
#endif
#ifdef F_sceFpu_0010
	IMPORT_FUNC	"sceFpu", 0xF6F20C83,sceFpuRsqrt
#endif
#ifdef F_sceFpu_0011
	IMPORT_FUNC	"sceFpu", 0x40303F26,sceFpuSqrt
#endif
#ifdef F_sceFpu_0012
	IMPORT_FUNC	"sceFpu", 0x73136289,sceFpuTrunc
#endif
#ifdef F_sceFpu_0013
	IMPORT_FUNC	"sceFpu", 0x6FBCB52E,sceFpuFmod
#endif
#ifdef F_sceFpu_0014
	IMPORT_FUNC	"sceFpu", 0xC0614AD2,sceFpuFrac
#endif
#ifdef F_sceFpu_0015
	IMPORT_FUNC	"sceFpu", 0x06E1C655,sceFpuReinterpretFloat
#endif
#ifdef F_sceFpu_0016
	IMPORT_FUNC	"sceFpu", 0x67EF7B8E,sceFpuReinterpretUint
#endif
#ifdef F_sceFpu_0017
	IMPORT_FUNC	"sceFpu", 0x09271163,sceFpuIsEqual
#endif
#ifdef F_sceFpu_0018
	IMPORT_FUNC	"sceFpu", 0x2D9961EE,sceFpuSignFloat
#endif
#ifdef F_sceFpu_0019
	IMPORT_FUNC	"sceFpu", 0xAB081BAF,sceFpuSignInt
#endif
#ifdef F_sceFpu_0020
	IMPORT_FUNC	"sceFpu", 0x7E01ACC3,sceFpuPositiveZero
#endif
#ifdef F_sceFpu_0021
	IMPORT_FUNC	"sceFpu", 0x42667A9F,sceFpuNegativeZero
#endif
#ifdef F_sceFpu_0022
	IMPORT_FUNC	"sceFpu", 0xE0D05CDA,sceFpuIsZero
#endif
#ifdef F_sceFpu_0023
	IMPORT_FUNC	"sceFpu", 0x79722000,sceFpuIsPositiveZero
#endif
#ifdef F_sceFpu_0024
	IMPORT_FUNC	"sceFpu", 0xFBA12688,sceFpuIsNegativeZero
#endif
#ifdef F_sceFpu_0025
	IMPORT_FUNC	"sceFpu", 0xA732EBAB,sceFpuIsDenormal
#endif
#ifdef F_sceFpu_0026
	IMPORT_FUNC	"sceFpu", 0x4B113CEA,sceFpuIsZeroOrDenormal
#endif
#ifdef F_sceFpu_0027
	IMPORT_FUNC	"sceFpu", 0xE677494E,sceFpuPositiveInf
#endif
#ifdef F_sceFpu_0028
	IMPORT_FUNC	"sceFpu", 0x1384643F,sceFpuNegativeInf
#endif
#ifdef F_sceFpu_0029
	IMPORT_FUNC	"sceFpu", 0xEEE709DE,sceFpuIsInf
#endif
#ifdef F_sceFpu_0030
	IMPORT_FUNC	"sceFpu", 0x9072D087,sceFpuPositiveNaN
#endif
#ifdef F_sceFpu_0031
	IMPORT_FUNC	"sceFpu", 0xB046B635,sceFpuNegativeNaN
#endif
#ifdef F_sceFpu_0032
	IMPORT_FUNC	"sceFpu", 0x1679670E,sceFpuPositiveQNaN
#endif
#ifdef F_sceFpu_0033
	IMPORT_FUNC	"sceFpu", 0xDE6648F8,sceFpuNegativeQNaN
#endif
#ifdef F_sceFpu_0034
	IMPORT_FUNC	"sceFpu", 0xBBAECB62,sceFpuPositiveSNaN
#endif
#ifdef F_sceFpu_0035
	IMPORT_FUNC	"sceFpu", 0xB5BC35DD,sceFpuNegativeSNaN
#endif
#ifdef F_sceFpu_0036
	IMPORT_FUNC	"sceFpu", 0xC2D5027F,sceFpuIsNaN
#endif
#ifdef F_sceFpu_0037
	IMPORT_FUNC	"sceFpu", 0xD528E708,sceFpuIsInfOrNaN
#endif
#ifdef F_sceFpu_0038
	IMPORT_FUNC	"sceFpu", 0x02BC1561,sceFpuNormalizePhase
#endif
#ifdef F_sceFpu_0039
	IMPORT_FUNC	"sceFpu", 0xA38AA0E9,sceFpuSin
#endif
#ifdef F_sceFpu_0040
	IMPORT_FUNC	"sceFpu", 0x0D801700,sceFpuCos
#endif
#ifdef F_sceFpu_0041
	IMPORT_FUNC	"sceFpu", 0xDA34FB1A,sceFpuAtan
#endif
#ifdef F_sceFpu_0042
	IMPORT_FUNC	"sceFpu", 0x3A8B8E77,sceFpuLog
#endif
#ifdef F_sceFpu_0043
	IMPORT_FUNC	"sceFpu", 0x65F397E6,sceFpuExp
#endif
#ifdef F_sceFpu_0044
	IMPORT_FUNC	"sceFpu", 0x0377975D,sceFpuFloatToDouble
#endif
#ifdef F_sceFpu_0045
	IMPORT_FUNC	"sceFpu", 0xB746B722,sceFpuDoubleToFloat
#endif

#ifdef __cplusplus
}
#endif
