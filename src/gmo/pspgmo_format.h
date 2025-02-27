#ifndef __PSPGMO_FORMAT_H__
#define __PSPGMO_FORMAT_H__

#include <pspgmo_types.h>

#ifdef __cplusplus
extern "C" {
#endif


//  enums                                                          
#define	PSP_GMO_FORMAT_SIGNATURE		(0x2e474d4f)	// '.GMO'
#define	PSP_GMO_FORMAT_VERSION		(0x312e3030)	// '1.00'
#define	PSP_GMO_FORMAT_STYLE_PSP		(0x00505350)	// 'PSP' 

enum {
	PSP_GMO_BASE_RESERVED		= 0x0000,	// 0000-0fff : reserved
	PSP_GMO_BASE_PRIVATE			= 0x1000,	// 1000-3fff : private use
	PSP_GMO_BASE_PUBLIC			= 0x4000,	// 4000-7fff : public use
	PSP_GMO_HALF_CHUNK			= 0x8000,
	PSP_GMO_BLOCK				= 0x0001,
	PSP_GMO_FILE					= 0x0002,
	PSP_GMO_MODEL				= 0x0003,
	PSP_GMO_BONE					= 0x0004,
	PSP_GMO_PART					= 0x0005,
	PSP_GMO_MESH					= 0x0006,
	PSP_GMO_ARRAYS				= 0x0007,
	PSP_GMO_MATERIAL				= 0x0008,
	PSP_GMO_LAYER				= 0x0009,
	PSP_GMO_TEXTURE				= 0x000a,
	PSP_GMO_MOTION				= 0x000b,
	PSP_GMO_FCURVE				= 0x000c,
	PSP_GMO_BLIND_BLOCK			= 0x000f,
	PSP_GMO_COMMAND				= 0x0011,
	PSP_GMO_FILE_NAME			= 0x0012,
	PSP_GMO_FILE_IMAGE			= 0x0013,
	PSP_GMO_BOUNDING_BOX			= 0x0014,
	PSP_GMO_VERTEX_OFFSET		= 0x0015,
	PSP_GMO_PARENT_BONE			= 0x0041,
	PSP_GMO_VISIBILITY			= 0x0042,
	PSP_GMO_MORPH_WEIGHTS		= 0x0043,
	PSP_GMO_MORPH_INDEX			= 0x004f,
	PSP_GMO_BLEND_BONES			= 0x0044,
	PSP_GMO_BLEND_OFFSETS		= 0x0045,
	PSP_GMO_PIVOT				= 0x0046,
	PSP_GMO_MULT_MATRIX			= 0x0047,
	PSP_GMO_TRANSLATE			= 0x0048,
	PSP_GMO_ROTATE_ZYX			= 0x0049,
	PSP_GMO_ROTATE_YXZ			= 0x004a,
	PSP_GMO_ROTATE_Q				= 0x004b,
	PSP_GMO_SCALE				= 0x004c,
	PSP_GMO_SCALE_2				= 0x004d,
	PSP_GMO_SCALE_3				= 0x00e1,
	PSP_GMO_DRAW_PART			= 0x004e,
	PSP_GMO_SET_MATERIAL			= 0x0061,
	PSP_GMO_BLEND_SUBSET			= 0x0062,
	PSP_GMO_SUBDIVISION			= 0x0063,
	PSP_GMO_KNOT_VECTOR_U		= 0x0064,
	PSP_GMO_KNOT_VECTOR_V		= 0x0065,
	PSP_GMO_DRAW_ARRAYS			= 0x0066,
	PSP_GMO_DRAW_PARTICLE		= 0x0067,
	PSP_GMO_DRAW_B_SPLINE		= 0x0068,
	PSP_GMO_DRAW_RECT_MESH		= 0x0069,
	PSP_GMO_DRAW_RECT_PATCH		= 0x006a,
	PSP_GMO_RENDER_STATE			= 0x0081,
	PSP_GMO_DIFFUSE				= 0x0082,
	PSP_GMO_SPECULAR				= 0x0083,
	PSP_GMO_EMISSION				= 0x0084,
	PSP_GMO_AMBIENT				= 0x0085,
	PSP_GMO_REFLECTION			= 0x0086,
	PSP_GMO_REFRACTION			= 0x0087,
	PSP_GMO_BUMP					= 0x0088,
	PSP_GMO_SET_TEXTURE			= 0x0091,
	PSP_GMO_MAP_TYPE				= 0x0092,
	PSP_GMO_MAP_FACTOR			= 0x0093,
	PSP_GMO_BLEND_FUNC			= 0x0094,
	PSP_GMO_TEX_FUNC				= 0x0095,
	PSP_GMO_TEX_FILTER			= 0x0096,
	PSP_GMO_TEX_WRAP				= 0x0097,
	PSP_GMO_TEX_CROP				= 0x0098,
	PSP_GMO_FRAME_LOOP			= 0x00b1,
	PSP_GMO_FRAME_RATE			= 0x00b2,
	PSP_GMO_FRAME_REPEAT			= 0x00b4,
	PSP_GMO_ANIMATE				= 0x00b3,
	PSP_GMO_BLIND_DATA			= 0x00f1,
	PSP_GMO_FILE_INFO			= 0x00ff
} ;

enum {
	PSP_GMO_PRIM_TYPE_MASK		= 0x000f,
	PSP_GMO_PRIM_POINTS			= 0x0000,
	PSP_GMO_PRIM_LINES			= 0x0001,
	PSP_GMO_PRIM_LINE_STRIP		= 0x0002,
	PSP_GMO_PRIM_TRIANGLES		= 0x0003,
	PSP_GMO_PRIM_TRIANGLE_STRIP	= 0x0004,
	PSP_GMO_PRIM_TRIANGLE_FAN	= 0x0005,
	PSP_GMO_PRIM_RECTANGLES		= 0x0006,
	PSP_GMO_PRIM_SPLINE_MASK		= 0xf000,
	PSP_GMO_PRIM_OPEN_U			= 0x3000,
	PSP_GMO_PRIM_OPEN_V			= 0xc000,
	PSP_GMO_PRIM_OPEN_U_IN		= 0x1000,
	PSP_GMO_PRIM_OPEN_U_OUT		= 0x2000,
	PSP_GMO_PRIM_OPEN_V_IN		= 0x4000,
	PSP_GMO_PRIM_OPEN_V_OUT		= 0x8000,
	PSP_GMO_PRIM_SEQUENTIAL		= 0x0100,
} ;

enum {
	PSP_GMO_FCURVE_INTERP_MASK	= 0x000f,
	PSP_GMO_FCURVE_CONSTANT		= 0x0000,
	PSP_GMO_FCURVE_LINEAR		= 0x0001,
	PSP_GMO_FCURVE_HERMITE		= 0x0002,
	PSP_GMO_FCURVE_CUBIC			= 0x0003,
	PSP_GMO_FCURVE_SPHERICAL		= 0x0004,
	PSP_GMO_FCURVE_EXTRAP_MASK	= 0xff00,
	PSP_GMO_FCURVE_HOLD			= 0x0000,
	PSP_GMO_FCURVE_CYCLE			= 0x1100,
	PSP_GMO_FCURVE_SHUTTLE		= 0x2200,
	PSP_GMO_FCURVE_REPEAT		= 0x3300,
	PSP_GMO_FCURVE_EXTEND		= 0x4400,
	PSP_GMO_FCURVE_EXTRAP_LEFT_MASK	= 0x0f00,
	PSP_GMO_FCURVE_HOLD_LEFT		= 0x0000,
	PSP_GMO_FCURVE_CYCLE_LEFT	= 0x0100,
	PSP_GMO_FCURVE_SHUTTLE_LEFT	= 0x0200,
	PSP_GMO_FCURVE_REPEAT_LEFT	= 0x0300,
	PSP_GMO_FCURVE_EXTEND_LEFT	= 0x0400,
	PSP_GMO_FCURVE_EXTRAP_RIGHT_MASK	= 0xf000,
	PSP_GMO_FCURVE_HOLD_RIGHT	= 0x0000,
	PSP_GMO_FCURVE_CYCLE_RIGHT	= 0x1000,
	PSP_GMO_FCURVE_SHUTTLE_RIGHT	= 0x2000,
	PSP_GMO_FCURVE_REPEAT_RIGHT	= 0x3000,
	PSP_GMO_FCURVE_EXTEND_RIGHT	= 0x4000,
} ;

enum {
	PSP_GMO_REPEAT_HOLD		= 0x0000,
	PSP_GMO_REPEAT_CYCLE		= 0x0001,
} ;

enum {
	PSP_GMO_STATE_LIGHTING		= 0,
	PSP_GMO_STATE_FOG			= 1,
	PSP_GMO_STATE_TEXTURE		= 2,
	PSP_GMO_STATE_CULL_FACE		= 3,
	PSP_GMO_STATE_DEPTH_TEST		= 4,
	PSP_GMO_STATE_DEPTH_MASK		= 5,
	PSP_GMO_STATE_ALPHA_TEST		= 6,
	PSP_GMO_STATE_ALPHA_MASK		= 7,
	PSP_GMO_STATE_ENABLE_LIGHTING	= 0,    // obsolete
	PSP_GMO_STATE_ENABLE_FOG			= 1		// obsolete
} ;

enum {
	PSP_GMO_BLEND_ADD			= 0,
	PSP_GMO_BLEND_SUB			= 1,
	PSP_GMO_BLEND_REV			= 2,
	PSP_GMO_BLEND_MIN			= 3,
	PSP_GMO_BLEND_MAX			= 4,
	PSP_GMO_BLEND_DIFF			= 5,
	PSP_GMO_BLEND_ZERO			= 0,		// != SCEGU
	PSP_GMO_BLEND_ONE			= 1,		// != SCEGU
	PSP_GMO_BLEND_SRC_COLOR		= 2,		// != SCEGU
	PSP_GMO_BLEND_INV_SRC_COLOR	= 3,		// != SCEGU
	PSP_GMO_BLEND_DST_COLOR		= 4,		// != SCEGU
	PSP_GMO_BLEND_INV_DST_COLOR	= 5,		// != SCEGU
	PSP_GMO_BLEND_SRC_ALPHA		= 6,		// != SCEGU
	PSP_GMO_BLEND_INV_SRC_ALPHA	= 7,		// != SCEGU
	PSP_GMO_BLEND_DST_ALPHA		= 8,		// != SCEGU
	PSP_GMO_BLEND_INV_DST_ALPHA	= 9,		// != SCEGU
} ;

enum {
	PSP_GMO_FUNC_MODULATE	= 0,
	PSP_GMO_FUNC_DECAL		= 1,
	PSP_GMO_FUNC_RGB			= 0,
	PSP_GMO_FUNC_RGBA		= 1
} ;

enum {
	PSP_GMO_FILTER_NEAREST		= 0,
	PSP_GMO_FILTER_LINEAR		= 1,
	PSP_GMO_FILTER_NEAREST_MIPMAP_NEAREST = 2,	// != SCEGU
	PSP_GMO_FILTER_LINEAR_MIPMAP_NEAREST = 3,	// != SCEGU
	PSP_GMO_FILTER_NEAREST_MIPMAP_LINEAR = 4,	// != SCEGU
	PSP_GMO_FILTER_LINEAR_MIPMAP_LINEAR = 5		// != SCEGU
} ;

enum {
	PSP_GMO_WRAP_REPEAT		= 0,
	PSP_GMO_WRAP_CLAMP		= 1
} ;


//  header structure                                               


typedef struct SceGmoHeader {
	unsigned int signature ;
	unsigned int version ;
	unsigned int style ;
	unsigned int option ;
} SceGmoHeader ;


//  chunk structure                                                


typedef struct SceGmoChunk {
	unsigned short type ;
	unsigned short args_offs ;
	unsigned int next_offs ;
	unsigned int child_offs ;
	unsigned int data_offs ;
} SceGmoChunk ;



//  block reference type                                           


#define PSP_GMO_REF_TYPE(ref) (0x7fff&((ref)>>16))
#define PSP_GMO_REF_LEVEL(ref) (0x000f&((ref)>>12))
#define PSP_GMO_REF_INDEX(ref) (0x0fff&(ref))


//  block args                                                     


typedef struct {
	int format ;
	int n_verts ;
	int n_morphs ;
	int format2 ;
} SceGmoArraysHeader ;

typedef struct {
	int format ;
	int n_dims ;
	int n_keys ;
	int reserved ;
} SceGmoFCurveHeader ;


//  command args ( common commands )                               


typedef struct {
	char name[ 1 ] ;
} SceGmoFileName ;

typedef struct {
	int size ;
	int data[ 1 ] ;
} SceGmoFileImage ;

typedef struct {
	SceGmoVec3F lower ;
	SceGmoVec3F upper ;
} SceGmoBoundingBox ;

typedef struct {
	int format ;
	float offset[ 1 ] ;
} SceGmoVertexOffset ;


//  command args ( bone commands )                                 


typedef struct {
	int bone ;
} SceGmoParentBone ;

typedef struct {
	int visibility ;
} SceGmoVisibility ;

typedef struct {
	int n_weights ;
	float weights[ 1 ] ;
} SceGmoMorphWeights ;

typedef struct {
	float index ;
} SceGmoMorphIndex ;

typedef struct {
	int n_bones ;
	int bones[ 1 ] ;
} SceGmoBlendBones ;

typedef struct {
	int n_offsets ;
	SceGmoMat4F offsets[ 1 ] ;
} SceGmoBlendOffsets ;

typedef struct {
	SceGmoVec3F pivot ;
} SceGmoPivot ;

typedef struct {
	SceGmoMat4F matrix ;
} SceGmoMultMatrix ;

typedef struct {
	SceGmoVec3F translate ;
} SceGmoTranslate ;

typedef struct {
	SceGmoVec3F rotate ;
} SceGmoRotateZYX ;

typedef struct {
	SceGmoVec3F rotate ;
} SceGmoRotateYXZ ;

typedef struct {
	SceGmoQuatF rotate ;
} SceGmoRotateQ ;

typedef struct {
	SceGmoVec3F scale ;
} SceGmoScale ;

typedef struct {
	SceGmoVec3F scale ;
} SceGmoScale2 ;

typedef struct {
	SceGmoVec3F scale ;
} SceGmoScale3 ;

typedef struct {
	int part ;
} SceGmoDrawPart ;


//  command args ( mesh commands )                                 


typedef struct {
	int material ;
} SceGmoSetMaterial ;

typedef struct {
	int n_indices ;
	int indices[ 1 ] ;
} SceGmoBlendSubset ;

typedef struct {
	float div_u ;
	float div_v ;
} SceGmoSubdivision ;

typedef struct {
	int arrays ;
	int mode ;
	int n_verts ;
	int n_prims ;
	unsigned short indices[ 1 ] ;
} SceGmoDrawArrays ;

typedef struct {
	int arrays ;
	int mode ;
	int n_verts ;
	int n_prims ;
	unsigned short indices[ 1 ] ;
} SceGmoDrawParticle ;

typedef struct {
	int arrays ;
	int mode ;
	int width ;
	int height ;
	unsigned short indices[ 1 ] ;
} SceGmoDrawBSpline ;

typedef struct {
	int arrays ;
	int mode ;
	int width ;
	int height ;
	unsigned short indices[ 1 ] ;
} SceGmoDrawRectMesh ;

typedef struct {
	int arrays ;
	int mode ;
	int width ;
	int height ;
	unsigned short indices[ 1 ] ;
} SceGmoDrawRectPatch ;


//  command args ( material commands )                             


typedef struct {
	int state ;
	int value ;
} SceGmoRenderState ;

typedef struct {
	SceGmoCol4F color ;
} SceGmoDiffuse ;

typedef struct {
	SceGmoCol4F color ;
	float shininess ;
} SceGmoSpecular ;

typedef struct {
	SceGmoCol4F color ;
} SceGmoEmission ;

typedef struct {
	SceGmoCol4F color ;
} SceGmoAmbient ;

typedef struct {
	float reflection ;
} SceGmoReflection ;

typedef struct {
	float refraction ;
} SceGmoRefraction ;

typedef struct {
	float bump ;
} SceGmoBump ;


//  command args ( layer commands )                                


typedef struct {
	int texture ;
} SceGmoSetTexture ;

typedef struct {
	int type ;
} SceGmoMapType ;

typedef struct {
	float factor ;
} SceGmoMapFactor ;

typedef struct {
	int mode ;
	int src ;
	int dst ;
} SceGmoBlendFunc ;

typedef struct {
	int func ;
	int comp ;
} SceGmoTexFunc ;

typedef struct {
	int mag ;
	int min ;
} SceGmoTexFilter ;

typedef struct {
	int wrap_u ;
	int wrap_v ;
} SceGmoTexWrap ;

typedef struct {
	SceGmoRectF crop ;
} SceGmoTexCrop ;


//  command args ( motion commands )                               


typedef struct {
	float start ;
	float end ;
} SceGmoFrameLoop ;

typedef struct {
	float fps ;
} SceGmoFrameRate ;

typedef struct {
	int mode ;
} SceGmoFrameRepeat ;

typedef struct {
	int block ;
	int cmd ;
	int index ;
	int fcurve ;
} SceGmoAnimate ;


//  command args ( other commands )                                


typedef struct {
	char name[ 1 ] ;
	// char pad[ n ] ;
	// void data[ m ] ; // use PSP_GMO_CHUNK_SKIPSTRING()
} SceGmoBlindData ;

typedef struct {
	char project_name[ 1 ] ;
	// char user_name[ n ] ;	// use PSP_GMO_CHUNK_SKIPSTRING()
	// char saved_date[ n ] ;	// use PSP_GMO_CHUNK_SKIPSTRING()
	// char originator[ n ] ;	// use PSP_GMO_CHUNK_SKIPSTRING()
} SceGmoFileInfo ;


//vertex format flags                  


#ifdef PSP_GMO_TARGET_PREVIEWER
#define SCEGU_TEXTURE_NONE       ( 0 <<  0 )
#define SCEGU_TEXTURE_UBYTE      ( 1 <<  0 )
#define SCEGU_TEXTURE_USHORT     ( 2 <<  0 )
#define SCEGU_TEXTURE_FLOAT      ( 3 <<  0 )
#define SCEGU_COLOR_NONE         ( 0 <<  2 )
#define SCEGU_COLOR_PF5650       ( 4 <<  2 )
#define SCEGU_COLOR_PF5551       ( 5 <<  2 )
#define SCEGU_COLOR_PF4444       ( 6 <<  2 )
#define SCEGU_COLOR_PF8888       ( 7 <<  2 )
#define SCEGU_NORMAL_NONE        ( 0 <<  5 )
#define SCEGU_NORMAL_BYTE        ( 1 <<  5 )
#define SCEGU_NORMAL_SHORT       ( 2 <<  5 )
#define SCEGU_NORMAL_FLOAT       ( 3 <<  5 )
#define SCEGU_VERTEX_NONE        ( 0 <<  7 )
#define SCEGU_VERTEX_BYTE        ( 1 <<  7 )
#define SCEGU_VERTEX_SHORT       ( 2 <<  7 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_WEIGHT_NONE        ( 0 <<  9 )
#define SCEGU_WEIGHT_UBYTE       ( 1 <<  9 )
#define SCEGU_WEIGHT_USHORT      ( 2 <<  9 )
#define SCEGU_WEIGHT_FLOAT       ( 3 <<  9 )
#define SCEGU_INDEX_NONE         ( 0 << 11 )
#define SCEGU_INDEX_UBYTE        ( 1 << 11 )
#define SCEGU_INDEX_USHORT       ( 2 << 11 )
#define SCEGU_WEIGHT_1           ( 0 << 14 )
#define SCEGU_WEIGHT_2           ( 1 << 14 )
#define SCEGU_WEIGHT_3           ( 2 << 14 )
#define SCEGU_WEIGHT_4           ( 3 << 14 )
#define SCEGU_WEIGHT_5           ( 4 << 14 )
#define SCEGU_WEIGHT_6           ( 5 << 14 )
#define SCEGU_WEIGHT_7           ( 6 << 14 )
#define SCEGU_WEIGHT_8           ( 7 << 14 )
#define SCEGU_VERTEX_1           ( 0 << 18 )
#define SCEGU_VERTEX_2           ( 1 << 18 )
#define SCEGU_VERTEX_3           ( 2 << 18 )
#define SCEGU_VERTEX_4           ( 3 << 18 )
#define SCEGU_VERTEX_5           ( 4 << 18 )
#define SCEGU_VERTEX_6           ( 5 << 18 )
#define SCEGU_VERTEX_7           ( 6 << 18 )
#define SCEGU_VERTEX_8           ( 7 << 18 )
#define SCEGU_THROUGH            ( 1 << 23 )
#endif


#ifdef __cplusplus
}
#endif

#endif
