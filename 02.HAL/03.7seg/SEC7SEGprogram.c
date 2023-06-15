/*
 * SEC7SEGprogram.c
 *
 * Created: 12-Jun-23 08:44:06 PM
 *  Author: mosta
 */ 

#include "SEC7SEGconfigure.h"

void SECSSEG_Init()
{
	DIO_voidSetPinDirection(SECSSEGPORT0, SECSSEGPIN0, OUT);
	DIO_voidSetPinDirection(SECSSEGPORT1, SECSSEGPIN1, OUT);
	DIO_voidSetPinDirection(SECSSEGPORT2, SECSSEGPIN2, OUT);
	DIO_voidSetPinDirection(SECSSEGPORT3, SECSSEGPIN3, OUT);
	
	DIO_voidSetPinValue(SECSSEGPORT0, SECSSEGPIN0, HIGH);
	DIO_voidSetPinValue(SECSSEGPORT1, SECSSEGPIN1, HIGH);
	DIO_voidSetPinValue(SECSSEGPORT2, SECSSEGPIN2, HIGH);
	DIO_voidSetPinValue(SECSSEGPORT3, SECSSEGPIN3, HIGH);
}

void SECSSEG_Display(u8 secSSegData)
{

	if(SV_BIT(secSSegData, PIN0)==LOW){
		DIO_voidSetPinValue(SECSSEGPORT0, SECSSEGPIN0, LOW);
	}
	else{
		DIO_voidSetPinValue(SECSSEGPORT0, SECSSEGPIN0, HIGH);
	}
	
	
	if(SV_BIT(secSSegData, PIN1)==LOW){
		DIO_voidSetPinValue(SECSSEGPORT1, SECSSEGPIN1, LOW);
	}
	else{
		DIO_voidSetPinValue(SECSSEGPORT1, SECSSEGPIN1, HIGH);
	}
	
	
	if(SV_BIT(secSSegData, PIN2)== LOW){
		DIO_voidSetPinValue(SECSSEGPORT2, SECSSEGPIN2, LOW);
	}
	else{
		DIO_voidSetPinValue(SECSSEGPORT2, SECSSEGPIN2, HIGH);
	}
	
	
	if(SV_BIT(secSSegData, PIN3)== LOW){
		DIO_voidSetPinValue(SECSSEGPORT3, SECSSEGPIN3, LOW);
	}
	else{
		DIO_voidSetPinValue(SECSSEGPORT3, SECSSEGPIN3, HIGH);
	}
}