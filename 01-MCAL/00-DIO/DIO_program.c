/**************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 22 March , 2023
* SWC     : DIO
* Version : 1.0
* Layer   : MCAL
**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

u8 DIO_u8SetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_u8PortID)
	{
		case DIO_PORTA : 
				switch(Copy_u8PinDirection)
				{
					case DIO_INPUT :
						CLEAR_BIT(DIO_DDRA_REG,Copy_u8PinID);
					break;
					case DIO_OUTPUT :
						SET_BIT(DIO_DDRA_REG,Copy_u8PinID);
					break;
					default :		
						Local_u8ErrorState = STD_TYPES_NOK;
					break;
				}
		break;
		case DIO_PORTB :
				switch(Copy_u8PinDirection)
				{
					case DIO_INPUT :
						CLEAR_BIT(DIO_DDRB_REG,Copy_u8PinID);
					break;
					case DIO_OUTPUT :
						SET_BIT(DIO_DDRB_REG,Copy_u8PinID);
					break;
					default :
						Local_u8ErrorState = STD_TYPES_NOK;
					break;
				}
		break;
		case DIO_PORTC :
				switch(Copy_u8PinDirection)
				{
					case DIO_INPUT :
						CLEAR_BIT(DIO_DDRC_REG,Copy_u8PinID);
					break;
					case DIO_OUTPUT :
						SET_BIT(DIO_DDRC_REG,Copy_u8PinID);
					break;
					default :
						Local_u8ErrorState = STD_TYPES_NOK;
					break;
				}
		break;
		case DIO_PORTD :
				switch(Copy_u8PinDirection)
				{
					case DIO_INPUT :
						CLEAR_BIT(DIO_DDRD_REG,Copy_u8PinID);
					break;
					case DIO_OUTPUT :
						SET_BIT(DIO_DDRD_REG,Copy_u8PinID);
					break;
					default :
						Local_u8ErrorState = STD_TYPES_NOK;
					break;
				}
		break;
		
		default : 	Local_u8ErrorState = STD_TYPES_NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch (Copy_u8PortID)
	{
		case DIO_PORTA : 
				switch(Copy_u8PinValue)
				{
					case DIO_LOW :
						CLEAR_BIT(DIO_PORTA_REG,Copy_u8PinID);
					break;
					case DIO_HIGH :
						SET_BIT(DIO_PORTA_REG,Copy_u8PinID);
					break;
					default :
						Local_u8ErrorState = STD_TYPES_NOK;
					break;
				}
		break;
		case DIO_PORTB :
				switch(Copy_u8PinValue)
				{
					case DIO_INPUT :
						CLEAR_BIT(DIO_PORTB_REG,Copy_u8PinID);
					break;
					case DIO_OUTPUT :
						SET_BIT(DIO_PORTB_REG,Copy_u8PinID);
					break;
					default :
						Local_u8ErrorState = STD_TYPES_NOK;
					break;
				}
		break;
		case DIO_PORTC :
				switch(Copy_u8PinValue)
				{
					case DIO_INPUT :
						CLEAR_BIT(DIO_PORTC_REG,Copy_u8PinID);
					break;
					case DIO_OUTPUT :
						SET_BIT(DIO_PORTC_REG,Copy_u8PinID);
					break;
					default :
						Local_u8ErrorState = STD_TYPES_NOK;
					break;
				}
		break;
		case DIO_PORTD :
				switch(Copy_u8PinValue)
				{
					case DIO_INPUT :
						CLEAR_BIT(DIO_PORTD_REG,Copy_u8PinID);
					break;
					case DIO_OUTPUT :
						SET_BIT(DIO_PORTD_REG,Copy_u8PinID);
					break;
					default :
						Local_u8ErrorState = STD_TYPES_NOK;
					break;
				}
		break;
		default :
			Local_u8ErrorState = STD_TYPES_NOK;
		break;
	}
	
	return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	u8 Local_u8ReturnedPinValue = 0;
	switch(Copy_u8PortID)
	{
		case DIO_PORTA :
				Local_u8ReturnedPinValue = GET_BIT(DIO_PINA_REG,Copy_u8PinID);
		break;
		case DIO_PORTB :
				Local_u8ReturnedPinValue = GET_BIT(DIO_PINB_REG,Copy_u8PinID);
		break;
		case DIO_PORTC :
				Local_u8ReturnedPinValue = GET_BIT(DIO_PINC_REG,Copy_u8PinID);
		break;
		case DIO_PORTD :
				Local_u8ReturnedPinValue = GET_BIT(DIO_PIND_REG,Copy_u8PinID);
		break;
		default :
			Local_u8ErrorState = STD_TYPES_NOK;
		break;
	}
	if (Local_u8ErrorState == STD_TYPES_OK)
	{
		return Local_u8ReturnedPinValue;
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
		return Local_u8ErrorState;
	}
}

u8 DIO_u8SetPortDirection(u8 Copy_u8PortID,u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8PortID)
	{
		case DIO_PORTA :
				SET_REG(DIO_DDRA_REG,Copy_u8PortDirection);
		break;
		case DIO_PORTB :
				SET_REG(DIO_DDRB_REG,Copy_u8PortDirection);
		break;
		case DIO_PORTC :
				SET_REG(DIO_DDRC_REG,Copy_u8PortDirection);
		break;
		case DIO_PORTD :
				SET_REG(DIO_DDRD_REG,Copy_u8PortDirection);
		break;
		default :
				Local_u8ErrorState = STD_TYPES_NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue(u8 Copy_u8PortID,u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	switch(Copy_u8PortID)
	{
		case DIO_PORTA :
				SET_REG(DIO_PORTA_REG,Copy_u8PortValue);
		break;
		case DIO_PORTB :
				SET_REG(DIO_PORTB_REG,Copy_u8PortValue);
		break;
		case DIO_PORTC :
				SET_REG(DIO_PORTC_REG,Copy_u8PortValue);
		break;
		case DIO_PORTD :
				SET_REG(DIO_PORTD_REG,Copy_u8PortValue);
		break;
		default :
				Local_u8ErrorState = STD_TYPES_NOK;
		break;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue(u8 Copy_u8PortID)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8ReturnedPortValue = 0x00;
	switch(Copy_u8PortID)
	{
		case DIO_PORTA :
				Local_u8ReturnedPortValue = GET_REG(DIO_PINA_REG);
		break;
		case DIO_PORTB :
				Local_u8ReturnedPortValue = GET_REG(DIO_PINB_REG);
		break;
		case DIO_PORTC :
				Local_u8ReturnedPortValue = GET_REG(DIO_PINC_REG);
		break;
		case DIO_PORTD :
				Local_u8ReturnedPortValue = GET_REG(DIO_PIND_REG);
		break;
		default : 
				Local_u8ErrorState = STD_TYPES_NOK;
		break;
	}
	if (Local_u8ErrorState == STD_TYPES_OK)
	{
		return Local_u8ReturnedPortValue;
	}
	else
	{
		return Local_u8ErrorState;
	}
}
void DIO_voidTogglePort(u8 Copy_u8PortID)
{
	u8 Local_u8ReturnedPortValue;
	
	Local_u8ReturnedPortValue =  DIO_u8GetPortValue(Copy_u8PortID);
	
	TOGGLE_REG(Local_u8ReturnedPortValue);
	
	DIO_u8SetPortValue(Copy_u8PortID,Local_u8ReturnedPortValue);
}