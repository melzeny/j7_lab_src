/*
 * ADC.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_ADC_ADC_H_
#define J7_LAB_SRC_MCAL_ADC_ADC_H_

#include "../../LIB/STD_TYPES.h"
typedef enum
{
	ADC_ch0,
	ADC_ch1,
	ADC_ch2,
	ADC_ch3,
	ADC_ch4,
	ADC_ch5,
	ADC_ch6,
	ADC_ch7,
	ADC_MAX_NO_OF_CH
}ADC_ch_t;

void ADC_init(void);
void ADC_startConversion(ADC_ch_t ch);
u16 ADC_getVoltage_mv(ADC_ch_t ch);
void ADC_enInterrupt(void);
void ADC_diInterrupt(void);


#endif /* J7_LAB_SRC_MCAL_ADC_ADC_H_ */
