/*
 * PSP Software Development Kit - https://github.com/pspdev
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in PSPSDK root for details.
 *
 * Copyright (c) 2005 Jesper Svennevid
 */

#include "guInternal.h"

void sceGuClutLoad(int num_blocks, const void *cbp)
{
	sendCommandi(CLUT_BUF_PTR, ((unsigned int)cbp) & 0xffffff);
	sendCommandi(CLUT_BUF_WIDTH, (((unsigned int)cbp) >> 8) & 0xf0000);
	sendCommandi(CLUT_LOAD, num_blocks);
}
