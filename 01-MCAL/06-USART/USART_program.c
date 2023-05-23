/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 17 April , 2023
* SWC			: USART
* Layer			: MCAL
* Version		: V1.0
*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void UART_voidInit(void)
{
	/*e7na mn2dr4 n3ml bit access fe USART_UCSRC_REG l2no byte access f3mlna variable
		n access el bits bta3to w b3den sawenah bl register */
	u8 Local_u8UCSRCTemp = 0;
	/*UART Parameters:
		- Mode is Asynchronous mode 
		- Enable TX & RX circuits 
		- Data size = 8 bits
		- Parity Disabled 
		- Stop bit = 1
		- Baudrate = 9600bps
		*/
		
		// Set the USART mode to be Asynchronous mode or Synchronous mode
	#if USART_MODE_SELECTION == ASYNCHRONOUS_MODE
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_UMSEL);
	#elif USART_MODE_SELECTION == SYNCHRONOUS_MODE
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UMSEL);
	#else
		#error "Configuration error : USART mode selection error"
	#endif	
		// Enable TX & RX circuits 
	SET_BIT(USART_UCSRB_REG,USART_UCSRB_TXEN);
	SET_BIT(USART_UCSRB_REG,USART_UCSRB_RXEN);
	
		// Set data size bits to be 8 bits
	#if CHARACTER_SIZE_SELECTION == CHARACTER_SIZE_5_BIT_MODE
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ0);
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ1);
		CLEAR_BIT(USART_UCSRB_REG,USART_UCSRB_UCSZ2);
	#elif CHARACTER_SIZE_SELECTION == CHARACTER_SIZE_6_BIT_MODE
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ0);
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ1);
		CLEAR_BIT(USART_UCSRB_REG,USART_UCSRB_UCSZ2);
	#elif CHARACTER_SIZE_SELECTION == CHARACTER_SIZE_7_BIT_MODE
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ0);
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ1);
		CLEAR_BIT(USART_UCSRB_REG,USART_UCSRB_UCSZ2);
	#elif CHARACTER_SIZE_SELECTION == CHARACTER_SIZE_8_BIT_MODE
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ0);
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ1);
		CLEAR_BIT(USART_UCSRB_REG,USART_UCSRB_UCSZ2);
	#elif CHARACTER_SIZE_SELECTION == CHARACTER_SIZE_9_BIT_MODE
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ0);
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UCSZ1);
		SET_BIT(USART_UCSRB_REG,USART_UCSRB_UCSZ2);
	#else 
		#error "Configuration error : Character size selection error"
	#endif
		
		//Disable parity mode
	#if PARITY_MODE_SELECTION == DISABLED_PARITY_MODE
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_UPM0);
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_UPM1);
	#elif PARITY_MODE_SELECTION == EVEN_PARITY_MODE
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_UPM0);
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UPM1);
	#elif PARITY_MODE_SELECTION == ODD_PARITY_MODE
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UPM0);
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_UPM1);
	#else
		#error "Configuration error : Parity mode selection error"
	#endif
	
		// Stop bit = 1
	#if STOP_BIT_SELECTION == BIT_1_MODE
		CLEAR_BIT(Local_u8UCSRCTemp,USART_UCSRC_USBS);
	#elif STOP_BIT_SELECTION == BIT_2_MODE
		SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_USBS);
	#else
		#error "Configuration error : Stop bit selection error"
	#endif
		
		//Set the USART register select bit to write on USRC
	SET_BIT(Local_u8UCSRCTemp,USART_UCSRC_URSEL);
		// Assign the variable value to the register
	USART_UCSRC_REG = Local_u8UCSRCTempl;
	
	#if TRANSMISSION_SPEED_MODE == NORMAL_SPEED	// Select transmission speed
		CLEAR_BIT(USART_UCSRA_REG,USART_UCSRA_U2X);
		#if TRANSMISSION_BAUD_RATE == BAUD_RATE_2400BPS // select baud rate
			USART_UBRRL_REG = 207;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_4800BPS
			USART_UBRRL_REG = 103;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_9600BPS
			USART_UBRRL_REG = 51;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_14.4KBPS
			USART_UBRRL_REG = 34;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_19.2KBPS
			USART_UBRRL_REG = 25;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_28.8KBPS
			USART_UBRRL_REG = 16;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_38.4KBPS
			USART_UBRRL_REG = 12;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_57.6KBPS
			USART_UBRRL_REG = 8;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_76.8KBPS
			USART_UBRRL_REG = 6;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_115.2KBPS
			USART_UBRRL_REG = 3;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_230.4KBPS
			USART_UBRRL_REG = 1;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_250KBPS
			USART_UBRRL_REG = 1;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_0.5MBPS
			USART_UBRRL_REG = 0;
		#else 
			#error "Configuration error : Transmission baud rate error"
		#endif
		
	#elif TRANSMISSION_SPEED_MODE == FAST_SPEED_MODE
		SET_BIT(USART_UCSRA_REG,USART_UCSRA_U2X); //select FAST Speed Mode
		#if TRANSMISSION_BAUD_RATE == BAUD_RATE_2400BPS // select baud rate
			USART_UBRRL_REG = 416;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_4800BPS
			USART_UBRRL_REG = 207;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_9600BPS
			USART_UBRRL_REG = 103;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_14.4KBPS
			USART_UBRRL_REG = 68;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_19.2KBPS
			USART_UBRRL_REG = 51;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_28.8KBPS
			USART_UBRRL_REG = 34;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_38.4KBPS
			USART_UBRRL_REG = 25;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_57.6KBPS
			USART_UBRRL_REG = 16;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_76.8KBPS
			USART_UBRRL_REG = 12;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_115.2KBPS
			USART_UBRRL_REG = 8;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_230.4KBPS
			USART_UBRRL_REG = 3;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_250KBPS
			USART_UBRRL_REG = 3;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_0.5MBPS
			USART_UBRRL_REG = 1;
		#elif TRANSMISSION_BAUD_RATE == BAUD_RATE_1MBPS
			USART_UBRRL_REG = 0;
		#else 
			#error "Configuration error : Transmission baud rate error"
		#endif
	#else 
		#error "Configuration error : Transmission speed mode error"
	#endif

			//Set the USART register select bit to write on UBRRL
	CLEAR_BIT(USART_UBRRH_REG,USART_UBRRH_URSEL);
	USART_UBRRH_REG = 0;
}
void UART_voidTransmitDataSynchronous(u8 Copy_u8Data)
{
	/* Polling (busy wait) On the UDR empty flag */
	while(GET_BIT(USART_UCSRA_REG,USART_UCSRA_UDRE) == 0);
	/* Copy Tha data to UDR register */
	USART_UDR_REG = Copy_u8Data;
		/* Polling (busy wait) On the TXC flag*/
	while(GET_BIT(USART_UCSRA_REG,USART_UCSRA_TXC) == 0);
	/* Clear the flag */
	SET_BIT(USART_UCSRA_REG,USART_UCSRA_TXC);
}
void UART_u8ReceiveDataSynchronous(u8 *Copy_u8ReceivedData)
{
		/* Polling (busy wait) On the RXC flag*/
	while(GET_BIT(USART_UCSRA_REG,USART_UCSRA_TXC) == 0);
		/* Get the received data and assign it to tha passed variable*/
	*Copy_u8ReceivedData = USART_UDR_REG;
}