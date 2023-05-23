/************************************************************************
* Author : Abdelrahman Osam Khaled
* Date	: 9 April , 2023
* SWC	 : TIMER
* Layer  : MCAL
* Version : 1.0
*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*Global_pvoidOVFNotificationFunction)(void) = NULL;
static void (*Global_pvoidCTCNotificationFunction)(void) = NULL;


void TIMER0_voidInit(void)
{
	/* Set Normal mode */
	#if TIMER0_MODE == TIMER0_NORMAL_MODE
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER0_CTC_MODE
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#endif
	
	/* Set Prescaler */
	#if TIMER0_PRESCALER == TIMER0_STOPPED
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_8
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER_PRESCALER_64
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER_PRESCALER_256
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER_PRESCALER_1024
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#endif
}

void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue)
{
	SET_REG(TIMER_TCNT0_REG,Copy_u8PreloadValue);
}

void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8CTCValue)
{
	SET_REG(TIMER_OCR0_REG,Copy_u8CTCValue);
}

void TIMER0_voidEnableInterrupt(u8 Copy_u8TIMERMode)
{
	if (Copy_u8TIMERMode == TIMER0_NORMAL_MODE)
	{
		SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE0);
	}
	else if (Copy_u8TIMERMode == TIMER0_CTC_MODE)
	{
		SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE0);
	}
}

void TIMER0_voidDisableInterrupt(u8 Copy_u8TIMERMode)
{
	if (Copy_u8TIMERMode == TIMER0_NORMAL_MODE)
	{
		CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE0);
	}
	else if (Copy_u8TIMERMode == TIMER0_CTC_MODE)
	{
		CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE0);
	}
}

void TIMER0_voidSetOVFCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidOVFNotificationFunction = pvNotificationFunction;
}

void TIMER0_voidSetCTCCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidCTCNotificationFunction = pvNotificationFunction;
}

void TIMER0_voidSetBusyWaitMS(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OVFNumbers;
	u32 Local_u32OVFCounter = 0;
	/* Set Prescaler 8 */
	SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
	CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
	CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
		
	Local_u32OVFNumbers = ((u32)1000*Copy_u32BusywaitedTime)/256;
	while (Local_u32OVFCounter < Local_u32OVFNumbers)
	{		
		/* e7na bncheck 3la el flag lw bzero yfdal awl ma yb2a b one 
			hay3dy el while */
		while (GET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV0)==0);
		/* Kda safrna el flag tany */
		SET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV0);
		Local_u32OVFCounter++;
	}
}


void __vector_10(void)	__attribute__((signal));
void __vector_10(void)
{
	if(Global_pvoidCTCNotificationFunction != NULL)
	{
		Global_pvoidCTCNotificationFunction();
	}
	else
	{
		//Nothing
	}
}

void __vector_11(void)	__attribute__((signal));
void __vector_11(void)
{
	if(Global_pvoidOVFNotificationFunction != NULL)
	{
		Global_pvoidOVFNotificationFunction();
	}
	else
	{
		//Nothing
	}
}
