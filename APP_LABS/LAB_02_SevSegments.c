/*
 * LAB_02_SevSegments.c
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <avr/delay.h>
#include "../MCAL/DIO/DIO.h"
#include "../HAL/SevSegments/SevSegments.h"


void lab_02_SevSegments(void)
{
	SevSegments_init();

	while(1)
	{
			SevSegments_enable(SevSegment_1);
			SevSegments_displayNum(SevSegment_1,6);
			_delay_ms(5);
			SevSegments_disable(SevSegment_1);


			SevSegments_enable(SevSegment_2);
			SevSegments_displayNum(SevSegment_2,9);
			_delay_ms(5);
			SevSegments_disable(SevSegment_2);
	}
}

