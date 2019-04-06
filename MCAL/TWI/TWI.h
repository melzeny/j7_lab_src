/*
 * TWI.h
 *
 *  Created on: Apr 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_TWI_TWI_H_
#define J7_LAB_SRC_MCAL_TWI_TWI_H_

ret_status_t TWI_sendMsg(u8 SlaveAddress,u8 TxMsg[],u8 SizeCpy);
void TWI_init(void);
void TWI_startReading(u8 SlaveAddress, u8 SizeCpy);
ret_status_t TWI_getlastRxMsg(u8 RxMsg[],u8* SizePtr);

#endif /* J7_LAB_SRC_MCAL_TWI_TWI_H_ */
