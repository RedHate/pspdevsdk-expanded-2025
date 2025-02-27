	.set noreorder

#include "pspimport.s"

#ifdef F_sceBase64_0000
	IMPORT_START	"sceBase64", 0x00010011
#endif
#ifdef F_sceBase64_0001
	IMPORT_FUNC	"sceBase64", 0x43543731, sceBase64Encoder
#endif
#ifdef F_sceBase64_0002
	IMPORT_FUNC	"sceBase64", 0x3AE99AAF, sceBase64Decoder
#endif

#ifdef __cplusplus
}
#endif
