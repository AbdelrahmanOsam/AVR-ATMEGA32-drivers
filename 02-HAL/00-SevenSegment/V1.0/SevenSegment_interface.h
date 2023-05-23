/*******************************************************************
* Author : Abdelrahman Osam Khaled
* Date : 28 March , 2023
* SWC : Seven segment numbers
* Version : 1.0
*******************************************************************/

#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

typedef struct
{
	u8 SevenSegment_PORT;
}SevenSegment;

void SevenSegment_voidInit(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber0(void);

void SevenSegment_voidDisplayNumber1(void);

void SevenSegment_voidDisplayNumber2(void);

void SevenSegment_voidDisplayNumber3(void);

void SevenSegment_voidDisplayNumber4(void);

void SevenSegment_voidDisplayNumber5(void);

void SevenSegment_voidDisplayNumber6(void);

void SevenSegment_voidDisplayNumber7(void);

void SevenSegment_voidDisplayNumber8(void);

void SevenSegment_voidDisplayNumber9(void);

#endif