/* 
 * pspusbmic.h - Prototypes for the sceUSBMic library
 *
 * Copyright (c) 2024 ultros
 *
 * $Id: pspusbmic.h 2342 2007-12-06 21:49:26Z ultros $
 */
#ifndef __PSPUSBMIC_H__
#define __PSPUSBMIC_H__

#ifdef __cplusplus
extern "C" {
#endif

#define PSP_USBMIC_ERROR_NOT_INITIALIZED   0x80260001
#define PSP_USBMIC_ERROR_OUTPUT_BUSY       0x80260002
#define PSP_USBMIC_ERROR_INVALID_CH        0x80260003
#define PSP_USBMIC_ERROR_PRIV_REQUIRED     0x80260004
#define PSP_USBMIC_ERROR_NOT_FOUND         0x80260005
#define PSP_USBMIC_ERROR_INVALID_SIZE      0x80260006
#define PSP_USBMIC_ERROR_INVALID_FORMAT    0x80260007
#define PSP_USBMIC_ERROR_NOT_RESERVED      0x80260008
#define PSP_USBMIC_ERROR_NOT_OUTPUT        0x80260009
#define PSP_USBMIC_ERROR_INVALID_FREQUENCY 0x8026000A
#define PSP_USBMIC_ERROR_INVALID_VOLUME    0x8026000B
#define PSP_USBMIC_ERROR_INPUT_BUSY        0x80260010

#define PSP_USBMIC_DRIVERNAME              "USBMicDriver"
#define PSP_USBMIC_PID                     0x025B

/**
  * Init audio input
  *
  * @param unknown1 - Unknown. Pass 0.
  *
  * @param gain - Gain.
  *
  * @param unknown2 - Unknown. Pass 0.
  *
  * @return 0 on success, an error if less than 0.
  */
int sceUsbMicInputInit(int unk, int vol, int unk2);

/**
  * Init audio input (with extra arguments)
  *
  * @param params - A pointer to a ::pspAudioInputParams struct.
  *
  * @return 0 on success, an error if less than 0.
  */
int sceUsbMicInputInitEx(pspAudioInputParams *params);

/**
  * Perform audio input (blocking)
  *
  * @param samplecount - Number of samples.
  *
  * @param freq - Either 44100, 22050 or 11025.
  *
  * @param buf - Pointer to where the audio data will be stored.
  *
  * @return 0 on success, an error if less than 0.
  */
int sceUsbMicInputBlocking(int samplecount, int freq, void *buf);

/**
  * Perform audio input
  *
  * @param samplecount - Number of samples.
  *
  * @param freq - Either 44100, 22050 or 11025.
  *
  * @param buf - Pointer to where the audio data will be stored.
  *
  * @return 0 on success, an error if less than 0.
  */
int sceUsbMicInput(int samplecount, int freq, void *buf);

/**
  * Get the number of samples that were acquired
  *
  * @return Number of samples acquired, an error if less than 0.
  */
int sceUsbMicGetInputLength(void);

/**
  * Wait for non-blocking audio input to complete
  *
  * @return 0 on success, an error if less than 0.
  */
int sceUsbMicWaitInputEnd(void);

/**
  * Poll for non-blocking audio input status
  *
  * @return 0 if input has completed, 1 if not completed or an error if less than 0.
  */
int sceUsbMicPollInputEnd(void);

#ifdef __cplusplus
}
#endif

#endif
