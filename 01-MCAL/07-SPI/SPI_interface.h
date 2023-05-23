/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 17 April , 2023
* SWC			: SPI
* Layer			: MCAL
* Version		: V1.0
*********************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidMasterInit(void);
void SPI_voidSlaveInit(void);
u8 SPI_u8TransmitReceive(u8 Copy_u8Data);
void SPI_voidsendData(u8 Copy_Data)
u8 SPI_u8ReceiveData(u8 *pdata)


#endif