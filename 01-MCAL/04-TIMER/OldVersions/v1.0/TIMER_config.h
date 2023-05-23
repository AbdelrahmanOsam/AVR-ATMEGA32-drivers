/************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 9 April , 2023
* SWC	  : TIMER
* Layer   : MCAL
* Version : 1.0
*************************************************************************/

#ifndef TIMER_CONFIG_H
#define TIMER_CONFIG_H

#define TIMER0_MODE TIMER0_FAST_PWM_MODE
/* Options :
			TIMER0_NORMAL_MODE
			TIMER0_CTC_MODE
			TIMER0_FAST_PWM_MODE
			TIMER0_PWM_PHASE_CORRECT_MODE
	*/
	
#define TIMER0_OUTPUT_MODE	TIMER0_NON_INVERTED
/* Options :
			TIMER0_OC0_DISCONNECTED
			TIMER0_NOT_INVERTED
			TIMER0_INVERTED
	*/
	
#define TIMER0_PRESCALER  TIMER0_PRESCALER_8
/* Options :
			TIMER0_STOPPED
			TIMER0_NO_PRESCALER
			TIMER0_PRESCALER_8
			TIMER0_PRESCALER_64
			TIMER0_PRESCALER_256
			TIMER0_PRESCALER_1024
	*/
#endif
