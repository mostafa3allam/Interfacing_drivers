/*
 * TMR0program.c
 *
 * Created: 18-Jun-23 08:12:11 AM
 *  Author: Mostafa Allam
 */ 

#include "TMR0config.h"
#define NULL ((void *) 0)
static void(*TMR0_gPtr)(void) = NULL ;

void TMR0_voidInit(u8 prscaler, u8 cmpMode)
{
	#if (MODE == NORMAL_MODE)
		TCCR0_REG->WGM00 = 0;
		TCCR0_REG->WGM01 = 0;
		TCCR0_REG->CS0 = prscaler;
		
	#elif (MODE == PWM_PHASE_CORRECT)
		TCCR0_REG -> FOC0 = 0;
		TCCR0_REG -> WGM01 = 0;
		TCCR0_REG -> WGM00 = 1;
		TCCR0_REG -> COM0 = cmpMode;
		TCCR0_REG -> CS0 = prscaler;
			
	#elif (MODE == CTC)
		TCCR0_REG -> FOC0 = 0;
		TCCR0_REG -> WGM01 = 1;
		TCCR0_REG -> WGM00 = 0;
		TCCR0_REG -> COM0 = cmpMode;
		TCCR0_REG -> CS0 = prscaler;
	
	#elif (MODE == FAST_PWM)
		TCCR0_REG -> FOC0 = 0;
		TCCR0_REG -> WGM01 = 1;
		TCCR0_REG -> WGM00 = 1;
		TCCR0_REG -> COM0 = cmpMode;
		TCCR0_REG -> CS0 = prscaler;
	
	#endif
}


void TMR0_voidStartCount(u8 startValue)
{
	TCNT0 = startValue;
}

void TMR0_voidCompVal(u8 cmpVal)
{
	#if (MODE == PWM_PHASE_CORRECT)
		cmpVal = (((u32)cmpVal * (256)) / 100);
		OCR0 = cmpVal;
	#elif (MODE == FAST_PWM)
		cmpVal = (((u32)cmpVal * (256)) / 100) - 1;
		OCR0 = cmpVal;
	#endif
}

void TMR0_voidInterruptEn()
{
	#if (MODE == NORMAL_MODE)
		SET_BIT(TIMSK, TOIE0);
	#elif (MODE == PWM_PHASE_CORRECT || MODE == CTC || MODE == FAST_PWM)
		SET_BIT(TIMSK, OCIE0);
	#endif
}

void TMR0_callBack(void (*TMR0Ptr)(void))
{
	if (TMR0Ptr != NULL)
	{
		TMR0_gPtr = TMR0Ptr;
	}
}


void __vector_11 (void) __attribute__ ((signal,used));

void __vector_11 (void)
{
	TMR0_gPtr();
}