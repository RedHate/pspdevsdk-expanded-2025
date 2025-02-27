
#include <pspuser.h>
#include <stdio.h>
#include <pspiofilemgr.h>

static __inline__
SceUID sceIoOpenCB(const char *filename, int flag, SceMode mode)
{
    SceUID fd;
    int res;
    SceIores iores;
    fd = sceIoOpenAsync(filename, flag, mode);
    if (fd < 0) {
        return fd;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (SceUID)iores;
    } else {
        return (SceUID)res;
    }

}

static __inline__
int    sceIoCloseCB(SceUID fd)
{
    int res;
    SceIores iores;
    res = sceIoCloseAsync(fd);
    if (res < 0) {
        return res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (int)iores;
    } else {
        return res;
    }

}

static __inline__
int    sceIoIoctlCB(SceUID fd, int cmd, void *argp, SceSize arglen,
                    void *bufp, SceSize buflen)
{
    int res;
    SceIores iores;
    res = sceIoIoctlAsync(fd, cmd, argp, arglen, bufp, buflen);
    if (res < 0) {
        return res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (int)iores;
    } else {
        return res;
    }

}

static __inline__
SceOff sceIoLseekCB(SceUID fd, SceOff offset, int whence)
{
    int res;
    SceIores iores;
    res = sceIoLseekAsync(fd, offset, whence);
    if (res < 0) {
        return (SceOff)res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (SceOff)iores;
    } else {
        return (SceOff)res;
    }
}

static __inline__
long   sceIoLseek32CB(SceUID fd, long offset, int whence)
{
    int res;
    SceIores iores;
    res = sceIoLseek32Async(fd, offset, whence);
    if (res < 0) {
        return (long)res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (long)iores;
    } else {
        return (long)res;
    }
}

static __inline__
SceSSize sceIoReadCB(SceUID fd, void *buf, SceSize nbyte)
{
    int res;
    SceIores iores;
    res = sceIoReadAsync(fd, buf, nbyte);
    if (res < 0) {
        return (SceSSize)res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (SceSSize)iores;
    } else {
        return (SceSSize)res;
    }

}

static __inline__
SceSSize sceIoWriteCB(SceUID fd, const void *buf, SceSize nbyte)
{
    int res;
    SceIores iores;
    res = sceIoWriteAsync(fd, buf, nbyte);
    if (res < 0) {
        return (SceSSize)res;
    }
    res = sceIoWaitAsyncCB(fd, &iores);
    if (res == 0) {
        return (SceSSize)iores;
    } else {
        return (SceSSize)res;
    }
}
