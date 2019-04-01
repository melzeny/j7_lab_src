/*
 * LAB_12_SPI.c
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/SPI/SPI.h"
#include "../HAL/LCD/LCD.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../SCHEDULER/SCHEDULER.h"
#include "avr/delay.h"

#define SPI_Comm_periodicity_ms			1000
#define SPI_Read_periodicity_ms			900

void SPI_Comm_Task(void)
{
	static u8 MsgNumber =0;
	switch(MsgNumber)
	{
	case 0:
		if(SPI_startComm((u8*)"HowAreYouSlave",(u8)15) == OK)
			MsgNumber++;
		break;
	case 1:
		if(SPI_startComm((u8*)"I'mTheMaster",(u8)13) == OK)
			MsgNumber++;
		break;
	case 2:
		if(SPI_startComm((u8*)"ICan'tSeeYou",(u8)13) == OK)
			MsgNumber++;
		break;
	case 3:
		if(SPI_startComm((u8*)"ICanHearYou",(u8)12) == OK)
			MsgNumber++;
		break;
	default:
		if(SPI_startComm((u8*)"Good Bye",(u8)9) == OK)
			MsgNumber=0;
		break;
	}
}

void lab_12_spi_master(void)
{
	static u8 str_RxMsg[32];
	static u8 RxMsgSize =0 ;

	LCD_init();
	SPI_init();

	SCHEDULER_createTask(SPI_Comm_Task,SPI_Read_periodicity_ms,0);
	SCHEDULER_init();

	SPI_enInterrupt();
	GI_en();

	while(1)
	{
		LCD_writeCmd(LCD_CMD_CLEAR);
		_delay_ms(2);
		SPI_ReadMsg(str_RxMsg,&RxMsgSize);
		str_RxMsg[RxMsgSize] = '\0';
		LCD_writeString(str_RxMsg,0,0);
		_delay_ms(SPI_Read_periodicity_ms);
	}
}
