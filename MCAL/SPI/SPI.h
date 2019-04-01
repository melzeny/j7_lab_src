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
ret_status_t SPI_startComm(u8 TxMsg);
void SPI_ReadMsg(u8 RxMsg[],u8* SizePtr);

#endif /* J7_LAB_SRC_MCAL_SPI_SPI_H_ */
