/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * pspsysevent.h - Prototypes for the sceSysEventForKernel library
 *
 * Copyright (c) 2007 Iaroslav Gaponenko <adrahil@gmail.com>
 *
 */
#ifndef __PSPSYSEVENT_H__
#define __PSPSYSEVENT_H__
 
#ifdef __cplusplus
extern "C" {
#endif
 
typedef struct SceSysEventHandler _SceSysEventHandler;
 
typedef int (*SceSysEventHandlerFunc)(int ev_id, char* ev_name, void* param, int* result);
 
typedef struct SceSysEventHandler{
  int size;
  char* name;
  int type_mask;
  int (*handler)(int ev_id, char* ev_name, void* param, int* result);
  int r28;
  int busy;
  _SceSysEventHandler *next;
  int reserved[9];
}SceSysEventHandler;
 
 
/**
 * Dispatch a SysEvent event.
 *
 * @param ev_type_mask - the event type mask
 * @param ev_id - the event id
 * @param ev_name - the event name
 * @param param - the pointer to the custom parameters
 * @param result - the pointer to the result
 * @param break_nonzero - set to 1 to interrupt the calling chain after the first non-zero return
 * @param break_handler - the pointer to the event handler having interrupted
 * @return 0 on success, < 0 on error
 */
int sceKernelSysEventDispatch(int ev_type_mask, int ev_id, char* ev_name, void* param, int* result, int break_nonzero, SceSysEventHandler* break_handler);
 
 
/**
 * Get the first SysEvent handler (the rest can be found with the linked list).
 *
 * @return 0 on error, handler on success
 */
SceSysEventHandler* sceKernelReferSysEventHandler(void);
 
 
/**
 * Check if a SysEvent handler is registered.
 *
 * @param handler - the handler to check
 * @return 0 if the handler is not registered
 */
int sceKernelIsRegisterSysEventHandler(SceSysEventHandler* handler);
 
 
/**
 * Register a SysEvent handler.
 *
 * @param handler - the handler to register
 * @return 0 on success, < 0 on error
 */
int sceKernelRegisterSysEventHandler(SceSysEventHandler* handler);
 
 
/**
 * Unregister a SysEvent handler.
 *
 * @param handler - the handler to unregister
 * @return 0 on success, < 0 on error
 */
int sceKernelUnregisterSysEventHandler(SceSysEventHandler* handler);
 
#ifdef __cplusplus
}
#endif
 
#endif

