/*
 * GIEprogram.c
 *
 * Created: 16-Jun-23 11:09:35 AM
 *  Author: mosta
 */ 

#include "GIEconfig.h"

void GIE_voidEnable()
{
	SET_BIT(SREG, IBIT);
}



void GIE_voidDisable()
{
	CLR_BIT(SREG, IBIT);
}