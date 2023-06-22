/*
 * ADCprogram.c
 *
 * Created: 17-Jun-23 11:14:05 AM
 *  Author: mosta
 */ 
#include "ADCconfig.h"
#include "../01.DIO/DIOconfig.h"


void ADC_voidInit(u8 voltSource, u8 adcMUX, u8 adcPrescalar)
{
	#if (ADC_MODE == POLLING)
		DIO_voidSetPinDirection(PORT_A, adcMUX, IN);
		ADMUX -> ADLAR = 0 ;
		ADMUX -> REFS = voltSource;
		ADMUX -> MUX = adcMUX;
		ADCSRA -> ADPS = adcPrescalar;
		ADCSRA -> ADIF = 1;
		ADCSRA -> ADEN = 1;
		
		
		
	#endif
}

void ADC_voidAutoTrig()
{
	#if (ADC_MODE == POLLING | ADC_MODE == INTERRUPT)
		ADCSRA -> ADATE = 0 ;
	#elif (ADC_MODE == TRIGGER_INTERRUPT)
		ADCSRA -> ADATE = 1;
	#endif
}

void ADC_voidStartConv()
{
	#if (ADC_MODE == POLLING)
		ADCSRA -> ADSC = 1;
	#endif
}


void ADC_voidReadRes(u16 *adcResult)
{
	*adcResult = ADCL;
	#if (ADC_MODE == POLLING)
		ADCSRA -> ADIF = 1;    /*This bit is set when an ADC conversion completes and the Data Registers are updated and it's cleared by writing a logical one to the flag*/
	#endif
}


void ADC_voidDisable()
{
	ADCSRA -> ADEN = 0;
}


void ADC_voidInterruptEn()
{
	#if (ADC_MODE == TRIGGER_INTERRUPT | ADC_MODE == INTERRUPT)
		ADCSRA -> ADIE = 1;
	#endif
}