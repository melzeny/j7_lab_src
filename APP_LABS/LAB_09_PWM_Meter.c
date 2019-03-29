/*
 * PWM_Measure.c
 *
 *  Created on: Mar 23, 2019
 *      Author: Mark Ashraf -  Mark Ashraf
 */
#define ONE_STEP_TIME_us		16

#include "../LIB/STD_TYPES.h"
#include "../SCHEDULER/SCHEDULER.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/TIMER_2/TIMER2.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/DIO/DIO.h"
#include "avr/delay.h"
#include "stdlib.h"
u32 Freq;
u8 DutyCycle;

void Display_task(void)
{
	u8 str_freq[5],str_DutyCycle[3];

	itoa(Freq,str_freq,10);
	itoa(DutyCycle,str_DutyCycle,10);

	LCD_writeCmd(LCD_CMD_CLEAR);
	LCD_writeString("Freq     : ",0,0);
	LCD_writeString(str_freq,0,10);

	LCD_writeString("DutyCycle: ",1,0);
	LCD_writeString(str_DutyCycle,1,10);


}
void lab_09_measurePwm(void)
{

	LCD_init();
//	SCHEDULER_createTask(Display_task,50,0);
//	SCHEDULER_init();
	EXTI_init(EXTI_int0);
	GI_en();
	EXTI_enInterrupt(EXTI_int0);
	TIMER2_init();


	while(1)
	{
		Display_task();
		_delay_ms(1000);

	}
}
EXTI_0_ISR
{
	static u8 T0_steps,T1_steps,T2_steps;
	static  u8 flag = 0;
	/*rising Edge*/
	if(flag == 0)
	{
		EXTI_setEdge(EXTI_int0,EXTI_FallingEdge);
		T0_steps = TIMER2_getCurrentCounterSteps();
		flag =1;
	}
	/*falling edge*/
	else if(flag == 1)
	{
		EXTI_setEdge(EXTI_int0,EXTI_RisingEdge);
		T1_steps  = TIMER2_getCurrentCounterSteps();
		flag =2;
	}
	/*rising Edge*/
	else
	{
		T2_steps  = TIMER2_getCurrentCounterSteps();
		flag =0;

		/*calc freq and DutyCycle*/
		Freq = 1000000/((T2_steps - T0_steps) * ONE_STEP_TIME_us);
		DutyCycle = ( (T1_steps* 100 - T0_steps* 100) / (T2_steps - T0_steps))  ;

		TIMER2_setCounterSteps(0);
	}

}
