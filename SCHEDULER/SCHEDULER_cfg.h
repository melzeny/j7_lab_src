/*
 * SCHEDULER_cfg.h
 *
 *  Created on: Mar 16, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_SCHEDULER_SCHEDULER_CFG_H_
#define J7_LAB_SRC_SCHEDULER_SCHEDULER_CFG_H_

#define SCHEDULER_MAX_NO_OF_TASKS				5

/*
 * Be Aware: the following configuration
 *  should be identical to timer0
 *  */
#define SCHEDULER_TIMER_STEPS					78

/*
 * TIMER0_CTC_ISR
 * TIMER0_NORMAL_ISR
 */
#define SCHEDULER_TIMER_ISR				TIMER0_CTC_ISR
#endif /* J7_LAB_SRC_SCHEDULER_SCHEDULER_CFG_H_ */
