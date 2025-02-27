
/*
 * I have no clue if i have this lib correct... 
 * Not sure it links to a prx.. might be missing a proper .a library from the sdk.
 * May have to code all these functions by hand and create this library... bummer.
 */

#ifndef __PSPGIM_PICTURE_H__
#define __PSPGIM_PICTURE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PSP_GIM_TARGET_PREVIEWER
#include <stdbool.h>
#include <pspgu.h>
#include <pspgum.h>
#endif

#include <pspgim_format.h>

#ifdef __cplusplus
extern "C" {
#endif

//  enums
enum SceGimDuplicate{
	PSP_GIM_DUPLICATE_REFERENCE	= 0x0000,
	PSP_GIM_DUPLICATE_STRUCTURE	= 0x0001,
	PSP_GIM_DUPLICATE_AUTOMATIC	= 0x0002,
	PSP_GIM_DUPLICATE_PICTURE	= 0x0008,
	PSP_GIM_DUPLICATE_IMAGE		= 0x0010,
	PSP_GIM_DUPLICATE_PALETTE	= 0x0020,
	PSP_GIM_DUPLICATE_SEQUENCE	= 0x0040
} ;

enum SceGimEnable{
	PSP_GIM_ENABLE_ALL			= 0xffff,
	PSP_GIM_ENABLE_DISSOLVE		= 0x0001,
	PSP_GIM_ENABLE_FACTOR		= 0x0002,
	PSP_GIM_ENABLE_CROP			= 0x0004,
	PSP_GIM_ENABLE_BLEND			= 0x0100,
	PSP_GIM_ENABLE_FUNC			= 0x0200,
	PSP_GIM_ENABLE_FILTER		= 0x0400,
	PSP_GIM_ENABLE_WRAP			= 0x0800,
} ;

//  classes
typedef struct SceGimPicture SceGimPicture ;

//  callback
void sceGimPictureSetMemoryManager( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;
void sceGimPictureSetMemoryManager2( void *(*alloc_func)( size_t ), void (*free_func)( void * ) ) ;

void *sceGimPictureAllocMemory( size_t size ) ;
void sceGimPictureFreeMemory( void *addr ) ;
void *sceGimPictureAllocMemory2( size_t size ) ;
void sceGimPictureFreeMemory2( void *addr ) ;

//  picture file
bool sceGimPictureCheckFileHeader( const void *buf, int size ) ;
int sceGimPictureGetChunkCount( const void *buf, int size ) ;
SceGimChunk *sceGimPictureGetChunk( const void *buf, int size, int index ) ;

//  picture class
SceGimPicture *sceGimPictureCreate( SceGimChunk *chunk ) ;
void sceGimPictureDelete( SceGimPicture *picture ) ;
SceGimPicture *sceGimPictureDuplicate( SceGimPicture *picture, int flags ) ;

bool sceGimPictureLoadFile( SceGimPicture *picture, const void *buf, int size, int index ) ;
bool sceGimPictureLoadTm2( SceGimPicture *picture, const void *buf, int size, int index ) ;
bool sceGimPictureLoadTga( SceGimPicture *picture, const void *buf, int size ) ;
bool sceGimPictureLoadBmp( SceGimPicture *picture, const void *buf, int size ) ;

bool sceGimPictureLoad( SceGimPicture *picture, SceGimChunk *chunk ) ;
void sceGimPictureUnload( SceGimPicture *picture ) ;
void sceGimPictureAnimate( SceGimPicture *picture, float step ) ;
void sceGimPictureControl( SceGimPicture *picture, int param, float value ) ;
void sceGimPictureActivate( SceGimPicture *picture ) ;
void sceGimPictureActivateTexture( SceGimPicture *picture ) ;
void sceGimPictureActivateRenderState( SceGimPicture *picture ) ;
bool sceGimPictureLoadCache( SceGimPicture *picture ) ;
void sceGimPictureUnloadCache( SceGimPicture *picture ) ;

void sceGimPictureSetEnableBits( SceGimPicture *picture, int bits, int value ) ;
int sceGimPictureGetEnableBits( SceGimPicture *picture ) ;
void sceGimPictureSetImageCrop( SceGimPicture *picture, const float *crop ) ;
const float *sceGimPictureGetImageCrop( SceGimPicture *picture ) ;

SceGimImageHeader *sceGimPictureGetImage( SceGimPicture *picture ) ;
SceGimPaletteHeader *sceGimPictureGetPalette( SceGimPicture *picture ) ;
void *sceGimPictureGetImagePixels( SceGimPicture *picture, int level, int frame ) ;
void *sceGimPictureGetPalettePixels( SceGimPicture *picture, int level, int frame ) ;
void sceGimPictureSetImagePixels( SceGimPicture *picture, int level, int frame, void *pixels ) ;
void sceGimPictureSetPalettePixels( SceGimPicture *picture, int level, int frame, void *pixels ) ;
bool sceGimPictureReallocImage( SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels ) ;
bool sceGimPictureReallocPalette( SceGimPicture *picture, int format, int w, int level, int frame, void *pixels ) ;

bool sceGimPictureHasAnimation( SceGimPicture *picture ) ;
void sceGimPictureSetFrameLoop( SceGimPicture *picture, float start, float end ) ;
const float *sceGimPictureGetFrameLoop( SceGimPicture *picture ) ;
void sceGimPictureSetFrameRate( SceGimPicture *picture, float fps ) ;
float sceGimPictureGetFrameRate( SceGimPicture *picture ) ;
void sceGimPictureSetFrameRepeat( SceGimPicture *picture, int mode ) ;
int sceGimPictureGetFrameRepeat( SceGimPicture *picture ) ;
void sceGimPictureSetFrame( SceGimPicture *picture, float frame ) ;
float sceGimPictureGetFrame( SceGimPicture *picture ) ;
void sceGimPictureSetImageFrame( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetImageFrame( SceGimPicture *picture ) ;
void sceGimPictureSetImageFrame2( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetImageFrame2( SceGimPicture *picture ) ;
void sceGimPictureSetPaletteFrame( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetPaletteFrame( SceGimPicture *picture ) ;
void sceGimPictureSetPaletteFrame2( SceGimPicture *picture, int frame ) ;
int sceGimPictureGetPaletteFrame2( SceGimPicture *picture ) ;
void sceGimPictureSetDissolve( SceGimPicture *picture, float dissolve ) ;
float sceGimPictureGetDissolve( SceGimPicture *picture ) ;

int sceGimPictureGetSequenceCount( SceGimPicture *picture ) ;
SceGimSequenceHeader *sceGimPictureGetSequence( SceGimPicture *picture, int index ) ;
void sceGimPictureSetCurrentSequence( SceGimPicture *picture, int index ) ;
int sceGimPictureGetCurrentSequence( SceGimPicture *picture ) ;

int sceGimPictureGetImagePlaneCount( SceGimPicture *picture ) ;
void sceGimPictureSetImagePlane( SceGimPicture *picture, int plane ) ;
int sceGimPictureGetImagePlane( SceGimPicture *picture ) ;
void sceGimPictureSetPaletteOffset( SceGimPicture *picture, int shift, int mask, int offs ) ;
const int *sceGimPictureGetPaletteOffset( SceGimPicture *picture ) ;

void sceGimPictureSetBlend( SceGimPicture *picture, int mode ) ;
const int *sceGimPictureGetBlend( SceGimPicture *picture ) ;
void sceGimPictureSetFunc( SceGimPicture *picture, int mode, int comp ) ;
const int *sceGimPictureGetFunc( SceGimPicture *picture ) ;
void sceGimPictureSetFilter( SceGimPicture *picture, int mag, int min ) ;
const int *sceGimPictureGetFilter( SceGimPicture *picture ) ;
void sceGimPictureSetWrap( SceGimPicture *picture, int u, int v ) ;
const int *sceGimPictureGetWrap( SceGimPicture *picture ) ;

//  compatibility functions
void sceGimPictureInitDevice( void *device, int flags ) ;
void sceGimPictureTermDevice() ;



//-----------------EXTRA C OBJECT FUNCTIONS-----------------
//used calculate image width and height
int sceGimPicturePow2( int num );

//unused
int sceGimPictureCLZ( int num );

//unused
int sceGimPictureCTZ( int num );

//-----------------FORMAT-----------------
//get the format of a gim image
int sceGimImageGetFormat( const SceGimImageHeader *image );

//set the format of a gim image
void sceGimImageSetFormat( const SceGimImageHeader *image, unsigned short format );

//-----------------ORDER-----------------
//get the order of a gim image
int sceGimImageGetOrder( const SceGimImageHeader *image );

//set the order of a gim image
void sceGimImageSetOrder( const SceGimImageHeader *image, unsigned short bpp );

//-----------------BPP-----------------
//get the bpp of a gim image
int sceGimImageGetBPP( const SceGimImageHeader *image );

//set the bpp of a gim image
void sceGimImageSetBPP( const SceGimImageHeader *image, unsigned short bpp );

//-----------------IMAGE WIDTH-----------------
//get the gim image width
int sceGimImageGetWidth( const SceGimImageHeader *image, int level );

//set the gim image width
void sceGimImageSetWidth( const SceGimImageHeader *image, unsigned short width );

//-----------------IMAGE HEIGHT-----------------
//get the gim image height
int sceGimImageGetHeight( const SceGimImageHeader *image, int level );

//set the gim image height
void sceGimImageSetHeight( const SceGimImageHeader *image, unsigned short height );

//-----------------IMAGE PITCH-----------------
//get the gim image pitch
int sceGimImageGetPitch( const SceGimImageHeader *image, int width );

//set the gim image pitch
void sceGimImageSetPitch( const SceGimImageHeader *image, unsigned short pitch_align );

//-----------------BUFFER WIDTH-----------------
//get the gim image buffer width
int sceGimImageGetBufWidth( const SceGimImageHeader *image, int width );

//set the gim image buffer width
void sceGimImageSetBufWidth( const SceGimImageHeader *image, unsigned short pitch_align );

//-----------------BUFFER HEIGHT-----------------
//get the gim image buffer height
int sceGimImageGetBufHeight( const SceGimImageHeader *image, int height );

//set the gim image buffer height
void sceGimImageSetBufHeight( const SceGimImageHeader *image, unsigned short height_align );

//-----------------TEXTURE WIDTH-----------------
//get the gim image texture width
int sceGimImageGetTexWidth( const SceGimImageHeader *image, int width );

//set the gim image texture width
void sceGimImageSetTexWidth( const SceGimImageHeader *image, unsigned short width );

//-----------------TEXTURE HEIGHT-----------------
//get the gim image texture height
int sceGimImageGetTexHeight( const SceGimImageHeader *image, int height );

//set the gim image texture height
void sceGimImageSetTexHeight( const SceGimImageHeader *image, unsigned short height );

//-----------------PLANE MASK-----------------
//get the gim image plane mask
int sceGimImageGetPlaneMask( const SceGimImageHeader *image );

//set the gim image plane mask
void sceGimImageSetPlaneMask( const SceGimImageHeader *image, unsigned int plane_mask );

//-----------------LEVEL COUNT-----------------
//get the level count of a gim image
int sceGimImageGetLevelCount( const SceGimImageHeader *image );

//set the level count of a gim image
void sceGimImageSetLevelCount( const SceGimImageHeader *image , unsigned short level_count );

//-----------------FRAME COUNT-----------------
//get the number of frames in a gim image
int sceGimImageGetFrameCount( const SceGimImageHeader *image );

//set the number of frames in the gim image
void sceGimImageSetFrameCount( const SceGimImageHeader *image, unsigned short frame_count );

//-----------------USER DATA-----------------
//get the image user data
void *sceGimImageGetUserData( const SceGimImageHeader *image );

//return the size of the data block minus the header
void sceGimImageGetUserDataSize( const SceGimImageHeader *image );

//-----------------PIXELS-----------------
//get the pixel data from gim image
void *sceGimImageGetPixels( const SceGimImageHeader *image, int level, int frame );

//set the pixel data for gim image
void sceGimImageSetPixels( SceGimImageHeader *image, void **offsets, int n_levels, int n_frames );

//-----------------CHUNK----------------
int sceGimChunkType( SceGimChunk *chunk );
SceGimChunk *sceGimChunkNext( SceGimChunk *chunk );
SceGimChunk *sceGimChunkChild( SceGimChunk *chunk );
void *sceGimChunkData( SceGimChunk *chunk );
int sceGimChunkSize( SceGimChunk *chunk );
int sceGimChunkTagSize( SceGimChunk *chunk );
int sceGimChunkDataSize( SceGimChunk *chunk );
int sceGimChunkChildSize( SceGimChunk *chunk );
void *sceGimChunkSkipString( const char *str, int align );

#ifdef __cplusplus
}
#endif

#endif
