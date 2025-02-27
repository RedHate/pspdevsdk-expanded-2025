	.set noreorder

#include "pspimport.s"

#ifdef F_sceFont_0000
	IMPORT_START "sceFont", 0x00010011
#endif
#ifdef F_sceFont_0001
	IMPORT_FUNC  "sceFont", 0x67F17ED7, sceFontNewLib
#endif
#ifdef F_sceFont_0002
	IMPORT_FUNC  "sceFont", 0x574B6FBC, sceFontDoneLib
#endif
#ifdef F_sceFont_0003
	IMPORT_FUNC  "sceFont", 0x48293280, sceFontSetResolution
#endif
#ifdef F_sceFont_0004
	IMPORT_FUNC  "sceFont", 0x27F6E642, sceFontGetNumFontList
#endif
#ifdef F_sceFont_0005
	IMPORT_FUNC  "sceFont", 0xBC75D85B, sceFontGetFontList
#endif
#ifdef F_sceFont_0006
	IMPORT_FUNC  "sceFont", 0x099EF33C, sceFontFindOptimumFont
#endif
#ifdef F_sceFont_0007
	IMPORT_FUNC  "sceFont", 0x681E61A7, sceFontFindFont
#endif
#ifdef F_sceFont_0008
	IMPORT_FUNC  "sceFont", 0x2F67356A, sceFontCalcMemorySize
#endif
#ifdef F_sceFont_0009
	IMPORT_FUNC  "sceFont", 0x5333322D, sceFontGetFontInfoByIndexNumber
#endif
#ifdef F_sceFont_0010
	IMPORT_FUNC  "sceFont", 0xA834319D, sceFontOpen
#endif
#ifdef F_sceFont_0011
	IMPORT_FUNC  "sceFont", 0x57FCB733, sceFontOpenUserFile
#endif
#ifdef F_sceFont_0012
	IMPORT_FUNC  "sceFont", 0xBB8E7FE6, sceFontOpenUserMemory
#endif
#ifdef F_sceFont_0013
	IMPORT_FUNC  "sceFont", 0x3AEA8CB6, sceFontClose
#endif
#ifdef F_sceFont_0014
	IMPORT_FUNC  "sceFont", 0x0DA7535E, sceFontGetFontInfo
#endif
#ifdef F_sceFont_0015
	IMPORT_FUNC  "sceFont", 0xDCC80C2F, sceFontGetCharInfo
#endif
#ifdef F_sceFont_0016
	IMPORT_FUNC  "sceFont", 0x5C3E4A9E, sceFontGetCharImageRect
#endif
#ifdef F_sceFont_0017
	IMPORT_FUNC  "sceFont", 0x980F4895, sceFontGetCharGlyphImage
#endif
#ifdef F_sceFont_0018
	IMPORT_FUNC  "sceFont", 0xCA1E6945, sceFontGetCharGlyphImage_Clip
#endif
#ifdef F_sceFont_0019
	IMPORT_FUNC  "sceFont", 0x81034B46, sceFontGetStringImageRect
#endif
#ifdef F_sceFont_0020
	IMPORT_FUNC  "sceFont", 0xDF5BA3D8, sceFontGetStringGlyphImage
#endif
#ifdef F_sceFont_0021
	IMPORT_FUNC  "sceFont", 0x74B21701, sceFontPixelToPointH
#endif
#ifdef F_sceFont_0022
	IMPORT_FUNC  "sceFont", 0xF8F0752E, sceFontPixelToPointV
#endif
#ifdef F_sceFont_0023
	IMPORT_FUNC  "sceFont", 0x472694CD, sceFontPointToPixelH
#endif
#ifdef F_sceFont_0024
	IMPORT_FUNC  "sceFont", 0x3C4B7E82, sceFontPointToPixelV
#endif
#ifdef F_sceFont_0025
	IMPORT_FUNC  "sceFont", 0xEE232411, sceFontSetAltCharacterCode
#endif
