/*
 * TIMER0_cfg.h
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

/*
 * write number of steps to count in range [0-255]
 *
 * */
#define TIMER0_NO_OF_PETER_STEPS		100
/*
 * choose between
 * TIMER0_MODE_NORMAL
 * TIMER0_MODE_CTC
 */
#define TIMER0_MODE_SELECTOR			TIMER0_MODE_NORMAL

/*
 * choose between
 *
 * TIMER0_PRESCALER_NO
 * TIMER0_PRESCALER_8
 * TIMER0_PRESCALER_64
 * TIMER0_PRESCALER_256
 * TIMER0_PRESCALER_1024
 *
 * */
#define TIMER0_PRESCALER_SELECTOR		TIMER0_PRESCALER_8

#if TIMER0_MODE_SELECTOR == TIMER0_MODE_CTC
/*
 * Choose between
 * TIMER0_OUTPUT_NONE
 * TIMER0_OUTPUT_TOGGLE
 * TIMER0_OUTPUT_SET
 * TIMER0_OUTPUT_CLEAR
 * */
#define TIMER0_COMPARE_MATCH_OUTPUT		TIMER0_OUTPUT_TOGGLE
#endif

#endif /* TIMER0_CFG_H_ */
