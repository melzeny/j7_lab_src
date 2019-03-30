/*
 * UART_cfg.h
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_UART_UART_CFG_H_
#define J7_LAB_SRC_MCAL_UART_UART_CFG_H_


/*
 * Configure MSG_LENGTH
 * UART_MSG_LENGTH_5_msk
 * UART_MSG_LENGTH_6_msk
 * UART_MSG_LENGTH_7_msk
 * UART_MSG_LENGTH_8_msk
 *
 * */
#define UART_MSG_LENGTH_msk		 		UART_MSG_LENGTH_8_msk

/*
 * Configure parity mode
 * UART_PARITY_DISABLE_msk
 * UART_PARITY_EVEN_msk
 * UART_PARITY_ODD_msk
 * */
#define UART_PARITY_MODE_msk			UART_PARITY_EVEN_msk
/*
 * configure stop bit
 * UART_STOP_BIT_1_msk
 * UART_STOP_BIT_2_msk
 * */
#define UART_STOP_BIT_MODE_msk			UART_STOP_BIT_1_msk

/*
 * refer to DATA sheet Table 70-71 Page 167-168
 * for baud rate = 9600
 * F_CPU 16MHz ==> UBRRL = 103
 * F_CPU 12MHz ==> UBRRL = 71
 * */
#define UART_BAUD_RATE_UBRR_VAL			103

/*
 * choose DOUBLE_SPEED_MODE
 * ENABLE     1
 * DISABLE    0
 * */
#define UART_DOUBLE_SPEED			DISABLE

#define UART_RX_BUFFER_SIZE			100
#define UART_TX_BUFFER_SIZE			100

#endif /* J7_LAB_SRC_MCAL_UART_UART_CFG_H_ */
