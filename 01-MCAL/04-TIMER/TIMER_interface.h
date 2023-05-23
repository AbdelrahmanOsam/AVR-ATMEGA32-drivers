/************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 10 April , 2023
* SWC	  : TIMER
* Layer   : MCAL
* Version : 2.0
*************************************************************************/

#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void TIMER0_voidInit(void);
void TIMER1_voidInit(void);
void TIMER2_voidInit(void);

void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue);
void TIMER1_voidSetPreloadValue(u16 Copy_u16PreloadValue);
void TIMER2_voidSetPreloadValue(u8 Copy_u8PreloadValue);

void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8CTCValue);
void TIMER1A_voidSetCTCCompareMatchValue(u16 Copy_u16CTCValue);
void TIMER1B_voidSetCTCCompareMatchValue(u16 Copy_u16CTCValue);
void TIMER2_voidSetCTCCompareMatchValue(u8 Copy_u8CTCValue);

void TIMER0_voidEnableInterrupt(u8 Copy_u8TIMERMode);
void TIMER1_voidEnableInterrupt(u8 Copy_u8TIMERMode,u8 Copy_u8OC_REG);
void TIMER2_voidEnableInterrupt(u8 Copy_u8TIMERMode);

void TIMER0_voidDisableInterrupt(u8 Copy_u8TIMERMode);
void TIMER1_voidDisableInterrupt(u8 Copy_u8TIMERMode,u8 Copy_u8OC_REG);
void TIMER2_voidDisableInterrupt(u8 Copy_u8TIMERMode);

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32BusywaitedTime);
void TIMER1_voidSetBusyWait_OVFMode(u32 Copy_u32BusywaitedTime);
void TIMER2_voidSetBusyWait_OVFMode(u32 Copy_u32BusywaitedTime);

void TIMER0_voidSetBusyWait_CTCMode(u32 Copy_u32BusywaitedTime);
void TIMER1A_voidSetBusyWait_CTCMode(u32 Copy_u32BusywaitedTime);
void TIMER1B_voidSetBusyWait_CTCMode(u32 Copy_u32BusywaitedTime);
void TIMER2_voidSetBusyWait_CTCMode(u32 Copy_u32BusywaitedTime);

void TIMER0_voidSetOVFCallBack(void (*pvNotificationFunction)(void));
void TIMER1_voidSetOVFCallBack(void (*pvNotificationFunction)(void));
void TIMER2_voidSetOVFCallBack(void (*pvNotificationFunction)(void));

void TIMER0_voidSetCTCCallBack(void (*pvNotificationFunction)(void));
void TIMER1A_voidSetCTCCallBack(void (*pvNotificationFunction)(void));
void TIMER1B_voidSetCTCCallBack(void (*pvNotificationFunction)(void));
void TIMER2_voidSetCTCCallBack(void (*pvNotificationFunction)(void));

/*************** Input Capture unit mode functions **************/

void TIMER1_voidICR1Value(u16 Copy_u16ICRValue);
void ICU_voidSetTriggerSignal(u8 Copy_u8TriggerSignal);
u16 ICU_u16GetICRRegister(void);
void ICU_voidSetCallBack(void(*NotificationFunction)(void));
void ICU_voidInterruptControl(u8 Copy_u8InterruptsState);

#define TIMER1_OC_REGA		0
#define TIMER1_OC_REGB		1	

#define ICU_RISING_EDGE		1
#define ICU_FALLING_EDGE	0

#define ICU_ENABLE			1
#define ICU_DISABLE			0	

#endif
