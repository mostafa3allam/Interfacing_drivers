/*
 * EXTI2.c
 *
 * Created: 16-Jun-23 01:44:04 PM
 *  Author: mosta
 */ 

#include "EXTI2config.h"
#include "../01.DIO/DIOconfig.h"

void EXTI2_voidInterruptInit(u8 snseCtrl)
{
	DIO_voidSetPinDirection(PORT_B, PIN2, IN);
	snseCtrl;
	SET_BIT(GIFR, INT2E);
}


void EXTI2_voidChangeSnsCtrl(u8 snseCtrl)
{
	snseCtrl;
}


void EXTI2_voidInterruptEnable()
{
	SET_BIT(GICR, INT2E);
}



void EXTI2_voidInterruptDisable()
{
	CLR_BIT(GICR, INT2E);
}


void __vector_3(void) __attribute__((signal,used));


void __vector_3(void)
{
	
}