/**************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 22 March , 2023
* SWC     : DIO
* Version : 1.0
* Layer   : MCAL
**************************************************************************/

#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/************** Function prototypes ********************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDirection);

u8 DIO_u8SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);

u8 DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);

u8 DIO_u8SetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortDirection);

u8 DIO_u8SetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue(u8 Copy_u8PortID);

void DIO_voidTogglePort(u8 Copy_u8PortID);


/* Macros for ports */
#define DIO_PORTA			0
#define DIO_PORTB			1
#define DIO_PORTC			2
#define DIO_PORTD			3

/* Macros for pins */
#define DIO_PIN0			0
#define DIO_PIN1			1
#define DIO_PIN2			2
#define DIO_PIN3			3
#define DIO_PIN4			4
#define DIO_PIN5			5
#define DIO_PIN6			6
#define DIO_PIN7			7

/* Macros for direction */
#define DIO_INPUT			0
#define DIO_OUTPUT			1

/* Macros for value */
#define DIO_LOW				0
#define DIO_HIGH			1

#define DIO_INPUT_FLOAT		0
#define DIO_INPUT_PULLUP	1


#endif
