/*
 * LAB_03_KP.c
 *
 *  Created on: Mar 3, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/DIO/DIO.h"
#include "../HAL/KP/KP.h"
#include "../HAL/SevSegments/SevSegments.h"

#include <avr/delay.h>
void lab_03_kp(void)
{
	volatile u8 PressedNum =-1;
	SevSegments_init();
	KP_init();

	while(1)
	{
		PressedNum = KP_getPressedButton();
		if(PressedNum != (u8)-1)
		{

			SevSegments_enable(SevSegment_1);
			SevSegments_displayNum(SevSegment_1,PressedNum%10);
			_delay_ms(5);
			SevSegments_disable(SevSegment_1);


			SevSegments_enable(SevSegment_2);
			SevSegments_displayNum(SevSegment_2,PressedNum/10);
			_delay_ms(5);
			SevSegments_disable(SevSegment_2);
		}

	}
}



