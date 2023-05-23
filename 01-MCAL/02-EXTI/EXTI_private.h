/*************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 29 March , 2023
* SWC	  : EXTI 
* Layer	  : MCAL
* version : 1.0
*************************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/*** Macros for EXTI Register addresses ***/
#define EXTI_MCUCR_REG		*((volatile u8*)0x55)

#define EXTI_MCUCSR_REG		*((volatile u8*)0x54)

#define EXTI_GICR_REG		*((volatile u8*)0x5B)

#define EXTI_GIFR_REG		*((volatile u8*)0x5A)

/*** Macros for bits EXTI_MCUCR_REG  ***/
#define EXTI_MCUCR_ISC00		0
#define EXTI_MCUCR_ISC01		1
#define EXTI_MCUCR_ISC10		2
#define EXTI_MCUCR_ISC11		3
#define EXTI_MCUCSR_ISC2		6

/*** Macros for EXTI_GICR_REG ***/
#define EXTI_GICR_INT0			6
#define EXTI_GICR_INT1			7
#define EXTI_GICR_INT2			5

#define INT_INPUT_PULLUP		0
#define INT_EXTERNAL_PULLUP		1
#define INT_EXTERNAL_PULLDOWN	2

/* Pins Connection On Hardware */
/* INT0 */
#define EXTI0_PORT      DIO_PORTD
#define EXTI0_PIN       DIO_PIN2
/* INT1 */
#define EXTI1_PORT      DIO_PORTD
#define EXTI1_PIN       DIO_PIN3
/* INT2 */
#define EXTI2_PORT      DIO_PORTB
#define EXTI2_PIN       DIO_PIN2



#endif