/*
 * EXTI1program.c
 *
 * Created: 16-Jun-23 12:03:31 PM
 *  Author: mosta
 */ 
#include "EXTI1config.h"
#include "../01.DIO/DIOconfig.h"

volatile void (*EXTI1_gptr)(void);

void EXTI1_voidInterruptInit(u8 snseCtrl)
{
	DIO_voidSetPinDirection(PORT_D, PIN3, IN);
	DIO_voidSetPinValue(PORT_D,PIN3,HIGH);
	snseCtrl;
	SET_BIT(GIFR, INT1E);
}


void EXTI1_voidChangeSnsCtrl(u8 snseCtrl)
{
	snseCtrl;
}


void EXTI1_voidInterruptEnable()
{
	SET_BIT(GICR, INT1E);
}



void EXTI1_voidInterruptDisable()
{
	CLR_BIT(GICR, INT1E);
}

void EXTI1_voidCallBack(void (*EXTI1_funPtr)(void))
{
	EXTI1_gptr= EXTI1_funPtr;
}

void __vector_2(void) __attribute__((signal,used));


void __vector_2(void)
{
	EXTI1_gptr();
}