/*
 * DIO_reg.h
 *
 *  Created on: Feb 16, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_DIO_DIO_REG_H_
#define J7_LAB_SRC_MCAL_DIO_DIO_REG_H_

#define DDRA				*((volatile u8*)0x3A)
#define PORTA				*((volatile u8*)0x3B)
#define PINA				*((const volatile u8*)0x39)

#define DDRB 				 *((volatile u8*)0x37)
#define PORTB                *((volatile u8*)0x38)
#define PINB                 *((const volatile u8*)0x36)

#define DDRC                 *((volatile u8*)0x34)
#define PORTC                *((volatile u8*)0x35)
#define PINC                 *((const volatile u8*)0x33)

#define DDRD                 *((volatile u8*)0x31)
#define PORTD                *((volatile u8*)0x32)
#define PIND                 *((const volatile u8*)0x30)

#endif /* J7_LAB_SRC_MCAL_DIO_DIO_REG_H_ */
