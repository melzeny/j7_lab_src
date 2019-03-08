/*
 * LCD.h
 *
 *  Created on: Feb 28, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_HAL_LCD_LCD_H_
#define J7_LAB_SRC_HAL_LCD_LCD_H_

#include "../../LIB/STD_TYPES.h"

/*Commands*/
#define LCD_CMD_CLEAR		(u8)0x01

/*APIs*/
void LCD_init(void);
void LCD_writeChar(u8 Data);
void LCD_writeCmd(u8 Cmd);
void LCD_writeString(u8 * str);

#endif /* J7_LAB_SRC_HAL_LCD_LCD_H_ */
