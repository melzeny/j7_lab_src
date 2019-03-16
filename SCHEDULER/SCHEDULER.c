/*
 * SCHEDULER.c
 *
 *  Created on: Mar 16, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "SCHEDULER_cfg.h"
#include "SCHEDULER.h"

typedef struct
{
	ptr2func_t str_taskPtr;
	u8 str_periodicity;

}Task_t;
Task_t TasksArr[SCHEDULER_MAX_NO_OF_TASKS];

void SCHEDULER_init(void)
{
	GI_en();
	TIMER0_enInterrupt();
	TIMER0_init();

}
ret_status_t SCHEDULER_createTask(ptr2func_t ptr2task,u8 periodicity)
{
	ret_status_t Ret_status;
	static u8 CurrentNumOfTasks =0;
	if(CurrentNumOfTasks < SCHEDULER_MAX_NO_OF_TASKS)
	{
		TasksArr[CurrentNumOfTasks].str_taskPtr=ptr2task;
		TasksArr[CurrentNumOfTasks].str_periodicity=periodicity;
		CurrentNumOfTasks++;
		Ret_status = OK;
	}
	else
	{
		Ret_status = NOT_OK;
	}
	return Ret_status;
}

TIMER0_CTC_ISR
{


}



