/*
 * DIOinterface.h
 *
 * Created: 11-Jun-23 11:33:14 AM
 *  Author: mosta
 */ 


#ifndef DIOINTERFACE_H_
#define DIOINTERFACE_H_

#include "DIOprivate.h"

void DIO_voidSetPinDirection(u8 portNumber, u8 pinNumber, u8 direction); /*initialize DIO direction*/
void DIO_voidSetPinValue(u8 portNumber, u8 pinNumber, u8 value); /*write data to DIO pin*/
void DIO_voidTogglePin(u8 portNumber, u8 pinNumber); /*toggle DIO pin*/

void DIO_voidGetPinValue(u8 portNumber, u8 pinNumber, u8 *val); /*read DIO pin*/

void DIO_voidSetPortDirection(u8 PORTID, u8 Direction);
void DIO_voidSetPortValue(u8 PORTID);
void DIO_voidClrPortValue(u8 PORTID);



#endif /* DIOINTERFACE_H_ */