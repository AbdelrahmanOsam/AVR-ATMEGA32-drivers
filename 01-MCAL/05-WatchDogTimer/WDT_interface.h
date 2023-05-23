/************************************************************************
* Author 	    : Abdelrahman Osam Khaled
* Creation date : 12 April , 2023
* SWC  		    : Watch dog timer
* Layer		    : MCAL
* Version 	    : v1.0
***********************************************************************/

#ifndef WDT_INTERFACE_H
#define WDT_INTERFACE_H

#define WDT_SLEEP_16_3_MS		0b000
#define WDT_SLEEP_32_5_MS		0b001
#define WDT_SLEEP_65_0_MS		0b010

void MWDT_voidEnable(void);
void MWDT_voidDisable(void);
void MWDT_voidSleep(u8 Copy_u8TimerOut);

#endif