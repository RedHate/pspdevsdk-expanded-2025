/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspfont.h - Prototypes for the libfont library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBFONT_H__
#define __LIBFONT_H__

#include <psperror.h>
#include <psptypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SCE_FONT_MAX_OPEN 				 (9)
#define SCE_FONT_ERROR_BASEVALUE 		 (0x0000)
#define SCE_FONT_NOERROR 				 (SCE_OK)

#define SCE_FONT_ERR_NOMEMORY 			 (0x80460001)
#define SCE_FONT_ERR_LIBID 				 (0x80460002)
#define SCE_FONT_ERR_ARG 				 (0x80460003)
#define SCE_FONT_ERR_NOFILE 			 (0x80460004)
#define SCE_FONT_ERR_FILEOPEN 			 (0x80460005)
#define SCE_FONT_ERR_FILECLOSE 			 (0x80460006)
#define SCE_FONT_ERR_FILEREAD 			 (0x80460007)
#define SCE_FONT_ERR_FILESEEK  			 (0x80460008)
#define SCE_FONT_ERR_TOOMANYOPENED 		 (0x80460009)
#define SCE_FONT_ERR_ILLEGALVERSION 	 (0x8046000a)
#define SCE_FONT_ERR_DATAINCONSISTENT  	 (0x8046000b)
#define SCE_FONT_ERR_EXPIRED  			 (0x8046000c)
#define SCE_FONT_ERR_REGISTRY 			 (0x8046000d)
#define SCE_FONT_ERR_NOSUPPORT 			 (0x8046000e)
#define SCE_FONT_ERR_UNKNOWN  			 (0x8046ffff)

enum sceFontFamilyCode {
    SCE_FONT_DEFAULT_FAMILY_CODE=(0),
    SCE_FONT_FAMILY_SANSERIF=(1),
    SCE_FONT_FAMILY_SERIF=(2),
    SCE_FONT_FAMILY_ROUNDED=(3)
};

enum sceFontStyleCode {
   
    SCE_FONT_DEFAULT_STYLE_CODE=(0),
    
    SCE_FONT_STYLE_REGULAR=(1),
    SCE_FONT_STYLE_OBLIQUE=(2),
    SCE_FONT_STYLE_NARROW=(3),
    SCE_FONT_STYLE_NARROW_OBLIQUE=(4),
    SCE_FONT_STYLE_BOLD=(5),
    SCE_FONT_STYLE_BOLD_OBLIQUE=(6),
    SCE_FONT_STYLE_BLACK=(7), 
    SCE_FONT_STYLE_BLACK_OBLIQUE=(8),

    SCE_FONT_STYLE_L=(101),
    SCE_FONT_STYLE_M=(102),
    SCE_FONT_STYLE_DB=(103),
    SCE_FONT_STYLE_B=(104),
    SCE_FONT_STYLE_EB=(105),
    SCE_FONT_STYLE_UB=(106) 
};

enum sceFontImageByfferPixelFormatType {
    SCE_FONT_USERIMAGE_DIRECT4_L=(0), 
    SCE_FONT_USERIMAGE_DIRECT4_R=(1), 
    SCE_FONT_USERIMAGE_DIRECT8=(2),  // 256
    SCE_FONT_USERIMAGE_DIRECT24=(3), // RGB 24
    SCE_FONT_USERIMAGE_DIRECT32=(4)  // RGBA 32
};

enum sceFontLanguageCode {
    SCE_FONT_DEFAULT_LANGUAGE_CODE=(0),
    SCE_FONT_LANGUAGE_J=(1),
    SCE_FONT_LANGUAGE_LATIN=(2),
    SCE_FONT_LANGUAGE_K=(3),
    SCE_FONT_LANGUAGE_C=(4),
    SCE_FONT_LANGUAGE_CJK=(5)
};

enum sceFontRegionCode {
    SCE_FONT_GENERIC_REGION_CODE=(0),
    SCE_FONT_REGION_001=(1), 
    SCE_FONT_REGION_002=(2),
    SCE_FONT_REGION_003=(3), 
    SCE_FONT_REGION_004=(4), 
    SCE_FONT_REGION_005=(5),
    SCE_FONT_REGION_006=(6),
    SCE_FONT_REGION_007=(7)
};

enum sceFontFontVendorCountryCode {
    SCE_FONT_GENERIC_COUNTRY_CODE=(0),
    SCE_FONT_COUNTRY_JAPAN=(1)
    SCE_FONT_COUNTRY_USA=(2)
};

enum sceFontBoolValue { 
    SCE_FONT_FALSE=(0),
    SCE_FONT_TRUE=(1)
};

#define SCE_FONT_SUBSTYLE_VERTICALLAYOUT 	(0x0001) 
#define SCE_FONT_SUBSTYLE_PSEUDO_BOLD 		(0x0002)
#define SCE_FONT_SUBSTYLE_PSEUDO_SLANT 		(0x0004)

#define SCE_FONT_FONTNAME_LENGTH 			(64)
#define SCE_FONT_FONTFILENAME_LENGTH 		(64)

enum sceFontDataAccessMode {
    SCE_FONT_FILEBASEDSTREAM=(0),
    SCE_FONT_MEMORYBASEDSTREAM=(1)
};

typedef unsigned long long sceFont_t_u64;
typedef signed long long sceFont_t_s64;
typedef unsigned long sceFont_t_u32;
typedef signed long sceFont_t_s32;
typedef unsigned short sceFont_t_u16;
typedef signed short sceFont_t_s16;
typedef unsigned char sceFont_t_u8;
typedef signed char sceFont_t_s8;
typedef float sceFont_t_f32;
typedef double sceFont_t_f64;
typedef sceFont_t_u32 sceFont_t_bool;

typedef void *sceFont_t_libId;
typedef void *sceFont_t_fontId;
typedef void *sceFont_t_pointer;
typedef void *sceFont_t_handle;

typedef sceFont_t_s32 sceFont_t_error;
typedef sceFont_t_s32 sceFont_t_int;
typedef sceFont_t_u16 sceFont_t_charCode;
typedef sceFont_t_charCode *sceFont_t_string;
typedef sceFont_t_s32 sceFont_t_fontIndex;


typedef struct sceFont_t_irect {
    sceFont_t_u16 width;
    sceFont_t_u16 height;
} sceFont_t_irect;

typedef struct sceFont_t_rect {
    sceFont_t_u32 width;
    sceFont_t_u32 height;
} sceFont_t_rect;

typedef struct sceFont_t_cacheSystemInterface {
    sceFont_t_pointer *cacheInstance;
    sceFont_t_s32 (*lockFunc)(sceFont_t_pointer);
    sceFont_t_s32 (*unlockFunc) (sceFont_t_pointer);
    sceFont_t_pointer (*findFunc)( sceFont_t_pointer, sceFont_t_u32, sceFont_t_pointer, sceFont_t_bool *);
    sceFont_t_s32 (*writeKeyValueToCacheFunc)( sceFont_t_pointer, sceFont_t_pointer,sceFont_t_pointer );
    sceFont_t_s32 (*write0ToCacheFunc)(sceFont_t_pointer,sceFont_t_pointer,sceFont_t_pointer,sceFont_t_int);
    sceFont_t_s32 (*write1ToCacheFunc)(sceFont_t_pointer,sceFont_t_pointer,sceFont_t_pointer,sceFont_t_int);
    sceFont_t_s32 (*write2ToCacheFunc)(sceFont_t_pointer,sceFont_t_pointer,sceFont_t_pointer,sceFont_t_int);
    sceFont_t_s32 (*write3ToCacheFunc) (sceFont_t_pointer,sceFont_t_pointer,sceFont_t_pointer,sceFont_t_int);
    sceFont_t_s32 (*read0FromCacheFunc)(sceFont_t_pointer,sceFont_t_pointer,sceFont_t_pointer);
    sceFont_t_s32 (*read1FromCacheFunc)(sceFont_t_pointer,sceFont_t_pointer,sceFont_t_pointer);
    sceFont_t_s32 (*read2FromCacheFunc)(sceFont_t_pointer,sceFont_t_pointer,sceFont_t_pointer);
    sceFont_t_s32 (*read3FromCacheFunc)(sceFont_t_pointer,sceFont_t_pointer,sceFont_t_pointer);
} sceFont_t_cacheSystemInterface;

typedef struct sceFont_t_initRec {
    sceFont_t_pointer userData;
    sceFont_t_u32 maxNumFonts; 
	sceFont_t_cacheSystemInterface *cache;
    sceFont_t_pointer (*allocFunc)(sceFont_t_pointer,sceFont_t_u32);
    void (*freeFunc)(sceFont_t_pointer,sceFont_t_pointer);
    sceFont_t_handle (*openFunc)(sceFont_t_pointer,sceFont_t_pointer,sceFont_t_error *);
    sceFont_t_error (*closeFunc)(sceFont_t_pointer, sceFont_t_handle);
    sceFont_t_u32 (*readFunc)(sceFont_t_pointer,sceFont_t_handle,sceFont_t_pointer,sceFont_t_u32,sceFont_t_u32,sceFont_t_error *);
    sceFont_t_error (*seekFunc)(sceFont_t_pointer,sceFont_t_handle, sceFont_t_u32);
    sceFont_t_s32 (*onErrorFunc)(sceFont_t_pointer,sceFont_t_s32 );
    sceFont_t_s32 (*whenDoneReadFunc)(sceFont_t_pointer,sceFont_t_s32);
} sceFont_t_initRec;

typedef struct sceFont_t_fontStyleInfo {
    sceFont_t_f32 hSize;
    sceFont_t_f32 vSize;
    sceFont_t_f32 hResolution;
    sceFont_t_f32 vResolution;
    sceFont_t_f32 weight;
    sceFont_t_u16 familyCode;
    sceFont_t_u16 style;
    sceFont_t_u16 subStyle;
    sceFont_t_u16 languageCode;
    sceFont_t_u16 regionCode;
    sceFont_t_u16 countryCode;
    sceFont_t_u8 fontName [SCE_FONT_FONTNAME_LENGTH];
    sceFont_t_u8 fileName [SCE_FONT_FONTFILENAME_LENGTH];
    sceFont_t_u32 extraAttributes;
    sceFont_t_u32 expireDate;
} sceFont_t_fontStyleInfo;

typedef struct sceFont_t_userImageBufferRec {
    sceFont_t_u32 pixelFormat;
    sceFont_t_s32 xPos64;
    sceFont_t_s32 yPos64;
    sceFont_t_irect rect;
    sceFont_t_u16 bytesPerLine; 
    sceFont_t_u16 reserved;
    sceFont_t_u8 *buffer; 
} sceFont_t_userImageBufferRec;

typedef struct sceFont_t_iGlyphMetricsInfo { 
    sceFont_t_u32 width64; 
    sceFont_t_u32 height64; 
    sceFont_t_s32 ascender64; 
    sceFont_t_s32 descender64; 
    sceFont_t_s32 horizontalBearingX64;
    sceFont_t_s32 horizontalBearingY64;
    sceFont_t_s32 verticalBearingX64;
    sceFont_t_s32 verticalBearingY64;
    sceFont_t_s32 horizontalAdvance64;
    sceFont_t_s32 verticalAdvance64;
} sceFont_t_iGlyphMetricsInfo;

typedef struct sceFont_t_charInfo {
    sceFont_t_u32 bitmapWidth;
    sceFont_t_u32 bitmapHeight;
    sceFont_t_u32 bitmapLeft;
    sceFont_t_u32 bitmapTop;
    sceFont_t_iGlyphMetricsInfo glyphMetrics;
    sceFont_t_u8 reserved0 [2]; 
    sceFont_t_u16 reserved1; 
} sceFont_t_charInfo;

typedef struct sceFont_t_fGlyphMetricsInfo {
    sceFont_t_f32 width;
    sceFont_t_f32 height; 
    sceFont_t_f32 ascender;
    sceFont_t_f32 descender; 
    sceFont_t_f32 horizontalBearingX;
    sceFont_t_f32 horizontalBearingY;
    sceFont_t_f32 verticalBearingX;
    sceFont_t_f32 verticalBearingY;
    sceFont_t_f32 horizontalAdvance;
    sceFont_t_f32 verticalAdvance;
} sceFont_t_fGlyphMetricsInfo;

typedef struct sceFont_t_fontInfo {
    sceFont_t_iGlyphMetricsInfo maxIGlyphMetrics;
    sceFont_t_fGlyphMetricsInfo maxFGlyphMetrics;
    sceFont_t_u16 maxGlyphBitmapWidth;
    sceFont_t_u16 maxGlyphBitmapHeight;
    sceFont_t_u32 numChars; 
    sceFont_t_u32 numSubChars; 
    sceFont_t_fontStyleInfo fontStyleInfo;
    sceFont_t_u8 pixelDepth; 
    sceFont_t_u8 reserved [3];
} sceFont_t_fontInfo;

typedef struct sceFontCacheKey {
    int keyValue0;
    int keyValue1;
    int keyValue2;
    int keyValue3;
} sceFontCacheKey;

extern sceFont_t_libId sceFontNewLib(sceFont_t_initRec *,sceFont_t_error *);
extern sceFont_t_error sceFontDoneLib(sceFont_t_libId);
extern sceFont_t_error sceFontSetResolution(sceFont_t_libId, sceFont_t_f32, sceFont_t_f32 );
extern sceFont_t_int sceFontGetNumFontList( sceFont_t_libId, sceFont_t_error *);
extern sceFont_t_error sceFontGetFontList(sceFont_t_libId,sceFont_t_fontStyleInfo *, sceFont_t_int);
extern sceFont_t_fontIndex sceFontFindOptimumFont(sceFont_t_libId,sceFont_t_fontStyleInfo *,sceFont_t_error *);
extern sceFont_t_fontIndex sceFontFindFont(sceFont_t_libId,sceFont_t_fontStyleInfo *, sceFont_t_error *);
extern sceFont_t_u32 sceFontCalcMemorySize(sceFont_t_libId,sceFont_t_fontStyleInfo *, sceFont_t_error *  );
extern sceFont_t_error sceFontGetFontInfoByIndexNumber(sceFont_t_libId,sceFont_t_fontStyleInfo *, sceFont_t_fontIndex);
extern sceFont_t_fontId sceFontOpen(sceFont_t_libId,sceFont_t_fontIndex,sceFont_t_u32,sceFont_t_error * );
sceFont_t_fontId sceFontOpenUserFile(sceFont_t_libId,sceFont_t_pointer,sceFont_t_u32, sceFont_t_error * );
sceFont_t_fontId sceFontOpenUserMemory(sceFont_t_libId,sceFont_t_pointer, sceFont_t_u32, sceFont_t_error * );
extern sceFont_t_error sceFontClose(sceFont_t_fontId );
extern sceFont_t_error sceFontGetFontInfo(sceFont_t_fontId,sceFont_t_fontInfo *);
extern sceFont_t_error sceFontGetCharInfo(sceFont_t_fontId,sceFont_t_charCode,sceFont_t_charInfo * );
extern sceFont_t_error sceFontGetCharImageRect(sceFont_t_fontId,sceFont_t_charCode,sceFont_t_irect *);
extern sceFont_t_error sceFontGetCharGlyphImage(sceFont_t_fontId, sceFont_t_charCode,sceFont_t_userImageBufferRec *);
extern sceFont_t_error sceFontGetCharGlyphImage_Clip(sceFont_t_fontId,sceFont_t_charCode,sceFont_t_userImageBufferRec *,sceFont_t_s32,sceFont_t_s32,sceFont_t_u32,sceFont_t_u32 );
extern sceFont_t_error sceFontGetStringImageRect(sceFont_t_fontId,sceFont_t_u32,sceFont_t_string,sceFont_t_rect *);
extern sceFont_t_error sceFontGetStringGlyphImage(sceFont_t_fontId, sceFont_t_u32, sceFont_t_string, sceFont_t_userImageBufferRec * );
extern sceFont_t_f32 sceFontPixelToPointH(sceFont_t_libId,sceFont_t_f32, sceFont_t_error *);
extern sceFont_t_f32 sceFontPixelToPointV(sceFont_t_libId,sceFont_t_f32,sceFont_t_error *);
extern sceFont_t_f32 sceFontPointToPixelH(sceFont_t_libId,sceFont_t_f32,sceFont_t_error * );
extern sceFont_t_f32 sceFontPointToPixelV(sceFont_t_libId, sceFont_t_f32, sceFont_t_error *);
extern sceFont_t_error sceFontSetAltCharacterCode(sceFont_t_libId,sceFont_t_charCode);

#ifdef __cplusplus
}
#endif

#endif
