/*
 * LCDprogram.c
 *
 * Created: 11-Jun-23 02:54:22 PM
 *  Author: mosta
 */ 

#define F_CPU 1000000UL

#include "LCDconfig.h"
#include <util/delay.h>

void LCD_voidInit8bit()
{
	DIO_voidSetPortDirection(PORT_C,OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_RS, OUT);
	/*DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_RW,OUT);*/
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
	/*DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);*/
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);

}


void LCD_voidSendData8Bit(u8 lcd8data)
{
	CPY_DATA(LCD_DATA_REG,lcd8data);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, HIGH);
	/*DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);*/
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
}


void LCD_voidInit4bit()
{
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN1, OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN2, OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN3, OUT);
	DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN4, OUT);
	
	DIO_voidSetPinDirection(LCD_PORT_CONTROL, LCD_RS, OUT);
	/*DIO_voidSetPinDirection(LCD_PORT_CONTROL, LCD_RW, OUT);*/
	DIO_voidSetPinDirection(LCD_PORT_CONTROL, LCD_E, OUT);
	_delay_ms(35);
	
	LCD_voidSendCommand4Bit(/*INIT_CMND1*/0x33);	//0x22
	LCD_voidSendCommand4Bit(/*INIT_CMND2*/0x32);	//0x40
	_delay_ms(1);
	
	LCD_voidSendCommand4Bit(/*DSPLY_OF_CMND1*/0x28);	//0xc0
	_delay_ms(1);
	
	LCD_voidSendCommand4Bit(/*DSPLY_CLR_CMND1*/0x0c);	//0x01
	_delay_ms(2);
	
	LCD_voidSendCommand4Bit(/*NTRY_MD_ST1*/0x01);
	LCD_voidSendCommand4Bit(/*NTRY_MD_ST1*/0x06);		//0x60
_delay_ms(100);
}


void LCD_voidSendCommand4Bit(u8 lcd4command)
{
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, LOW);
	/*DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);*/
	
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4,(lcd4command>>7)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN3,(lcd4command>>6)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN2,(lcd4command>>5)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN1,(lcd4command>>4)&1);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
	
	
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4,(lcd4command>>3)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN3,(lcd4command>>2)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN2,(lcd4command>>1)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN1,(lcd4command>>0)&1);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
}


void LCD_voidSendData4Bit(u8 lcd4data)
{
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RS, HIGH);
	/*DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_RW, LOW);*/
	
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4,(lcd4data>>7)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN3,(lcd4data>>6)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN2,(lcd4data>>5)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN1,(lcd4data>>4)&1);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
	
	
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN4,(lcd4data>>3)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN3,(lcd4data>>2)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN2,(lcd4data>>1)&1);
	DIO_voidSetPinValue(LCD_DATA_PORT,LCD_DATA_PIN1,(lcd4data>>0)&1);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, HIGH);
	_delay_us(1);
	DIO_voidSetPinValue(LCD_PORT_CONTROL, LCD_E, LOW);
	_delay_ms(3);
}


void LCD_voidSendString(u8 lcdstring[30])
{
	for (u8 i=0; lcdstring[i] != '\0'; i++)
	{
		#if (LCDCONFIGURATION == 4)
			LCD_voidSendData4Bit(lcdstring[i]);
		#elif (LCDCONFIGURATION == 8)
			LCD_voidSendData8Bit(lcdstring[i]);
		#endif
	}
}

void LCD_voidClrScrn()
{
	#if (LCDCONFIGURATION == 4)
		LCD_voidSendCommand4Bit(0x01);
	#elif (LCDCONFIGURATION == 8){
		LCD_voidSendCommand8Bit(0x01);
	#endif
}

void LCD_voidGoToRowColumn(u8 row,u8 col)
{
	u8 Address=0x00;
	
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}					
	#if (LCDCONFIGURATION == 4)
		LCD_voidSendCommand4Bit(Address | SET_CURSOR_LOCATION);
	#elif (LCDCONFIGURATION == 8)
		LCD_voidSendCommand8Bit(Address | SET_CURSOR_LOCATION);
	#endif
}

void LCD_voidIntgertoStr(u16 data)
{
	u8 post_data[10];
	u8 counter=0;
	do 
	{
		post_data[counter] = (data % 10) + '0';
		data = data / 10;
		counter++;
	} while (data != 0);
	#if (LCDCONFIGURATION == 4)
		for (; counter > 0; counter --)
		{
			LCD_voidSendData4Bit(post_data[counter-1]);
		}
	#elif (LCDCONFIGURATION == 8)
		for (; counter > 0; counter --)
		{
			LCD_voidSendData8Bit(post_data[counter-1]);
		}
	#endif
}

void LCD_voidCustomCharacter(u8 customArr[1][8])
{
	#if (LCDCONFIGURATION == 4)
		LCD_voidSendCommand4Bit(0x40);
		for (u8 i=0; i < 8; i++)
		{
			/*for (u8 j=0; j < 8;j++)
			{*/
				LCD_voidSendData4Bit(customArr[0][i]);
			//}
		}
		LCD_voidSendCommand4Bit(0x80);
		for (u8 i=0; i < 8; i++)
		{
			/*for (u8 j=0; j < 8;j++)
			{*/
				LCD_voidSendData4Bit(customArr[0][i]);
			//}
		}
	
	#endif
}