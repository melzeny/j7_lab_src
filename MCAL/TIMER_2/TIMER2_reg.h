/*
 * TIMER2_reg.h
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef TIMER2_REG_H_
#define TIMER2_REG_H_

#define TCCR2			*((volatile u8*)0x45)
#define TCNT2			*((volatile u8*)0x44)
#define OCR2			*((volatile u8*)0x43)
#define TIMSK			*((volatile u8*)0x59)
#define TIFR			*((volatile u8*)0x58)

#endif /* TIMER2_REG_H_ */
