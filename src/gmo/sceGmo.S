	.set noreorder

#include "pspimport.s"

#ifdef F_sceGmo_0000
	IMPORT_START "sceGmo", 0x00010011
#endif
#ifdef F_sceGmo_0001
	IMPORT_FUNC  "sceGmo", 0xAE72B398, sceGmoModelSetMemoryManager
#endif
#ifdef F_sceGmo_0002
	IMPORT_FUNC  "sceGmo", 0x9279B50D, sceGmoModelSetMemoryManager2
#endif
#ifdef F_sceGmo_0003
	IMPORT_FUNC  "sceGmo", 0x4CF4A945, sceGmoModelSetPictureManager
#endif
#ifdef F_sceGmo_0004
	IMPORT_FUNC  "sceGmo", 0x310F1FFF, sceGmoModelOpenMemoryCluster
#endif
#ifdef F_sceGmo_0005
	IMPORT_FUNC  "sceGmo", 0xC675034E, sceGmoModelOpenMemoryCluster2
#endif
#ifdef F_sceGmo_0006
	IMPORT_FUNC  "sceGmo", 0xF5D7A0B2, sceGmoModelCloseMemoryCluster
#endif
#ifdef F_sceGmo_0007
	IMPORT_FUNC  "sceGmo", 0xB7D86C63, sceGmoModelCloseMemoryCluster2
#endif
#ifdef F_sceGmo_0008
	IMPORT_FUNC  "sceGmo", 0x76C956AE, sceGmoModelAllocMemory
#endif
#ifdef F_sceGmo_0009
	IMPORT_FUNC  "sceGmo", 0x96FB8487, sceGmoModelAllocMemory2
#endif
#ifdef F_sceGmo_0010
	IMPORT_FUNC  "sceGmo", 0xDF05371F, sceGmoModelFreeMemory
#endif
#ifdef F_sceGmo_0011
	IMPORT_FUNC  "sceGmo", 0x5ADFA96E, sceGmoModelFreeMemory2
#endif
#ifdef F_sceGmo_0012
	IMPORT_FUNC  "sceGmo", 0xAE45A094, sceGmoModelImportPicture
#endif
#ifdef F_sceGmo_0013
	IMPORT_FUNC  "sceGmo", 0x79242164, sceGmoModelExportPicture
#endif
#ifdef F_sceGmo_0014
	IMPORT_FUNC  "sceGmo", 0x04AE207E, sceGmoModelCheckFileHeader
#endif
#ifdef F_sceGmo_0015
	IMPORT_FUNC  "sceGmo", 0x75589A40, sceGmoModelGetChunkCount
#endif
#ifdef F_sceGmo_0016
	IMPORT_FUNC  "sceGmo", 0x1AD6BE7C, sceGmoModelGetChunk
#endif
#ifdef F_sceGmo_0017
	IMPORT_FUNC  "sceGmo", 0x3ABC9D45, sceGmoModelCreate
#endif
#ifdef F_sceGmo_0018
	IMPORT_FUNC  "sceGmo", 0x95A9BAB0, sceGmoModelDelete
#endif
#ifdef F_sceGmo_0019
	IMPORT_FUNC  "sceGmo", 0x72FC9E95, sceGmoModelDuplicate
#endif
#ifdef F_sceGmo_0020
	IMPORT_FUNC  "sceGmo", 0xD02EF50B, sceGmoModelLoadFile
#endif
#ifdef F_sceGmo_0021
	IMPORT_FUNC  "sceGmo", 0x35995383, sceGmoModelLoad
#endif
#ifdef F_sceGmo_0022
	IMPORT_FUNC  "sceGmo", 0xF9EEEAAA, sceGmoModelUnload
#endif
#ifdef F_sceGmo_0023
	IMPORT_FUNC  "sceGmo", 0xBC0C8614, sceGmoModelLoadCache
#endif
#ifdef F_sceGmo_0024
	IMPORT_FUNC  "sceGmo", 0xC5BAA6B9, sceGmoModelUnloadCache
#endif
#ifdef F_sceGmo_0025
	IMPORT_FUNC  "sceGmo", 0xCE33AF74, sceGmoModelAnimate
#endif
#ifdef F_sceGmo_0026
	IMPORT_FUNC  "sceGmo", 0x0BB8CF61, sceGmoModelUpdate
#endif
#ifdef F_sceGmo_0027
	IMPORT_FUNC  "sceGmo", 0xA85C7EEF, sceGmoModelDraw
#endif
#ifdef F_sceGmo_0028
	IMPORT_FUNC  "sceGmo", 0x6F77CCEF, sceGmoModelSetWorldMatrix
#endif
#ifdef F_sceGmo_0029
	IMPORT_FUNC  "sceGmo", 0xFF410EC7, sceGmoModelGetWorldMatrix
#endif
#ifdef F_sceGmo_0030
	IMPORT_FUNC  "sceGmo", 0x6383F250, sceGmoModelSetCurrentMotion
#endif
#ifdef F_sceGmo_0031
	IMPORT_FUNC  "sceGmo", 0x185B008D, sceGmoModelGetCurrentMotion
#endif
#ifdef F_sceGmo_0032
	IMPORT_FUNC  "sceGmo", 0xF9213D2C, sceGmoModelSetEnableBits
#endif
#ifdef F_sceGmo_0033
	IMPORT_FUNC  "sceGmo", 0xBDF1C9F4, sceGmoModelGetEnableBits
#endif
#ifdef F_sceGmo_0034
	IMPORT_FUNC  "sceGmo", 0x74DE4716, sceGmoModelSetEnableMask
#endif
#ifdef F_sceGmo_0035
	IMPORT_FUNC  "sceGmo", 0xF834383B, sceGmoModelGetEnableMask
#endif
#ifdef F_sceGmo_0036
	IMPORT_FUNC  "sceGmo", 0x8DD9AFD0, sceGmoModelHasAnimation
#endif
#ifdef F_sceGmo_0037
	IMPORT_FUNC  "sceGmo", 0x7D36BCE6, sceGmoModelGetBoundingBox
#endif
#ifdef F_sceGmo_0038
	IMPORT_FUNC  "sceGmo", 0x544D4B1D, sceGmoModelGetVertexOffset
#endif
#ifdef F_sceGmo_0039
	IMPORT_FUNC  "sceGmo", 0x71592B04, sceGmoModelGetTexcoordOffset
#endif
#ifdef F_sceGmo_0040
	IMPORT_FUNC  "sceGmo", 0xC4999ECF, sceGmoModelGetBoneCount
#endif
#ifdef F_sceGmo_0041
	IMPORT_FUNC  "sceGmo", 0xFA6E3580, sceGmoModelGetPartCount
#endif
#ifdef F_sceGmo_0042
	IMPORT_FUNC  "sceGmo", 0x138CFD2D, sceGmoModelGetMaterialCount
#endif
#ifdef F_sceGmo_0043
	IMPORT_FUNC  "sceGmo", 0xD1D1E96C, sceGmoModelGetTextureCount
#endif
#ifdef F_sceGmo_0044
	IMPORT_FUNC  "sceGmo", 0x2A48A889, sceGmoModelGetMotionCount
#endif
#ifdef F_sceGmo_0045
	IMPORT_FUNC  "sceGmo", 0x0CBF5AE7, sceGmoModelGetBone
#endif
#ifdef F_sceGmo_0046
	IMPORT_FUNC  "sceGmo", 0xB8C497C2, sceGmoModelGetPart
#endif
#ifdef F_sceGmo_0047
	IMPORT_FUNC  "sceGmo", 0xE4F6E8BC, sceGmoModelGetMaterial
#endif
#ifdef F_sceGmo_0048
	IMPORT_FUNC  "sceGmo", 0x3555198C, sceGmoModelGetTexture
#endif
#ifdef F_sceGmo_0049
	IMPORT_FUNC  "sceGmo", 0x58F64B31, sceGmoModelGetMotion
#endif
#ifdef F_sceGmo_0050
	IMPORT_FUNC  "sceGmo", 0xFFA3DB73, sceGmoModelSetBone
#endif
#ifdef F_sceGmo_0051
	IMPORT_FUNC  "sceGmo", 0x83C347B6, sceGmoModelSetPart
#endif
#ifdef F_sceGmo_0052
	IMPORT_FUNC  "sceGmo", 0x63848BD4, sceGmoModelSetMaterial
#endif
#ifdef F_sceGmo_0053
	IMPORT_FUNC  "sceGmo", 0xB322BF8E, sceGmoModelSetTexture
#endif
#ifdef F_sceGmo_0054
	IMPORT_FUNC  "sceGmo", 0x0FE3BE33, sceGmoModelSetMotion
#endif
#ifdef F_sceGmo_0055
	IMPORT_FUNC  "sceGmo", 0xB35B500F, sceGmoBoneCreate
#endif
#ifdef F_sceGmo_0056
	IMPORT_FUNC  "sceGmo", 0x26ED8856, sceGmoBoneDelete
#endif
#ifdef F_sceGmo_0057
	IMPORT_FUNC  "sceGmo", 0xF6FF014B, sceGmoBoneDuplicate
#endif
#ifdef F_sceGmo_0058
	IMPORT_FUNC  "sceGmo", 0xDE6ADE0F, sceGmoBoneLoad
#endif
#ifdef F_sceGmo_0059
	IMPORT_FUNC  "sceGmo", 0xC7D963A4, sceGmoBoneUnload
#endif
#ifdef F_sceGmo_0060
	IMPORT_FUNC  "sceGmo", 0x1E45F621, sceGmoBoneUpdate
#endif
#ifdef F_sceGmo_0061
	IMPORT_FUNC  "sceGmo", 0xAC30813D, sceGmoBoneDraw
#endif
#ifdef F_sceGmo_0062
	IMPORT_FUNC  "sceGmo", 0x675359AB, sceGmoBoneActivate
#endif
#ifdef F_sceGmo_0063
	IMPORT_FUNC  "sceGmo", 0xAE782FC6, sceGmoBoneControl
#endif
#ifdef F_sceGmo_0064
	IMPORT_FUNC  "sceGmo", 0x873084F1, sceGmoBoneSetParent
#endif
#ifdef F_sceGmo_0065
	IMPORT_FUNC  "sceGmo", 0x59F2FB37, sceGmoBoneGetParent
#endif
#ifdef F_sceGmo_0066
	IMPORT_FUNC  "sceGmo", 0x6A2C59C3, sceGmoBoneGetWorldMatrix
#endif
#ifdef F_sceGmo_0067
	IMPORT_FUNC  "sceGmo", 0x09288EB3, sceGmoPartCreate
#endif
#ifdef F_sceGmo_0068
	IMPORT_FUNC  "sceGmo", 0x53906ABF, sceGmoPartDelete
#endif
#ifdef F_sceGmo_0069
	IMPORT_FUNC  "sceGmo", 0x760D9948, sceGmoPartDuplicate
#endif
#ifdef F_sceGmo_0070
	IMPORT_FUNC  "sceGmo", 0x0C036D9F, sceGmoPartLoad
#endif
#ifdef F_sceGmo_0071
	IMPORT_FUNC  "sceGmo", 0xFD5F5F34, sceGmoPartUnload
#endif
#ifdef F_sceGmo_0072
	IMPORT_FUNC  "sceGmo", 0x9B2A408E, sceGmoPartLoadCache
#endif
#ifdef F_sceGmo_0073
	IMPORT_FUNC  "sceGmo", 0x7F0CDF0F, sceGmoPartUnloadCache
#endif
#ifdef F_sceGmo_0074
	IMPORT_FUNC  "sceGmo", 0xFB265128, sceGmoPartDraw
#endif
#ifdef F_sceGmo_0075
	IMPORT_FUNC  "sceGmo", 0x5BDC7701, sceGmoPartSetParent
#endif
#ifdef F_sceGmo_0076
	IMPORT_FUNC  "sceGmo", 0x3616747A, sceGmoPartGetParent
#endif
#ifdef F_sceGmo_0077
	IMPORT_FUNC  "sceGmo", 0xF04AF000, sceGmoPartGetMeshCount
#endif
#ifdef F_sceGmo_0078
	IMPORT_FUNC  "sceGmo", 0xA1DB2B16, sceGmoPartGetArraysCount
#endif
#ifdef F_sceGmo_0079
	IMPORT_FUNC  "sceGmo", 0xBBB59151, sceGmoPartGetMesh
#endif
#ifdef F_sceGmo_0080
	IMPORT_FUNC  "sceGmo", 0xEBB3DD02, sceGmoPartGetArrays
#endif
#ifdef F_sceGmo_0081
	IMPORT_FUNC  "sceGmo", 0x9D2E8B09, sceGmoMeshCreate
#endif
#ifdef F_sceGmo_0082
	IMPORT_FUNC  "sceGmo", 0x131782FD, sceGmoMeshDelete
#endif
#ifdef F_sceGmo_0083
	IMPORT_FUNC  "sceGmo", 0x172E2214, sceGmoMeshDuplicate
#endif
#ifdef F_sceGmo_0084
	IMPORT_FUNC  "sceGmo", 0x6F6C79BD, sceGmoMeshLoad
#endif
#ifdef F_sceGmo_0085
	IMPORT_FUNC  "sceGmo", 0x14E555A7, sceGmoMeshUnload
#endif
#ifdef F_sceGmo_0086
	IMPORT_FUNC  "sceGmo", 0x674F660A, sceGmoMeshLoadCache
#endif
#ifdef F_sceGmo_0087
	IMPORT_FUNC  "sceGmo", 0x41B2D18C, sceGmoMeshUnloadCache
#endif
#ifdef F_sceGmo_0088
	IMPORT_FUNC  "sceGmo", 0xAA1AEF06, sceGmoMeshDraw
#endif
#ifdef F_sceGmo_0089
	IMPORT_FUNC  "sceGmo", 0x7E807600, sceGmoMaterialCreate
#endif
#ifdef F_sceGmo_0090
	IMPORT_FUNC  "sceGmo", 0x70E783E4, sceGmoMaterialDelete
#endif
#ifdef F_sceGmo_0091
	IMPORT_FUNC  "sceGmo", 0x0FB5B450, sceGmoMaterialDuplicate
#endif
#ifdef F_sceGmo_0092
	IMPORT_FUNC  "sceGmo", 0x0E246166, sceGmoMaterialLoad
#endif
#ifdef F_sceGmo_0093
	IMPORT_FUNC  "sceGmo", 0x5DA63832, sceGmoMaterialUnload
#endif
#ifdef F_sceGmo_0094
	IMPORT_FUNC  "sceGmo", 0x0AC1C154, sceGmoMaterialLoadCache
#endif
#ifdef F_sceGmo_0095
	IMPORT_FUNC  "sceGmo", 0x6345A9EA, sceGmoMaterialUnloadCache
#endif
#ifdef F_sceGmo_0096
	IMPORT_FUNC  "sceGmo", 0xD7936E75, sceGmoMaterialUpdate
#endif
#ifdef F_sceGmo_0097
	IMPORT_FUNC  "sceGmo", 0x492DF9AD, sceGmoMaterialActivate
#endif
#ifdef F_sceGmo_0098
	IMPORT_FUNC  "sceGmo", 0x6BB63988, sceGmoMaterialControl
#endif
#ifdef F_sceGmo_0099
	IMPORT_FUNC  "sceGmo", 0xC19C7F7A, sceGmoMaterialSetParent
#endif
#ifdef F_sceGmo_0100
	IMPORT_FUNC  "sceGmo", 0x8BCFDE8B, sceGmoMaterialGetParent
#endif
#ifdef F_sceGmo_0101
	IMPORT_FUNC  "sceGmo", 0xA1DADBC3, sceGmoMaterialGetLayerCount
#endif
#ifdef F_sceGmo_0102
	IMPORT_FUNC  "sceGmo", 0xD8009762, sceGmoMaterialGetLayer
#endif
#ifdef F_sceGmo_0103
	IMPORT_FUNC  "sceGmo", 0xE3DEE8EE, sceGmoLayerCreate
#endif
#ifdef F_sceGmo_0104
	IMPORT_FUNC  "sceGmo", 0x2B90DC80, sceGmoLayerDelete
#endif
#ifdef F_sceGmo_0105
	IMPORT_FUNC  "sceGmo", 0xE97E3A67, sceGmoLayerDuplicate
#endif
#ifdef F_sceGmo_0106
	IMPORT_FUNC  "sceGmo", 0x5F76EC50, sceGmoLayerLoad
#endif
#ifdef F_sceGmo_0107
	IMPORT_FUNC  "sceGmo", 0x46A67199, sceGmoLayerUnload
#endif
#ifdef F_sceGmo_0108
	IMPORT_FUNC  "sceGmo", 0x8C8F022F, sceGmoLayerLoadCache
#endif
#ifdef F_sceGmo_0109
	IMPORT_FUNC  "sceGmo", 0x48D05472, sceGmoLayerUnloadCache
#endif
#ifdef F_sceGmo_0110
	IMPORT_FUNC  "sceGmo", 0xCFE1F3B2, sceGmoLayerActivate
#endif
#ifdef F_sceGmo_0111
	IMPORT_FUNC  "sceGmo", 0xF1CBD458, sceGmoLayerSetMapType
#endif
#ifdef F_sceGmo_0112
	IMPORT_FUNC  "sceGmo", 0xD9B06EAB, sceGmoLayerGetMapType
#endif
#ifdef F_sceGmo_0113
	IMPORT_FUNC  "sceGmo", 0xD04191C7, sceGmoLayerSetTexCrop
#endif
#ifdef F_sceGmo_0114
	IMPORT_FUNC  "sceGmo", 0x0F924EA6, sceGmoLayerGetTexCrop
#endif
#ifdef F_sceGmo_0115
	IMPORT_FUNC  "sceGmo", 0xF5289D03, sceGmoTextureCreate
#endif
#ifdef F_sceGmo_0116
	IMPORT_FUNC  "sceGmo", 0xE7ECE9A4, sceGmoTextureDelete
#endif
#ifdef F_sceGmo_0117
	IMPORT_FUNC  "sceGmo", 0x090EEB05, sceGmoTextureDuplicate
#endif
#ifdef F_sceGmo_0118
	IMPORT_FUNC  "sceGmo", 0x6D4CFB10, sceGmoTextureLoad
#endif
#ifdef F_sceGmo_0119
	IMPORT_FUNC  "sceGmo", 0xFEEAB6C0, sceGmoTextureUnload
#endif
#ifdef F_sceGmo_0120
	IMPORT_FUNC  "sceGmo", 0x10D0AFBA, sceGmoTextureAnimate
#endif
#ifdef F_sceGmo_0121
	IMPORT_FUNC  "sceGmo", 0x47C91943, sceGmoTextureActivate
#endif
#ifdef F_sceGmo_0122
	IMPORT_FUNC  "sceGmo", 0x6430EEA8, sceGmoTextureSetParent
#endif
#ifdef F_sceGmo_0123
	IMPORT_FUNC  "sceGmo", 0xEE8CA2BE, sceGmoTextureGetParent
#endif
#ifdef F_sceGmo_0124
	IMPORT_FUNC  "sceGmo", 0xD3D1AC7B, sceGmoTextureSetPicture
#endif
#ifdef F_sceGmo_0125
	IMPORT_FUNC  "sceGmo", 0x5E9A8E95, sceGmoTextureGetPicture
#endif
#ifdef F_sceGmo_0126
	IMPORT_FUNC  "sceGmo", 0x5783B331, sceGmoTextureHasAnimation
#endif
#ifdef F_sceGmo_0127
	IMPORT_FUNC  "sceGmo", 0xC7775326, sceGmoMotionCreate
#endif
#ifdef F_sceGmo_0128
	IMPORT_FUNC  "sceGmo", 0xCAE6E4F3, sceGmoMotionDelete
#endif
#ifdef F_sceGmo_0129
	IMPORT_FUNC  "sceGmo", 0xEDFE98B9, sceGmoMotionDuplicate
#endif
#ifdef F_sceGmo_0130
	IMPORT_FUNC  "sceGmo", 0x7B870A77, sceGmoMotionLoad
#endif
#ifdef F_sceGmo_0131
	IMPORT_FUNC  "sceGmo", 0xF029F601, sceGmoMotionUnload
#endif
#ifdef F_sceGmo_0132
	IMPORT_FUNC  "sceGmo", 0x9402E8E3, sceGmoMotionAnimate
#endif
#ifdef F_sceGmo_0133
	IMPORT_FUNC  "sceGmo", 0x66B8E208, sceGmoMotionSetParent
#endif
#ifdef F_sceGmo_0134
	IMPORT_FUNC  "sceGmo", 0xE7A322DF, sceGmoMotionGetParent
#endif
#ifdef F_sceGmo_0135
	IMPORT_FUNC  "sceGmo", 0x43299C60, sceGmoMotionSetFrameLoop
#endif
#ifdef F_sceGmo_0136
	IMPORT_FUNC  "sceGmo", 0x234C71A0, sceGmoMotionGetFrameLoop
#endif
#ifdef F_sceGmo_0137
	IMPORT_FUNC  "sceGmo", 0x1F0449A3, sceGmoMotionSetFrameRate
#endif
#ifdef F_sceGmo_0138
	IMPORT_FUNC  "sceGmo", 0x64CC09DA, sceGmoMotionGetFrameRate
#endif
#ifdef F_sceGmo_0139
	IMPORT_FUNC  "sceGmo", 0xF2F5F36A, sceGmoMotionSetFrameRepeat
#endif
#ifdef F_sceGmo_0140
	IMPORT_FUNC  "sceGmo", 0x8CC188D6, sceGmoMotionGetFrameRepeat
#endif
#ifdef F_sceGmo_0141
	IMPORT_FUNC  "sceGmo", 0x65230FB1, sceGmoMotionSetFrame
#endif
#ifdef F_sceGmo_0142
	IMPORT_FUNC  "sceGmo", 0xA4CEB1E7, sceGmoMotionGetFrame
#endif
#ifdef F_sceGmo_0143
	IMPORT_FUNC  "sceGmo", 0xB0AA2D00, sceGmoMotionSetWeight
#endif
#ifdef F_sceGmo_0144
	IMPORT_FUNC  "sceGmo", 0x3B647D91, sceGmoMotionGetWeight
#endif
#ifdef F_sceGmo_0145
	IMPORT_FUNC  "sceGmo", 0xBBFD8341, sceGmoMotionGetAnimationCount
#endif
#ifdef F_sceGmo_0146
	IMPORT_FUNC  "sceGmo", 0xE6A37C8F, sceGmoMotionGetFcurveCount
#endif
#ifdef F_sceGmo_0147
	IMPORT_FUNC  "sceGmo", 0x69723CD2, sceGmoMotionGetAnimation
#endif
#ifdef F_sceGmo_0148
	IMPORT_FUNC  "sceGmo", 0x10EE6E24, sceGmoMotionGetFcurve
#endif
#ifdef F_sceGmo_0149
	IMPORT_FUNC  "sceGmo", 0xC957E3DA, sceGmoBoneAnimate
#endif
#ifdef F_sceGmo_0150
	IMPORT_FUNC  "sceGmo", 0x6D04DE89, sceGmoMaterialAnimate
#endif
#ifdef F_sceGmo_0151
	IMPORT_FUNC  "sceGmo", 0x8596B735, sceGmoTextureUpdate
#endif
#ifdef F_sceGmo_0152
	IMPORT_FUNC  "sceGmo", 0x102F9989, sceGmoMotionUpdate
#endif
#ifdef F_sceGmo_0153
	IMPORT_FUNC  "sceGmo", 0xB7A723FB, sceGmoSubjectConstruct
#endif
#ifdef F_sceGmo_0154
	IMPORT_FUNC  "sceGmo", 0x76F6E264, sceGmoSubjectDestruct
#endif
#ifdef F_sceGmo_0155
	IMPORT_FUNC  "sceGmo", 0xE49A3510, sceGmoSubjectCopy
#endif
#ifdef F_sceGmo_0156
	IMPORT_FUNC  "sceGmo", 0xEC278F73, sceGmoSubjectAttachObserver
#endif
#ifdef F_sceGmo_0157
	IMPORT_FUNC  "sceGmo", 0x781A9AEA, sceGmoSubjectDetachObserver
#endif
#ifdef F_sceGmo_0158
	IMPORT_FUNC  "sceGmo", 0xE7605D48, sceGmoObserverConstruct
#endif
#ifdef F_sceGmo_0159
	IMPORT_FUNC  "sceGmo", 0x5B9AA49E, sceGmoObserverDestruct
#endif
#ifdef F_sceGmo_0160
	IMPORT_FUNC  "sceGmo", 0xF0B41F6F, sceGmoObserverCopy
#endif
#ifdef F_sceGmo_0161
	IMPORT_FUNC  "sceGmo", 0x88E27DFB, sceGmoObserverSetSubject
#endif
#ifdef F_sceGmo_0162
	IMPORT_FUNC  "sceGmo", 0x62EBEE68, sceGmoBaseConstruct
#endif
#ifdef F_sceGmo_0163
	IMPORT_FUNC  "sceGmo", 0x66CA9D34, sceGmoBaseDestruct
#endif
#ifdef F_sceGmo_0164
	IMPORT_FUNC  "sceGmo", 0xF0F342D4, sceGmoBaseCopy
#endif
#ifdef F_sceGmo_0165
	IMPORT_FUNC  "sceGmo", 0x71AA1B1D, sceGmoBaseAttachObserver
#endif
#ifdef F_sceGmo_0166
	IMPORT_FUNC  "sceGmo", 0xDACC9B43, sceGmoBaseDetachObserver
#endif
#ifdef F_sceGmo_0167
	IMPORT_FUNC  "sceGmo", 0xDE7291CA, sceGmoBaseSetParent
#endif
#ifdef F_sceGmo_0168
	IMPORT_FUNC  "sceGmo", 0x581CFB44, sceGmoModelGetMetrics
#endif
#ifdef F_sceGmo_0169
	IMPORT_FUNC  "sceGmo", 0x8EE0AA24, sceGmoModelGetMemoryClusterSize
#endif
#ifdef F_sceGmo_0170
	IMPORT_FUNC  "sceGmo", 0x4756B492, sceGmoModelGetMemoryClusterSize2
#endif
