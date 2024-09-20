/*
 * calculator.h
 *
 *  Created on: Sep 20, 2024
 *      Author: ahmed
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

/********* Function Declarations *********/
void resetCalculator();
void handleNumberInput(uint8_t key);
void handleOperatorInput(uint8_t key);
void calculateResult();
void calculatorLoop();

#endif /* CALCULATOR_H_ */
