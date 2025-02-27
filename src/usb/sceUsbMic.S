	.set noreorder

#include "pspimport.s"

#ifdef F_sceUsbMic_0000
	IMPORT_START	"sceUsbMic",0x40090011
#endif
#ifdef F_sceUsbMic_0001
	IMPORT_FUNC	"sceUsbMic",0x06128E42,sceUsbMicPollInputEnd
#endif
#ifdef F_sceUsbMic_0002
	IMPORT_FUNC	"sceUsbMic",0x2E6DCDCD,sceUsbMicInputBlocking
#endif
#ifdef F_sceUsbMic_0003
	IMPORT_FUNC	"sceUsbMic",0x45310F07,sceUsbMicInputInitEx
#endif
#ifdef F_sceUsbMic_0004
	IMPORT_FUNC	"sceUsbMic",0x5f7f368D,sceUsbMicInput
#endif
#ifdef F_sceUsbMic_0005
	IMPORT_FUNC	"sceUsbMic",0x63400E20,sceUsbMicGetInputLength
#endif
#ifdef F_sceUsbMic_0006
	IMPORT_FUNC	"sceUsbMic",0xB8E536EB,sceUsbMicInputInit
#endif
#ifdef F_sceUsbMic_0007
	IMPORT_FUNC	"sceUsbMic",0xF899001C,sceUsbMicWaitInputEnd
#endif

#ifdef __cplusplus
}
#endif
