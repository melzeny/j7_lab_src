/*
 * TIMER2.h
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TIMER2_H_
#define TIMER2_H_

#define TIMER2_CTC_ISR			void __vector_4 (void) __attribute__ ((signal,used));\
								void __vector_4 (void)
#define TIMER2_NORMAL_ISR		void __vector_5 (void) __attribute__ ((signal,used));\
								void __vector_5 (void)

void TIMER2_init(void);
void TIMER2_enInterrupt(void);
void TIMER2_diInterrupt(void);
void TIMER2_setNoOfSteps(u8 StepsNo);
u8 TIMER2_getNoOfSteps(void);

#endif /* TIMER2_H_ */
