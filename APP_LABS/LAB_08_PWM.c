/*
 * LAB_08_PWM.c
 *
 *  Created on: Mar 22, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../MCAL/TIMER_2/TIMER2.h"
#include "../MCAL/DIO/DIO.h"
void lab_08_pwm(void)
{
	GI_en();
	TIMER2_enInterrupt();
	TIMER2_init();
	DIO_init();

	while(1)
	{


	}

}
TIMER2_CTC_ISR
{
	static boolean_t flag = false;
	if(flag == false)
	{
		TIMER2_setComparedValue(4);
		flag = true;

	}
	else
	{
		TIMER2_setComparedValue(16);
		flag = false;
	}
}
