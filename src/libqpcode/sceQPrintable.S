	.set noreorder

#include "pspimport.s"

#ifdef F_sceQPrintable_0000
	IMPORT_START "sceQPrintable", 0x00010011
#endif
#ifdef F_sceQPrintable_0001
	IMPORT_FUNC	"sceQPrintable", 0x2B235B5A, sceQPrintableLineDecoder
#endif
#ifdef F_sceQPrintable_0002
	IMPORT_FUNC	"sceQPrintable", 0x69752447, sceQPrintableEncoder
#endif

#ifdef __cplusplus
}
#endif
