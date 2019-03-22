/*
 * LAB_07_Scheduler_Uls.c
 *
 *  Created on: Mar 18, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../HAL/ULS/ULS.h"
#include "../SCHEDULER/SCHEDULER.h"
#include "../HAL/LCD/LCD.h"
#include <stdlib.h>
void UlsApp_task(void)
{
	u8 str[3]={0};
	u16 Distance = ULS_getDistance_cm();
	itoa(10,str,Distance);
	LCD_writeString(str,0,0);

}
void lab_07_UlsApp(void)
{
	SCHEDULER_createTask(UlsApp_task,100,0);

	LCD_init();
	ULS_init();
	SCHEDULER_init();
	while(1)
	{


	}


}


