/*************************************************************************
* Author : Abdelrahman Osam Khaled
* Date : 28 March , 2023
* SWC : LED
* Version : 1.0
***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

#include "DIO_interface.h"

void LED_voidInit(LED *LEDobj)
{
	DIO_u8SetPinDirection(LEDobj->LED_PORT,LEDobj->LED_PIN,DIO_OUTPUT);
}
void LED_voidLEDTurnON(LED *LEDobj)
{
	DIO_u8SetPinValue(LEDobj->LED_PORT,LEDobj->LED_PIN,DIO_HIGH);
}

void LED_voidLEDTurnOFF(LED *LEDobj)
{
	DIO_u8SetPinValue(LEDobj->LED_PORT,LEDobj->LED_PIN,DIO_LOW);
}

/*void LED_voidLEDToggle(LED_t *LEDobj)
{
	// reverse the state of pin
}*/
