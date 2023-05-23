/**********************************************************************
* Author  : Abdelrahman Osam Khaled
* Date 	  : 6 April,2023
* SWC	  : LM35 temperature sensor
* Version : 1.0
* Layer	  : HAL
*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LM35_interface.h"
#include "LM35_private.h"
#include "LM35_config.h"

#include "DIO_interface.h"

void HLM35_voidInit(LM35 *LM35obj)
{
	DIO_u8SetPinDirection(LM35obj->LM35_PORT,LM35obj->LM35_PIN,DIO_INPUT);
}