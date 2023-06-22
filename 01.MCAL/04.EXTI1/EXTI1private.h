/*
 * EXTI0private.h
 *
 * Created: 16-Jun-23 11:45:38 AM
 *  Author: mosta
 */ 


#ifndef EXTI1PRIVATE_H_
#define EXTI1PRIVATE_H_

#include "../../lib/BIT_Math.h"
#include "../../lib/STD_types.h"

#define MCUCR *((volatile u8 *) 0x55)
#define GICR *((volatile u8 *) 0x5b)
#define GIFR *((volatile u8 *) 0x5a)

#define INT1E 7
#define ISC10 2
#define ISC11 3

#define EXTI1_LOW_LEVEL ((CLR_BIT(MCUCR, ISC11))|(CLR_BIT(MCUCR, ISC10)))
#define EXTI1_LOGIC_CHANGE ((CLR_BIT(MCUCR, ISC11))|(SET_BIT(MCUCR, ISC10)))
#define EXTI1_FALLING_EDGE ((SET_BIT(MCUCR, ISC11))|(CLR_BIT(MCUCR, ISC10)))
#define EXTI1_RISING_EDGE ((SET_BIT(MCUCR, ISC11))|(SET_BIT(MCUCR, ISC10)))



#endif /* EXTI1PRIVATE_H_ */