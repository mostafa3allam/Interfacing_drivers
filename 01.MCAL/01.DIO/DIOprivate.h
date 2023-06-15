/*
 * DIOprivate.h
 *
 * Created: 11-Jun-23 11:31:14 AM
 *  Author: mosta
 */ 


#ifndef DIOPRIVATE_H_
#define DIOPRIVATE_H_

#include "../../lib/BIT_Math.h"
#include "../../lib/STD_types.h"


/************************************************************************/
/* All microcontroller Registers                                        */
/************************************************************************/


/************************************************************************/
/* DIO Registers                                                        */
/************************************************************************/
/*PORT A Registers*/
#define PORTA *((volatile u8 *) 0x3B) /* 8 bit register */
#define DDRA *((volatile u8 *) 0x3A) /* 8 bit register */
#define PINA *((volatile u8 *) 0x39) /* 8 bit register */

/*PORT B Registers*/
#define PORTB *((volatile u8 *) 0x38) /* 8 bit register */
#define DDRB *((volatile u8 *) 0x37) /* 8 bit register */
#define PINB *((volatile u8 *) 0x36) /* 8 bit register */

/*PORT C Registers*/
#define PORTC *((volatile u8 *) 0x35) /* 8 bit register */
#define DDRC *((volatile u8 *) 0x34) /* 8 bit register */
#define PINC *((volatile u8 *) 0x33) /* 8 bit register */

/*PORT D Registers*/
#define PORTD *((volatile u8 *) 0x32) /* 8 bit register */
#define DDRD *((volatile u8 *) 0x31) /* 8 bit register */
#define PIND *((volatile u8 *) 0x30) /* 8 bit register */



#endif /* DIOPRIVATE_H_ */