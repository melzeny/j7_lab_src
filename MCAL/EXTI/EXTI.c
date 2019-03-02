/*
 * EXTI.c
 *
 *  Created on: Mar 2, 2019
 *      Author: Nada
 */

#define EXTI_EDGE_SELECTOR_RISING		0
#define EXTI_EDGE_SELECTOR_FALLING		1
#define EXTI_EDGE_SELECTOR_ONCHANGE		2


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "EXTI_reg.h"
#include "EXTI_cfg.h"
#include "EXTI.h"

void EXTI_init(EXTI_num_t ExtiNum)
{
	switch(ExtiNum)
	{
	case EXTI_int0:
		/*select edge*/
#if EXTI_EDGE_SELECTOR_INT0 == EXTI_EDGE_SELECTOR_RISING
		/*rising edge*/
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);

#elif EXTI_EDGE_SELECTOR_INT0 == EXTI_EDGE_SELECTOR_FALLING
		/*falling edge*/
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
#elif EXTI_EDGE_SELECTOR_INT0 == EXTI_EDGE_SELECTOR_ONCHANGE
		/*on Change*/
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
#else
#warning EXTI_EDGE_SELECTOR_INT0 configuration not valid
#endif
		break;

	case EXTI_int1:
		/*select edge*/
#if EXTI_EDGE_SELECTOR_INT1 == EXTI_EDGE_SELECTOR_RISING
		/*rising edge*/
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);

#elif EXTI_EDGE_SELECTOR_INT1 == EXTI_EDGE_SELECTOR_FALLING
		/*falling edge*/
		CLR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
#elif EXTI_EDGE_SELECTOR_INT1 == EXTI_EDGE_SELECTOR_ONCHANGE
		/*on Change*/
		SET_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
#else
#warning EXTI_EDGE_SELECTOR_INT1 configuration not valid
#endif
		break;

	case EXTI_int2:
		/*select edge*/
#if EXTI_EDGE_SELECTOR_INT2 == EXTI_EDGE_SELECTOR_RISING
		/*rising edge*/
		SET_BIT(MCUCSR,6);

#elif EXTI_EDGE_SELECTOR_INT2 == EXTI_EDGE_SELECTOR_FALLING
		/*falling edge*/
		CLR_BIT(MCUCSR,6);

#warning EXTI_EDGE_SELECTOR_INT2 configuration not valid
#endif
		break;
	}
}
void EXTI_enInterrupt(EXTI_num_t ExtiNum)
{
	switch(ExtiNum)
	{
	case EXTI_int0:
		SET_BIT(GICR,6);
		break;
	case EXTI_int1:
		SET_BIT(GICR,7);
		break;
	case EXTI_int2:
		SET_BIT(GICR,5);
		break;
	}

}
void EXTI_diInterrupt(EXTI_num_t ExtiNum)
{
	switch(ExtiNum)
	{
	case EXTI_int0:
		CLR_BIT(GICR,6);
		break;
	case EXTI_int1:
		CLR_BIT(GICR,7);
		break;
	case EXTI_int2:
		CLR_BIT(GICR,5);
		break;
	}
}


