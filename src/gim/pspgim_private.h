#ifndef __PSPGIM_PRIVATE_H__
#define __PSPGIM_PRIVATE_H__

#include "pspgim_protected.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef DEBUG
#define WARNING( format ) printf( format )
#define WARNING1( format, arg1 ) printf( format, arg1 )
#define WARNING2( format, arg1, arg2 ) printf( format, arg1, arg2 )
#define ASSERT( p ) { if (!(p)) { printf( "Assertion failed: %s, File %s, Line %d\n", #p, __FILE__, __LINE__ ) ; abort() ; } }
#else
#define WARNING( format )
#define WARNING1( format, arg1 )
#define WARNING2( format, arg1, arg2 )
#define ASSERT( p )
#endif

#define MALLOC(size) sceGimPictureAllocMemory( size )
#define MALLOC2(size) sceGimPictureAllocMemory2( size )
#define FREE(addr) sceGimPictureFreeMemory( addr )
#define FREE2(addr) sceGimPictureFreeMemory2( addr )

#define MEMCPY(dst,src,size) memcpy( dst, src, size )
#define MEMSET(dst,src,size) memset( dst, src, size )

extern int sceGimPictureCountChunk( SceGimChunk *chunk, int type ) ;
extern SceGimChunk *sceGimPictureFindChunk( SceGimChunk *chunk, int type, int idx ) ;

#ifdef __cplusplus
}
#endif

#endif
