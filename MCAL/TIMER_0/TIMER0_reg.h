/*
 * TIMER0_reg.h
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

#define TCCR0			*((volatile u8*)0x53)
#define TCNT0			*((volatile u8*)0x52)
#define OCR0			*((volatile u8*)0x5C)
#define TIMSK			*((volatile u8*)0x59)
#define TIFR			*((volatile u8*)0x58)

#endif /* TIMER0_REG_H_ */
