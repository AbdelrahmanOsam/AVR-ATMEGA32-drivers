/************************************************************************
* Author 	    : Abdelrahman Osam Khaled
* Creation date : 12 April , 2023
* SWC  		    : Watch dog timer
* Layer		    : MCAL
* Version 	    : v1.0
***********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"


void MWDT_voidEnable(void)
{
	/* Set the WDE bit to enable the watchdog Timer */
	SET_BIT(WDT_WDTCR_REG,WDT_WDICR_WDE);
}

void MWDT_voidSleep(u8 Copy_u8TimerOut)
{
	/* Mask (clear) the first three bits in WDTCR (WDP2:0) */
	WDT_WDTCR_REG &= 0b11111000;
	/* Set the time out to WDT */
	WDT_WDTCR_REG |= Copy_u8TimerOut;
}

void MWDT_voidDisable(void)
{
	/* WDT Disable sequence :
	* 1- WDTE , WDE->1 @ the same time 
	* 2- Write 0 in WDE->within the next four clock cycles */
	WDT_WDTCR_REG |= (1<<WDT_WDTCR_WDTOE)|(1<<WDT_WDTCR_WDE);
	WDT_WDTCR_REG=0;
}