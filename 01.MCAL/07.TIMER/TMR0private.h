/*
 * TMR0private.h
 *
 * Created: 18-Jun-23 09:03:51 AM
 *  Author: Mostafa Allam
 */ 


#ifndef TMR0PRIVATE_H_
#define TMR0PRIVATE_H_

#include "../01.DIO/DIOconfig.h"
#include "../../lib/STD_types.h"
#include "../../lib/BIT_Math.h"

typedef struct
{
	u8 CS0 : 3;
	u8 WGM01 : 1;
	u8 COM0 : 2;
	u8 WGM00 : 1;
	u8 FOC0 : 1;
} TCCR0;

#define TCCR0_REG ((volatile TCCR0 *) 0x53)
#define TCNT0 *((volatile u8 *) 0x52)
#define OCR0 *((volatile u8 *) 0x5c)
#define TIMSK *((volatile u8 *) 0x59)
#define TIFR *((volatile u8 *) 0x58)

#define NO_CLOCK 0b000
#define No_PRESCALER 0b001
#define PRESCALER_8 0b010
#define PRESCALER_64 0b011
#define PRESCALER_256 0b100
#define PRESCALER_1024 0b101
#define FALLING_EXTCLK 0b110
#define RISING_EXTCLK 0b111

#define CTC_NO_OC 0b00
#define CTC_TOG_OC 0b01
#define CTC_CLR_OC 0b10
#define CTC_SET_OC 0b11

#define FPWM_NO_OC 0b00
#define FPWM_CLR_OC 0b10
#define FPWM_SET_OC 0b11

#define TOIE0 0
#define OCIE0 1

#define TOV0 0
#define OCF0 1

#define NORMAL_MODE 0
#define PWM_PHASE_CORRECT 1
#define CTC 2
#define FAST_PWM 3

#endif /* TMR0PRIVATE_H_ */