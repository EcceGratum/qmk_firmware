// Copyright 2023 eccegratum (@eccegratum)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//#define RIGHT_PART

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define DEBUG_MATRIX_SCAN_RATE

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25

#define SPLIT_USB_DETECT
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_OLED_ENABLE

#define RGBLIGHT_DEFAULT_ON true // Enable RGB lighting by default
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT // Set default mode to static light
//#define RGB_MATRIX_TIMEOUT 300000 // number of milliseconds to wait until rgb automatically turns off
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)

#define SERIAL_USART_DRIVER SD0
#define SERIAL_USART_FULL_DUPLEX
#ifdef RIGHT_PART
// RX & TX from 3.5mm jack is not swapped so swap on firmware
//	#define SERIAL_USART_TX_PIN GP12
//	#define SERIAL_USART_RX_PIN GP13
	#define SERIAL_USART_TX_PIN GP13
	#define SERIAL_USART_RX_PIN GP12
	#define WS2812_DI_PIN GP27
#else
	#define SERIAL_USART_TX_PIN GP22
	#define SERIAL_USART_RX_PIN GP17
	#define WS2812_DI_PIN GP6
#endif
 
#ifdef OLED_ENABLE
//#define OLED_DISPLAY_128X32
//#define SPLIT_OLED_ENABLE
//#define SPLIT_LAYER_STATE_ENABLE

#ifdef RIGHT_PART
	#define I2C_DRIVER I2CD1
//	#define I2C0_SCL_PIN        GP11
//	#define I2C0_SDA_PIN        GP10
	
	#define I2C1_SCL_PIN        GP11
	#define I2C1_SDA_PIN        GP10
	
//	#define I2C2_SCL_PIN        GP11
//	#define I2C2_SDA_PIN        GP10

#else
	#define I2C_DRIVER I2CD0	
	#define I2C1_SCL_PIN        GP21
	#define I2C1_SDA_PIN        GP20
#endif

#define OLED_BRIGHTNESS 127
#define OLED_FONT_H "keyboards/piantor_mx_rgb/lib/glcdfont.c"
//#define OLED_DISABLE_TIMEOUT
#define OLED_TIMEOUT 60000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 15
#define OLED_UPDATE_INTERVAL 50
#endif
