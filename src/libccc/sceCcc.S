	.set noreorder

#include "pspimport.s"

#ifdef F_sceCcc_0000
	IMPORT_START "sceCcc", 0x00010011
#endif
#ifdef F_sceCcc_0001
	IMPORT_FUNC	"sceCcc", 0xB4D1CBBF, sceCccStrlenUTF16
#endif
#ifdef F_sceCcc_0002
	IMPORT_FUNC	"sceCcc", 0x4BDEB2A8, sceCccStrlenUTF8
#endif
#ifdef F_sceCcc_0003
	IMPORT_FUNC	"sceCcc", 0xB7D3C112, sceCccStrlenSJIS
#endif
#ifdef F_sceCcc_0004
	IMPORT_FUNC	"sceCcc", 0xD9392CCB, sceCccIsValidUCS4
#endif
#ifdef F_sceCcc_0005
	IMPORT_FUNC	"sceCcc", 0xD2B18485, sceCccIsValidUCS2
#endif
#ifdef F_sceCcc_0006
	IMPORT_FUNC	"sceCcc", 0x76E33E9C, sceCccIsValidJIS
#endif
#ifdef F_sceCcc_0007
	IMPORT_FUNC	"sceCcc", 0xA2D5D209, sceCccIsValidUTF8
#endif
#ifdef F_sceCcc_0008
	IMPORT_FUNC	"sceCcc", 0x90521AC5, sceCccIsValidUTF16
#endif
#ifdef F_sceCcc_0009
	IMPORT_FUNC	"sceCcc", 0xCC0A8BDA, sceCccIsValidSJIS
#endif
#ifdef F_sceCcc_0010
	IMPORT_FUNC	"sceCcc", 0x67BF0D19, sceCccDecodeUTF16
#endif
#ifdef F_sceCcc_0011
	IMPORT_FUNC	"sceCcc", 0xE0CF8091, sceCccDecodeUTF8
#endif
#ifdef F_sceCcc_0012
	IMPORT_FUNC	"sceCcc", 0xC6A8BEE2, sceCccDecodeSJIS
#endif
#ifdef F_sceCcc_0013
	IMPORT_FUNC	"sceCcc", 0x953E6C10, sceCccEncodeUTF16
#endif
#ifdef F_sceCcc_0014
	IMPORT_FUNC	"sceCcc", 0x8406F469, sceCccEncodeUTF8
#endif
#ifdef F_sceCcc_0015
	IMPORT_FUNC	"sceCcc", 0x92C05851, sceCccEncodeSJIS
#endif
#ifdef F_sceCcc_0016
	IMPORT_FUNC	"sceCcc", 0x068C4320, sceCccUCStoJIS
#endif
#ifdef F_sceCcc_0017
	IMPORT_FUNC	"sceCcc", 0x70ECAA10, sceCccJIStoUCS
#endif
#ifdef F_sceCcc_0018
	IMPORT_FUNC	"sceCcc", 0xFB7846E2, sceCccUTF8toUTF16
#endif
#ifdef F_sceCcc_0019
	IMPORT_FUNC	"sceCcc", 0x00D1378F, sceCccUTF8toSJIS
#endif
#ifdef F_sceCcc_0020
	IMPORT_FUNC	"sceCcc", 0x6F82EE03, sceCccSJIStoUTF8
#endif
#ifdef F_sceCcc_0021
	IMPORT_FUNC	"sceCcc", 0xA62E6E80, sceCccSJIStoUTF16
#endif
#ifdef F_sceCcc_0022
	IMPORT_FUNC	"sceCcc", 0xBEB47224, sceCccUTF16toSJIS
#endif
#ifdef F_sceCcc_0023
	IMPORT_FUNC	"sceCcc", 0xF1B73D12, sceCccUTF16toUTF8
#endif
#ifdef F_sceCcc_0024
	IMPORT_FUNC	"sceCcc", 0x41B724A5, sceCccSetErrorCharSJIS
#endif
#ifdef F_sceCcc_0025
	IMPORT_FUNC	"sceCcc", 0xC56949AD, sceCccSetErrorCharUTF8
#endif
#ifdef F_sceCcc_0026
	IMPORT_FUNC	"sceCcc", 0x17E1D813, sceCccSetErrorCharUTF16
#endif
#ifdef F_sceCcc_0027
	IMPORT_FUNC	"sceCcc", 0xB8476CF4, sceCccGetErxEntries
#endif
