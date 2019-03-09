/*
 * LAB_05_LCD.c
 *
 *  Created on: Mar 8, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../HAL/LCD/LCD.h"

void lab_05_lcd(void)
{
	LCD_init();
	LCD_writeString("AHMED",1,4);
	while(1)
	{

	}


}
