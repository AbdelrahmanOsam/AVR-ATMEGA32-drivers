/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 28 March , 2023
* SWC     : Keypad
* Version : 1.0
*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Keypad_interface.h"
#include "Keypad_private.h"
#include "Keypad_config.h"

#include "DIO_interface.h"



void Keypad_voidInit(void)
{
	/* Set rows pins to be input pull up */
	DIO_u8SetPinDirection(KEYPAD_ROWS_PORT,KEYPAD_ROW0_PIN,DIO_PULLUP);
	DIO_u8SetPinDirection(KEYPAD_ROWS_PORT,KEYPAD_ROW1_PIN,DIO_PULLUP);
	DIO_u8SetPinDirection(KEYPAD_ROWS_PORT,KEYPAD_ROW2_PIN,DIO_PULLUP);
	DIO_u8SetPinDirection(KEYPAD_ROWS_PORT,KEYPAD_ROW3_PIN,DIO_PULLUP);
	

	/* set columns pins to be output high */
	DIO_u8SetPinDirection(KEYPAD_COLUMNS_PORT,KEYPAD_COLUMN0_PIN,DIO_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_COLUMNS_PORT,KEYPAD_COLUMN1_PIN,DIO_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_COLUMNS_PORT,KEYPAD_COLUMN2_PIN,DIO_OUTPUT);
	DIO_u8SetPinDirection(KEYPAD_COLUMNS_PORT,KEYPAD_COLUMN3_PIN,DIO_OUTPUT);

	DIO_u8SetPinValue(KEYPAD_COLUMNS_PORT,KEYPAD_COLUMN0_PIN,DIO_HIGH);
	DIO_u8SetPinValue(KEYPAD_COLUMNS_PORT,KEYPAD_COLUMN1_PIN,DIO_HIGH);
	DIO_u8SetPinValue(KEYPAD_COLUMNS_PORT,KEYPAD_COLUMN2_PIN,DIO_HIGH);
	DIO_u8SetPinValue(KEYPAD_COLUMNS_PORT,KEYPAD_COLUMN3_PIN,DIO_HIGH);
}


u8 Keypad_u8GetPressedKey(void)
{
	/* as static change lifetime of local variables fkda hwa hy3ml initialize w assignation
		lw el function etnadet tany fa homa mawgden 34an lifetime bta3hom b2a el program klo
				dh 3mlnah 34an nwfr time */
	static u8 Local_au8KeypadArray[KEYPAD_ROWS_NUM][KEYPAD_COLUMNS_NUM] = KEYPAD_ARR_VAL;
	static u8 Local_au8KeypadColumnsArray[KEYPAD_COLUMNS_NUM]={KEYPAD_COLUMN0_PIN,KEYPAD_COLUMN1_PIN,KEYPAD_COLUMN2_PIN,KEYPAD_COLUMN3_PIN};
	static u8 Local_au8KeypadRowsArray[KEYPAD_ROWS_NUM]={KEYPAD_ROW0_PIN,KEYPAD_ROW1_PIN,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};

	u8 Local_u8RowValue;
	
	u8 Local_u8PressedKey = KEYPAD_NOT_PRESSED_VALUE;
	u8 Local_u8ColumnIterator;       
	u8 Local_u8RowIterator;          
	                                 
	for(Local_u8ColumnIterator = 0;Local_u8ColumnIterator < KEYPAD_COLUMNS_NUM;Local_u8ColumnIterator++)
	{
		/* Activate a column , activate by (ground) */
		DIO_u8SetPinValue(KEYPAD_COLUMNS_PORT,Local_au8KeypadColumnsArray[Local_u8ColumnIterator],DIO_LOW);
		for(Local_u8RowIterator=0;Local_u8RowIterator<KEYPAD_ROWS_NUM;Local_u8RowIterator++)
		{
			/* Get Row Value */
			Local_u8RowValue = DIO_u8GetPinValue(KEYPAD_ROWS_PORT,Local_au8KeypadRowsArray[Local_u8RowIterator]);
			if(Local_u8RowValue == DIO_LOW)
			{
				/* Get pressed Key */
				Local_u8PressedKey = Local_au8KeypadArray[Local_u8RowIterator][Local_u8ColumnIterator];
				/* Polling (busy wait):ya3ny el processor hyfdal mstny 7aga t7sl*/
				/* busy wait : The key is relaesed*/
				while(Local_u8RowValue == DIO_LOW)
				{
					Local_u8RowValue = DIO_u8GetPinValue(KEYPAD_ROWS_PORT,Local_au8KeypadRowsArray[Local_u8RowIterator]);
				}
				return Local_u8PressedKey;
			}
			else
			{
				
			}
		}
		DIO_u8SetPinValue(KEYPAD_COLUMNS_PORT,Local_au8KeypadColumnsArray[Local_u8ColumnIterator],DIO_HIGH);
	}
	return Local_u8PressedKey;
}