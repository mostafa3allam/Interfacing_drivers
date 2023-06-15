/*
 * SWprogram.c
 *
 * Created: 11-Jun-23 12:53:02 PM
 *  Author: mosta
 */ 

#include "SWinterface.h"

void Switch_init(u8 PortID, u8 PinNumber)
{
	DIO_voidSetPinDirection(PortID,PinNumber,IN);
}

void Switch_read(u8 PortID, u8 PinNumber, u8 *val)
{
	DIO_voidGetPinValue(PortID,PinNumber,val);
}