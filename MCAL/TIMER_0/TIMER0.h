/*
 * TIMER0.h
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#define TIMER0_CTC_ISR			void __vector_10 (void) __attribute__ ((signal,used));\
								void __vector_10 (void)
#define TIMER0_NORMAL_ISR		void __vector_11 (void) __attribute__ ((signal,used));\
								void __vector_11 (void)

void TIMER0_init(void);
void TIMER0_enInterrupt(void);
void TIMER0_diInterrupt(void);
void TIMER0_setCounterSteps(u8 StepsNo);
u8 TIMER0_getCurrentCounterSteps(void);
void TIMER0_setComparedValue(u8 ComparedValue);

#endif /* TIMER0_H_ */
