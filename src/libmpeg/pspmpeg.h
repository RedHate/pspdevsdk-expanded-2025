/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspmpeg.h - Prototypes for the libmpeg library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBMPEG_H__
#define __LIBMPEG_H__

#ifdef __cplusplus
extern "C" {
#endif

#define PSP_MPEG_AVC_FORMAT_DEFAULT -1
#define PSP_MPEG_AVC_FORMAT_5650 0
#define PSP_MPEG_AVC_FORMAT_5551 1
#define PSP_MPEG_AVC_FORMAT_4444 2
#define PSP_MPEG_AVC_FORMAT_8888 3

// MPEG PACK SIZE
#define	PSP_MPEG_PACK_SIZE					(2048)

// LIBMPEG ERROR CODES
#define _PSP_MPEG_API_COMPLETION			(0x8001)
#define	_PSP_MPEG_API_PACKHEADER_FIELDFLAG	(0x8002)
#define	_PSP_MPEG_API_RINGBUFFER			(0x8003)
#define	_PSP_MPEG_API_NO_RAPI				(0x8004)
#define	_PSP_MPEG_API_ALREADY_USED			(0x8005)
#define	_PSP_MPEG_API_INTERNAL				(0x8006)
#define	_PSP_MPEG_API_ILLEGAL_STREAM		(0x8007)

// AVC DECODE ERRORS
#define _PSP_MPEG_VIDEO_CODEC_ERROR			(0x8001)
#define _PSP_MPEG_VIDEO_CODEC_FATAL			(0x8002)


// ERROR CODES
#define PSP_MPEG_OK		PSP_OK
#define PSP_MPEG_ERROR_NOT_COMPLETED		PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG, _PSP_MPEG_API_COMPLETION)
#define PSP_MPEG_ERROR_INVALID_VALUE		PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG,  PSP_ERROR_INVALID_VALUE)
#define PSP_MPEG_ERROR_UNMATCHED_VERSION	PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG,  PSP_ERROR_UNMATECHED_VERSION)
#define PSP_MPEG_ERROR_INVALID_POINTER		PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG,  PSP_ERROR_INVALID_POINTER)
#define PSP_MPEG_ERROR_OUT_OF_MEMORY		PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG,  PSP_ERROR_OUT_OF_MEMORY)
#define PSP_MPEG_ERROR_NO_RAPI				PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG, _PSP_MPEG_API_NO_RAPI)
#define PSP_MPEG_ERROR_ALREADY_USED			PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG, _PSP_MPEG_API_ALREADY_USED)
#define PSP_MPEG_ERROR_INTERNAL				PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG, _PSP_MPEG_API_INTERNAL)
#define PSP_MPEG_ERROR_ILLEGAL_STREAM		PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_MPEG, _PSP_MPEG_API_ILLEGAL_STREAM)

// VIDEO DECODER 
#define PSP_MPEG_ERROR_VIDEO_INVALID_VALUE  	PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_AVC, PSP_ERROR_INVALID_VALUE)
#define PSP_MPEG_ERROR_VIDEO_UNMATCHED_VERSION 	PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_AVC, PSP_ERROR_UNMATECHED_VERSION)
#define PSP_MPEG_ERROR_VIDEO_ERROR				PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_AVC, _PSP_MPEG_VIDEO_CODEC_ERROR)
#define PSP_MPEG_ERROR_VIDEO_FATAL 				PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_AVC, _PSP_MPEG_VIDEO_CODEC_FATAL)

// AUDIO DECOER 
#define PSP_MPEG_ERROR_AUDIO_INVALID_VALUE PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_CODEC, 0x0001)
#define PSP_MPEG_ERROR_AUDIO_ERROR PSP_ERROR_MAKE_ERROR(PSP_ERROR_FACILITY_CODEC, 0x0002)

typedef SceUInt32 sceMpegStreamId;
typedef SceUChar8* sceMpegHandle;

typedef struct sceMpegTimeStamp {
	SceUInt32 MSB_ts;
	SceUInt32 ts;
} sceMpegTimeStamp;

#define PSP_MPEG_VOID_TIMESTAMP (-1)

typedef struct sceMpegAu {
	sceMpegTimeStamp pts;
	sceMpegTimeStamp dts;
	SceUChar8 *pEsBuf;
	SceInt32 iEsSize;
} sceMpegAu;

typedef struct sceMpegStream {
	sceMpegStreamId qStreamId;
	sceMpegStreamId qStreamIdMask;
	SceVoid *m_pRAPICtrlStream;
	SceUChar8 *m_pRAPI;
	SceInt32 m_iAuNum;
	SceInt32 m_iPesPacketForwardSize;
	SceInt32 m_iPesPacketForwardFlag;
	SceShort16 m_iPesPacketAULocator;
	SceShort16 reserved;
	SceInt32 m_iPesPacketNum;
	SceInt32 m_iAuSize;
	SceInt32 m_iBoundarySize;
	SceInt32 m_iAuSizeOfProceed;
	SceUInt32 m_iGetAuMode;
	SceInt32 m_iPayloadHeaderRemainderFlag;
	SceInt32 m_iPayloadHeaderRemainderSize;
	SceChar8 m_cPayloadHeaderBuf[4];
} sceMpegStream;

typedef struct sceMpeg {
    SceVoid *sys;		/* system data for decoding*/
} sceMpeg;

// STREAM TYPES 
typedef enum sceMpegStrType_enum{
	PSP_MPEG_STREAM_M4AVC		= 0, 	/* MPEG4 AVC video stream*/
	PSP_MPEG_STREAM_ATRAC		= 1,    /* ATRAC3plus stream*/
	PSP_MPEG_STREAM_PCM         = 2,    /* PCM data */
	PSP_MPEG_STREAM_AUDIO       = 15    /* ATRAC3plus or PCM */
} sceMpegStrType_enum;

typedef SceInt32 sceMpegStrType;


// -------------- PSMF ---------------
/**
 * sceMpegQueryStreamOffset
 *
 * mp - SceMpeg handle
 * @param pBuffer - pointer to file header
 * @param iOffset - will contain stream offset in bytes, usually 2048
 *
 * @return 0 if success.
 */
SceInt32 sceMpegQueryStreamOffset (sceMpeg *mp, const SceVoid* addr, SceUInt32* offset);
/**
 * sceMpegQueryStreamSize
 *
 * @param pBuffer - pointer to file header
 * @param iSize - will contain stream size in bytes
 *
 * @return 0 if success.
 */
SceInt32 sceMpegQueryStreamSize (const SceVoid* addr, SceUInt32* stream_size);


// -------------- RING BUFFER --------------- 
typedef SceInt32 (*sceMpegRBCallback)(SceVoid *pBuf, SceInt32 iPackNum, SceVoid *CallbackData);

typedef struct sceMpegRingbuffer {
	SceInt32 m_iBufsize;
	SceInt32 m_iRpos;
	SceInt32 m_iWpos;
	SceInt32 m_iInlen;
	SceInt32 m_iTypeSize;
	SceVoid *m_pBuf;
	sceMpegRBCallback callback;
	SceVoid *m_CallbackData;
	SceVoid *pPack;
	SceInt32	iSemaRB;
	SceVoid *mp;
} sceMpegRingbuffer;

/**
 * sceMpegRingbufferQueryMemSize
 *
 * @param iPackets - number of packets in the ringbuffer
 *
 * @return < 0 if error else ringbuffer data size.
 */
SceInt32 sceMpegRingbufferQueryMemSize(SceInt32 iPackNum);

/**
 * sceMpegRingbufferConstruct
 *
 * @param Ringbuffer - pointer to a sceMpegRingbuffer struct
 * @param iPackets - number of packets in the ringbuffer
 * @param pData - pointer to allocated memory
 * @param iSize - size of allocated memory, shoud be sceMpegRingbufferQueryMemSize(iPackets)
 * @param Callback - ringbuffer callback
 * @param pCBparam - param passed to callback
 *
 * @return 0 if success.
 */
SceInt32 sceMpegRingbufferConstruct(sceMpegRingbuffer *pRingbuffer, SceInt32 iPackNum, SceVoid *pBuf, SceInt32 iSize, sceMpegRBCallback callback, SceVoid *pCallbackData);
/**
 * sceMpegRingbufferDestruct
 *
 * @param Ringbuffer - pointer to a sceMpegRingbuffer struct
 */
SceInt32 sceMpegRingbufferDestruct(sceMpegRingbuffer *pRingbuffer);
/**
 * sceMpegRingbufferPut
 *
 * @param Ringbuffer - pointer to a sceMpegRingbuffer struct
 * @param iNumPackets - num packets to put into the ringbuffer
 * @param iAvailable - free packets in the ringbuffer, should be sceMpegRingbufferAvailableSize()
 *
 * @return < 0 if error else number of packets.
 */
SceInt32 sceMpegRingbufferPut(sceMpegRingbuffer *pRB, SceInt32 iPackNum, SceInt32 iAvailable);
/**
 * sceMpegRingbufferAvailableSize 
 *
 * @param Ringbuffer - pointer to a sceMpegRingbuffer struct
 *
 * @return < 0 if error else number of free packets in the ringbuffer.
 */
SceInt32 sceMpegRingbufferAvailableSize( sceMpegRingbuffer *pRB);

// -------------- MPEG --------------- 

/**
 * sceMpegInit
 *
 * @return 0 if success.
 */
SceInt32 sceMpegInit(SceVoid);

/**
 * sceMpegFinish
 */
SceInt32 sceMpegFinish(SceVoid);

/**
 * sceMpegQueryMemSize
 *
 * SceInt32 iMpegMode 
 *
 * @return < 0 if error else decoder data size.
 */
SceInt32 sceMpegQueryMemSize(SceInt32 iMpegMode);

/**
 * sceMpegCreate
 *
 * mp - will be filled
 * @param pData - pointer to allocated memory of size = sceMpegQueryMemSize()
 * @param iSize - size of data, should be = sceMpegQueryMemSize()
 * @param Ringbuffer - a ringbuffer
 * @param iFrameWidth - display buffer width, set to 512 if writing to framebuffer
 * @param iMpegMode
 * @param pDDRTop -
 *
 * @return 0 if success.
 */
SceInt32 sceMpegCreate(sceMpeg * mp, SceUChar8 * work_area, SceInt32 size, sceMpegRingbuffer *pPSRB, SceInt32 iFrameWidth, SceInt32 iMpegMode, SceVoid *pDDRTop);

/**
 * sceMpegDelete
 *
 * mp - SceMpeg handle
 */
SceInt32 sceMpegDelete(sceMpeg *mp);

/**
 * sceMpegRegistStream
 *
 * @param mp - SceMpeg handle
 * @param iStreamType - stream id, 0 for video, 1 for audio
 * @param ch
 *
 * @return 0 if error.
 */
sceMpegStream *sceMpegRegistStream(sceMpeg *mp, sceMpegStrType iStreamType, SceInt32 ch);

/**
 * sceMpegUnRegistStream
 *
 * @param mp - SceMpeg handle
 * @param pStream - pointer to stream
 */
SceInt32 sceMpegUnRegistStream(sceMpeg *mp, sceMpegStream *pStream);

/**
 * sceMpegMallocAvcEsBuf
 *
 * @return 0 if error else pointer to buffer.
 */
sceMpegHandle sceMpegMallocAvcEsBuf(sceMpeg *mp);

/**
 * sceMpegFreeAvcEsBuf
 * 
 * @param mp - SceMpeg handle
 * @param tHandle sceMpegHandle
 */
SceInt32 sceMpegFreeAvcEsBuf(sceMpeg *mp, sceMpegHandle tHandle);

/**
 * sceMpegQueryAtracEsSize
 *
 * @param mp - SceMpeg handle
 * @param iEsSize - will contain size of Es
 * @param iOutSize - will contain size of decoded data
 *
 * @return 0 if success.
 */
SceInt32 sceMpegQueryAtracEsSize(sceMpeg *mp, SceInt32 *iEsSize, SceInt32 *iOutSize);

/**
 * sceMpegQueryPcmEsSize
 *
 * @param mp - SceMpeg handle
 * @param iEsSize - will contain size of Es
 * @param iOutSize - will contain size of decoded data
 *
 * @return 0 if success.
 */
SceInt32 sceMpegQueryPcmEsSize(sceMpeg *mp, SceInt32 *iEsSize, SceInt32 *iOutSize);

/**
 * sceMpegInitAu
 *
 * @param mp - SceMpeg handle
 * @param pEsBuffer - prevously allocated Es buffer
 * @param pAu - will contain pointer to Au
 *
 * @return 0 if success.
 */
SceInt32 sceMpegInitAu(sceMpeg *mp,sceMpegHandle hEsBuf,sceMpegAu *pAu);

typedef enum sceMpegAuMode_enum{
	PSP_MPEG_AU_MODE_NORMAL = 0,
	PSP_MPEG_AU_MODE_JUMP = 1
} sceMpegAuMode_enum;

typedef SceInt32 sceMpegAuMode;

SceInt32 sceMpegChangeGetAuMode(sceMpeg *mp,sceMpegStream *pStream,sceMpegAuMode iAuMode);
/**
 * sceMpegGetAvcAu
 *
 * @param mp - SceMpeg handle
 * @param pStream - associated stream
 * @param pAu - will contain pointer to Au
 * @param iAttr -
 *
 * @return 0 if success.
 */
SceInt32 sceMpegGetAvcAu(sceMpeg *mp,sceMpegStream *pStream,sceMpegAu *pAu,SceInt32 *iAttr);

/**
 * sceMpegGetAtracAu
 *
 * @param mp - SceMpeg handle
 * @param pStream - associated stream
 * @param pAu - will contain pointer to Au
 * @param pAtracBody - buffer containing atrac audio
 *
 * @return 0 if success.
 */
SceInt32 sceMpegGetAtracAu(sceMpeg *mp,sceMpegStream *pStream,sceMpegAu *pAu,SceVoid **pAtracBody);

/**
 * sceMpegGetPcmAu
 *
 * @param mp - SceMpeg handle
 * @param pStream - associated stream
 * @param pAu - will contain pointer to Au
 * @param iAttr -
 *
 * @return 0 if success.
 */
SceInt32 sceMpegGetPcmAu(sceMpeg *mp,sceMpegStream *pStream,sceMpegAu *pAu,SceInt32 *iAttr);

/**
 * sceMpegFlushAllStreams
 *
 * @return 0 if success.
 */
SceInt32 sceMpegFlushAllStream(sceMpeg *mp);
/**
 * sceMpegUnRegistStream
 *
 * @param mp - SceMpeg handle
 * @param pStream - pointer to stream
 */
SceInt32 sceMpegFlushStream(sceMpeg *mp,sceMpegStream *pStream);


//-------------AVC----------------
/**
 * sceMpegAvcDecode
 *
 * @param mp - SceMpeg handle
 * @param pAu - video Au
 * @param iFrameWidth - output buffer width, set to 512 if writing to framebuffer
 * @param pBuffer - buffer that will contain the decoded frame
 * @param iInit - will be set to 0 on first call, then 1
 *
 * @return 0 if success.
 */
SceInt32 sceMpegAvcDecode(sceMpeg *mp,sceMpegAu *pAu,SceInt32 iFrameWidth,SceUChar8 *pRGBA[],SceInt32 *iNum);

typedef enum sceMpeg_SAVD_RESULT{
	PSP_MPEG_ERROR_AVC_FATAL = -8,
	PSP_MPEG_ERROR_AVC_SYNTAX,
	PSP_MPEG_ERROR_AVC_ADDR,
	PSP_MPEG_ERROR_AVC_SIZE,
	PSP_MPEG_ERROR_AVC_LIB,
	PSP_MPEG_ERROR_AVC_CABAC,
	PSP_MPEG_AVC_OK = 1
} sceMpeg_SAVD_RESULT;

typedef struct sceMpegAvcDecodeDetailInfo{
	SceInt32	iDecodeResult;
	SceUInt32	uiRecoveryPoint;
	SceUInt32	uiHorizontalSize;
	SceUInt32	uiVerticalSize;
	SceUInt32	uiFrameCropLeftOffset;
	SceUInt32	uiFrameCropRightOffset;
	SceUInt32	uiFrameCropTopOffset;
	SceUInt32	uiFrameCropBottomOffset;
	SceUInt32	uiDisplayFrameNum;
} sceMpegAvcDecodeDetailInfo;

SceInt32 sceMpegAvcDecodeDetail(sceMpeg *mp,sceMpegAvcDecodeDetailInfo *pDetail);
SceInt32 sceMpegAvcDecodeFlush(sceMpeg *mp);
/**
 * sceMpegAvcDecodeStop
 *
 * mp - SceMpeg handle
 * @param iFrameWidth - output buffer width, set to 512 if writing to framebuffer
 * @param pBuffer - buffer that will contain the decoded frame
 * @param iStatus - frame number
 *
 * @return 0 if success.
 */
SceInt32 sceMpegAvcDecodeStop(sceMpeg *mp,SceInt32 iFrameWidth,SceUChar8 *pRGBA[],SceInt32 *iNum);

#define	PSP_MPEG_AVC_DEC_NO_CHANGE  		(-1)

typedef enum PSP_MPEG_AVC_PIXEL_FORMAT{
	PSP_MPEG_AVC_PIXEL_NO_CHANGE	= -1,
	PSP_MPEG_AVC_PIXEL_RGB565		= 0,
	PSP_MPEG_AVC_PIXEL_RGBA5551		= 1,
	PSP_MPEG_AVC_PIXEL_RGBA4444		= 2,
	PSP_MPEG_AVC_PIXEL_RGBA8888		= 3
} PSP_MPEG_AVC_PIXEL_FORMAT;

#define PSP_MPEG_AVC_YCBCR_EXTERNAL 	(1)
#define PSP_MPEG_AVC_YCBCR_INTERNAL		(2)

typedef struct sceMpegAvcMode{
	SceInt32	iDecodeMode;
	SceInt32	iPixelFormat;
} sceMpegAvcMode;

/**
 * sceMpegAvcDecodeMode
 *
 * mp - SceMpeg handle
 * @param pMode - pointer to SceMpegAvcMode struct defining the decode mode (pixelformat)
 * @return 0 if success.
 */
SceInt32 sceMpegAvcDecodeMode(sceMpeg *mp,sceMpegAvcMode *pMode);
/**
 * sceMpegAtracDecode
 *
 * mp - SceMpeg handle
 * @param pAu - video Au
 * @param pBuffer - buffer that will contain the decoded frame
 * @param iInit - set this to 1 on first call
 *
 * @return 0 if success.
 */
SceInt32 sceMpegAtracDecode(sceMpeg *mp,sceMpegAu *pAu,SceUChar8 *pPcmData,SceInt32 iInitFlag);


typedef struct sceMpegAvcYCbCrRange{
	SceUInt32 uiStartWidth;
	SceUInt32 uiStartHeight;
	SceUInt32 uiLenWidth;
	SceUInt32 uiLenHeight;
} sceMpegAvcYCbCrRange;

SceInt32 sceMpegAvcQueryYCbCrSize(sceMpeg *mp,SceInt32 iYCbCrMode,SceInt32 iYCbCrWidth,SceInt32 iYCbCrHeight,SceInt32 *iAvcYCbCrSize);
SceInt32 sceMpegAvcInitYCbCr(sceMpeg *mp,SceInt32 iYCbCrMode,SceInt32 iYCbCrWidth,SceInt32 iYCbCrHeight,SceUChar8 *pAvcYCbCr);
SceInt32 sceMpegAvcDecodeYCbCr(sceMpeg *mp,sceMpegAu *pAu,SceUChar8 *pAvcYCbCr[],SceInt32 *iNum);
SceInt32 sceMpegAvcDecodeStopYCbCr(sceMpeg *mp,SceUChar8 *pAvcYCbCr[],SceInt32 *iNum);
SceInt32 sceMpegAvcCsc(sceMpeg *mp,SceUChar8 *pAvcYCbCr,sceMpegAvcYCbCrRange *pRange,SceInt32 iFrameWidth,SceUChar8 *pRGBA);

#ifdef __cplusplus
}
#endif

#endif

