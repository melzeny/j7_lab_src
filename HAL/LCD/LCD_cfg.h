/*
 * LCD_cfg.h
 *
 *  Created on: Mar 8, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_HAL_LCD_LCD_CFG_H_
#define J7_LAB_SRC_HAL_LCD_LCD_CFG_H_

/*
 * Please Choose between:
 * LCD_MODE_4_PIN
 * LCD_MODE_8_PIN
 */
#define LCD_MODE_SELECTOR	LCD_MODE_4_PIN


#define LCD_PIN_RS			DIO_pin_B1
#define LCD_PIN_RW			DIO_pin_B2
#define LCD_PIN_E			DIO_pin_B3



#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN
#define LCD_PIN_D0			DIO_pin_A0
#define LCD_PIN_D1			DIO_pin_A1
#define LCD_PIN_D2			DIO_pin_A2
#define LCD_PIN_D3			DIO_pin_A3
#endif

#define LCD_PIN_D4			DIO_pin_A4
#define LCD_PIN_D5			DIO_pin_A5
#define LCD_PIN_D6			DIO_pin_A6
#define LCD_PIN_D7			DIO_pin_A7



#endif /* J7_LAB_SRC_HAL_LCD_LCD_CFG_H_ */
