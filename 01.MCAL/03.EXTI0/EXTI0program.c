/*
 * EXTI0program.c
 *
 * Created: 16-Jun-23 11:16:03 AM
 *  Author: mosta
 */ 

#include "EXTI0config.h"
#include "../01.DIO/DIOconfig.h"

volatile void(*EXTI0_gPtr)(void);
 
void EXTI0_voidInterruptInit(u8 snseCtrl)
{
	DIO_voidSetPinDirection(PORT_D, PIN2, IN);
	snseCtrl;
	SET_BIT(GIFR, INT0E);
}

void EXTI0_voidChangeSnsCtrl(u8 snseCtrl)
{
	snseCtrl;
}

void EXTI0_voidInterruptEnable()
{
	SET_BIT(GICR, INT0E);
}



void EXTI0_voidInterruptDisable()
{
	CLR_BIT(GICR, INT0E);
}

void EXTI0_voidCallBack(void(*funPtr)(void)){
	EXTI0_gPtr=funPtr;
}

void __vector_1(void) __attribute__((signal,used));


void __vector_1(void)
{
	EXTI0_gPtr();
}