/*******************************************************************
* Author : Abdelrahman Osam Khaled
* Date : 28 March , 2023
* SWC : Seven segment numbers
* Version : 1.0
*******************************************************************/

#include "STD_TYPES.h"
#include "BITMATH.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"
#include "SevenSegment_config.h"

#include "DIO_interface.h"

void SevenSegment_voidInit(SevenSegment *SevenSegmentobj);
{
	DIO_u8SetPortDirection(SevenSegmentobj->SevenSegment_PORT,0xFF);
}

void SevenSegment_voidDispalyNumber0(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_LOW);
}

void SevenSegment_voidDisplayNumber1(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_LOW);
}

void SevenSegment_voidDisplayNumber2(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_HIGH);
}

void SevenSegment_voidDisplayNumber3(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_HIGH);
}

void SevenSegment_voidDisplayNumber4(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_HIGH);
}

void SevenSegment_voidDisplayNumber5(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_HIGH);
}

void SevenSegment_voidDisplayNumber6(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_HIGH);
}

void SevenSegment_voidDisplayNumber7(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_LOW);
}

void SevenSegment_voidDisplayNumber8(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_HIGH);
}

void SevenSegment_voidDisplayNumber9(void)
{
	DIO_u8SetPinValue(LED_PORT,DIO_PIN0,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN1,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN2,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN3,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN4,DIO_LOW);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN5,DIO_HIGH);
	DIO_u8SetPinValue(LED_PORT,DIO_PIN6,DIO_HIGH);
}