/*
 * Ultros - 2024
 * 
 * To use libsha512 you must first acquire the libsha512.prx from somewhere, i got mine from "talkman"
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
#include <pspsha512.h>

/* Define the module info section */
PSP_MODULE_INFO("libsha512test", 0, 1, 1);

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
	
	#define SHA512_HASH_LEN 64
	
	pspDebugScreenInit();
	SetupCallbacks();
	
	//used for loops
	int i;
	
	//the very data we will be check-summing we are computing our digest of this string.
	const char *string = "you will receive the hashsum of this string.";
	
	//------------------------------------------------------------
	// FULL SINGLE FUNC SHA512
	//------------------------------------------------------------
	
	//print the string first
	pspDebugScreenPuts("\r\n\r\n ");
	pspDebugScreenPuts("Single Pass:\r\n ");
	pspDebugScreenPuts(string);
	pspDebugScreenPuts("\r\n ");
	
	//holders
	unsigned char a_hash[SHA512_HASH_LEN];
	char a_buffer[3];
	
	//compute all segments in one pass
	sceSha512Digest((const unsigned char*)string, strlen((const char*)string), a_hash);
	
	//convert to readable and print the resulting digest
	for(i=0;i<SHA512_HASH_LEN;i++){
		sprintf(a_buffer, "%02X", (unsigned char)a_hash[i]);
		pspDebugScreenPuts(a_buffer);
	}
	
	//------------------------------------------------------------
	// FULL SHA512 DIGEST
	//------------------------------------------------------------
	
	//print the string first
	pspDebugScreenPuts("\r\n\r\n ");
	pspDebugScreenPuts("Full Pass:\r\n ");
	pspDebugScreenPuts(string);
	pspDebugScreenPuts("\r\n ");
	
	//holders
	unsigned char b_hash[SHA512_HASH_LEN];
	char b_buffer[3];
	
	//declare context for sha512 data
	PspSha512Context pContext;
	
	//init sha512 context
	sceSha512BlockInit(&pContext);
	
	//loop through the block of data from start to end, 
	//in this case its a string so we can use strlen to find the end.
	for(i=0;i<(strlen(string));i++){
		//compute segment
		sceSha512BlockUpdate(&pContext, (const unsigned char*)string+i, sizeof(unsigned char));
	}
	
	//get the final digest
	sceSha512BlockResult(&pContext, b_hash);
	
	//convert to readable and print the resulting digest
	for(i=0;i<SHA512_HASH_LEN;i++){
		sprintf(b_buffer, "%02X", (unsigned char)b_hash[i]);
		pspDebugScreenPuts(b_buffer);
	}
	
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
