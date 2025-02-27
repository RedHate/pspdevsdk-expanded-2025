	.set noreorder

#include "pspimport.s"

#ifdef F_sceSha384_0000
	IMPORT_START "sceSha384", 0x00010011
#endif
#ifdef F_sceSha384_0001
	IMPORT_FUNC  "sceSha384", 0xD7DF2B41, sceSha384Digest
#endif
#ifdef F_sceSha384_0002
	IMPORT_FUNC  "sceSha384", 0x139319AF, sceSha384BlockInit
#endif
#ifdef F_sceSha384_0003
	IMPORT_FUNC  "sceSha384", 0x9CC3A3A2, sceSha384BlockUpdate
#endif
#ifdef F_sceSha384_0004
	IMPORT_FUNC  "sceSha384", 0xD9E51292, sceSha384BlockResult
#endif
