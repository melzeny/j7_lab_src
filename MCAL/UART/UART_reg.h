/*
 * UART_reg.h
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_UART_UART_REG_H_
#define J7_LAB_SRC_MCAL_UART_UART_REG_H_


#define UBRRL           *((volatile u8*)0x29)
#define UBRRH           *((volatile u8*)0x40)
#define UCSRC           *((volatile u8*)0x40)
#define UCSRB           *((volatile u8*)0x2A)
#define UCSRA			*((volatile u8*)0x2B)
#define UDR				*((volatile u8*)0x2C)

#endif /* J7_LAB_SRC_MCAL_UART_UART_REG_H_ */
