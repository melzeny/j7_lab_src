/*
 * LCD.c
 *
 *  Created on: Mar 8, 2019
 *      Author: Mohammed Mahdy - Mohammed Zharan -Mostafa Yasser Mahmoud
 */
#define  LCD_MODE_4_PIN		1
#define  LCD_MODE_8_PIN		2
#include <avr/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"

#include "LCD_cfg.h"
#include "LCD.h"

static void LCD_writeChar(u8 Data);

static u8 lastUsed_DDRAM_Address = 0;

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
#elif LCD_MODE_SELECTOR	== LCD_MODE_4_PIN

	LCD_writeCmd(0x33);
	_delay_us(100);
	LCD_writeCmd(0x32);
	_delay_us(100);
	LCD_writeCmd(0x28); /*init 5*7 matrix in 4-pin mode*/
	_delay_ms(2);

#else
#warning WRONG LCD CONFIGURATION
#endif
	LCD_writeCmd(LCD_CMD_DISPLAY_ON); /*display on*/
	_delay_us(100);
	LCD_writeCmd(LCD_CMD_CLEAR);	/*clear LCD */
	_delay_ms(2);

}
static void LCD_writeChar(u8 Data)
{

	/*RW = low*/
	DIO_writePinValue(LCD_PIN_RW,DIO_pin_value_low);

	/*RS = HIGH*/
	DIO_writePinValue(LCD_PIN_RS,DIO_pin_value_high);

	/*write on data pins*/
#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN
	DIO_writePinValue(LCD_PIN_D0,GET_BIT(Data,0));
	DIO_writePinValue(LCD_PIN_D1,GET_BIT(Data,1));
	DIO_writePinValue(LCD_PIN_D2,GET_BIT(Data,2));
	DIO_writePinValue(LCD_PIN_D3,GET_BIT(Data,3));
#endif
	DIO_writePinValue(LCD_PIN_D4,GET_BIT(Data,4));
	DIO_writePinValue(LCD_PIN_D5,GET_BIT(Data,5));
	DIO_writePinValue(LCD_PIN_D6,GET_BIT(Data,6));
	DIO_writePinValue(LCD_PIN_D7,GET_BIT(Data,7));

	/*Enable pulse (>= 450ns) */
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_high);
	_delay_us(0.450);
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_low);
#if	LCD_MODE_SELECTOR == LCD_MODE_4_PIN
	DIO_writePinValue(LCD_PIN_D4,GET_BIT(Data,0));
	DIO_writePinValue(LCD_PIN_D5,GET_BIT(Data,1));
	DIO_writePinValue(LCD_PIN_D6,GET_BIT(Data,2));
	DIO_writePinValue(LCD_PIN_D7,GET_BIT(Data,3));

	/*Enable pulse (>= 450ns) */
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_high);
	_delay_us(0.450);
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_low);

#endif

}
void LCD_writeCmd(u8 Cmd)
{
	/*RW = low*/
	DIO_writePinValue(LCD_PIN_RW,DIO_pin_value_low);

	/*RS = LOW*/
	DIO_writePinValue(LCD_PIN_RS,DIO_pin_value_low);

	/*write on data pins*/
#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN
	DIO_writePinValue(LCD_PIN_D0,GET_BIT(Cmd,0));
	DIO_writePinValue(LCD_PIN_D1,GET_BIT(Cmd,1));
	DIO_writePinValue(LCD_PIN_D2,GET_BIT(Cmd,2));
	DIO_writePinValue(LCD_PIN_D3,GET_BIT(Cmd,3));
#endif
	DIO_writePinValue(LCD_PIN_D4,GET_BIT(Cmd,4));
	DIO_writePinValue(LCD_PIN_D5,GET_BIT(Cmd,5));
	DIO_writePinValue(LCD_PIN_D6,GET_BIT(Cmd,6));
	DIO_writePinValue(LCD_PIN_D7,GET_BIT(Cmd,7));

	/*Enable pulse (>= 450ns) */
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_high);
	_delay_us(0.450);
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_low);
#if	LCD_MODE_SELECTOR == LCD_MODE_4_PIN
	DIO_writePinValue(LCD_PIN_D4,GET_BIT(Cmd,0));
	DIO_writePinValue(LCD_PIN_D5,GET_BIT(Cmd,1));
	DIO_writePinValue(LCD_PIN_D6,GET_BIT(Cmd,2));
	DIO_writePinValue(LCD_PIN_D7,GET_BIT(Cmd,3));

	/*Enable pulse (>= 450ns) */
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_high);
	_delay_us(0.450);
	DIO_writePinValue(LCD_PIN_E,DIO_pin_value_low);

#endif

}
/*=====================================
 * CGRAM_MatrixOffset [0-7]
 *
 *
 =====================================*/
void LCD_storeCustomChar(u8* CustomChar,u8 CGRAM_MatrixOffset)
{
	/*CMD: set CGRAM Addr
	 * AC point to CGRAM
	 * */

	/*DATA: write custom char*/


	/*
	 * make AC pointing to LastUsed_DDRAM_Address
	 * */


}
void LCD_displayCustomChar(u8 CGRAM_MatrixIndex)
{
	u8 addr = CGRAM_MatrixIndex * 8;

	LCD_writeChar(addr);

}
void LCD_writeString(u8 * str,u8 row,u8 col)
{
	u8 addr = (row*0x40) + col;

	LCD_writeCmd(0b10000000 | addr);
	u8 i =0;
	while(str[i] != '\0')
	{
		LCD_writeChar(str[i]);

		i++;
	}
	lastUsed_DDRAM_Address = addr + i;
}




