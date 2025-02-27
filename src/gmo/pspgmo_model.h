#ifndef __PSPGMO_MODEL_H__
#define __PSPGMO_MODEL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef PSP_GMO_TARGET_PREVIEWER
#include <stdbool.h>
#include <pspgu.h>
#include <pspgum.h>
#endif

#include <pspgmo_types.h>
#include <pspgmo_format.h>
#include <pspgmo_metrics.h>
#include <pspgim_picture.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PSP_GMO_LIBRARY_VERSION (0x01050000)


//  enums


enum {
	PSP_GMO_DUPLICATE_REFERENCE	= 0x0000,
	PSP_GMO_DUPLICATE_STRUCTURE	= 0x0001,
	PSP_GMO_DUPLICATE_AUTOMATIC	= 0x0002,
	PSP_GMO_DUPLICATE_MODEL		= 0x0008,
	PSP_GMO_DUPLICATE_BONE		= 0x0010,
	PSP_GMO_DUPLICATE_PART		= 0x0020,
	PSP_GMO_DUPLICATE_MESH		= 0x0040,
	PSP_GMO_DUPLICATE_ARRAYS		= 0x0080,
	PSP_GMO_DUPLICATE_MATERIAL	= 0x0100,
	PSP_GMO_DUPLICATE_LAYER		= 0x0200,
	PSP_GMO_DUPLICATE_TEXTURE	= 0x0400,
	PSP_GMO_DUPLICATE_MOTION		= 0x0800,
	PSP_GMO_DUPLICATE_FCURVE		= 0x1000
} ;

enum {
	PSP_GMO_ENABLE_ALL			= 0xffff,
	PSP_GMO_ENABLE_LIGHTING		= 0x0001,
	PSP_GMO_ENABLE_FOG			= 0x0002,
	PSP_GMO_ENABLE_TEXTURE		= 0x0004,
	PSP_GMO_ENABLE_CULL_FACE		= 0x0008,
	PSP_GMO_ENABLE_DEPTH_TEST	= 0x0010,
	PSP_GMO_ENABLE_DEPTH_MASK	= 0x0020,
	PSP_GMO_ENABLE_ALPHA_TEST	= 0x0040,
	PSP_GMO_ENABLE_ALPHA_MASK	= 0x0080
} ;


//  classes
typedef struct SceGmoModel SceGmoModel ;
typedef struct SceGmoBone SceGmoBone ;
typedef struct SceGmoPart SceGmoPart ;
typedef struct SceGmoMesh SceGmoMesh ;
typedef struct SceGmoMaterial SceGmoMaterial ;
typedef struct SceGmoLayer SceGmoLayer ;
typedef struct SceGmoTexture SceGmoTexture ;
typedef struct SceGmoMotion SceGmoMotion ;


//  callback
void sceGmoModelSetMemoryManager( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGmoModelSetMemoryManager2( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGmoModelSetPictureManager( SceGimPicture *(*get_func)( const char *filename ), void (*set_func)( const char *filename, SceGimPicture *picture ) ) ;

void *sceGmoModelOpenMemoryCluster( size_t size, size_t align ) ;
void *sceGmoModelOpenMemoryCluster2( size_t size, size_t align ) ;
int sceGmoModelCloseMemoryCluster() ;
int sceGmoModelCloseMemoryCluster2() ;

void *sceGmoModelAllocMemory( size_t size ) ;
void *sceGmoModelAllocMemory2( size_t size ) ;
void sceGmoModelFreeMemory( void *addr ) ;
void sceGmoModelFreeMemory2( void *addr ) ;

SceGimPicture *sceGmoModelImportPicture( const char *filename ) ;
void sceGmoModelExportPicture( const char *filename, SceGimPicture *picture ) ;


//  model file
bool sceGmoModelCheckFileHeader( const void *buf, int size ) ;
int sceGmoModelGetChunkCount( const void *buf, int size ) ;
SceGmoChunk *sceGmoModelGetChunk( const void *buf, int size, int index ) ;


//  model class
SceGmoModel *sceGmoModelCreate( SceGmoChunk *chunk ) ;
void sceGmoModelDelete( SceGmoModel *model ) ;
SceGmoModel *sceGmoModelDuplicate( SceGmoModel *model, int flags ) ;

bool sceGmoModelLoadFile( SceGmoModel *model, const void *buf, int size, int index ) ;
bool sceGmoModelLoad( SceGmoModel *model, SceGmoChunk *chunk ) ;
void sceGmoModelUnload( SceGmoModel *model ) ;
bool sceGmoModelLoadCache( SceGmoModel *model ) ;
void sceGmoModelUnloadCache( SceGmoModel *model ) ;
void sceGmoModelAnimate( SceGmoModel *model, float step ) ;
void sceGmoModelUpdate( SceGmoModel *model ) ;
void sceGmoModelDraw( SceGmoModel *model ) ;

void sceGmoModelSetWorldMatrix( SceGmoModel *model, const SceGmoMat4 *m ) ;
const SceGmoMat4 *sceGmoModelGetWorldMatrix( SceGmoModel *model ) ;
void sceGmoModelSetCurrentMotion( SceGmoModel *model, int index, float delay ) ;
int sceGmoModelGetCurrentMotion( SceGmoModel *model ) ;

void sceGmoModelSetEnableBits( SceGmoModel *model, int bits, int value ) ;
int sceGmoModelGetEnableBits( SceGmoModel *model ) ;
void sceGmoModelSetEnableMask( SceGmoModel *model, int mask, int value ) ;
int sceGmoModelGetEnableMask( SceGmoModel *model ) ;

bool sceGmoModelHasAnimation( SceGmoModel *model ) ;
const SceGmoVec3 *sceGmoModelGetBoundingBox( SceGmoModel *model ) ;
const SceGmoMat4 *sceGmoModelGetVertexOffset( SceGmoModel *model ) ;
const SceGmoRect *sceGmoModelGetTexcoordOffset( SceGmoModel *model ) ;

int sceGmoModelGetBoneCount( SceGmoModel *model ) ;
int sceGmoModelGetPartCount( SceGmoModel *model ) ;
int sceGmoModelGetMaterialCount( SceGmoModel *model ) ;
int sceGmoModelGetTextureCount( SceGmoModel *model ) ;
int sceGmoModelGetMotionCount( SceGmoModel *model ) ;

SceGmoBone *sceGmoModelGetBone( SceGmoModel *model, int index ) ;
SceGmoPart *sceGmoModelGetPart( SceGmoModel *model, int index ) ;
SceGmoMaterial *sceGmoModelGetMaterial( SceGmoModel *model, int index ) ;
SceGmoTexture *sceGmoModelGetTexture( SceGmoModel *model, int index ) ;
SceGmoMotion *sceGmoModelGetMotion( SceGmoModel *model, int index ) ;
SceGmoBone *sceGmoModelSetBone( SceGmoModel *model, int index, SceGmoBone *bone, int flags ) ;
SceGmoPart *sceGmoModelSetPart( SceGmoModel *model, int index, SceGmoPart *part, int flags ) ;
SceGmoMaterial *sceGmoModelSetMaterial( SceGmoModel *model, int index, SceGmoMaterial *material, int flags ) ;
SceGmoTexture *sceGmoModelSetTexture( SceGmoModel *model, int index, SceGmoTexture *texture, int flags ) ;
SceGmoMotion *sceGmoModelSetMotion( SceGmoModel *model, int index, SceGmoMotion *motion, int flags ) ;


//  bone class
SceGmoBone *sceGmoBoneCreate( SceGmoChunk *chunk ) ;
void sceGmoBoneDelete( SceGmoBone *bone ) ;
SceGmoBone *sceGmoBoneDuplicate( SceGmoBone *bone, int flags ) ;

bool sceGmoBoneLoad( SceGmoBone *bone, SceGmoChunk *chunk ) ;
void sceGmoBoneUnload( SceGmoBone *bone ) ;
void sceGmoBoneUpdate( SceGmoBone *bone, SceGmoModel *model ) ;
void sceGmoBoneDraw( SceGmoBone *bone, SceGmoModel *model ) ;
void sceGmoBoneActivate( SceGmoBone *bone, SceGmoModel *model, const int *indices, int n_indices ) ;
void sceGmoBoneControl( SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoBoneSetParent( SceGmoBone *bone, SceGmoModel *parent ) ;

SceGmoModel *sceGmoBoneGetParent( SceGmoBone *bone ) ;
const SceGmoMat4 *sceGmoBoneGetWorldMatrix( SceGmoBone *bone ) ;

//  part class
SceGmoPart *sceGmoPartCreate( SceGmoChunk *chunk ) ;
void sceGmoPartDelete( SceGmoPart *part ) ;
SceGmoPart *sceGmoPartDuplicate( SceGmoPart *part, int flags ) ;

bool sceGmoPartLoad( SceGmoPart *part, SceGmoChunk *chunk ) ;
void sceGmoPartUnload( SceGmoPart *part ) ;
bool sceGmoPartLoadCache( SceGmoPart *part ) ;
void sceGmoPartUnloadCache( SceGmoPart *part ) ;
void sceGmoPartDraw( SceGmoPart *part, SceGmoModel *model, SceGmoBone *bone ) ;

void sceGmoPartSetParent( SceGmoPart *part, SceGmoModel *parent ) ;
SceGmoModel *sceGmoPartGetParent( SceGmoPart *part ) ;

int sceGmoPartGetMeshCount( SceGmoPart *part ) ;
int sceGmoPartGetArraysCount( SceGmoPart *part ) ;
SceGmoMesh *sceGmoPartGetMesh( SceGmoPart *part, int index ) ;
SceGmoChunk *sceGmoPartGetArrays( SceGmoPart *part, int index ) ;

//  mesh class
SceGmoMesh *sceGmoMeshCreate( SceGmoChunk *chunk ) ;
void sceGmoMeshDelete( SceGmoMesh *mesh ) ;
SceGmoMesh *sceGmoMeshDuplicate( SceGmoMesh *mesh, int flags ) ;

bool sceGmoMeshLoad( SceGmoMesh *mesh, SceGmoChunk *chunk ) ;
void sceGmoMeshUnload( SceGmoMesh *mesh ) ;
bool sceGmoMeshLoadCache( SceGmoMesh *mesh, SceGmoPart *part ) ;
void sceGmoMeshUnloadCache( SceGmoMesh *mesh ) ;
void sceGmoMeshDraw( SceGmoMesh *mesh, SceGmoModel *model, SceGmoBone *bone, SceGmoPart *part ) ;

//  material class
SceGmoMaterial *sceGmoMaterialCreate( SceGmoChunk *chunk ) ;
void sceGmoMaterialDelete( SceGmoMaterial *material ) ;
SceGmoMaterial *sceGmoMaterialDuplicate( SceGmoMaterial *material, int flags ) ;

bool sceGmoMaterialLoad( SceGmoMaterial *material, SceGmoChunk *chunk ) ;
void sceGmoMaterialUnload( SceGmoMaterial *material ) ;
bool sceGmoMaterialLoadCache( SceGmoMaterial *material ) ;
void sceGmoMaterialUnloadCache( SceGmoMaterial *material ) ;
void sceGmoMaterialUpdate( SceGmoMaterial *material, SceGmoModel *model ) ;
int sceGmoMaterialActivate( SceGmoMaterial *material, SceGmoModel *model, int index ) ;
void sceGmoMaterialControl( SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight ) ;

void sceGmoMaterialSetParent( SceGmoMaterial *material, SceGmoModel *parent ) ;
SceGmoModel *sceGmoMaterialGetParent( SceGmoMaterial *material ) ;

int sceGmoMaterialGetLayerCount( SceGmoMaterial *material ) ;
SceGmoLayer *sceGmoMaterialGetLayer( SceGmoMaterial *material, int index ) ;

//  layer class
SceGmoLayer *sceGmoLayerCreate( SceGmoChunk *chunk ) ;
void sceGmoLayerDelete( SceGmoLayer *layer ) ;
SceGmoLayer *sceGmoLayerDuplicate( SceGmoLayer *layer, int flags ) ;

bool sceGmoLayerLoad( SceGmoLayer *layer, SceGmoChunk *chunk ) ;
void sceGmoLayerUnload( SceGmoLayer *layer ) ;
bool sceGmoLayerLoadCache( SceGmoLayer *layer, SceGmoMaterial *material ) ;
void sceGmoLayerUnloadCache( SceGmoLayer *layer ) ;
int sceGmoLayerActivate( SceGmoLayer *layer, SceGmoModel *model, SceGmoMaterial *material ) ;

void sceGmoLayerSetMapType( SceGmoLayer *layer, int type ) ;
int sceGmoLayerGetMapType( SceGmoLayer *layer ) ;
void sceGmoLayerSetTexCrop( SceGmoLayer *layer, const SceGmoRect *crop ) ;
const SceGmoRect *sceGmoLayerGetTexCrop( SceGmoLayer *layer ) ;

//  texture class
SceGmoTexture *sceGmoTextureCreate( SceGmoChunk *chunk ) ;
void sceGmoTextureDelete( SceGmoTexture *texture ) ;
SceGmoTexture *sceGmoTextureDuplicate( SceGmoTexture *texture, int flags ) ;

bool sceGmoTextureLoad( SceGmoTexture *texture, SceGmoChunk *chunk ) ;
void sceGmoTextureUnload( SceGmoTexture *texture ) ;
void sceGmoTextureAnimate( SceGmoTexture *texture, SceGmoModel *model, float step ) ;
void sceGmoTextureActivate( SceGmoTexture *texture, SceGmoModel *model ) ;

void sceGmoTextureSetParent( SceGmoTexture *texture, SceGmoModel *parent ) ;
SceGmoModel *sceGmoTextureGetParent( SceGmoTexture *texture ) ;
void sceGmoTextureSetPicture( SceGmoTexture *texture, SceGimPicture *picture, int flags ) ;
SceGimPicture *sceGmoTextureGetPicture( SceGmoTexture *texture ) ;
bool sceGmoTextureHasAnimation( SceGmoTexture *texture ) ;

//  motion class
SceGmoMotion *sceGmoMotionCreate( SceGmoChunk *chunk ) ;
void sceGmoMotionDelete( SceGmoMotion *motion ) ;
SceGmoMotion *sceGmoMotionDuplicate( SceGmoMotion *motion, int flags ) ;

bool sceGmoMotionLoad( SceGmoMotion *motion, SceGmoChunk *chunk ) ;
void sceGmoMotionUnload( SceGmoMotion *motion ) ;
void sceGmoMotionAnimate( SceGmoMotion *motion, SceGmoModel *model, float step ) ;

void sceGmoMotionSetParent( SceGmoMotion *motion, SceGmoModel *parent ) ;
SceGmoModel *sceGmoMotionGetParent( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrameLoop( SceGmoMotion *motion, float start, float end ) ;
const float *sceGmoMotionGetFrameLoop( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrameRate( SceGmoMotion *motion, float fps ) ;
float sceGmoMotionGetFrameRate( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrameRepeat( SceGmoMotion *motion, int mode ) ;
int sceGmoMotionGetFrameRepeat( SceGmoMotion *motion ) ;
void sceGmoMotionSetFrame( SceGmoMotion *motion, float frame ) ;
float sceGmoMotionGetFrame( SceGmoMotion *motion ) ;
void sceGmoMotionSetWeight( SceGmoMotion *motion, float weight ) ;
float sceGmoMotionGetWeight( SceGmoMotion *motion ) ;

int sceGmoMotionGetAnimationCount( SceGmoMotion *motion ) ;
int sceGmoMotionGetFcurveCount( SceGmoMotion *motion ) ;
SceGmoChunk *sceGmoMotionGetAnimation( SceGmoMotion *motion, int index ) ;
SceGmoChunk *sceGmoMotionGetFcurve( SceGmoMotion *motion, int index ) ;

//  obsolete functions
void sceGmoBoneAnimate( SceGmoBone *bone, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoMaterialAnimate( SceGmoMaterial *material, int type, int idx, const float *val, int cnt, float weight ) ;
void sceGmoTextureUpdate( SceGmoTexture *texture, SceGmoModel *model, float step ) ;
void sceGmoMotionUpdate( SceGmoMotion *motion, SceGmoModel *model, float step ) ;

#ifdef __cplusplus
}
#endif

#endif
