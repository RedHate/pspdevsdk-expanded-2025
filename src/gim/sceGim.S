	.set noreorder

#include "pspimport.s"

#ifdef F_sceGim_0000
	IMPORT_START "sceGim", 0x00010011
#endif
#ifdef F_sceGim_0001
	IMPORT_FUNC  "sceGim", 0xD6831760, sceGimPictureSetMemoryManager
#endif
#ifdef F_sceGim_0002
	IMPORT_FUNC  "sceGim", 0xE8F8A61F, sceGimPictureSetMemoryManager2
#endif
#ifdef F_sceGim_0003
	IMPORT_FUNC  "sceGim", 0x4FED5CB3, sceGimPictureAllocMemory
#endif
#ifdef F_sceGim_0004
	IMPORT_FUNC  "sceGim", 0xBBBFE04A, sceGimPictureFreeMemory
#endif
#ifdef F_sceGim_0005
	IMPORT_FUNC  "sceGim", 0x3E8FF4C5, sceGimPictureAllocMemory2
#endif
#ifdef F_sceGim_0006
	IMPORT_FUNC  "sceGim", 0x4A9286E8, sceGimPictureFreeMemory2
#endif
#ifdef F_sceGim_0007
	IMPORT_FUNC  "sceGim", 0x872807A1, sceGimPictureCheckFileHeader
#endif
#ifdef F_sceGim_0008
	IMPORT_FUNC  "sceGim", 0x51468DB2, sceGimPictureGetChunkCount
#endif
#ifdef F_sceGim_0009
	IMPORT_FUNC  "sceGim", 0x309F00CA, sceGimPictureGetChunk
#endif
#ifdef F_sceGim_0010
	IMPORT_FUNC  "sceGim", 0x2041D147, sceGimPictureCreate
#endif
#ifdef F_sceGim_0011
	IMPORT_FUNC  "sceGim", 0x3CDA57F5, sceGimPictureDelete
#endif
#ifdef F_sceGim_0012
	IMPORT_FUNC  "sceGim", 0x27D6F8BA, sceGimPictureDuplicate
#endif
#ifdef F_sceGim_0013
	IMPORT_FUNC  "sceGim", 0x3760BFB7, sceGimPictureLoadFile
#endif
#ifdef F_sceGim_0014
	IMPORT_FUNC  "sceGim", 0x95A76162, sceGimPictureLoadTm2
#endif
#ifdef F_sceGim_0015
	IMPORT_FUNC  "sceGim", 0x62AF9F3B, sceGimPictureLoadTga
#endif
#ifdef F_sceGim_0016
	IMPORT_FUNC  "sceGim", 0xB434306C, sceGimPictureLoadBmp
#endif
#ifdef F_sceGim_0017
	IMPORT_FUNC  "sceGim", 0x4712BE6B, sceGimPictureLoad
#endif
#ifdef F_sceGim_0018
	IMPORT_FUNC  "sceGim", 0x055585E4, sceGimPictureUnload
#endif
#ifdef F_sceGim_0019
	IMPORT_FUNC  "sceGim", 0x00CADB78, sceGimPictureAnimate
#endif
#ifdef F_sceGim_0020
	IMPORT_FUNC  "sceGim", 0x3CCA0289, sceGimPictureControl
#endif
#ifdef F_sceGim_0021
	IMPORT_FUNC  "sceGim", 0x6779D55B, sceGimPictureActivate
#endif
#ifdef F_sceGim_0022
	IMPORT_FUNC  "sceGim", 0x431BAE6E, sceGimPictureActivateTexture
#endif
#ifdef F_sceGim_0023
	IMPORT_FUNC  "sceGim", 0x01CE20F1, sceGimPictureActivateRenderState
#endif
#ifdef F_sceGim_0024
	IMPORT_FUNC  "sceGim", 0xA0692AD9, sceGimPictureLoadCache
#endif
#ifdef F_sceGim_0025
	IMPORT_FUNC  "sceGim", 0xB0272C7D, sceGimPictureUnloadCache
#endif
#ifdef F_sceGim_0026
	IMPORT_FUNC  "sceGim", 0x53CAD8C0, sceGimPictureSetEnableBits
#endif
#ifdef F_sceGim_0027
	IMPORT_FUNC  "sceGim", 0x88652BC4, sceGimPictureGetEnableBits
#endif
#ifdef F_sceGim_0028
	IMPORT_FUNC  "sceGim", 0x64695880, sceGimPictureSetImageCrop
#endif
#ifdef F_sceGim_0029
	IMPORT_FUNC  "sceGim", 0x403794FA, sceGimPictureGetImageCrop
#endif
#ifdef F_sceGim_0030
	IMPORT_FUNC  "sceGim", 0xC1A0073E, sceGimPictureGetImage
#endif
#ifdef F_sceGim_0031
	IMPORT_FUNC  "sceGim", 0xB1E3E0B1, sceGimPictureGetPalette
#endif
#ifdef F_sceGim_0032
	IMPORT_FUNC  "sceGim", 0x9344EE49, sceGimPictureGetImagePixels
#endif
#ifdef F_sceGim_0033
	IMPORT_FUNC  "sceGim", 0x6929482F, sceGimPictureGetPalettePixels
#endif
#ifdef F_sceGim_0034
	IMPORT_FUNC  "sceGim", 0xE5FAD9BA, sceGimPictureSetImagePixels
#endif
#ifdef F_sceGim_0035
	IMPORT_FUNC  "sceGim", 0x0245FF5A, sceGimPictureSetPalettePixels
#endif
#ifdef F_sceGim_0036
	IMPORT_FUNC  "sceGim", 0xD381B0D1, sceGimPictureReallocImage
#endif
#ifdef F_sceGim_0037
	IMPORT_FUNC  "sceGim", 0x9A2C647D, sceGimPictureReallocPalette
#endif
#ifdef F_sceGim_0038
	IMPORT_FUNC  "sceGim", 0xE14C0F3B, sceGimPictureHasAnimation
#endif
#ifdef F_sceGim_0039
	IMPORT_FUNC  "sceGim", 0x838839B1, sceGimPictureSetFrameLoop
#endif
#ifdef F_sceGim_0040
	IMPORT_FUNC  "sceGim", 0x5A7ADB9F, sceGimPictureGetFrameLoop
#endif
#ifdef F_sceGim_0041
	IMPORT_FUNC  "sceGim", 0x4F8AD3DD, sceGimPictureSetFrameRate
#endif
#ifdef F_sceGim_0042
	IMPORT_FUNC  "sceGim", 0x9475C42A, sceGimPictureGetFrameRate
#endif
#ifdef F_sceGim_0043
	IMPORT_FUNC  "sceGim", 0x57739A07, sceGimPictureSetFrameRepeat
#endif
#ifdef F_sceGim_0044
	IMPORT_FUNC  "sceGim", 0xE35B8260, sceGimPictureGetFrameRepeat
#endif
#ifdef F_sceGim_0045
	IMPORT_FUNC  "sceGim", 0xB8496E49, sceGimPictureSetFrame
#endif
#ifdef F_sceGim_0046
	IMPORT_FUNC  "sceGim", 0xDA622ADC, sceGimPictureGetFrame
#endif
#ifdef F_sceGim_0047
	IMPORT_FUNC  "sceGim", 0x8B6DBF46, sceGimPictureSetImageFrame
#endif
#ifdef F_sceGim_0048
	IMPORT_FUNC  "sceGim", 0x6B884DC8, sceGimPictureGetImageFrame
#endif
#ifdef F_sceGim_0049
	IMPORT_FUNC  "sceGim", 0x8AD23153, sceGimPictureSetImageFrame2
#endif
#ifdef F_sceGim_0050
	IMPORT_FUNC  "sceGim", 0x40B8EB2C, sceGimPictureGetImageFrame2
#endif
#ifdef F_sceGim_0051
	IMPORT_FUNC  "sceGim", 0xD159C88C, sceGimPictureSetPaletteFrame
#endif
#ifdef F_sceGim_0052
	IMPORT_FUNC  "sceGim", 0x0AF40A8E, sceGimPictureGetPaletteFrame
#endif
#ifdef F_sceGim_0053
	IMPORT_FUNC  "sceGim", 0x1A1FB73F, sceGimPictureSetPaletteFrame2
#endif
#ifdef F_sceGim_0054
	IMPORT_FUNC  "sceGim", 0xBE02E15B, sceGimPictureGetPaletteFrame2
#endif
#ifdef F_sceGim_0055
	IMPORT_FUNC  "sceGim", 0xBC1E9F7D, sceGimPictureSetDissolve
#endif
#ifdef F_sceGim_0056
	IMPORT_FUNC  "sceGim", 0x5FD6DEDD, sceGimPictureGetDissolve
#endif
#ifdef F_sceGim_0057
	IMPORT_FUNC  "sceGim", 0x41B2545C, sceGimPictureGetSequenceCount
#endif
#ifdef F_sceGim_0058
	IMPORT_FUNC  "sceGim", 0x66C99783, sceGimPictureGetSequence
#endif
#ifdef F_sceGim_0059
	IMPORT_FUNC  "sceGim", 0x71D789DE, sceGimPictureSetCurrentSequence
#endif
#ifdef F_sceGim_0060
	IMPORT_FUNC  "sceGim", 0xD0AAD363, sceGimPictureGetCurrentSequence
#endif
#ifdef F_sceGim_0061
	IMPORT_FUNC  "sceGim", 0xD2FB97E2, sceGimPictureGetImagePlaneCount
#endif
#ifdef F_sceGim_0062
	IMPORT_FUNC  "sceGim", 0x82F8039A, sceGimPictureSetImagePlane
#endif
#ifdef F_sceGim_0063
	IMPORT_FUNC  "sceGim", 0xA89B04C1, sceGimPictureGetImagePlane
#endif
#ifdef F_sceGim_0064
	IMPORT_FUNC  "sceGim", 0xBDD69706, sceGimPictureSetPaletteOffset
#endif
#ifdef F_sceGim_0065
	IMPORT_FUNC  "sceGim", 0xDDC1CABB, sceGimPictureGetPaletteOffset
#endif
#ifdef F_sceGim_0066
	IMPORT_FUNC  "sceGim", 0x7658FDD7, sceGimPictureSetBlend
#endif
#ifdef F_sceGim_0067
	IMPORT_FUNC  "sceGim", 0x0D45AA5D, sceGimPictureGetBlend
#endif
#ifdef F_sceGim_0068
	IMPORT_FUNC  "sceGim", 0x94615A54, sceGimPictureSetFunc
#endif
#ifdef F_sceGim_0069
	IMPORT_FUNC  "sceGim", 0x0048F7C9, sceGimPictureGetFunc
#endif
#ifdef F_sceGim_0070
	IMPORT_FUNC  "sceGim", 0x8EC7C9BB, sceGimPictureSetFilter
#endif
#ifdef F_sceGim_0071
	IMPORT_FUNC  "sceGim", 0x697E78FC, sceGimPictureGetFilter
#endif
#ifdef F_sceGim_0072
	IMPORT_FUNC  "sceGim", 0xE5C22261, sceGimPictureSetWrap
#endif
#ifdef F_sceGim_0073
	IMPORT_FUNC  "sceGim", 0xD4F2A274, sceGimPictureGetWrap
#endif
#ifdef F_sceGim_0074
	IMPORT_FUNC  "sceGim", 0x9FAA38E3, sceGimPictureInitDevice
#endif
#ifdef F_sceGim_0075
	IMPORT_FUNC  "sceGim", 0xB068D48C, sceGimPictureTermDevice
#endif
