#ifndef __PSPGMO_PROTECTED_H__
#define __PSPGMO_PROTECTED_H__

#include "pspgmo_model.h"

#ifdef __cplusplus
extern "C" {
#endif

//  base structures                                                 
typedef struct SceGmoSubject {
	struct SceGmoObserver *m_observers ;	//  observer list 
} SceGmoSubject ;

typedef struct SceGmoObserver {
	struct SceGmoObserver *m_next ;			//  next observer   
	struct SceGmoSubject *m_subject ;		//  observed object 
	void *m_reserved ;
} SceGmoObserver ;

typedef struct SceGmoBase {
	struct SceGmoSubject m_subject ;
	struct SceGmoObserver m_parent ;
} SceGmoBase ;

void sceGmoSubjectConstruct( SceGmoSubject *subject ) ;
void sceGmoSubjectDestruct( SceGmoSubject *subject ) ;
void sceGmoSubjectCopy( SceGmoSubject *subject, const SceGmoSubject *src ) ;
void sceGmoSubjectAttachObserver( SceGmoSubject *subject, SceGmoObserver *observer ) ;
void sceGmoSubjectDetachObserver( SceGmoSubject *subject, SceGmoObserver *observer ) ;

void sceGmoObserverConstruct( SceGmoObserver *observer ) ;
void sceGmoObserverDestruct( SceGmoObserver *observer ) ;
void sceGmoObserverCopy( SceGmoObserver *observer, const SceGmoObserver *src ) ;
void sceGmoObserverSetSubject( SceGmoObserver *observer, SceGmoSubject *subject ) ;


void sceGmoBaseConstruct( SceGmoBase *base ) ;
void sceGmoBaseDestruct( SceGmoBase *base ) ;
void sceGmoBaseCopy( SceGmoBase *base, const SceGmoBase *src ) ;
void sceGmoBaseAttachObserver( SceGmoBase *base, SceGmoObserver *observer ) ;
void sceGmoBaseDetachObserver( SceGmoBase *base, SceGmoObserver *observer ) ;
void sceGmoBaseSetParent( SceGmoBase *base, SceGmoSubject *parent ) ;

//  model structure
enum {
	PSP_GMO_MODEL_HAS_BOUNDING_BOX	= 0x0001,
	PSP_GMO_MODEL_HAS_VERTEX_OFFSET	= 0x0002,
	PSP_GMO_MODEL_HAS_TEXCOORD_OFFSET = 0x0004
} ;

struct SceGmoModel {
	SceGmoBase m_base ;
	int m_reference ;
	int m_flags ;

	SceGmoBone **m_bones ;
	SceGmoPart **m_parts ;
	SceGmoMaterial **m_materials ;
	SceGmoTexture **m_textures ;
	SceGmoMotion **m_motions ;
	int m_n_bones ;
	int m_n_parts ;
	int m_n_materials ;
	int m_n_textures ;
	int m_n_motions ;

	int m_current_motion ;
	float m_change_motion ;
	int m_enable_bits ;
	int m_enable_mask ;

	SceGmoMat4 m_world_matrix ;
	SceGmoVec3 m_bounding_box[ 2 ] ;
	SceGmoMat4 m_vertex_offset ;
	SceGmoRect m_texcoord_offset ;
} ;


//  bone structure
enum {
	PSP_GMO_BONE_IS_SCALE_STACKED	= 0x80000000,
	PSP_GMO_BONE_IS_LOCAL_DIRTY	= 0x40000000,
	PSP_GMO_BONE_IS_WORLD_DIRTY	= 0x20000000,

	PSP_GMO_BONE_HAS_TRANSLATE	= 0x0001,
	PSP_GMO_BONE_HAS_ROTATE		= 0x0002,
	PSP_GMO_BONE_HAS_SCALE		= 0x0004,
	PSP_GMO_BONE_HAS_SCALE_2		= 0x0008,
	PSP_GMO_BONE_HAS_SCALE_3		= 0x0010,
	PSP_GMO_BONE_HAS_MULT_MATRIX	= 0x0040,
	PSP_GMO_BONE_HAS_PIVOT		= 0x0080,
	PSP_GMO_BONE_HAS_MORPH_WEIGHTS	= 0x0100,
	PSP_GMO_BONE_HAS_VISIBILITY	= 0x0200,
} ;

enum {
	PSP_GMO_BONE_ANIM_MODIFIED	= 0x0000ffff,
	PSP_GMO_BONE_ANIM_COMPLETE	= 0xffff0000,
} ;

struct SceGmoBone {
	SceGmoBase m_base ;
	SceGmoBone *m_initial ;
	int m_reference ;
	int m_flags ;

	int *m_draw_parts ;
	float *m_morph_weights ;
	int *m_blend_bones ;
	SceGmoMat4 *m_blend_offsets ;
	int m_n_draw_parts ;
	int m_n_morph_weights ;
	int m_n_blend_bones ;
	int m_n_blend_offsets ;

	int m_parent_bone ;
	int m_visibility ;
	int m_anim_flags ;
	float m_anim_weights[ 5 ] ;

	SceGmoVec3 m_pivot ;
	SceGmoVec3 m_translate ;
	SceGmoQuat m_rotate ;
	SceGmoVec3 m_scale ;
	SceGmoMat4 m_local_matrix ;
	SceGmoMat4 m_stack_matrix ;
	SceGmoVec3 m_stack_scale ;
	SceGmoMat4 m_world_matrix ;
} ;


//  part structure
struct SceGmoPart {
	SceGmoBase m_base ;
	SceGmoChunk *m_chunk ;
	int m_reference ;
	int m_flags ;

	SceGmoMesh **m_meshes ;
	SceGmoChunk **m_arrays ;
	int m_n_meshes ;
	int m_n_arrays ;
} ;

//  mesh structure
struct SceGmoMesh {
	SceGmoChunk *m_chunk ;
	int m_reference ;
	int m_flags ;

	struct SceGmoMeshCache *m_cache ;
	int m_material ;
	int *m_blend_subset ;
	int m_n_blend_subset ;
} ;

//  material structure
enum {
	PSP_GMO_MATERIAL_HAS_IMPLICIT_LAYER		= 0x80000000,
	PSP_GMO_MATERIAL_HAS_EXPLICIT_AMBIENT	= 0x40000000,
	PSP_GMO_MATERIAL_HAS_DIFFUSE				= 0x0001,
	PSP_GMO_MATERIAL_HAS_SPECULAR			= 0x0002,
	PSP_GMO_MATERIAL_HAS_EMISSION			= 0x0004,
	PSP_GMO_MATERIAL_HAS_AMBIENT				= 0x0008,
	PSP_GMO_MATERIAL_HAS_REFLECTION			= 0x0010,
	PSP_GMO_MATERIAL_HAS_REFRACTION			= 0x0020,
	PSP_GMO_MATERIAL_HAS_BUMP				= 0x0040,
	PSP_GMO_MATERIAL_HAS_TEX_CROP			= 0x0100,
	PSP_GMO_MATERIAL_HAS_TEX_CROPS			= 0xff00,
} ;

enum {
	PSP_GMO_MATERIAL_COLOR_BLACK				= 0,
	PSP_GMO_MATERIAL_COLOR_DIFFUSE			= 1,
	PSP_GMO_MATERIAL_COLOR_SPECULAR			= 2,
	PSP_GMO_MATERIAL_COLOR_EMISSION			= 3,
	PSP_GMO_MATERIAL_COLOR_AMBIENT			= 4,
	PSP_GMO_MATERIAL_COLOR_REFLECTION		= 5,
} ;

enum {
	PSP_GMO_MATERIAL_ANIM_MODIFIED			= 0x0000ffff,
	PSP_GMO_MATERIAL_ANIM_COMPLETE			= 0xffff0000,
} ;

struct SceGmoMaterial {
	SceGmoBase m_base ;
	SceGmoMaterial *m_initial ;
	int m_reference ;
	int m_flags ;

	SceGmoLayer *m_layers[ 8 ] ;
	int m_n_layers ;

	int m_enable_mask ;
	int m_enable_bits ;
	SceGmoCol4 m_colors[ 6 ] ;
	float m_shininess ;
	float m_refraction ;
	float m_bump ;

	int m_anim_flags ;
	float m_anim_weights[ 5 ] ;
} ;


//  layer structure
enum {
	PSP_GMO_LAYER_HAS_TEX_CROP		= 0x0001,
} ;

struct SceGmoLayer {
	SceGmoLayer *m_initial ;
	int m_reference ;
	int m_flags ;

	struct SceGmoLayerCache *m_cache ;
	int m_map_type ;
	float m_map_factor ;
	int m_blend_func[ 5 ] ;
	int m_texture ;

	int m_enable_mask ;
	int m_enable_bits ;
	int m_diffuse ;
	int m_specular ;
	int m_ambient ;

	SceGmoRect m_tex_crop ;
} ;

//  texture structure
struct SceGmoTexture {
	SceGmoBase m_base ;
	SceGimPicture *m_picture ;
	int m_reference ;
	int m_flags ;
} ;

//  motion structure
enum {
	PSP_GMO_MOTION_IS_REPEAT_HOLD	= 0x0001,
} ;

struct SceGmoMotion {
	SceGmoBase m_base ;
	SceGmoChunk *m_chunk ;
	int m_reference ;
	int m_flags ;

	SceGmoChunk **m_anims ;
	SceGmoChunk **m_fcurves ;
	int m_n_anims ;
	int m_n_fcurves ;

	float m_frame_loop[ 2 ] ;
	float m_frame_rate ;
	float m_frame ;
	float m_weight ;
} ;

//  model context
enum {
	PSP_GMO_ENABLE_PRIVATE			= 0xffff0000,
	PSP_GMO_ENABLE_FLUSH				= 0x80000000,
	PSP_GMO_ENABLE_SEPARATE_SPECULAR	= 0x00010000,
	PSP_GMO_ENABLE_SHADE_MAP			= 0x00020000,
	PSP_GMO_ENABLE_DEFAULT			= (PSP_GMO_ENABLE_ALL | PSP_GMO_ENABLE_SEPARATE_SPECULAR)
} ;

void sceGmoContextBegin(void) ;
void sceGmoContextEnd(void) ;

void sceGmoContextSetBone( SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices ) ;
int  sceGmoContextSetMaterial( SceGmoMaterial *material, SceGmoModel *model, int index ) ;
void sceGmoContextSetTexture( SceGmoTexture *texture, SceGmoModel *model ) ;

void sceGmoContextDefaultEnableBits( int mask, int bits ) ;
void sceGmoContextSetEnableBits( int mask, int bits ) ;

void sceGmoContextDefaultTexOffs( const SceGmoRect *offs ) ;
void sceGmoContextDefaultTexCrop( const SceGmoRect *crop ) ;
void sceGmoContextDefaultTexTrim( const SceGmoRect *trim ) ;
void sceGmoContextSetTexOffs( const SceGmoRect *offs ) ;
void sceGmoContextSetTexCrop( const SceGmoRect *crop ) ;
void sceGmoContextSetTexTrim( const SceGmoRect *trim ) ;


//  private math implementation                                     
extern const SceGmoVec3 sceGmoVec3_One ;
extern const SceGmoVec4 sceGmoVec4_One ;
extern const SceGmoMat4 sceGmoMat4_One ;
extern const SceGmoQuat sceGmoQuat_One ;
extern const SceGmoRect sceGmoRect_One ;
extern const SceGmoCol4 sceGmoCol4_One ;

SceGmoVec3 *sceGmoVec3Set( SceGmoVec3 *dst, float x, float y, float z ) ;
SceGmoVec4 *sceGmoVec4Set( SceGmoVec4 *dst, float x, float y, float z, float w ) ;
SceGmoMat4 *sceGmoMat4Set( SceGmoMat4 *dst, float tx, float ty, float tz, float sx, float sy, float sz ) ;
SceGmoQuat *sceGmoQuatSet( SceGmoQuat *dst, float x, float y, float z, float w ) ;
SceGmoRect *sceGmoRectSet( SceGmoRect *dst, float x, float y, float w, float h ) ;
SceGmoCol4 *sceGmoCol4Set( SceGmoCol4 *dst, float r, float g, float b, float a ) ;

SceGmoVec3 *sceGmoVec3Load( SceGmoVec3 *dst, const SceGmoVec3F *src ) ;
SceGmoVec4 *sceGmoVec4Load( SceGmoVec4 *dst, const SceGmoVec4F *src ) ;
SceGmoMat4 *sceGmoMat4Load( SceGmoMat4 *dst, const SceGmoMat4F *src ) ;
SceGmoQuat *sceGmoQuatLoad( SceGmoQuat *dst, const SceGmoQuatF *src ) ;
SceGmoRect *sceGmoRectLoad( SceGmoRect *dst, const SceGmoRectF *src ) ;
SceGmoCol4 *sceGmoCol4Load( SceGmoCol4 *dst, const SceGmoCol4F *src ) ;

SceGmoMat4 *sceGmoMat4Multiply( SceGmoMat4 *dst, const SceGmoMat4 *src1, const SceGmoMat4 *src2 ) ;
SceGmoMat4 *sceGmoMat4Scale( SceGmoMat4 *dst, const SceGmoMat4 *src1, const SceGmoVec3 *src2 ) ;
float *sceGmoFloatLerp( float *dst, const float *src1, const float *src2, int count, float f ) ;

SceGmoMat4 *sceGmoMat4FromQuat( SceGmoMat4 *dst, const SceGmoQuat *src ) ;
SceGmoQuat *sceGmoQuatFromRotZYX( SceGmoQuat *dst, const SceGmoVec3 *src ) ;
SceGmoQuat *sceGmoQuatFromRotYXZ( SceGmoQuat *dst, const SceGmoVec3 *src ) ;
SceGmoQuat *sceGmoQuatSlerp( SceGmoQuat *dst, const SceGmoQuat *src1, const SceGmoQuat *src2, float f ) ;

SceGmoVec4 *sceGmoVec4FromCol4( SceGmoVec4 *dst, const SceGmoCol4 *src ) ;
SceGmoCol4 *sceGmoCol4FromVec4( SceGmoCol4 *dst, const SceGmoVec4 *src ) ;
bool sceGmoCol4IsBlack( const SceGmoCol4 *src ) ;
bool sceGmoCol4IsHollow( const SceGmoCol4 *src ) ;

void sceGmoBoneAffineMatrix( SceGmoMat4 *m, const SceGmoVec3 *translate, const SceGmoQuat *rotate, const SceGmoVec3 *scale, int flags ) ;
int  sceGmoBoneStackScale( SceGmoMat4 *m, SceGmoVec3 *sscale, const SceGmoVec3 *lscale, int flags, const SceGmoVec3 *sscale2, const SceGmoVec3 *lscale2, int flags2 ) ;
void sceGmoBoneApplyPivot( SceGmoMat4 *m, const SceGmoVec3 *pivot, const SceGmoVec3 *scale ) ;

#ifdef __cplusplus
}
#endif

#endif
