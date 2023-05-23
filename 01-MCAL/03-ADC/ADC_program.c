/***************************************************************
* Author  : Abdelrahman Osam Khaled 
* Date    : 30 March , 2023
* SWC     : ADC
* Version : 1.0
* Layer   : MCAL
***************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

static void (*ADC_pvoidNotificationFunction)(void) = NULL;
volatile u16 ADC_u16ADCDigitalResult = 0;

void ADC_voidInit(void)
{
    /*Check For The ADC Enable*/
    #if ADC_ENABLE  == ENABLE
        SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN);
    #elif ADC_ENABLE == DISABLE
        CLEAR_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADEN);
    #else
        #error "Error, ADC_ENABLE Configuration Error"
    #endif

    /*Check For The ADC Interrupt*/ 
    #if ADC_INTERRUPT_STATUS == ENABLE
        SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIE);
    #elif ADC_INTERRUPT_STATUS == DISABLE
        CLEAR_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIE);
    #else
        #error("Error, ADC_INTERRUPT_ENABLE Configuration Error")
    #endif

	
    /*Check for the Reference Voltage Option*/
    /*#if ADC_REFERENCE_SELECTION == AREF
        CLEAR_BIT(ADMUX, ADMUX_REFS0);
        CLEAR_BIT(ADMUX, ADMUX_REFS1);
    #elif   ADC_REFERENCE_SELECTION == AVCC
        SET_BIT(ADMUX, ADMUX_REFS0);
        CLEAR_BIT(ADMUX, ADMUX_REFS1);       
    #elif   ADC_REFERENCE_SELECTION == INTERNAL_2v56
        SET_BIT(ADMUX, ADMUX_REFS0);
        SET_BIT(ADMUX, ADMUX_REFS1);
    #else
        #error ("Error, ADC_REFERENCE_SELECTION Configuration Error")
    #endif*/
	
	 /* 3mlna bit mask hna w e8tzlna line 37->49 l 2 lines bs 52,53 */
	 
	     /*Set the Reference Voltage selection*/
	ADC_ADMUX_REG &= REF_SEL_BIT_MASK;
	ADC_ADMUX_REG |= ADC_REFERENCE_SELECTION;

		/* Set the Prescaler Values*/
	ADC_ADCSRA_REG &= PRESCALER_SEL_MASK;
	ADC_ADCSRA_REG |= ADC_PRESCALER_SELECTION;
	
    /*Check For The ADC Adjust Result*/
    #if ADC_ADJUST_RESULT ==ADC_RIGHT_ADJUST
        CLEAR_BIT(ADC_ADMUX_REG,ADC_ADMUX_ADLAR);
    #elif ADC_ADJUST_RESULT == ADC_LEFT_ADJUST
        SET_BIT(ADC_ADMUX_REG,ADC_ADMUX_ADLAR);
    #else
        #error("Error, ADC_ADJUST_RESULT Configuration Error")
    #endif


}


void ADC_voidInterruptControl(u8 Copy_u8InterruptStatus)
{
    switch(Copy_u8InterruptStatus)
    {
        case DISABLE:
            CLEAR_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIE);
        break;

        case ENABLE:
            SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIE);
        break;

        default:
            /*Do Noting*/
        break;
    }
}
	/* Using polling */
u8 ADC_u8StartConversionSynchronous(u8 Copy_u8ChannelNumber)
{
	u8 Local_u8ReturnedDigitalValue;
	/* Set channel of ADC */
	ADC_ADMUX_REG &= CHANNEL_SELECTION_MASK;
	ADC_ADMUX_REG |= Copy_u8ChannelNumber;
	
	/* start the ADC to convert  input analog signal*/
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADSC);
	
	/* Polling (busy wait)till the flag is raised */
	while(GET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIF) == STD_TYPES_FALSE);
	
	/* Clear the flag */
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADIF);
	
	/* Return the digital value */
	#if ADC_ADJUST_RESULT == ADC_LEFT_ADJUST
		Local_u8ReturnedDigitalValue = ADC_ADCH_REG;
	#elif ADC_ADJUST_RESULT == ADC_RIGHT_ADJUST
		Local_u8ReturnedDigitalValue = ADC_ADCL_REG;
	#endif
	return Local_u8ReturnedDigitalValue;
}

	/* Using Interrupt */
void ADC_u8StartConversionAsynchronous(u8 Copy_u8ChannelNumber,void (*Copy_pvoidNotificationFunction)(void))
{
	/* Set channel of ADC */
	ADC_ADMUX_REG &= CHANNEL_SELECTION_MASK;
	ADC_ADMUX_REG |= Copy_u8ChannelNumber;
	
	ADC_pvoidNotificationFunction = Copy_pvoidNotificationFunction;

	/* start the ADC to convert  input analog signal*/
	SET_BIT(ADC_ADCSRA_REG,ADC_ADCSRA_ADSC);
}

void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	ADC_voidInterruptControl(ADC_INTERRUPT_DISABLE);
	ADC_u16ADCDigitalResult = ADC_ADCH_REG;
	if(ADC_pvoidNotificationFunction != NULL)
	{
		ADC_pvoidNotificationFunction();
	}
	else
	{
		//Nothing
	}
	ADC_voidInterruptControl(ADC_INTERRUPT_ENABLE);
}
