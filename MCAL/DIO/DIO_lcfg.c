/*
 * DIO_lcfg.c
 *
 *  Created on: Mar 15, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../LIB/STD_TYPES.h"

#define DIO_PIN_INPUT			0
#define DIO_PIN_OUTPUT			1

#include "DIO_lcfg.h"

const DIO_pin_dir_t DIO_pin_dir =
{
		{
				/* PIN_A0_DIR */ DIO_PIN_INPUT,
				/* PIN_A1_DIR */ DIO_PIN_INPUT,
				/* PIN_A2_DIR */ DIO_PIN_INPUT,
				/* PIN_A3_DIR */ DIO_PIN_INPUT,
				/* PIN_A4_DIR */ DIO_PIN_INPUT,
				/* PIN_A5_DIR */ DIO_PIN_INPUT,
				/* PIN_A6_DIR */ DIO_PIN_INPUT,
				/* PIN_A7_DIR */ DIO_PIN_INPUT,

				/* PIN_B0_DIR */ DIO_PIN_INPUT,
				/* PIN_B1_DIR */ DIO_PIN_INPUT,
				/* PIN_B2_DIR */ DIO_PIN_INPUT,
				/* PIN_B3_DIR */ DIO_PIN_INPUT,
				/* PIN_B4_DIR */ DIO_PIN_INPUT,
				/* PIN_B5_DIR */ DIO_PIN_INPUT,
				/* PIN_B6_DIR */ DIO_PIN_INPUT,
				/* PIN_B7_DIR */ DIO_PIN_INPUT,
                /*  */
				/* PIN_C0_DIR */ DIO_PIN_INPUT,
				/* PIN_C1_DIR */ DIO_PIN_INPUT,
				/* PIN_C2_DIR */ DIO_PIN_INPUT,
				/* PIN_C3_DIR */ DIO_PIN_INPUT,
				/* PIN_C4_DIR */ DIO_PIN_INPUT,
				/* PIN_C5_DIR */ DIO_PIN_INPUT,
				/* PIN_C6_DIR */ DIO_PIN_INPUT,
				/* PIN_C7_DIR */ DIO_PIN_INPUT,

				/* PIN_D0_DIR */ DIO_PIN_INPUT,
				/* PIN_D1_DIR */ DIO_PIN_INPUT,
				/* PIN_D2_DIR */ DIO_PIN_INPUT,
				/* PIN_D3_DIR */ DIO_PIN_INPUT,
				/* PIN_D4_DIR */ DIO_PIN_INPUT,
				/* PIN_D5_DIR */ DIO_PIN_INPUT,
				/* PIN_D6_DIR */ DIO_PIN_INPUT,
				/* PIN_D7_DIR */ DIO_PIN_OUTPUT,

		}
};
