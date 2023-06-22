/*
 * EXTI2private.h
 *
 * Created: 16-Jun-23 01:46:01 PM
 *  Author: mosta
 */ 


#ifndef EXTI2PRIVATE_H_
#define EXTI2PRIVATE_H_

#include "../../lib/BIT_Math.h"
#include "../../lib/STD_types.h"

#define MCUCSR *((volatile u8 *) 0x54)
#define GICR *((volatile u8 *) 0x5b)
#define GIFR *((volatile u8 *) 0x5a)

#define INT2E 5
#define ISC2 6

#define FALLING_EDGE CLR_BIT(MCUCSR, ISC2)
#define RISING_EDGE SET_BIT(MCUCSR, ISC2)



#endif /* EXTI2PRIVATE_H_ */