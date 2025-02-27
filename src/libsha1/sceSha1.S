	.set noreorder

#include "pspimport.s"

#ifdef F_sceSha1_0000
	IMPORT_START "sceSha1", 0x00010011
#endif
#ifdef F_sceSha1_0001
	IMPORT_FUNC	"sceSha1", 0xB94ACDAE, sceSha1Digest
#endif
#ifdef F_sceSha1_0002
	IMPORT_FUNC	"sceSha1", 0x4A80340A, sceSha1BlockInit
#endif
#ifdef F_sceSha1_0003
	IMPORT_FUNC	"sceSha1", 0x5AF85569, sceSha1BlockUpdate
#endif
#ifdef F_sceSha1_0004
	IMPORT_FUNC	"sceSha1", 0x78EDE680, sceSha1BlockResult
#endif

