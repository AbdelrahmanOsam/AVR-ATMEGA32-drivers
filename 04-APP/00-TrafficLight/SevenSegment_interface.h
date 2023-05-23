/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 7 April , 2023
* SWC     : Seven segment numbers
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

typedef struct
{
	u8 SevenSegment_PORT;
}SevenSegment;

void SevenSegment_voidInit(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber0(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber1(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber2(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber3(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber4(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber5(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber6(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber7(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber8(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber9(SevenSegment *SevenSegmentobj);

/* Macros for numbers */
#define SEVEN_SEGMENT_NO0	0b00111111
#define SEVEN_SEGMENT_NO1	0b00000110
#define SEVEN_SEGMENT_NO2	0b01011011
#define SEVEN_SEGMENT_NO3	0b01001111
#define SEVEN_SEGMENT_NO4	0b01100110
#define SEVEN_SEGMENT_NO5	0b01101101
#define SEVEN_SEGMENT_NO6	0b01111101
#define SEVEN_SEGMENT_NO7	0b00000111
#define SEVEN_SEGMENT_NO8	0b01111111
#define SEVEN_SEGMENT_NO9	0b01101111

#endif
