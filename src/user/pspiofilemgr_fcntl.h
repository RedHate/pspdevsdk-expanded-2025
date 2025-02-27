/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspiofilemgr_fcntl.h - File control definitions.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 * Copyright (c) 2005 James Forshaw <tyranid@gmail.com>
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 */
#ifndef PSPIOFILEMGR_FCNTL_H
#define PSPIOFILEMGR_FCNTL_H

//kept for backward compat with pspdevsdk



// flags
#define	PSP_FREAD	(0x0001)  // readable
#define	PSP_FWRITE	(0x0002)  // writable
#define	PSP_FNBLOCK	(0x0004)  //   Reserved: non-blocking reads
#define	PSP_FDIRO	(0x0008)  // internal use for dopen
#define	PSP_FRLOCK	(0x0010)  //   Reserved: read locked (non-shared)
#define	PSP_FWLOCK	(0x0020)  //   Reserved: write locked (non-shared)
#define	PSP_FAPPEND	(0x0100)  // append on each write
#define	PSP_FCREAT	(0x0200)  // create if nonexistant
#define	PSP_FTRUNC	(0x0400)  // truncate to zero length
#define PSP_EXCL	(0x0800)  // exclusive create
#define	PSP_FSCAN	(0x1000)  //   Reserved: scan type
#define	PSP_FRCOM	(0x2000)  //   Reserved: remote command entry
#define	PSP_FNBUF	(0x4000)  //   Reserved: no ring buf. and console interrupt
#define	PSP_FASYNC	(0x8000)  //   Reserved: asyncronous i/o
#define PSP_FFDEXCL (0x01000000)        // exclusive access
#define PSP_FPWLOCK (0x02000000)        // power control lock

// Flag for open()
#define PSP_O_DIR 		(PSP_FDIRO)   //some made up bullshit by pspdev folks (doesnt actually exist)
#define PSP_O_RDONLY    (PSP_FREAD)
#define PSP_O_WRONLY    (PSP_FWRITE)
#define PSP_O_RDWR      (PSP_FREAD|PSP_FWRITE)
#define PSP_O_NBLOCK    (PSP_FNBLOCK) //   Reserved: Non-Blocking I/O
#define PSP_O_APPEND    (PSP_FAPPEND) // append (writes guaranteed at the end)
#define PSP_O_CREAT     (PSP_FCREAT)  // open with file create
#define PSP_O_TRUNC     (PSP_FTRUNC)  // open with truncation
#define PSP_O_EXCL	    (PSP_EXCL)	  // exclusive create
#define PSP_O_NOBUF     (PSP_FNBUF)	  //   Reserved: no device buffer and console interrupt
#define PSP_O_NOWAIT    (PSP_FASYNC)  //   Reserved: asyncronous i/o
#define PSP_O_FDEXCL    (PSP_FFDEXCL) // exclusive access
#define PSP_O_PWLOCK    (PSP_FPWLOCK) // power control lock

#define PSP_O_RETRY_0   (0x00000000)       //   Retry count
#define PSP_O_RETRY_1   (0x00010000)       //   Retry count
#define PSP_O_RETRY_2   (0x00020000)       //   Retry count
#define PSP_O_RETRY_3   (0x00030000)       //   Retry count
#define PSP_O_RETRY_4   (0x00040000)       //   Retry count
#define PSP_O_RETRY_5   (0x00050000)       //   Retry count
#define PSP_O_RETRY_6   (0x00060000)       //   Retry count
#define PSP_O_RETRY_7   (0x00070000)       //   Retry count
#define PSP_O_RETRY_8   (0x00080000)       //   Retry count
#define PSP_O_RETRY_9   (0x00090000)       //   Retry count
#define PSP_O_RETRY_10  (0x000a0000)       //   Retry count
#define PSP_O_RETRY_11  (0x000b0000)       //   Retry count
#define PSP_O_RETRY_12  (0x000c0000)       //   Retry count
#define PSP_O_RETRY_13  (0x000d0000)       //   Retry count
#define PSP_O_RETRY_14  (0x000e0000)       //   Retry count
#define PSP_O_RETRY_15  (0x000f0000)       //   Retry count


#define PSP_SEEK_SET	(0)
#define PSP_SEEK_CUR	(1)
#define PSP_SEEK_END	(2)




#endif /* PSPIOFILEMGR_FCNTL_H */
