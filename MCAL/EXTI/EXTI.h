/*
 * EXTI.h
 *
 *  Created on: Mar 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_EXTI_EXTI_H_
#define J7_LAB_SRC_MCAL_EXTI_EXTI_H_

typedef enum
{
	EXTI_int0,
	EXTI_int1,
	EXTI_int2
}EXTI_num_t;

void EXTI_init(EXTI_num_t ExtiNum );
void EXTI_enInterrupt(EXTI_num_t ExtiNum);
void EXTI_diInterrupt(EXTI_num_t ExtiNum);

#define EXTI_ISR	void __vector_1 (void) __attribute__ ((signal,used));\
					void __vector_1 (void)

#endif /* J7_LAB_SRC_MCAL_EXTI_EXTI_H_ */
