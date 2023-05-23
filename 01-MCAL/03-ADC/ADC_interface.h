/***************************************************************
* Author  : Abdelrahman Osam Khaled 
* Date    : 30 March , 2023
* SWC     : ADC
* Version : 1.0
* Layer   : MCAL
***************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H



void ADC_voidInit(void);

void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus);

u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber);

void ADC_u8StartConversionAsynchronous(u8 Copy_u8ChannelNumber,void (*Copy_pvoidNotificationFunction)(void));

#define ADC_INTERRUPT_ENABLE      1
#define ADC_INTERRUPT_DISABLE     0

#define ADC_CHANNEL_0			0b00000
#define ADC_CHANNEL_1			0b00001
#define ADC_CHANNEL_2			0b00010
#define ADC_CHANNEL_3			0b00011
#define ADC_CHANNEL_4			0b00100
#define ADC_CHANNEL_5			0b00101
#define ADC_CHANNEL_6			0b00110
#define ADC_CHANNEL_7			0b00111


#endif
