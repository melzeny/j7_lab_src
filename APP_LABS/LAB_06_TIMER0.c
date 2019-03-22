/*
 * LAB_06_TIMER0.c
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER_0/TIMER0.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
void lab_06_timer(void)
{
	GI_en();
	TIMER0_enInterrupt();

	DIO_init();
	TIMER0_init();
	while(1)
	{


	}

}
TIMER0_NORMAL_ISR
{
	static u8 counter =0;
	TIMER0_setCounterSteps(156);
	if(counter >= 50)
	{
		DIO_togglePin(DIO_pin_A0);
		counter =0;
	}
	counter++;
}

