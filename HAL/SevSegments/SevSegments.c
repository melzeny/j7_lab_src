
/*
 * SevSegments.c
 *
 *  Created on: Feb 23, 2019
 *      Author: NORAN
 */
#define SevSegments_COMMON_CATHODE			0
#define SevSegments_COMMON_ANOD				1

#include "../../../j7_lab_src/MCAL/DIO/DIO.h"
#include "../../../j7_lab_src/HAL/SevSegments/SevSegments_cfg.h"
#include "../../../j7_lab_src/HAL/SevSegments/SevSegments.h"


#define SEGMENT_ACTIVE_VALUE_1			!SevSegments_COMMON_TYPE_1
#define	SEGMENT_DEACTIVE_VALUE_1		SevSegments_COMMON_TYPE_1

#define SEGMENT_ACTIVE_VALUE_2			!SevSegments_COMMON_TYPE_2
#define	SEGMENT_DEACTIVE_VALUE_2		SevSegments_COMMON_TYPE_2

void SevSegments_init(void)
{
	DIO_init();
}
void SevSegments_displayNum(SevSegment_num_t SevSegmentNum,u8 num)
{
	switch(num)
	{
	case 0:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_DEACTIVE_VALUE_1);
		break;

	case 1:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_DEACTIVE_VALUE_1);
		break;

	case 2:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE_1);
		break;

	case 3:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE_1);
		break;

	case 4:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE_1);
		break;

	case 5:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE_1);
		break;

	case 6:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE_1);
		break;

	case 7:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_DEACTIVE_VALUE_1);
		break;

	case 8:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE_1);
		break;

	case 9:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE_1);
		break;
	default:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE_1);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE_1);
		break;
	}
}
void SevSegments_enable(SevSegment_num_t SevSegmentNum)
{
	if(SevSegmentNum == SevSegment_1)
	{
#if (SevSegments_COMMON_TYPE_1	== SevSegments_COMMON_CATHODE)
		DIO_writePinValue(SevSegmnets_PIN_COMMON_1,DIO_pin_value_low);

#elif (SevSegments_COMMON_TYPE_1	== SevSegments_COMMON_ANOD)
		DIO_writePinValue(SevSegmnets_PIN_COMMON_1,DIO_pin_value_high);

#endif
	}
	else if(SevSegmentNum == SevSegment_2)
	{
#if (SevSegments_COMMON_TYPE_2	== SevSegments_COMMON_CATHODE)
		DIO_writePinValue(SevSegmnets_PIN_COMMON_2,DIO_pin_value_low);

#elif (SevSegments_COMMON_TYPE_2	== SevSegments_COMMON_ANOD)
		DIO_writePinValue(SevSegmnets_PIN_COMMON_2,DIO_pin_value_high);

#endif
	}

}
void SevSegments_disable(SevSegment_num_t SevSegmentNum)
{
#if (SevSegments_COMMON_TYPE_1	== SevSegments_COMMON_CATHODE)
	DIO_writePinValue(SevSegmnets_PIN_COMMON_1,DIO_pin_value_high);

#elif (SevSegments_COMMON_TYPE_1	== SevSegments_COMMON_ANOD)
	DIO_writePinValue(SevSegmnets_PIN_COMMON_1,DIO_pin_value_low);

#endif


}
