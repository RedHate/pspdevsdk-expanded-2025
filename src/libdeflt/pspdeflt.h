/*
 * PSP Software Development Kit Expansion - https://github.com/redhate/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspdeflt.h - Prototypes for the libdeflt library
 *
 * Copyright (c) 2025 ultros
 *
 */

#ifndef __LIBDEFLT_H__
#define __LIBDEFLT_H__

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * not really used by anything
 */
 /*
typedef struct sceGzipHeader{
	unsigned char id1;				//Identification 1(0x1F)					
	unsigned char id2;				//Identification 2(0x8B)					
	unsigned char cm;				//Compression Method						
							// 0x00 - 0x07:	reserved					
							// 0x08: 	deflate						
							// 0x09		unknown						
	unsigned char flg;		//flags									
							// bit 7	reserved					
							// bit 4:		FCOMMENT					
							// bit 3:		FNAME						
							// bit 2:		FEXTRA						
							// bit 1:		FHCRC						
							// bit 0:		FTEXT						
	unsigned int  uiMtime;			//Modification TIME						
	unsigned char xlf;				//extra flags								
							//0x02= compressor used maximum			
							//      compression, slowest algorithm	
							//0x04= compressor used fastest algorithm	
	unsigned char os;				// OS										
							// 0x00: FAT								
							// 0x01: Amiga								
							// 0x02: VMS								
							// 0x03: Unix								
							// 0x04: VM/CMS								
							// 0x05: Atari TOS							
							// 0x06: HPFS(OS/2, NT)						
							// 0x07: Macintosh							
							// 0x08: Z-System							
							// 0x09: CP/M								
							// 0x0A: TOPS-20							
							// 0x0B: NTFS(NT)							
							// 0x0C: QDOS								
							// 0x0D: Acorn RISCOS						
							// 0xFF: unknown							
} sceGzipHeader;
*/


/*RFC1952 */
/**
 *  Checks gzip buffer integrity
 *  @const void *pSrc - the gzip buffer in memory
 *	@return - 1 if valid gzip buffer 
 * 			  0 if invalid gzip buffer
 */
int sceGzipIsValid(const void *pSrc);


int sceGzipGetInfo(const void *pSrc, const void **ppvExtra, const char **ppszName, const char **ppszComment, unsigned short *pusCrc, const void **ppvData);

/**
 *  @return - returns file name buffer of the gzip 
 */
const char *sceGzipGetName(const void *pSrc);
/**
 *  @return - returns comment buffer of the gzip 
 */
const char *sceGzipGetComment(const void *pSrc);
/**
 *  @return - returns data buffer of the gzip
 */
const void *sceGzipGetCompressedData(const void *pSrc);
/* Calc CRC32 (ITU-T v.42) */
/**
 * @unsigned int uiCrc - the crc32 sum
 * @const unsigned char *pSrc - gzip buffer
 * @unsigned int uiSize - gzip buffer size
 * @return -
 */
unsigned int sceGzipCrc32(unsigned int uiCrc, const unsigned char *pSrc, unsigned int uiSize);

/* GZIP deflate decompress */
/**
 *  Deflates to buffer
 * 
 *  unsigned char *pDst - the destination buffer for unpacked gzip
 *  unsigned int uiBufSize - the size of the buffer
 *  const void *pSrcGzip - the gzip buffer
 *  unsigned int *puiCrc32 - returned crc32 
 * 	
 *  @return - returns data buffer of the gzip
 */
int  sceGzipDecompress(unsigned char *pDst, unsigned int uiBufSize, const void *pSrcGzip, unsigned int *puiCrc32);



/* RFC1950 */
/**
 *  Checks bzip buffer integrity
 *  @const void *pSrc - the bzip buffer in memory
 *	@return - 1 if valid bzip buffer 
 * 			  0 if invalid bzip buffer
 */
int sceZlibIsValid(const void *pSrc);


int sceZlibGetInfo(const void *pSrc, unsigned char *pbCmf, unsigned char *pbFlg, unsigned int *puiDictId, const void **ppvData);

/**
 *  @return - returns data buffer of the bzip
 */
const void *sceZlibGetCompressedData(const void *pSrcZlib);

/* ZLIB deflate decompress */
/**
 * Decompresses zlib from buffer
 * @unsigned char *pDst - destination buffer
 * @unsigned int uiBufSize - zlib buffer size
 * @const void *pSrcZlib - zlib buffer
 * @unsigned int *puiAdler32 - adler
 * @return - success 1 / failure 0 ?
 */
int  sceZlibDecompress(unsigned char *pDst, unsigned int uiBufSize, const void *pSrcZlib, unsigned int *puiAdler32);

/* Calc Adler-32 checksum */
unsigned int sceZlibAdler32(unsigned int uiAdler, const unsigned char *pSrc, unsigned int uiSize);

/* RFC1951 */
/*DEFLATE without GZIP / BZIP header date decompress */
int  sceDeflateDecompress(unsigned char *pDst, unsigned int uiBufSize, const void *pSrcDeflate, void *ppNext);

void *sceDeflateGetErxEntries(void);

#ifdef __cplusplus
}
#endif

#endif
