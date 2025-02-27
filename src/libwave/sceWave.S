	.set noreorder

#include "pspimport.s"

#ifdef F_sceWave_0000
	IMPORT_START "sceWave", 0x00010011
#endif
#ifdef F_sceWave_0001
	IMPORT_FUNC  "sceWave", 0xDBC2F77B, sceWaveInit
#endif
#ifdef F_sceWave_0002
	IMPORT_FUNC  "sceWave", 0xA2EC6F86, sceWaveExit
#endif
#ifdef F_sceWave_0003
	IMPORT_FUNC  "sceWave", 0x0AE87042, sceWaveStart
#endif
#ifdef F_sceWave_0004
	IMPORT_FUNC  "sceWave", 0x4D1B6B89, sceWaveEnd
#endif
#ifdef F_sceWave_0005
	IMPORT_FUNC  "sceWave", 0x790A0504, sceWaveSetVoice
#endif
#ifdef F_sceWave_0006
	IMPORT_FUNC  "sceWave", 0x7B1E4FF7, sceWaveSetVolume
#endif
#ifdef F_sceWave_0007
	IMPORT_FUNC  "sceWave", 0xB50466EF, sceWaveGetVolume
#endif
#ifdef F_sceWave_0008
	IMPORT_FUNC  "sceWave", 0x0DB1A8DD, sceWaveSetVolumeEx
#endif
#ifdef F_sceWave_0009
	IMPORT_FUNC  "sceWave", 0x1B68DDA0, sceWaveGetVolumeEx
#endif
#ifdef F_sceWave_0010
	IMPORT_FUNC  "sceWave", 0x5B143EEB, sceWaveSetLoopMode
#endif
#ifdef F_sceWave_0011
	IMPORT_FUNC  "sceWave", 0xAB9E413B, sceWaveGetRestByte
#endif
#ifdef F_sceWave_0012
	IMPORT_FUNC  "sceWave", 0xF33D907E, sceWaveGetStat
#endif
#ifdef F_sceWave_0013
	IMPORT_FUNC  "sceWave", 0x62DCDECF, sceWavePlay
#endif
#ifdef F_sceWave_0014
	IMPORT_FUNC  "sceWave", 0x7AFDF508, sceWavePlayEx
#endif
#ifdef F_sceWave_0015
	IMPORT_FUNC  "sceWave", 0x34B8AB30, sceWaveStop
#endif
#ifdef F_sceWave_0016
	IMPORT_FUNC  "sceWave", 0x46862ED5, sceWavePause
#endif
#ifdef F_sceWave_0017
	IMPORT_FUNC  "sceWave", 0xDC6EE551, sceWaveReplay
#endif
#ifdef F_sceWave_0018
	IMPORT_FUNC  "sceWave", 0xE850A076, sceWaveAllStop
#endif
#ifdef F_sceWave_0019
	IMPORT_FUNC  "sceWave", 0x0FB8CC50, sceWaveAudioSetSample
#endif
#ifdef F_sceWave_0020
	IMPORT_FUNC  "sceWave", 0xD283DA4C, sceWaveAudioSetVolume
#endif
#ifdef F_sceWave_0021
	IMPORT_FUNC  "sceWave", 0x0B58D6F4, sceWaveAudioSetFormat
#endif
#ifdef F_sceWave_0022
	IMPORT_FUNC  "sceWave", 0xEB6CD7A0, sceWaveAudioGetRestSample
#endif
#ifdef F_sceWave_0023
	IMPORT_FUNC  "sceWave", 0xA4E42072, sceWaveAudioWrite
#endif
#ifdef F_sceWave_0024
	IMPORT_FUNC  "sceWave", 0xBE99CAD4, sceWaveAudioWriteBlocking
#endif
