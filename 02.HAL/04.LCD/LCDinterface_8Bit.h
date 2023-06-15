/*
 * LCDinterface_8Bit.h
 *
 * Created: 11-Jun-23 07:49:58 PM
 *  Author: mosta
 */ 


#ifndef LCDINTERFACE_8BIT_H_
#define LCDINTERFACE_8BIT_H_

void LCD_voidInit8Bit();
void LCD_voidSendCommand8Bit(u8 lcd8command);
void LCD_voidSendData8Bit(u8 lcd8data);



#endif /* LCDINTERFACE_8BIT_H_ */