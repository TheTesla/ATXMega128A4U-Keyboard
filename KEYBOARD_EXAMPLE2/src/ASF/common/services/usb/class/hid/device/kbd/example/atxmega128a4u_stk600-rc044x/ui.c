/**
 * \file
 *
 * \brief User Interface
 *
 * Copyright (c) 2011 - 2012 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#include <asf.h>
#include "ui.h"

void ui_init(void){}
void ui_powerdown(void){}
void ui_wakeup_enable(void){}
void ui_wakeup_disable(void){}

void ui_wakeup(void){}

void ui_process(uint16_t framenumber)
{
	static int32_t i = 0;
	i+=1;
	
	switch(i){
		case 10:
		udi_hid_kbd_down(HID_H);
		udi_hid_kbd_up(HID_H);
		break;
		case 20:
		udi_hid_kbd_down(HID_A);
		udi_hid_kbd_up(HID_A);
		break;
		case 30:
		udi_hid_kbd_down(HID_L);
		udi_hid_kbd_up(HID_L);
		break;
		case 40:
		udi_hid_kbd_down(HID_L);
		udi_hid_kbd_up(HID_L);
		break;
		case 50:
		udi_hid_kbd_down(HID_O);
		udi_hid_kbd_up(HID_O);
		break;
		case 60:
		udi_hid_kbd_down(HID_SPACEBAR);
		udi_hid_kbd_up(HID_SPACEBAR);
		break;
		case 70:
		udi_hid_kbd_down(HID_W);
		udi_hid_kbd_up(HID_W);
		break;
		case 80:
		udi_hid_kbd_down(HID_E);
		udi_hid_kbd_up(HID_E);
		break;
		case 90:
		udi_hid_kbd_down(HID_L);
		udi_hid_kbd_up(HID_L);
		break;
		case 100:
		udi_hid_kbd_down(HID_T);
		udi_hid_kbd_up(HID_T);
		break;
		case 110:
		udi_hid_kbd_down(HID_ENTER);
		udi_hid_kbd_up(HID_ENTER);
		break;		case 500:
		i = 0;
		default:
		break;
	}

}

void ui_kbd_led(uint8_t value)
{
}

/**
 * \defgroup UI User Interface
 *
 * Human interface on STK600:
 * - Led 0 is on when USB line is in IDLE mode, and off in SUSPEND mode
 * - Led 1 blinks when USB host has checked and enabled HID Keyboard interface
 * - Led 2 displays numeric lock status.
 * - Led 3 displays caps lock status.
 * - The switch 0 open a note pad application on Windows O.S.
 * and send key sequence "Atmel AVR USB Keyboard"
 * - The switch 0 can be used to wakeup USB Host in remote wakeup mode.
 *
 * Setup for STK600:
 * - LEDS connector is connected to PORTA
 * - SWITCHES are connected to PORTB
 * - Warning! The AREF1 jumper must be removed
 * because AREF1 connected on PORTB0 overrides switch 0.
 */
