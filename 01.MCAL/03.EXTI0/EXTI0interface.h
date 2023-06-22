/*
 * EXTI0interface.h
 *
 * Created: 16-Jun-23 11:17:07 AM
 *  Author: mosta
 */ 


#ifndef EXTI0INTERFACE_H_
#define EXTI0INTERFACE_H_

#include "EXTI0private.h"

void EXTI0_voidInterruptInit(u8 snseCtrl);
void EXTI0_voidInterruptEnable();
void EXTI0_voidInterruptDisable();
void EXTI0_voidChangeSnsCtrl(u8 snseCtrl);
void EXTI0_voidCallBack(void(*funPtr)(void));



#endif /* EXTI0INTERFACE_H_ */