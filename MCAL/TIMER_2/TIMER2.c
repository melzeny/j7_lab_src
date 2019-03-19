/*
 * TIMER2.c
 *
 *  Created on: Mar 18, 2019
 *      Author: Muhammad Elzeiny
 */

#define TIMER2_MODE_NORMAL_MSK			0b00000000
#define TIMER2_MODE_CTC_MSK   			0b00001000

#define TIMER2_PRESCALER_NO_MSK  		0b00000001
#define TIMER2_PRESCALER_8_MSK   		0b00000010
#define TIMER2_PRESCALER_64_MSK  		0b00000011
#define TIMER2_PRESCALER_256_MSK 		0b00000100
#define TIMER2_PRESCALER_1024_MSK		0b00000101

#define TIMER2_OUTPUT_NONE_MSK  		0b00000000
#define TIMER2_OUTPUT_TOGGLE_MSK		0b00010000
#define TIMER2_OUTPUT_SET_MSK   		0b00110000
#define TIMER2_OUTPUT_CLEAR_MSK 		0b00100000

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER2_reg.h"
#include "TIMER2_cfg.h"
#include "TIMER2.h"

void TIMER2_init(void)
{
	/*clear control registers*/
	TCCR2 = 0;

	/* select mode*/
	TCCR2 |= TIMER2_MODE_SELECTOR_MSK;

	/*set output status on OC0*/
	TCCR2 |= TIMER2_OC0_PIN_OUTPUT_MSK;

	/*set steps to count*/
#if TIMER2_MODE_SELECTOR_MSK == TIMER2_MODE_CTC_MSK
	OCR2 = TIMER2_NO_OF_STEPS;
#elif TIMER2_MODE_SELECTOR_MSK == TIMER2_MODE_NORMAL_MSK
	TCNT2 = 255-TIMER2_NO_OF_STEPS;
#endif
	/*select Prescaler*/
	TCCR2 |= TIMER2_PRESCALER_SELECTOR_MSK;

}
void TIMER2_enInterrupt(void)
{
#if TIMER2_MODE_SELECTOR_MSK == TIMER2_MODE_CTC_MSK
	SET_BIT(TIMSK,7);
#elif TIMER2_MODE_SELECTOR_MSK == TIMER2_MODE_NORMAL_MSK
	SET_BIT(TIMSK,6);
#endif

}
void TIMER2_diInterrupt(void)
{
#if TIMER2_MODE_SELECTOR_MSK == TIMER2_MODE_CTC_MSK
	CLR_BIT(TIMSK,7);
#elif TIMER2_MODE_SELECTOR_MSK == TIMER2_MODE_NORMAL_MSK
	CLR_BIT(TIMSK,6);
#endif
}
void TIMER2_setNoOfSteps(u8 stepsNo)
{
	/*set steps to count*/
#if TIMER2_MODE_SELECTOR_MSK == TIMER2_MODE_CTC_MSK
	OCR2 = stepsNo;
#elif TIMER2_MODE_SELECTOR_MSK == TIMER2_MODE_NORMAL_MSK
	TCNT2 = 255-stepsNo;
#endif
}

u8 TIMER2_getNoOfSteps(void)
{
	return TCNT2;
}
