/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 7 April , 2023
* SWC     : Seven segment numbers
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"
#include "SevenSegment_config.h"

#include "DIO_interface.h"

void SevenSegment_voidInit(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortDirection(SevenSegmentobj->SevenSegment_PORT,0xFF);
}

void SevenSegment_voidDisplayNumber0(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO0);
}

void SevenSegment_voidDisplayNumber1(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO1);
}

void SevenSegment_voidDisplayNumber2(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO2);
}

void SevenSegment_voidDisplayNumber3(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO3);
}

void SevenSegment_voidDisplayNumber4(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO4);
}

void SevenSegment_voidDisplayNumber5(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO5);
}

void SevenSegment_voidDisplayNumber6(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO6);
}

void SevenSegment_voidDisplayNumber7(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO7);
}

void SevenSegment_voidDisplayNumber8(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO8);
}

void SevenSegment_voidDisplayNumber9(SevenSegment *SevenSegmentobj)
{
	DIO_u8SetPortValue(SevenSegmentobj->SevenSegment_PORT,SEVEN_SEGMENT_NO9);
}
