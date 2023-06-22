/*
 * LCDinterface.h
 *
 * Created: 11-Jun-23 02:52:38 PM
 *  Author: mosta
 */ 


#ifndef LCDINTERFACE_4BIT_H_
#define LCDINTERFACE_4BIT_H_

#include "../../01.MCAL/01.DIO/DIOconfig.h"

void LCD_voidInit4bit();
void LCD_voidSendCommand4Bit(u8 lcd4command);
void LCD_voidSendData4Bit(u8 lcd4data);
void LCD_voidInit8bit();
void LCD_voidSendCommand8Bit(u8 lcd8command);
void LCD_voidSendData8Bit(u8 lcd8data);
void LCD_voidSendString(u8 lcdstring[30]);
void LCD_voidClrScrn();
void LCD_voidGoToRowColumn(u8 row,u8 col);
void LCD_voidIntgertoStr(u16 data);
void LCD_voidCustomCharacter(u8 customArr[1][8]);


#endif /* LCDINTERFACE_H_ */