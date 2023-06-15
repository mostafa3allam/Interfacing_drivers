/*
 * LEDinterface.h
 *
 * Created: 11-Jun-23 12:17:42 PM
 *  Author: mosta
 */ 


#ifndef LEDINTERFACE_H_
#define LEDINTERFACE_H_

#include "../../01.MCAL/01.DIO/DIOconfig.h"

void LED_init(u8 ledPort, u8 ledNumber);
void LED_on(u8 ledPort, u8 ledNumber);
void LED_off(u8 ledPort, u8 ledNumber);
void LED_toggle(u8 ledPort, u8 ledNumber);




#endif /* LEDINTERFACE_H_ */