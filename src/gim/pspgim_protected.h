#ifndef __PSPGIM_PROTECTED_H__
#define __PSPGIM_PROTECTED_H__

#include <pspgim_picture.h>

#ifdef __cplusplus
extern "C" {
#endif


//  configuration                                                   


#ifndef PSP_GIM_SUPPORT_NONGIMFILES
#define PSP_GIM_SUPPORT_NONGIMFILES 1
#endif
#ifndef PSP_GIM_SUPPORT_ANIMATION
#define PSP_GIM_SUPPORT_ANIMATION 1
#endif
#ifndef PSP_GIM_SUPPORT_SEQUENCE
#define PSP_GIM_SUPPORT_SEQUENCE 1
#endif
#ifndef PSP_GIM_SUPPORT_PLANEMASK
#define PSP_GIM_SUPPORT_PLANEMASK 1
#endif
#ifndef PSP_GIM_SUPPORT_RENDERSTATE
#define PSP_GIM_SUPPORT_RENDERSTATE 1
#endif

#if ( PSP_GIM_SUPPORT_SEQUENCE )
#define PSP_GIM_SUPPORT_ANIMATION 1
#endif

//  picture structures                                              
enum SceGimPictureAttr{
	PSP_GIM_PICTURE_HAS_IMAGE_LEVELS		= 0x0001,
	PSP_GIM_PICTURE_HAS_IMAGE_FRAMES		= 0x0002,
	PSP_GIM_PICTURE_HAS_PALETTE_LEVELS	= 0x0004,
	PSP_GIM_PICTURE_HAS_PALETTE_FRAMES	= 0x0008,

	PSP_GIM_PICTURE_IS_ANIMATED			= 0x0010,
	PSP_GIM_PICTURE_IS_CROPPED			= 0x0020,
	PSP_GIM_PICTURE_IS_NONPOW2			= 0x0040,
	PSP_GIM_PICTURE_IS_NOREPEAT			= 0x0080
};

typedef struct SceGimPicture {
	int m_reference ;
	int m_flags ;
	int m_enable_bits ;

	struct SceGimPictureCache *m_cache ;
	SceGimImageHeader *m_image ;
	SceGimPaletteHeader *m_palette ;

	int m_buf_width ;
	int m_clut_load ;
	float m_image_crop[ 4 ] ;

#if ( PSP_GIM_SUPPORT_ANIMATION )
	float m_frame_loop[ 2 ] ;
	float m_frame_rate ;
	float m_frame ;
	float m_dissolve ;

	int m_image_frame ;
	int m_image_frame2 ;
	int m_palette_frame ;
	int m_palette_frame2 ;
#endif

#if ( PSP_GIM_SUPPORT_SEQUENCE )
	SceGimSequenceHeader **m_sequences ;
	int m_n_sequences ;
	int m_current_sequence ;
#endif

#if ( PSP_GIM_SUPPORT_PLANEMASK )
	int m_image_plane ;
	int m_palette_offset[ 3 ] ;
#endif

#if ( PSP_GIM_SUPPORT_RENDERSTATE )
	int m_blend[ 1 ] ;
	int m_func[ 2 ] ;
	int m_filter[ 2 ] ;
	int m_wrap[ 2 ] ;
#endif
} SceGimPicture;


#ifdef __cplusplus
}
#endif

#endif
