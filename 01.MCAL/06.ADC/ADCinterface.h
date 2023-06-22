/*
 * ADCinterface.h
 *
 * Created: 17-Jun-23 11:13:04 AM
 *  Author: mosta
 */ 


#ifndef ADCINTERFACE_H_
#define ADCINTERFACE_H_

#include "ADCprivate.h"

void ADC_voidInit(u8 voltSource, u8 adcMUX, u8 adcPrescalar);
void ADC_voidStartConv();
void ADC_voidReadRes(u16 *adcResult);
void ADC_voidDisable();
void ADC_voidInterruptEn();
void ADC_voidAutoTrigDisable();


#endif /* ADCINTERFACE_H_ */