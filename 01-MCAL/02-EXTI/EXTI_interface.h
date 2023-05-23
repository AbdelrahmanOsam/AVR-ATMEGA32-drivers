/*************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 29 March , 2023
* SWC	  : EXTI 
* Layer	  : MCAL
* version : 1.0
*************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef struct
{
	u8 Local_u8EXTIPort;
	u8 Local_u8EXTIPin;
}EXTI;

//void EXTI_voidInit(EXTI *EXTI_obj)

void EXTI_voidInit(u8 Copy_u8InterruptNumber);
void EXTI_voidInterruptSenseMode(u8 Copy_u8InterruptNumber,u8 Copy_u8SenseMode);

void EXTI_voidEnableInterrupt(u8 Copy_u8InterruptNumber);

void EXTI_voidDisableInterrupt(u8 Copy_u8InterruptNumber);

void EXTI_voidINTSetCallback(u8 Copy_u8EXTIIndex,void (*NotificationFunction)(void));

/*** Macros for Sense mode ***/
#define EXTI_LOW_LEVEL					0
#define EXTI_ANY_LOGICAL_CHANGE			1
#define EXTI_FALLING_EDGE				2
#define EXTI_RISING_EDGE				3

/*** Macros for EXTI pins ***/
#define EXTI_INT0						0
#define EXTI_INT1						1
#define EXTI_INT2						2



#endif