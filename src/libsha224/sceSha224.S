	.set noreorder

#include "pspimport.s"

#ifdef F_sceSha224_0000
	IMPORT_START "sceSha224", 0x00010011
#endif
#ifdef F_sceSha224_0001
	IMPORT_FUNC	"sceSha224", 0x5BE354EA,sceSha224Digest
#endif
#ifdef F_sceSha224_0002
	IMPORT_FUNC	"sceSha224", 0x3A96138F,sceSha224BlockInit
#endif
#ifdef F_sceSha224_0003
	IMPORT_FUNC	"sceSha224", 0xEF597FC7,sceSha224BlockUpdate
#endif
#ifdef F_sceSha224_0004
	IMPORT_FUNC	"sceSha224", 0xD6A3ADCB,sceSha224BlockResult
#endif

#ifdef __cplusplus
}
#endif
