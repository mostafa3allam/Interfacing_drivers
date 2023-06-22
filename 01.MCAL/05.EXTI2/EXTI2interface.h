/*
 * EXTI2interface.h
 *
 * Created: 16-Jun-23 01:45:05 PM
 *  Author: mosta
 */ 


#ifndef EXTI2INTERFACE_H_
#define EXTI2INTERFACE_H_


#include "EXTI2private.h"

void EXTI2_voidInterruptInit(u8 snseCtrl);
void EXTI2_voidInterruptEnable();
void EXTI2_voidInterruptDisable();
void EXTI2_voidChangeSnsCtrl(u8 snseCtrl);

#endif /* EXTI2INTERFACE_H_ */