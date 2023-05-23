/**********************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 26 March , 2023
* SWC	  : LCD
* Version : 1.0
************************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#define LCD_DATA_PORT	DIO_PORTA
/* Options for ports:
				- DIO_PORTA
				- DIO_PORTB
				- DIO_PORTC
				- DIO_PORTD
*/
#define LCD_INIT_MODE	EIGHT_BIT_MODE
/* Options for modes:
				- EIGHT_BIT_MODE
				- FOUR_BIT_MODE
*/

#define LCD_CTRL_PORT	DIO_PORTB
/* Options for ports:
				- DIO_PORTA
				- DIO_PORTB
				- DIO_PORTC
				- DIO_PORTD
*/

#define LCD_RW_PIN	DIO_PIN0
#define LCD_RS_PIN	DIO_PIN1
#define LCD_EN_PIN	DIO_PIN2

/* Options for Pins:
				- DIO_PIN0
				- DIO_PIN1
				- DIO_PIN2
				- DIO_PIN3
				- DIO_PIN4
				- DIO_PIN5
				- DIO_PIN6
				- DIO_PIN7
*/
#endif