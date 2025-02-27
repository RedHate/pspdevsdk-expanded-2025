/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspccc.h - Prototypes for the libccc library
 *
 * Copyright (c) 2025 ultros
 *
 */
 
#ifndef __LIBCCC_H__
#define __LIBCCC_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned short	sceCccJISCS;
typedef unsigned short	sceCccSJISCS;
typedef unsigned short	sceCccUCS2;
typedef unsigned int	sceCccUCS4;

typedef unsigned char	sceCccJISTF;
typedef unsigned char	sceCccSJISTF;
typedef unsigned char	sceCccUTF8;
typedef unsigned short	sceCccUTF16;

#define __MAXCHRSIZE_SJIS__		(2)
#define __MAXCHRSIZE_UTF8__		(4)
#define __MAXCHRSIZE_UTF16__	(4)

void sceCccSetTable(sceCccUCS2 const* jis2ucs, sceCccJISCS const* ucs2jis);

int sceCccStrlenUTF16(sceCccUTF16 const* str);
int sceCccStrlenUTF8(sceCccUTF8 const* str);
int sceCccStrlenSJIS(sceCccSJISTF const* str);
int sceCccIsValidUCS4(sceCccUCS4 code);
int sceCccIsValidUCS2(sceCccUCS4 code);
int sceCccIsValidJIS(sceCccJISCS code);
int sceCccIsValidUTF8(sceCccUCS4 code);
int sceCccIsValidUTF16(sceCccUCS4 code);
int sceCccIsValidSJIS(sceCccJISCS code);

sceCccUCS4 sceCccDecodeUTF16(sceCccUTF16 const** str);
sceCccUCS4 sceCccDecodeUTF8(sceCccUTF8 const** str);/
sceCccJISCS sceCccDecodeSJIS(sceCccSJISTF const** str);

void sceCccEncodeUTF16(sceCccUTF16** dst, sceCccUCS4 code);
void sceCccEncodeUTF8(sceCccUTF8** dst, sceCccUCS4 code);
void sceCccEncodeSJIS(sceCccSJISTF** dst, sceCccJISCS code);

sceCccJISCS sceCccUCStoJIS(sceCccUCS4 code, sceCccJISCS chr);
sceCccUCS4 sceCccJIStoUCS(sceCccJISCS code, sceCccUCS4 chr);

/* UTF8 to UTF16 */
int sceCccUTF8toUTF16(sceCccUTF16* dst, size_t count, sceCccUTF8 const* str);

/* UTF8 to SJIS */
int sceCccUTF8toSJIS(sceCccSJISTF* dst, size_t count, sceCccUTF8 const* str);

/* SJIS to UTF8 */
int sceCccSJIStoUTF8(sceCccUTF8* dst, size_t count, sceCccSJISTF const* str);

/* SJIS to UT16 */
int sceCccSJIStoUTF16(sceCccUTF16* dst, size_t count, sceCccSJISTF const* str);

/* UTF16 to SJIS */
int sceCccUTF16toSJIS(sceCccSJISTF* dst, size_t count, sceCccUTF16 const* str);

/* UTF16 to UTF8 */
int sceCccUTF16toUTF8(sceCccUTF8* dst, size_t count, sceCccUTF16 const* str);

sceCccJISCS sceCccSetErrorCharSJIS(sceCccJISCS chr);
sceCccUCS4 sceCccSetErrorCharUTF8(sceCccUCS4 chr);
sceCccUCS4 sceCccSetErrorCharUTF16(sceCccUCS4 chr);

void *sceCccGetErxEntries(void);

#ifdef __cplusplus
}
#endif

#endif
