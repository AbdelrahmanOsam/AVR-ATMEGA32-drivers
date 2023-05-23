/************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 9 April , 2023
* SWC	  : TIMER
* Layer   : MCAL
* Version : 1.0
*************************************************************************/

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/********* Macros for Timers *********/
#define TIMER_TIMSK_REG			*(volatile u8*)(0x59)
#define TIMER_TIFR_REG			*(volatile u8*)(0x58)
#define TIMER_SFIOR_REG			*(volatile u8*)(0x50)


/*	Macros for TIMER0 registers */
#define TIMER_TCCR0_REG			*(volatile u8*)(0x53)
#define TIMER_TCNT0_REG			*(volatile u8*)(0x52)
#define TIMER_OCR0_REG			*(volatile u8*)(0x5C)


/* Macros for Pins of TCCR0 Register */
#define TIMER_TCCR0_CS00				0
#define TIMER_TCCR0_CS01				1
#define TIMER_TCCR0_CS02				2
#define TIMER_TCCR0_WGM01				3
#define TIMER_TCCR0_COM00				4
#define TIMER_TCCR0_COM01				5
#define TIMER_TCCR0_WGM00				6
#define TIMER_TCCR0_FOC0				7

/* Macros for Pins of TIMSK register*/
#define TIMER_TIMSK_TOIE0				0
#define TIMER_TIMSK_OCIE0				1

/* Macros for Pins of TIFR register */
#define TIMER_TIFR_TOV0					0
#define TIMER_TIFR_OCF0					1

/* Macros for TIMER0 Mode */
#define TIMER0_NORMAL_MODE				0
#define TIMER0_CTC_MODE					1
#define TIMER0_FAST_PWM_MODE			2
#define TIMER0_PWM_PHASE_CORRECT_MODE	3

/* Macros for TIMER0 OutPut mode */
#define TIMER0_OC0_DISCONNECTED			0
#define TIMER0_NON_INVERTED				1
#define TIMER0_INVERTED					2

/* Macros for TIMER0 Prescaler */
#define TIMER0_STOPPED					0
#define TIMER0_NO_PRESCALER				1
#define TIMER0_PRESCALER_8				2
#define TIMER0_PRESCALER_64				3
#define TIMER0_PRESCALER_256			4
#define TIMER0_PRESCALER_1024			5

#endif
