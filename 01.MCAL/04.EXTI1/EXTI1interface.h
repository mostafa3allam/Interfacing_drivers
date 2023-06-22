/*
 * EXTI1interface.h
 *
 * Created: 16-Jun-23 11:46:37 AM
 *  Author: mosta
 */ 


#ifndef EXTI1INTERFACE_H_
#define EXTI1INTERFACE_H_


#include "EXTI1private.h"

void EXTI1_voidInterruptInit(u8 snseCtrl);
void EXTI1_voidInterruptEnable();
void EXTI1_voidInterruptDisable();
void EXTI1_voidCallBack(void (*EXTI1_funPtr)(void));
void EXTI1_voidChangeSnsCtrl(u8 snseCtrl);

#endif /* EXTI1INTERFACE_H_ */