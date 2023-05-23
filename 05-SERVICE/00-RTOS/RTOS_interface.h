/*******************************************************************
* Author 		: Abdelrahman Osam Khaled
* Creation Date : 24 April , 2023
* SWC			: RTOS
* Layer			: SERVICE
* Version		: V1.0
*********************************************************************/

#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

void RTOS_voidInit(void);
void RTOS_voidCreateTask(u8 Copy_u8Priority,u16 Copy_u16Periodicity,u16 Copy_u16FirstDaley,void (*TaskFunction)(void));
void RTOS_voidDeleteTask(u8 Copy_u8Priority);

#endif