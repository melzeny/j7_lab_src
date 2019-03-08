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

#define LCD_PIN_E			DIO_pin_D0
#define LCD_PIN_RW			DIO_pin_D1
#define LCD_PIN_RS			DIO_pin_D2

#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN
#define LCD_PIN_D0			DIO_pin_C0
#define LCD_PIN_D1			DIO_pin_C1
#define LCD_PIN_D2			DIO_pin_C2
#define LCD_PIN_D3			DIO_pin_C3
#endif

#define LCD_PIN_D4			DIO_pin_C4
#define LCD_PIN_D5			DIO_pin_C5
#define LCD_PIN_D6			DIO_pin_C6
#define LCD_PIN_D7			DIO_pin_C7



#endif /* J7_LAB_SRC_HAL_LCD_LCD_CFG_H_ */
