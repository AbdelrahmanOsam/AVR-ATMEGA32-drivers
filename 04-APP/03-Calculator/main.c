/*
 * main.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Abd El Rahman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"
#include "Keypad_interface.h"

#include "DIO_interface.h"


int main(void)
{
	u8 Local_u8PressedKey;
	LCD_voidInit();
	Keypad_voidInit();
	while(1)
	{
		do
		{
			Local_u8PressedKey = Keypad_u8GetPressedKey();
		}while(Local_u8PressedKey == 255);

//		Local_u8PressedKey = Keypad_u8GetPressedKey();
//		while(Local_u8PressedKey == 255)
	//	{
//			Local_u8PressedKey = Keypad_u8GetPressedKey();
//		}
		LCD_voidSendNumber(Local_u8PressedKey);
	}
	return 0;
}
