/*
 * PSP Software Development Kit Expansion - https://github.com/redhate
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * usb microphone loop demo in userspace
 *
 * Copyright (c) 2025 ultros
 *
 */
 
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <psputility.h>
#include <psphprm.h>
#include <pspaudio.h>
#include <pspusb.h>
#include <pspusbmic.h>
#include <pspusbacc.h>

#define PSP_NUM_AUDIO_CHANNELS 	1  		//8 max							 (INT)
#define PSP_NUM_AUDIO_SAMPLES 	64  	//64-2048   (to the power of 2)  (INT)
#define PSP_NUM_AUDIO_FREQ 		44100  	//11025,22050,44100,48000 (to the power of 2)(INT)
#define PSP_VOLUME_MAX 			0x8000	//volume level 					 (OCT) (float 32768) (dec 65534)

PSP_MODULE_INFO("sceUsbMicRedHate", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(PSP_THREAD_ATTR_VSH);//(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
//PSP_HEAP_SIZE_MAX();

enum colors {
				/* ARGB */
	MAGENTA 	= 0xFFC000C0,
	RED 		= 0xFF0000C0,
	YELLOW 		= 0xFF00C0C0,
	GREEN 		= 0xFF00C000,
	CYAN 		= 0xFFC0C000,
	BLUE 		= 0xFFC00000,
	WHITE 		= 0xFFFFFFFF,
	LIGHTGRAY 	= 0xFFC0C0C0,
	GRAY 		= 0xFF808080,
	DARKGRAY 	= 0xFF202020,
	BLACK 		= 0xFF000000,
};

int running = 1;

/* Exit callback */
int exit_callback(int arg1, int arg2, void *common){
	running = 0;
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
	if(thid >= 0) {
		sceKernelStartThread(thid, 0, 0);
	}
	
	return thid;
}

int mic_state = 0;
int mic_retval = 0;
float mic_gain 	= 1.0f; //soft gain

//gets used by all threads
unsigned short audio_sndbuf[PSP_NUM_AUDIO_CHANNELS][2][PSP_NUM_AUDIO_SAMPLES][2];

//gets used by microphone
unsigned short usb_micbuf[1][2][PSP_NUM_AUDIO_SAMPLES][2];

typedef struct{
	SceUID t;	//thread id
	int c;		//which line the thread is for
} lineinfo;

//for some reason these are refered to as lines but they are actually "lines" they are stereo pairs
static lineinfo linedata[PSP_NUM_AUDIO_CHANNELS];

/** 
 * for an example i am coloring the output buffer of a single line while simultaneously sampling from the microphone 
 */
static int AudioLineThread(int args, void *argp){
	
	//get the line number
	int line=*(int*)argp;
	
	while(running){
		
		//grab from the mic
		if(mic_state){
			//default to the headset remote, if its not plugged in use the usb mic
			if(sceHprmIsMicrophoneExist()){
				//grab from the internal mic if the remote / microphone exist
				mic_retval = sceAudioInputBlocking(PSP_NUM_AUDIO_SAMPLES, PSP_NUM_AUDIO_FREQ, &usb_micbuf);
			}
			else{
				//grab from the usb mic
				mic_retval = sceUsbMicInputBlocking(PSP_NUM_AUDIO_SAMPLES, PSP_NUM_AUDIO_FREQ, &usb_micbuf);
			}
		}
		
		//stereo sample
		typedef struct{
			 short l, r;
		}sample_t;
		
		//set up a pointer to the audio buffer
		void *bufptr=&audio_sndbuf[line][0];
		//set up a sample pointer
		sample_t* p = (sample_t*) bufptr;
		
		int i;
		for(i = 0; i < PSP_NUM_AUDIO_SAMPLES; i++){
			//if the mic state is enabled we fill the buffer with the mic data
			if(mic_state){
				//mic is returning error?
				if(mic_retval & 0x80000000){
					p[i].l = 0;
					p[i].r = 0;	
				}
				//no error lets color the buffer
				else{
					p[i].l = (*((short*)&usb_micbuf+i)) * mic_gain;
					p[i].r = (*((short*)&usb_micbuf+i)) * mic_gain;
				}

			}
			//keeps things quiet when nothings happening
			else{
				p[i].l = 0;
				p[i].r = 0;
			}
		}
		
		//flip the audio buffer
		sceAudioOutputPannedBlocking(linedata[line].c, PSP_VOLUME_MAX, PSP_VOLUME_MAX, bufptr);
	
	}
	
	//sceKernelExitThread(0);
	sceKernelExitDeleteThread(0);
	
	return 0;
	
}

/**
 * Initialize an audio line and thread for it.
 * @note Audio lines are considered stereo pairs. 
 * @note There are 8 lines to work with max
 * @note The lines are 0 - 7
 * 
 * @param line - the specific line number from 0 - 7
 * @param blocksize - the amount of samples
 * @return - returns 0 on success and < 0 on failure
 */
int InitAudioLine(int line, int blocksize, int format){
	
	char str[32];

	//construction of some vars before hand, not the most elegant thing
	linedata[line].c = -1;
	linedata[line].t = -1;
	
	//reserve lines for playback
	if((linedata[line].c = sceAudioChReserve(line, blocksize, format))<0){
		sceAudioChRelease(linedata[line].c);
	}
	else{
		//create an audio line thread
		sprintf(str,"audiot%d", line);
		if((linedata[line].t = sceKernelCreateThread(str,(void*)&AudioLineThread,0x12,0x10000,0,NULL)) < 0){
			sceKernelDeleteThread(linedata[line].t);
			return -1;
		}
		//start an audio line thread
		if((sceKernelStartThread(linedata[line].t,sizeof(line),&line)) != 0){
			sceKernelDeleteThread(linedata[line].t);
			return -2;
		}
	}

	return 0;
	
}

/**
 * Terminate an individual thread and free it's line
 */
void TerminateAudioLine(int line){
	//kill line
	sceAudioChRelease(linedata[line].c);
	//kill thread
	sceKernelDeleteThread(linedata[line].t);
}

/**
 * Terminate all running threads and free all lines
 */
void TerminateAllAudio(){
	int i;
	//delete the audio threads and release the lines
	for(i=0; i<PSP_AUDIO_CHANNEL_MAX; i++){
		TerminateAudioLine(i);
	}
}

/** 
 *	load / start usb modules, usb mic pid and init the usb mic
 */
void InitUsbMic(){
	
	//load the modules
	sceUtilityLoadUsbModule(PSP_USB_MODULE_ACC);
	sceUtilityLoadUsbModule(PSP_USB_MODULE_MIC);
	
	//start the modules
	sceUsbStart("USBBusDriver", 0, 0);
	sceUsbStart("USBAccBaseDriver", 0, 0);
	sceUsbStart("USBMicDriver", 0, 0);
	
	//activate the usb driver
	sceUsbActivate(PSP_USBMIC_PID); //0x25B
	
}

/**
 *deactivate the usb mic, stop and unload modules
 */
void TerminateUsbMic(){
	
	//deactivate the driver
	sceUsbDeactivate(PSP_USBMIC_PID); //0x25B
	
	//stop the modules
	sceUsbStop("USBBusDriver", 0, 0);
	sceUsbStop("USBAccBaseDriver", 0, 0);
	sceUsbStop("USBMicDriver", 0, 0);
	
	//unload the modules
	sceUtilityUnloadNetModule(PSP_USB_MODULE_ACC);
	sceUtilityUnloadNetModule(PSP_USB_MODULE_MIC);
	
}

int main(void){

	//init debug
	pspDebugScreenInit();
	
	//set up exit callback
	SetupCallbacks();

	//draw header
	pspDebugScreenSetTextColor(MAGENTA); pspDebugScreenPuts("--------------------------------------------------------------------");
	pspDebugScreenSetTextColor(CYAN);    pspDebugScreenPuts("        USB Mic Sample - https://githib.com/redhate/sceUsbMic \r\n");
	pspDebugScreenSetTextColor(MAGENTA); pspDebugScreenPuts("--------------------------------------------------------------------\r\n\r\n");
	pspDebugScreenSetTextColor(WHITE);
	
	//init the usb mic
	InitUsbMic();
	
	//initialize the audio line, sampling is done directly in this loop for the sample
	//however.. if you're writing a proper voice chat client or something you may want independent
	//threads so you can adjust the sample size and rate to feed to your encoder
	InitAudioLine(0, PSP_NUM_AUDIO_SAMPLES, PSP_AUDIO_FORMAT_STEREO);
	
	char buffer[64];
	
	//start the headset / remote / internal mic capture (all mic games default to this)
	int ret = sceAudioInputInit(0, 4096, 0);
	if(ret < 0){
		sprintf(buffer, " sceAudioInputInit Failed: %08X\r\n", ret); pspDebugScreenSetTextColor(RED); pspDebugScreenPuts(buffer);
	}

	//start the usb mic capture (secondary mic only certain games use this)
	ret = sceUsbMicInputInit(0, 4096, 0);
	if(ret < 0){
		sprintf(buffer, " sceUsbMicInputInit Failed: %08X\r\n", ret); pspDebugScreenSetTextColor(RED); pspDebugScreenPuts(buffer);
	}

	//print a bit of a legend
	pspDebugScreenSetTextColor(GRAY);
	pspDebugScreenPuts(" R Trigger - Talk\r\n");
	pspDebugScreenPuts(" Up / Down - Gain\r\n");
	
	//start up the joypad
	SceCtrlData pad;
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
	
	//let the user control the mic capture
	while(running){

		//print a little info in real time
		pspDebugScreenSetXY(0,7);
		if(mic_retval & 0x80000000){
			//mic not present, or the rate / sample size is wrong
			pspDebugScreenSetTextColor(YELLOW); pspDebugScreenPuts(" /!\\ Mic Error /!\\                    \r\n");
		}
		else{
			sprintf(buffer, " Mic Return: %08X\r\n", mic_retval); pspDebugScreenSetTextColor(WHITE); pspDebugScreenPuts(buffer);
		}
		
		//read pad input
		sceCtrlReadBufferPositive(&pad, 1);
		if(pad.Buttons & PSP_CTRL_UP){
			if(mic_gain < 10) mic_gain++;
			sceKernelDelayThread(250000);
		}
		if(pad.Buttons & PSP_CTRL_DOWN){
			if(mic_gain > 1) mic_gain--;
			sceKernelDelayThread(250000);
		}
		//if r trigger is pressed set the mic state to 1
		if(pad.Buttons & PSP_CTRL_RTRIGGER){
			mic_state = 1;
		}
		//otherwise we set the mic state to 0;
		else{ 
			mic_state = 0; 
		}

		//exit
	    if(pad.Buttons & PSP_CTRL_START){
			running = 0;
			sceKernelDelayThread(250000);
		}

	}
	
	//terminate audio threads
	TerminateAllAudio();
	
	//terminate the usb mic
	TerminateUsbMic();

	//exit clean
	sceKernelExitGame();

	//since fnc type is int
	return 0;
}

