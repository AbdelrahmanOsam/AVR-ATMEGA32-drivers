/**********************************************************************
* Author  : Abdelrahman Osam Khaled
* Date 	  : 6 April,2023
* SWC	  : LM35 temperature sensor
* Version : 1.0
* Layer	  : HAL
*********************************************************************/

#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

typedef struct {
			u8 LM35_PORT;
			u8 LM35_PIN;
	
			}LM35;
			
void HLM35_voidInit(LM35 *LM35obj);

#endif