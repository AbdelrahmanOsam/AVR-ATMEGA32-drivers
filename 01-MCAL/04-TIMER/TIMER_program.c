/************************************************************************
* Author          : Abdelrahman Osam Khaled
* Created date	  : 10 April , 2023
* SWC	          : TIMER
* Layer  		  : MCAL
* Version 		  : V1.0	-> Create Timer0
*				  : V2.0 -> Add Timer2
*				  
*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

/****** Global Pointers for TIMER 1&2&3 ************/
static void (*Global_pvoidTIMER0_OVFNotificationFunction)(void) = NULL;
static void (*Global_pvoidTIMER0_CTCNotificationFunction)(void) = NULL;

static void (*Global_pvoidTIMER1_OVFNotificationFunction)(void) = NULL;
static void (*Global_pvoidTIMER1A_CTCNotificationFunction)(void) = NULL;
static void (*Global_pvoidTIMER1B_CTCNotificationFunction)(void) = NULL;

static void (*Global_pvoidTIMER2_OVFNotificationFunction)(void) = NULL;
static void (*Global_pvoidTIMER2_CTCNotificationFunction)(void) = NULL;

void TIMER0_voidInit(void)
{
	/* Set Waveform generation mode */
	#if TIMER0_MODE == TIMER_NORMAL_MODE
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER_PWM_PHASE_CORRECT_TOP_8_MODE
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER_CTC_TOP_OCR_MODE
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#elif TIMER0_MODE == TIMER_FAST_PWM_TOP_8_MODE
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_WGM01);
	#else	
		#error("Error : TIMER0_MODE Configuration error")

	#endif

	/* Set output mode*/
	#if TIMER0_OUTPUT_MODE == TIMER_OC_DISCONNECTED
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM01);
	#elif TIMER0_OUTPUT_MODE == TIMER_NON_INVERTED
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM01);
	#elif TIMER0_OUTPUT_MODE == TIMER_INVERTED
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_COM01);	
	#else	
		#error( "Error : TIMER0_OUTPUT_MODE Configuration error")
	#endif

	/* Set Prescaler */
	#if TIMER0_PRESCALER == TIMER_STOPPED
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER  == TIMER_NO_PRESCALER
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
	#elif TIMER0_PRESCALER == TIMER_PRESCALER_8
		CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
		SET_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
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
	#else	
		//#error("Error : TIMER0_PRESCALER Configuration error")
	#endif
}

void TIMER1_voidInit(void)
{
		/* Set Waveform generation mode */
	#if TIMER1_MODE == TIMER_NORMAL_MODE
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_PWM_PHASE_CORRECT_TOP_8_MODE
		SET_BIT(TIMER_TCCR1A_REG,TIMER1_TCCR1A_WGM10);
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_PWM_PHASE_CORRECT_TOP_9_MODE
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_PWM_PHASE_CORRECT_TOP_10_MODE
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_CTC_TOP_OCR_MODE
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_FAST_PWM_TOP_8_MODE
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_FAST_PWM_TOP_9_MODE
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_FAST_PWM_TOP_10_MODE
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_PWM_PHASE_FREQ_CORRECT_TOP_ICR_MODE
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_PWM_PHASE_FREQ_CORRECT_TOP_OCR_MODE
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_PWM_PHASE_CORRECT_TOP_ICR_MODE
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_PWM_PHASE_CORRECT_TOP_OCR_MODE
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_CTC_TOP_ICR_MODE
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_FAST_PWM_TOP_ICR_MODE
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#elif TIMER1_MODE == TIMER_FAST_PWM_TOP_OCR_MODE
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM10);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_WGM11);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM12);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_WGM13);
	#else	
		#error("Error : TIMER1_MODE Configuration error")
	#endif

			/* Set output mode For A & B*/
	#if TIMER1A_OUTPUT_MODE == TIMER_OC_DISCONNECTED
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_COM1A0);
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_COM1A1);
	#elif TIMER1A_OUTPUT_MODE == TIMER_NON_INVERTED
		CLEAR_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_COM1A0);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_COM1A1);
	#elif TIMER1A_OUTPUT_MODE == TIMER_INVERTED
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_COM1A0);
		SET_BIT(TIMER_TCCR1A_REG,TIMER_TCCR1A_COM1A0);
	#else 
		#error("Error : TIMER1A_OUTPUT_MODE Configuration error")
	#endif
	
	#if TIMER1B_OUTPUT_MODE == TIMER_OC_DISCONNECTED
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1A_COM1B0);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1A_COM1B1);
	#elif TIMER1B_OUTPUT_MODE == TIMER_NON_INVERTED
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1A_COM1B0);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1A_COM1B1);
	#elif TIMER1B_OUTPUT_MODE == TIMER_INVERTED
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1A_COM1B0);
		SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1A_COM1B1);
	#else 
		#error ("Error : TIMER1B_OUTPUT_MODE Configuration error")
	#endif

	/* Set Prescaler */
	#if TIMER1_PRESCALER == TIMER_STOPPED
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
	#elif TIMER1_PRESCALER  == TIMER_NO_PRESCALER
		SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
	#elif TIMER1_PRESCALER == TIMER_PRESCALER_8
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
		SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
	#elif TIMER1_PRESCALER == TIMER_PRESCALER_64
		SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
		SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
	#elif TIMER1_PRESCALER == TIMER_PRESCALER_256
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
		SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
	#elif TIMER1_PRESCALER == TIMER_PRESCALER_1024
		SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
		CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
		SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
	#else	
		#error("Error : TIMER0_PRESCALER Configuration error")
	#endif
}

void TIMER2_voidInit(void)
{
		/* Set Waveform generation mode */
	#if TIMER2_MODE == TIMER_NORMAL_MODE
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_WGM20);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_WGM21);
	#elif TIMER2_MODE == TIMER_PWM_PHASE_CORRECT_TOP_8_MODE
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_WGM20);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_WGM21);
	#elif TIMER2_MODE == TIMER_CTC_TOP_OCR_MODE
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_WGM20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_WGM21);
	#elif TIMER2_MODE == TIMER_FAST_PWM_TOP_8_MODE
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_WGM20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_WGM21);
	#else	
		#error("Error : TIMER2_MODE Configuration error")
	#endif

	/* Set output mode*/
	#if TIMER2_OUTPUT_MODE == TIMER0_OC0_DISCONNECTED
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_COM20);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_COM21);
	#elif TIMER2_OUTPUT_MODE == TIMER0_NON_INVERTED
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_COM20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_COM21);
	#elif TIMER2_OUTPUT_MODE == TIMER0_INVERTED
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_COM20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_COM21);	
	#else	
		//#error("Error : TIMER2_OUTPUT_MODE Configuration error")
	#endif

	/* Set Prescaler */
	#if TIMER2_PRESCALER == TIMER_STOPPED
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	#elif TIMER2_PRESCALER  == TIMER_NO_PRESCALER
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	#elif TIMER2_PRESCALER == TIMER_PRESCALER_8
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	#elif TIMER2_PRESCALER == TIMER_PRESCALER_32
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	#elif TIMER2_PRESCALER == TIMER_PRESCALER_64
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	#elif TIMER2_PRESCALER == TIMER_PRESCALER_128
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	#elif TIMER2_PRESCALER == TIMER_PRESCALER_256
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	#elif TIMER2_PRESCALER == TIMER_PRESCALER_1024
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	#else	
		#error("Error : TIMER2_PRESCALER Configuration error")
	#endif
}

/***********Macros for Set preload function for TIMER 1&2&3 ***************/

void TIMER0_voidSetPreloadValue(u8 Copy_u8PreloadValue)
{
	TIMER_TCNT0_REG = Copy_u8PreloadValue;
}

void TIMER1_voidSetPreloadValue(u16 Copy_u16PreloadValue)
{
	TIMER_TCNT1L_REG = Copy_u16PreloadValue;
}

void TIMER2_voidSetPreloadValue(u8 Copy_u8PreloadValue)
{
	TIMER_TCNT2_REG = Copy_u8PreloadValue;
}

/********Macros for Set Output compare function for TIMER 1&2&3 ***********/

void TIMER0_voidSetCTCCompareMatchValue(u8 Copy_u8CTCValue)
{
	TIMER_OCR0_REG = Copy_u8CTCValue;
}

void TIMER1A_voidSetCTCCompareMatchValue(u16 Copy_u16CTCValue)
{
	TIMER_OCR1AL_REG = Copy_u16CTCValue;
}

void TIMER1B_voidSetCTCCompareMatchValue(u16 Copy_u16CTCValue)
{
	TIMER_OCR1BL_REG = Copy_u16CTCValue;
}

void TIMER2_voidSetCTCCompareMatchValue(u8 Copy_u8CTCValue)
{
	TIMER_OCR2_REG = Copy_u8CTCValue;
}

/***********Macros for enable interrupt functions  for TIMER 1,2&3 ************/
void TIMER0_voidOVEnableInterrupt(void)
{
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE0);
}

void TIMER0_voidOCEnableInterrupt(void)
{
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE0);
}

void TIMER1A_voidOCEnableInterrupt(void)
{
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE1A);
}
void TIMER1B_voidOCEnableInterrupt(void)
{
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE1B);
}
void TIMER1_voidOVEnableInterrupt(void)
{
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE1);
}

void TIMER2_voidOVEnableInterrupt(void)
{
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE2);
}

void TIMER2_voidOCEnableInterrupt(void)
{
	SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE2);

}
/*********Macros for disable interrupt functions  for TIMER 1,2&3 **********/
void TIMER0_voidOVDisableInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE0);
}

void TIMER0_voidOCDisableInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE0);
}

void TIMER1A_voidOCDisableInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE1A);
}
void TIMER1B_voidOCDisableInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE1B);
}
void TIMER1_voidOVDisableInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE1);
}

void TIMER2_voidOVDisableInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TOIE2);
}

void TIMER2_voidOCDisableInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_OCIE2);

}
/********** Macros for busy wait OV functions for TIMER 1,2&3 **************/

void TIMER0_voidSetBusyWait_OVFMode(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OVFNumbers;
	u32 Local_u32OVFCounter = 0;
	TIMER0_voidSetPreloadValue(6);
	/* Set Prescaler 8 */
	CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS00);
	SET_BIT	 (TIMER_TCCR0_REG,TIMER_TCCR0_CS01);
	CLEAR_BIT(TIMER_TCCR0_REG,TIMER_TCCR0_CS02);
		
	Local_u32OVFNumbers = ((u32)Copy_u32BusywaitedTime*1000UL)/250UL;
	while (Local_u32OVFCounter <= Local_u32OVFNumbers)
	{		
		/* e7na bncheck 3la el flag lw bzero yfdal awl ma yb2a b one hay3dy el while */
		while (GET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV0)==0);
		/* Kda safrna el flag tany */
		SET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV0);
		Local_u32OVFCounter++;
		TIMER0_voidSetPreloadValue(6);
	}
}
void TIMER1_voidSetBusyWait_OVFMode(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OVFNumbers;
	u32 Local_u32OVFCounter = 0;
				/* Set Prescaler 8 */
	CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
	SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
	CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
		
	Local_u32OVFNumbers = (Copy_u32BusywaitedTime*1000UL)/65536UL;
	while (Local_u32OVFCounter <= Local_u32OVFNumbers)
	{		
		/* e7na bncheck 3la el flag lw bzero yfdal awl ma yb2a b one hay3dy el while */
		while (GET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV1)==0);
		/* Kda safrna el flag tany */
		SET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV1);
		Local_u32OVFCounter++;
	}
}

void TIMER2_voidSetBusyWait_OVFMode(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OVFNumbers;
	u32 Local_u32OVFCounter = 0;
	TIMER0_voidSetPreloadValue(6);

	/* Set Prescaler 8 */
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
		SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
		CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
		
	Local_u32OVFNumbers = (Copy_u32BusywaitedTime*1000UL)/250UL;
	while (Local_u32OVFCounter <= Local_u32OVFNumbers)
	{		
		/* e7na bncheck 3la el flag lw bzero yfdal awl ma yb2a b one hay3dy el while */
		while (GET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV2)==0);
		/* Kda safrna el flag tany */
		SET_BIT(TIMER_TIFR_REG,TIMER_TIFR_TOV2);
		Local_u32OVFCounter++;
	}
}

/********** Macros for busy wait OC functions for TIMER 1,2&3 **************/


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

void TIMER1A_voidSetBusyWait_CTCMode(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OCFNumbers;
	u32 Local_u32OCFCounter = 0;

	/*Set The Prescaler to be 8*/
	CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
	SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
	CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
	/* Clear the timer register */
	TIMER_TCNT1L_REG = 0x00;
	TIMER1A_voidSetCTCCompareMatchValue(250);
	/*You should cast the constants, i.e., 1000 and 250 to unsigned long (u32) and compute the multiplication operation first before the division */
	//u32 Number_of_OCFlags = ((u32)(Copy_u32BusywaitedTime*1000)) / 250;
	Local_u32OCFNumbers = ((u32)Copy_u32BusywaitedTime * 1000UL) / 250UL;

	while(Local_u32OCFCounter <= Local_u32OCFNumbers)
	{
		while(GET_BIT(TIMER_TIFR_REG ,TIMER_TIFR_OCF1A) == 0);
		SET_BIT(TIMER_TIFR_REG ,TIMER_TIFR_OCF1A);
		Local_u32OCFCounter++;
	}
}

void TIMER1B_voidSetBusyWait_CTCMode(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OCFNumbers;
	u32 Local_u32OCFCounter = 0;

	/*Set The Prescaler to be 8*/
	CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS10);
	SET_BIT  (TIMER_TCCR1B_REG,TIMER_TCCR1B_CS11);
	CLEAR_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_CS12);
	/* Clear the timer register */
	TIMER_TCNT1L_REG = 0x00;
	TIMER1B_voidSetCTCCompareMatchValue(250);
	/*You should cast the constants, i.e., 1000 and 250 to unsigned long (u32) and compute the multiplication operation first before the division */
	//u32 Number_of_OCFlags = ((u32)(Copy_u32BusywaitedTime*1000)) / 250;
	Local_u32OCFNumbers = ((u32)Copy_u32BusywaitedTime * 1000UL) / 250UL;

	while(Local_u32OCFCounter <= Local_u32OCFNumbers)
	{
		while(GET_BIT(TIMER_TIFR_REG ,TIMER_TIFR_OCF1B) == 0);
		SET_BIT(TIMER_TIFR_REG ,TIMER_TIFR_OCF1B);
		Local_u32OCFCounter++;
	}
}

void TIMER2_voidSetBusyWait_CTCMode(u32 Copy_u32BusywaitedTime)
{
	u32 Local_u32OCFNumbers;
	u32 Local_u32OCFCounter = 0;

	/*Set The Prescaler to be 8*/
	CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS20);
	SET_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS21);
	CLEAR_BIT(TIMER_TCCR2_REG,TIMER_TCCR2_CS22);
	/* Clear the timer register */
	TIMER_TCNT2_REG = 0x00;
	TIMER2_voidSetCTCCompareMatchValue(250);
	/*You should cast the constants, i.e., 1000 and 250 to unsigned long (u32) and compute the multiplication operation first before the division */
	//u32 Number_of_OCFlags = ((u32)(Copy_u32BusywaitedTime*1000)) / 250;
	Local_u32OCFNumbers = ((u32)Copy_u32BusywaitedTime * 1000UL) / 250UL;

	while(Local_u32OCFCounter <= Local_u32OCFNumbers)
	{
		while(GET_BIT(TIMER_TIFR_REG ,TIMER_TIFR_OCF2) == 0);
		SET_BIT(TIMER_TIFR_REG ,TIMER_TIFR_OCF2);
		Local_u32OCFCounter++;
	}
}

/************ Macros for Set OV function callback for TIMER 1&2&3 **************/

void TIMER0_voidSetOVFCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER0_OVFNotificationFunction = pvNotificationFunction;
}

void TIMER1_voidSetOVFCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER1_OVFNotificationFunction = pvNotificationFunction;
}

void TIMER2_voidSetOVFCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER2_OVFNotificationFunction = pvNotificationFunction;
}

/************ Macros for Set OC function callback for TIMER 1&2&3 **************/

void TIMER0_voidSetCTCCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER0_CTCNotificationFunction = pvNotificationFunction;
}

void TIMER1A_voidSetCTCCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER1A_CTCNotificationFunction = pvNotificationFunction;
}

void TIMER1B_voidSetCTCCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER1B_CTCNotificationFunction = pvNotificationFunction;
}

void TIMER2_voidSetCTCCallBack(void (*pvNotificationFunction)(void))
{
	Global_pvoidTIMER2_CTCNotificationFunction = pvNotificationFunction;
}

/****************** Macros for ISR function for TIMER1&2&3 ******************/

/********** for Timer 0 OV & OC ***************/

void __vector_10(void)	__attribute__((signal));
void __vector_10(void)
{
	if(Global_pvoidTIMER0_CTCNotificationFunction != NULL)
	{
		Global_pvoidTIMER0_CTCNotificationFunction();
	}
	else
	{
		//Nothing
	}
}

void __vector_11(void)	__attribute__((signal));
void __vector_11(void)
{
	if(Global_pvoidTIMER0_OVFNotificationFunction != NULL)
	{
		Global_pvoidTIMER0_OVFNotificationFunction();
	}
	else
	{
		//Nothing
	}
}

/********** for Timer 1 OV & OC ***************/

void __vector_7(void)	__attribute__((signal));
void __vector_7(void)
{
	if(Global_pvoidTIMER1A_CTCNotificationFunction != NULL)
	{
		Global_pvoidTIMER1A_CTCNotificationFunction();
	}
	else
	{
		//Nothing
	}
}

void __vector_8(void)	__attribute__((signal));
void __vector_8(void)
{
	if(Global_pvoidTIMER1B_CTCNotificationFunction != NULL)
	{
		Global_pvoidTIMER1B_CTCNotificationFunction();
	}
	else
	{
		//Nothing
	}
}
void __vector_9(void)	__attribute__((signal));
void __vector_9(void)
{
	if(Global_pvoidTIMER1_OVFNotificationFunction != NULL)
	{
		Global_pvoidTIMER1_OVFNotificationFunction();
	}
	else
	{
		//Nothing
	}
}

/********** for Timer 2 OV & OC ***************/

void __vector_4(void)	__attribute__((signal));
void __vector_4(void)
{
	if(Global_pvoidTIMER2_CTCNotificationFunction != NULL)
	{
		Global_pvoidTIMER2_CTCNotificationFunction();
	}
	else
	{
		//Nothing
	}
}

void __vector_5(void)	__attribute__((signal));
void __vector_5(void)
{
	if(Global_pvoidTIMER2_OVFNotificationFunction != NULL)
	{
		Global_pvoidTIMER2_OVFNotificationFunction();
	}
	else
	{
		//Nothing
	}
}
/*************** Input capture unit mode ****************************/
static void (*ICU_NotificationFunction)(void) = NULL;

u16 ICU_u16GetICRRegister(void)
{
	return TIMER_ICR1L_REG;
}


void ICU_voidSetTriggerSignal(u8 Copy_u8TriggerSignal)
{
	switch(Copy_u8TriggerSignal)
	{
		case ICU_RISING_EDGE :
					SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_ICES1);
		break;
		case ICU_FALLING_EDGE :
					SET_BIT(TIMER_TCCR1B_REG,TIMER_TCCR1B_ICES1);
		break;
		default :
		break;
	}
}

void ICU_voidInterruptControl(u8 Copy_u8InterruptsState)
{
	switch(Copy_u8InterruptsState)
	{
		case ICU_ENABLE :
				SET_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TICIE1);
		break;
		case ICU_DISABLE :
				CLEAR_BIT(TIMER_TIMSK_REG,TIMER_TIMSK_TICIE1);
		break;
		default :
		break;
	}
}

void ICU_voidSetCallBack(void(*NotificationFunction)(void))
{
	ICU_NotificationFunction = NotificationFunction;
}

	// ISR for Input capture unit (ICU)
void __vector_6 (void)  __attribute__((signal));
void __vector_6 (void)
{
	if(ICU_NotificationFunction != NULL)
	{
		ICU_NotificationFunction();
	}
	else
	{
		//Nothing
	}
}