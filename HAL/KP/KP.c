/*
 * KP.c
 *
 *  Created on: Feb 23, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../../j7_lab_src/HAL/KP/KP.h"

#include "../../../j7_lab_src/HAL/KP/KP_cfg.h"
#include "../../../j7_lab_src/HAL/KP/KP_cfg.h"
#include "../../../j7_lab_src/MCAL/DIO/DIO.h"

static u8 KP_Pressed_Button;
void KP_init(void)
{
	DIO_init();
	/*active internal pull-up resistor for input pins*/
	DIO_writePinValue(KP_INPUT_PIN_C0,DIO_pin_value_high);
	DIO_writePinValue(KP_INPUT_PIN_C1,DIO_pin_value_high);
	DIO_writePinValue(KP_INPUT_PIN_C2,DIO_pin_value_high);
	DIO_writePinValue(KP_INPUT_PIN_C3,DIO_pin_value_high);

}
static void readInputPins(u8 RowActivated)
{
	if(DIO_readPinValue(KP_INPUT_PIN_C0) == DIO_pin_value_low)
	{
		KP_Pressed_Button = RowActivated * 4;
	}
	else if(DIO_readPinValue(KP_INPUT_PIN_C1) == DIO_pin_value_low)
	{
		KP_Pressed_Button = (RowActivated * 4) + 1;
	}
	else if(DIO_readPinValue(KP_INPUT_PIN_C2) == DIO_pin_value_low)
	{
		KP_Pressed_Button = (RowActivated * 4) + 2;
	}
	else if(DIO_readPinValue(KP_INPUT_PIN_C3) == DIO_pin_value_low)
	{
		KP_Pressed_Button = (RowActivated * 4) + 3;
	}
}
u8 KP_getPressedButton(void)
{
	KP_Pressed_Button = -1;
	/*active Row 0*/
	DIO_writePinValue(KP_OUTPUT_PIN_R0,DIO_pin_value_low); /*active */
	DIO_writePinValue(KP_OUTPUT_PIN_R1,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R2,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R3,DIO_pin_value_high);
	readInputPins(0);

	/*active Row 1*/
	DIO_writePinValue(KP_OUTPUT_PIN_R0,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R1,DIO_pin_value_low); /*active */
	DIO_writePinValue(KP_OUTPUT_PIN_R2,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R3,DIO_pin_value_high);
	readInputPins(1);


	/*active Row 2*/
	DIO_writePinValue(KP_OUTPUT_PIN_R0,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R1,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R2,DIO_pin_value_low); /*active */
	DIO_writePinValue(KP_OUTPUT_PIN_R3,DIO_pin_value_high);
	readInputPins(2);

	/*active Row 3*/
	DIO_writePinValue(KP_OUTPUT_PIN_R0,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R1,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R2,DIO_pin_value_high);
	DIO_writePinValue(KP_OUTPUT_PIN_R3,DIO_pin_value_low);/*active */
	readInputPins(3);

	return KP_Pressed_Button;
}
