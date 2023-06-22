/*
 * EXTI0private.h
 *
 * Created: 16-Jun-23 11:16:53 AM
 *  Author: mosta
 */ 


#ifndef EXTI0PRIVATE_H_
#define EXTI0PRIVATE_H_

#include "../../lib/BIT_Math.h"
#include "../../lib/STD_types.h"

#define MCUCR *((volatile u8 *) 0x55)
#define GICR *((volatile u8 *) 0x5b)
#define GIFR *((volatile u8 *) 0x5a)

#define INT0E 6
#define ISC00 0
#define ISC01 1

#define EXTI0_LOW_LEVEL ((CLR_BIT(MCUCR, ISC01))|(CLR_BIT(MCUCR, ISC00)))
#define EXTI0_LOGIC_CHANGE ((CLR_BIT(MCUCR, ISC01))|(SET_BIT(MCUCR, ISC00)))
#define EXTI0_FALLING_EDGE ((SET_BIT(MCUCR, ISC01))|(CLR_BIT(MCUCR, ISC00)))
#define EXTI0_RISING_EDGE ((SET_BIT(MCUCR, ISC01))|(SET_BIT(MCUCR, ISC00)))


#endif /* EXTI0PRIVATE_H_ */