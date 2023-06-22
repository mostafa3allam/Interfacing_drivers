/*
 * LCDconfig.h
 *
 * Created: 11-Jun-23 02:52:06 PM
 *  Author: mosta
 */ 


#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

#include "LCDinterface.h"
/************************************************************************/
/* control mode of operation                                            */
/************************************************************************/
#define LCDCONFIGURATION 4

#define SET_CURSOR_LOCATION 0x80

/************************************************************************/
/* 4BIT Mode                                                            */
/************************************************************************/



/************************************************************************/
/* Data Bits and ControlBits                                            */
/************************************************************************/
#define LCD_DATA_PORT PORT_B
#define LCD_DATA_REG PORTB
#define LCD_PORT_CONTROL PORT_A

#define LCD_DATA_PIN1 PIN0
#define LCD_DATA_PIN2 PIN1
#define LCD_DATA_PIN3 PIN2
#define LCD_DATA_PIN4 PIN3

#define LCD_RS PIN5
#define LCD_RW PIN4
#define LCD_E PIN6

/************************************************************************/
/* Commands                                                             */
/************************************************************************/
#define INIT_CMND1 0x22
#define INIT_CMND2 0x40 /* 4bit 2line 5x7dots*/
#define DSPLY_OF_CMND1 0xc0 /*display on, cursor off, blinking off*/
#define DSPLY_CLR_CMND1 0x10
#define NTRY_MD_ST1 0x60 /*set mode to increment*/

/************************************************************************/
/* 8BIT Mode                                                            */
/************************************************************************/



/************************************************************************/
/* Data Bits and ControlBits                                            */
/************************************************************************/



/************************************************************************/
/* Commands                                                             */
/************************************************************************/
#define INIT_CMND 0x38 /* 8bit 2line 5x7dots*/
#define DSPLY_OF_CMND 0x0c /*display on, cursor off, blinking off*/
#define DSPLY_CLR_CMND 0x01 
#define NTRY_MD_ST 0x06 /*set mode to increment*/







#endif /* LCDCONFIG_H_ */