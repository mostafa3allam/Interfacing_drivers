/*
 * ADCprivate.h
 *
 * Created: 17-Jun-23 10:46:53 AM
 *  Author: mosta
 */ 


#ifndef ADCPRIVATE_H_
#define ADCPRIVATE_H_

#include "../../lib/BIT_Math.h"
#include "../../lib/STD_types.h"


#define ADCL *((volatile u16 *) 0x24)
#define SFIOR *((volatile u8 *) 0x50)


typedef struct  
{
	u8 MUX : 5;
	u8 ADLAR : 1;
	u8 REFS : 2;
} ADMUX_Bits;
#define ADMUX ((volatile ADMUX_Bits *) 0x27)


typedef struct
{
	u8 ADPS : 3;
	u8 ADIE : 1;
	u8 ADIF : 1;
	u8 ADATE : 1;
	u8 ADSC : 1;
	u8 ADEN : 1;
} ADCSRA_Bits;
#define ADCSRA ((volatile ADCSRA_Bits *) 0x26)


#define ADTS2 7
#define ADTS1 6
#define ADTS0 5

#define AREF (0b00)
#define AVCC (0b01)
#define INTERNAL_VOLTAGE (0b11)

#define SINGLE_ADC0 (0b00000)
#define SINGLE_ADC1 (0b00001)
#define SINGLE_ADC2 (0b00010)
#define SINGLE_ADC3 (0b00011)
#define SINGLE_ADC4 (0b00100)
#define SINGLE_ADC5 (0b00101)
#define SINGLE_ADC6 (0b00110)
#define SINGLE_ADC7 (0b00111)

#define DIV_BY_2 (0b000)
#define PS_BY_2 (0b001)
#define DIV_BY_4 (0b010)
#define DIV_BY_8 (0b011)
#define DIV_BY_16 (0b100)
#define DIV_BY_32 (0b101)
#define DIV_BY_64 (0b110)
#define DIV_BY_128 (0b111)

#define POLLING 0
#define INTERRUPT 1
#define TRIGGER_INTERRUPT 2


#endif /* ADCPRIVATE_H_ */