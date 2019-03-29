/*
 * ADC_reg.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_ADC_ADC_REG_H_
#define J7_LAB_SRC_MCAL_ADC_ADC_REG_H_

#define ADMUX			*((volatile u8*)0x27)
#define ADCSRA			*((volatile u8*)0x26)
#define ADCLH			*((volatile u16*)0x24)		/*0x24  0x25*/
#define SFIOR			*((volatile u8*)0x50)


#endif /* J7_LAB_SRC_MCAL_ADC_ADC_REG_H_ */
