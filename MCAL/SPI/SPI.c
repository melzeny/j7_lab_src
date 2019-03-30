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

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_reg.h"
#include "SPI_cfg.h"
#include "SPI.h"

void SPI_init(void)
{
	/*init cfg*/

	/* edge type leading */
	SPCR &= SPI_LEADING_EDGE_clr_msk;
	SPCR |= SPI_LEADING_EDGE_SELECTOR_msk;

	SPCR &= SPI_PRESCALER_clr_msk;
	SPCR |= SPI_PRESCALER_SELECTOR_msk;

	ASSIGN_BIT(SPSR,0,SPI_DOUBLE_SPEED_MODE);

	SPCR &= SPI_LEADING_EDGE_OP_clr_msk;
	SPCR |= SPI_LEADING_EDGE_OP_msk;

	/*choose master\slave*/
	ASSIGN_BIT(SPCR,4,SPI_MODE_SELECTOR);

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
u8 SPI_startComm(u8 TxMsg)
{
	SPDR = TxMsg;
	/*wait until transmission is complete*/
	while(GET_BIT(SPSR,7) == 0);
	SET_BIT(SPSR,7);
	return SPDR;
}
