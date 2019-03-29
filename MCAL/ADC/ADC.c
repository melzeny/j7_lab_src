/*
 * ADC.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Muhammad.Elzeiny
 */
#define ADC_Vref_PIN_clr_msk			0b00111111
#define ADC_Vref_Aref_msk     			0b00000000
#define ADC_Vref_AVCC_msk         		0b01000000
#define ADC_Vref_INTERNAL_2_56_msk		0b11000000

#define ADC_MODE_AUTO_TRIGGER     		0
#define ADC_MODE_SINGLE_CONVERSION		1

#define ADC_PRESCALER_clr_msk								0b11111000
#define ADC_PRESCALER_msk_2  								0b00000001
#define ADC_PRESCALER_msk_4  								0b00000010
#define ADC_PRESCALER_msk_8        							0b00000011
#define ADC_PRESCALER_msk_16        						0b00000100
#define ADC_PRESCALER_msk_32        						0b00000101
#define ADC_PRESCALER_msk_64        						0b00000110
#define ADC_PRESCALER_msk_128       						0b00000111

#define ADC_SOURCE_TRIGGER_clr_msk							0b00011111
#define ADC_SOURCE_TRIGGER_FREE_RUNNING_msk  		  		0b00000000
#define ADC_SOURCE_TRIGGER_ANALOG_COMARATOR_msk             0b00100000
#define ADC_SOURCE_TRIGGER_EXTI0_msk                        0b01000000
#define ADC_SOURCE_TRIGGER_TIMER0_COMPARE_MATCH_msk         0b01100000
#define ADC_SOURCE_TRIGGER_TIMER0_OVF_msk                   0b10000000
#define ADC_SOURCE_TRIGGER_TIMER1_COMPARE_MATCH_msk         0b10100000
#define ADC_SOURCE_TRIGGER_TIMER1_OVF_msk                   0b11000000
#define ADC_SOURCE_TRIGGER_TIMER1_CAPTURE_EVENT_msk         0b11100000

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_reg.h"
#include "ADC_cfg.h"
#include "ADC.h"

void ADC_init(void)
{

}
void ADC_startConversion(ADC_ch_t ch)
{

}
u16 ADC_getLastConvertedVal(ADC_ch_t ch)
{

}
void ADC_enInterrupt(void)
{

}
void ADC_diInterrupt(void)
{

}



void _vector_16(void) __attribute__((signal,used));
void _vector_16(void)
{
	/*ADC ISR*/
}
