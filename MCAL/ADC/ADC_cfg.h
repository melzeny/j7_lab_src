/*
 * ADC_cfg.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef J7_LAB_SRC_MCAL_ADC_ADC_CFG_H_
#define J7_LAB_SRC_MCAL_ADC_ADC_CFG_H_


/*
 *  choose Vref
 *  ADC_Vref_Aref_msk
 *  ADC_Vref_AVCC_msk
 *  ADC_Vref_INTERNAL_2_56_msk
 * */
#define ADC_Vref_PIN_msk				ADC_Vref_AVCC_msk


/*
 * choose ADC mode
 * ADC_MODE_AUTO_TRIGGER
 * ADC_MODE_SINGLE_CONVERSION
 * */
#define ADC_MODE_SELECTOR				ADC_MODE_SINGLE_CONVERSION

#if ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER
/*choose source trigger
 * ADC_SOURCE_TRIGGER_FREE_RUNNING_msk
 * ADC_SOURCE_TRIGGER_ANALOG_COMARATOR_msk
 * ADC_SOURCE_TRIGGER_EXTI0_msk
 * ADC_SOURCE_TRIGGER_TIMER0_COMPARE_MATCH_msk
 * ADC_SOURCE_TRIGGER_TIMER0_OVF_msk
 * ADC_SOURCE_TRIGGER_TIMER1_COMPARE_MATCH_msk
 * ADC_SOURCE_TRIGGER_TIMER1_OVF_msk
 * ADC_SOURCE_TRIGGER_TIMER1_CAPTURE_EVENT_msk
 * */
#define ADC_SOURCE_TRIGGER_msk			ADC_SOURCE_TRIGGER_FREE_RUNNING_msk
#endif
/*
 * choose ADC circuit prescaler
 * ADC_PRESCALER_msk_2
 * ADC_PRESCALER_msk_4
 * ADC_PRESCALER_msk_8
 * ADC_PRESCALER_msk_16
 * ADC_PRESCALER_msk_32
 * ADC_PRESCALER_msk_64
 * ADC_PRESCALER_msk_128
 * */
#define ADC_PRESCALER_msk				ADC_PRESCALER_msk_128

#endif /* J7_LAB_SRC_MCAL_ADC_ADC_CFG_H_ */
