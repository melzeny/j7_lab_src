
/*
 * SevSegments.c
 *
 *  Created on: Feb 23, 2019
 *      Author: NORAN
 */
#define SevSegments_COMMON_CATHODE			0
#define SevSegments_COMMON_ANOD				1

#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "BcdSevSegments_cfg.h"
#include "BcdSevSegments.h"

void BcdSevSegments_init(void)
{
	DIO_init();
}
void BcdSevSegments_displayNum(u8 num)
{
	if(num<16)
	{
		DIO_writePinValue(BcdSevSegmnets_PIN_A,GET_BIT(num,0));
		DIO_writePinValue(BcdSevSegmnets_PIN_B,GET_BIT(num,1));
		DIO_writePinValue(BcdSevSegmnets_PIN_C,GET_BIT(num,2));
		DIO_writePinValue(BcdSevSegmnets_PIN_D,GET_BIT(num,3));
	}
	else
	{

	}
}
void BcdSevSegments_enable(BcdSevSegment_num_t SevSegmentNum)
{
	if(SevSegmentNum == BcdSevSegment_1)
	{
		DIO_writePinValue(BcdSevSegmnets_PIN_EN_1,DIO_pin_value_high);

	}
	else if (SevSegmentNum == BcdSevSegment_2)
	{
		DIO_writePinValue(BcdSevSegmnets_PIN_EN_2,DIO_pin_value_high);

	}
}
void BcdSevSegments_disable(BcdSevSegment_num_t SevSegmentNum)
{
	if(SevSegmentNum == BcdSevSegment_1)
	{
		DIO_writePinValue(BcdSevSegmnets_PIN_EN_1,DIO_pin_value_low);

	}
	else if (SevSegmentNum == BcdSevSegment_2)
	{
		DIO_writePinValue(BcdSevSegmnets_PIN_EN_2,DIO_pin_value_low);

	}
}
