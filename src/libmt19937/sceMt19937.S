	.set noreorder

#include "pspimport.s"

#ifdef F_sceMt19937_0000
	IMPORT_START "sceMt19937", 0x00010011
#endif
#ifdef F_sceMt19937_0001
	IMPORT_FUNC	"sceMt19937",0xECF5D379,sceMt19937Init
#endif
#ifdef F_sceMt19937_0002
	IMPORT_FUNC	"sceMt19937",0xF40C98E6,sceMt19937UInt
#endif

#ifdef __cplusplus
}
#endif
