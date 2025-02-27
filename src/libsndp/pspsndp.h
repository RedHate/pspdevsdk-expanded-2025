/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsndp.h - Prototypes for the libsndp sound library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBSSNDP_H__
#define __LIBSSNDP_H__

#include <pspkerneltypes.h>
#include <psptypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PSP_SNDP_ERROR_NOTINIT           (0x80450001)
#define PSP_SNDP_ERROR_PHDID             (0x80450002)
#define PSP_SNDP_ERROR_SMF               (0x80450003)
#define PSP_SNDP_ERROR_SMFCTX            (0x80540004)
#define PSP_SNDP_ERROR_FORMAT            (0x80540005)
#define PSP_SNDP_ERROR_SMFFULL           (0x80540006)
#define PSP_SNDP_ERROR_SMFID             (0x80540007)
#define PSP_SNDP_ERROR_PLAYCOUNT         (0x80540008)
#define PSP_SNDP_ERROR_NOTREADY          (0x80540009)
#define PSP_SNDP_ERROR_PARAM             (0x8054000a)
#define PSP_SNDP_ERROR_NOTPLAY           (0x8054000b)
#define PSP_SNDP_ERROR_NOTPAUSE          (0x8054000c)
#define PSP_SNDP_ERROR_DONTSTOP          (0x8054000d)
#define PSP_SNDP_ERROR_ALREADY           (0x8054000e)
#define PSP_SNDP_ERROR_SOUNDDATAFULL     (0x8054000f)
#define PSP_SNDP_ERROR_CANTALLOCATEVOICE (0x80540010)
#define PSP_SNDP_ERROR_VOICENUM          (0x80540011)
#define PSP_SNDP_ERROR_RESERVEDVOICE     (0x80540012)

#define PSP_SNDP_OFF                          (0)
#define PSP_SNDP_ON                           (1)
#define PSP_SNDP_INFINITY                     (0xffffffff)

#define PSP_SNDP_VOICESTATUS_RESERVED         (0)
#define PSP_SNDP_VOICESTATUS_IDLE             (1)
#define PSP_SNDP_VOICESTATUS_NOTEON           (2)
#define PSP_SNDP_VOICESTATUS_BUSY             (3)
#define PSP_SNDP_VOICESTATUS_NOTEOFF          (4)
#define PSP_SNDP_VOICESTATUS_RELEASE          (5)
#define PSP_SNDP_VOICESTATUS_CONTINUE         (6)
#define PSP_SNDP_VOICESTATUS_SUSTAIN          (7)
#define PSP_SNDP_VOICESTATUS_NOTEOFFSUSTAIN   (8)
#define PSP_SNDP_VOICESTATUS_NOTEONSUSTAIN    (9)

#define PSP_SNDP_PLAYSTATUS_READY             (0)
#define PSP_SNDP_PLAYSTATUS_PLAY              (1)
#define PSP_SNDP_PLAYSTATUS_STOP              (2)
#define PSP_SNDP_PLAYSTATUS_ERROR             (3)

#define PSP_SNDP_FX_PARAM_ALL                 (0xffffffff)
#define PSP_SNDP_FX_PARAM_TYPE                (1 << 0)
#define PSP_SNDP_FX_PARAM_PARAM               (1 << 1)
#define PSP_SNDP_FX_PARAM_EFFECTVOLUME        (1 << 2)
#define PSP_SNDP_FX_PARAM_SWITCH              (1 << 3)

#define PSP_SNDP_FX_TYPE_OFF                  (-1)
#define PSP_SNDP_FX_TYPE_ROOM                 (0)
#define PSP_SNDP_FX_TYPE_STUDIOA              (1)
#define PSP_SNDP_FX_TYPE_STUDIOB              (2)
#define PSP_SNDP_FX_TYPE_STUDIOC              (3)
#define PSP_SNDP_FX_TYPE_HALL                 (4)
#define PSP_SNDP_FX_TYPE_SPACE                (5)
#define PSP_SNDP_FX_TYPE_ECHO                 (6)
#define PSP_SNDP_FX_TYPE_DELAY                (7)
#define PSP_SNDP_FX_TYPE_PIPE                 (8)

#define PSP_SNDP_SNDP_CTX_SIZE                (8)
#define PSP_SNDP_SMF_CTX_SIZE                 (320)

/*J sndp */
typedef struct{
	char   system[PSP_SNDP_SNDP_CTX_SIZE];
} sceSsSndpCtx;

/*J smf */
typedef struct{
	char   system[PSP_SNDP_SMF_CTX_SIZE];
} sceSsSmfCtx;

typedef struct {
	unsigned char   vel;
	unsigned char   pan;
	unsigned char   sendVel;
	unsigned char   sendPan;
	int             addPitch;
} sceSsKeyOnParam;

typedef struct{
	unsigned int   setMask;
	unsigned int   type;
	unsigned int   delayTime;
	unsigned int   feedBack;
	unsigned int   effectVolume_l;
	unsigned int   effectVolume_r;
	unsigned int   drySwitch;
	unsigned int   wetSwitch;
} sceSsEffectParam;

SceUShort16 sceSsNote2Pitch(SceUShort16 center_note, SceUShort16 center_fine, SceUShort16 note, SceShort16 fine);
SceUShort16 sceSsPitch2Note(SceUShort16 center_note, SceUShort16 center_fine, SceUShort16 pitch);

SceInt32 sceSsSynthesis(short *pOut);
SceInt32 sceSsVoiceSetReserveMode(SceUInt32 voiceNum, SceUInt32 reserveMode);

SceInt32 sceSsBindSoundData(sceSsSndpCtx *sndpCtx, void *phd, void*pbd);
SceInt32 sceSsUnbindSoundData(SceUInt32 phdID);

SceInt32 sceSsNoteOnByTone(SceUInt32 phdID, SceUInt32 toneIndex, SceUInt32 note, SceUInt32 keyOnID, sceSsKeyOnParam *keyOnParam);
SceInt32 sceSsKeyOnByTone(SceUInt32 phdID, SceUInt32 toneIndex, SceUInt32 pitch, SceUInt32 keyOnID, sceSsKeyOnParam *keyParam);

SceInt32 sceSsVoiceNoteOnByTone(SceUInt32 phdID, SceUInt32 voiceNum, SceUInt32 toneIndex, SceUInt32 note, SceUInt32 keyOnID, sceSsKeyOnParam *keyParam);
SceInt32 sceSsVoiceKeyOnByTone(SceUInt32 phdID, SceUInt32 voiceNum, SceUInt32 toneIndex, SceUInt32 pitch, SceUInt32 keyOnID, sceSsKeyOnParam *keyParam);
SceInt32 sceSsVoiceSetSustainHold(SceUInt32 voiceNum, SceUInt32 sustainHold);
SceInt32 sceSsVoiceKeyoff(SceUInt32 voiceNum);
SceInt32 sceSsVoiceSetPitch(SceUInt32 voiceNum, SceInt32 addPitch);
SceInt32 sceSsVoiceSetVelocity(SceUInt32 voiceNum, SceUInt32 velocity);
SceInt32 sceSsVoiceSetPanpot(SceUInt32 voiceNum, SceUInt32 panpot);
SceInt32 sceSsVoiceSetPitchBend(SceUInt32 voiceNum, SceUInt32 bendValue);
SceInt32 sceSsVoiceSetSendVelocity(SceUInt32 voiceNum, SceUInt32 sendVelocity);
SceInt32 sceSsVoiceSetSendPanpot(SceUInt32 voiceNum, SceUInt32 sendPanpot);
SceInt32 sceSsVoiceAllKeyOff(void);
SceInt32 sceSsVoiceGetEndFlag(SceUInt32 voiceNum);
SceInt32 sceSsVoiceGetEnvelope(SceUInt32 voiceNum);
SceInt32 sceSsVoiceGetStatus(SceUInt32 voiceNum);

SceUInt32 sceSsKeyOffByID(SceUInt32 ID);
SceUInt32 sceSsGetVoice(SceUInt32 midiChannel, SceUInt32 ID);

SceUInt32 sceSsNoteOn(SceUInt32 phdID, SceUInt32 midiChannel, SceUInt32 midiProgram, SceUInt32 midiNote, SceUInt32 sustain, sceSsKeyOnParam *keyOnParam, SceUInt32 keyOnID);
SceUInt32 sceSsNoteOff(SceUInt32 midiChannel, SceUInt32 midiNote, SceUInt32 ID);

SceUInt32 sceSsSetSustainHold(SceUInt32 midiChannel, SceUInt32 sustainHold, SceUInt32 ID);

SceInt32 sceSsSetEffectParam(sceSsEffectParam *effectParam);

SceInt32 sceSsInit(SceUInt32 maxVoice);
SceInt32 sceSsExit(void);

/* SMF */
SceInt32 sceSsSMFBind(sceSsSmfCtx *smfCtx, void *smf, SceUInt32 phdID);
SceInt32 sceSsSMFUnbind(SceUInt32 smfID);
SceInt32 sceSsSMFPlay(SceUInt32 smfID, SceUInt32 playVelocity, SceUInt32 playPan, SceUInt32 playSendVelocity, SceUInt32 playSendPan, SceUInt32 playCount);
SceInt32 sceSsSMFPause(SceUInt32 smfID);
SceInt32 sceSsSMFResume(SceUInt32 smfID);
SceInt32 sceSsSMFStop(SceUInt32 smfID);
SceInt32 sceSsSMFAddTempo(SceUInt32 smfID, SceInt32 addTempo);
SceInt32 sceSsSMFGetTempo(SceUInt32 smfID);
SceInt32 sceSsSMFSetPlayVelocity(SceUInt32 smfID, SceUInt32 playVelocity);
SceInt32 sceSsSMFGetPlayVelocity(SceUInt32 smfID);
SceInt32 sceSsSMFSetPlaySendVelocity(SceUInt32 smfID, SceUInt32 playSendVelocity);
SceInt32 sceSsSMFGetPlaySendVelocity(SceUInt32 smfID);
SceInt32 sceSsSMFSetPlayPanpot(SceUInt32 smfID, SceUInt32 playPanpot);
SceInt32 sceSsSMFGetPlayPanpot(SceUInt32 smfID);
SceInt32 sceSsSMFSetPlaySendPanpot(SceUInt32 smfID, SceUInt32 playSendPanpot);
SceInt32 sceSsSMFGetPlaySendPanpot(SceUInt32 smfID);
SceInt32 sceSsSMFGetPlayStatus(SceUInt32 smfID);
SceInt32 sceSsSMFSetChannelMute(SceUInt32 smfID, SceUInt32 midiChannel);
SceInt32 sceSsSMFResetChannelMute(SceUInt32 smfID);
SceInt32 sceSsSMFSetPlayChannel(SceUInt32 smfID, SceUInt32 playChannelBit);
SceInt32 sceSsSMFGetPlayChannel(SceUInt32 smfID, SceUInt32 *playChannelBit);

#ifdef __cplusplus
}
#endif

#endi
