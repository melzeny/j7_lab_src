/*
 * ULS_cfg.h
 *
 *  Created on: Mar 18, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_HAL_ULS_ULS_CFG_H_
#define J7_LAB_SRC_HAL_ULS_ULS_CFG_H_

/*
 * task periodicity configuration
 * Note:  use over 60ms measurement cycle,
 * in order to prevent trigger signal to the echo signal
 * */
#define ULS_TASK_PERIODICITY		20


#define ULS_TRIGGER_PIN				DIO_pin_D0


/* ECHO pin configuration
 * Choose between
 * EXTI_int0
 * EXTI_int1
 * EXTI_int2
 */
#define ULS_ECHO_EXTI_PIN			EXTI_int1

/* ultrasonic timer ISR configuration
 * choose between
 * TIMER2_CTC_ISR
 * TIMER2_NORMAL_ISR
 * BE_AWARE_OF: this configuration should be identical to timer2
 * */
#define ULS_TIMER_ISR				TIMER2_NORMAL_ISR

/*
 * Be Aware: the following configuration
 *  should be identical to timer2
 *  */
#define ULS_STEP_TIME_us			(u8)4

#endif /* J7_LAB_SRC_HAL_ULS_ULS_CFG_H_ */
