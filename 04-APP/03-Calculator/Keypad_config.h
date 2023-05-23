/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 28 March , 2023
* SWC     : Keypad
* Version : 1.0
*******************************************************************/

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

#define KEYPAD_ROWS_PORT		DIO_PORTD
#define KEYPAD_COLUMNS_PORT		DIO_PORTD

#define KEYPAD_ROW0_PIN			DIO_PIN0
#define KEYPAD_ROW1_PIN			DIO_PIN1
#define KEYPAD_ROW2_PIN			DIO_PIN2
#define KEYPAD_ROW3_PIN			DIO_PIN3

#define KEYPAD_COLUMN0_PIN		DIO_PIN4
#define KEYPAD_COLUMN1_PIN		DIO_PIN5
#define KEYPAD_COLUMN2_PIN		DIO_PIN6
#define KEYPAD_COLUMN3_PIN		DIO_PIN7


/* est5mna al ascii code '' 34an de values httb3t ll MC */
#define KEYPAD_ARR_VAL {{'1','2','3','/'},{'4','5','6','*'},{'7','8','9','-'},{'%','0','=','+'},}
#define KEYPAD_ROWS_NUM			4
#define KEYPAD_COLUMNS_NUM		4

#define KEYPAD_NOT_PRESSED_VALUE	255

#endif
