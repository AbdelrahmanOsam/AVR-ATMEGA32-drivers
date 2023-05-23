/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 17 April , 2023
* SWC			: USART
* Layer			: MCAL
* Version		: V1.0
*********************************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void UART_voidInit(void);
void UART_voidTransmitDataSynchronous(u8 Copy_u8Data);
void UART_u8ReceiveDataSynchronous(u8 *Copy_u8ReceivedData);
#endif