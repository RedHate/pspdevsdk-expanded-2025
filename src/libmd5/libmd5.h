
typedef struct {
	unsigned int       h[4];
	unsigned int       pad;
	unsigned short     usRemains;
	unsigned short     usComputed;
	unsigned long long ulTotalLen;
	unsigned char      buf[64];
} SceMd5Context;

/*E Get full MD5 digest with one pass */
int  sceMd5Digest(const unsigned char *plain, unsigned int len, unsigned char *digest);

/*E Initialize digest value */
int  sceMd5BlockInit(SceMd5Context *pContext);

/*E MD5 digest value compute segment */
int  sceMd5BlockUpdate(SceMd5Context *pContext, const unsigned char *plain, unsigned int len);

/*E Get MD5 digest */
int  sceMd5BlockResult(SceMd5Context *pContext, unsigned char *digest);


