/*
 * SWinterface.h
 *
 * Created: 11-Jun-23 12:49:08 PM
 *  Author: mosta
 */ 


#ifndef SWINTERFACE_H_
#define SWINTERFACE_H_

#include "../../01.MCAL/01.DIO/DIOconfig.h"

void Switch_init(u8 PortID, u8 PinNumber);
void Switch_read(u8 PortID, u8 PinNumber, u8 *val);


#endif /* SWINTERFACE_H_ */