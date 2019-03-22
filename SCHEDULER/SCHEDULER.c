
/*
 * SCHEDULER.c
 *
 *  Created on: Mar 16, 2019
 *      Author: Mohammad.Zharan - Noran Raafat
 */

#include "../LIB/STD_TYPES.h"
#include "../MCAL/TIMER_0/TIMER0.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "SCHEDULER_cfg.h"
#include "SCHEDULER.h"

static u8 CurrentNumOfTasks =0;

typedef struct
{
	p2func_t str_taskPtr;
	u32 str_periodicity;
	u32 str_first_delay;

}Task_t;
Task_t TasksArr[SCHEDULER_MAX_NO_OF_TASKS];

void SCHEDULER_init(void)
{
	GI_en();
	TIMER0_enInterrupt();
	TIMER0_init();

}
ret_status_t SCHEDULER_createTask(p2func_t ptr2task,
		u32 periodicity,
		u32 FirstDelay)
{
	ret_status_t Ret_status;
	if(CurrentNumOfTasks < SCHEDULER_MAX_NO_OF_TASKS)
	{
		TasksArr[CurrentNumOfTasks].str_taskPtr=ptr2task;
		TasksArr[CurrentNumOfTasks].str_periodicity=periodicity;
		TasksArr[CurrentNumOfTasks].str_first_delay = FirstDelay;
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
	u8 i;
	/*loop */
	for(i=0;i<CurrentNumOfTasks;i++)
	{
		/*check if TickCounter multiple of periodicity  */
			if(TasksArr[i].str_first_delay == 0)
			{
				TasksArr[i].str_first_delay = TasksArr[i].str_periodicity;
				TasksArr[i].str_taskPtr();
				TasksArr[i].str_first_delay--;
			}
			else
			{
				TasksArr[i].str_first_delay--;
			}
	}
}
