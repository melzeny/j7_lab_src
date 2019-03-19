/*
 * TIMER2_cfg.h
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TIMER2_CFG_H_
#define TIMER2_CFG_H_

/*
 * write number of steps to count in range [0-255]
 *
 * */
#define TIMER2_NO_OF_STEPS					(u8)0
/*
 * choose between
 * TIMER2_MODE_NORMAL_MSK
 * TIMER2_MODE_CTC_MSK
 */
#define TIMER2_MODE_SELECTOR_MSK			TIMER2_MODE_NORMAL_MSK

/*
 * choose between
 *
 * TIMER2_PRESCALER_NO_MSK
 * TIMER2_PRESCALER_8_MSK
 * TIMER2_PRESCALER_64_MSK
 * TIMER2_PRESCALER_256_MSK
 * TIMER2_PRESCALER_1024_MSK
 *
 * */

#define TIMER2_PRESCALER_SELECTOR_MSK  TIMER2_PRESCALER_64_MSK
/*
 * Choose between
 * TIMER2_OUTPUT_NONE_MSK
 * TIMER2_OUTPUT_TOGGLE_MSK
 * TIMER2_OUTPUT_SET_MSK
 * TIMER2_OUTPUT_CLEAR_MSK
 * */
#define TIMER2_OC0_PIN_OUTPUT_MSK		TIMER2_OUTPUT_TOGGLE_MSK

#endif /* TIMER2_CFG_H_ */
