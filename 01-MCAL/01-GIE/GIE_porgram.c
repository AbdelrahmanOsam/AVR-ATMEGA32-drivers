/*************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 29 March , 2023
* SWC	  : GIE 
* Layer	  : MCAL
* version : 1.0
*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"

void GIE_voidEnableGlobalInterrupt(void)
{
	SET_BIT(GIE_SREG_REG,GIE_SREG_PIN);
}

void GIE_voidDisableGlobalInterrupt(void)
{
	CLEAR_BIT(GIE_SREG_REG,GIE_SREG_PIN);
}