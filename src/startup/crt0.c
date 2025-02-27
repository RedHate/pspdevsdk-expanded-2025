/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * crt0.c - Startup code.
 *
 * Copyright (c) 2005 Marcus R. Brown <mrbrown@ocgnet.org>
 *
 */

#include <stdlib.h>
#include <string.h>

#include <pspkerneltypes.h>
#include <pspmoduleinfo.h>
#include <pspthreadman.h>
#include <psploadexec.h>
#include <pspmodulemgr.h>

/* The maximum number of arguments that can be passed to main(). */
#define ARG_MAX 19

/* Default thread parameters for the main program thread. */
#define DEFAULT_THREAD_PRIORITY 32
#define DEFAULT_THREAD_ATTRIBUTE PSP_THREAD_ATTR_USER
#define DEFAULT_THREAD_STACK_KB_SIZE 256
#define DEFAULT_MAIN_THREAD_NAME "user_main"

/* If these variables are defined by the program, then they override the
   defaults given above. */
extern int sce_newlib_nocreate_thread_in_start __attribute__((weak));
extern unsigned int sce_newlib_priority __attribute__((weak));
extern unsigned int sce_newlib_attribute __attribute__((weak));
extern unsigned int sce_newlib_stack_kb_size __attribute__((weak));
extern const char*  sce_newlib_main_thread_name __attribute__((weak));

/* This is declared weak in case someone compiles an empty program.  That
   program won't work on the PSP, but it could be useful for testing the
   toolchain. */
extern SceModuleInfo module_info __attribute__((weak));

/* Allow to provide a libc init hook to be called before main */
extern void __libcglue_init(int argc, char *argv[]);
extern void __libcglue_deinit();
extern void _init(void);
extern void _fini(void);
extern int main(int argc, char *argv[]);

/**
 * Main program thread
 *
 * Initializes runtime parameters and calls the program's main().
 *
 * @param args - Size (in bytes) of the argp parameter.
 * @param argp - Pointer to program arguments.  Each argument is a NUL-terminated string.
 */
void _main(SceSize args, void *argp)
{
	char *argv[ARG_MAX + 1];
	int argc = 0;
	int loc = 0;
	char *ptr = argp;

	/* Turn our thread arguments into main()'s argc and argv[]. */
	while(loc < args)
	{
		argv[argc] = &ptr[loc];
		loc += strlen(&ptr[loc]) + 1;
		argc++;
		if(argc == ARG_MAX)
		{
			break;
		}
	}

	argv[argc] = NULL;

	/* Call libc initialization hook */
	__libcglue_init(argc, argv);

	/* Init can contain C++ constructors that require working threading */
	_init();

	/* Call main(). */
	int res = main(argc, argv);

	/* Return control to the operating system. This will end calling `_exit`*/
	exit(res);
}

__attribute__((__noreturn__))
void _exit(int status)
{
	/* call global destructors*/
	_fini();

	// uninitialize libcglue
	__libcglue_deinit();

	if (&sce_newlib_nocreate_thread_in_start != NULL) {
		sceKernelSelfStopUnloadModule(1, 0, NULL);
	} else {
		sceKernelExitGame();
	}

	while (1); // Avoid warning
}

/**
 * Startup thread
 *
 * Creates the main program thread based on variables defined by the program.
 *
 * @param args - Size (in bytes) of arguments passed to the program by the kernel.
 * @param argp - Pointer to arguments passed by the kernel.
 */
int _start(SceSize args, void *argp)
{
	void (*_main_func)(SceSize args, void *argp) = _main;

	if ((&module_info != NULL) && (module_info.modattribute & PSP_MODULE_KERNEL)) {
		/* If we're running in kernel mode, the addresses of our _main() thread
		   must also reside in kernel mode. */
		_main_func = (void *) ((u32) _main_func | 0x80000000);
	}

	if (&sce_newlib_nocreate_thread_in_start != NULL) {
		/* The program does not want main() to be run in a seperate thread. */
		_main_func(args, argp);
		return 1;
	}

	int priority = DEFAULT_THREAD_PRIORITY;
	unsigned int attribute = DEFAULT_THREAD_ATTRIBUTE;
	unsigned int stackSize = DEFAULT_THREAD_STACK_KB_SIZE * 1024;
	const char *threadName = DEFAULT_MAIN_THREAD_NAME;

	if (&sce_newlib_priority != NULL) {
		priority = sce_newlib_priority;
	}
	if (&sce_newlib_attribute != NULL) {
		attribute = sce_newlib_attribute;
	}
	if (&sce_newlib_stack_kb_size != NULL) {
		stackSize = sce_newlib_stack_kb_size * 1024;
	}
	if (&sce_newlib_main_thread_name != NULL) {
		threadName = sce_newlib_main_thread_name;
	}

	/* Does the _main() thread belong to the User, VSH, or USB/WLAN APIs? */
	if (attribute & (PSP_THREAD_ATTR_USER | PSP_THREAD_ATTR_USBWLAN | PSP_THREAD_ATTR_VSH)) {
		/* Remove the kernel mode addressing from the pointer to _main(). */
		_main_func = (void *) ((u32) _main_func & 0x7fffffff);
	}

	SceUID thid;
	thid = sceKernelCreateThread(threadName, (void *) _main_func, priority, stackSize, attribute, 0);
	sceKernelStartThread(thid, args, argp);

	return 0;
}

/* The entry table provides pointers to the executable's _start() and
   module_info structure. */
static const unsigned int __entrytable[4] __attribute__((section(".rodata.sceResident"))) = {
	0xD632ACDB, 0xF01D73A7, (unsigned int) &_start, (unsigned int) &module_info
};

/* Create the empty library entry used to describe the program's _start() and
   module_info. */
static const struct _library_entry {
	const char *	name;
	unsigned short	version;
	unsigned short	attribute;
	unsigned char	entLen;
	unsigned char	varCount;
	unsigned short	funcCount;
	void *			entrytable;
} _library_entry __attribute__((section(".lib.ent"), used)) = {
	NULL, 0, 0x8000, 4, 1, 1, (unsigned int *) &__entrytable
};
