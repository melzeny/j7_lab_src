/*
 * SCHEDULER.c
 *
 *  Created on: Mar 16, 2019
 *      Author: Muhammad.Elzeiny
 */
#define SCHEDULER_MODE_DISABLE     			0
#define SCHEDULER_MODE_TIMER_CTC   			1
#define SCHEDULER_MODE_TIMER_NORMAL			2

#include "../LIB/STD_TYPES.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "SCHEDULER_cfg.h"
#include "SCHEDULER.h"

static u8 CurrentNumOfTasks =0;

typedef struct
{
	ptr2func_t str_taskPtr;
	u32 str_periodicity;

}Task_t;
Task_t TasksArr[SCHEDULER_MAX_NO_OF_TASKS];

void SCHEDULER_init(void)
{
	GI_en();
	TIMER0_enInterrupt();
	TIMER0_init();

}
ret_status_t SCHEDULER_createTask(ptr2func_t ptr2task,u32 periodicity)
{
	ret_status_t Ret_status;
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
#if SCHEDULER_MODE_SELECTOR == SCHEDULER_MODE_TIMER_CTC
TIMER0_CTC_ISR
{
	u8 i;
	static u32 TickCounter = 0;
	/*loop */
	for(i=0;i<CurrentNumOfTasks;i++)
	{
		/*check if TickCounter multiple of periodicity  */
		if((TickCounter % TasksArr[i].str_periodicity) == 0)
		{
			TasksArr[i].str_taskPtr();
		}
	}
	TickCounter++;

}
#elif SCHEDULER_MODE_SELECTOR == SCHEDULER_MODE_TIMER_NORMAL
TIMER0_NORMAL_ISR
{
	u8 i;
	static u32 TickCounter = 0;
	TIMER0_setNoOfSteps(78);
	/*loop */
	for(i=0;i<CurrentNumOfTasks;i++)
	{
		/*check if TickCounter multiple of periodicity  */
		if((TickCounter % TasksArr[i].str_periodicity) == 0)
		{
			TasksArr[i].str_taskPtr();
		}
	}
	TickCounter++;

}
#endif





