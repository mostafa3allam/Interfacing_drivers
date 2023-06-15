/*
 * LCDprogram.c
 *
 * Created: 11-Jun-23 02:54:22 PM
 *  Author: mosta
 */ 

#define F_CPU 16000000UL

#include "LCDconfig.h"
#include <util/delay.h>

/*
void LCD_voidInit8bit()
{
	DIO_voidSetPortDirection(PORT_C,OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_RS, OUT);
	/ *DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_RW,OUT);* /
	DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_E,OUT);
	_delay_ms(35);
	
	LCD_voidSendCommand8Bit(INIT_CMND);
	_delay_us(45);
	
	LCD_voidSendCommand8Bit(DSPLY_OF_CMND);
	_delay_us(45);
	
	LCD_voidSendCommand8Bit(DSPLY_CLR_CMND);
	_delay_ms(2);
	
	LCD_voidSendCommand8Bit(NTRY_MD_ST);
}


void LCD_voidSendCommand8Bit(u8 lcd8command)
{
	CPY_DATA(LCD_DATA_REG,lcd8command);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, LOW);
	/ *DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);* /
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);

}


void LCD_voidSendData8Bit(u8 lcd8data)
{
	CPY_DATA(LCD_DATA_REG,lcd8data);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, HIGH);
	/ *DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);* /
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
}
*/

void LCD_voidInit4bit()
{
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN1, OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN2, OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN3, OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN4, OUT);
	
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_RS, OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_RW, OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_E, OUT);
	_delay_ms(35);
	
	LCD_voidSendCommand4Bit(INIT_CMND1);
	LCD_voidSendCommand4Bit(INIT_CMND2);
	_delay_us(45);
	
	LCD_voidSendCommand4Bit(DSPLY_OF_CMND1);
	_delay_us(45);
	
	LCD_voidSendCommand4Bit(DSPLY_CLR_CMND1);
	_delay_ms(2);
	
	LCD_voidSendCommand4Bit(NTRY_MD_ST1);

}


void LCD_voidSendCommand4Bit(u8 lcd4command)
{
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, LOW);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	LCD_DATA_REG = (LCD_DATA_REG & 0x0f) | (lcd4command & 0xf0);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
	
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_ms(1);
	LCD_DATA_REG = (LCD_DATA_REG & 0x0f) | (lcd4command << 4);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
}


void LCD_voidSendData4Bit(u8 lcd4data)
{
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, HIGH);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	LCD_DATA_REG = (LCD_DATA_REG & 0x0f) | (lcd4data & 0xf0);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
	
	LCD_DATA_REG = (LCD_DATA_REG & 0x0f) | (lcd4data << 4);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	LCD_DATA_REG = (LCD_DATA_REG & 0x0f) | (lcd4data << 4);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
}


void LCD_voidSendStringBit(u8 lcdstring)
{
	for (u8 i=0; lcdstring[i] != '\0'; i++)
	{
		if (LCDCONFIGURATION == 4)
		{
			LCD_voidSendData4Bit(lcdstring[i]);
		}
		else if (LCDCONFIGURATION == 8){
			LCD_voidSendData8Bit(lcdstring[i]);
		}
	}
}

void LCD_voidClrScrn()
{
	if (LCDCONFIGURATION == 4)
	{
		LCD_voidSendCommand4Bit(0x01);
	}
	else if (LCDCONFIGURATION == 8){
		LCD_voidSendCommand8Bit(0x01);
	}
}

