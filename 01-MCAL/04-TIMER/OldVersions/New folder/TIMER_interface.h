/************************************************************************
* Author : Abdelrahman Osam Khaled
* Date	: 9 April , 2023
* SWC	 : TIMER
* Layer  : MCAL
* Version : 1.0
*************************************************************************/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void TIMER0_voidInit(void);

void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue);

void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8CTCValue);

void TIMER0_voidEnableInterrupt(u8 Copy_u8TIMERMode);

void TIMER0_voidDisableInterrupt(u8 Copy_u8TIMERMode);

void TIMER0_voidSetOVFCallBack(void (*pvNotificationFunction)(void));

void TIMER0_voidSetCTCCallBack(void (*pvNotificationFunction)(void));

void TIMER0_voidSetBusyWaitMS(u32 Copy_u32BusywaitedTime);

#define TIMER0_NORMAL_MODE 		0
#define TIMER0_CTC_MODE			1
#endif
