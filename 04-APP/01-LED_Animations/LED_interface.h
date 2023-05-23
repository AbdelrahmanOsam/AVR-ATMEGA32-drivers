/*************************************************************************
* Author : Abdelrahman Osam Khaled
* Date : 28 March , 2023
* SWC : LED
* Version : 1.0
***********************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef struct
{
			u8 LED_PORT;
			u8 LED_PIN;
	
			}LED;
			
void LED_voidInit(LED *LEDobj);
void LED_voidLEDTurnON(LED *LEDobj);
void LED_voidLEDTurnOFF(LED *LEDobj);
//void LED_voidLEDToggle(LED_t *LEDobj);
		
#endif
