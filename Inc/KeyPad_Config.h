/*
 * KeyPad_Config.h
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */

#ifndef INC_KEYPAD_CONFIG_H_
#define INC_KEYPAD_CONFIG_H_

#include "GPIO_interface.h"
#include <stdint.h>

#define KEYPAD_ROWS         4
#define KEYPAD_COLUMNS      4



#define KEYPAD_ROW_PORT		        PORTB

#define KEYPAD_ROW_1_PIN			PIN4
#define KEYPAD_ROW_2_PIN			PIN5
#define KEYPAD_ROW_3_PIN			PIN6
#define KEYPAD_ROW_4_PIN			PIN7

#define KEYPAD_COLUMN_PORT		    PORTC

#define KEYPAD_COLUMN_1_PIN			PIN5
#define KEYPAD_COLUMN_2_PIN			PIN6
#define KEYPAD_COLUMN_3_PIN			PIN7
#define KEYPAD_COLUMN_4_PIN			PIN8

/************** Mapping Keypad Buttons *********************/
uint8_t KEYPAD_ButtonValues[KEYPAD_ROWS][KEYPAD_COLUMNS]={
	{'1','2','3','+'},
	{'4','5','6','-'},
	{'7','8','9','C'},
	{'*','0','=','/'},

};

#endif /* INC_KEYPAD_CONFIG_H_ */
