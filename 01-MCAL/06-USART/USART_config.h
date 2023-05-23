/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 17 April , 2023
* SWC			: USART
* Layer			: MCAL
* Version		: V1.0
*********************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

#define USART_MODE_SELECTION	ASYNCHRONOUS_MODE
/* Options :
			- ASYNCHRONOUS_MODE
			- SYNCHRONOUS_MODE
	*/
	
#define CHARACTER_SIZE_SELECTION CHARACTER_SIZE_8_BIT_MODE
/* Options :
			- CHARACTER_SIZE_5_BIT_MODE
			- CHARACTER_SIZE_6_BIT_MODE
			- CHARACTER_SIZE_7_BIT_MODE
			- CHARACTER_SIZE_8_BIT_MODE
			- CHARACTER_SIZE_9_BIT_MODE
	*/
#define PARITY_MODE_SELECTION DISABLED_PARITY_MODE
/* Options :
			- DISABLED_PARITY_MODE
			- EVEN_PARITY_MODE
			- ODD_PARITY_MODE
	*/
#define STOP_BIT_SELECTION BIT_1_MODE
/* Options :
			- BIT_1_MODE
			- BIT_2_MODE
	*/
#define TRANSMISSION_SPEED_MODE		NORMAL_SPEED_MODE
/* Options :
			- NORMAL_SPEED_MODE
			- FAST_SPEED_MODE
	*/
#define TRANSMISSION_BAUD_RATE  BAUD_RATE_9600BPS
/* Options :
			- BAUD_RATE_2400BPS
			- BAUD_RATE_4800BPS 
			- BAUD_RATE_9600BPS
			- BAUD_RATE_14.4KBPS
			- BAUD_RATE_19.2KBPS
			- BAUD_RATE_28.8KBPS
			- BAUD_RATE_38.4KBPS
			- BAUD_RATE_57.6KBPS
			- BAUD_RATE_76.8KBPS
            - BAUD_RATE_115.2KBPS
            - BAUD_RATE_230.4KBPS
            - BAUD_RATE_250KBPS
            - BAUD_RATE_0.5MBPS
			- BAUD_RATE_1MBPS
	*/
#endif 