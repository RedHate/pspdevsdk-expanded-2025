/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * psppsmf.h - Prototypes for the libpsmf
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBMT19937_H__
#define __LIBMT19937_H__

#ifdef __cplusplus
extern "C" {
#endif

#define SCE_MPEG_ERROR_PSMF_NOT_INITIALIZED     0x80615001
#define SCE_MPEG_ERROR_PSMF_UNMATCHED_VERSION   0x80615002
#define SCE_MPEG_ERROR_PSMF_NOT_FOUND           0x80615025
#define SCE_MPEG_ERROR_PSMF_INVALID_ID          0x80615100
#define SCE_MPEG_ERROR_PSMF_INVALID_VALUE       0x806151FE
#define SCE_MPEG_ERROR_PSMF_INVALID_TIMESTAMP   0x80615500
#define SCE_MPEG_ERROR_PSMF_INVALID_PSMF        0x80615501

typedef struct scePsmf {
	SceInt32  type;
	SceInt32  groupingPeriodId;
	SceInt32  groupId;
	SceInt32  streamNumber;
	SceVoid   *header;
	SceVoid   *sequenceInfo;
	SceVoid   *currentGroupingPeriod;
	SceVoid   *currentGroup;
	SceVoid   *currentStream;
	SceVoid   *currentEPmap;
} scePsmf;

typedef struct scePsmfVideoInfo {
	SceInt32 horizontalSize;
	SceInt32 verticalSize;
} scePsmfVideoInfo;

typedef struct scePsmfAudioInfo {
	SceInt32 channelConfiguration;
	SceInt32 samplingFrequency;
} scePsmfAudioInfo;

typedef struct scePsmfEntryPoint {
	SceUInt32 pts;
	SceUInt32 offset;
} scePsmfEntryPoint;

SceInt32 scePsmfSetPsmf(scePsmf *psmf, SceVoid* addr);
SceInt32 scePsmfGetCurrentStreamType(scePsmf *psmf, SceMpegStrType* type, SceInt32* ch);
SceInt32 scePsmfGetCurrentStreamNumber(scePsmf *psmf);
SceInt32 scePsmfSpecifyStreamWithStreamType(scePsmf *psmf, SceMpegStrType type, SceInt32 ch);
SceInt32 scePsmfSpecifyStream(scePsmf *psmf, SceInt32 streamNumber);
SceInt32 scePsmfSpecifyStreamWithStreamTypeNumber(scePsmf* psmf, SceMpegStrType streamType, SceInt32 streamTypeNumber);
SceInt32 scePsmfGetPresentationStartTime(scePsmf *psmf, SceUInt32* start_time);
SceInt32 scePsmfGetPresentationEndTime(scePsmf *psmf, SceUInt32* end_time);
SceInt32 scePsmfGetNumberOfStreams(scePsmf *psmf);
SceInt32 scePsmfGetNumberOfSpecificStreams (scePsmf* psmf, SceMpegStrType streamType);
SceInt32 scePsmfGetVideoInfo(scePsmf* psmf, scePsmfVideoInfo* pVideoInfo);
SceInt32 scePsmfGetAudioInfo (scePsmf* psmf, scePsmfAudioInfo* pAudioInfo);
SceInt32 scePsmfGetNumberOfEPentries (scePsmf *psmf);
SceInt32 scePsmfCheckEPmap(scePsmf *psmf);
SceInt32 scePsmfGetEPWithId(scePsmf *psmf, SceInt32 epId, scePsmfEntryPoint* pEntry);
SceInt32 scePsmfGetEPWithTimestamp(scePsmf *psmf, SceUInt32 timestamp, scePsmfEntryPoint* pEntry);
SceInt32 scePsmfGetEPidWithTimestamp(scePsmf *psmf, SceUInt32 timestamp);
SceInt32 scePsmfQueryStreamSize (const SceVoid* addr, SceUInt32* stream_size);
SceInt32 scePsmfQueryStreamOffset (const SceVoid* addr, SceUInt32* offset);

#ifdef __cplusplus
}
#endif

#endif
