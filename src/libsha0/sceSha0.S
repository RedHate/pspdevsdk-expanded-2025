	.set noreorder

#include "pspimport.s"

#ifdef F_sceSha0_0000
	IMPORT_START "sceSha0", 0x00010011
#endif
#ifdef F_sceSha0_0001
	IMPORT_FUNC  "sceSha0", 0x931612A8, sceSha0Digest
#endif
#ifdef F_sceSha0_0002
	IMPORT_FUNC  "sceSha0", 0x1070B261, sceSha0lockInit
#endif
#ifdef F_sceSha0_0003
	IMPORT_FUNC  "sceSha0", 0x91524E96, sceSha0BlockUpdate
#endif
#ifdef F_sceSha0_0004
	IMPORT_FUNC  "sceSha0", 0x86E64331, sceSha0BlockResult
#endif
