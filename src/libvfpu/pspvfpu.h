/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspvfpu.h - Prototypes for the libvfpu library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBVFPU_H__
#define __LIBVFPU_H__

#include <psptypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* initialize to zero vector  */
#define sceVfpuVector2Null(_pv)							sceVfpuVector2PositiveZero(_pv)
#define sceVfpuVector2Zero(_pv)							sceVfpuVector2PositiveZero(_pv)
#define sceVfpuVector3Null(_pv)							sceVfpuVector3PositiveZero(_pv)
#define sceVfpuVector3Zero(_pv)							sceVfpuVector3PositiveZero(_pv)
#define sceVfpuVector4Null(_pv)							sceVfpuVector4PositiveZero(_pv)
#define sceVfpuVector4Zero(_pv)							sceVfpuVector4PositiveZero(_pv)
scePspFVector2 *sceVfpuVector2PositiveZero(scePspFVector2 *pv);
scePspFVector3 *sceVfpuVector3PositiveZero(scePspFVector3 *pv);
scePspFVector4 *sceVfpuVector4PositiveZero(scePspFVector4 *pv);
scePspFVector2 *sceVfpuVector2NegativeZero(scePspFVector2 *pv);
scePspFVector3 *sceVfpuVector3NegativeZero(scePspFVector3 *pv);
scePspFVector4 *sceVfpuVector4NegativeZero(scePspFVector4 *pv);


/* set scePspFVector */
scePspFVector2 *sceVfpuVector2Set(scePspFVector2 *pv0, float x, float y);
scePspFVector3 *sceVfpuVector3Set(scePspFVector3 *pv0, float x, float y, float z);
scePspFVector4 *sceVfpuVector4Set(scePspFVector4 *pv0, float x, float y, float z, float w);
scePspFVector4 *sceVfpuVector4SetXYZ(scePspFVector4 *pv0, float x, float y, float z);

/* copy scePspFVector */
scePspFVector2 *sceVfpuVector2Copy(scePspFVector2 *pv0, const scePspFVector2 *pv1);
scePspFVector3 *sceVfpuVector3Copy(scePspFVector3 *pv0, const scePspFVector3 *pv1);
scePspFVector4 *sceVfpuVector4Copy(scePspFVector4 *pv0, const scePspFVector4 *pv1);

scePspIVector2 *sceVfpuVector2Ceil(scePspIVector2 *pv0, const scePspFVector2 *pv1);
scePspIVector3 *sceVfpuVector3Ceil(scePspIVector3 *pv0, const scePspFVector3 *pv1);
scePspIVector4 *sceVfpuVector4Ceil(scePspIVector4 *pv0, const scePspFVector4 *pv1);

scePspIVector2 *sceVfpuVector2Trunc(scePspIVector2 *pv0, const scePspFVector2 *pv1);
scePspIVector3 *sceVfpuVector3Trunc(scePspIVector3 *pv0, const scePspFVector3 *pv1);
scePspIVector4 *sceVfpuVector4Trunc(scePspIVector4 *pv0, const scePspFVector4 *pv1);

scePspIVector2 *sceVfpuVector2Round(scePspIVector2 *pv0, const scePspFVector2 *pv1);
scePspIVector3 *sceVfpuVector3Round(scePspIVector3 *pv0, const scePspFVector3 *pv1);
scePspIVector4 *sceVfpuVector4Round(scePspIVector4 *pv0, const scePspFVector4 *pv1);

scePspIVector2 *sceVfpuVector2Floor(scePspIVector2 *pv0, const scePspFVector2 *pv1);
scePspIVector3 *sceVfpuVector3Floor(scePspIVector3 *pv0, const scePspFVector3 *pv1);
scePspIVector4 *sceVfpuVector4Floor(scePspIVector4 *pv0, const scePspFVector4 *pv1);

scePspFVector2 *sceVfpuVector2FromIVector(scePspFVector2 *pv0, const scePspIVector2 *pv1);
scePspFVector3 *sceVfpuVector3FromIVector(scePspFVector3 *pv0, const scePspIVector3 *pv1);
scePspFVector4 *sceVfpuVector4FromIVector(scePspFVector4 *pv0, const scePspIVector4 *pv1);

/* Vector addtion */
scePspFVector2 *sceVfpuVector2Add(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2);
scePspFVector3 *sceVfpuVector3Add(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2);
scePspFVector4 *sceVfpuVector4Add(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Add X,Y and Z elements of 4D vectors */
scePspFVector4 *sceVfpuVector4AddXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Vector Subtraction */
#define sceVfpuVector2Subtract(_pv0, _pv1, _pv2)		sceVfpuVector2Sub(_pv0, _pv1, _pv2)
#define sceVfpuVector3Subtract(_pv0, _pv1, _pv2)		sceVfpuVector3Sub(_pv0, _pv1, _pv2)
#define sceVfpuVector4Subtract(_pv0, _pv1, _pv2)		sceVfpuVector4Sub(_pv0, _pv1, _pv2)
#define sceVfpuVector4SubtractXYZ(_pv0, _pv1, _pv2)		sceVfpuVector4SubXYZ(_pv0, _pv1, _pv2)
scePspFVector2 *sceVfpuVector2Sub(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2);
scePspFVector3 *sceVfpuVector3Sub(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2);
scePspFVector4 *sceVfpuVector4Sub(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Subtract X,Y and Z elements of 4D vectors */
scePspFVector4 *sceVfpuVector4SubXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Vector multiplication */
#define sceVfpuVector2Multiply(_pv0, _pv1, _pv2)		sceVfpuVector2Mul(_pv0, _pv1, _pv2)
#define sceVfpuVector3Multiply(_pv0, _pv1, _pv2)		sceVfpuVector3Mul(_pv0, _pv1, _pv2)
#define sceVfpuVector4Multiply(_pv0, _pv1, _pv2)		sceVfpuVector4Mul(_pv0, _pv1, _pv2)
#define sceVfpuVector4MultiplyXYZ(_pv0, _pv1, _pv2)		sceVfpuVector4MulXYZ(_pv0, _pv1, _pv2)
scePspFVector2 *sceVfpuVector2Mul(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2);
scePspFVector3 *sceVfpuVector3Mul(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2);
scePspFVector4 *sceVfpuVector4Mul(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Multiply X,Y and Z elements of 4D vectors */
scePspFVector4 *sceVfpuVector4MulXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Vector division */
#define sceVfpuVector2Divide(_pv0, _pv1, _pv2)			sceVfpuVector2Div(_pv0, _pv1, _pv2)
#define sceVfpuVector3Divide(_pv0, _pv1, _pv2)			sceVfpuVector3Div(_pv0, _pv1, _pv2)
#define sceVfpuVector4Divide(_pv0, _pv1, _pv2)			sceVfpuVector4Div(_pv0, _pv1, _pv2)
#define sceVfpuVector4DivideXYZ(_pv0, _pv1, _pv2)		sceVfpuVector4DivXYZ(_pv0, _pv1, _pv2)
scePspFVector2 *sceVfpuVector2Div(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2);
scePspFVector3 *sceVfpuVector3Div(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2);
scePspFVector4 *sceVfpuVector4Div(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Divide X,Y and Z elements of 4D vectors */
scePspFVector4 *sceVfpuVector4DivXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);


/* Vector sign reversal */
scePspFVector2 *sceVfpuVector2Neg(scePspFVector2 *pv0, const scePspFVector2 *pv1);
scePspFVector3 *sceVfpuVector3Neg(scePspFVector3 *pv0, const scePspFVector3 *pv1);
scePspFVector4 *sceVfpuVector4Neg(scePspFVector4 *pv0, const scePspFVector4 *pv1);

/* Vector absolute value */
scePspFVector2 *sceVfpuVector2Abs(scePspFVector2 *pv0, const scePspFVector2 *pv1);
scePspFVector3 *sceVfpuVector3Abs(scePspFVector3 *pv0, const scePspFVector3 *pv1);
scePspFVector4 *sceVfpuVector4Abs(scePspFVector4 *pv0, const scePspFVector4 *pv1);

/* Vector clamp */
scePspFVector2 *sceVfpuVector2Clamp(scePspFVector2 *pv0, const scePspFVector2 *pv1, float min, float max);
scePspFVector3 *sceVfpuVector3Clamp(scePspFVector3 *pv0, const scePspFVector3 *pv1, float min, float max);
scePspFVector4 *sceVfpuVector4Clamp(scePspFVector4 *pv0, const scePspFVector4 *pv1, float min, float max);

/* Clamp X,Y and Z elements of 4D vectors */
scePspFVector4 *sceVfpuVector4ClampXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, float min, float max);

/* Maximum value */
scePspFVector2 *sceVfpuVector2Max(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2);
scePspFVector3 *sceVfpuVector3Max(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2);
scePspFVector4 *sceVfpuVector4Max(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Minimum value */
scePspFVector2 *sceVfpuVector2Min(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2);
scePspFVector3 *sceVfpuVector3Min(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2);
scePspFVector4 *sceVfpuVector4Min(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Multiplication of vector by scalar */
scePspFVector2 *sceVfpuVector2Scale(scePspFVector2 *pv0, const scePspFVector2 *pv1, float s);
scePspFVector3 *sceVfpuVector3Scale(scePspFVector3 *pv0, const scePspFVector3 *pv1, float s);
scePspFVector4 *sceVfpuVector4Scale(scePspFVector4 *pv0, const scePspFVector4 *pv1, float s);

/* Multiply X,Y and Z elements of 4D vector by scalar */
scePspFVector4 *sceVfpuVector4ScaleXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, float s);

/* Generate interpolation vector */
#define sceVfpuVector2Inter(_pv0,_pv1,_pv2,_t)		sceVfpuVector2Lerp(_pv0,_pv1,_pv2,(1.0f - (_t)))
#define sceVfpuVector3Inter(_pv0,_pv1,_pv2,_t)		sceVfpuVector3Lerp(_pv0,_pv1,_pv2,(1.0f - (_t)))
#define sceVfpuVector4Inter(_pv0,_pv1,_pv2,_t)		sceVfpuVector4Lerp(_pv0,_pv1,_pv2,(1.0f - (_t)))
scePspFVector2 *sceVfpuVector2Lerp(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2, float t);
scePspFVector3 *sceVfpuVector3Lerp(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2, float t);
scePspFVector4 *sceVfpuVector4Lerp(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2, float t);

/* Generate interpolation vector */
#define sceVfpuVector4InterXYZ(_pv0,_pv1,_pv2,_t)	sceVfpuVector4LerpXYZ(_pv0,_pv1,_pv2,(1.0f - (_t)))
scePspFVector4 *sceVfpuVector4LerpXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2, float t);

/* Vector inner product */
#define sceVfpuVector2Dot(_v1,_v2)						sceVfpuVector2InnerProduct(_v1,_v2)
#define sceVfpuVector3Dot(_v1,_v2)						sceVfpuVector3InnerProduct(_v1,_v2)
#define sceVfpuVector4Dot(_v1,_v2)						sceVfpuVector4InnerProduct(_v1,_v2)
#define sceVfpuVector4DotXYZ(_v1,_v2)					sceVfpuVector4InnerProductXYZ(_v1,_v2)
float sceVfpuVector2InnerProduct(const scePspFVector2 *pv1, const scePspFVector2 *pv2);
float sceVfpuVector3InnerProduct(const scePspFVector3 *pv1, const scePspFVector3 *pv2);
float sceVfpuVector4InnerProduct(const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Vector inner product */
float sceVfpuVector4InnerProductXYZ(const scePspFVector4 *pv1, const scePspFVector4 *pv2);

/* Vector outer product */
#define sceVfpuVector3Cross(_v0,_v1, _v2)				sceVfpuVector3OuterProduct(_v0, _v1, _v2)
#define sceVfpuVector4Cross(_v0,_v1, _v2)				sceVfpuVector4OuterProductXYZ(_v0, _v1, _v2)
scePspFVector3 *sceVfpuVector3OuterProduct(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2);
scePspFVector4 *sceVfpuVector4OuterProductXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

float sceVfpuVector2Funnel(const scePspFVector2 *pv);
float sceVfpuVector3Funnel(const scePspFVector3 *pv);
float sceVfpuVector4Funnel(const scePspFVector4 *pv);

float sceVfpuVector2Average(const scePspFVector2 *pv);
float sceVfpuVector3Average(const scePspFVector3 *pv);
float sceVfpuVector4Average(const scePspFVector4 *pv);

sceBool sceVfpuVector2IsEqual(const scePspFVector2 *pv1, const scePspFVector2 *pv2);
sceBool sceVfpuVector3IsEqual(const scePspFVector3 *pv1, const scePspFVector3 *pv2);
sceBool sceVfpuVector4IsEqual(const scePspFVector4 *pv1, const scePspFVector4 *pv2);

#define sceVfpuVector2IsNull(_pv)	sceVfpuVector2IsZero(_pv)
sceBool sceVfpuVector2IsZero(const scePspFVector2 *pv0);

#define sceVfpuVector3IsNull(_pv)	sceVfpuVector3IsZero(_pv)
sceBool sceVfpuVector3IsZero(const scePspFVector3 *pv0);

#define sceVfpuVector4IsNull(_pv)	sceVfpuVector4IsZero(_pv)
sceBool sceVfpuVector4IsZero(const scePspFVector4 *pv0);

scePspFVector2 *sceVfpuVector2SignFloat(scePspFVector2 *pv0, const scePspFVector2 *pv1);
scePspFVector3 *sceVfpuVector3SignFloat(scePspFVector3 *pv0, const scePspFVector3 *pv1);
scePspFVector4 *sceVfpuVector4SignFloat(scePspFVector4 *pv0, const scePspFVector4 *pv1);

scePspIVector2 *sceVfpuVector2SignInt(scePspIVector2 *piv, const scePspFVector2 *pfv);
scePspIVector3 *sceVfpuVector3SignInt(scePspIVector3 *piv, const scePspFVector3 *pfv);
scePspIVector4 *sceVfpuVector4SignInt(scePspIVector4 *piv, const scePspFVector4 *pfv);

scePspFVector2 *sceVfpuVector2Normalize(scePspFVector2 *pv0, const scePspFVector2 *pv1);
scePspFVector3 *sceVfpuVector3Normalize(scePspFVector3 *pv0, const scePspFVector3 *pv1);
scePspFVector4 *sceVfpuVector4Normalize(scePspFVector4 *pv0, const scePspFVector4 *pv1);
scePspFVector4 *sceVfpuVector4NormalizeXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1);

float sceVfpuVector2Length(const scePspFVector2 *pfv);
float sceVfpuVector3Length(const scePspFVector3 *pfv);
float sceVfpuVector4LengthXYZ(const scePspFVector4 *pfv);

float sceVfpuVector2Distance(const scePspFVector2 *pv1, const scePspFVector2 *pv2);
float sceVfpuVector3Distance(const scePspFVector3 *pv1, const scePspFVector3 *pv2);
float sceVfpuVector4DistanceXYZ(const scePspFVector4 *pv1, const scePspFVector4 *pv2);

scePspFVector4 *sceVfpuVector4NormalizePhase(scePspFVector4 *pv0, const scePspFVector4 *pv1);


scePspFVector2 *sceVfpuVector2FaceForward(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2, const scePspFVector2 *pv3);
scePspFVector3 *sceVfpuVector3FaceForward(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2, const scePspFVector3 *pv3);
scePspFVector4 *sceVfpuVector2FaceForwardXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2, const scePspFVector4 *pv3);

scePspFVector2 *sceVfpuVector2Reflect(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2);
scePspFVector3 *sceVfpuVector3Reflect(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2);
scePspFVector4 *sceVfpuVector4ReflectXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2);

scePspFVector2 *sceVfpuVector2Refract(scePspFVector2 *pv0, const scePspFVector2 *pv1, const scePspFVector2 *pv2, float eta);
scePspFVector3 *sceVfpuVector3Refract(scePspFVector3 *pv0, const scePspFVector3 *pv1, const scePspFVector3 *pv2, float eta);
scePspFVector4 *sceVfpuVector4RefractXYZ(scePspFVector4 *pv0, const scePspFVector4 *pv1, const scePspFVector4 *pv2, float eta);


/* Generate unit matrix */
#define sceVfpuMatrix2Identity(_pm)							sceVfpuMatrix2Unit(_pm)
#define sceVfpuMatrix3Identity(_pm)							sceVfpuMatrix3Unit(_pm)
#define sceVfpuMatrix4Identity(_pm)							sceVfpuMatrix4Unit(_pm)
scePspFMatrix2 *sceVfpuMatrix2Unit(scePspFMatrix2 *pm);
scePspFMatrix3 *sceVfpuMatrix3Unit(scePspFMatrix3 *pm);
scePspFMatrix4 *sceVfpuMatrix4Unit(scePspFMatrix4 *pm);

/* Generate zero matrix */
#define sceVfpuMatrix2Null(_pm)								sceVfpuMatrix2Zero(_pm)
#define sceVfpuMatrix3Null(_pm)								sceVfpuMatrix3Zero(_pm)
#define sceVfpuMatrix4Null(_pm)								sceVfpuMatrix4Zero(_pm)
scePspFMatrix2 *sceVfpuMatrix2Zero(scePspFMatrix2 *pm);
scePspFMatrix3 *sceVfpuMatrix3Zero(scePspFMatrix3 *pm);
scePspFMatrix4 *sceVfpuMatrix4Zero(scePspFMatrix4 *pm);

/* Matrix copy */
scePspFMatrix2 *sceVfpuMatrix2Copy(scePspFMatrix2 *pm0, const scePspFMatrix2 *pm1);
scePspFMatrix3 *sceVfpuMatrix3Copy(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1);
scePspFMatrix4 *sceVfpuMatrix4Copy(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1);

/* Multiply matrix by vector */
scePspFVector2 *sceVfpuMatrix2Apply(scePspFVector2 *pv0, const scePspFMatrix2 *pm0, const scePspFVector2 *pv1);
scePspFVector3 *sceVfpuMatrix3Apply(scePspFVector3 *pv0, const scePspFMatrix3 *pm0, const scePspFVector3 *pv1);
scePspFVector4 *sceVfpuMatrix4Apply(scePspFVector4 *pv0, const scePspFMatrix4 *pm0, const scePspFVector4 *pv1);

/* Multiply matrix by vector */
scePspFVector4 *sceVfpuMatrix4ApplyXYZ(scePspFVector4 *pv0, const scePspFMatrix4 *pm0, const scePspFVector4 *pv1);

/* Matrix product */
scePspFMatrix2 *sceVfpuMatrix2Mul(scePspFMatrix2 *pm0, const scePspFMatrix2 *pm1, const scePspFMatrix2 *pm2);
scePspFMatrix3 *sceVfpuMatrix3Mul(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1, const scePspFMatrix3 *pm2);
scePspFMatrix4 *sceVfpuMatrix4Mul(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1, const scePspFMatrix4 *pm2);

scePspFMatrix2 *sceVfpuMatrix2Scale(scePspFMatrix2 *pm0, const scePspFMatrix2 *pm1, float s);
scePspFMatrix3 *sceVfpuMatrix3Scale(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1, float s);
scePspFMatrix4 *sceVfpuMatrix4Scale(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1, float s);

/* Multiply matrix by scalar */
scePspFMatrix2 *sceVfpuMatrix2Transpose(scePspFMatrix2 *pm0, const scePspFMatrix2 *pm1);
scePspFMatrix3 *sceVfpuMatrix3Transpose(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1);
scePspFMatrix4 *sceVfpuMatrix4Transpose(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1);

/* Generate inverse matrix */
#define sceVfpuMatrix4Invers(_m0,_m1)	sceVfpuMatrix4Inverse(_m0,_m1)
scePspFMatrix4 *sceVfpuMatrix4Inverse(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1);

/* Matrix normalization */
scePspFMatrix3 *sceVfpuMatrix3Normalize(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1);

/* Matrix normalization */
scePspFMatrix4 *sceVfpuMatrix4NormalizeXYZ(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1);

/* Matrix rotation */
scePspFMatrix2 *sceVfpuMatrix2RotZ(scePspFMatrix2 *pm0, const scePspFMatrix2 *pm1, float rz);

scePspFMatrix3 *sceVfpuMatrix3RotX(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1, float rx);
scePspFMatrix3 *sceVfpuMatrix3RotY(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1, float ry);
scePspFMatrix3 *sceVfpuMatrix3RotZ(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1, float rz);
scePspFMatrix3 *sceVfpuMatrix3Rot(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1, const scePspFVector3 *rot);

scePspFMatrix4 *sceVfpuMatrix4RotX(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1, float rx);
scePspFMatrix4 *sceVfpuMatrix4RotY(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1, float ry);
scePspFMatrix4 *sceVfpuMatrix4RotZ(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1, float rz);
scePspFMatrix4 *sceVfpuMatrix4Rot(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1, const scePspFVector4 *rot);


/* Matrix translation */
scePspFMatrix4 *sceVfpuMatrix4Transfer(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1, const scePspFVector4 *ptv);
scePspFMatrix4 *sceVfpuMatrix4SetTransfer(scePspFMatrix4 *pm, const scePspFVector4 *ptv);/
scePspFVector4 *sceVfpuMatrix4GetTransfer(scePspFVector4 *pv, const scePspFMatrix4 *pm);

#define sceVfpuMatrix2IsIdentity(_pm)						sceVfpuMatrix2IsUnit(_pm)
#define sceVfpuMatrix3IsIdentity(_pm)						sceVfpuMatrix3IsUnit(_pm)
#define sceVfpuMatrix4IsIdentity(_pm)						sceVfpuMatrix4IsUnit(_pm)
sceBool sceVfpuMatrix2IsUnit(const scePspFMatrix2 *pm);
sceBool sceVfpuMatrix3IsUnit(const scePspFMatrix3 *pm);
sceBool sceVfpuMatrix4IsUnit(const scePspFMatrix4 *pm);


/* Trace */
float sceVfpuMatrix2Trace(const scePspFMatrix2 *pm);
float sceVfpuMatrix3Trace(const scePspFMatrix3 *pm);
float sceVfpuMatrix4Trace(const scePspFMatrix4 *pm);


float sceVfpuMatrix2Determinant(const scePspFMatrix2 *pm);
float sceVfpuMatrix3Determinant(const scePspFMatrix3 *pm);
float sceVfpuMatrix4Determinant(const scePspFMatrix4 *pm);

/* adjoint matrix */
scePspFMatrix2 *sceVfpuMatrix2Adjoint(scePspFMatrix2 *pm0, const scePspFMatrix2 *pm1);
scePspFMatrix3 *sceVfpuMatrix3Adjoint(scePspFMatrix3 *pm0, const scePspFMatrix3 *pm1);
scePspFMatrix4 *sceVfpuMatrix4Adjoint(scePspFMatrix4 *pm0, const scePspFMatrix4 *pm1);


/* Generate unit Quaternion */
#define sceVfpuQuaternionIdentity(_pq)						sceVfpuQuaternionUnit(_pq)
scePspFQuaternion *sceVfpuQuaternionUnit(scePspFQuaternion *pq);

/* Quaternion copy */
scePspFQuaternion *sceVfpuQuaternionCopy(scePspFQuaternion *pq0, const scePspFQuaternion *pq1);
scePspFMatrix4    *sceVfpuQuaternionToMatrix(scePspFMatrix4 *pm, const scePspFQuaternion *pq);
scePspFVector4    *sceVfpuQuaternionApply(scePspFVector4 *pv0, const scePspFQuaternion *pq, const scePspFVector4 *pv1);

/* Quaternion addtion */
scePspFQuaternion *sceVfpuQuaternionAdd(scePspFQuaternion *pq0, const scePspFQuaternion *pq1, const scePspFQuaternion *pq2);
/* Quaternion subtraction */
scePspFQuaternion *sceVfpuQuaternionSub(scePspFQuaternion *pq0, const scePspFQuaternion *pq1, const scePspFQuaternion *pq2);
/* Quaternion multiplication */
scePspFQuaternion *sceVfpuQuaternionMul(scePspFQuaternion *pq0, const scePspFQuaternion *pq1, const scePspFQuaternion *pq2);

/* Quaternion inner product */
#define sceVfpuQuaternionDot(_v1,_v2)						sceVfpuQuaternionInnerProduct(_q1,_q2)
float sceVfpuQuaternionInnerProduct(const scePspFQuaternion *pq1, const scePspFQuaternion *pq2);


scePspFQuaternion *sceVfpuQuaternionSlerp(scePspFQuaternion *pq0, const scePspFQuaternion *pq1, const scePspFQuaternion *pq2, float rate);


scePspFQuaternion *sceVfpuQuaternionSquad(scePspFQuaternion *pq0,
											const scePspFQuaternion *pq1, const scePspFQuaternion *pq2,
											const scePspFQuaternion *pq3, const scePspFQuaternion *pq4,
											float t);

/* Quaternion normalization */
scePspFQuaternion *sceVfpuQuaternionNormalize(scePspFQuaternion *pq0, const scePspFQuaternion *pq1);

/* Quaternion conjugate */
scePspFQuaternion *sceVfpuQuaternionConj(scePspFQuaternion *pq0, const scePspFQuaternion *pq1);

/* Quaternion inverse */
scePspFQuaternion *sceVfpuQuaternionInverse(scePspFQuaternion *pq0, const scePspFQuaternion *pq1);


scePspFQuaternion *sceVfpuQuaternionFromMatrix(scePspFQuaternion *pq, const scePspFMatrix4 *pm);

scePspFQuaternion *sceVfpuQuaternionFromRotZYX(scePspFQuaternion *pq, const scePspFVector4 *pv);
scePspFQuaternion *sceVfpuQuaternionFromRotXYZ(scePspFQuaternion *pq, const scePspFVector4 *pv);
scePspFQuaternion *sceVfpuQuaternionFromRotYXZ(scePspFQuaternion *pq, const scePspFVector4 *pv);

scePspFQuaternion *sceVfpuQuaternionFromRotate(scePspFQuaternion *pq, float angle, const scePspFVector4 *pvAxis);

scePspFVector4    *sceVfpuQuaternionToRotZYX(scePspFVector4 *pv, const scePspFQuaternion *pq);
scePspFVector4    *sceVfpuQuaternionToRotYXZ(scePspFVector4 *pv, const scePspFQuaternion *pq);

scePspRGBA8888 sceVfpuColorToRGBA8888(const scePspFColor *pc0);
scePspRGBA4444 sceVfpuColorToRGBA4444(const scePspFColor *pc0);
scePspRGBA5551 sceVfpuColorToRGBA5551(const scePspFColor *pc0, float q);
scePspRGB565   sceVfpuColorToRGB565(const scePspFColor *pc0);
scePspFColor *sceVfpuColorFromRGBA8888(scePspFColor *pc0, scePspRGBA8888 rgba);
scePspFColor *sceVfpuColorFromRGBA4444(scePspFColor *pc0, scePspRGBA4444 rgba);
scePspFColor *sceVfpuColorFromRGBA5551(scePspFColor *pc0, scePspRGBA5551 rgba, float q);
scePspFColor *sceVfpuColorFromRGB565(scePspFColor *pc0, scePspRGB565 rgb, float q);

scePspFColor *sceVfpuColorZero(scePspFColor *pc0);
scePspFColor *sceVfpuColorSet(scePspFColor *pc0, float r, float g, float b, float a);
scePspFColor *sceVfpuColorSetRGB(scePspFColor *pc0, float r, float g, float b);
scePspFColor *sceVfpuColorCopy(scePspFColor *pc0, const scePspFColor *pc1);
scePspFColor *sceVfpuColorAdd(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2);
scePspFColor *sceVfpuColorAddRGB(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2);
scePspFColor *sceVfpuColorSub(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2);
scePspFColor *sceVfpuColorSubRGB(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2);
scePspFColor *sceVfpuColorMul(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2);
scePspFColor *sceVfpuColorMulRGB(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2);
scePspFColor *sceVfpuColorNeg(scePspFColor *pc0, const scePspFColor *pc1);
scePspFColor *sceVfpuColorNegRGB(scePspFColor *pc0, const scePspFColor *pc1);

/* Generate interpolation color */
#define sceVfpuColorInter(_pc0,_pc1,_pc2,_t)		sceVfpuColorLerp(_pc0,_pc1,_pc2,(1.0f - (_t)))
#define sceVfpuColorInterRGB(_pc0,_pc1,_pc2,_t)		sceVfpuColorLerpRGB(_pc0,_pc1,_pc2,(1.0f - (_t)))
scePspFColor *sceVfpuColorLerp(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2, float t);
scePspFColor *sceVfpuColorLerpRGB(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2, float t);

scePspFColor *sceVfpuColorScale(scePspFColor *pc0, const scePspFColor *pc1, float t);
scePspFColor *sceVfpuColorScaleRGB(scePspFColor *pc0, const scePspFColor *pc1, float s);
scePspFColor *sceVfpuColorClamp(scePspFColor *pc0, const scePspFColor *pc1, float min, float max);
scePspFColor *sceVfpuColorClampRGB(scePspFColor *pc0, const scePspFColor *pc1, float min, float max);
scePspFColor *sceVfpuColorMax(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2);
scePspFColor *sceVfpuColorMin(scePspFColor *pc0, const scePspFColor *pc1, const scePspFColor *pc2);
sceBool sceVfpuColorIsEqual(const scePspFColor *pc1, const scePspFColor *pc2);
sceBool sceVfpuColorIsZero(const scePspFColor *pc0);

/* Color normalization */
scePspFColor *sceVfpuColorNormalize(scePspFColor *pc0, const scePspFColor *pc1);

/* Color normalization */
scePspFColor *sceVfpuColorNormalizeRGB(scePspFColor *pc0, const scePspFColor *pc1);

/* scalar math operation */
float sceVfpuScalarAbs(float s);
float sceVfpuScalarAcos(float s);
float sceVfpuScalarAsin(float s);
float sceVfpuScalarCeil(float s);
float sceVfpuScalarCos(float s);
float sceVfpuScalarExp(float s);
float sceVfpuScalarFloor(float s);
float sceVfpuScalarLog(float s);
float sceVfpuScalarLog2(float s);
float sceVfpuScalarLog10(float s);
float sceVfpuScalarMax(float a, float b);
float sceVfpuScalarMin(float a, float b);
float sceVfpuScalarPow(float x, float y);
float sceVfpuScalarPow2(float x);
float sceVfpuScalarRound(float s);
float sceVfpuScalarRsqrt(float s);
float sceVfpuScalarSin(float s);
float sceVfpuScalarSqrt(float s);
float sceVfpuScalarTan(float s);
float sceVfpuScalarTrunc(float s);

typedef struct sceVfpuRandContext {
	unsigned int seed[8];
} sceVfpuRandContext __attribute__((aligned(16)));


int sceVfpuRandSaveContext(sceVfpuRandContext *pContext);
int sceVfpuRandRestoreContext(const sceVfpuRandContext *pContext);

float sceVfpuRandFloat(float n);
float sceVfpuRandPi(void);
float sceVfpuRandTwopi(void);

scePspFVector4 *sceVfpuRandVector(scePspFVector4 *pfv);

int   sceVfpuRandInt(int n);
float sceVfpuRandPeekFloat(void);


scePspFMatrix4 *sceVfpuLookAtMatrix(scePspFMatrix4 *pm0, const scePspFVector4 *pvEye, const scePspFVector4 *pvCenter, const scePspFVector4 *pvUp);
scePspFMatrix4 *sceVfpuPerspectiveMatrix(scePspFMatrix4 *pm0, float fovy, float aspect, float r_near, float r_far);
scePspFMatrix4 *sceVfpuOrthoMatrix(scePspFMatrix4 *pm0, float left, float right, float bottom, float top, float r_near, float r_far);

scePspFMatrix4 *sceVfpuCameraMatrix(scePspFMatrix4 *pm, const scePspFVector4 *p, const scePspFVector4 *zd, const scePspFVector4 *yd);
scePspFMatrix4 *sceVfpuViewScreenMatrix(scePspFMatrix4 *pm, float scrz, float ax, float ay, float cx, float cy, float zmin, float zmax, float nearz, float farz);
scePspFMatrix4 *sceVfpuDropShadowMatrix(scePspFMatrix4 *pm, const scePspFVector4 *lp, float a, float b, float c, int mode);

scePspFVector4 *sceVfpuRotTransPers(scePspFVector4 *pv0, const scePspFMatrix4 *pm0, const scePspFVector4 *pv1);
int sceVfpuRotTransPersN(short *pXyz, int pitch, const scePspFMatrix4 *pm0, const scePspFVector4 *pv1, int n);

#ifdef __cplusplus
}
#endif

#endi
