/*
 * LCD.c
 *
 *  Created on: Mar 8, 2019
 *      Author: Muhammad.Elzeiny
 */
#define  LCD_MODE_4_PIN		1
#define  LCD_MODE_8_PIN		2
#include <avr/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"

#include "LCD_cfg.h"
#include "LCD.h"

void LCD_init(void)
{
	/*Dio init*/
	DIO_init();
	/*delay 15 ms after power-up*/
	_delay_ms(15);

#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN
	/*Write sequence init cmd
	 *
	 * 0x38	(100 us)
	 * 0x0E	(100 us)
	 * 0x01	(2ms)
	 * */
	LCD_writeCmd(0x38);
	_delay_us(100);
	LCD_writeCmd(0x0E);
	_delay_us(100);
	LCD_writeCmd(0x01);
	_delay_ms(2);
#elif LCD_MODE_SELECTOR	== LCD_MODE_4_PIN

	LCD_writeCmd(0x33);
	_delay_us(100);
	LCD_writeCmd(0x32);
	_delay_us(100);
	LCD_writeCmd(0x28);
	_delay_ms(2);

#else
#warning FAULT IN LCD CONFIGURATION
#endif

}
void LCD_writeChar(u8 Data)
{

	/*RW = low*/
	DIO_writePinValue(LCD_PIN_RW,DIO_pin_value_low);

	/*RS = HIGH*/
	DIO_writePinValue(LCD_PIN_RS,DIO_pin_value_high);

	/*write on data pins*/
	DIO_writePinValue(LCD_PIN_D0,GET_BIT(Data,0));
	DIO_writePinValue(LCD_PIN_D1,GET_BIT(Data,1));
	DIO_writePinValue(LCD_PIN_D2,GET_BIT(Data,2));
	DIO_writePinValue(LCD_PIN_D3,GET_BIT(Data,3));
	DIO_writePinValue(LCD_PIN_D4,GET_BIT(Data,4));
	DIO_writePinValue(LCD_PIN_D5,GET_BIT(Data,5));
	DIO_writePinValue(LCD_PIN_D6,GET_BIT(Data,6));
	DIO_writePinValue(LCD_PIN_D7,GET_BIT(Data,7));

	/*Enable pulse (>= 450ns) */
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_high);
	_delay_us(0.450);
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_low);

}
void LCD_writeCmd(u8 Cmd)
{
	/*RW = low*/
	DIO_writePinValue(LCD_PIN_RW,DIO_pin_value_low);

	/*RS = LOW*/
	DIO_writePinValue(LCD_PIN_RS,DIO_pin_value_low);

	/*write on data pins*/
	DIO_writePinValue(LCD_PIN_D0,GET_BIT(Cmd,0));
	DIO_writePinValue(LCD_PIN_D1,GET_BIT(Cmd,1));
	DIO_writePinValue(LCD_PIN_D2,GET_BIT(Cmd,2));
	DIO_writePinValue(LCD_PIN_D3,GET_BIT(Cmd,3));
	DIO_writePinValue(LCD_PIN_D4,GET_BIT(Cmd,4));
	DIO_writePinValue(LCD_PIN_D5,GET_BIT(Cmd,5));
	DIO_writePinValue(LCD_PIN_D6,GET_BIT(Cmd,6));
	DIO_writePinValue(LCD_PIN_D7,GET_BIT(Cmd,7));

	/*Enable pulse (>= 450ns) */
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_high);
	_delay_us(0.450);
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_low);

}

void LCD_writeString(u8 * str)
{
	u8 i =0;
	while(str[i] != '\0')
	{
		LCD_writeChar(str[i]);

		i++;
	}
}




