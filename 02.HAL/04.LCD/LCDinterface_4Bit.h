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



#endif /* LCDINTERFACE_H_ */