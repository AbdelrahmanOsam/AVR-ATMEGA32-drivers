/************************************************************************
* Author 	    : Abdelrahman Osam Khaled
* Creation date : 12 April , 2023
* SWC  		    : Watch dog timer
* Layer		    : MCAL
* Version 	    : v1.0
***********************************************************************/

#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

#define WDT_WDTCR_REG		*((volatile u8*)0x41)	//watchdog timer control register

#define WDT_WDTCR_WDP0			0			//watchdog timer prescaler bit 0
#define WDT_WDTCR_WDP1			1			//watchdog timer prescaler bit 1
#define WDT_WDTCR_WDP2			2			//watchdog timer prescaler bit 2
#define WDT_WDTCR_WDE			3			//watchdog timer enable bit
#define WDT_WDTCR_WDTOE			4			//watchdog timer turn off enable bit


#endif