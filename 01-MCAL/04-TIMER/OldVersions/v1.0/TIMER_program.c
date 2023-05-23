/************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 9 April , 2023
* SWC	  : TIMER
* Layer   : MCAL
* Version : 1.0
*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*Global_pvoidTIMER0_OVFNotificationFunction)(void) = NULL;
static void (*Global_pvoidTIMER0_CTCNotificationFunction)(void) = NULL;

void TIMER0_voidInit(void)
{
	/* Set Waveform generation mode */
	#if TIMER0_MODE == TIMER0_NORMAL_MODE
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER0_PWM_PHASE_CORRECT_MODE
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER0_CTC_MODE
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);

	#endif

	/* Set output mode*/
	#if TIMER0_OUTPUT_MODE == TIMER0_OC0_DISCONNECTED
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM01);
	#elif TIMER0_OUTPUT_MODE == TIMER0_NON_INVERTED
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM01);
	#elif TIMER0_OUTPUT_MODE == TIMER0_INVERTED
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM01);	

	/* Set Prescaler */
	#if TIMER0_PRESCALER == TIMER0_STOPPED
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER  == TIMER0_NO_PRESCALER
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_8
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_64
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_256
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER0_PRESCALER_1024
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

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OVFNumbers;
	u32 Local_u32OVFCounter = 0;
	/* Set Prescaler 8 */
	CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
	SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
	CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
		
	Local_u32OVFNumbers = (Copy_u32BusywaitedTime*1000UL)/256UL;
	while (Local_u32OVFCounter <= Local_u32OVFNumbers)
	{		
		/* e7na bncheck 3la el flag lw bzero yfdal awl ma yb2a b one hay3dy el while */
		while (GET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV0)==0);
		/* Kda safrna el flag tany */
		SET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV0);
		Local_u32OVFCounter++;
	}
}

void TIMER0_voidSetBusyWait_CTCMode(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OCFNumbers;
	u32 Local_u32OCFCounter = 0;

	/*Set The Prescaler to be 8*/
	CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
	SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
	CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	/* Clear the timer register */
	TIMER_TCNT0_REG = 0x00;
	TIMER0_voidSetCTCCompareMatchValue(250);
	/*You should cast the constants, i.e., 1000 and 250 to unsigned long (u32) and compute the multiplication operation first before the division */
	//u32 Number_of_OCFlags = ((u32)(Copy_u32BusywaitedTime*1000)) / 250;
	Local_u32OCFNumbers = ((u32)Copy_u32BusywaitedTime * 1000UL) / 250UL;

	while(Local_u32OCFCounter <= Local_u32OCFNumbers)
	{
		while(GET_BIT(TIMER_TIFR_REG ,TIMER_TIFR_OCF0) == 0);
		SET_BIT(TIMER_TIFR_REG ,TIMER_TIFR_OCF0);
		Local_u32OCFCounter++;
	}
}

void TIMER0_voidSetOVFCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER0_OVFNotificationFunction = pvNotificationFunction;
}

void TIMER0_voidSetCTCCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER0_CTCNotificationFunction = pvNotificationFunction;
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