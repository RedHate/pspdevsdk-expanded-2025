/*
 * Sce Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in SceSDK root for details.
 *
 * pspinit.h - Interface to InitForKernel.
 *
 * Copyright (c) 2007 moonlight
 *
 */
#ifndef __SceINIT_H__
#define __SceINIT_H__

enum SceBootFrom
{
	Sce_BOOT_FLASH = 0, /* ? */
	Sce_BOOT_DISC = 0x20,
	Sce_BOOT_MS = 0x40,
};

enum SceInitApitype
{
	Sce_INIT_APITYPE_DISC = 0x120,
	Sce_INIT_APITYPE_DISC_UPDATER = 0x121,
	Sce_INIT_APITYPE_MS1 = 0x140,
	Sce_INIT_APITYPE_MS2 = 0x141,
	Sce_INIT_APITYPE_MS3 = 0x142,
	Sce_INIT_APITYPE_MS4 = 0x143,
	Sce_INIT_APITYPE_MS5 = 0x144,
	Sce_INIT_APITYPE_VSH1 = 0x210, /* ExitGame */
	Sce_INIT_APITYPE_VSH2 = 0x220, /* ExitVSH */
};

enum SceKeyConfig
{
	Sce_INIT_KEYCONFIG_VSH = 0x100,
	Sce_INIT_KEYCONFIG_GAME = 0x200,
	Sce_INIT_KEYCONFIG_POPS = 0x300,
};

/**
 * Gets the api type 
 *
 * @return the api type in which the system has booted
*/
int sceKernelInitApitype();

/**
 * Gets the filename of the executable to be launched after all modules of the api.
 *
 * @return filename of executable or NULL if no executable found.
*/
char *sceKernelInitFileName();

/**
 *
 * Gets the device in which the application was launched.
 *
 * @return the device code, one of SceBootFrom values.
*/
int sceKernelBootFrom();

/**
 * Get the key configuration in which the system has booted.
 *
 * @return the key configuration code, one of SceKeyConfig values 
*/
int InitForKernel_7233B5BC();

#define sceKernelInitKeyConfig InitForKernel_7233B5BC

#endif

