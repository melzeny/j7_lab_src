/*
 * TIMER0.h
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#if TIMER0_MODE_SELECTOR == TIMER0_MODE_CTC
#define TIMER0_ISR			void __vector_10 (void) __attribute__ ((signal,used));\
							void __vector_10 (void)
#elif TIMER0_MODE_SELECTOR == TIMER0_MODE_NORMAL
#define TIMER0_ISR			void __vector_11 (void) __attribute__ ((signal,used));\
							void __vector_11 (void)
#endif

void TIMER0_init(void);
void TIMER0_enInterrupt(void);
void TIMER0_diInterrupt(void);
void TIMER0_setNoOfSteps(void);
#endif /* TIMER0_H_ */
