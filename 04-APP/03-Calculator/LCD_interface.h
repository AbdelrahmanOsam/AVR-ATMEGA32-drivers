/**********************************************************************
* Author : Abdelrahman Osam Khaled
* Date	 : 26 March , 2023
* SWC	 : LCD
* Version : 1.0
************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidInit(void);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidClearDisplay(void);

void LCD_voidGoToXY(u8 Copy_u8XPosition,u8 Copy_u8YPosition);

void LCD_voidSendString(u8 *Copy_pu8StringArray);

void LCD_voidSendNumber(u32 Copy_u32Number);

void LCD_voidSendCustomCharacter(u8 * Copy_pu8CharacterArray,u8 Copy_u8PatternNumber,u8 Copy_u8XPosition,u8 Copy_u8YPosition);




#endif
