/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspmsstor.h - Memory stick storage functions
 *
 * Copyright (c) 2006 Adrahil
 *
 */
#ifndef PSPMSSTOR_H
#define PSPMSSTOR_H

#ifdef __cplusplus
extern "C" {
#endif

//#define SCE_MSSTOR_ERROR(sev, kind) (int)(SCE_ERROR_MAKE_ERROR(SCE_ERROR_FACILITY_MEMSTICK,((1 << 8) | (sev & 1)<<7) | (kind & 0x7F)))
//#define SCE_MSSTOR_FERROR(sev, kind) (int)(SCE_ERROR_MAKE_CRITICAL(SCE_ERROR_FACILITY_MEMSTICK,((1 << 8) | (sev & 1)<<7) | (kind & 0x7F)))


#define SCE_MSSTOR_WARN               0x80220100 //warning error                     
#define SCE_MSSTOR_ERR                0x80220180 //gneral error                      
#define SCE_MSSTOR_FATAL              0xC0220100 //fatal  error                      

#define SCE_MSSTOR_EEXIST             0x80220181 //already exist                     
#define SCE_MSSTOR_EACCESS            0x80220182 //access violation                  
#define SCE_MSSTOR_EINVAL             0x80220183 //invalid parameter or mode         
#define SCE_MSSTOR_ETIMEDOUT          0x80220184 //timeout                           
#define SCE_MSSTOR_ERR_WRITEPROTECTED 0x80220185 //Media Write Protected             
#define SCE_MSSTOR_ERR_READONLY       0x80220186 //Media is readonly media or state  
#define SCE_MSSTOR_ERR_NOBLOCK        0x80220187 //failed to allocate a block        
#define SCE_MSSTOR_ERR_INVALID_PARAM  0x80220188 //parameter invalid                 
 
#define SCE_IOCTL_DEVICE_MS_STOR  (0x21)
#define PSP_MSSTOR_CTLCODE(dst, src, priv, cache, wait, devctl, funcno) \
((SCE_IOCTL_DEVICE_MS_STOR << 20) | \
 ((dst    & 1) << 17)   | \
 ((src    & 1) << 16)   | \
 ((priv   & 1) << 15)   | \
 ((cache  & 1) << 14)   | \
 ((wait   & 3) << 12)   | \
 ((devctl & 1) << 11)   | \
 ((funcno << 0) & 0x07ff))

// ioctls 
#define SCE_MSSTOR_TEST_UNIT_READY            PSP_MSSTOR_CTLCODE(1, 0, 0, 1, 1, 0, 1)
#define SCE_MSSTOR_START                      PSP_MSSTOR_CTLCODE(0, 0, 0, 1, 1, 0, 2)
#define SCE_MSSTOR_STOP                       PSP_MSSTOR_CTLCODE(0, 0, 0, 1, 1, 0, 3)
#define SCE_MSSTOR_CACHE_FLUSH                PSP_MSSTOR_CTLCODE(0, 0, 0, 1, 1, 0, 4)
#define SCE_MSSTOR_GET_CACHE_SIZE             PSP_MSSTOR_CTLCODE(0, 0, 0, 1, 1, 0, 5)
#define SCE_MSSTOR_READ_CAPACITY              PSP_MSSTOR_CTLCODE(1, 0, 0, 1, 1, 0, 6)
#define SCE_MSSTOR_GET_BLOCK_SIZE             PSP_MSSTOR_CTLCODE(1, 0, 0, 1, 1, 0, 7)
#define SCE_MSSTOR_GET_MEDIUM_PROTECT_STATE   PSP_MSSTOR_CTLCODE(1, 0, 0, 1, 1, 0, 8)
#define SCE_MSSTOR_GET_MEDIUM_WP_SWITCH_STATE PSP_MSSTOR_CTLCODE(1, 0, 0, 1, 1, 0, 9)

// devctls 
#define SCE_MSSTOR_GET_MEDIUM_TYPE			 PSP_MSSTOR_CTLCODE(1, 0, 0, 1, 1, 1, 1)
#define SCE_MSSTOR_GET_MEDIUM_TYPE2			 PSP_MSSTOR_CTLCODE(1, 0, 0, 1, 1, 1, 2)
#define SCE_MSSTOR_GET_ATTRIBUTE_AREA		 PSP_MSSTOR_CTLCODE(1, 0, 0, 1, 1, 1, 3)

typedef struct sceMSstorMediaTypeTuple{
	sceUChar   mt_type;				 // value of MS register #04 
	sceUChar   mt_category;			 // value of MS register #06 
	sceUChar   mt_class;			 // value of MS register #07 
	sceUChar   mt_parallel;			 //  Std: offset 0x1d3 of boot&attribute area 
	// Pro: offset 0x033 of system information area 
	sceUChar   mt_device_id;		 // Std: offset 0x1d8 of boot&attribute area 
	// Pro: offset 0x038 of system information area 
} sceMSstorMediaTypeTuple;

typedef enum sceMSstorMediaType2{
	SCE_MSSTOR_MEDIA_TYPE2_UNKNOWN	= (0),
	SCE_MSSTOR_MEDIA_TYPE2_V1	    = (0x10),
	SCE_MSSTOR_MEDIA_TYPE2_V1_ROM	= (0x11),
	SCE_MSSTOR_MEDIA_TYPE2_PRO	    = (0x40),
	SCE_MSSTOR_MEDIA_TYPE2_PRO_ROM	= (0x41),
	SCE_MSSTOR_MEDIA_TYPE2_PAD      = (0x40000000)
} sceMSstorMediaType2;


extern int sceMSstorRegisterCLDMSelf(char * path);


#ifdef __cplusplus
}
#endif

#endif
