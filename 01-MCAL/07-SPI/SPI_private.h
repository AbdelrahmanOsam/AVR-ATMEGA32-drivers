/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 17 April , 2023
* SWC			: SPI
* Layer			: MCAL
* Version		: V1.0
*********************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPI_SPCR_REG	*(volatile u8*(0x2D))
#define SPI_SPSR_REG	*(volatile u8*(0x2E))
#define SPI_SPDR_REG	*(volatile u8*(0x2F))

/*********** Macros for SPCR REG ***********/
#define SPI_SPCR_SPR0	0
#define SPI_SPCR_SPR1	1
#define SPI_SPCR_CPHA	2
#define SPI_SPCR_CPOL	3
#define SPI_SPCR_MSTR	4
#define SPI_SPCR_DORD	5
#define SPI_SPCR_SPE	6
#define SPI_SPCR_SPIE	7

/*********** Macros for SPSR REG ***********/
#define SPI_SPSR_SPI2X	0
#define SPI_SPSR_WCOL	6
#define SPI_SPSR_SPIF	7

/*********** Macros for SPSR REG ***********/
#define SPI_SPDR_LSB	0
#define SPI_SPDR_MSB	7

/*** MACROS for CLOCK_POLARITY_SELECTION ***/
#define LEADING_RISING_TRAILING_FALLING_MODE	0
#define LEADING_FALLING_TRAILING_RISING_MODE	1

/*** Macros for CLOCK_PHASE_SELECTION ***/
#define SAMPLE_LEADING_SETUP_TRAILING_MODE		0
#define SETUP_LEADING_SAMPLE_TRAILING_MODE		1

/*** Macros for CLOCK_RATE_SELECTION ***/
#define FREQUENCY_DIVIDE_BY_4_MODE				0
#define FREQUENCY_DIVIDE_BY_16_MODE				1
#define FREQUENCY_DIVIDE_BY_64_MODE				2
#define FREQUENCY_DIVIDE_BY_128_MODE			3
#define FREQUENCY_DIVIDE_BY_2_MODE				4
#define FREQUENCY_DIVIDE_BY_8_MODE				5
#define FREQUENCY_DIVIDE_BY_32_MODE				6
#define FREQUENCY_DIVIDE_BY_64_MODE				7

#endif