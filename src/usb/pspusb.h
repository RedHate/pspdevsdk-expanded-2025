/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENS in PSPSDK root for details.
 *
 * pspusb.h - Prototypes for the sceUsb library
 *
 * Copyright (c) 2005 John Kelley <ps2dev@kelley.ca>
 *
 */
#ifndef __PSPUSB_H__
#define __PSPUSB_H__

#ifdef __cplusplus
extern "C" {
#endif


//driver names
#define PSP_USBBUS_DRIVERNAME          "USBBusDriver"


#define PSP_USBSTORAGE_DRIVERNAME      "USBStor_Driver"
#define PSP_USBSTORAGE_PID				0x1C8

//kept for compat for pspsdk samples
#define PSP_USB_CABLE_CONNECTED			0x020 
#define PSP_USB_CONNECTION_ESTABLISHED	0x002


/* Device codes */
#define PSP_USB_DEVICE_USB           	0x30  /* USB bus driver */
#define PSP_USB_DEVICE_PSPCM         	0x34  /* USB "PSP" communication driver */

/* usb state activation */
#define PSP_USB_ACT_MASK             	0x0F00
#define PSP_USB_DEACTIVATED          	0x0100
#define PSP_USB_ACTIVATED            	0x0200

/* usb cable state */
#define PSP_USB_CONN_MASK            	0x00F0
#define PSP_USB_DISCONNECTED         	0x0010
#define PSP_USB_CONNECTED            	0x0020

/* usb state */
#define PSP_USB_STATE_MASK           	0x000F
#define PSP_USB_DEFAULT              	0x0001
#define PSP_USB_CONFIGURED           	0x0002
#define PSP_USB_SUSPENDED            	0x0004

/* usb bus driver errors */
#define PSP_USB_ERROR_OK         		0x00000000 /* no error */
#define PSP_USB_ERROR_ALREADY    		0x80243001 /* already processed */
#define PSP_USB_ERROR_INVAL      		0x80243002 /* invalid argument */
#define PSP_USB_ERROR_NOSPC      		0x80243003 /* no space */
#define PSP_USB_ERROR_NOMEM      		0x80243004 /* no memory */
#define PSP_USB_ERROR_NOENT      		0x80243005 /* plugin failure */
#define PSP_USB_ERROR_INPROGRESS 		0x80243006 /* in progress */
#define PSP_USB_ERROR_NOTAVAIL   		0x80243007 /* not available */
#define PSP_USB_ERROR_TIMEOUT    		0x80243008 /* timed out */
#define PSP_USB_ERROR_CANCELED   		0x80243009 /* canceled */

/* Plug state of driver */
#define PSP_USB_PLUGIN          		0x1      /* plug in */
#define PSP_USB_PLUGOUT         		0x2      /* plug out */

/* protocol driver */
#define PSP_USB_MAX_DRV_NAM 			32

typedef struct PspUsbDrvInfo {
	unsigned int size;                        /* size of structure */
	char         name[PSP_USB_MAX_DRV_NAM];   /* Driver name */
	int          state;                       /* Plug state */
	int          reserved[2];                 /* reserved */
} PspUsbDrvInfo;

/**
  * Start a USB driver.
  * 
  * @param driverName - name of the USB driver to start
  * @param size - Size of arguments to pass to USB driver start
  * @param args - Arguments to pass to USB driver start
  *
  * @return 0 on success
  */
int sceUsbStart(const char* driverName, int size, void *args);

/**
  * Stop a USB driver.
  * 
  * @param driverName - name of the USB driver to stop
  * @param size - Size of arguments to pass to USB driver stop
  * @param args - Arguments to pass to USB driver stop
  *
  * @return 0 on success
  */
int sceUsbStop(const char* driverName, int size, void *args);

/**
  * Activate a USB driver.
  * 
  * @param pid - Product ID for the default USB Driver
  *
  * @return 0 on success
  */
int sceUsbActivate(u32 pid);

/**
  * Deactivate USB driver.
  *
  * @param pid - Product ID for the default USB driver
  * 
  * @return 0 on success
  */
int sceUsbDeactivate(u32 pid);

/**
  * Get USB state
  * 
  * @return OR'd PSP_USB_* constants
  */
int sceUsbGetState(void);

/**
  * Get state of a specific USB driver
  * 
  * @param driverName - name of USB driver to get status from
  *
  * @return 1 if the driver has been started, 2 if it is stopped
  */
int sceUsbGetDrvState(const char* driverName);

int sceUsbGetDrvList(int flag, PspUsbDrvInfo *drvinfo_list, int max_num);

int sceUsbWaitState(unsigned int state, int waitmode, unsigned int *timeout);

int sceUsbWaitCancel(void);


#ifdef __cplusplus
}
#endif

#endif
