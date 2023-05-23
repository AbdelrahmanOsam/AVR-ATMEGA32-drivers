/*************************************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 29 March , 2023
* SWC	  : GIE 
* Layer	  : MCAL
* version : 1.0
*************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#include "DIO_interface.h"

/* dh array of global pointer to function to be read for void __vector_1&2&3(void) & 
		void EXTI_voidINT0SetCallback(void (*NotificationFunction)(void))*/

void (*EXTI_pvoidINTNotificationFunction[3])(void)= {NULL,NULL,NULL};

/**************************************************************/
/*void EXTI_voidInit(EXTI *EXTI_obj)
{
	#if EXTI_PIN_CONNECTION == EXTI_INTERNAL_PULLUP
		DIO_voidSetPinDirection(EXTI_obj->Local_u8EXTIPort ,EXTI_obj->Local_u8EXTIPin ,DIO_INPUT);
		DIO_voidSetPinValue(EXTI_obj->Local_u8EXTIPort ,EXTI_obj->Local_u8EXTIPin ,DIO_HIGH);
	#elif EXTI_PIN_CONNECTION == EXTI_EXTERNAL_PULLUP
		DIO_voidSetPinDirection(EXTI_obj->Local_u8EXTIPort ,EXTI_obj->Local_u8EXTIPin,DIO_INPUT);
	#elif EXTI_PIN_CONNECTION == EXTI_EXTERNAL_PULLDOWN
		DIO_voidSetPinDirection(EXTI_obj->Local_u8EXTIPort ,EXTI_obj->Local_u8EXTIPin,DIO_INPUT);
	#endif
}*/
void EXTI_voidInit(u8 Copy_u8InterruptNumber)
{
	switch(Copy_u8InterruptNumber)
	{
		case EXTI_INT0 :
			#if EXTI_PIN_CONNECTION == EXTI_INTERNAL_PULLUP
				DIO_u8SetPinDirection(EXTI0_PORT,EXTI0_PIN,DIO_INPUT);
				DIO_u8SetPinValue(EXTI0_PORT,EXTI0_PIN,DIO_HIGH);
			#elif EXTI_PIN_CONNECTION == EXTI_EXTERNAL_PULLUP
				DIO_u8SetPinDirection(EXTI0_PORT,EXTI0_PIN,DIO_INPUT);
			#elif EXTI_PIN_CONNECTION == EXTI_EXTERNAL_PULLDOWN
				DIO_u8SetPinDirection(EXTI0_PORT,EXTI0_PIN,DIO_INPUT);
			#else
				#error "Configuration error : Input pin connection error"
			#endif
		break;
		case EXTI_INT1 :
			#if EXTI_PIN_CONNECTION == EXTI_INTERNAL_PULLUP
				DIO_u8SetPinDirection(EXTI1_PORT,EXTI1_PIN,DIO_INPUT);
				DIO_u8SetPinValue(EXTI1_PORT,EXTI1_PIN,DIO_HIGH);
			#elif EXTI_PIN_CONNECTION == EXTI_EXTERNAL_PULLUP
				DIO_u8SetPinDirection(EXTI1_PORT,EXTI1_PIN,DIO_INPUT);
			#elif EXTI_PIN_CONNECTION == EXTI_EXTERNAL_PULLDOWN
				DIO_u8SetPinDirection(EXTI1_POR,EXTI1_PIN,DIO_INPUT);
			#else
				#error "Configuration error : Input pin connection error"
			#endif
		break;
		case EXTI_INT2 :
			#if EXTI_PIN_CONNECTION == EXTI_INTERNAL_PULLUP
				DIO_u8SetPinDirection(EXTI2_PORT,EXTI2_PIN,DIO_INPUT);
				DIO_u8SetPinValue(EXTI2_PORT,EXTI2_PIN,DIO_HIGH);
			#elif EXTI_PIN_CONNECTION == EXTI_EXTERNAL_PULLUP
				DIO_u8SetPinDirection(EXTI2_PORT,EXTI2_PIN,DIO_INPUT);
			#elif EXTI_PIN_CONNECTION == EXTI_EXTERNAL_PULLDOWN
				DIO_u8SetPinDirection(EXTI2_POR,EXTI2_PIN,DIO_INPUT);
			#else
				#error "Configuration error : Input pin connection error"
			#endif
		break;
		default :
			// Error 
		break;
	}        
}            
void EXTI_voidInterruptSenseMode(u8 Copy_u8InterruptNumber,u8 Copy_u8SenseMode)
{
	switch(Copy_u8InterruptNumber)
	{
		case EXTI_INT0 :
					switch(Copy_u8SenseMode)
					{
						case EXTI_LOW_LEVEL : 
								CLEAR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
								CLEAR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
						break;
						case EXTI_ANY_LOGICAL_CHANGE :
								SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
								CLEAR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
						break;
						case EXTI_FALLING_EDGE :
								CLEAR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
								SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
						break;
						case EXTI_RISING_EDGE :
								SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC00);
								SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC01);
						break;
						default : 
						break;
					}
		break;
		case EXTI_INT1:
					switch(Copy_u8SenseMode)
					{
						case EXTI_LOW_LEVEL : 
								CLEAR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
								CLEAR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
						break;
						case EXTI_ANY_LOGICAL_CHANGE :
								SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
								CLEAR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
						break;
						case EXTI_FALLING_EDGE :
								CLEAR_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
								SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
						break;
						case EXTI_RISING_EDGE :
								SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC10);
								SET_BIT(EXTI_MCUCR_REG,EXTI_MCUCR_ISC11);
						break;
						default : 	//error state
						break;
					}
		break;
		case EXTI_INT2:
					switch(Copy_u8SenseMode)
					{
						case EXTI_FALLING_EDGE :
								CLEAR_BIT(EXTI_MCUCSR_REG,EXTI_MCUCSR_ISC2);
						break;
						case EXTI_RISING_EDGE :
								SET_BIT(EXTI_MCUCSR_REG,EXTI_MCUCSR_ISC2);
						break;
						default : 	//error state
						break;
					}
		break;
		default :		//Error state
		break;
	}
}

void EXTI_voidEnableInterrupt(u8 Copy_u8InterruptNumber)
{
	switch(Copy_u8InterruptNumber)
	{
		case EXTI_INT0 :
					SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT0);
		break;
		case EXTI_INT1:
					SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT1);
		break;
		case EXTI_INT2:
					SET_BIT(EXTI_GICR_REG,EXTI_GICR_INT2);
		break;
		default :		//Error state
		break;
	}
}

void EXTI_voidDisableInterrupt(u8 Copy_u8InterruptNumber)
{
	switch(Copy_u8InterruptNumber)
	{
		case EXTI_INT0 :
					CLEAR_BIT(EXTI_GICR_REG,EXTI_GICR_INT0);
		break;
		case EXTI_INT1:
					CLEAR_BIT(EXTI_GICR_REG,EXTI_GICR_INT1);
		break;
		case EXTI_INT2:
					CLEAR_BIT(EXTI_GICR_REG,EXTI_GICR_INT2);
		break;
		default :		//Error state
		break;
	}
}

/* e7na 3awzen nrbt ben el void vector function w el function el fe el main elly 
	httnfz lma y7sl interrupt */
void EXTI_voidINTSetCallback(u8 Copy_u8EXTIIndex,void (*NotificationFunction)(void))
{
	EXTI_pvoidINTNotificationFunction[Copy_u8EXTIIndex]= NotificationFunction;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	/* 3mlna el if de 34an momkn y7sl interrupt  mn 8er ma el user y3ml callback function
	 fa sa3tha haynfz el GV  wmn3rfsh feha eh fa el if no3 mn anwa3 el security */
	if (EXTI_pvoidINTNotificationFunction[0] != NULL)
	{
		EXTI_pvoidINTNotificationFunction[0]();
	}
	else
	{
		// Do Nothing
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (EXTI_pvoidINTNotificationFunction[1] != NULL)
	{
		EXTI_pvoidINTNotificationFunction[1]();
	}
	else
	{
		// DoNothing
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (EXTI_pvoidINTNotificationFunction[2] != NULL)
	{
		EXTI_pvoidINTNotificationFunction[2]();
	}
	else
	{
		// Do Nothing
	}
}