/*
 * calculator.c
 *
 *  Created on: Sep 20, 2024
 *      Author: ahmed
 */


#include <stdint.h>
#include "GPIO_interface.h"
#include "LCD_Interface.h"
#include "KeyPad_Interface.h"



/* Global variables */
float num1 = 0;
float num2 = 0;
float Loc_Sum = 0;
char operator = 0;
uint8_t isNum1Entered = 0;  // Flag to track if num1 has been fully entered
uint8_t isOperatorEntered = 0;  // Flag to track if the operator has been entered





/********* Function Definitions *********/

// Resets the calculator variables and LCD display
void resetCalculator() {
    num1 = 0;
    num2 = 0;
    Loc_Sum = 0;
    operator = 0;
    isNum1Entered = 0;
    isOperatorEntered = 0;
    LCD_voidSendCommand(0x01);  // Clear display
}

// Handles number input and stores it in the correct variable (num1 or num2)
void handleNumberInput(uint8_t key) {
    if (!isOperatorEntered) {
        num1 = (num1 * 10) + (key - '0');
        LCD_voidSendNum(key - '0');
    } else {
        num2 = (num2 * 10) + (key - '0');
        LCD_voidSendNum(key - '0');
    }
}

// Handles operator input and sets the operator for calculation
void handleOperatorInput(uint8_t key) {
    if (!isOperatorEntered) {
        operator = key;
        LCD_voidSendData(operator);
        isOperatorEntered = 1;
    }
}

// Performs the calculation based on the operator and displays the result
void calculateResult() {
    switch (operator) {
        case '+':
            Loc_Sum = num1 + num2;
            break;
        case '-':
            Loc_Sum = num1 - num2;
            break;
        case '*':
            Loc_Sum = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                Loc_Sum = num1 / num2;
            } else {
                LCD_voidSendString("Err");  // Display error for division by zero
                return;
            }
            break;
        default:
            return;
    }
    LCD_SetGridPos(0,1);
    LCD_voidSendData('=');
    LCD_voidSendNum(Loc_Sum);
}

/********* Main Calculator Loop *********/
void calculatorLoop() {
    uint8_t Loc_KeyVal = 0;

    resetCalculator();  // Initialize the calculator

    while (1) {
        Loc_KeyVal = KEYPAD_GetPressedKey();

        if (Loc_KeyVal == 0xFF) {
            continue;  // No key pressed
        }

        if (Loc_KeyVal >= '0' && Loc_KeyVal <= '9') {
            handleNumberInput(Loc_KeyVal);  // Handle number input
        } else if (Loc_KeyVal == '+' || Loc_KeyVal == '-' || Loc_KeyVal == '*' || Loc_KeyVal == '/') {
            handleOperatorInput(Loc_KeyVal);  // Handle operator input
        } else if (Loc_KeyVal == '=') {
            calculateResult();  // Perform the calculation and display the result
        } else if (Loc_KeyVal == 'C') {
            resetCalculator();  // Clear the display and reset variables
        }
    }
}
