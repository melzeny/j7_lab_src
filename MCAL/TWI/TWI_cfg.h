/*
 * TWI_cfg.h
 *
 *  Created on: Apr 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_TWI_TWI_CFG_H_
#define J7_LAB_SRC_MCAL_TWI_TWI_CFG_H_

#define TWI_BITRATE_TWBR_VAL			100
/*
 * TWI_PRESCALER_1_msk
 * TWI_PRESCALER_4_msk
 * TWI_PRESCALER_16_msk
 * TWI_PRESCALER_64_msk
 * */
#define TWI_PRESCALER_SELECTOR_msk		TWI_PRESCALER_1_msk

/*select address in range [1-127]*/
#define TWI_NODE_ADDRESS				0x55

#define TWI_BROADCAST_EN				ENABLE
#endif /* J7_LAB_SRC_MCAL_TWI_TWI_CFG_H_ */
