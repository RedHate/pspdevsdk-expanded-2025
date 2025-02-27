/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspmscm.h - Memory stick utility functions
 *
 * Copyright (c) 2006 Adrahil
 *
 */
#ifndef PSPMSCM_H
#define PSPMSCM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pspiofilemgr.h>

// device file name for MSCM                                                               
#define SCE_MSCM_MSCM_DEVFILE           "mscm"
#define SCE_MSCM_HC_DEVFILE_BASE        "mscmhc"
//#define SCE_MSCM_HC_DEVFILE(instance)   SCE_MSCM_HC_DEVFILE_BASE#instance
//#define SCE_MSCM_ERROR(sev, kind) 		(int)(SCE_ERROR_MAKE_ERROR(SCE_ERROR_FACILITY_MEMSTICK,((0 << 8) | (sev & 1)<<7) | (kind & 0x7F)))
//#define SCE_MSCM_FERROR(sev, kind) 		(int)(SCE_ERROR_MAKE_CRITICAL(SCE_ERROR_FACILITY_MEMSTICK,((0 << 8) | (sev & 1)<<7) | (kind & 0x7F)))
#define SCE_MSCM_WARN               	0x80220000 //warning error                           
#define SCE_MSCM_WARN_NO_MORE_CLDM  	0x80220001 //no more cldm found                      
#define SCE_MSCM_ERR                	0x80220080 //general error                           
#define SCE_MSCM_FATAL              	0xC0220000 //fatal error                             
#define SCE_MSCM_ERR_INVALID_PARAM  	0x80220081 //caller's specified parameter is invalid 
#define SCE_MSCM_ERR_NOMEM          	0x80220082 //out of memory                           
#define SCE_MSCM_ERR_OUT_OF_SERVICE 	0x80220083 //requested target is out of service      
#define SCE_MSCM_ERR_NOT_FOUND      	0x80220084 //specified object not found              
#define SCE_MSCM_ERR_ALREADY        	0x80220085 //requested status is already achieved    
#define SCE_MSCM_ERR_BUSY           	0x80220086 //requested target is busy                
#define SCE_MSCM_ERR_TIMEOUT        	0x80220087 //timeout                                 
#define SCE_MSCM_ERR_CRC            	0x80220088 //CRC error                               
#define SCE_MSCM_ERR_TOE            	0x80220089 //MS SMS TOE                              
#define SCE_MSCM_ERR_DMA            	0x8022008A //DMA operation is done with error        
#define SCE_MSCM_ERR_CMDNK          	0x8022008B //CMDNK detected                          
#define SCE_MSCM_ERR_FLASH          	0x8022008C //MS Flash error                          

#define SCE_MSCM_FATAL_INVALID_PARAM	 0xC0220001 //parameter is completely wrong, giveup 
#define SCE_MSCM_FATAL_CLDM_LIST_DAMAGED 0xC0220002 //internal structure damaged, giveup    

// MSCM status.                                           
typedef enum {
	SCE_MSCM_MSCMSTATUS_UNKNOWN,
	SCE_MSCM_MSCMSTATUS_NOMEDIA,
	SCE_MSCM_MSCMSTATUS_INSERTED,
	SCE_MSCM_MSCMSTATUS_QUERYING,
	SCE_MSCM_MSCMSTATUS_ATTACHED,
	SCE_MSCM_MSCMSTATUS_PAD      = 0x40000000
} sceMScmMSCMStatus;

// M.S. slot status                                     
typedef enum {
	SCE_MSCM_SLOTINSERTION_UNCHANGE,
	SCE_MSCM_SLOTINSERTION_INSERTED,
	SCE_MSCM_SLOTINSERTION_NOMEDIA,
	SCE_MSCM_SLOTINSERTION_PAD   = 0x40000000
} sceMScmHCSlotInsertionState;


#define SCE_IOCTL_DEVICE_MS_CM  (0x20)
#define SCE_MSCM_CTLCODE(dst, src, priv, cache, wait, devctl, funcno) \
((SCE_IOCTL_DEVICE_MS_CM << 20) | \
 ((dst    & 1) << 17)   | \
 ((src    & 1) << 16)   | \
 ((priv   & 1) << 15)   | \
 ((cache  & 1) << 14)   | \
 ((wait   & 3) << 12)   | \
 ((devctl & 1) << 11)   | \
 ((funcno << 0) & 0x07ff))


// devctl code for query MSCM media status.                                                
#define SCE_MSCM_QUERY_MSCM_STATUS           SCE_MSCM_CTLCODE(1, 0, 0, 1, 1, 1, 1)

// devctl code for cld eventflag to notify CLD's attachment/detachment 
// and media insertion and removal                                                         
#define SCE_MSCM_REGISTER_CALLBACK           SCE_MSCM_CTLCODE(0, 1, 0, 1, 1, 1, 4)
#define SCE_MSCM_UNREGISTER_CALLBACK         SCE_MSCM_CTLCODE(0, 1, 0, 1, 1, 1, 5)

// devctl code for query media status.                                                     
#define SCE_MSCM_QUERY_SLOT_STATUS           SCE_MSCM_CTLCODE(1, 0, 0, 1, 1, 1, 6)

// event flag pattern for devctl above 
#define SCE_MSCM_NOTIFY_CLD_ATTACHED         (1<<0)        // a class driver may ready 
#define SCE_MSCM_NOTIFY_CLD_DETACHED 	     (1<<1)        // the class driver removed 
#define SCE_MSCM_NOTIFY_MEDIUM_INSERTED      (1<<2)        // media insertion detected 
#define SCE_MSCM_NOTIFY_MEDIUM_REMOVED       (1<<3)        // media removal detected   

/**
 * @return 1 if storage driver is ready, otherwise 0  
 */         
static __inline__ int sceMScmIsCLDAttached(void)
{
	sceMScmMSCMStatus status;
	int ret;
	if ((ret = sceIoDevctl("mscmhc0:", SCE_MSCM_QUERY_MSCM_STATUS, 0, 0, &status, sizeof(status))) < 0)
		return ret;
	return (status == SCE_MSCM_MSCMSTATUS_ATTACHED) ? 1 : 0;
}       
static __inline__ int sceMScmIsCLDDettached(void)
{
	sceMScmMSCMStatus status;
	int ret;
	if ((ret = sceIoDevctl("mscmhc0:", SCE_MSCM_QUERY_MSCM_STATUS, 0, 0, &status, sizeof(status))) < 0)
		return ret;
	return (status == SCE_MSCM_NOTIFY_CLD_DETACHED) ? 1 : 0;
}
/**
 * Returns whether a memory stick is current inserted
 *
 * @return 1 if memory stick inserted, 0 if not or if < 0 on error
 */      
static __inline__ int sceMScmIsMediumInserted(void)
{
	sceMScmHCSlotInsertionState status;
	int ret;
	if ((ret = sceIoDevctl("mscmhc0:", SCE_MSCM_QUERY_SLOT_STATUS, 0, 0, &status, sizeof(status))) < 0)
		return ret;
	return (status == SCE_MSCM_SLOTINSERTION_INSERTED) ? 1 : 0;
}

static __inline__ int sceMScmIsMediumRemoved(void)
{
	sceMScmHCSlotInsertionState status;
	int ret;
	if ((ret = sceIoDevctl("mscmhc0:", SCE_MSCM_QUERY_SLOT_STATUS, 0, 0, &status, sizeof(status))) < 0)
		return ret;
	return (status == SCE_MSCM_NOTIFY_MEDIUM_REMOVED) ? 1 : 0;
}

// macro for registering callback of media/driver notification 
static __inline__ int sceMScmRegisterNotifyCallback(sceUID uidCB)
{
	return sceIoDevctl("mscmhc0:", SCE_MSCM_REGISTER_CALLBACK, &uidCB, sizeof(uidCB), 0, 0);
}

// macro for unregistering callback of media/driver notification 
static __inline__ int sceMScmUnRegisterNotifyCallback(sceUID uidCB)
{
	return sceIoDevctl("mscmhc0:", SCE_MSCM_UNREGISTER_CALLBACK, &uidCB, sizeof(uidCB), 0, 0);
}

/* Event which has occurred in the memory stick ejection callback, passed in arg2 */
#define MS_CB_EVENT_INSERTED 1
#define MS_CB_EVENT_EJECTED  2

/**
 * Registers a memory stick ejection callback
 *
 * @param cbid - The uid of an allocated callback
 *
 * @return 0 on success, < 0 on error
 */
static __inline__ int sceMScmRegisterMSInsertEjectCallback(sceUID cbid)
{
	return sceIoDevctl("fatms0:", 0x02415821, &cbid, sizeof(cbid), 0, 0);
}

/**
 * Unregister a memory stick ejection callback
 *
 * @param cbid - The uid of an allocated callback
 *
 * @return 0 on success, < 0 on error
 */
static __inline__ int sceMScmUnregisterMSInsertEjectCallback(sceUID cbid)
{
	return sceIoDevctl("fatms0:", 0x02415822, &cbid, sizeof(cbid), 0, 0);
}



#ifdef __cplusplus
}
#endif

#endif /* PSPMSCM_H */
