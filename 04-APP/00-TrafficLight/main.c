/*
 * main.c
 *
 *  Created on: Mar 28, 2023
 *      Author: Abd El Rahman
 */

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SevenSegment_interface.h"
#include "LED_interface.h"

int main (void)
{
	/* Initialize LEDs */
	LED LED0={DIO_PORTA,DIO_PIN0};
	LED LED1={DIO_PORTA,DIO_PIN1};
	LED LED2={DIO_PORTA,DIO_PIN2};

	LED_voidInit(&LED0);
	LED_voidInit(&LED1);
	LED_voidInit(&LED2);

	/* Initialize Seven Segment */
	SevenSegment SevenSegment0={DIO_PORTB};
	SevenSegment SevenSegment1={DIO_PORTD};

	SevenSegment_voidInit(&SevenSegment0);
	SevenSegment_voidInit(&SevenSegment1);

	while(1)
	{
		/* Turn on RED LED and count from 10 to 0 */
		LED_voidLEDTurnOFF(&LED2);
		LED_voidLEDTurnON(&LED0);
		SevenSegment_voidDisplayNumber1(&SevenSegment0);
		SevenSegment_voidDisplayNumber0(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber9(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber8(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber7(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber6(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber5(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber4(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber3(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber2(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber1(&SevenSegment1);
		_delay_ms(1000);

		/* Turn Yellow LED and count from 3 to 0 */
		LED_voidLEDTurnOFF(&LED0);
		LED_voidLEDTurnON(&LED1);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber3(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber2(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber1(&SevenSegment1);
		_delay_ms(1000);

		/* Turn on Green LED and count from 10 to 0 */
		LED_voidLEDTurnOFF(&LED1);
		LED_voidLEDTurnON(&LED2);
		SevenSegment_voidDisplayNumber1(&SevenSegment0);
		SevenSegment_voidDisplayNumber0(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber9(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber8(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber7(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber6(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber5(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber4(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber3(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber2(&SevenSegment1);
		_delay_ms(1000);
		SevenSegment_voidDisplayNumber0(&SevenSegment0);
		SevenSegment_voidDisplayNumber1(&SevenSegment1);
		_delay_ms(1000);
	}
}
