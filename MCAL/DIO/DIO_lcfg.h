/*
 * DIO_lcfg.h
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_DIO_DIO_LCFG_H_
#define J7_LAB_SRC_MCAL_DIO_DIO_LCFG_H_

typedef struct
{
	u8 pin_A0_dir:1;
	u8 pin_A1_dir:1;
	u8 pin_A2_dir:1;
	u8 pin_A3_dir:1;
	u8 pin_A4_dir:1;
	u8 pin_A5_dir:1;
	u8 pin_A6_dir:1;
	u8 pin_A7_dir:1;

	u8 pin_B0_dir:1;
	u8 pin_B1_dir:1;
	u8 pin_B2_dir:1;
	u8 pin_B3_dir:1;
	u8 pin_B4_dir:1;
	u8 pin_B5_dir:1;
	u8 pin_B6_dir:1;
	u8 pin_B7_dir:1;

	u8 pin_C0_dir:1;
	u8 pin_C1_dir:1;
	u8 pin_C2_dir:1;
	u8 pin_C3_dir:1;
	u8 pin_C4_dir:1;
	u8 pin_C5_dir:1;
	u8 pin_C6_dir:1;
	u8 pin_C7_dir:1;

	u8 pin_D0_dir:1;
	u8 pin_D1_dir:1;
	u8 pin_D2_dir:1;
	u8 pin_D3_dir:1;
	u8 pin_D4_dir:1;
	u8 pin_D5_dir:1;
	u8 pin_D6_dir:1;
	u8 pin_D7_dir:1;
}BF_pin_dir_t;
typedef union
{
	BF_pin_dir_t bit;
	u8 byte[4];
}DIO_pin_dir_t;

extern const DIO_pin_dir_t DIO_pin_dir;

#endif /* J7_LAB_SRC_MCAL_DIO_DIO_LCFG_H_ */
