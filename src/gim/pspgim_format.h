#ifndef __PSPGIM_FORMAT_H__
#define __PSPGIM_FORMAT_H__

#ifdef __cplusplus
extern "C" {
#endif


//  enums                                                           
#define	PSP_GIM_FORMAT_SIGNATURE		(0x2e47494d)	// '.GIM' 
#define	PSP_GIM_FORMAT_VERSION		(0x312e3030)	// '1.00' 
#define	PSP_GIM_FORMAT_STYLE_PSP		(0x00505350)	// 'PSP'  

enum SceGimBase{
	PSP_GIM_BASE_RESERVED		= 0x0000,	// 0000-0fff : reserved 
	PSP_GIM_BASE_PRIVATE			= 0x1000,	// 1000-3fff : private use 
	PSP_GIM_BASE_PUBLIC			= 0x4000,	// 4000-7fff : public use 
	
	PSP_GIM_BLOCK				= 0x0001,
	PSP_GIM_FILE					= 0x0002,
	PSP_GIM_PICTURE				= 0x0003,
	PSP_GIM_IMAGE				= 0x0004,
	PSP_GIM_PALETTE				= 0x0005,
	PSP_GIM_SEQUENCE				= 0x0006,
	PSP_GIM_FILE_INFO			= 0x00ff
} ;

enum SceGimImageFormat{
	PSP_GIM_FORMAT_RGBA5650		= 0,
	PSP_GIM_FORMAT_RGBA5551		= 1,
	PSP_GIM_FORMAT_RGBA4444		= 2,
	PSP_GIM_FORMAT_RGBA8888		= 3,
	PSP_GIM_FORMAT_INDEX4		= 4,
	PSP_GIM_FORMAT_INDEX8		= 5,
	PSP_GIM_FORMAT_INDEX16		= 6,
	PSP_GIM_FORMAT_INDEX32		= 7,
	PSP_GIM_FORMAT_DXT1			= 8,
	PSP_GIM_FORMAT_DXT3			= 9,
	PSP_GIM_FORMAT_DXT5			= 10,
	PSP_GIM_FORMAT_DXT1EXT		= 264,
	PSP_GIM_FORMAT_DXT3EXT		= 265,
	PSP_GIM_FORMAT_DXT5EXT		= 266,

	// obsolete 
	PSP_GIM_RGBA_5650		= 0,
	PSP_GIM_RGBA_5551		= 1,
	PSP_GIM_RGBA_4444		= 2,
	PSP_GIM_RGBA_8888		= 3,
	PSP_GIM_INDEX_4			= 4,
	PSP_GIM_INDEX_8			= 5,
	PSP_GIM_INDEX_16			= 6,
	PSP_GIM_INDEX_32			= 7
} ;

enum SceGimOrder{
	PSP_GIM_ORDER_NORMAL		= 0,
	PSP_GIM_ORDER_PSPIMAGE	= 1
} ;

enum SceGimType{
	PSP_GIM_TYPE_GENERIC		= 0,
	PSP_GIM_TYPE_MIPMAP		= 1,
	PSP_GIM_TYPE_MIPMAP2		= 2,
	PSP_GIM_TYPE_SEQUENCE	= 3
} ;

enum SceGimInterp{
	PSP_GIM_INTERP_TYPEMASK		= 0x0f,
	PSP_GIM_INTERP_DISSOLVE		= 0x80,
	PSP_GIM_INTERP_EVENT			= 0x40,

	PSP_GIM_INTERP_CONSTANT		= 0,
	PSP_GIM_INTERP_LINEAR		= 1
} ;

enum SceGimRepeat{
	PSP_GIM_REPEAT_HOLD			= 0,
	PSP_GIM_REPEAT_CYCLE			= 1,
} ;

enum SceGimParam{
	PSP_GIM_PARAM_IMAGE_INDEX	= 0,
	PSP_GIM_PARAM_IMAGE_PLANE	= 1,
	PSP_GIM_PARAM_IMAGE_LEVEL	= 2,
	PSP_GIM_PARAM_IMAGE_FRAME	= 3,
	PSP_GIM_PARAM_PALETTE_INDEX	= 8,
	PSP_GIM_PARAM_PALETTE_LEVEL	= 10,
	PSP_GIM_PARAM_PALETTE_FRAME	= 11,
	PSP_GIM_PARAM_CROP_U			= 16,
	PSP_GIM_PARAM_CROP_V			= 17,
	PSP_GIM_PARAM_CROP_W			= 18,
	PSP_GIM_PARAM_CROP_H			= 19,
	PSP_GIM_PARAM_BLEND_MODE		= 32,
	PSP_GIM_PARAM_FUNC_MODE		= 34,
	PSP_GIM_PARAM_FUNC_COMP		= 35,
	PSP_GIM_PARAM_FILTER_MAG		= 36,
	PSP_GIM_PARAM_FILTER_MIN		= 37,
	PSP_GIM_PARAM_WRAP_U			= 38,
	PSP_GIM_PARAM_WRAP_V			= 39
};

enum SceGimBlend{
	PSP_GIM_BLEND_OFF			= 0,
	PSP_GIM_BLEND_MIX			= 1,
	PSP_GIM_BLEND_ADD			= 2,
	PSP_GIM_BLEND_SUB			= 3,
	PSP_GIM_BLEND_MIN			= 4,
	PSP_GIM_BLEND_MAX			= 5,
	PSP_GIM_BLEND_ABS			= 6
};

enum SceGimTexType{
	PSP_GIM_FUNC_MODULATE		= 0,
	PSP_GIM_FUNC_DECAL			= 1,
};

enum SceGimPixelFormat{
	PSP_GIM_FUNC_RGB				= 0,
	PSP_GIM_FUNC_RGBA			= 1
};

enum SceGimFilter{
	PSP_GIM_FILTER_NEAREST				 = 0,
	PSP_GIM_FILTER_LINEAR				 = 1,
	PSP_GIM_FILTER_NEAREST_MIPMAP_NEAREST = 4,
	PSP_GIM_FILTER_LINEAR_MIPMAP_NEAREST  = 5,
	PSP_GIM_FILTER_NEAREST_MIPMAP_LINEAR  = 6,
	PSP_GIM_FILTER_LINEAR_MIPMAP_LINEAR   = 7
};

enum SceGimWrap{
	PSP_GIM_WRAP_REPEAT		= 0,
	PSP_GIM_WRAP_CLAMP		= 1
};

//   header structure                                               
typedef struct {
	unsigned int signature ;
	unsigned int version ;
	unsigned int style ;
	unsigned int option ;
} SceGimHeader ;

//  chunk structure                                                 
typedef struct {
	unsigned short type ;
	unsigned short unused ;
	unsigned int next_offs ;
	unsigned int child_offs ;
	unsigned int data_offs ;
} SceGimChunk ;

int PSP_GIM_CHUNK_TYPE( SceGimChunk *chunk );
SceGimChunk *PSP_GIM_CHUNK_NEXT( SceGimChunk *chunk );
SceGimChunk *PSP_GIM_CHUNK_CHILD( SceGimChunk *chunk );
void *PSP_GIM_CHUNK_DATA( SceGimChunk *chunk );
int PSP_GIM_CHUNK_SIZE( SceGimChunk *chunk );
int PSP_GIM_CHUNK_TAG_SIZE( SceGimChunk *chunk );
int PSP_GIM_CHUNK_DATA_SIZE( SceGimChunk *chunk );
int PSP_GIM_CHUNK_CHILD_SIZE( SceGimChunk *chunk );
void *PSP_GIM_CHUNK_SKIPSTRING( const char *str, int align );

//   image chunk data                                               
typedef struct {
	unsigned short header_size ;
	unsigned short reference ;
	unsigned short format ;
	unsigned short order ;
	unsigned short width ;
	unsigned short height ;
	unsigned short bpp ;
	unsigned short pitch_align ;
	unsigned short height_align ;
	unsigned short dim_count ;
	unsigned short reserved ;
	unsigned short reserved2 ;
	unsigned int offsets ;
	unsigned int images ;
	unsigned int total ;
	unsigned int plane_mask ;
	unsigned short level_type ;
	unsigned short level_count ;
	unsigned short frame_type ;
	unsigned short frame_count ;
} SceGimImageHeader ;

//  palette chunk data                                              
typedef SceGimImageHeader SceGimPaletteHeader;

//  sequence chunk data                                             
typedef struct {
	unsigned short header_size ;
	unsigned short reference ;
	unsigned short frame_start ;
	unsigned short frame_end ;
	unsigned short frame_rate ;
	unsigned short frame_repeat ;
	unsigned short n_constants ;
	unsigned short n_functions ;
	unsigned int constants ;
	unsigned int functions ;
	unsigned int keyframes ;
	unsigned int total ;
} SceGimSequenceHeader ;

typedef struct {
	unsigned short param ;
	short value ;
} SceGimConstant ;

typedef struct {
	unsigned short param ;
	unsigned short interp ;
	unsigned int keyframes ;
} SceGimFunction ;

typedef struct {
	short count ;
	short values[ 1 ] ;
} SceGimKeyframe ;

//  file info chunk data                                            
typedef struct {
	char project_name[ 1 ] ;
	// char user_name[ n ] ; 	// use PSP_GIM_CHUNK_SKIPSTRING() 
	// char saved_date[ n ] ; 	// use PSP_GIM_CHUNK_SKIPSTRING() 
	// char originator[ n ] ; 	// use PSP_GIM_CHUNK_SKIPSTRING() 
} SceGimFileInfo;


#ifdef __cplusplus
}
#endif

#endif
