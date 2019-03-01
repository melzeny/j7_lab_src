/*
 * LAB_02_SevSegments.c
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../HAL/SevSegments/SevSegments.h"
#include "../../HAL/KP/KP.h"
#include <avr/delay.h>
void lab_02_SevSegments(void)
{
	u8 PressedNum =-1;
	SevSegments_init();
	KP_init();
	while(1)
	{
		PressedNum = KP_getPressedButton();
		if(PressedNum != -1)
		{
			SevSegments_enable(SevSegment_1);
			SevSegments_displayNum(SevSegment_1,PressedNum%10);
			_delay_ms(1);
			SevSegments_disable(SevSegment_1);

			SevSegments_enable(SevSegment_2);
			SevSegments_displayNum(SevSegment_2,PressedNum/10);
			_delay_ms(1);
			SevSegments_disable(SevSegment_2);
		}

	}


}

