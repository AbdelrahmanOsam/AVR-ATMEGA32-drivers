/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 24 April , 2023
* SWC			: RTOS
* Layer			: SERVICE
* Version		: ->V1.0
				  ->V2.0 : Add first delay for tasks & change the counter algorithm 
*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "GIE_interface.h"

#include "RTOS_interface.h"
#include "RTOS_private.h"
#include "RTOS_config.h"

void RTOS_voidInit(void)
{
    /*Set The Compare Match Value To 125 To Make CTC Event every 1msec*/
    TIMER0_voidSetCTCCompareMatchValue(125);
    /*Set The Callback For Timer0 To Call Scheduler Function For Each Interrupt*/
    TIMER0_voidSetCTCCallBack(&voidScheduler);
    /*Enable The CTC Mode Interrupt*/
    TIMER0_voidEnableInterrupt(CTC_MODE);
    /*Enable The Global Interrupt*/
    GIE_voidEnableGlobalInterrupt();
    /*Set The CTC Mode, Prescaler = 64*/
    TIMER0_voidInit();
}

void RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity,u16 Copy_u16FirstDaley, void (*TaskFunction)(void))
{
    // SystemTasks[Copy_u8Priority].Priority = Copy_u8Priority;
    SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
    SystemTasks[Copy_u8Priority].TaskFunc = TaskFunction;
	SystemTasks[Copy_u8Priority].FirstDaley = Copy_u16FirstDaley;
    // SystemTasks[Copy_u8Priority].State = READY;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
    SystemTasks[Copy_u8Priority].TaskFunc = NULL;
    // SystemTasks[Copy_u8Priority].State = DELETED;
}

static void voidScheduler(void)
{
    /*Algorithm = Priority Based*/
	/* Local_u32TickCounter tmam w nfz el periodicity elly 3awzha bs 3ebo eno hay7slo overFlow
	w mynf34 n5le counter y7slo over flow fhnl8eh w n3ml code tany */
    //static u32 Local_u32TickCounter = 0;
    //Local_u32TickCounter++;
    u8 Local_u8LoopCounter;
    for (Local_u8LoopCounter = 0;Local_u8LoopCounter < NUMBER_OF_TASKS;Local_u8LoopCounter++)
    {
        if (SystemTasks[Local_u8LoopCounter].TaskFunc != NULL)
        {
            /*Algorithm Code*/
            //if (Local_u32TickCounter % SystemTasks[Local_u8LoopCounter].Periodicity == 0)
            if (SystemTasks[Local_u8LoopCounter].FirstDaley == 0)
			{
                /*Dispatcher Code*/
				/* Update the first delay parameter value */
				SystemTasks[Local_u8LoopCounter].FirstDaley = SystemTasks[Local_u8LoopCounter].Periodicity-1;
                /*Execute The Task Function*/
                SystemTasks[Local_u8LoopCounter].TaskFunc();
            }
			else
			{
				/* Decremnt the first dealy value by 1 */
				SystemTasks[Local_u8LoopCounter].FirstDaley --;
			}
        }
    }
}