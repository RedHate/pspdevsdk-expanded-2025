/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspfpu_real.h - Prototypes for the libfpu library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBDFPU_H__
#define __LIBDFPU_H__

#ifdef __cplusplus
extern "C" {
#endif

//sce fpu, the fpu included in pspsdk is not this.

unsigned int sceFpuGetFCR31(void);							/*Get value from FCR31 register */
unsigned int sceFpuSetFCR31(unsigned int fcr);				/*Set value to FCR31 register */

float sceFpuAbs(float fs);									/*returns absolute value */
int   sceFpuCeil(float fs);									/*Round up */
int   sceFpuFloor(float fs);								/*Truncate */
float sceFpuMax(float fs1, float fs2);						/*select maximum value */
float sceFpuMin(float fs1, float fs2);						/*select minimum value */
float sceFpuNeg(float fs);									/*Sign reversal */
int   sceFpuRound(float fs);								/*Round to nearest */
float sceFpuRsqrt(float fs);								/*Reciprocal of square root */
float sceFpuSqrt(float fs);									/*Square root */
int   sceFpuTrunc(float fs);								/*Round towards zero */

float sceFpuFmod(float fs, float fd);						/**/
float sceFpuFrac(float fs);									/**/

float sceFpuReinterpretFloat(unsigned int ui);				/**/
unsigned int sceFpuReinterpretUint(float fs);				/**/
int   sceFpuIsEqual(float fs1, float fs2);					/**/

float sceFpuSignFloat(float fs);							/**/
int   sceFpuSignInt(float fs);								/**/

#define sceFpuZero()		sceFpuPositiveZero()
float sceFpuPositiveZero(void);								/*Positive zero */
float sceFpuNegativeZero(void);								/*Negative zero */
int   sceFpuIsZero(float f);								/*Test for zero value */
int   sceFpuIsPositiveZero(float f);						/*Test for positive zero */
int   sceFpuIsNegativeZero(float f);						/*Test for negative zero */
int   sceFpuIsDenormal(float f);							/*Test for denormalized number */
int   sceFpuIsZeroOrDenormal(float f);						/*Test for zero or denormalized number */

float sceFpuPositiveInf(void);								/*Positive infinity */
float sceFpuNegativeInf(void);								/*Negative infinity */
int   sceFpuIsInf(float f);									/*Test for infinity */

#define sceFpuNan()			sceFpuPositiveNaN()
#define sceFpuQNan()		sceFpuPositiveQNaN()
#define sceFpuSNan(_x)		sceFpuPositiveSNaN(_x)
float sceFpuPositiveNaN(void);								/*NaN (positive SNaN) */
float sceFpuNegativeNaN(void);								/*NaN (negative SNaN) */
float sceFpuPositiveQNaN(void);								/*Quiet NaN (positive QNaN) */
float sceFpuNegativeQNaN(void);								/*Quiet NaN (positive QNaN) */
float sceFpuPositiveSNaN(unsigned int uiSignal);			/*Signaling NaN (positive SNaN) */
float sceFpuNegativeSNaN(unsigned int uiSignal);			/*Signaling NaN (negative SNaN) */
int   sceFpuIsNaN(float f);									/*Test for NaN */
int   sceFpuIsInfOrNaN(float f);							/*Test for infinity or NaN */
float sceFpuNormalizePhase(float fs);						/**/
float sceFpuSin(float x);									/*Sine */
float sceFpuCos(float x);									/*Cosine */
float sceFpuAtan(float x);									/*Arc tangent */
float sceFpuLog(float x);									/*Natural Logarithm */
float sceFpuExp(float x);									/*Exponential */


double sceFpuFloatToDouble(float a); /*convert float to double(similar to __extendsfdf2) */
float  sceFpuDoubleToFloat(double a); /*convert double to float(almost similar to __truncdfsf2) */

#ifdef __cplusplus
}
#endif

#endif
