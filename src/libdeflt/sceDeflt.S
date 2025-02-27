	.set noreorder

#include "pspimport.s"

#ifdef F_sceDeflt_0000
	IMPORT_START "sceDeflt", 0x00010011
#endif
#ifdef F_sceDeflt_0001
	IMPORT_FUNC	"sceDeflt", 0x44054E03, sceDeflateDecompress
#endif
#ifdef F_sceDeflt_0002
	IMPORT_FUNC	"sceDeflt", 0x6E4701D1, sceDeflateGetErxEntries
#endif
#ifdef F_sceDeflt_0003
	IMPORT_FUNC "sceDeflt", 0xE46EB986, sceZlibIsValid
#endif
#ifdef F_sceDeflt_0004
	IMPORT_FUNC "sceDeflt", 0xAFE01FD3, sceZlibGetInfo
#endif
#ifdef F_sceDeflt_0005
	IMPORT_FUNC "sceDeflt", 0x6A548477, sceZlibGetCompressedData
#endif
#ifdef F_sceDeflt_0006
	IMPORT_FUNC "sceDeflt", 0xA9E4FB28, sceZlibDecompress
#endif
#ifdef F_sceDeflt_0007
	IMPORT_FUNC "sceDeflt", 0x2EE39A64, sceZlibAdler32
#endif
#ifdef F_sceDeflt_0008
	IMPORT_FUNC "sceDeflt", 0x1B5B82BC, sceGzipIsValid
#endif
#ifdef F_sceDeflt_0009
	IMPORT_FUNC "sceDeflt", 0x8AA82C92, sceGzipGetInfo
#endif
#ifdef F_sceDeflt_0010
	IMPORT_FUNC "sceDeflt", 0x106A3552, sceGzipGetName
#endif
#ifdef F_sceDeflt_0011
	IMPORT_FUNC "sceDeflt", 0xB767F9A0, sceGzipGetComment
#endif
#ifdef F_sceDeflt_0012
	IMPORT_FUNC "sceDeflt", 0x0BA3B9CC, sceGzipGetCompressedData
#endif
#ifdef F_sceDeflt_0013
	IMPORT_FUNC "sceDeflt", 0x6DBCF897, sceGzipDecompress
#endif
#ifdef F_sceDeflt_0014
	IMPORT_FUNC "sceDeflt", 0x2DA2A96D, sceGzipCrc32
#endif


#ifdef __cplusplus
}
#endif
