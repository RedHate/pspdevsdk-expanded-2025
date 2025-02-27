/*
 * Ultros - 2024
 * 
 * To use libsha1 you must first acquire the libsha1.prx from somewhere, i got mine from "talkman"
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
#include <pspsha1.h>
#include <pspmd5.h>

/* Define the module info section */
PSP_MODULE_INFO("libsha1test", 0, 1, 1);

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
	
	pspDebugScreenInit();
	SetupCallbacks();
	
	//used for loops
	int i;
	char buf[3];
	
	//the very data we will be check-summing we are computing our digest of this string.
	const char *string = "you will receive the hashsum of this string.";
	
	//------------------------------------------------------------
	// SHA1
	//------------------------------------------------------------
	
	#define SHA1_HASH_LEN 20
	//holders
	unsigned char sha1_hash[SHA1_HASH_LEN];
	
	//------------------------------------------------------------
	// FULL SINGLE FUNC SHA1
	//------------------------------------------------------------
	
	//print the string first
	pspDebugScreenPuts("\r\n\r\n ");
	pspDebugScreenPuts("SHA1 Single Pass:\r\n ");
	pspDebugScreenPuts(string);
	pspDebugScreenPuts("\r\n ");
	
	//compute all segments in one pass
	sceSha1Digest((const unsigned char*)string, strlen((const char*)string), sha1_hash);
	
	//convert to readable and print the resulting digest
	for(i=0;i<SHA1_HASH_LEN;i++){
		sprintf(buf, "%02X", (unsigned char)sha1_hash[i]);
		pspDebugScreenPuts(buf);
	}
	
	//------------------------------------------------------------
	// FULL SHA1 DIGEST
	//------------------------------------------------------------
	
	//print the string first
	pspDebugScreenPuts("\r\n\r\n ");
	pspDebugScreenPuts("SHA1 Full Pass:\r\n ");
	pspDebugScreenPuts(string);
	pspDebugScreenPuts("\r\n ");
	
	//declare context for sha1 data
	sceSha1Context sha1_pContext;
	
	//init sha1 context
	sceSha1BlockInit(&sha1_pContext);
	
	//loop through the block of data from start to end, 
	//in this case its a string so we can use strlen to find the end.
	for(i=0;i<(strlen(string));i++){
		//compute segment
		sceSha1BlockUpdate(&sha1_pContext, (const unsigned char*)string+i, sizeof(unsigned char));
	}
	
	//get the final digest
	sceSha1BlockResult(&sha1_pContext, sha1_hash);
	
	//convert to readable and print the resulting digest
	for(i=0;i<SHA1_HASH_LEN;i++){
		sprintf(buf, "%02X", (unsigned char)sha1_hash[i]);
		pspDebugScreenPuts(buf);
	}
	
	//------------------------------------------------------------
	// MD5
	//------------------------------------------------------------
	
	#define MD5_HASH_LEN 16
	
	//holders
	unsigned char hashmd5[MD5_HASH_LEN];
	
	//------------------------------------------------------------
	// FULL SINGLE FUNC MD5
	//------------------------------------------------------------
	
	//print the string first
	pspDebugScreenPuts("\r\n\r\n ");
	pspDebugScreenPuts("MD5 Single Pass:\r\n ");
	pspDebugScreenPuts(string);
	pspDebugScreenPuts("\r\n ");
	
	//compute all segments in one pass
	sceMd5Digest((const unsigned char*)string, strlen((const char*)string), hashmd5);
	
	//convert to readable and print the resulting digest
	for(i=0;i<MD5_HASH_LEN;i++){
		sprintf(buf, "%02X", (unsigned char)hashmd5[i]);
		pspDebugScreenPuts(buf);
	}
	
	//------------------------------------------------------------
	// FULL MD5 DIGEST
	//------------------------------------------------------------
	
	//print the string first
	pspDebugScreenPuts("\r\n\r\n ");
	pspDebugScreenPuts("MD5 Full Pass:\r\n ");
	pspDebugScreenPuts(string);
	pspDebugScreenPuts("\r\n ");
	
	//declare context for md5 data
	sceMd5Context md5_pContext;
	
	//init md5 context
	sceMd5BlockInit(&md5_pContext);
	
	//loop through the block of data from start to end, 
	//in this case its a string so we can use strlen to find the end.
	for(i=0;i<(strlen(string));i++){
		//compute segment
		sceMd5BlockUpdate(&md5_pContext, (const unsigned char*)string+i, sizeof(unsigned char));
	}
	
	//get the final digest
	sceMd5BlockResult(&md5_pContext, hashmd5);
	
	//convert to readable and print the resulting digest
	for(i=0;i<MD5_HASH_LEN;i++){
		sprintf(buf, "%02X", (unsigned char)hashmd5[i]);
		pspDebugScreenPuts(buf);
	}
	
	
	//------------------------------------------------------------
	// INPUT
	//------------------------------------------------------------
	
	SceCtrlData input;
	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

	while(!done){
		sceCtrlReadBufferPositive(&input, 1);
		if (input.Buttons != 0){
			if (input.Buttons & PSP_CTRL_START){
				done = 1;
			}
		}
	}

	//sceKernelExitGame();
	
	int status = 0;
	sceKernelExitGameWithStatus(status);
	
	return 0;
}
