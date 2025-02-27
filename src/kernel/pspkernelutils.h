/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * psputilsforkernel.h - Include file for UtilsForKernel
 *
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 * Copyright (c) 2005 adresd
 * Some added by ultros in 2025
 * 
 * KERNEL UTILS NOT LIMITED TO KERNEL SPACE
 *
 */

#ifndef __PSPUTILSFORKERNEL_H__
#define __PSPUTILSFORKERNEL_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/time.h>
#include <sys/timeb.h>
#include <sys/times.h>

/** 
 *  This struct is needed because tv_sec size is different from what newlib expect
 * Newlib expects 64bits for seconds and PSP expects 32bits
 */
typedef struct SceKernelTimeval {
	uint32_t tv_sec;
	uint32_t tv_usec;
} SceKernelTimeval;

/**
  * Get the time in seconds since the epoc (1st Jan 1970)
  *
  */
time_t sceKernelLibcTime(time_t *t);

/**
  * Get the processor clock used since the start of the process
  */
clock_t sceKernelLibcClock(void);

/**
  * Get the current time of time and time zone information
  */
int sceKernelLibcGettimeofday(struct SceKernelTimeval *tp, struct timezone *tzp);


// PSP Tool (hardware) GPI & GPO
unsigned char sceKernelGetGPI(void);
void          sceKernelSetGPO(unsigned char gpo);

// data cache
/**
  * Write back the data cache to memory
  */
void sceKernelDcacheWritebackAll(void);

/**
  * Write back and invalidate the data cache
  */
void sceKernelDcacheWritebackInvalidateAll(void);

/**
 * Smarter people will know what this does.
 */
void sceUtilsKernelDcacheWBinvRange(const char *start, unsigned int size);

/**
  * Write back a range of addresses from the data cache to memory
  */
void sceKernelDcacheWritebackRange(const char *start, unsigned int size);

/**
  * Write back and invalidate a range of addresses in the data cache
  */
void sceKernelDcacheWritebackInvalidateRange(const char *start, unsigned int size);

/**
  * Invalidate a range of addresses in data cache
  */
int  sceKernelDcacheInvalidateRange(void *start, unsigned int size);

/**
 * Invalidate the entire data cache
 */ 
void sceKernelDcacheInvalidateAll(void);

/**
 * Check whether the specified address is in the data cache
 * @param addr - The address to check
 *
 * @return 0 = not cached, 1 = cache
 */
int  sceKernelDcacheProbe(void *addr);



// instruction cache

/**
 * Check whether the specified address is in the instruction cache
 * @param addr - The address to check
 *
 * @return 0 = not cached, 1 = cache
 */
int  sceKernelIcacheProbe(const void *addr);

/**
 * Invalidate a instruction cache range.
 * @param addr - The start address of the range.
 * @param size - The size in bytes
 */
void sceKernelIcacheInvalidateRange(const void *addr, unsigned int size);

/**
 * Invalidate the entire instruction cache
 */
void sceKernelIcacheInvalidateAll(void);

/**
 * Invalidate the CPU's instruction cache.
 */
void sceKernelIcacheClearAll(void);


// MD5 digest data type
typedef struct SceKernelUtilsMd5Context {
	unsigned int       h[4];
	unsigned int       pad;
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long int ullTotalLen;
	unsigned char      buf[64];
} SceKernelUtilsMd5Context;

// basic hash
int  sceKernelUtilsMd5Digest(const unsigned char *plain, unsigned int uiLen, unsigned char *digest);

// splitable hash
int  sceKernelUtilsMd5BlockInit(SceKernelUtilsMd5Context *pContext);
int  sceKernelUtilsMd5BlockUpdate(SceKernelUtilsMd5Context *pContext, const unsigned char *plain, unsigned int uiLen);
int  sceKernelUtilsMd5BlockResult(SceKernelUtilsMd5Context *pContext, unsigned char *digest);

/** only sha1 - no sha224, sha256, sha512 in kmode **/

/* SHA1 digest */
typedef struct SceKernelUtilsSha1Context {
	unsigned int       h[5];
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long int ullTotalLen;
	unsigned char      buf[64];
} SceKernelUtilsSha1Context;

// SHA1
/*all data must be in memory */
int  sceKernelUtilsSha1Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);
/*splitable hash computing */
int  sceKernelUtilsSha1BlockInit(SceKernelUtilsSha1Context *pContext);
int  sceKernelUtilsSha1BlockUpdate(SceKernelUtilsSha1Context *pContext, const unsigned char *plain, unsigned int uiLen);
int  sceKernelUtilsSha1BlockResult(SceKernelUtilsSha1Context *pContext, unsigned char *digest);

// SHA224
/*all data must be in memory */
int  sceKernelUtilsSha224Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);
/*splitable hash computing */
int  sceKernelUtilsSha224BlockInit(SceKernelUtilsSha1Context *pContext);
int  sceKernelUtilsSha224BlockUpdate(SceKernelUtilsSha1Context *pContext, const unsigned char *plain, unsigned int uiLen);
int  sceKernelUtilsSha224BlockResult(SceKernelUtilsSha1Context *pContext, unsigned char *digest);

// SHA256
/*all data must be in memory */
int  sceKernelUtilsSha256Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);
/*splitable hash computing */
int  sceKernelUtilsSha256BlockInit(SceKernelUtilsSha1Context *pContext);
int  sceKernelUtilsSha256BlockUpdate(SceKernelUtilsSha1Context *pContext, const unsigned char *plain, unsigned int uiLen);
int  sceKernelUtilsSha256BlockResult(SceKernelUtilsSha1Context *pContext, unsigned char *digest);

// SHA512
/*all data must be in memory */
int  sceKernelUtilsSha512Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);
/*splitable hash computing */
int  sceKernelUtilsSha512BlockInit(SceKernelUtilsSha1Context *pContext);
int  sceKernelUtilsSha512BlockUpdate(SceKernelUtilsSha1Context *pContext, const unsigned char *plain, unsigned int uiLen);
int  sceKernelUtilsSha512BlockResult(SceKernelUtilsSha1Context *pContext, unsigned char *digest);

// MT19937 psuedo random number data type
typedef struct SceKernelUtilsMt19937Context {
	unsigned int count;
	unsigned int state[624];
} SceKernelUtilsMt19937Context;

int sceKernelUtilsMt19937Init(SceKernelUtilsMt19937Context *pCtx, unsigned int seed);
unsigned int sceKernelUtilsMt19937UInt(SceKernelUtilsMt19937Context *pCtx);

// power switch lock & unlock
#define PSP_KERNEL_POWER_LOCK_DEFAULT		0
int sceKernelPowerLock(int locktype);				// Lock power swtich control
int sceKernelPowerUnlock(int locktype);				// Unnlock power swtich control

// volatile memory lock & unlock
#define PSP_KERNEL_VOLATILE_MEM_DEFAULT		0
int sceKernelVolatileMemLock(int arg, void **ppAdr, unsigned int *puiSize);
int sceKernelVolatileMemTryLock(int arg, void **ppAdr, unsigned int *puiSize);
int sceKernelVolatileMemUnlock(int arg);

// idle timer 
#define PSP_KERNEL_POWER_TICK_DEFAULT		0x00	// Cancel all timers
#define PSP_KERNEL_POWER_TICK_SUSPENDONLY	0x01	// Cancel auto-suspend timer
#define PSP_KERNEL_POWER_TICK_LCDONLY		0x06	// Cancel LCD timer
int sceKernelPowerTick(int ticktype);

// rfc1952
/**
 *  Checks gzip buffer integrity
 *  @const void *pSrc - the gzip buffer in memory
 *	@return - 1 if valid gzip buffer 
 * 			  0 if invalid gzip buffer
 */
int sceKernelGzipIsValid(const void *pSrc);

int sceKernelGzipGetInfo(const void *pSrc, const void **ppvExtra, const char **ppszName, const char **ppszComment, unsigned short *pusCrc, const void **ppvData);

/**
 *  @return - returns file name buffer of the gzip 
 */
const char *sceKernelGzipGetName(const void *pSrc);
/**
 *  @return - returns comment buffer of the gzip 
 */
const char *sceKernelGzipGetComment(const void *pSrc);
/**
 *  @return - returns data buffer of the gzip
 */
const void *sceKernelGzipGetCompressedData(const void *pSrc);
// Calc CRC32 ITU-T v.42
/**
 * @unsigned int uiCrc - the crc32 sum
 * @const unsigned char *pSrc - gzip buffer
 * @unsigned int uiSize - gzip buffer size
 * @return -
 */
unsigned int sceKernelGzipCrc32(unsigned int uiCrc, const unsigned char *pSrc, unsigned int uiSize);

// GZIP deflate
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
int  sceKernelGzipDecompress(unsigned char *pDst, unsigned int uiBufSize, const void *pSrcGzip, unsigned int *puiCrc32);



// rfc1950
/**
 *  Checks bzip buffer integrity
 *  @const void *pSrc - the bzip buffer in memory
 *	@return - 1 if valid bzip buffer 
 * 			  0 if invalid bzip buffer
 */
int sceKernelZlibIsValid(const void *pSrc);


int sceKernelZlibGetInfo(const void *pSrc, unsigned char *pbCmf, unsigned char *pbFlg, unsigned int *puiDictId, const void **ppvData);

/**
 *  @return - returns data buffer of the bzip
 */
const void *sceKernelZlibGetCompressedData(const void *pSrcZlib);

// ZLIB deflate
/**
 * Decompresses zlib from buffer
 * @unsigned char *pDst - destination buffer
 * @unsigned int uiBufSize - zlib buffer size
 * @const void *pSrcZlib - zlib buffer
 * @unsigned int *puiAdler32 - adler
 * @return - success 1 / failure 0 ?
 */
int  sceKernelZlibDecompress(unsigned char *pDst, unsigned int uiBufSize, const void *pSrcZlib, unsigned int *puiAdler32);

// Adler-32 checksum
unsigned int sceKernelZlibAdler32(unsigned int uiAdler, const unsigned char *pSrc, unsigned int uiSize);

// rfc1951
// deflate without GZIP / BZIP header
int  sceKernelDeflateDecompress(unsigned char *pDst, unsigned int uiBufSize, const void *pSrcDeflate, void *ppNext);

void *sceKernelDeflateGetErxEntries(void);

static __inline__ unsigned int sceKernelMakePhysicalAddr(const void *a)
{
	return (((unsigned int)a) & 0x1FFFFFFF);
}

/*
	//gpi/gpo for psp tool
	IMPORT_FUNC	"UtilsForKernel",0x193D4036,sceKernelSetGPIMask
	IMPORT_FUNC	"UtilsForKernel",0x95035FEF,sceKernelSetGPOMask
	//libc rtc
	IMPORT_FUNC	"UtilsForKernel",0x7B7ED3FD,sceKernelRegisterLibcRtcFunc
	IMPORT_FUNC	"UtilsForKernel",0x6151A7C3,sceKernelReleaseLibcRtcFunc
	//cache
	IMPORT_FUNC	"UtilsForKernel",0x16641D70,sceKernelDcacheReadTag
	IMPORT_FUNC	"UtilsForKernel",0xFB05FAD0,sceKernelIcacheReadTag
*/

#ifdef __cplusplus
}
#endif

#endif
