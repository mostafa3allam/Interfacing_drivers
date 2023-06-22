/*
 * TMR0interfae.h
 *
 * Created: 18-Jun-23 09:04:18 AM
 *  Author: Mostafa Allam
 */ 


#ifndef TMR0INTERFAE_H_
#define TMR0INTERFAE_H_

#include "TMR0private.h"

void TMR0_voidInit(u8 prscaler, u8 cmpMode);
void TMR0_voidStartCount(u8 startValue);
void TMR0_callBack(void (*TMR0Ptr)(void));
void TMR0_voidInterruptEn();
void TMR0_voidCompVal(u8 cmpVal);


#endif /* TMR0INTERFAE_H_ */