/*
 *
 *	Runtime Plugin Initialization
 * 
 *	Ultros - PSPSDK 2025
 * 
 *	What it do?:
 * 		Plug & init PSP runtime library modules to extend the scope of PSPSDK
 * 		(runtime stub libs and headers included in this sdk)
 * 
 * 	sha1sample.prx source can be found in "sha1" directory along with the
 *  decrypted libsha1.prx library.
 * 
 *	keep in mind when coding with this sample that official firmware handles
 *	signature checking on plugins, that you will need the correct sigs
 *	in order to plug your modules to the proper memory partitions
 * 
 *	Might be able to plug and load kernel plugins on OFW provided all plugins
 *	are signed correctly, kernel plugins need kernel plugin sigs. 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>
#include <pspmodulemgr.h>

PSP_MODULE_INFO("moduleLoadStartTest", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
// PSP_HEAP_SIZE_MAX();
 
// var for tracking main thread state
int running = 1;

// vars for module uids, we track these for unloading.
SceUID module_id[3];

/** 
 *  LoadStart function for plugins
 * 	@param path - the full path to your plugin: "ms0:/PSP/GAME/mygame/myplugin.prx"
 * 	@param flags - set to 0
 * 	@param mpid - the memory partition to load the plugin into, PSP_MEMORY_PARTITION_KERNEL or PSP_MEMORY_PARTITION_USER
 *  @return - 0 on success or error code if failed.
 */
u32 moduleLoadStart (const char *path, int flags, SceUID mpid){

	// If mpid for some reason is set 0 then we default to 1 (kernel)
	if(mpid != (PSP_MEMORY_PARTITION_KERNEL || PSP_MEMORY_PARTITION_USER)) 
		mpid = PSP_MEMORY_PARTITION_USER;

	// Declare the structure
	SceKernelLMOption option;
	
	// Initialize structure
	memset(&option,0,sizeof(option));
	option.size = sizeof(option);
	option.mpidtext = mpid;
	option.mpiddata = mpid;
	option.position = 0;
	option.access = 1;
	
	// Load module
	SceUID loadResult = sceKernelLoadModule(path,flags,(mpid == (PSP_MEMORY_PARTITION_KERNEL || PSP_MEMORY_PARTITION_USER))? &option : NULL);
	if (loadResult & 0x80000000) return loadResult;
	
	// Start module
	int status;
	SceUID startResult = sceKernelStartModule(loadResult,0,NULL,&status,NULL);
	if (loadResult != startResult) return loadResult;
	
	// Return the result
	return startResult;

};

/** 
 *  StopUnload function for plugins
 * 	@param uid - the uid of a plugin to be stopped (returned by moduleLoadStart on init)
 *  @return - 0 on success or error code if failed.
 */
u32 moduleStopUnload (SceUID uid){

	// Stop module
	int status;
	SceUID stopResult = sceKernelStopModule(uid,0,NULL,&status,NULL);
	if (stopResult & 0x80000000) return stopResult;
	
	// Unload module
	SceUID unloadResult = sceKernelUnloadModule(uid);
	if (unloadResult & 0x80000000) return unloadResult;
	
	// Return the result
	return stopResult;

};

void load_modules(){

   /* 
	*	We cannot load things directly from flash0 from a userspace program
	*	either it needs to be on ms0, umd, or a buffer.
	*/

	#define _D_ISO_ 1

#ifdef _D_ISO_
	// Load and start a library module (take note of the memory partition, its dependant of the prx's mode)
	module_id[0] = moduleLoadStart("disc0:/PSP_GAME/USRDIR/module/libsha1.prx", 0, PSP_MEMORY_PARTITION_USER);
#else
	module_id[0] = moduleLoadStart("fatms0:/PSP/GAME/runtime_init/libsha1.prx", 0, PSP_MEMORY_PARTITION_USER);
#endif
	// If the return value of loaded module is an error code
	if(module_id[0] & 0x80000000){
		pspDebugScreenPuts("library prx not loaded"); CheckKernelError(module_id[0]); pspDebugScreenPuts("\r\n");
	}
	// If the return value of loaded module is a proper UID
	else{
		pspDebugScreenPuts("library prx loaded\r\n");
	}

#ifdef _D_ISO_
	// Load and start a library module (take note of the memory partition, its dependant of the prx's mode)
	module_id[1] = moduleLoadStart("disc0:/PSP_GAME/USRDIR/module/libmd5.prx", 0, PSP_MEMORY_PARTITION_USER);
#else
	module_id[1] = moduleLoadStart("fatms0:/PSP/GAME/runtime_init/libmd5.prx", 0, PSP_MEMORY_PARTITION_USER);
#endif
	// If the return value of loaded module is an error code
	if(module_id[1] & 0x80000000){
		pspDebugScreenPuts("library prx not loaded"); CheckKernelError(module_id[1]); pspDebugScreenPuts("\r\n");
	}
	// If the return value of loaded module is a proper UID
	else{
		pspDebugScreenPuts("library prx loaded\r\n");
	}


	// Load and start main module that references the previously loaded lib (again take note of the memory partition, its dependant of the prx's mode)
#ifdef _D_ISO_
	module_id[2] = moduleLoadStart("disc0:/PSP_GAME/USRDIR/module/sample.prx", 0, PSP_MEMORY_PARTITION_USER);
#else
	module_id[2] = moduleLoadStart("fatms0:/PSP/GAME/runtime_init/sample.prx", 0, PSP_MEMORY_PARTITION_USER);
#endif
	// If the return value of loaded module is an error code
	if(module_id[2] & 0x80000000){
		pspDebugScreenPuts("main prx not loaded"); CheckKernelError(module_id[2]); pspDebugScreenPuts("\r\n");
	}
	// If the return value of loaded module is a proper UID
	else{
		pspDebugScreenPuts("main prx loaded\r\n");
	}

}

void unload_modules(){
	// Unload our couple modules before exit
	moduleStopUnload(module_id[0]);
	moduleStopUnload(module_id[1]);
	moduleStopUnload(module_id[2]);
}

int main(){
	
	pspDebugScreenInit();
	
	// Wait for the kernel to boot
	sceKernelDelayThread(100000);
	while(!sceKernelFindModuleByName("sceKernelLibrary")) sceKernelDelayThread(100000); //tenth a second
	
	// Load the modules into memory and execute them
	load_modules();
	
	// This 1 second delay is super important, it gives the system enough time to plug the modules and allow them to init
	sceKernelDelayThread(1000000);

	// Controller init
	SceCtrlData pad;
	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

	// This just keeps the game mode from dying once the sub-modules are initialized. not sure how to init and exit
	while(running){
		// Poll input
		sceCtrlReadBufferPositive(&pad, 1);
		// Some change
		if (pad.Buttons != 0){
			// State pressed, break the loop
			if (pad.Buttons & PSP_CTRL_START){
				running = 0;
			} 
		}
	}

	// Unload modules
	unload_modules();
	// Give time for modules to unload
	sceKernelDelayThread(1000000);

	// Exit the game
	//sceKernelExitGame(); //regular exit no status
	
	// Exit with status (used with prx modules, return exit code to unload status var)
	int status = 0;
	sceKernelExitGameWithStatus(status);
	
	return 0;

};

