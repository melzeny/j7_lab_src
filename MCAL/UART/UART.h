/*
 * UART.h
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_UART_UART_H_
#define J7_LAB_SRC_MCAL_UART_UART_H_

#include "../../LIB/STD_TYPES.h"

typedef enum
{
	UART_Transmission_Complete,
	UART_Receive_Complete,
	UART_UDR_Ready
}UART_interrupt_t;

void UART_init(void);
void UART_enInterrupt(UART_interrupt_t interrupt);
void UART_diInterrupt(UART_interrupt_t interrupt);
void UART_sendMsg(u8 Msg[],u8 SizeCpy);
void UART_ReadMsg(u8 Msg[],u8* Size);

#endif /* J7_LAB_SRC_MCAL_UART_UART_H_ */
