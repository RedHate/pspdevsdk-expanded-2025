	.set noreorder

#include "pspimport.s"

#ifdef F_scePsmf_0000
	IMPORT_START "scePsmf", 0x00010011
#endif
#ifdef F_scePsmf_0001
	IMPORT_FUNC	"scePsmf", 0xC22C8327, scePsmfSetPsmf
#endif
#ifdef F_scePsmf_0002
	IMPORT_FUNC	"scePsmf", 0xC7DB3A5B, scePsmfGetCurrentStreamType
#endif
#ifdef F_scePsmf_0003
	IMPORT_FUNC	"scePsmf", 0x28240568, scePsmfGetCurrentStreamNumber
#endif
#ifdef F_scePsmf_0004
	IMPORT_FUNC	"scePsmf", 0x1E6D9013, scePsmfSpecifyStreamWithStreamType
#endif
#ifdef F_scePsmf_0005
	IMPORT_FUNC	"scePsmf", 0x4BC9BDE0, scePsmfSpecifyStream
#endif
#ifdef F_scePsmf_0006
	IMPORT_FUNC	"scePsmf", 0x0C120E1D, scePsmfSpecifyStreamWithStreamTypeNumber
#endif
#ifdef F_scePsmf_0007
	IMPORT_FUNC	"scePsmf", 0x76D3AEBA, scePsmfGetPresentationStartTime
#endif
#ifdef F_scePsmf_0008
	IMPORT_FUNC	"scePsmf", 0xBD8AE0D8, scePsmfGetPresentationEndTime
#endif
#ifdef F_scePsmf_0009
	IMPORT_FUNC	"scePsmf", 0xEAED89CD, scePsmfGetNumberOfStreams
#endif
#ifdef F_scePsmf_0010
	IMPORT_FUNC	"scePsmf", 0x68D42328, scePsmfGetNumberOfSpecificStreams
#endif
#ifdef F_scePsmf_0011
	IMPORT_FUNC	"scePsmf", 0x0BA514E5, scePsmfGetVideoInfo
#endif
#ifdef F_scePsmf_0012
	IMPORT_FUNC	"scePsmf", 0xA83F7113, scePsmfGetAudioInfo
#endif
#ifdef F_scePsmf_0013
	IMPORT_FUNC	"scePsmf", 0x7491C438, scePsmfGetNumberOfEPentries
#endif
#ifdef F_scePsmf_0014
	IMPORT_FUNC	"scePsmf", 0x971A3A90, scePsmfCheckEPmap
#endif
#ifdef F_scePsmf_0015
	IMPORT_FUNC	"scePsmf", 0x4E624A34, scePsmfGetEPWithId
#endif
#ifdef F_scePsmf_0016
	IMPORT_FUNC	"scePsmf", 0x7C0E7AC3, scePsmfGetEPWithTimestamp
#endif
#ifdef F_scePsmf_0017
	IMPORT_FUNC	"scePsmf", 0x5F457515, scePsmfGetEPidWithTimestamp
#endif
#ifdef F_scePsmf_0018
	IMPORT_FUNC	"scePsmf", 0x9553CC91, scePsmfQueryStreamSize
#endif
#ifdef F_scePsmf_0019
	IMPORT_FUNC	"scePsmf", 0x5B70FCC1, scePsmfQueryStreamOffset
#endif

#ifdef __cplusplus
}
#endif
