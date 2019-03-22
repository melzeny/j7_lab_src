/*
 * SCHEDULER.h
 *
 *  Created on: Mar 16, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_SCHEDULER_SCHEDULER_H_
#define J7_LAB_SRC_SCHEDULER_SCHEDULER_H_

#include "../LIB/STD_TYPES.h"

void SCHEDULER_init(void);
ret_status_t SCHEDULER_createTask(p2func_t ptr2task,u32 periodicity,u32 FirstDelay);


#endif /* J7_LAB_SRC_SCHEDULER_SCHEDULER_H_ */
