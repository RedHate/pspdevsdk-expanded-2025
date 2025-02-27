	.set noreorder

#include "pspimport.s"

#ifdef F_sceSha256_0000
	IMPORT_START "sceSha256", 0x00010011
#endif
#ifdef F_sceSha256_0001
	IMPORT_FUNC	"sceSha256", 0x318A350C,sceSha256Digest
#endif
#ifdef F_sceSha256_0002
	IMPORT_FUNC	"sceSha256", 0x5368F1BC,sceSha256BlockInit
#endif
#ifdef F_sceSha256_0003
	IMPORT_FUNC	"sceSha256", 0x7310DDCF,sceSha256BlockUpdate
#endif
#ifdef F_sceSha256_0004
	IMPORT_FUNC	"sceSha256", 0x82C67FB3,sceSha256BlockResult
#endif

#ifdef __cplusplus
}
#endif
