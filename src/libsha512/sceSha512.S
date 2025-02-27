	.set noreorder

#include "pspimport.s"

#ifdef F_sceSha512_0000
	IMPORT_START "sceSha512", 0x00010011
#endif
#ifdef F_sceSha512_0001
	IMPORT_FUNC	"sceSha512", 0x5AFE898D,sceSha512Digest
#endif
#ifdef F_sceSha512_0002
	IMPORT_FUNC	"sceSha512", 0x16ED8DC6,sceSha512BlockInit
#endif
#ifdef F_sceSha512_0003
	IMPORT_FUNC	"sceSha512", 0x8208F538,sceSha512BlockUpdate
#endif
#ifdef F_sceSha512_0004
	IMPORT_FUNC	"sceSha512", 0xAAB6221E,sceSha512BlockResult
#endif

#ifdef __cplusplus
}
#endif
