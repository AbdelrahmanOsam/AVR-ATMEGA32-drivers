/*
 * main.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Abd El Rahman
 */

#include<util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"

int main (void)
{
	/* Initialize LEDs */
	LED LED0={DIO_PORTA,DIO_PIN0};
	LED LED1={DIO_PORTA,DIO_PIN1};
	LED LED2={DIO_PORTA,DIO_PIN2};
	LED LED3={DIO_PORTA,DIO_PIN3};
	LED LED4={DIO_PORTA,DIO_PIN4};
	LED LED5={DIO_PORTA,DIO_PIN5};
	LED LED6={DIO_PORTA,DIO_PIN6};
	LED LED7={DIO_PORTA,DIO_PIN7};

	LED_voidInit(&LED0);
	LED_voidInit(&LED1);
	LED_voidInit(&LED2);
	LED_voidInit(&LED3);
	LED_voidInit(&LED4);
	LED_voidInit(&LED5);
	LED_voidInit(&LED6);
	LED_voidInit(&LED7);

	DIO_u8SetPortDirection(DIO_PORTC,0x00);
	DIO_u8SetPortValue(DIO_PORTC,0x00);

	while(1)
	{
		/* Toggle all LEDs */
		while (DIO_u8GetPinValue(DIO_PORTC,DIO_PIN0)==1)
		{
			LED_voidLEDTurnON(&LED0);
			LED_voidLEDTurnON(&LED1);
			LED_voidLEDTurnON(&LED2);
			LED_voidLEDTurnON(&LED3);
			LED_voidLEDTurnON(&LED4);
			LED_voidLEDTurnON(&LED5);
			LED_voidLEDTurnON(&LED6);
			LED_voidLEDTurnON(&LED7);
			_delay_ms(500);
			LED_voidLEDTurnOFF(&LED0);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnOFF(&LED3);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnOFF(&LED7);
			_delay_ms(500);
		}
		/* descending LEDs */
		while(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN1)==1)
		{
			LED_voidLEDTurnON(&LED7);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED7);
			LED_voidLEDTurnON(&LED6);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnON(&LED5);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnON(&LED4);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnON(&LED3);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED3);
			LED_voidLEDTurnON(&LED2);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnON(&LED1);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnON(&LED0);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED0);
		}
		/* Ascending LEDs */
		while(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN2)==1)
		{
			LED_voidLEDTurnON(&LED0);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED0);
			LED_voidLEDTurnON(&LED1);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnON(&LED2);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnON(&LED3);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED3);
			LED_voidLEDTurnON(&LED4);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnON(&LED5);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnON(&LED6);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnON(&LED7);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED7);
		}
		while(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN3)==1)
		{
			LED_voidLEDTurnON(&LED7);
			LED_voidLEDTurnON(&LED0);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED7);
			LED_voidLEDTurnOFF(&LED0);
			LED_voidLEDTurnON(&LED6);
			LED_voidLEDTurnON(&LED1);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnON(&LED5);
			LED_voidLEDTurnON(&LED2);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnON(&LED4);
			LED_voidLEDTurnON(&LED3);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnOFF(&LED3);
		}
		while(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN4)==1)
		{
			LED_voidLEDTurnON(&LED4);
			LED_voidLEDTurnON(&LED3);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnOFF(&LED3);
			LED_voidLEDTurnON(&LED5);
			LED_voidLEDTurnON(&LED2);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnON(&LED6);
			LED_voidLEDTurnON(&LED1);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnON(&LED7);
			LED_voidLEDTurnON(&LED0);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED7);
			LED_voidLEDTurnOFF(&LED0);
		}
				/* Ping pong LEDS */
		while(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN5)==1)
		{
			LED_voidLEDTurnON(&LED0);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED0);
			LED_voidLEDTurnON(&LED1);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnON(&LED2);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnON(&LED3);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED3);
			LED_voidLEDTurnON(&LED4);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnON(&LED5);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnON(&LED6);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnON(&LED7);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED7);
		}
		while(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN6)==1)
		{
			LED_voidLEDTurnON(&LED0);
			_delay_ms(250);
			LED_voidLEDTurnON(&LED1);
			_delay_ms(250);
			LED_voidLEDTurnON(&LED2);
			_delay_ms(250);
			LED_voidLEDTurnON(&LED3);
			_delay_ms(250);
			LED_voidLEDTurnON(&LED4);
			_delay_ms(250);
			LED_voidLEDTurnON(&LED5);
			_delay_ms(250);
			LED_voidLEDTurnON(&LED6);
			_delay_ms(250);
			LED_voidLEDTurnON(&LED7);
			_delay_ms(250);
			LED_voidLEDTurnOFF(&LED0);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnOFF(&LED3);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnOFF(&LED7);
		}
		while(DIO_u8GetPinValue(DIO_PORTC,DIO_PIN7)==1)
		{
			LED_voidLEDTurnON(&LED7);
			LED_voidLEDTurnON(&LED0);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED7);
			LED_voidLEDTurnOFF(&LED0);
			LED_voidLEDTurnON(&LED6);
			LED_voidLEDTurnON(&LED1);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnON(&LED5);
			LED_voidLEDTurnON(&LED2);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnON(&LED4);
			LED_voidLEDTurnON(&LED3);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnOFF(&LED3);

			LED_voidLEDTurnON(&LED4);
			LED_voidLEDTurnON(&LED3);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED4);
			LED_voidLEDTurnOFF(&LED3);
			LED_voidLEDTurnON(&LED5);
			LED_voidLEDTurnON(&LED2);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED5);
			LED_voidLEDTurnOFF(&LED2);
			LED_voidLEDTurnON(&LED6);
			LED_voidLEDTurnON(&LED1);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED6);
			LED_voidLEDTurnOFF(&LED1);
			LED_voidLEDTurnON(&LED7);
			LED_voidLEDTurnON(&LED0);
			_delay_ms(300);
			LED_voidLEDTurnOFF(&LED7);
			LED_voidLEDTurnOFF(&LED0);
		}

	}
	return 0;
}

