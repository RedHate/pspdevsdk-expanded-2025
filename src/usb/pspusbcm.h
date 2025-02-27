
/* module main params %s %d: on start up? */


#ifndef USBPSPCM_H
#define USBPSPCM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pspusb.h>

// Driver name 
#define PSP_USBPSPCM_DRIVERNAME      "USBPSPCommunicationDriver"

// Device file name 
#define PSP_USBPSPCM_DEVNAME         "usbpspcm:"

/*E Product ID */
#define SCE_USB_PID_PSPCM            0x01CB

/*E Device code */
#define SCE_USB_DEVICE_USB           0x30  /* USB bus driver */
#define SCE_USB_DEVICE_PSPCM         0x34  /* USB "PSP" communication driver */ 

/* Maximum length of device file name */
#define PSP_USBPSPCM_DEVNAME_LENGTH  16

/* Address of USB host */
#define PSP_USBPSPCM_HOST_ADDR       0xFF

/* Devctl command */
enum PspUsbCmDevctlCMD{
    PSP_USBPSPCM_REGISTER       = 0x03415001, // register thread    
    PSP_USBPSPCM_UNREGISTER     = 0x03415002, // unregister thread    
    PSP_USBPSPCM_GET_OWN_ADDR   = 0x03407003, // get "own" address    
    PSP_USBPSPCM_GET_ADDR       = 0x03427004, // get all address    
    PSP_USBPSPCM_BIND           = 0x03435005, // start bind    
    PSP_USBPSPCM_CANCEL_BIND    = 0x03415006, // cancels start bind    
};

/* ioctl command */
enum PspUsbCmIoctlCMD{
    PSP_USBPSPCM_RESET          = 0x03405101,    // reset channel    
    PSP_USBPSPCM_RDWR_MODE      = 0x03416102,    // set read/write mode    
};

/* r/w mode */
enum PspUsbRWMode{
    PSP_USBPSPCM_RDWR_NORMAL    = 0x00U, //read write mode normal
    PSP_USBPSPCM_RDWR_RD_SEQ    = 0x01U, //read
    PSP_USBPSPCM_RDWR_WR_SEQ    = 0x02U, //write
};

/* communication state */
typedef struct SceUsbPspcmConnect {
	int     addr;            // address of PSP    
	SceUInt stat;            // connection state    
} SceUsbPspcmConnect;

/* state enumerations */
enum PspUsbCmState{
    PSP_USBPSPCM_CONNECTED      = 0x01, // connected    
    PSP_USBPSPCM_DISCONNECTED   = 0x02, // disconnected    
    PSP_USBPSPCM_INVAL_TITLE    = 0x04, // title check failure    
    PSP_USBPSPCM_BUSY           = 0x08, // the usb host is busy    
    PSP_USBPSPCM_WAIT           = 0x10, // wait for title check    
    PSP_USBPSPCM_EXCEEDED       = 0x20, // excceded number restriction    
    PSP_USBPSPCM_VERSION_ERROR  = 0x40, // version error    
    PSP_USBPSPCM_OWN            = 0x80, // "own" connection    
};

/* communication start */
typedef struct SceUsbPspcmBind {
	SceSize size;            // size of structure    
	int     addr;            // communication partner's address    
	SceUInt *timeout;        // timeout    
} SceUsbPspcmBind;

/* communication driver errors */
enum PspUsbCmError{
    PSP_USBPSPCM_ERROR_ALREADY    = 0x80243401,  // already processed    
    PSP_USBPSPCM_ERROR_INVAL      = 0x80243402,  // invalid argument    
    PSP_USBPSPCM_ERROR_NOSPC      = 0x80243403,  // no space    
    PSP_USBPSPCM_ERROR_NOENT      = 0x80243405,  // specified object does not exist    
    PSP_USBPSPCM_ERROR_INPROGRESS = 0x80243406,  // in progress    
    PSP_USBPSPCM_ERROR_NOTAVAIL   = 0x80243407,  // not available    
    PSP_USBPSPCM_ERROR_TIMEOUT    = 0x80243408,  // timed out    
    PSP_USBPSPCM_ERROR_CANCELED   = 0x80243409,  // canceled
    PSP_USBPSPCM_ERROR_RESETTING  = 0x8024340A,  // resetting
    PSP_USBPSPCM_ERROR_RESET_END  = 0x8024340B,  // reset end
    PSP_USBPSPCM_ERROR_CLOSED     = 0x8024340C,  // communication end
};



#ifdef __cplusplus
}
#endif

/**@}*/

#endif 
