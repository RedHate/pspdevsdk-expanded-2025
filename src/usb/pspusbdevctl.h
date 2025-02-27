
/* module main params %s %d: on start up? */


#ifndef USBPSPCM_H
#define USBPSPCM_H

#ifdef __cplusplus
extern "C" {
#endif


/*
 * IOCTL/DEVCTL command of USB
 *
 *  31      28 27    20 19 18  17  16  15   14   13  12 11       0
 * +----------+--------+-----+---+---+----+-----+------+----------+
 * | Reserved | DEVICE | Rsv |Dst|Src|Priv|Cache|ThWait| Function |
 * +----------+--------+-----+---+---+----+-----+------+----------+
 *
 *  bit 31-28: Reserved
 *      0000= Always zero
 *
 *  bit 27-20: DeviceCode (DEVICE)
 *      Identifier of protocol driver
 *
 *  bit 19,18: Reserved
 *      00= Always zero
 *
 *  bit 17: Output block use (Dst)
 *      1= Use    (output data exist)
 *      0= No use (no output data)
 *
 *  bit 16: Input block use (Src)
 *      1= Use    (input data exist)
 *      0= No use (no input data)
 *
 *  bit 15: Privilege access (Priv)
 *      1= Privilege is required
 *      0= Privilege is not required
 *
 *  bit 14: Input/Output cache operation in driver (Cache)
 *      1= Driver NOT guarantees cache coherency
 *      0= Driver guarantees cache coherency
 *
 *  bit 13,12: Thread WAIT condition (ThWait)
 *      11= Driver does not make thread to WAIT condition, can execute in CPUDI
 *      10= Driver does not make thread to WAIT condition
 *      01= Driver may make thread to WAIT condition
 *      00= Driver may make thread to WAIT condition with callback
 *
 *  bit 11-0: Function code (Function)
 *      Concrete meanings are defined by each protocol driver
 */


#define PSP_USB_ERROR_OK         0x00000000 /* no error */
#define PSP_USB_ERROR_ALREADY    0x80243001 /* already processed */
#define PSP_USB_ERROR_INVAL      0x80243002 /* invalid argument */
#define PSP_USB_ERROR_NOSPC      0x80243003 /* no space */
#define PSP_USB_ERROR_NOMEM      0x80243004 /* no memory */
#define PSP_USB_ERROR_NOENT      0x80243005 /* no driver by which plug-in was carried out */
#define PSP_USB_ERROR_INPROGRESS 0x80243006 /* in progress */
#define PSP_USB_ERROR_NOTAVAIL   0x80243007 /* not available */
#define PSP_USB_ERROR_TIMEOUT    0x80243008 /* timed out */
#define PSP_USB_ERROR_CANCELED   0x80243009 /* canceled */

/* Activation state of device */
#define PSP_USB_ACT_MASK             0x0F00
#define PSP_USB_DEACTIVATED          0x0100
#define PSP_USB_ACTIVATED            0x0200

/* Connection of USB cable */
#define PSP_USB_CONN_MASK            0x00F0
#define PSP_USB_DISCONNECTED         0x0010
#define PSP_USB_CONNECTED            0x0020

/* State on USB specification */
#define PSP_USB_STATE_MASK           0x000F
#define PSP_USB_DEFAULT              0x0001
#define PSP_USB_CONFIGURED           0x0002
#define PSP_USB_SUSPENDED            0x0004

/*
	to be passed to sceUtilityLoadUsbModule(); to load the module into memory
	#define PSP_USB_MODULE_PSPCM 1
	#define PSP_USB_MODULE_ACC	 2
	#define PSP_USB_MODULE_MIC	 3 // Requires PSP_USB_MODULE_ACC loading first
	#define PSP_USB_MODULE_CAM	 4 // Requires PSP_USB_MODULE_ACC loading first
	#define PSP_USB_MODULE_GPS	 5 // Requires PSP_USB_MODULE_ACC loading first
*/

// Driver name 

#define PSP_USB_BUS_DRIVER_NAME      "USBBusDriver"
#define PSP_USB_ACC_DRIVER_NAME		 "USBAccBaseDriver"
#define PSP_USB_PSPCM_DRIVER_NAME    "USBPSPCommunicationDriver"
#define PSP_USB_STOR_DRIVER_NAME 	 "USBStor_Driver"
#define PSP_USB_MIC_DRIVER_NAME      "USBMicDriver"
#define PSP_USB_CAM_DRIVER_NAME		 "USBCamDriver"
#define PSP_USB_CAM_MIC_DRIVER_NAME	 "USBCamMicDriver"

// Device file name 
#define PSP_USBPSPCM_DEVNAME         "usbpspcm:"

// Product ID
#define PSP_USB_PID_STOR             0x1C8
#define PSP_USB_PID_PSPCM            0x1CB
#define PSP_USB_PID_MIC              0x25B
#define PSP_USB_PID_CAM				 0x282

// Plug-In/Out state of protocol driver
#define PSP_USB_PLUGIN          	 0x1
#define PSP_USB_PLUGOUT         	 0x2

// Information of protocol driver
#define PSP_USB_MAX_DRV_NAME    	 32

// Maximum length of device file name 
#define PSP_USBPSPCM_DEVNAME_LENGTH  16

// Devctl command 
#define PSP_USBPSPCM_REGISTER        0x03415001 // register thread for the notification of connection 
#define PSP_USBPSPCM_UNREGISTER      0x03415002 // unregister thread for the notification of connection 
#define PSP_USBPSPCM_GET_OWN_ADDR    0x03407003 // get own address 
#define PSP_USBPSPCM_GET_ADDR        0x03427004 // get address of all PSP 
#define PSP_USBPSPCM_BIND            0x03435005 // issue of a communication start demand 
#define PSP_USBPSPCM_CANCEL_BIND     0x03415006 // cancel communication start demand 

// ioctl code
#define PSP_USB_DEVICE_USB           0x30  // USB bus driver
#define PSP_USB_DEVICE_PSPCM         0x34  // USB communication driver

// ultros guessed these could be wrong
#define PSP_USB_DEVICE_STOR          0x38  // USB storage driver
#define PSP_USB_DEVICE_MIC           0x3C  // USB mic driver
#define PSP_USB_DEVICE_CAM         	 0x40  // USB cam driver
#define PSP_USB_DEVICE_CAMMIC        0x44  // USB cam and mic driver

// Ioctl command 
#define PSP_USBPSPCM_RESET           0x03405101    // reset channel 
#define PSP_USBPSPCM_RDWR_MODE       0x03416102    // set read/write mode 

static __inline__ int sceUsbCmReset(){
	return sceIoIoctl(PSP_USB_DEVICE_PSPCM, PSP_USBPSPCM_RESET, NULL, 0, NULL, 0);
}

static __inline__ int sceUsbCmRdwrMode(){
	return sceIoIoctl(PSP_USB_DEVICE_PSPCM, PSP_USBPSPCM_RDWR_MODE, NULL, 0, NULL, 0);
}

// Address of USB host 
#define PSP_USBPSPCM_HOST_ADDR       0xFF

// Read/Write mode 
#define PSP_USBPSPCM_RDWR_NORMAL     0x00U
#define PSP_USBPSPCM_RDWR_RD_SEQ     0x01U
#define PSP_USBPSPCM_RDWR_WR_SEQ     0x02U

// Connection state 
typedef struct PspUsbPspcmConnect {
	int     addr;            // address of PSP 
	SceUInt stat;            // connection state 
} PspUsbPspcmConnect;

//PspUsbPspcmConnect stat (right above this)
#define PSP_USBPSPCM_CONNECTED       0x01 // connected 
#define PSP_USBPSPCM_DISCONNECTED    0x02 // disconnected 
#define PSP_USBPSPCM_INVAL_TITLE     0x04 // title check failure 
#define PSP_USBPSPCM_BUSY            0x08 // USB host is busy 
#define PSP_USBPSPCM_WAIT            0x10 // wait for title check 
#define PSP_USBPSPCM_EXCEEDED        0x20 // excceded number restriction 
#define PSP_USBPSPCM_VERSION_ERROR   0x40 // version error 
#define PSP_USBPSPCM_OWN             0x80 // own notification of connection 

// Communiation start demand 
typedef struct PspUsbPspcmBind {
	SceSize size;            // size of structure 
	int     addr;            // communication partner's address 
	SceUInt *timeout;        // timeout 
} PspUsbPspcmBind;

// Error code of USB PSP communication driver 
#define PSP_USBPSPCM_ERROR_ALREADY    0x80243401 // already processed 
#define PSP_USBPSPCM_ERROR_INVAL      0x80243402 // invalid argument 
#define PSP_USBPSPCM_ERROR_NOSPC      0x80243403 // no space 
#define PSP_USBPSPCM_ERROR_NOENT      0x80243405 // specified object does not exist 
#define PSP_USBPSPCM_ERROR_INPROGRESS 0x80243406 // in progress 
#define PSP_USBPSPCM_ERROR_NOTAVAIL   0x80243407 // not available 
#define PSP_USBPSPCM_ERROR_TIMEOUT    0x80243408 // timed out 
#define PSP_USBPSPCM_ERROR_CANCELED   0x80243409 // canceled 
#define PSP_USBPSPCM_ERROR_RESETTING  0x8024340A // resetting 
#define PSP_USBPSPCM_ERROR_RESET_END  0x8024340B // reset end 
#define PSP_USBPSPCM_ERROR_CLOSED     0x8024340C // communication end 

void usbpspcm_check_error(unsigned int error_code){	

	CheckKernelError(error_code);

	pspDebugScreenSetTextColor(0xFF0000FF);
	switch(error_code){
        case PSP_USBPSPCM_ERROR_ALREADY:    pspDebugScreenPuts(" USBPSPCM_ERROR_ALREADY");    break; //0x80243401 // already processed 
        case PSP_USBPSPCM_ERROR_INVAL:      pspDebugScreenPuts(" USBPSPCM_ERROR_INVAL");      break; //0x80243402 // invalid argument 
        case PSP_USBPSPCM_ERROR_NOSPC:      pspDebugScreenPuts(" USBPSPCM_ERROR_NOSPC");      break; //0x80243403 // no space 
        case PSP_USBPSPCM_ERROR_NOENT:      pspDebugScreenPuts(" USBPSPCM_ERROR_NOENT");      break; //0x80243405 // specified object does not exist 
        case PSP_USBPSPCM_ERROR_INPROGRESS: pspDebugScreenPuts(" USBPSPCM_ERROR_INPROGRESS"); break; //0x80243406 // in progress 
        case PSP_USBPSPCM_ERROR_NOTAVAIL:   pspDebugScreenPuts(" USBPSPCM_ERROR_NOTAVAIL");   break; //0x80243407 // not available 
        case PSP_USBPSPCM_ERROR_TIMEOUT:    pspDebugScreenPuts(" USBPSPCM_ERROR_CANCELED");   break; //0x80243408 // timed out 
        case PSP_USBPSPCM_ERROR_CANCELED:   pspDebugScreenPuts(" USBPSPCM_ERROR_CANCELED");   break; //0x80243409 // canceled 
        case PSP_USBPSPCM_ERROR_RESETTING:  pspDebugScreenPuts(" USBPSPCM_ERROR_RESETTING");  break; //0x8024340A // resetting 
        case PSP_USBPSPCM_ERROR_RESET_END:  pspDebugScreenPuts(" USBPSPCM_ERROR_RESET_END");  break; //0x8024340B // reset end 
        case PSP_USBPSPCM_ERROR_CLOSED:     pspDebugScreenPuts(" USBPSPCM_ERROR_CLOSED");     break; //0x8024340C // communication end
        default: pspDebugScreenPuts("\r\n"); break;
	}
	pspDebugScreenSetTextColor(0xFFFFFFFF);
	
}

/** 
 *	load / start usb modules for the usb communication driver
 */
static __inline__ int UsbCmInit(){
	if(sceUtilityLoadUsbModule(PSP_USB_MODULE_PSPCM) != 0) return 1;
	if(sceUtilityLoadUsbModule(PSP_USB_MODULE_ACC) != 0)   return 2;
	if(sceUsbStart("USBBusDriver", 0, 0) != 0)             return 3;
	if(sceUsbStart("USBAccBaseDriver", 0, 0) != 0)         return 4;
	if(sceUsbActivate(PSP_USB_PID_PSPCM) != 0)             return 5;
	return 0;
}

/** 
 *	stop / unload usb modules for the usb communication driver
 */
static __inline__ int UsbCmQuit(){
	if(sceUsbDeactivate(PSP_USB_PID_PSPCM) != 0)           return 5;
	if(sceUsbStop("USBAccBaseDriver", 0, 0) != 0)          return 4;
	if(sceUsbStop("USBBusDriver", 0, 0) != 0)              return 3;
	if(sceUtilityUnloadUsbModule(PSP_USB_MODULE_ACC) != 0) return 2;
	sceUtilityUnloadUsbModule(PSP_USB_MODULE_PSPCM) != 0)  return 1;
	return 0;
}

/** 
 *	load / start usb modules, usb mic pid and init the usb mic
 */
static __inline__ int InitUsbMic(){
	if(sceUtilityLoadUsbModule(PSP_USB_MODULE_ACC) != 0)  return 1;
	if(sceUtilityLoadUsbModule(PSP_USB_MODULE_MIC) != 0)  return 2;
	if(sceUsbStart("USBBusDriver", 0, 0) != 0)            return 3;
	if(sceUsbStart("USBAccBaseDriver", 0, 0) != 0)        return 4;
	if(sceUsbStart("USBMicDriver", 0, 0) != 0)            return 5;
	if(sceUsbActivate(PSP_USBMIC_PID) != 0)               return 6;
	return 0;
}

/**
 *  stop / unload usb modules, usb mic pid and init the usb mic
 */
static __inline__ int TerminateUsbMic(){
	if(sceUsbDeactivate(PSP_USBMIC_PID) != 0)               return 6;
	if(sceUsbStop("USBBusDriver", 0, 0) != 0)               return 5;
	if(sceUsbStop("USBAccBaseDriver", 0, 0) != 0)           return 4;
	if(sceUsbStop("USBMicDriver", 0, 0) != 0)               return 3;
	if(sceUtilityUnloadNetModule(PSP_USB_MODULE_ACC) != 0)  return 2;
	if(sceUtilityUnloadNetModule(PSP_USB_MODULE_MIC) != 0)  return 1;
	if(return 0;
}

#ifdef __cplusplus
}
#endif

/**@}*/

#endif 
