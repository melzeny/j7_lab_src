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

static u8 Rx_Buffer[UART_RX_BUFFER_SIZE]={0};
static u8 Tx_Buffer[UART_TX_BUFFER_SIZE]={0};
static u8 Rx_msg_length = 0,Tx_msg_index=0,Tx_size;

void UART_init(void)
{
	/*init cfg*/

	/*access UCSRC*/
	SET_BIT(UCSRC,7);

	/* config length*/
	UCSRC &= UART_MSG_LENGTH_clr_msk;
	UCSRC |= UART_MSG_LENGTH_msk;

	/* config Parity*/
	UCSRC &= UART_PARITY_clr_msk;
	UCSRC |= UART_PARITY_MODE_msk;

	/*config stop bit*/
	UCSRC &= UART_STOP_BIT_MODE_clr_msk;
	UCSRC |= UART_STOP_BIT_MODE_msk;

	/*config baud rate*/
	UBRRL = UART_BAUD_RATE_UBRR_VAL;

	/*config double speed*/
	ASSIGN_BIT(UCSRA,1,UART_DOUBLE_SPEED);

	/*enable Tx*/
	SET_BIT(UCSRB,3);
	/*enable Rx*/
	SET_BIT(UCSRB,4);
}
void UART_enInterrupt(UART_interrupt_t InterruptSource)
{
	switch(InterruptSource)
	{
	case UART_Receive_Complete:
		SET_BIT(UCSRB,7);
		break;
	case UART_Transmission_Complete:
		SET_BIT(UCSRB,6);
		break;
	case UART_UDR_Ready:
		SET_BIT(UCSRB,5);
		break;
	}
}
void UART_diInterrupt(UART_interrupt_t InterruptSource)
{
	switch(InterruptSource)
	{
	case UART_Receive_Complete:
		CLR_BIT(UCSRB,7);
		break;
	case UART_Transmission_Complete:
		CLR_BIT(UCSRB,6);
		break;
	case UART_UDR_Ready:
		CLR_BIT(UCSRB,5);
		break;
	}
}
void UART_sendMsg(u8 TxMsg[],u8 SizeCpy)
{
	u8 i;
	Tx_size = SizeCpy;
	for(i=0; i<SizeCpy ;i++)
	{
		Tx_Buffer[i]= TxMsg[i];
	}
	UART_enInterrupt(UART_UDR_Ready);
}
void UART_ReadMsg(u8 RxMsg[],u8* SizePtr)
{
	u8 i;
	*SizePtr = Rx_msg_length;
	for(i=0;i<Rx_msg_length;i++)
	{
		RxMsg[i]= Rx_Buffer[i];
	}
	Rx_msg_length=0;
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
	if(Rx_msg_length < UART_RX_BUFFER_SIZE)
	{
		Rx_Buffer[Rx_msg_length] = UDR;
		Rx_msg_length++;
	}
	else
	{
		/*ignore messages*/
	}
}
/*UDR ready complete ISR*/
void __vector_14(void) __attribute__((signal,used));
void __vector_14(void)
{
	if( Tx_msg_index < Tx_size)
	{
		UDR = Tx_Buffer[Tx_msg_index];
		Tx_msg_index++;

	}
	else
	{
		Tx_msg_index = 0;
		Tx_size = 0;
		UART_diInterrupt(UART_UDR_Ready);
	}
}
