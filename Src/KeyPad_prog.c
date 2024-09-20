/*
 * KeyPad_prog.c
 *
 *  Created on: Sep 18, 2024
 *      Author: ahmed
 */
#include "KeyPad_Config.h"
#include "LCD_Interface.h"
#include "GPIO_interface.h"


PinConfig_t Row_pin1;
PinConfig_t Row_pin2;
PinConfig_t Row_pin3;
PinConfig_t Row_pin4;



/* Correct Pin Configuration for Keypad */
PinConfig_t Key_Pad_PinConfig[4] = {
    {KEYPAD_COLUMN_PORT, KEYPAD_COLUMN_1_PIN, OUTPUT, MEDIUM, PUSH_PULL, PULLUP},
    {KEYPAD_COLUMN_PORT, KEYPAD_COLUMN_2_PIN, OUTPUT, MEDIUM, PUSH_PULL, PULLUP},
    {KEYPAD_COLUMN_PORT, KEYPAD_COLUMN_3_PIN, OUTPUT, MEDIUM, PUSH_PULL, PULLUP},
    {KEYPAD_COLUMN_PORT, KEYPAD_COLUMN_4_PIN, OUTPUT, MEDIUM, PUSH_PULL, PULLUP},

};








/************* Function to initialize Keypad ************/
void KEYPAD_init(void) {
    uint8_t Loc_iterator = 0;


    Row_pin1.Port=KEYPAD_ROW_PORT;
    Row_pin1.PinNum=KEYPAD_ROW_1_PIN;
    Row_pin1.Mode=INPUT;
    Row_pin1.OutputType=PUSH_PULL;
    Row_pin1.PullType=PULLUP;

    Row_pin2.Port=KEYPAD_ROW_PORT;
    Row_pin2.PinNum=KEYPAD_ROW_2_PIN;
    Row_pin2.Mode=INPUT;
    Row_pin2.OutputType=PUSH_PULL;
    Row_pin2.PullType=PULLUP;

    Row_pin3.Port=KEYPAD_ROW_PORT;
    Row_pin3.PinNum=KEYPAD_ROW_3_PIN;
    Row_pin3.Mode=INPUT;
    Row_pin3.OutputType=PUSH_PULL;
    Row_pin3.PullType=PULLUP;

    Row_pin4.Port=KEYPAD_ROW_PORT;
    Row_pin4.PinNum=KEYPAD_ROW_4_PIN;
    Row_pin4.Mode=INPUT;
    Row_pin4.OutputType=PUSH_PULL;
    Row_pin4.PullType=PULLUP;
    /* Initialize all columns as output and rows as input */
    GPIO_u8PinInit(&Row_pin1);
    GPIO_u8PinInit(&Row_pin2);
    GPIO_u8PinInit(&Row_pin3);
    GPIO_u8PinInit(&Row_pin4);

    for (Loc_iterator = 0; Loc_iterator < 4; Loc_iterator++) {
        GPIO_u8PinInit(&Key_Pad_PinConfig[Loc_iterator]);
    }
}

/************ Function to return the pressed key *************/
uint8_t KEYPAD_GetPressedKey(void) {
    uint8_t Loc_rand_var = 0xFF;

    /* Arrays holding the column and row pins */
    uint16_t Loc_u8_arr_col[4] = {
        KEYPAD_COLUMN_1_PIN,
        KEYPAD_COLUMN_2_PIN,
        KEYPAD_COLUMN_3_PIN,
        KEYPAD_COLUMN_4_PIN
    };

    uint16_t Loc_u8_arr_row[4] = {
        KEYPAD_ROW_1_PIN,
        KEYPAD_ROW_2_PIN,
        KEYPAD_ROW_3_PIN,
        KEYPAD_ROW_4_PIN
    };

    uint8_t Loc_u8_row_iterator = 0;
    uint8_t Loc_u8_column_iterator = 0;
    uint8_t Loc_Val = 0;

    for (Loc_u8_column_iterator = 0; Loc_u8_column_iterator < KEYPAD_COLUMNS; Loc_u8_column_iterator++) {
        /* Set the current column to LOW */
        GPIO_u8SetPinValue(KEYPAD_COLUMN_PORT, Loc_u8_arr_col[Loc_u8_column_iterator], PIN_LOW);

        for (Loc_u8_row_iterator = 0; Loc_u8_row_iterator < KEYPAD_ROWS; Loc_u8_row_iterator++) {
            /* Read the current row's value */
            GPIO_u8ReadPinValue(KEYPAD_ROW_PORT, Loc_u8_arr_row[Loc_u8_row_iterator], &Loc_Val);

            if (Loc_Val == 0) {  // Button is pressed
                /* Get the corresponding button value */
                Loc_rand_var = KEYPAD_ButtonValues[Loc_u8_row_iterator][Loc_u8_column_iterator];

                /* Wait for key release */
                do {
                    GPIO_u8ReadPinValue(KEYPAD_ROW_PORT, Loc_u8_arr_row[Loc_u8_row_iterator], &Loc_Val);
                } while (Loc_Val == 0);  // Loop until the button is released

                return Loc_rand_var;  // Return the pressed key value
            }
        }

        /* Reset the column back to HIGH */
        GPIO_u8SetPinValue(KEYPAD_COLUMN_PORT, Loc_u8_arr_col[Loc_u8_column_iterator], PIN_HIGH);
    }

    return Loc_rand_var;
}


uint16_t GetNumberFromKeypad(void) {
    uint16_t number = 0;
    uint8_t key;

    while (1) {
        key = KEYPAD_GetPressedKey();

        if (key == 0xFF) continue; // No key pressed

        if (key == '=' || key == '+' || key == '-' || key == '*' || key == '/') {
            return number; // End of number input
        } else if (key >= '0' && key <= '9') {
            number = number * 10 + (key - '0'); // Append digit
            LCD_voidSendNum(key - '0'); // Display digit
        } else if (key == 'C') {
            LCD_voidSendCommand(0x01); // Clear display
            return 0; // Start over
        }
    }
}


