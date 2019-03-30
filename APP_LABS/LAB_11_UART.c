/*
 * LAB_11_UART.c
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <avr/delay.h>
#include "../MCAL/UART/UART.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../MCAL/DIO/DIO.h"
void lab_11_uart(void)
{
	u8 str_RxMsg[15];
	u8 RxMsgSize =0 ;

	DIO_init();
	LCD_init();
	UART_init();

	GI_en();
	UART_enInterrupt(UART_Receive_Complete);

	while(1)
	{
		UART_sendMsg("Amit_j7",8);
		_delay_ms(500);
		UART_ReadMsg(str_RxMsg,&RxMsgSize);
		LCD_writeString(str_RxMsg,0,0);
		_delay_ms(500);

	}

}

