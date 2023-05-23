/***************************************************************
* Author  : Abdelrahman Osam Khaled 
* Date    : 30 March , 2023
* SWC     : ADC
* Version : 1.0
* Layer   : MCAL
***************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

		/**** ADC Register digital value *****/
#define ADC_ADMUX_REG   	*((volatile u8 *)0x27)  // ADC Multiplixer Selection Register
#define ADC_ADCSRA_REG  	*((volatile u8 *)0x26)  // ADC Control and Status Register
#define	ADC_ADCH_REG		*((	volatile u8*)0x25)	// ADC High register (8-bits)
#define	ADC_ADCL_REG		*((	volatile u8*)0x24)	// ADC Low register	 (8-bits)
#define	ADC_ADCHL_REG		*((	volatile u16*)0x24) //ADC High&Low register (16-bits)

/*****************Macros for ADMUX register ********************/
#define ADC_ADMUX_MUX0       0    // ADC Muliplixer Bit 0
#define ADC_ADMUX_MUX1       1    // ADC Muliplixer Bit 1
#define ADC_ADMUX_MUX2       2    // ADC Muliplixer Bit 2
#define ADC_ADMUX_MUX3       3    // ADC Muliplixer Bit 3
#define ADC_ADMUX_MUX4       4    // ADC Muliplixer Bit 4
#define ADC_ADMUX_ADLAR      5    // ADC Left Adjust Result
#define ADC_ADMUX_REFS0      6    // ADC Reference Selection Bit 0
#define ADC_ADMUX_REFS1      7    // ADC Reference Selection Bit 1

/****************Macros for ADCSRA register *********************/
#define ADC_ADCSRA_ADPS0     0    // ADC Prescaler Selection bit 0 
#define ADC_ADCSRA_ADPS1     1    // ADC Prescaler Selection bit 1
#define ADC_ADCSRA_ADPS2     2    // ADC Prescaler Selection bit 2
#define ADC_ADCSRA_ADIE      3    // ADC Interrupt Enable Bit
#define ADC_ADCSRA_ADIF      4    // ADC Interrupt Flag Bit
#define ADC_ADCSRA_ADATE     5    // ADC Auto Trigger Enable bit
#define ADC_ADCSRA_ADSC      6    // ADC Start Conversion bit
#define ADC_ADCSRA_ADEN      7    // ADC Enable Bit

		/*** Macros for ADC masks ***/
#define	REF_SEL_BIT_MASK			0b00111111
#define	PRESCALER_SEL_MASK			0b11111000
#define CHANNEL_SELECTION_MASK 		0b11100000

		/*** Macros for ADC Voltage reference selection ***/
#define ADC_AREF                	0b00000000  
#define ADC_AVCC                	0b01000000
#define ADC_INTERNAL_2v56       	0b11000000

		/*** Macros ADC Prescaler Selections	***/
#define	ADC_DIVISION_FACTOR_2		0b00000000
#define	ADC_DIVISION_FACTOR_4    	0b00000010
#define	ADC_DIVISION_FACTOR_8    	0b00000011
#define	ADC_DIVISION_FACTOR_16      0b00000100
#define	ADC_DIVISION_FACTOR_32      0b00000101
#define	ADC_DIVISION_FACTOR_64      0b00000110
#define	ADC_DIVISION_FACTOR_128     0b00000111

		/*************Different Macros*******************/
#define	ADC_RIGHT_ADJUST            0
#define ADC_LEFT_ADJUST             1

#define     DISABLE                 0
#define     ENABLE                  1


#endif