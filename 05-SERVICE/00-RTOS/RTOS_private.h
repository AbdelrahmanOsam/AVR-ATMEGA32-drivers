/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 24 April , 2023
* SWC			: RTOS
* Layer			: SERVICE
* Version		: V1.0
*********************************************************************/

#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef struct
{
    u8 Priority;
	u16 FirstDaley;
    u16 Periodicity;
    States_t State;
    void (*TaskFunc)(void);
}Task_t;

typedef enum
{
    Deleted,
    Ready,
}States_t;

static Task_t SystemTasks[NUMBER_OF_TASKS] = {{0}};
static void voidScheduler(void);

#endif