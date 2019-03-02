/*
 * GI.c
 *
 *  Created on: Mar 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#define SREG			*((volatile u8*)0x5F)


void GI_en(void)
{
	SET_BIT(SREG,7);
}

void GI_di(void)
{
	CLR_BIT(SREG,7);
}
