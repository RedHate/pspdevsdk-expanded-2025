	.set noreorder

#include "pspimport.s"

#ifdef F_sceVfpu_0000
	IMPORT_START "sceVfpu", 0x00010011
#endif
#ifdef F_sceVfpu_0001
	IMPORT_FUNC  "sceVfpu", 0xE64C3946, sceVfpuVector2PositiveZero
#endif
#ifdef F_sceVfpu_0002
	IMPORT_FUNC  "sceVfpu", 0xC0028BAA, sceVfpuVector3PositiveZero
#endif
#ifdef F_sceVfpu_0003
	IMPORT_FUNC  "sceVfpu", 0xFE3B7EB5, sceVfpuVector4PositiveZero
#endif
#ifdef F_sceVfpu_0004
	IMPORT_FUNC  "sceVfpu", 0x9F463359, sceVfpuVector2NegativeZero
#endif
#ifdef F_sceVfpu_0005
	IMPORT_FUNC  "sceVfpu", 0xF2609482, sceVfpuVector3NegativeZero
#endif
#ifdef F_sceVfpu_0006
	IMPORT_FUNC  "sceVfpu", 0x2034FFD9, sceVfpuVector4NegativeZero
#endif
#ifdef F_sceVfpu_0007
	IMPORT_FUNC  "sceVfpu", 0xCE32B68D, sceVfpuVector2Set
#endif
#ifdef F_sceVfpu_0008
	IMPORT_FUNC  "sceVfpu", 0x295BF133, sceVfpuVector3Set
#endif
#ifdef F_sceVfpu_0009
	IMPORT_FUNC  "sceVfpu", 0xF1CE796C, sceVfpuVector4Set
#endif
#ifdef F_sceVfpu_0010
	IMPORT_FUNC  "sceVfpu", 0x722A420F, sceVfpuVector4SetXYZ
#endif
#ifdef F_sceVfpu_0011
	IMPORT_FUNC  "sceVfpu", 0x333F5B0C, sceVfpuVector2Copy
#endif
#ifdef F_sceVfpu_0012
	IMPORT_FUNC  "sceVfpu", 0xCFC58802, sceVfpuVector3Copy
#endif
#ifdef F_sceVfpu_0013
	IMPORT_FUNC  "sceVfpu", 0xCD8623A1, sceVfpuVector4Copy
#endif
#ifdef F_sceVfpu_0014
	IMPORT_FUNC  "sceVfpu", 0x6E92CF51, sceVfpuVector2Ceil
#endif
#ifdef F_sceVfpu_0015
	IMPORT_FUNC  "sceVfpu", 0x7D47E137, sceVfpuVector3Ceil
#endif
#ifdef F_sceVfpu_0016
	IMPORT_FUNC  "sceVfpu", 0x67537638, sceVfpuVector4Ceil
#endif
#ifdef F_sceVfpu_0017
	IMPORT_FUNC  "sceVfpu", 0x9CF6E52E, sceVfpuVector2Trunc
#endif
#ifdef F_sceVfpu_0018
	IMPORT_FUNC  "sceVfpu", 0xDE9A11C7, sceVfpuVector3Trunc
#endif
#ifdef F_sceVfpu_0019
	IMPORT_FUNC  "sceVfpu", 0x75ED958E, sceVfpuVector4Trunc
#endif
#ifdef F_sceVfpu_0020
	IMPORT_FUNC  "sceVfpu", 0x73570699, sceVfpuVector2Round
#endif
#ifdef F_sceVfpu_0021
	IMPORT_FUNC  "sceVfpu", 0x3BBF0BD5, sceVfpuVector3Round
#endif
#ifdef F_sceVfpu_0022
	IMPORT_FUNC  "sceVfpu", 0x839DF9E1, sceVfpuVector4Round
#endif
#ifdef F_sceVfpu_0023
	IMPORT_FUNC  "sceVfpu", 0xEAFA1BC0, sceVfpuVector2Floor
#endif
#ifdef F_sceVfpu_0024
	IMPORT_FUNC  "sceVfpu", 0xED06F118, sceVfpuVector3Floor
#endif
#ifdef F_sceVfpu_0025
	IMPORT_FUNC  "sceVfpu", 0x8049B8DF, sceVfpuVector4Floor
#endif
#ifdef F_sceVfpu_0026
	IMPORT_FUNC  "sceVfpu", 0x1F3AAFF2, sceVfpuVector2FromIVector
#endif
#ifdef F_sceVfpu_0027
	IMPORT_FUNC  "sceVfpu", 0x5341BF3B, sceVfpuVector3FromIVector
#endif
#ifdef F_sceVfpu_0028
	IMPORT_FUNC  "sceVfpu", 0x3A786605, sceVfpuVector4FromIVector
#endif
#ifdef F_sceVfpu_0029
	IMPORT_FUNC  "sceVfpu", 0xAA6E3AEA, sceVfpuVector2Add
#endif
#ifdef F_sceVfpu_0030
	IMPORT_FUNC  "sceVfpu", 0xD3890ECB, sceVfpuVector3Add
#endif
#ifdef F_sceVfpu_0031
	IMPORT_FUNC  "sceVfpu", 0x15BE7861, sceVfpuVector4Add
#endif
#ifdef F_sceVfpu_0032
	IMPORT_FUNC  "sceVfpu", 0x310DE5C7, sceVfpuVector4AddXYZ
#endif
#ifdef F_sceVfpu_0033
	IMPORT_FUNC  "sceVfpu", 0x8B52B60D, sceVfpuVector2Sub
#endif
#ifdef F_sceVfpu_0034
	IMPORT_FUNC  "sceVfpu", 0xE71B4A22, sceVfpuVector3Sub
#endif
#ifdef F_sceVfpu_0035
	IMPORT_FUNC  "sceVfpu", 0xBC1D779C, sceVfpuVector4Sub
#endif
#ifdef F_sceVfpu_0036
	IMPORT_FUNC  "sceVfpu", 0x23E473A6, sceVfpuVector4SubXYZ
#endif
#ifdef F_sceVfpu_0037
	IMPORT_FUNC  "sceVfpu", 0x8A435D84, sceVfpuVector2Mul
#endif
#ifdef F_sceVfpu_0038
	IMPORT_FUNC  "sceVfpu", 0x37548694, sceVfpuVector3Mul
#endif
#ifdef F_sceVfpu_0039
	IMPORT_FUNC  "sceVfpu", 0x2314BC7B, sceVfpuVector4Mul
#endif
#ifdef F_sceVfpu_0040
	IMPORT_FUNC  "sceVfpu", 0x06F6A476, sceVfpuVector4MulXYZ
#endif
#ifdef F_sceVfpu_0041
	IMPORT_FUNC  "sceVfpu", 0x1D267982, sceVfpuVector2Div
#endif
#ifdef F_sceVfpu_0042
	IMPORT_FUNC  "sceVfpu", 0xCD1F4251, sceVfpuVector3Div
#endif
#ifdef F_sceVfpu_0043
	IMPORT_FUNC  "sceVfpu", 0x2C0929FE, sceVfpuVector4Div
#endif
#ifdef F_sceVfpu_0044
	IMPORT_FUNC  "sceVfpu", 0x5FCDA4DC, sceVfpuVector4DivXYZ
#endif
#ifdef F_sceVfpu_0045
	IMPORT_FUNC  "sceVfpu", 0x509A66E6, sceVfpuVector2Neg
#endif
#ifdef F_sceVfpu_0046
	IMPORT_FUNC  "sceVfpu", 0xA8EB39C9, sceVfpuVector3Neg
#endif
#ifdef F_sceVfpu_0047
	IMPORT_FUNC  "sceVfpu", 0xE0786B49, sceVfpuVector4Neg
#endif
#ifdef F_sceVfpu_0048
	IMPORT_FUNC  "sceVfpu", 0xE27E6E5E, sceVfpuVector2Abs
#endif
#ifdef F_sceVfpu_0049
	IMPORT_FUNC  "sceVfpu", 0x8BFD0B7B, sceVfpuVector3Abs
#endif
#ifdef F_sceVfpu_0050
	IMPORT_FUNC  "sceVfpu", 0xDDEE7637, sceVfpuVector4Abs
#endif
#ifdef F_sceVfpu_0051
	IMPORT_FUNC  "sceVfpu", 0x633C134B, sceVfpuVector2Clamp
#endif
#ifdef F_sceVfpu_0052
	IMPORT_FUNC  "sceVfpu", 0xD0B3477A, sceVfpuVector3Clamp
#endif
#ifdef F_sceVfpu_0053
	IMPORT_FUNC  "sceVfpu", 0xE0277A7D, sceVfpuVector4Clamp
#endif
#ifdef F_sceVfpu_0054
	IMPORT_FUNC  "sceVfpu", 0xE60A581A, sceVfpuVector4ClampXYZ
#endif
#ifdef F_sceVfpu_0055
	IMPORT_FUNC  "sceVfpu", 0x34796DBE, sceVfpuVector2Max
#endif
#ifdef F_sceVfpu_0056
	IMPORT_FUNC  "sceVfpu", 0x6F0F019C, sceVfpuVector3Max
#endif
#ifdef F_sceVfpu_0057
	IMPORT_FUNC  "sceVfpu", 0x5705C256, sceVfpuVector4Max
#endif
#ifdef F_sceVfpu_0058
	IMPORT_FUNC  "sceVfpu", 0x21F68B7A, sceVfpuVector2Min
#endif
#ifdef F_sceVfpu_0059
	IMPORT_FUNC  "sceVfpu", 0x43DDAC30, sceVfpuVector3Min
#endif
#ifdef F_sceVfpu_0060
	IMPORT_FUNC  "sceVfpu", 0xBC31AC59, sceVfpuVector4Min
#endif
#ifdef F_sceVfpu_0061
	IMPORT_FUNC  "sceVfpu", 0xF5477BCF, sceVfpuVector2Scale
#endif
#ifdef F_sceVfpu_0062
	IMPORT_FUNC  "sceVfpu", 0xBA5DC138, sceVfpuVector3Scale
#endif
#ifdef F_sceVfpu_0063
	IMPORT_FUNC  "sceVfpu", 0xA025F5D0, sceVfpuVector4Scale
#endif
#ifdef F_sceVfpu_0064
	IMPORT_FUNC  "sceVfpu", 0x8E537509, sceVfpuVector4ScaleXYZ
#endif
#ifdef F_sceVfpu_0065
	IMPORT_FUNC  "sceVfpu", 0x006C8EE8, sceVfpuVector2Lerp
#endif
#ifdef F_sceVfpu_0066
	IMPORT_FUNC  "sceVfpu", 0x64CE5F24, sceVfpuVector3Lerp
#endif
#ifdef F_sceVfpu_0067
	IMPORT_FUNC  "sceVfpu", 0x7BCB8905, sceVfpuVector4Lerp
#endif
#ifdef F_sceVfpu_0068
	IMPORT_FUNC  "sceVfpu", 0xACCDB524, sceVfpuVector4LerpXYZ
#endif
#ifdef F_sceVfpu_0069
	IMPORT_FUNC  "sceVfpu", 0xBB54BCFE, sceVfpuVector2InnerProduct
#endif
#ifdef F_sceVfpu_0070
	IMPORT_FUNC  "sceVfpu", 0x12DA0DE2, sceVfpuVector3InnerProduct
#endif
#ifdef F_sceVfpu_0071
	IMPORT_FUNC  "sceVfpu", 0x538A2A9D, sceVfpuVector4InnerProduct
#endif
#ifdef F_sceVfpu_0072
	IMPORT_FUNC  "sceVfpu", 0x0C27DC4A, sceVfpuVector4InnerProductXYZ
#endif
#ifdef F_sceVfpu_0073
	IMPORT_FUNC  "sceVfpu", 0x44AF2C28, sceVfpuVector3OuterProduct
#endif
#ifdef F_sceVfpu_0074
	IMPORT_FUNC  "sceVfpu", 0xF16047DB, sceVfpuVector4OuterProductXYZ
#endif
#ifdef F_sceVfpu_0075
	IMPORT_FUNC  "sceVfpu", 0x29DE8D72, sceVfpuVector2Funnel
#endif
#ifdef F_sceVfpu_0076
	IMPORT_FUNC  "sceVfpu", 0x491FAF71, sceVfpuVector3Funnel
#endif
#ifdef F_sceVfpu_0077
	IMPORT_FUNC  "sceVfpu", 0xBB238B83, sceVfpuVector4Funnel
#endif
#ifdef F_sceVfpu_0078
	IMPORT_FUNC  "sceVfpu", 0xE3A55ECE, sceVfpuVector2Average
#endif
#ifdef F_sceVfpu_0079
	IMPORT_FUNC  "sceVfpu", 0xEAF270E3, sceVfpuVector3Average
#endif
#ifdef F_sceVfpu_0080
	IMPORT_FUNC  "sceVfpu", 0x32CB111B, sceVfpuVector4Average
#endif
#ifdef F_sceVfpu_0081
	IMPORT_FUNC  "sceVfpu", 0x0A9B32C8, sceVfpuVector2IsEqual
#endif
#ifdef F_sceVfpu_0082
	IMPORT_FUNC  "sceVfpu", 0xAE579B2F, sceVfpuVector3IsEqual
#endif
#ifdef F_sceVfpu_0083
	IMPORT_FUNC  "sceVfpu", 0x94C81EE5, sceVfpuVector4IsEqual
#endif
#ifdef F_sceVfpu_0084
	IMPORT_FUNC  "sceVfpu", 0x65F6CB75, sceVfpuVector2IsZero
#endif
#ifdef F_sceVfpu_0085
	IMPORT_FUNC  "sceVfpu", 0x42DAB93C, sceVfpuVector3IsZero
#endif
#ifdef F_sceVfpu_0086
	IMPORT_FUNC  "sceVfpu", 0xD5A72405, sceVfpuVector4IsZero
#endif
#ifdef F_sceVfpu_0087
	IMPORT_FUNC  "sceVfpu", 0x25392D5A, sceVfpuVector2SignFloat
#endif
#ifdef F_sceVfpu_0088
	IMPORT_FUNC  "sceVfpu", 0x56DA956A, sceVfpuVector3SignFloat
#endif
#ifdef F_sceVfpu_0089
	IMPORT_FUNC  "sceVfpu", 0x6A99CCE6, sceVfpuVector4SignFloat
#endif
#ifdef F_sceVfpu_0090
	IMPORT_FUNC  "sceVfpu", 0x25D8DB5C, sceVfpuVector2SignInt
#endif
#ifdef F_sceVfpu_0091
	IMPORT_FUNC  "sceVfpu", 0x9CB86EC7, sceVfpuVector3SignInt
#endif
#ifdef F_sceVfpu_0092
	IMPORT_FUNC  "sceVfpu", 0x30E4D15E, sceVfpuVector4SignInt
#endif
#ifdef F_sceVfpu_0093
	IMPORT_FUNC  "sceVfpu", 0x803FC64B, sceVfpuVector2Normalize
#endif
#ifdef F_sceVfpu_0094
	IMPORT_FUNC  "sceVfpu", 0x767DE7AB, sceVfpuVector3Normalize
#endif
#ifdef F_sceVfpu_0095
	IMPORT_FUNC  "sceVfpu", 0xC5F4027B, sceVfpuVector4Normalize
#endif
#ifdef F_sceVfpu_0096
	IMPORT_FUNC  "sceVfpu", 0x1FE543F1, sceVfpuVector4NormalizeXYZ
#endif
#ifdef F_sceVfpu_0097
	IMPORT_FUNC  "sceVfpu", 0xF5974E2F, sceVfpuVector2Lengthpfv
#endif
#ifdef F_sceVfpu_0098
	IMPORT_FUNC  "sceVfpu", 0x4089A54A, sceVfpuVector3Lengthpfv
#endif
#ifdef F_sceVfpu_0099
	IMPORT_FUNC  "sceVfpu", 0x3AC1AA5D, sceVfpuVector4LengthXYZpfv
#endif
#ifdef F_sceVfpu_0100
	IMPORT_FUNC  "sceVfpu", 0xAA923EC4, sceVfpuVector2Distance
#endif
#ifdef F_sceVfpu_0101
	IMPORT_FUNC  "sceVfpu", 0xFEA9D478, sceVfpuVector3Distance
#endif
#ifdef F_sceVfpu_0102
	IMPORT_FUNC  "sceVfpu", 0xC2CD822B, sceVfpuVector4DistanceXYZ
#endif
#ifdef F_sceVfpu_0103
	IMPORT_FUNC  "sceVfpu", 0x67C2A9DD, sceVfpuVector4NormalizePhase
#endif
#ifdef F_sceVfpu_0104
	IMPORT_FUNC  "sceVfpu", 0xCD183209, sceVfpuVector2FaceForward
#endif
#ifdef F_sceVfpu_0105
	IMPORT_FUNC  "sceVfpu", 0xB4549A82, sceVfpuVector3FaceForward
#endif
#ifdef F_sceVfpu_0106
	IMPORT_FUNC  "sceVfpu", 0xEE9B684B, sceVfpuVector2FaceForwardXYZ
#endif
#ifdef F_sceVfpu_0107
	IMPORT_FUNC  "sceVfpu", 0x75920079, sceVfpuVector2Reflect
#endif
#ifdef F_sceVfpu_0108
	IMPORT_FUNC  "sceVfpu", 0xDA6A6F46, sceVfpuVector3Reflect
#endif
#ifdef F_sceVfpu_0109
	IMPORT_FUNC  "sceVfpu", 0xA4165834, sceVfpuVector4ReflectXYZ
#endif
#ifdef F_sceVfpu_0110
	IMPORT_FUNC  "sceVfpu", 0xD0A188B5, sceVfpuVector2Refract
#endif
#ifdef F_sceVfpu_0111
	IMPORT_FUNC  "sceVfpu", 0x25BB1549, sceVfpuVector3Refract
#endif
#ifdef F_sceVfpu_0112
	IMPORT_FUNC  "sceVfpu", 0x19423BCA, sceVfpuVector4RefractXYZ
#endif
#ifdef F_sceVfpu_0113
	IMPORT_FUNC  "sceVfpu", 0x500B1756, sceVfpuMatrix2Unit
#endif
#ifdef F_sceVfpu_0114
	IMPORT_FUNC  "sceVfpu", 0x29D1B9D5, sceVfpuMatrix3Unit
#endif
#ifdef F_sceVfpu_0115
	IMPORT_FUNC  "sceVfpu", 0x13A603EB, sceVfpuMatrix4Unit
#endif
#ifdef F_sceVfpu_0116
	IMPORT_FUNC  "sceVfpu", 0xFD0887C4, sceVfpuMatrix2Zero
#endif
#ifdef F_sceVfpu_0117
	IMPORT_FUNC  "sceVfpu", 0xECAAC680, sceVfpuMatrix3Zero
#endif
#ifdef F_sceVfpu_0118
	IMPORT_FUNC  "sceVfpu", 0xBE792119, sceVfpuMatrix4Zero
#endif
#ifdef F_sceVfpu_0119
	IMPORT_FUNC  "sceVfpu", 0xBD6A07AE, sceVfpuMatrix2Copy
#endif
#ifdef F_sceVfpu_0120
	IMPORT_FUNC  "sceVfpu", 0x5DE2FCC0, sceVfpuMatrix3Copy
#endif
#ifdef F_sceVfpu_0121
	IMPORT_FUNC  "sceVfpu", 0x91EFFDC1, sceVfpuMatrix4Copy
#endif
#ifdef F_sceVfpu_0122
	IMPORT_FUNC  "sceVfpu", 0xA5BB7508, sceVfpuMatrix2Apply
#endif
#ifdef F_sceVfpu_0123
	IMPORT_FUNC  "sceVfpu", 0x6F6862D7, sceVfpuMatrix3Apply
#endif
#ifdef F_sceVfpu_0124
	IMPORT_FUNC  "sceVfpu", 0xCF146FC4, sceVfpuMatrix4Apply
#endif
#ifdef F_sceVfpu_0125
	IMPORT_FUNC  "sceVfpu", 0x82596212, sceVfpuMatrix4ApplyXYZ
#endif
#ifdef F_sceVfpu_0126
	IMPORT_FUNC  "sceVfpu", 0xE537EF14, sceVfpuMatrix2Mul
#endif
#ifdef F_sceVfpu_0127
	IMPORT_FUNC  "sceVfpu", 0x7C331AE4, sceVfpuMatrix3Mul
#endif
#ifdef F_sceVfpu_0128
	IMPORT_FUNC  "sceVfpu", 0xD697947E, sceVfpuMatrix4Mul
#endif
#ifdef F_sceVfpu_0129
	IMPORT_FUNC  "sceVfpu", 0xBD585F5E, sceVfpuMatrix2Scale
#endif
#ifdef F_sceVfpu_0130
	IMPORT_FUNC  "sceVfpu", 0xEE9A0DEC, sceVfpuMatrix3Scale
#endif
#ifdef F_sceVfpu_0131
	IMPORT_FUNC  "sceVfpu", 0x98709196, sceVfpuMatrix4Scale
#endif
#ifdef F_sceVfpu_0132
	IMPORT_FUNC  "sceVfpu", 0x1192AA93, sceVfpuMatrix2Transpose
#endif
#ifdef F_sceVfpu_0133
	IMPORT_FUNC  "sceVfpu", 0x29FE3E73, sceVfpuMatrix3Transpose
#endif
#ifdef F_sceVfpu_0134
	IMPORT_FUNC  "sceVfpu", 0x3325AA47, sceVfpuMatrix4Transpose
#endif
#ifdef F_sceVfpu_0135
	IMPORT_FUNC  "sceVfpu", 0x059281D4, sceVfpuMatrix4Inverse
#endif
#ifdef F_sceVfpu_0136
	IMPORT_FUNC  "sceVfpu", 0xB327C8B9, sceVfpuMatrix3Normalize
#endif
#ifdef F_sceVfpu_0137
	IMPORT_FUNC  "sceVfpu", 0x26168205, sceVfpuMatrix4NormalizeXYZ
#endif
#ifdef F_sceVfpu_0138
	IMPORT_FUNC  "sceVfpu", 0x158364F1, sceVfpuMatrix2RotZ
#endif
#ifdef F_sceVfpu_0139
	IMPORT_FUNC  "sceVfpu", 0xB0BADD91, sceVfpuMatrix3RotX
#endif
#ifdef F_sceVfpu_0140
	IMPORT_FUNC  "sceVfpu", 0xD63C9E95, sceVfpuMatrix3RotY
#endif
#ifdef F_sceVfpu_0141
	IMPORT_FUNC  "sceVfpu", 0x73918516, sceVfpuMatrix3RotZ
#endif
#ifdef F_sceVfpu_0142
	IMPORT_FUNC  "sceVfpu", 0x37562668, sceVfpuMatrix3Rot
#endif
#ifdef F_sceVfpu_0143
	IMPORT_FUNC  "sceVfpu", 0x45D54BCF, sceVfpuMatrix4RotX
#endif
#ifdef F_sceVfpu_0144
	IMPORT_FUNC  "sceVfpu", 0x8B0A8B96, sceVfpuMatrix4RotY
#endif
#ifdef F_sceVfpu_0145
	IMPORT_FUNC  "sceVfpu", 0x27511CE0, sceVfpuMatrix4RotZ
#endif
#ifdef F_sceVfpu_0146
	IMPORT_FUNC  "sceVfpu", 0x95739712, sceVfpuMatrix4Rot
#endif
#ifdef F_sceVfpu_0147
	IMPORT_FUNC  "sceVfpu", 0x6786E0EF, sceVfpuMatrix4Transfer
#endif
#ifdef F_sceVfpu_0148
	IMPORT_FUNC  "sceVfpu", 0x10601B88, sceVfpuMatrix4SetTransfer
#endif
#ifdef F_sceVfpu_0149
	IMPORT_FUNC  "sceVfpu", 0x1B9FDB6F, sceVfpuMatrix4GetTransfer
#endif
#ifdef F_sceVfpu_0150
	IMPORT_FUNC  "sceVfpu", 0x533C4C02, sceVfpuMatrix2IsUnit
#endif
#ifdef F_sceVfpu_0151
	IMPORT_FUNC  "sceVfpu", 0xB3B9BF75, sceVfpuMatrix3IsUnit
#endif
#ifdef F_sceVfpu_0152
	IMPORT_FUNC  "sceVfpu", 0x2D146EC7, sceVfpuMatrix4IsUnit
#endif
#ifdef F_sceVfpu_0153
	IMPORT_FUNC  "sceVfpu", 0x5DCA22C2, sceVfpuMatrix2Trace
#endif
#ifdef F_sceVfpu_0154
	IMPORT_FUNC  "sceVfpu", 0x5744BFB1, sceVfpuMatrix3Trace
#endif
#ifdef F_sceVfpu_0155
	IMPORT_FUNC  "sceVfpu", 0x187E033E, sceVfpuMatrix4Trace
#endif
#ifdef F_sceVfpu_0156
	IMPORT_FUNC  "sceVfpu", 0xCF75DBDF, sceVfpuMatrix2Determinant
#endif
#ifdef F_sceVfpu_0157
	IMPORT_FUNC  "sceVfpu", 0xEBBBD96E, sceVfpuMatrix3Determinant
#endif
#ifdef F_sceVfpu_0158
	IMPORT_FUNC  "sceVfpu", 0x538D8F89, sceVfpuMatrix4Determinant
#endif
#ifdef F_sceVfpu_0159
	IMPORT_FUNC  "sceVfpu", 0xE57BB5C2, sceVfpuMatrix2Adjoint
#endif
#ifdef F_sceVfpu_0160
	IMPORT_FUNC  "sceVfpu", 0xCE2F1A73, sceVfpuMatrix3Adjoint
#endif
#ifdef F_sceVfpu_0161
	IMPORT_FUNC  "sceVfpu", 0x732C4F28, sceVfpuMatrix4Adjoint
#endif
#ifdef F_sceVfpu_0162
	IMPORT_FUNC  "sceVfpu", 0x3F998799, sceVfpuQuaternionUnit
#endif
#ifdef F_sceVfpu_0163
	IMPORT_FUNC  "sceVfpu", 0xA6344995, sceVfpuQuaternionCopy
#endif
#ifdef F_sceVfpu_0164
	IMPORT_FUNC  "sceVfpu", 0xB693AF8E, sceVfpuQuaternionToMatrix
#endif
#ifdef F_sceVfpu_0165
	IMPORT_FUNC  "sceVfpu", 0xA6A079E8, sceVfpuQuaternionApply
#endif
#ifdef F_sceVfpu_0166
	IMPORT_FUNC  "sceVfpu", 0x1BAA2B93, sceVfpuQuaternionAdd
#endif
#ifdef F_sceVfpu_0167
	IMPORT_FUNC  "sceVfpu", 0x32F52CAC, sceVfpuQuaternionSub
#endif
#ifdef F_sceVfpu_0168
	IMPORT_FUNC  "sceVfpu", 0x8C23C415, sceVfpuQuaternionMul
#endif
#ifdef F_sceVfpu_0169
	IMPORT_FUNC  "sceVfpu", 0x9F5F98AB, sceVfpuQuaternionInnerProduct
#endif
#ifdef F_sceVfpu_0170
	IMPORT_FUNC  "sceVfpu", 0x660F96F4, sceVfpuQuaternionSlerp
#endif
#ifdef F_sceVfpu_0171
	IMPORT_FUNC  "sceVfpu", 0xB079A5D1, sceVfpuQuaternionSquad
#endif
#ifdef F_sceVfpu_0172
	IMPORT_FUNC  "sceVfpu", 0x9460BD06, sceVfpuQuaternionNormalize
#endif
#ifdef F_sceVfpu_0173
	IMPORT_FUNC  "sceVfpu", 0x5C2835DE, sceVfpuQuaternionConj
#endif
#ifdef F_sceVfpu_0174
	IMPORT_FUNC  "sceVfpu", 0x966FBCFA, sceVfpuQuaternionInverse
#endif
#ifdef F_sceVfpu_0175
	IMPORT_FUNC  "sceVfpu", 0xA2C4E735, sceVfpuQuaternionFromMatrix
#endif
#ifdef F_sceVfpu_0176
	IMPORT_FUNC  "sceVfpu", 0xE8EA9D7C, sceVfpuQuaternionFromRotZYX
#endif
#ifdef F_sceVfpu_0177
	IMPORT_FUNC  "sceVfpu", 0x0EBB4C05, sceVfpuQuaternionFromRotXYZ
#endif
#ifdef F_sceVfpu_0178
	IMPORT_FUNC  "sceVfpu", 0x9ED79CEA, sceVfpuQuaternionFromRotYXZ
#endif
#ifdef F_sceVfpu_0179
	IMPORT_FUNC  "sceVfpu", 0xC87E4924, sceVfpuQuaternionFromRotate
#endif
#ifdef F_sceVfpu_0180
	IMPORT_FUNC  "sceVfpu", 0xEA203626, sceVfpuQuaternionToRotZYX
#endif
#ifdef F_sceVfpu_0181
	IMPORT_FUNC  "sceVfpu", 0xB5179384, sceVfpuQuaternionToRotYXZ
#endif
#ifdef F_sceVfpu_0182
	IMPORT_FUNC  "sceVfpu", 0x38401656, sceVfpuColorToRGBA8888
#endif
#ifdef F_sceVfpu_0183
	IMPORT_FUNC  "sceVfpu", 0x85EBD3B4, sceVfpuColorToRGBA4444
#endif
#ifdef F_sceVfpu_0184
	IMPORT_FUNC  "sceVfpu", 0x1ABDBABF, sceVfpuColorToRGBA5551
#endif
#ifdef F_sceVfpu_0185
	IMPORT_FUNC  "sceVfpu", 0x33FDC8BA, sceVfpuColorToRGB565
#endif
#ifdef F_sceVfpu_0186
	IMPORT_FUNC  "sceVfpu", 0x94F364BA, sceVfpuColorFromRGBA8888
#endif
#ifdef F_sceVfpu_0187
	IMPORT_FUNC  "sceVfpu", 0x0B93F1FE, sceVfpuColorFromRGBA4444
#endif
#ifdef F_sceVfpu_0188
	IMPORT_FUNC  "sceVfpu", 0x01B0C3EE, sceVfpuColorFromRGBA5551
#endif
#ifdef F_sceVfpu_0189
	IMPORT_FUNC  "sceVfpu", 0xF99533C5, sceVfpuColorFromRGB565
#endif
#ifdef F_sceVfpu_0190
	IMPORT_FUNC  "sceVfpu", 0x31EA10A8, sceVfpuColorZero
#endif
#ifdef F_sceVfpu_0191
	IMPORT_FUNC  "sceVfpu", 0x633728A5, sceVfpuColorSet
#endif
#ifdef F_sceVfpu_0192
	IMPORT_FUNC  "sceVfpu", 0xA27FD171, sceVfpuColorSetRGB
#endif
#ifdef F_sceVfpu_0193
	IMPORT_FUNC  "sceVfpu", 0xCE7D2C9E, sceVfpuColorCopy
#endif
#ifdef F_sceVfpu_0194
	IMPORT_FUNC  "sceVfpu", 0xB1682E28, sceVfpuColorAdd
#endif
#ifdef F_sceVfpu_0195
	IMPORT_FUNC  "sceVfpu", 0x0ECB8E01, sceVfpuColorAddRGB
#endif
#ifdef F_sceVfpu_0196
	IMPORT_FUNC  "sceVfpu", 0x5606B326, sceVfpuColorSub
#endif
#ifdef F_sceVfpu_0197
	IMPORT_FUNC  "sceVfpu", 0x3E4223FE, sceVfpuColorSubRGB
#endif
#ifdef F_sceVfpu_0198
	IMPORT_FUNC  "sceVfpu", 0x4877BD68, sceVfpuColorMul
#endif
#ifdef F_sceVfpu_0199
	IMPORT_FUNC  "sceVfpu", 0x4056A4DA, sceVfpuColorMulRGB
#endif
#ifdef F_sceVfpu_0200
	IMPORT_FUNC  "sceVfpu", 0xD250640E, sceVfpuColorNeg
#endif
#ifdef F_sceVfpu_0201
	IMPORT_FUNC  "sceVfpu", 0xF7BCED2E, sceVfpuColorNegRGB
#endif
#ifdef F_sceVfpu_0202
	IMPORT_FUNC  "sceVfpu", 0xE758A14F, sceVfpuColorLerp
#endif
#ifdef F_sceVfpu_0203
	IMPORT_FUNC  "sceVfpu", 0x89165328, sceVfpuColorLerpRGB
#endif
#ifdef F_sceVfpu_0204
	IMPORT_FUNC  "sceVfpu", 0xECCB2666, sceVfpuColorScale
#endif
#ifdef F_sceVfpu_0205
	IMPORT_FUNC  "sceVfpu", 0x6FD8157A, sceVfpuColorScaleRGB
#endif
#ifdef F_sceVfpu_0206
	IMPORT_FUNC  "sceVfpu", 0xDE3AFA05, sceVfpuColorClamp
#endif
#ifdef F_sceVfpu_0207
	IMPORT_FUNC  "sceVfpu", 0x58DCA3EF, sceVfpuColorClampRGB
#endif
#ifdef F_sceVfpu_0208
	IMPORT_FUNC  "sceVfpu", 0xD0DF548E, sceVfpuColorMax
#endif
#ifdef F_sceVfpu_0209
	IMPORT_FUNC  "sceVfpu", 0xF412CF9E, sceVfpuColorMin
#endif
#ifdef F_sceVfpu_0210
	IMPORT_FUNC  "sceVfpu", 0x6B7AF67C, sceVfpuColorIsEqual
#endif
#ifdef F_sceVfpu_0211
	IMPORT_FUNC  "sceVfpu", 0x85F55944, sceVfpuColorIsZero
#endif
#ifdef F_sceVfpu_0212
	IMPORT_FUNC  "sceVfpu", 0xF7A9960F, sceVfpuColorNormalize
#endif
#ifdef F_sceVfpu_0213
	IMPORT_FUNC  "sceVfpu", 0x4858BC84, sceVfpuColorNormalizeRGB
#endif
#ifdef F_sceVfpu_0214
	IMPORT_FUNC  "sceVfpu", 0x317716E5, sceVfpuScalarAbs
#endif
#ifdef F_sceVfpu_0215
	IMPORT_FUNC  "sceVfpu", 0xFE7BDE64, sceVfpuScalarAcos
#endif
#ifdef F_sceVfpu_0216
	IMPORT_FUNC  "sceVfpu", 0x5C4E84AA, sceVfpuScalarAsin
#endif
#ifdef F_sceVfpu_0217
	IMPORT_FUNC  "sceVfpu", 0x0A0CC3A4, sceVfpuScalarCeil
#endif
#ifdef F_sceVfpu_0218
	IMPORT_FUNC  "sceVfpu", 0x7D880441, sceVfpuScalarCos
#endif
#ifdef F_sceVfpu_0219
	IMPORT_FUNC  "sceVfpu", 0xD829D719, sceVfpuScalarExp
#endif
#ifdef F_sceVfpu_0220
	IMPORT_FUNC  "sceVfpu", 0x6C97C2FD, sceVfpuScalarFloor
#endif
#ifdef F_sceVfpu_0221
	IMPORT_FUNC  "sceVfpu", 0x1C922D69, sceVfpuScalarLog
#endif
#ifdef F_sceVfpu_0222
	IMPORT_FUNC  "sceVfpu", 0x880B3B57, sceVfpuScalarLog2
#endif
#ifdef F_sceVfpu_0223
	IMPORT_FUNC  "sceVfpu", 0xF1C199B4, sceVfpuScalarLog10
#endif
#ifdef F_sceVfpu_0224
	IMPORT_FUNC  "sceVfpu", 0xDA790D12, sceVfpuScalarMax
#endif
#ifdef F_sceVfpu_0225
	IMPORT_FUNC  "sceVfpu", 0x26F05781, sceVfpuScalarMin
#endif
#ifdef F_sceVfpu_0226
	IMPORT_FUNC  "sceVfpu", 0x424598D9, sceVfpuScalarPow
#endif
#ifdef F_sceVfpu_0227
	IMPORT_FUNC  "sceVfpu", 0x34592A20, sceVfpuScalarPow2
#endif
#ifdef F_sceVfpu_0228
	IMPORT_FUNC  "sceVfpu", 0x711AC797, sceVfpuScalarRound
#endif
#ifdef F_sceVfpu_0229
	IMPORT_FUNC  "sceVfpu", 0xC012BD05, sceVfpuScalarRsqrt
#endif
#ifdef F_sceVfpu_0230
	IMPORT_FUNC  "sceVfpu", 0x8637BCB2, sceVfpuScalarSin
#endif
#ifdef F_sceVfpu_0231
	IMPORT_FUNC  "sceVfpu", 0x8D0CE141, sceVfpuScalarSqrt
#endif
#ifdef F_sceVfpu_0232
	IMPORT_FUNC  "sceVfpu", 0x6CF80554, sceVfpuScalarTan
#endif
#ifdef F_sceVfpu_0233
	IMPORT_FUNC  "sceVfpu", 0x7A15809D, sceVfpuScalarTrunc
#endif
#ifdef F_sceVfpu_0234
	IMPORT_FUNC  "sceVfpu", 0xD0C4434B, sceVfpuRandSaveContext
#endif
#ifdef F_sceVfpu_0235
	IMPORT_FUNC  "sceVfpu", 0xFB137DE8, sceVfpuRandRestoreContext
#endif
#ifdef F_sceVfpu_0236
	IMPORT_FUNC  "sceVfpu", 0x156FE253, sceVfpuRandFloat
#endif
#ifdef F_sceVfpu_0237
	IMPORT_FUNC  "sceVfpu", 0xA845C069, sceVfpuRandPi
#endif
#ifdef F_sceVfpu_0238
	IMPORT_FUNC  "sceVfpu", 0x89160DF1, sceVfpuRandTwopi
#endif
#ifdef F_sceVfpu_0239
	IMPORT_FUNC  "sceVfpu", 0xCA9896F0, sceVfpuRandVector
#endif
#ifdef F_sceVfpu_0240
	IMPORT_FUNC  "sceVfpu", 0xB2DA8CC7, sceVfpuRandInt
#endif
#ifdef F_sceVfpu_0241
	IMPORT_FUNC  "sceVfpu", 0xB65A3F92, sceVfpuRandPeekFloat
#endif
#ifdef F_sceVfpu_0242
	IMPORT_FUNC  "sceVfpu", 0x44653809, sceVfpuLookAtMatrix
#endif
#ifdef F_sceVfpu_0243
	IMPORT_FUNC  "sceVfpu", 0x45A1EA6F, sceVfpuPerspectiveMatrix
#endif
#ifdef F_sceVfpu_0244
	IMPORT_FUNC  "sceVfpu", 0xB442C776, sceVfpuOrthoMatrix
#endif
#ifdef F_sceVfpu_0245
	IMPORT_FUNC  "sceVfpu", 0x59A406B3, sceVfpuCameraMatrix
#endif
#ifdef F_sceVfpu_0246
	IMPORT_FUNC  "sceVfpu", 0x0E65F6C2, sceVfpuViewScreenMatrix
#endif
#ifdef F_sceVfpu_0247
	IMPORT_FUNC  "sceVfpu", 0xB4C1C542, sceVfpuDropShadowMatrix
#endif
#ifdef F_sceVfpu_0248
	IMPORT_FUNC  "sceVfpu", 0x0962DB03, sceVfpuRotTransPers
#endif
#ifdef F_sceVfpu_0249
	IMPORT_FUNC  "sceVfpu", 0x1C2A2A76, sceVfpuRotTransPersN
#endif
