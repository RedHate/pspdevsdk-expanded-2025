#ifndef __PSPGMO_TYPES_H__
#define __PSPGMO_TYPES_H__

#ifdef __cplusplus
extern "C" {
#endif

//  proxy types file format                                     
typedef struct SceGmoVec3F { float x, y, z ; } SceGmoVec3F ;
typedef struct SceGmoVec4F { float x, y, z, w ; } SceGmoVec4F ;
typedef struct SceGmoMat4F { SceGmoVec4F x, y, z, w ; } SceGmoMat4F ;
typedef struct SceGmoQuatF { float x, y, z, w ; } SceGmoQuatF ;
typedef struct SceGmoRectF { float x, y, w, h ; } SceGmoRectF ;
typedef struct SceGmoCol4F { float r, g, b, a ; } SceGmoCol4F ;

//  proxy types application                                     
#ifdef PSP_GMO_TARGET_PREVIEWER
typedef struct SceGmoVec3 { float x, y, z, w ; } PSP_GMO_ALIGNED SceGmoVec3 ;
typedef struct SceGmoVec4 { float x, y, z, w ; } PSP_GMO_ALIGNED SceGmoVec4 ;
typedef struct SceGmoMat4 { SceGmoVec4 x, y, z, w ; } PSP_GMO_ALIGNED SceGmoMat4 ;
typedef struct SceGmoQuat { float x, y, z, w ; } PSP_GMO_ALIGNED SceGmoQuat ;
typedef struct SceGmoRect { float x, y, w, h ; } PSP_GMO_ALIGNED SceGmoRect ;
typedef unsigned int SceGmoCol4 ;
#else 
typedef ScePspFVector4 SceGmoVec3 ;
typedef ScePspFVector4 SceGmoVec4 ;
typedef ScePspFMatrix4 SceGmoMat4 ;
typedef ScePspFQuaternion SceGmoQuat ;
typedef ScePspFRect PSP_GMO_ALIGNED SceGmoRect ;
typedef unsigned int SceGmoCol4 ;
#endif 

#ifdef __cplusplus
}
#endif

#endif
