/*
 * _7SEGprogram.c
 *
 * Created: 12-Jun-23 01:31:26 PM
 *  Author: mosta
 */ 

#include "7SEGconfigure.h"

void SSEG_Init()
{
	DIO_voidSetPinDirection(SSEGPORT0, SSEGPIN0, OUT);
	DIO_voidSetPinDirection(SSEGPORT1, SSEGPIN1, OUT);
	DIO_voidSetPinDirection(SSEGPORT2, SSEGPIN2, OUT);
	DIO_voidSetPinDirection(SSEGPORT3, SSEGPIN3, OUT);
	
	DIO_voidSetPinValue(SSEGPORT0, SSEGPIN0, HIGH);
	DIO_voidSetPinValue(SSEGPORT1, SSEGPIN1, HIGH);
	DIO_voidSetPinValue(SSEGPORT2, SSEGPIN2, HIGH);
	DIO_voidSetPinValue(SSEGPORT3, SSEGPIN3, HIGH);
}

void SSEG_Display(u8 sSegData)
{
	if(SV_BIT(sSegData, PIN0)==LOW){
		DIO_voidSetPinValue(SSEGPORT0, SSEGPIN0, LOW);
	}
	else{
		DIO_voidSetPinValue(SSEGPORT0, SSEGPIN0, HIGH);
	}
	
	
	if(SV_BIT(sSegData, PIN1)==LOW){
		DIO_voidSetPinValue(SSEGPORT1, SSEGPIN1, LOW);
	}
	else{
		DIO_voidSetPinValue(SSEGPORT1, SSEGPIN1, HIGH);
	}
	
	
	if(SV_BIT(sSegData, PIN2)== LOW){
		DIO_voidSetPinValue(SSEGPORT2, SSEGPIN2, LOW);
	}
	else{
		DIO_voidSetPinValue(SSEGPORT2, SSEGPIN2, HIGH);
	}
	
	
	if(SV_BIT(sSegData, PIN3)== LOW){
		DIO_voidSetPinValue(SSEGPORT3, SSEGPIN3, LOW);
	}
	else{
		DIO_voidSetPinValue(SSEGPORT3, SSEGPIN3, HIGH);
	}
}