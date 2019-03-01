/*
 * SevSegments.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_H_
#define J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_H_
#include "../../../j7_lab_src/LIB/STD_TYPES.h"

typedef enum
{
	SevSegment_1,
	SevSegment_2

}SevSegment_num_t;
void SevSegments_init(void);
void SevSegments_displayNum(u8 num);
void SevSegments_enable(SevSegment_num_t SevSegmentNum);
void SevSegments_disable(SevSegment_num_t SevSegmentNum);


#endif /* J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_H_ */
