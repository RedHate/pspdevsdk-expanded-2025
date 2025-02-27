/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspwave.h - Prototypes for the libwave - VAG & PCM output library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBWAVE_H__
#define __LIBWAVE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define	PSP_WAVE_VOICE_MAX				(8)
#define	PSP_WAVE_LOOP					(1 << 0)
#define	PSP_WAVE_VAGFLAG				(1 << 1)
#define	PSP_WAVE_VOL_MAX				(127)
#define	PSP_WAVE_DET_VOL_MAX			(4096)

#define	PSP_WAVE_AUDIO_CH_MAX			(3)
#define	PSP_WAVE_AUDIO_SMPL_MIN			(64)
#define	PSP_WAVE_AUDIO_SMPL_MAX			(65536 - PSP_WAVE_AUDIO_SMPL_MIN)
#define	PSP_WAVE_AUDIO_VOL_MAX			(0x8000)
#define	PSP_WAVE_AUDIO_FMT_S16_STEREO	(0x0000)
#define	PSP_WAVE_AUDIO_FMT_S16_MONO		(0x0010)

#define	PSP_WAVE_STAT_STOP				(0)
#define	PSP_WAVE_STAT_PLAY				(1)

#define	PSP_WAVE_ERROR_INITFAIL			(0x80440001)
#define	PSP_WAVE_ERROR_EXITFAIL			(0x80440002)
#define	PSP_WAVE_ERROR_STARTFAIL		(0x80440003)
#define	PSP_WAVE_ERROR_ENDFAIL			(0x80440004)
#define	PSP_WAVE_ERROR_VOICENUM			(0x80440005)
#define	PSP_WAVE_ERROR_BUFFPTR			(0x80440006)
#define	PSP_WAVE_ERROR_SIZE				(0x80440007)
#define	PSP_WAVE_ERROR_MODE				(0x80440008)
#define	PSP_WAVE_ERROR_VOICEPLAY		(0x80440009)
#define	PSP_WAVE_ERROR_VOL				(0x8044000A)
#define	PSP_WAVE_ERROR_VOLPTR			(0x8044000B)
#define	PSP_WAVE_ERROR_RESTPTR			(0x8044000C)
#define	PSP_WAVE_ERROR_LOOPMODE			(0x8044000D)
#define	PSP_WAVE_ERROR_AUDIOCH			(0x80440010)
#define	PSP_WAVE_ERROR_SAMPLE			(0x80440011)
#define	PSP_WAVE_ERROR_THPRIORITY		(0x80440012)

#define	PSP_AUDIO_ERROR_NOT_INITIALIZED	(0x80260001)
#define	PSP_AUDIO_ERROR_OUTPUT_BUSY		(0x80260002)
#define	PSP_AUDIO_ERROR_INVALID_CH		(0x80260003)
#define	PSP_AUDIO_ERROR_PRIV_REQUIRED	(0x80260004)
#define	PSP_AUDIO_ERROR_NOT_FOUND		(0x80260005)
#define	PSP_AUDIO_ERROR_INVALID_SIZE	(0x80260006)
#define	PSP_AUDIO_ERROR_INVALID_FORMAT	(0x80260007)
#define	PSP_AUDIO_ERROR_NOT_RESERVED	(0x80260008)
#define	PSP_AUDIO_ERROR_NOT_OUTPUT		(0x80260009)

extern int sceWaveInit(void);
extern int sceWaveExit(void);

extern int sceWaveStart(int iPri);
extern int sceWaveEnd(void);
extern int sceWaveSetVoice(int iVoice,char* pBuf,int iSize,int iMode);
extern int sceWaveSetVolume(int iVoice,int iVolL,int iVolR);
extern int sceWaveGetVolume(int iVoice,int* iVolL,int* iVolR);
extern int sceWaveSetVolumeEx(int iVoice,int iVolL,int iVolR);
extern int sceWaveGetVolumeEx(int iVoice,int* iVolL,int* iVolR);
extern int sceWaveSetLoopMode(int iVoice,int iMode);
extern int sceWaveGetRestByte(int iVoice,int* iRestByte);
extern int sceWaveGetStat(int iVoice);
extern int sceWavePlay(int iVoice,int iVolL,int iVolR);
extern int sceWavePlayEx(int iVoice,int iVolL,int iVolR);
extern int sceWaveStop(int iVoice);
extern int sceWavePause(int iVoice);
extern int sceWaveReplay(int iVoice);
extern void sceWaveAllStop(void);

extern int sceWaveAudioSetSample(int iCh,int iSampleNum);
extern int sceWaveAudioSetVolume(int iCh,int iVolL,int iVolR);
extern int sceWaveAudioSetFormat(int iCh,int iId);
extern int sceWaveAudioGetRestSample(int iCh);
extern int sceWaveAudioWrite(int iCh,int iVolL,int iVolR,void* pBuf);
extern int sceWaveAudioWriteBlocking(int iCh,int iVolL,int iVolR,void* pBuf);

#ifdef __cplusplus
}
#endif

#endi
