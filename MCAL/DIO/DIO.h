/*
 * DIO.h
 *
 *  Created on: Feb 16, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_DIO_DIO_H_
#define J7_LAB_SRC_MCAL_DIO_DIO_H_

#include "../../LIB/STD_TYPES.h"

/*typedefs*/
typedef enum
{
	DIO_pin_value_low,
	DIO_pin_value_high
}DIO_pin_value_t;
typedef enum
{
	DIO_pin_A0,
	DIO_pin_A1,
	DIO_pin_A2,
	DIO_pin_A3,
	DIO_pin_A4,
	DIO_pin_A5,
	DIO_pin_A6,
	DIO_pin_A7,

	DIO_pin_B0,
	DIO_pin_B1,
	DIO_pin_B2,
	DIO_pin_B3,
	DIO_pin_B4,
	DIO_pin_B5,
	DIO_pin_B6,
	DIO_pin_B7,

	DIO_pin_C0,
	DIO_pin_C1,
	DIO_pin_C2,
	DIO_pin_C3,
	DIO_pin_C4,
	DIO_pin_C5,
	DIO_pin_C6,
	DIO_pin_C7,

	DIO_pin_D0,
	DIO_pin_D1,
	DIO_pin_D2,
	DIO_pin_D3,
	DIO_pin_D4,
	DIO_pin_D5,
	DIO_pin_D6,
	DIO_pin_D7,

}DIO_pin_num_t;
typedef enum
{
	DIO_port_A,
	DIO_port_B,
	DIO_port_C,
	DIO_port_D

}DIO_port_num_t;
/*functions prototypes*/
void DIO_init(void);
void DIO_writePinValue(DIO_pin_num_t PinNum,DIO_pin_value_t PinValue);
DIO_pin_value_t DIO_readPinValue(DIO_pin_num_t PinNum);
void DIO_writePortValue(DIO_port_num_t PortNum,u8 value);
u8 DIO_readPortValue(DIO_port_num_t PortNum);
void DIO_togglePin(DIO_pin_num_t PinNum);
#endif /* J7_LAB_SRC_MCAL_DIO_DIO_H_ */
