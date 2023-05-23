/**********************************************************************
* Author : Abdelrahman Osam Khaled
* Date	 : 26 March , 2023
* SWC	 : LCD
* Version : 1.0
************************************************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define EIGHT_BIT_MODE	1
#define FOUR_BIT_MODE	0

#define LCD_ALL_OUTPUT			0xFF

#define FUNCTION_SET_COMMAND	0x38 //0b00111000

#define DISPLAY_ON_OFF_COMMAND	0x0F

#define DISPLAY_CLEAR_COMMAND	0x01

static void LCD_voidSendCommand(u8 Copy_u8Command);

#endif