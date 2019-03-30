/*
 * UART.c
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */
#define UART_MSG_LENGTH_clr_msk						0b11111001
#define UART_MSG_LENGTH_5_msk						0b00000000
#define UART_MSG_LENGTH_6_msk						0b00000010
#define UART_MSG_LENGTH_7_msk						0b00000100
#define UART_MSG_LENGTH_8_msk						0b00000110

#define UART_PARITY_clr_msk							0b11001111
#define UART_PARITY_DISABLE_msk						0b00000000
#define UART_PARITY_EVEN_msk   						0b00100000
#define UART_PARITY_ODD_msk    						0b00110000

#define UART_STOP_BIT_MODE_clr_msk					0b11110111
#define UART_STOP_BIT_1_msk			                0b00000000
#define UART_STOP_BIT_2_msk                         0b00001000

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_reg.h"
#include "UART_cfg.h"
#include "UART.h"

static u8 Rx_Buffer[100]={0};
static u8 Tx_Buffer[100]={0};

void UART_init(void)
{
	/*init cfg*/

	/*enable Tx*/

	/*enable Rx*/

}
void UART_enInterrupt(UART_interrupt_t interrupt)
{

}
void UART_diInterrupt(UART_interrupt_t interrupt)
{

}
void UART_sendMsg(u8 TxMsg[],u8 SizeCpy)
{

}
void UART_ReadMsg(u8 RxMsg[],u8* Size)
{

}

/*Tx complete ISR*/
void __vector_15(void) __attribute__((signal,used));
void __vector_15(void)
{

}
/*Rx complete ISR*/
void __vector_13(void) __attribute__((signal,used));
void __vector_13(void)
{

}
/*UDR ready complete ISR*/
void __vector_14(void) __attribute__((signal,used));
void __vector_14(void)
{

}
