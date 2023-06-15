/*
 * DIOprogram.c
 *
 * Created: 11-Jun-23 11:36:34 AM
 *  Author: mosta
 */ 

#include "DIOconfig.h"

void DIO_voidSetPinDirection(u8 portNumber, u8 pinNumber, u8 direction) /*initialize DIO direction*/
{
	switch(portNumber)
	{
		case PORT_A:	if(direction == IN)
						{
							CLR_BIT(DDRA , pinNumber);/*input*/
						}
						else if (direction == OUT)
						{
							SET_BIT(DDRA , pinNumber); /*output*/
						}
						else
						{
							/*ERROR*/
						}
						break;
		case PORT_B:	if(direction == IN)
						{
							CLR_BIT(DDRB , pinNumber);/*input*/
						}
						else if (direction == OUT)
						{
							SET_BIT(DDRB , pinNumber); /*output*/
						}
						else
						{
							/*ERROR*/
						}
						break;
		case PORT_C:	if(direction == IN)
						{
							CLR_BIT(DDRC , pinNumber);/*input*/
						}
						else if (direction == OUT)
						{
							SET_BIT(DDRC , pinNumber); /*output*/
						}
						else
						{
							/*ERROR*/
						}
						break;
		case PORT_D:	if(direction == IN)
						{
							CLR_BIT(DDRD , pinNumber);/*input*/
						}
						else if (direction == OUT)
						{
							SET_BIT(DDRD , pinNumber); /*output*/
						}
						else
						{
							/*ERROR*/
						}
						break;
	}
}

void DIO_voidSetPinValue(u8 portNumber, u8 pinNumber, u8 value) /*write data to DIO pin*/
{
	switch(portNumber)
	{
		case PORT_A:	if(value == LOW)
						{
							CLR_BIT(PORTA , pinNumber);/*write 0*/
						}
						else if (value == HIGH)
						{
							SET_BIT(PORTA , pinNumber); /*write 1*/
						}
						else
						{
							/*ERROR*/
						}
						break;
		case PORT_B:	if(value == LOW)
						{
							CLR_BIT(PORTB , pinNumber);/*write 0*/
						}
						else if (value == HIGH)
						{
							SET_BIT(PORTB , pinNumber); /*write 1*/
						}
						else
						{
							/*ERROR*/
						}
						break;
		case PORT_C:	if(value == LOW)
						{
							CLR_BIT(PORTC , pinNumber);/*write 0*/
						}
						else if (value == HIGH)
						{
							SET_BIT(PORTC , pinNumber); /*write 1*/
						}
						else
						{
							/*ERROR*/
						}
						break;
		case PORT_D:	if(value == LOW)
						{
							CLR_BIT(PORTD , pinNumber);/*write 0*/
						}
						else if (value == HIGH)
						{
							SET_BIT(PORTD , pinNumber); /*write 1*/
						}
						else
						{
							/*ERROR*/
						}
						break;
	}
}

void DIO_voidTogglePin(u8 portNumber, u8 pinNumber) /*toggle DIO pin*/
{
	switch(portNumber)
	{
		case PORT_A:	TOG_BIT(PORTA , pinNumber); /*toggle pin*/
						break;
		case PORT_B:	TOG_BIT(PORTB , pinNumber); /*toggle pin*/
						break;
		case PORT_C:	TOG_BIT(PORTC , pinNumber); /*toggle pin*/
						break;
		case PORT_D:	TOG_BIT(PORTD , pinNumber); /*toggle pin*/
						break;
	}
}

void DIO_voidGetPinValue(u8 portNumber, u8 pinNumber, u8 *val) /*read DIO pin*/
{
	switch(portNumber)
	{
		case PORT_A:	if(isBITCLR(PINA , pinNumber))
						{
							*val = LOW; /*read PORTA pinNumber into *value*/
						}
						else if (isBITSET(PINA , pinNumber))
						{
							*val = HIGH; /*read PORTA pinNumber into *value*/
						}
						break;
		case PORT_B:	if(isBITCLR(PINB , pinNumber))
						{
							*val = LOW; /*read PORTA pinNumber into *value*/
						}
						else if (isBITSET(PINB , pinNumber))
						{
							*val = HIGH; /*read PORTA pinNumber into *value*/
						}
						break;
		case PORT_C:	if(isBITCLR(PINC , pinNumber))
						{
							*val = LOW; /*read PORTA pinNumber into *value*/
						}
						else if (isBITSET(PINC , pinNumber))
						{
							*val = HIGH; /*read PORTA pinNumber into *value*/
						}
						break;
		case PORT_D:	if(isBITCLR(PIND , pinNumber))
						{
							*val = LOW; /*read PORTA pinNumber into *value*/
						}
						else if (isBITSET(PIND , pinNumber))
						{
							*val = HIGH; /*read PORTA pinNumber into *value*/
						}
						break;
	}
}

void DIO_voidSetPortDirection(u8 PORTID, u8 Direction)
{
	switch(PORTID)
	{
		case PORT_A:	if (Direction == IN)
						{
							CLR_REG(DDRA);
						}
						else if (Direction == OUT)
						{
							SET_REG(DDRA);
						}
						break;
		case PORT_B:	if (Direction == IN)
						{
							CLR_REG(DDRB);
						}
						else if (Direction == OUT)
						{
							SET_REG(DDRB);
						}
						break;
		case PORT_C:	if (Direction == IN)
						{
							CLR_REG(DDRC);
						}
						else if (Direction == OUT)
						{
							SET_REG(DDRC);
						}
						break;
		case PORT_D:	if (Direction == IN)
						{
							CLR_REG(DDRD);
						}
						else if (Direction == OUT)
						{
							SET_REG(DDRD);
						}
						break;
	}
}


void DIO_voidSetPortValue(u8 PORTID)
{
	switch(PORTID)
	{
		case PORT_A:	SET_REG(PORTA);
						break;
		case PORT_B:	SET_REG(PORTB);
						break;
		case PORT_C:	SET_REG(PORTC);
						break;
		case PORT_D:	SET_REG(PORTD);
						break;
	}
}

void DIO_voidClrPortValue(u8 PORTID)
{
	switch(PORTID)
	{
		case PORT_A:	CLR_REG(PORTA);
						break;
		case PORT_B:	CLR_REG(PORTB);
						break;
		case PORT_C:	CLR_REG(PORTC);
						break;
		case PORT_D:	CLR_REG(PORTD);
						break;
	}
}
