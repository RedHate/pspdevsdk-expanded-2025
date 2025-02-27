/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsas.h - Prototypes for the libsas
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBSAS_H__
#define __LIBSAS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define	PSP_SAS_VOICE_MAX				(32)
#define PSP_SAS_GRAIN_SAMPLES			(256)
#define	PSP_SAS_VOLUME_MAX				(0x1000)
#define	PSP_SAS_FX_VOLUME_MAX			(PSP_SAS_VOLUME_MAX)

#define	PSP_SAS_LOOP_DISABLE			(0)
#define	PSP_SAS_LOOP_ENABLE				(1)

#define	PSP_SAS_PITCH_MIN				(1)
#define	PSP_SAS_PITCH_MAX				(0x4000)
#define	PSP_SAS_PITCH_BASE				(0x1000)
#define	PSP_SAS_NOISE_CLOCK_MAX			(0x3f)

#define	PSP_SAS_ENVELOPE_HEIGHT_MAX		(0x40000000)
#define	PSP_SAS_ENVELOPE_RATE_MAX		(0x7fffffff)

#define	PSP_SAS_ADSR_MODE_LINEAR_INC	(0)
#define	PSP_SAS_ADSR_MODE_LINEAR_DEC	(1)
#define	PSP_SAS_ADSR_MODE_BENT_LINEAR	(2)
#define	PSP_SAS_ADSR_MODE_REVEXPONENT	(3)
#define	PSP_SAS_ADSR_MODE_EXPONENT		(4)
#define	PSP_SAS_ADSR_MODE_DIRECT		(5)

#define	PSP_SAS_ATTACK_VALID			(1)
#define	PSP_SAS_DECAY_VALID				(2)
#define	PSP_SAS_SUSTAIN_VALID			(4)
#define	PSP_SAS_RELEASE_VALID			(8)

#define	PSP_SAS_FX_TYPE_OFF				(-1)
#define	PSP_SAS_FX_TYPE_ROOM			(0)
#define	PSP_SAS_FX_TYPE_STUDIOA			(1)
#define	PSP_SAS_FX_TYPE_STUDIOB			(2)
#define	PSP_SAS_FX_TYPE_STUDIOC			(3)
#define	PSP_SAS_FX_TYPE_HALL			(4)
#define	PSP_SAS_FX_TYPE_SPACE			(5)
#define	PSP_SAS_FX_TYPE_ECHO			(6)
#define	PSP_SAS_FX_TYPE_DELAY			(7)
#define	PSP_SAS_FX_TYPE_PIPE			(8)

#define	PSP_SAS_ERROR_ADDRESS			(0x80420005)
#define	PSP_SAS_ERROR_VOICE_INDEX		(0x80420010)
#define	PSP_SAS_ERROR_NOISE_CLOCK		(0x80420011)
#define	PSP_SAS_ERROR_PITCH_VAL			(0x80420012)
#define	PSP_SAS_ERROR_ADSR_MODE			(0x80420013)
#define	PSP_SAS_ERROR_ADPCM_SIZE		(0x80420014)
#define	PSP_SAS_ERROR_LOOP_MODE			(0x80420015)
#define	PSP_SAS_ERROR_INVALID_STATE		(0x80420016)
#define	PSP_SAS_ERROR_VOLUME_VAL		(0x80420018)
#define	PSP_SAS_ERROR_ADSR_VAL			(0x80420019)

#define	PSP_SAS_ERROR_FX_TYPE			(0x80420020)
#define	PSP_SAS_ERROR_FX_FEEDBACK		(0x80420021)
#define	PSP_SAS_ERROR_FX_DELAY			(0x80420022)
#define	PSP_SAS_ERROR_FX_VOLUME_VAL		(0x80420023)

#define	PSP_SAS_ERROR_BUSY              (0x80420030)
#define	PSP_SAS_ERROR_NOTINIT			(0x80420100)
#define	PSP_SAS_ERROR_ALRDYINIT			(0x80420101)


int sceSasInit(void);
int sceSasExit(void);
int sceSasCore(short *pOut);
int sceSasSetKeyOn(int iVoiceNum);
int sceSasSetKeyOff(int iVoiceNum);
int sceSasSetVolume(int iVoiceNum, int l, int r, int wl, int wr);
int sceSasSetPitch(int iVoiceNum, int pitch);
int sceSasSetVoice(int iVoiceNum,unsigned char *vagBuf,SceSize size,int loopflag);
int sceSasSetNoise(int iVoiceNum, unsigned int uClk);
int sceSasSetADSR(int iVoiceNum, int flag, SceUInt32 a, SceUInt32 d, SceUInt32 s, SceUInt32 r);
int sceSasSetADSRmode(int iVoiceNum, int flag, int a, int d, int s, int r);
int sceSasSetSL(int iVoiceNum, SceInt32 sl);
int sceSasSetSimpleADSR(int iVoiceNum, int ADSR1, int ADSR2);
SceUInt32 sceSasGetEndFlag(void);
SceInt32 sceSasGetEnvelope(int voice);
int sceSasSetEffect(int dry_sw, int wet_sw);
int sceSasSetEffectVolume(int val_l, int val_r);
int sceSasSetEffectType(int type);
int sceSasSetEffectParam(unsigned int dt, unsigned int fb);

#ifdef __cplusplus
}
#endif

#endif
