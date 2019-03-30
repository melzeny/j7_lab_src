/*
 * SPI.h
 *
 *  Created on: Mar 30, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_SPI_SPI_H_
#define J7_LAB_SRC_MCAL_SPI_SPI_H_

#include "../../LIB/STD_TYPES.h"

void SPI_init(void);
void SPI_enInterrupt(void);
void SPI_diInterrupt(void);
u8 SPI_startComm(u8 TxMsg);

#endif /* J7_LAB_SRC_MCAL_SPI_SPI_H_ */
