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
#define TIMER0_NO_OF_PETER_STEPS		(u8)78
/*
 * choose between
 * TIMER0_MODE_NORMAL_MSK
 * TIMER0_MODE_CTC_MSK
 */
#define TIMER0_MODE_SELECTOR_MSK			TIMER0_MODE_CTC_MSK

/*
 * choose between
 *
 * TIMER0_PRESCALER_NO_MSK
 * TIMER0_PRESCALER_8_MSK
 * TIMER0_PRESCALER_64_MSK
 * TIMER0_PRESCALER_256_MSK
 * TIMER0_PRESCALER_1024_MSK
 *
 * */

#define TIMER0_PRESCALER_SELECTOR_MSK  TIMER0_PRESCALER_1024_MSK
/*
 * Choose between
 * TIMER0_OUTPUT_NONE_MSK
 * TIMER0_OUTPUT_TOGGLE_MSK
 * TIMER0_OUTPUT_SET_MSK
 * TIMER0_OUTPUT_CLEAR_MSK
 * */
#define TIMER0_OC0_PIN_OUTPUT_MSK		TIMER0_OUTPUT_NONE_MSK

#endif /* TIMER0_CFG_H_ */
