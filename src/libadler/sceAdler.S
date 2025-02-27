	.set noreorder

#include "pspimport.s"

#ifdef F_sceAdler_0000
	IMPORT_START "sceAdler", 0x00010011
#endif
#ifdef F_sceAdler_0001
	IMPORT_FUNC	"sceAdler", 0x9702EF11, sceAdler32
#endif

