	.set noreorder

#include "pspimport.s"

#ifdef F_sceMd5_0000
	IMPORT_START "sceMd5", 0x00010011
#endif
#ifdef F_sceMd5_0001
	IMPORT_FUNC	"sceMd5", 0x98E31A9E, sceMd5Digest
#endif
#ifdef F_sceMd5_0002
	IMPORT_FUNC	"sceMd5", 0x19884A15, sceMd5BlockInit
#endif
#ifdef F_sceMd5_0003
	IMPORT_FUNC	"sceMd5", 0xA30206C2, sceMd5BlockUpdate
#endif
#ifdef F_sceMd5_0004
	IMPORT_FUNC	"sceMd5", 0x4876AFFF, sceMd5BlockResult
#endif

#ifdef __cplusplus
}
#endif




