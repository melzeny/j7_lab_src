/*
 * LAB_02_SevSegments.c
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../../j7_lab_src/HAL/SevSegments/SevSegments.h"

void lab_02_SevSegments(void)
{
	SevSegments_init();
	SevSegments_enable();
	SevSegments_displayNum(5);

	while(1);


}

