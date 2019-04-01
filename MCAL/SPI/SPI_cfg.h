/*
 * SPI_cfg.h
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_SPI_SPI_CFG_H_
#define J7_LAB_SRC_MCAL_SPI_SPI_CFG_H_

/*
 * Choose SPI MODE
 * SPI_MODE_MASTER				1
 * SPI_MODE_SLAVE				0
 * */
#define SPI_MODE_SELECTOR				SPI_MODE_MASTER
/*
 * Clock polarity configuration
 * SPI_LEADING_EDGE_RISING_msk
 * SPI_LEADING_EDGE_FALLING_msk
 * */
#define SPI_LEADING_EDGE_SELECTOR_msk 	SPI_LEADING_EDGE_RISING_msk
/*
 * Choose action on lead
 * SPI_LEADING_EDGE_SAMPLE_msk
 * SPI_LEADING_EDGE_SETUP_msk
 * */
#define SPI_LEADING_EDGE_OP_msk			SPI_LEADING_EDGE_SAMPLE_msk

#define SPI_RX_BUFFER_SIZE				100
#define SPI_TX_BUFFER_SIZE				100
/*=================================================
 *
 * MASTER CONFIGURATION
 =================================================*/

#if SPI_MODE_SELECTOR == SPI_MODE_MASTER
/*
 * prescaler configuration
 * SPI_PRESCALER_4_msk
 * SPI_PRESCALER_16_msk
 * SPI_PRESCALER_64_msk
 * SPI_PRESCALER_128_msk
 * */
#define SPI_PRESCALER_SELECTOR_msk		SPI_PRESCALER_128_msk

/*
 * Choose Double speed mode
 * ENABLE
 * DISABLE
 * */
#define SPI_DOUBLE_SPEED_MODE			DISABLE
#endif

#endif /* J7_LAB_SRC_MCAL_SPI_SPI_CFG_H_ */
