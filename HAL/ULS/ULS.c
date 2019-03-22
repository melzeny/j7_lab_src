/*
 * ULS.c
 *
 *  Created on: Mar 18, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "avr/delay.h"
#include "../../SCHEDULER/SCHEDULER.h"
#include "../../MCAL/EXTI/EXTI.h"
#include "../../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER_2/TIMER2.h"

#include "ULS_cfg.h"
#include "ULS.h"

static u8 CounterLoopNo;
static u8 timer_read_1,timer_read_2;
static boolean_t BusyFlag = false;
void ULS_task(void)
{
	/*trigger pulse */

	DIO_writePinValue(ULS_TRIGGER_PIN,DIO_pin_value_high);
	_delay_us(10);
	DIO_writePinValue(ULS_TRIGGER_PIN,DIO_pin_value_low);

}

void ULS_init(void)
{
	GI_en();

	EXTI_enInterrupt(ULS_ECHO_EXTI_PIN);
	EXTI_init(ULS_ECHO_EXTI_PIN);

	TIMER2_enInterrupt();

	SCHEDULER_createTask(ULS_task,ULS_TASK_PERIODICITY,0);
	TIMER2_init();
	SCHEDULER_init();
}

u16 ULS_getDistance_cm(void)
{
	u16 Distance_cm = 0,PulseWidth_steps,PulseWidth_us;
	EXTI_diInterrupt(ULS_TRIGGER_PIN);
	if(BusyFlag == false)
	{
		CounterLoopNo = 0;
		PulseWidth_steps = (s32)((s32)timer_read_2 - (s32)timer_read_1) + (CounterLoopNo*(u8)255);
		PulseWidth_us = PulseWidth_steps * ULS_STEP_TIME_us;
		Distance_cm = PulseWidth_us / 58;
	}
	EXTI_enInterrupt(ULS_TRIGGER_PIN);
	return Distance_cm;
}
ULS_TIMER_ISR
{
	if(BusyFlag == true)
	{
		CounterLoopNo++;
	}
}
#if 0
#if ULS_ECHO_EXTI_PIN == EXTI_int1
EXTI_1_ISR
#elif ULS_ECHO_EXTI_PIN == EXTI_int2
EXTI_2_ISR
#else
EXTI_0_ISR
#endif
{

	/* external interrupt edge should be configured onChange*/
	if(BusyFlag == false)
	{
		timer_read_1 = TIMER2_getNoOfSteps();
		BusyFlag = true;
	}
	else
	{
		timer_read_2 = TIMER2_getNoOfSteps();
		BusyFlag = false;
	}

}
#endif
