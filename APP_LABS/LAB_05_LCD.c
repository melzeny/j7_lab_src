/*
 * LAB_05_LCD.c
 *
 *  Created on: Mar 8, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../HAL/LCD/LCD.h"

void lab_05_lcd(void)
{
	u8 customChar[8]={0,0,31,5,7,0,0,0};
	LCD_init();
	LCD_storeCustomChar(customChar,0);
	LCD_displayCustomChar(0,0,5);
	while(1)
	{

	}


}
