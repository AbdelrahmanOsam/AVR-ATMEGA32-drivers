/************************************************************************
* Author : Abdelrahman Osam Khaled
* Date	: 9 April , 2023
* SWC	 : TIMER
* Layer  : MCAL
* Version : 1.0
*************************************************************************/

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define TIMER_TCCR0_REG			*(volatile u8*)(0x53)
#define TIMER_TCNT0_REG			*(volatile u8*)(0x52)
#define TIMER_OCR0_REG			*(volatile u8*)(0x5C)
#define TIMER_TIMSK_REG			*(volatile u8*)(0x59)
#define TIMER_TIFR_REG			*(volatile u8*)(0x58)

#define TIMER_TCCR0_CS00		0
#define TIMER_TCCR0_CS01		1
#define TIMER_TCCR0_CS02		2
#define TIMER_TCCR0_WGM01		3
#define TIMER_TCCR0_COM00		4
#define TIMER_TCCR0_COM01		5
#define TIMER_TCCR0_WGM00		6
#define TIMER_TCCR0_FOC0		7

#define TIMER_TIMSK_TOIE0		0
#define TIMER_TIMSK_OCIE0		1

#define TIMER_TIFR_TOV0		0
#define TIMER_TIFR_OCF0		1

#endif
