/*
 * TIMER0.c
 *
 *  Created on: Mar 15, 2019
 *      Author: Noran Raafat - Nada Hefny
 */

#define TIMER0_MODE_NORMAL_MSK			0b00000000
#define TIMER0_MODE_CTC_MSK   			0b00001000

#define TIMER0_PRESCALER_NO_MSK  		0b00000001
#define TIMER0_PRESCALER_8_MSK   		0b00000010
#define TIMER0_PRESCALER_64_MSK  		0b00000011
#define TIMER0_PRESCALER_256_MSK 		0b00000100
#define TIMER0_PRESCALER_1024_MSK		0b00000101

#define TIMER0_OUTPUT_NONE_MSK  		0b00000000
#define TIMER0_OUTPUT_TOGGLE_MSK		0b00010000
#define TIMER0_OUTPUT_SET_MSK   		0b00110000
#define TIMER0_OUTPUT_CLEAR_MSK 		0b00100000

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER0_reg.h"
#include "TIMER0_cfg.h"

void TIMER0_init(void)
{
	/*clear control registers*/
	TCCR0 = 0;

	/* select mode*/
	TCCR0 |= TIMER0_MODE_SELECTOR_MSK;

	/*set output status on OC0*/
	TCCR0 |= TIMER0_OC0_PIN_OUTPUT_MSK;

	/*set steps to count*/
#if TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_CTC_MSK
	OCR0 = TIMER0_NO_OF_PETER_STEPS;
#elif TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_NORMAL_MSK
	TCNT0 = 255-TIMER0_NO_OF_PETER_STEPS;
#endif
	/*select Prescaler*/
	TCCR0 |= TIMER0_PRESCALER_SELECTOR_MSK;

}
void TIMER0_enInterrupt(void)
{
#if TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_CTC_MSK
	SET_BIT(TIMSK,1);
#elif TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_NORMAL_MSK
	SET_BIT(TIMSK,0);
#endif

}
void TIMER0_diInterrupt(void)
{
#if TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_CTC_MSK
	CLR_BIT(TIMSK,1);
#elif TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_NORMAL_MSK
	CLR_BIT(TIMSK,0);
#endif
}
void TIMER0_setNoOfSteps(u8 stepsNo)
{
	/*set steps to count*/
#if TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_CTC_MSK
	OCR0 = stepsNo;
#elif TIMER0_MODE_SELECTOR_MSK == TIMER0_MODE_NORMAL_MSK
	TCNT0 = 255-stepsNo;
#endif
}

u8 TIMER0_getNoOfSteps(void)
{
	return TCNT0;
}
