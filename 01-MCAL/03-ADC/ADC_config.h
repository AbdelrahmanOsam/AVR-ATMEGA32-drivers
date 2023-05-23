/***************************************************************
* Author  : Abdelrahman Osam Khaled 
* Date    : 30 March , 2023
* SWC     : ADC
* Version : 1.0
* Layer   : MCAL
***************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


#define     ADC_ADJUST_RESULT           ADC_LEFT_ADJUST
/*Options: 
        ADC_LEFT_ADJUST
        ADC_RIGHT_ADJUST
*/

#define     ADC_REFERENCE_SELECTION     ADC_AREF
/*
    Options for Voltage reference selection:
        ADC_AREF
        ADC_AVCC
        ADC_INTERNAL_2v56
*/


#define     ADC_INTERRUPT_STATUS        ENABLE
/*Options:
        ENABLE
        DISBALE
*/


#define     ADC_ENABLE                  ENABLE
/*Options:
        ENABLE
        DISBALE
*/
#define	ADC_PRESCALER_SELECTION			ADC_DIVISION_FACTOR_128
/* Options of prescaler selections : 
			ADC_DIVISION_FACTOR_2
			ADC_DIVISION_FACTOR_4
			ADC_DIVISION_FACTOR_8
			ADC_DIVISION_FACTOR_16
			ADC_DIVISION_FACTOR_32
			ADC_DIVISION_FACTOR_64
			ADC_DIVISION_FACTOR_128
*/
#endif
