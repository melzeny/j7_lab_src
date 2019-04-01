/*
 * LAB_12_SPI.c
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "avr/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/SPI/SPI.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../MCAL/SPI/SPI_reg.h"

#define TX_INTERVAL_ms			10
void lab_12_spi_master(void)
{
	u8 str_RxMsg[10];
	u8 RxMsgSize =0 ;

	LCD_init();
	SPI_init();

	SPI_enInterrupt();
	GI_en();
	while(1)
	{
		SPI_startComm('M');
		_delay_ms(TX_INTERVAL_ms);
		SPI_startComm('A');
		_delay_ms(TX_INTERVAL_ms);
		SPI_startComm('S');
		_delay_ms(TX_INTERVAL_ms);
		SPI_startComm('T');
		_delay_ms(TX_INTERVAL_ms);
		SPI_startComm('E');
		_delay_ms(TX_INTERVAL_ms);
		SPI_startComm('R');
		_delay_ms(TX_INTERVAL_ms);
		SPI_ReadMsg(str_RxMsg,&RxMsgSize);
		str_RxMsg[RxMsgSize] = '\0';
		LCD_writeString(str_RxMsg,0,0);
	}
}
