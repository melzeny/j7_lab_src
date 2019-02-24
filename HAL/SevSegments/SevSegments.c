
/*
 * SevSegments.c
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */
#define SevSegments_COMMON_CATHODE			100
#define SevSegments_COMMON_ANOD				101

#include "../../../j7_lab_src/MCAL/DIO/DIO.h"
#include "../../../j7_lab_src/HAL/SevSegments/SevSegments_cfg.h"
#include "../../../j7_lab_src/HAL/SevSegments/SevSegments.h"

#if (SevSegments_COMMON_TYPE	== SevSegments_COMMON_CATHODE)
#define SEGMENT_ACTIVE_VALUE			DIO_pin_value_high
#define SEGMENT_DEACTIVE_VALUE			DIO_pin_value_low
#elif (SevSegments_COMMON_TYPE	== SevSegments_COMMON_ANOD)
#define SEGMENT_ACTIVE_VALUE			DIO_pin_value_low
#define SEGMENT_DECTIVE_VALUE			DIO_pin_value_high
#endif

void SevSegments_init(void)
{
	DIO_init();
}
void SevSegments_displayNum(u8 num)
{
	switch(num)
	{
	case 0:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_DEACTIVE_VALUE);
		break;

	case 1:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_DEACTIVE_VALUE);
		break;

	case 2:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE);
		break;

	case 3:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE);
		break;

	case 4:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE);
		break;

	case 5:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE);
		break;

	case 6:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE);
		break;

	case 7:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_DEACTIVE_VALUE);
		break;

	case 8:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE);
		break;

	case 9:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_ACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE);
		break;
	default:
		DIO_writePinValue(SevSegmnets_PIN_A,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_B,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_C,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_D,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_E,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_F,SEGMENT_DEACTIVE_VALUE);
		DIO_writePinValue(SevSegmnets_PIN_G,SEGMENT_ACTIVE_VALUE);
		break;
	}
}
void SevSegments_enable(void)
{
#if (SevSegments_COMMON_TYPE	== SevSegments_COMMON_CATHODE)
	DIO_writePinValue(SevSegmnets_PIN_COMMON,DIO_pin_value_low);

#elif (SevSegments_COMMON_TYPE	== SevSegments_COMMON_ANOD)
	DIO_writePinValue(SevSegmnets_PIN_COMMON,DIO_pin_value_high);

#endif

}
void SevSegments_disable(void)
{
#if (SevSegments_COMMON_TYPE	== SevSegments_COMMON_CATHODE)
	DIO_writePinValue(SevSegmnets_PIN_COMMON,DIO_pin_value_high);

#elif (SevSegments_COMMON_TYPE	== SevSegments_COMMON_ANOD)
	DIO_writePinValue(SevSegmnets_PIN_COMMON,DIO_pin_value_low);

#endif


}
