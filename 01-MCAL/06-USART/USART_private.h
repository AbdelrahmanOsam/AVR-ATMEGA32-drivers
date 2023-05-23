/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 17 April , 2023
* SWC			: USART
* Layer			: MCAL
* Version		: V1.0
*********************************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define USART_UDR_REG		*((volatile u8*)0x2C)	// USART Data Register
#define USART_UCSRA_REG		*((volatile u8*)0x2B)	//USART control and status register A
#define USART_UCSRB_REG		*((volatile u8*)0x2A)	//USART control and status register B
#define USART_UCSRC_REG		*((volatile u8*)0x40)	//USART control and status register C
#define USART_UBRRL_REG		*((volatile u8*)0x29)	// USART baudrate register LOW
#define USART_UBRRH_REG		*((volatile u8*)0x40)	// USART baud rate register high

/**********USART UCSRA REG bits*********/
#define USART_UCSRA_MPCM	0
#define USART_UCSRA_U2X		1
#define USART_UCSRA_PE		2
#define USART_UCSRA_DOR		3
#define USART_UCSRA_FE		4
#define USART_UCSRA_UDRE	5
#define USART_UCSRA_TXC		6
#define USART_UCSRA_RXC		7

/**********USART UCSRB REG bits*********/
#define USART_UCSRB_TXB8	0		//Transmitted data 9th bit
#define USART_UCSRB_RXB8	1		//Received data 9th bit
#define USART_UCSRB_UCSZ2	2		//USART charatcer size select bit 2
#define USART_UCSRB_TXEN	3		//Transmiter enable
#define USART_UCSRB_RXEN	4		//Receiver enable
#define USART_UCSRB_UDRIE	5		//UDR register empty interrupt enable
#define USART_UCSRB_TXCIE	6		//Transmission complete interrupt enable
#define USART_UCSRB_RXCIE	7		//Reception complete interrupt enable

/**********USART UCSRC REG bits*********/
#define USART_UCSRC_UCPOL	0		//USART clock polarity
#define USART_UCSRC_UCSZ0	1	
#define USART_UCSRC_UCSZ1	2
#define USART_UCSRC_USBS	3
#define USART_UCSRC_UPM0	4
#define USART_UCSRC_UPM1	5
#define USART_UCSRC_UMSEL	6
#define USART_UCSRC_URSEL	7

/**********************/
#define USART_UBRRH_URSEL	7	//USART register select

/*** Macros for USART_MODE_SELECTION ***/
#define ASYNCHRONOUS_MODE			0
#define SYNCHRONOUS_MODE			1

/*** Macros for CHARACTER_SIZE_SELECTION ***/
#define CHARACTER_SIZE_5_BIT_MODE	0
#define CHARACTER_SIZE_6_BIT_MODE	1
#define CHARACTER_SIZE_7_BIT_MODE	2
#define CHARACTER_SIZE_8_BIT_MODE	3
#define CHARACTER_SIZE_9_BIT_MODE	4

/*** Macros for PARITY_MODE_SELECTION ***/
#define DISABLED_PARITY_MODE		0
#define EVEN_PARITY_MODE			1
#define ODD_PARITY_MODE				2

/*** Macros for STOP_BIT_SELECTION ***/
#define BIT_1_MODE					0
#define BIT_2_MODE					1

/**** Macros for Transmission speed mode ****/
#define NORMAL_SPEED_MODE			0
#define FAST_SPEED_MODE				1

/*** Macros for Baud rate speed ***/
#define BAUD_RATE_2400BPS			0
#define BAUD_RATE_4800BPS 			1
#define BAUD_RATE_9600BPS			2
#define BAUD_RATE_14.4KBPS			3
#define BAUD_RATE_19.2KBPS			4
#define BAUD_RATE_28.8KBPS			5
#define BAUD_RATE_38.4KBPS			6
#define BAUD_RATE_57.6KBPS			7
#define BAUD_RATE_76.8KBPS			8
#define BAUD_RATE_115.2KBPS			9
#define BAUD_RATE_230.4KBPS			10
#define BAUD_RATE_250KBPS			11
#define BAUD_RATE_0.5MBPS			12
#define BAUD_RATE_1MBPS				13

#endif