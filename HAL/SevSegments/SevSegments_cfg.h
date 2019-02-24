/*
 * SevSegments_cfg.h
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_CFG_H_
#define J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_CFG_H_

/* choose from DIO pins*/

#define SevSegmnets_PIN_A			DIO_pin_A0
#define SevSegmnets_PIN_B			DIO_pin_A1
#define SevSegmnets_PIN_C			DIO_pin_A2
#define SevSegmnets_PIN_D           DIO_pin_A3
#define SevSegmnets_PIN_E           DIO_pin_A4
#define SevSegmnets_PIN_F           DIO_pin_A5
#define SevSegmnets_PIN_G           DIO_pin_A6
#define SevSegmnets_PIN_DP          DIO_pin_A7
#define SevSegmnets_PIN_COMMON      DIO_pin_B0



/*
 * choose between
 * SevSegments_COMMON_CATHODE
 * SevSegments_COMMON_ANOD
 */
#define SevSegments_COMMON_TYPE		SevSegments_COMMON_CATHODE

#endif /* J7_LAB_SRC_HAL_SEVSEGMENTS_SEVSEGMENTS_CFG_H_ */
