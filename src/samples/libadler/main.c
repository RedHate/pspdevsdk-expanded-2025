/*
 * Ultros - 2024
 * 
 * To use libadler you must first acquire the libadler.prx from somewhere, i got mine from "talkman"
 * You will also need to remove the sce header up to the ~PSP with a hex editor then use prxDecryptor
 * Plug the library with seplugins or via code.
 * 
 */
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pspadler.h>

/* Define the module info section */
PSP_MODULE_INFO("libadler32test", 0, 1, 1);

/* Define the main thread's attribute value (optional) */
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

int done = 0;

/* Exit callback */
int exit_callback(int arg1, int arg2, void *common){
	done = 1;
	return 0;
}

/* Callback thread */
int CallbackThread(SceSize args, void *argp){
	int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
	sceKernelRegisterExitCallback(cbid);
	sceKernelSleepThreadCB();
	return 0;
}

/* Sets up the callback thread and returns its thread id */
int SetupCallbacks(void){
	int thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
	if(thid >= 0){
		sceKernelStartThread(thid, 0, 0);
	}
	return thid;
}

/* Main thread function */
int main(void){
	
	#define ADLER32_HASH_LEN 16
	
	pspDebugScreenInit();
	SetupCallbacks();
	
	//the very data we will be check-summing we are computing our digest of this string.
	const char *string = "you will receive the hashsum of this string.";
	
	//------------------------------------------------------------
	// FULL SINGLE FUNC MD5
	//------------------------------------------------------------
	
	//print the string first
	pspDebugScreenPuts("\r\n\r\n ");
	pspDebugScreenPuts(string);
	pspDebugScreenPuts("\r\n ");
	
	//holders
	char a_buffer[16];
	
	//i believe this is correct...
	unsigned int uiAdler=0;
	int sum = sceAdler32(0, NULL, 0);
	sum = sceAdler32(uiAdler, (const unsigned char*)string, strlen((const char*)string));
	
	//print result
	sprintf(a_buffer, "%08X", sum);
	pspDebugScreenPuts(a_buffer);
	
	//------------------------------------------------------------
	// INPUT
	//------------------------------------------------------------
	
	SceCtrlData pad;
	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

	while(!done){
		
		sceCtrlReadBufferPositive(&pad, 1);
		if (pad.Buttons != 0){
			if (pad.Buttons & PSP_CTRL_START){
				done = 1;
			}
		}
	}

	sceKernelExitGame();
	return 0;
}
