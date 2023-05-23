/************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 10 April , 2023
* SWC	  : TIMER
* Layer   : MCAL
* Version : 2.0
*************************************************************************/

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/********* Macros for Timers *********/
#define TIMER_TIMSK_REG					*(volatile u8*)(0x59)
#define TIMER_TIFR_REG					*(volatile u8*)(0x58)
#define TIMER_SFIOR_REG					*(volatile u8*)(0x50)

/*	Macros for TIMER0 registers */
#define TIMER_TCCR0_REG					*(volatile u8*)(0x53)
#define TIMER_TCNT0_REG					*(volatile u8*)(0x52)
#define TIMER_OCR0_REG					*(volatile u8*)(0x5C)

/* Macros for timer1 registers */
#define TIMER_TCCR1A_REG				*(volatile u8*)(0x4F)
#define TIMER_TCCR1B_REG       			*(volatile u8*)(0x4E)
#define TIMER_TCNT1H_REG       			*(volatile u8*)(0x4D)
#define TIMER_TCNT1L_REG       			*(volatile u16*)(0x4C)
#define TIMER_OCR1AH_REG			    *(volatile u8*)(0x4B)
#define TIMER_OCR1AL_REG       			*(volatile u16*)(0x4A)
#define TIMER_OCR1BH_REG			  	*(volatile u8*)(0x49)
#define TIMER_OCR1BL_REG       			*(volatile u16*)(0x48)
#define TIMER_ICR1H_REG  	  			*(volatile u8*)(0x47)
#define TIMER_ICR1L_REG        			*(volatile u16*)(0x46)

/* Macros for Timer2 registers */
#define TIMER_TCCR2_REG					*(volatile u8*)(0x45)
#define TIMER_TCNT2_REG					*(volatile u8*)(0x44)
#define TIMER_OCR2_REG					*(volatile u8*)(0x43)
#define TIMER_ASSR_REG					*(volatile u8*)(0x42)


#define TIMER_TIMSK_TOIE0				0
#define TIMER_TIMSK_OCIE0				1
#define TIMER_TIMSK_TOIE1				2
#define TIMER_TIMSK_OCIE1B				3
#define TIMER_TIMSK_OCIE1A				4
#define TIMER_TIMSK_TICIE1				5
#define TIMER_TIMSK_TOIE2				6
#define TIMER_TIMSK_OCIE2				7

#define TIMER_TIFR_TOV0					0
#define TIMER_TIFR_OCF0					1
#define TIMER_TIFR_TOV1					2
#define TIMER_TIFR_OCF1B				3
#define TIMER_TIFR_OCF1A				4
#define TIMER_TIFR_ICF1					5
#define TIMER_TIFR_TOV2					6
#define TIMER_TIFR_OCF2 				7

/* Macros for Pins of TCCR0 Register */
#define TIMER_TCCR0_CS00				0
#define TIMER_TCCR0_CS01				1
#define TIMER_TCCR0_CS02				2
#define TIMER_TCCR0_WGM01				3
#define TIMER_TCCR0_COM00				4
#define TIMER_TCCR0_COM01				5
#define TIMER_TCCR0_WGM00				6
#define TIMER_TCCR0_FOC0				7

/******* Macros for TIMER1_TCCR1A_REG ************/
#define TIMER_TCCR1A_WGM10				0
#define TIMER_TCCR1A_WGM11				1
#define TIMER_TCCR1A_FOC1B				2
#define TIMER_TCCR1A_FOC1A				3
#define TIMER_TCCR1A_COM1B0				4
#define TIMER_TCCR1A_COM1B1				5
#define TIMER_TCCR1A_COM1A0				6
#define TIMER_TCCR1A_COM1A1				7

/******* Macros for TIMER1_TCCR1B_REG ************/
#define TIMER_TCCR1B_CS10				0
#define TIMER_TCCR1B_CS11				1
#define TIMER_TCCR1B_CS12				2
#define TIMER_TCCR1B_WGM12				3
#define TIMER_TCCR1B_WGM13				4
#define TIMER_TCCR1B_ICES1				6
#define TIMER_TCCR1B_ICNC1				7

/**********Macros for TIMER_TCCR2_REG *********/
#define TIMER_TCCR2_CS20				0
#define TIMER_TCCR2_CS21				1
#define TIMER_TCCR2_CS22				2
#define TIMER_TCCR2_WGM21				3
#define TIMER_TCCR2_COM20				4
#define TIMER_TCCR2_COM21				5
#define TIMER_TCCR2_WGM20				6
#define TIMER_TCCR2_FOC2				7

/* Macros for TIMERs Wave form generation Mode */
#define TIMER_NORMAL_MODE								0
#define TIMER_PWM_PHASE_CORRECT_TOP_8_MODE				1
#define TIMER_PWM_PHASE_CORRECT_TOP_9_MODE				2
#define TIMER_PWM_PHASE_CORRECT_TOP_10_MODE				3
#define TIMER_CTC_TOP_OCR_MODE							4
#define TIMER_FAST_PWM_TOP_8_MODE						5
#define TIMER_FAST_PWM_TOP_9_MODE						6
#define TIMER_FAST_PWM_TOP_10_MODE						7
#define TIMER_PWM_PHASE_FREQ_CORRECT_TOP_ICR_MODE		8
#define TIMER_PWM_PHASE_FREQ_CORRECT_TOP_OCR_MODE		9
#define TIMER_PWM_PHASE_CORRECT_TOP_ICR_MODE			10
#define TIMER_PWM_PHASE_CORRECT_TOP_OCR_MODE			11
#define TIMER_CTC_TOP_ICR_MODE							12
#define TIMER_FAST_PWM_TOP_ICR_MODE						13
#define TIMER_FAST_PWM_TOP_OCR_MODE						14

/* Macros for TIMERs OutPut mode */
#define TIMER_OC_DISCONNECTED			0
#define TIMER_NON_INVERTED				1
#define TIMER_INVERTED					2

/* Macros for TIMERs 0&2 Prescaler */
#define TIMER_STOPPED					0
#define TIMER_NO_PRESCALER				1
#define TIMER_PRESCALER_8				2
#define TIMER_PRESCALER_32				3
#define TIMER_PRESCALER_64				4
#define TIMER_PRESCALER_128				5
#define TIMER_PRESCALER_256				6
#define TIMER_PRESCALER_1024			7


#endif
