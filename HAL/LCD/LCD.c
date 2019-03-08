/*
 * LCD.c
 *
 *  Created on: Mar 8, 2019
 *      Author: Muhammad.Elzeiny
 */
#define  LCD_MODE_4_PIN		1
#define  LCD_MODE_8_PIN		2
#include <avr/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "LCD_cfg.h"
#include "LCD.h"

void LCD_init(void)
{
	/*delay 15 ms after power-up*/

	/*Write sequence init cmd
	 *
	 * 0x38	(100 us)
	 * 0x0E	(100 us)
	 * 0x01	(2ms)
	 * */


}
void LCD_writeChar(u8 Data)
{

	/*RW = low*/


	/*RS = HIGH*/

	/*write on data pins*/

	/*Enable pulse (>= 450ns) */


}
void LCD_writeCmd(u8 Cmd)
{
	/*RW = low*/

	/*RS = low*/

	/*write on data pins*/

	/*Enable pulse (>= 450ns) */

}




