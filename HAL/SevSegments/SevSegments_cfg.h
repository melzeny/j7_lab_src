/*
 * SevSegments_cfg.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_CFG_H_
#define J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_CFG_H_

/* choose from DIO pins*/

#define SevSegmnets_PIN_A			DIO_pin_C0
#define SevSegmnets_PIN_B			DIO_pin_C1
#define SevSegmnets_PIN_C			DIO_pin_C2
#define SevSegmnets_PIN_D           DIO_pin_C3
#define SevSegmnets_PIN_E           DIO_pin_C4
#define SevSegmnets_PIN_F           DIO_pin_C5
#define SevSegmnets_PIN_G           DIO_pin_C6
#define SevSegmnets_PIN_DP          DIO_pin_C7
#define SevSegmnets_PIN_COMMON_1    DIO_pin_D0
#define SevSegmnets_PIN_COMMON_2    DIO_pin_D1



/*
 * choose between
 * SevSegments_COMMON_CATHODE ==>0
 * SevSegments_COMMON_ANOD	  ==>1
 */
#define SevSegments_COMMON_TYPE_1		SevSegments_COMMON_CATHODE
#define SevSegments_COMMON_TYPE_2		SevSegments_COMMON_CATHODE

#endif /* J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_CFG_H_ */
