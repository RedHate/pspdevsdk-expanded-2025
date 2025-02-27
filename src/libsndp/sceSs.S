	.set noreorder

#include "pspimport.s"

#ifdef F_sceSs_0000
	IMPORT_START "sceSs", 0x00010011
#endif
#ifdef F_sceSs_0001
	IMPORT_FUNC  "sceSs", 0xE22D097E, sceSsNote2Pitch
#endif
#ifdef F_sceSs_0002
	IMPORT_FUNC  "sceSs", 0x9996ED44, sceSsPitch2Note
#endif
#ifdef F_sceSs_0003
	IMPORT_FUNC  "sceSs", 0xB6929CA1, sceSsSynthesis
#endif
#ifdef F_sceSs_0004
	IMPORT_FUNC  "sceSs", 0x5BA2B0B2, sceSsVoiceSetReserveMode
#endif
#ifdef F_sceSs_0005
	IMPORT_FUNC  "sceSs", 0xD6AE1814, sceSsBindSoundData
#endif
#ifdef F_sceSs_0006
	IMPORT_FUNC  "sceSs", 0x76E03F23, sceSsUnbindSoundData
#endif
#ifdef F_sceSs_0007
	IMPORT_FUNC  "sceSs", 0x4FAC7083, sceSsNoteOnByTone
#endif
#ifdef F_sceSs_0008
	IMPORT_FUNC  "sceSs", 0x4D8A8695, sceSsKeyOnByTone
#endif
#ifdef F_sceSs_0009
	IMPORT_FUNC  "sceSs", 0x8B181546, sceSsVoiceNoteOnByTone
#endif
#ifdef F_sceSs_0010
	IMPORT_FUNC  "sceSs", 0x3024A6D4, sceSsVoiceKeyOnByTone
#endif
#ifdef F_sceSs_0011
	IMPORT_FUNC  "sceSs", 0xBDCCFB4E, sceSsVoiceSetSustainHold
#endif
#ifdef F_sceSs_0012
	IMPORT_FUNC  "sceSs", 0x9C05B459, sceSsVoiceKeyoff
#endif
#ifdef F_sceSs_0013
	IMPORT_FUNC  "sceSs", 0xB062267E, sceSsVoiceSetPitch
#endif
#ifdef F_sceSs_0014
	IMPORT_FUNC  "sceSs", 0x2C0C519F, sceSsVoiceSetVelocity
#endif
#ifdef F_sceSs_0015
	IMPORT_FUNC  "sceSs", 0x5BC20482, sceSsVoiceSetPanpot
#endif
#ifdef F_sceSs_0016
	IMPORT_FUNC  "sceSs", 0x608A01FF, sceSsVoiceSetPitchBend
#endif
#ifdef F_sceSs_0017
	IMPORT_FUNC  "sceSs", 0x41C61F33, sceSsVoiceSetSendVelocity
#endif
#ifdef F_sceSs_0018
	IMPORT_FUNC  "sceSs", 0x79528B67, sceSsVoiceSetSendPanpot
#endif
#ifdef F_sceSs_0019
	IMPORT_FUNC  "sceSs", 0x53406CA8, sceSsVoiceAllKeyOff
#endif
#ifdef F_sceSs_0020
	IMPORT_FUNC  "sceSs", 0x832B0279, sceSsVoiceGetEndFlag
#endif
#ifdef F_sceSs_0021
	IMPORT_FUNC  "sceSs", 0x43882DDA, sceSsVoiceGetEnvelope
#endif
#ifdef F_sceSs_0022
	IMPORT_FUNC  "sceSs", 0xB50FC77A, sceSsVoiceGetStatus
#endif
#ifdef F_sceSs_0023
	IMPORT_FUNC  "sceSs", 0x3E69411E, sceSsKeyOffByID
#endif
#ifdef F_sceSs_0024
	IMPORT_FUNC  "sceSs", 0x5FA08DBB, sceSsGetVoice
#endif
#ifdef F_sceSs_0025
	IMPORT_FUNC  "sceSs", 0xE64415BC, sceSsNoteOn
#endif
#ifdef F_sceSs_0026
	IMPORT_FUNC  "sceSs", 0xFF84003F, sceSsNoteOff
#endif
#ifdef F_sceSs_0027
	IMPORT_FUNC  "sceSs", 0xE5474F2B, sceSsSetSustainHold
#endif
#ifdef F_sceSs_0028
	IMPORT_FUNC  "sceSs", 0x99A7451C, sceSsSetEffectParam
#endif
#ifdef F_sceSs_0029
	IMPORT_FUNC  "sceSs", 0xDCB06292, sceSsInit
#endif
#ifdef F_sceSs_0030
	IMPORT_FUNC  "sceSs", 0x0FAD741F, sceSsExit
#endif
#ifdef F_sceSs_0031
	IMPORT_FUNC  "sceSs", 0x9727B582, sceSsSMFBind
#endif
#ifdef F_sceSs_0032
	IMPORT_FUNC  "sceSs", 0x7FBA2643, sceSsSMFUnbind
#endif
#ifdef F_sceSs_0033
	IMPORT_FUNC  "sceSs", 0x57971273, sceSsSMFPlay
#endif
#ifdef F_sceSs_0034
	IMPORT_FUNC  "sceSs", 0x0D3D5C43, sceSsSMFPause
#endif
#ifdef F_sceSs_0035
	IMPORT_FUNC  "sceSs", 0x2280713F, sceSsSMFResume
#endif
#ifdef F_sceSs_0036
	IMPORT_FUNC  "sceSs", 0xCA187ED1, sceSsSMFStop
#endif
#ifdef F_sceSs_0037
	IMPORT_FUNC  "sceSs", 0xA6838301, sceSsSMFAddTempo
#endif
#ifdef F_sceSs_0038
	IMPORT_FUNC  "sceSs", 0x70DAA2E6, sceSsSMFGetTempo
#endif
#ifdef F_sceSs_0039
	IMPORT_FUNC  "sceSs", 0xF27648CA, sceSsSMFSetPlayVelocity
#endif
#ifdef F_sceSs_0040
	IMPORT_FUNC  "sceSs", 0xC20D62A0, sceSsSMFGetPlayVelocity
#endif
#ifdef F_sceSs_0041
	IMPORT_FUNC  "sceSs", 0xCF95D397, sceSsSMFSetPlaySendVelocity
#endif
#ifdef F_sceSs_0042
	IMPORT_FUNC  "sceSs", 0x13604291, sceSsSMFGetPlaySendVelocity
#endif
#ifdef F_sceSs_0043
	IMPORT_FUNC  "sceSs", 0x69987274, sceSsSMFSetPlayPanpot
#endif
#ifdef F_sceSs_0044
	IMPORT_FUNC  "sceSs", 0xA1962775, sceSsSMFGetPlayPanpot
#endif
#ifdef F_sceSs_0045
	IMPORT_FUNC  "sceSs", 0xDBA3C87A, sceSsSMFSetPlaySendPanpot
#endif
#ifdef F_sceSs_0046
	IMPORT_FUNC  "sceSs", 0x5DB3B3A6, sceSsSMFGetPlaySendPanpot
#endif
#ifdef F_sceSs_0047
	IMPORT_FUNC  "sceSs", 0x27D1BA8F, sceSsSMFGetPlayStatus
#endif
#ifdef F_sceSs_0048
	IMPORT_FUNC  "sceSs", 0x5BB2B0AF, sceSsSMFSetChannelMute
#endif
#ifdef F_sceSs_0049
	IMPORT_FUNC  "sceSs", 0x9858FBA9, sceSsSMFResetChannelMute
#endif
#ifdef F_sceSs_0050
	IMPORT_FUNC  "sceSs", 0x1149CC2B, sceSsSMFSetPlayChannel
#endif
#ifdef F_sceSs_0051
	IMPORT_FUNC  "sceSs", 0x9FD89865, sceSsSMFGetPlayChannel
#endif
