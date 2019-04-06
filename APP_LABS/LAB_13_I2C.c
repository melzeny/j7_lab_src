/*
 * LAB_13_I2C.c
 *
 *  Created on: Apr 6, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/TWI/TWI.h"
#include <avr/delay.h>
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
void lab_13_i2c(void)
{
	u8 arr[5]= {0x00,0x04,0x1,0x2,0x3};
	TWI_init();
	GI_en();
	while(1)
	{
		TWI_sendMsg(0b10100000,arr,5);
		_delay_ms(1000);
	}


}
