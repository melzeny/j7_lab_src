/*
 * ADC.c
 *
 *  Created on: Mar 29, 2019
 *      Author: Yasmin Mahdy
 */
#define ADC_Vref_PIN_clr_msk								0b00111111
#define ADC_Vref_Aref_msk     								0b00000000
#define ADC_Vref_AVCC_msk         							0b01000000
#define ADC_Vref_INTERNAL_2_56_msk							0b11000000

#define ADC_MODE_SELECTOR_clr_msk							0b11011111
#define ADC_MODE_AUTO_TRIGGER     							0b00100000
#define ADC_MODE_SINGLE_CONVERSION							0b00000000

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

static u16 LastConvertedVal[ADC_MAX_NO_OF_CH];
void ADC_init(void)
{
	/*set Vref*/
	ADMUX &= ADC_Vref_PIN_clr_msk;
	ADMUX |= ADC_Vref_PIN_msk;

	/*select mode*/
	ADCSRA &= ADC_MODE_SELECTOR_clr_msk;
	ADCSRA |= ADC_MODE_SELECTOR;
#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
	/* trigger source*/
	SFIOR &= ADC_SOURCE_TRIGGER_clr_msk;
	SFIOR |= ADC_SOURCE_TRIGGER_msk;
#endif

	/*ADC enable*/
	SET_BIT(ADCSRA,7);

	/*ADC prescaler*/
	ADCSRA &= ADC_PRESCALER_clr_msk;
	ADCSRA |= ADC_PRESCALER_msk;

}
void ADC_startConversion(ADC_ch_t ch)
{
	if(ch < ADC_MAX_NO_OF_CH)
	{
		/* choose ch*/
		ADMUX &= 0b11100000;
		ADMUX |= ch;

		/*start conversion*/
		SET_BIT(ADCSRA,6);
	}
}
u16 ADC_getLastConvertedVal(ADC_ch_t ch)
{
	return LastConvertedVal[ch];
}
void ADC_enInterrupt(void)
{
	SET_BIT(ADCSRA,3);
}
void ADC_diInterrupt(void)
{
	CLR_BIT(ADCSRA,3);
}



void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
	/*ADC ISR*/
	ADC_ch_t CurrentChannle = 0b00011111 & ADMUX;
	LastConvertedVal[CurrentChannle] = ADCLH;
}
