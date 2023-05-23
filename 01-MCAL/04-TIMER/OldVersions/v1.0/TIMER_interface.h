/************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 9 April , 2023
* SWC	  : TIMER
* Layer   : MCAL
* Version : 1.0
*************************************************************************/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

/*************************TIMER0 Functions**********************************/

void TIMER0_voidInit(void);

void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue);

void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8CTCValue);

void TIMER0_voidEnableInterrupt(u8 Copy_u8TIMERMode);

void TIMER0_voidDisableInterrupt(u8 Copy_u8TIMERMode);

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32BusywaitedTime);

void TIMER0_voidSetBusyWait_CTCMode(u32 Copy_u32Time);

void TIMER0_voidSetOVFCallBack(void (*pvNotificationFunction)(void));

void TIMER0_voidSetCTCCallBack(void (*pvNotificationFunction)(void));

#endif
