/**********************************************************************
* Author : Abdelrahman Osam Khaled
* Date	 : 26 March , 2023
* SWC	 : LCD
* Version : 1.0
************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

//#include "../../01-MCAL/00-DIO/DIO_interface.h"
#include "DIO_interface.h"


void LCD_voidInitialization(void)
{
	#if LCD_INIT_MODE	== EIGHT_BIT_MODE
			// Initialize data port
		DIO_u8SetPortDirection(LCD_DATA_PORT,LCD_ALL_OUTPUT);
			// Initialize control pins 
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,DIO_OUTPUT);
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,DIO_OUTPUT);
		DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_EN_PIN,DIO_OUTPUT);
			
			// wait for 40 ms
		_delay_ms(40);
			// send function set command
		LCD_voidSendCommand(FUNCTION_SET_COMMAND);
				// wait for 1msec
			// send display on off command
		LCD_voidSendCommand(DISPLAY_ON_OFF_COMMAND);
			// send clear command
		LCD_voidSendCommand(DISPLAY_CLEAR_COMMAND);
	#elif LCD_INIT_MODE == FOUR_BIT_MODE
	
	#else
		#error("LCD_INIT_MODE configuration error")
	#endif
}
static void LCD_voidSendCommand(u8 Copy_u8Command)
{
		//Clear RS pin to send command
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_LOW);
	
		// Clear the RW pin to send command
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	
		// set the command on the data pins
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Command);
	
		// send enable pulse
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
		//Clear RS pin to send Data
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_HIGH);
	
		// Clear the RW pin to send Data
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_LOW);
	
		// set the command on the data pins
	DIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Data);
	
		// send enable pulse
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_LOW);
}

void LCD_voidClearDisplay(void)
{
	LCD_voidSendCommand(DISPLAY_CLEAR_COMMAND);
}

void LCD_voidGoToXY(u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
	u8 Local_u8CharacterAddress = 0;
	/* Calculate the address of the character on LCD */
	if(Copy_u8XPosition == 0)
	{
		Local_u8CharacterAddress = Copy_u8YPosition;
	}
	else if (Copy_u8XPosition == 1)
	{
		Local_u8CharacterAddress = Copy_u8YPosition+0x40;
	}
	else
	{
		// Raise an error
	}
	
	/* set the 7th bit in the address variable */
	SET_BIT(Local_u8CharacterAddress,7);
	/* Send address variable as a command */
	LCD_voidSendCommand(Local_u8CharacterAddress);
}

void LCD_voidSendString(u8 *Copy_pu8StringArray)
{
	u8 Local_u8LoopCounter = 0;
	while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
	{
		LCD_voidSendData(Copy_pu8StringArray[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
	u8 Local_au8ArrayNumber[10];
	s8 Local_u8LoopCounter=0;
	while(Copy_u32Number != 0)
	{
		Local_au8ArrayNumber[Local_u8LoopCounter] = Copy_u32Number%10;
		Copy_u32Number /= 10;
		Local_u8LoopCounter++;
	}
	Local_u8LoopCounter --;

	/* Local_u8LoopCounter != 255 3mlna el condition da kda 34an el counter u8
		flma yb2a b zero w n3mlo DEC hyb2a 255 w momkn n5le Local_u8LoopCounter 
		s8 fe el decleration w n3ml Local_u8LoopCounter != 0 */
		
	//while(Local_u8LoopCounter != 255)
	while(Local_u8LoopCounter >= 0)
	{
		/* Gm3na 3la el rkm el askii code bta3 el zero elly bysawy = 48
			34an mynf34 ab3t el rkm keda lazm ykon fe el askii */
		LCD_voidSendData(Local_au8ArrayNumber[Local_u8LoopCounter] + '0');
		Local_u8LoopCounter --;
	}
}

void LCD_voidSendCustomCharacter(u8 *Copy_pu8CharacterArray,u8 Copy_u8PatternNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
    u8 Local_u8LoopCounter;
    u8 Local_u8CGRAMAddress = 0;
    /*Calculate the CGRAM Address = Pattern Number * 8*/
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
    /*Set The 6th bit in the CGRAM Address Command*/
    SET_BIT(Local_u8CGRAMAddress, 6);
    /*Send The CGRAM Address Command To The LCD*/
    LCD_voidSendCommand(Local_u8CGRAMAddress);
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
    {
        /*Send Byte From The Character Array*/
        LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
    }
    /*Send The Command to Set The DDRAM Address*/
    LCD_voidGoToXY(Copy_u8XPosition, Copy_u8YPosition);
    /*Display The Pattern From CGRAM*/
    LCD_voidSendData(Copy_u8PatternNumber);
}
