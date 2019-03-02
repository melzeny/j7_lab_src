/*
 * DIO.c
 *
 *  Created on: Feb 16, 2019
 *      Author: Zahran
 */
#include "../../../j7_lab_src/MCAL/DIO/DIO.h"

#include "../../../j7_lab_src/LIB/BIT_MATH.h"
#include "../../../j7_lab_src/MCAL/DIO/DIO_cfg.h"
#include "../../../j7_lab_src/MCAL/DIO/DIO_reg.h"
#include "../../../j7_lab_src/LIB/BIT_MATH.h"
#include "../../../j7_lab_src/LIB/STD_TYPES.h"

#define DIO_PORT_SIZE		8

void DIO_init(void)
{
	DDRA=BIT_CONC(DIO_PIN_A7_DIR,DIO_PIN_A6_DIR,DIO_PIN_A5_DIR,DIO_PIN_A4_DIR,DIO_PIN_A3_DIR,DIO_PIN_A2_DIR,DIO_PIN_A1_DIR,DIO_PIN_A0_DIR);
	DDRB=BIT_CONC(DIO_PIN_B7_DIR,DIO_PIN_B6_DIR,DIO_PIN_B5_DIR,DIO_PIN_B4_DIR,DIO_PIN_B3_DIR,DIO_PIN_B2_DIR,DIO_PIN_B1_DIR,DIO_PIN_B0_DIR);
	DDRC=BIT_CONC(DIO_PIN_C7_DIR,DIO_PIN_C6_DIR,DIO_PIN_C5_DIR,DIO_PIN_C4_DIR,DIO_PIN_C3_DIR,DIO_PIN_C2_DIR,DIO_PIN_C1_DIR,DIO_PIN_C0_DIR);
	DDRD=BIT_CONC(DIO_PIN_D7_DIR,DIO_PIN_D6_DIR,DIO_PIN_D5_DIR,DIO_PIN_D4_DIR,DIO_PIN_D3_DIR,DIO_PIN_D2_DIR,DIO_PIN_D1_DIR,DIO_PIN_D0_DIR);
}
void DIO_writePinValue(DIO_pin_num_t PinNum,DIO_pin_value_t PinValue)
{
	/*write on PORTx REgister*/
	DIO_port_num_t PortNum = PinNum / DIO_PORT_SIZE;
	PinNum %= DIO_PORT_SIZE;
	switch(PortNum)
	{
	case DIO_port_A:
		if(PinValue == DIO_pin_value_high)
			SET_BIT(PORTA,PinNum);
		else
			CLR_BIT(PORTA,PinNum);
		break;
	case DIO_port_B:
		if(PinValue == DIO_pin_value_high)
			SET_BIT(PORTB,PinNum);
		else
			CLR_BIT(PORTB,PinNum);
		break;
	case DIO_port_C:
		if(PinValue == DIO_pin_value_high)
			SET_BIT(PORTC,PinNum);
		else
			CLR_BIT(PORTC,PinNum);
		break;
	case DIO_port_D:
		if(PinValue == DIO_pin_value_high)
			SET_BIT(PORTD,PinNum);
		else
			CLR_BIT(PORTD,PinNum);
		break;

	}
}
DIO_pin_value_t DIO_readPinValue(DIO_pin_num_t PinNum)
{
	DIO_pin_value_t ret;
	/*read value from PINx register*/
	DIO_port_num_t PortNum = PinNum / DIO_PORT_SIZE;
	PinNum %= DIO_PORT_SIZE;
	switch(PortNum)
	{
	case DIO_port_A:
		ret = GET_BIT(PINA,PinNum);
		break;
	case DIO_port_B:
		ret = GET_BIT(PINB,PinNum);
		break;
	case DIO_port_C:
		ret = GET_BIT(PINC,PinNum);
		break;
	case DIO_port_D:
		ret = GET_BIT(PIND,PinNum);
		break;

	}
	return ret;
}
void DIO_writePortValue(DIO_port_num_t PortNum,u8 value)
{
	switch(PortNum)
	{
	case DIO_port_A:
		PORTA = value;
		break;
	case DIO_port_B:
		PORTB = value;
		break;
	case DIO_port_C:
		PORTC = value;
		break;
	case DIO_port_D:
		PORTD = value;
		break;
	}

}
u8 DIO_readPortValue(DIO_port_num_t PortNum)
{
	u8 ret;
	switch(PortNum)
	{
	case DIO_port_A:
		ret = PINA;
		break;
	case DIO_port_B:
		ret = PINB;
		break;
	case DIO_port_C:
		ret = PINC;
		break;
	case DIO_port_D:
		ret = PIND;
		break;
	}
	return ret;

}

void DIO_togglePin(DIO_pin_num_t PinNum)
{
	/*write on PORTx REgister*/
	DIO_port_num_t PortNum = PinNum / DIO_PORT_SIZE;
	PinNum %= DIO_PORT_SIZE;
	switch(PortNum)
	{
	case DIO_port_A:
		TOGGLE_BIT(PORTA,PinNum);
		break;
	case DIO_port_B:
		TOGGLE_BIT(PORTB,PinNum);
		break;
	case DIO_port_C:
		TOGGLE_BIT(PORTC,PinNum);
		break;
	case DIO_port_D:
		TOGGLE_BIT(PORTD,PinNum);
		break;

	}
}
