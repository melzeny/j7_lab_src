/*
 * LAB_10_ADC.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../MCAL/ADC/ADC.h"
#include "../HAL/LCD/LCD.h"
#include "stdlib.h"
#include <avr/delay.h>
#include "../SCHEDULER/SCHEDULER.h"

void lab_10_adc(void)
{
	u16 val;
	u8 str_val[5]={0};

	LCD_init();
	ADC_enInterrupt();
	GI_en();
	ADC_init();

	while(1)
	{
		ADC_startConversion(ADC_ch0);
		val = ADC_getVoltage_mv(ADC_ch0);
		itoa(val,str_val,10);
		str_val[4]='\0';
		LCD_writeString(str_val,0,0);
	}

}
