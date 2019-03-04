/*
 * LAB_01_DIO.c
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO.h"

#define LED_0_PIN	DIO_pin_D5
#define SW_0_PIN	DIO_pin_D0


void lab_0_dio(void)
{

	DIO_pin_value_t prevStatus = DIO_pin_value_low
			,currentStatus=DIO_pin_value_low;

	DIO_init();

	while(1)
	{
		currentStatus = DIO_readPinValue(SW_0_PIN);
		if(currentStatus == DIO_pin_value_high)
		{
			if(prevStatus != currentStatus)
			{
				DIO_togglePin(LED_0_PIN);
			}
		}
		prevStatus = currentStatus;

	}


}

