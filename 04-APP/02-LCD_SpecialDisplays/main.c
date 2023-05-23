/*
 * main.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Abd El Rahman
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include <util/delay.h>

#include "LCD_interface.h"
#include "DIO_interface.h"

int main (void)
{
	LCD_voidInitialization();
		LCD_voidGoToXY(0,0);
		LCD_voidSendString ("My name is");
		LCD_voidGoToXY(1,0);
		LCD_voidSendString ("Za3boula :");

		u8 Human_Arr1[] = { 0x0E,
				  0x0E,
				  0x04,
				  0x0E,
				  0x15,
				  0x04,
				  0x0E,
				  0x11};

		LCD_voidSendCustomCharacter(Human_Arr1,0b00000000,1,12);

		_delay_ms(2000);
		LCD_voidClearDisplay();

		LCD_voidGoToXY(0,0);
		LCD_voidSendString ("I can Play");
		LCD_voidGoToXY(1,0);
		LCD_voidSendString (" Football :");
		u8 Human_Arr2[] = { 0x07,
				  0x07,
				  0x02,
				  0x07,
				  0x0A,
				  0x06,
				  0x0A,
				  0x12};
		u8 Ball_arr[]= { 0x00,
				  0x00,
				  0x00,
				  0x00,
				  0x0E,
				  0x0E,
				  0x0E,
				  0x00};
		LCD_voidSendCustomCharacter(Human_Arr2,0b00000000,1,13);
		//LCD_voidSendCustomCharacter(Human_Arr4,0b00000001,1,13);
		LCD_voidSendCustomCharacter(Ball_arr,0b00000001,1,12);
		_delay_ms(2000);

		LCD_voidClearDisplay();

		LCD_voidGoToXY(0,0);
		LCD_voidSendString ("Let's play");
		LCD_voidGoToXY(1,0);
		LCD_voidSendString (" A game :");

		u8 Eye_Arr[]={ 0x0E,
				  0x11,
				  0x00,
				  0x1F,
				  0x11,
				  0x11,
				  0x1F,
				  0x00};
		u8 Mouse_Arr[] = {0x00,
				  0x00,
				  0x00,
				  0x11,
				  0x11,
				  0x1F,
				  0x1F,
				  0x00};
		LCD_voidSendCustomCharacter(Eye_Arr,0b00000000,0,13);
		LCD_voidSendCustomCharacter(Eye_Arr,0b00000001,0,11);
		LCD_voidSendCustomCharacter(Mouse_Arr,0b00000011,1,12);
		_delay_ms(2000);

		LCD_voidClearDisplay();

		u8 Gun_Arr[] = {0x00,
				  0x1F,
				  0x18,
				  0x14,
				  0x18,
				  0x10,
				  0x00,
				  0x00};
		u8 dash_Arr[]={ 0x00,
				  0x1F,
				  0x00,
				  0x00,
				  0x00,
				  0x00,
				  0x00,
				  0x00};
		LCD_voidSendCustomCharacter(Gun_Arr,0b00000000,0,0);
		LCD_voidSendCustomCharacter(dash_Arr,0b00000001,0,1);
		_delay_ms(100);
		LCD_voidSendCustomCharacter(dash_Arr,0b00000001,0,2);
		_delay_ms(100);
		LCD_voidSendCustomCharacter(dash_Arr,0b00000001,0,3);
		_delay_ms(100);
		LCD_voidSendCustomCharacter(dash_Arr,0b00000001,0,4);
		_delay_ms(100);
		LCD_voidSendCustomCharacter(dash_Arr,0b00000001,0,5);
		_delay_ms(100);
		LCD_voidGoToXY(0,6);
		LCD_voidSendString ("Don't Kill");
		LCD_voidGoToXY(1,6);
		LCD_voidSendString (" me :");
		LCD_voidSendCustomCharacter(Human_Arr1,0b00000010,1,14);
		_delay_ms(1000);


	return 0;
}
