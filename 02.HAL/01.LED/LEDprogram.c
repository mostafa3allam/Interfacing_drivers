/*
 * LEDprogram.c
 *
 * Created: 11-Jun-23 12:47:09 PM
 *  Author: mosta
 */ 

#include "LEDinterface.h"

void LED_init(u8 ledPort, u8 ledNumber)
{
	DIO_voidSetPinDirection(ledPort, ledNumber,OUT);
}

void LED_on(u8 ledPort, u8 ledNumber)
{
	DIO_voidSetPinValue(ledPort, ledNumber, HIGH);
}

void LED_off(u8 ledPort, u8 ledNumber)
{
	DIO_voidSetPinValue(ledPort, ledNumber, LOW);
}

void LED_toggle(u8 ledPort, u8 ledNumber)
{
	DIO_voidTogglePin(ledPort,ledNumber);
}