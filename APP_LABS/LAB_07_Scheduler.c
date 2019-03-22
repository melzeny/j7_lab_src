/*
 * LAB_07_Scheduler.c
 *
 *  Created on: Mar 16, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/DIO/DIO.h"
#include "../SCHEDULER/SCHEDULER.h"

void task_1(void)
{
	DIO_togglePin(DIO_pin_A0);

}
void task_2(void)
{
	DIO_togglePin(DIO_pin_A1);

}
void lab_07_Scheduler(void)
{
	DIO_init();
	SCHEDULER_init();
	SCHEDULER_createTask(task_1,1,0);
	SCHEDULER_createTask(task_2,2,0);
	while(1)
	{


	}


}
