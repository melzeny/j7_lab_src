/*
 * SPI.c
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */
#define SPI_LEADING_EDGE_clr_msk			0b11110111
#define SPI_LEADING_EDGE_RISING_msk 		0b00000000
#define SPI_LEADING_EDGE_FALLING_msk		0b00001000

#define SPI_PRESCALER_clr_msk				0b11111100
#define SPI_PRESCALER_4_msk                 0b00000000
#define SPI_PRESCALER_16_msk                0b00000001
#define SPI_PRESCALER_64_msk                0b00000010
#define SPI_PRESCALER_128_msk               0b00000011

#define SPI_LEADING_EDGE_OP_clr_msk			0b11111011
#define SPI_LEADING_EDGE_SAMPLE_msk         0b00000000
#define SPI_LEADING_EDGE_SETUP_msk          0b00000100

#define SPI_MODE_MASTER				1
#define SPI_MODE_SLAVE				0

#include "../DIO/DIO.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_reg.h"
#include "SPI_cfg.h"
#include "SPI.h"

static u8 SPI_Rx_Buffer[SPI_RX_BUFFER_SIZE] = {0},
SPI_Rx_Msg_Length = 0,
SPI_Tx_Buffer[SPI_TX_BUFFER_SIZE] ={0},
SPI_Tx_Msg_Length = 0,SPI_Tx_Msg_index = 0;

void SPI_init(void)
{
	/*init cfg*/

	/* edge type leading */
	SPCR &= SPI_LEADING_EDGE_clr_msk;
	SPCR |= SPI_LEADING_EDGE_SELECTOR_msk;

	SPCR &= SPI_LEADING_EDGE_OP_clr_msk;
	SPCR |= SPI_LEADING_EDGE_OP_msk;

	/*choose master\slave*/
	ASSIGN_BIT(SPCR,4,SPI_MODE_SELECTOR);

	/*init master clock cfg*/
#if SPI_MODE_SELECTOR == SPI_MODE_MASTER
	SPCR &= SPI_PRESCALER_clr_msk;
	SPCR |= SPI_PRESCALER_SELECTOR_msk;

	ASSIGN_BIT(SPSR,0,SPI_DOUBLE_SPEED_MODE);
#endif

	/*enable SPI*/
	SET_BIT(SPCR,6);
}
void SPI_enInterrupt(void)
{
	SET_BIT(SPCR,7);
}
void SPI_diInterrupt(void)
{
	CLR_BIT(SPCR,7);
}
ret_status_t SPI_startComm(u8 TxMsg)
{
	SPDR = TxMsg;
	return OK;
}
void SPI_ReadMsg(u8 RxMsg[],u8* SizePtr)
{
	u8 i;
	for(i=0;i<SPI_Rx_Msg_Length;i++)
	{
		RxMsg[i] = SPI_Rx_Buffer[i];
	}
	* SizePtr = SPI_Rx_Msg_Length;
	SPI_Rx_Msg_Length = 0;
}

void __vector_12(void) __attribute__((signal,used));
void __vector_12(void)
{
	SPI_Rx_Buffer[SPI_Rx_Msg_Length++] = SPDR;
	DIO_togglePin(DIO_pin_D7);

}

