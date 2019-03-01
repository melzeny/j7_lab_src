/*
 * SevSegments.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_HAL_BCDSEVSEGMENTS_SEVSEGMENTS_H_
#define J7_LAB_SRC_HAL_BCDSEVSEGMENTS_SEVSEGMENTS_H_
#include "../../../j7_lab_src/LIB/STD_TYPES.h"

typedef enum
{
	SevSegment_1,
	SevSegment_2

}SevSegment_num_t;
void BcdSevSegments_init(void);
void BcdSevSegments_displayNum(u8 num);
void BcdSevSegments_enable(SevSegment_num_t SevSegmentNum);
void BcdSevSegments_disable(SevSegment_num_t SevSegmentNum);


#endif /* J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_H_ */
