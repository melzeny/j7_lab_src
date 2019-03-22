/*
 * LAB_08_PWM_Scheduler.c
 *
 *  Created on: Mar 22, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../SCHEDULER/SCHEDULER.h"
#include "../MCAL/DIO/DIO.h"

#define PWM_T			5
#define PWM_Ton			2
void pwm_Rising_Edge_task(void)
{
	DIO_writePinValue(DIO_pin_A0,DIO_pin_value_high);
}
void pwm_Falling_Edge_task(void)
{
	DIO_writePinValue(DIO_pin_A0,DIO_pin_value_low);

}
void lab_08_PwmScheduler(void)
{
	DIO_init();
	SCHEDULER_createTask(pwm_Rising_Edge_task,PWM_T,0);
	SCHEDULER_createTask(pwm_Falling_Edge_task,PWM_T,PWM_Ton);
	SCHEDULER_init();
	while(1)
	{

	}

}


