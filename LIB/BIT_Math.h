/*
 * BIT_Math.h
 *
 * Created: 11-Jun-23 11:09:55 AM
 *  Author: mosta
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT) (REG |= (1<<BIT)) /*set any bit in register*/
#define CLR_BIT(REG,BIT) (REG &= (~(1<<BIT))) /*clear in bit in register*/
#define SV_BIT(REG,BIT) (REG & (1<<BIT))
#define TOG_BIT(REG,BIT) (REG ^= (1<<BIT)) /*TOGGLE ANY BIT*/
#define isBITSET(REG,BIT) (REG & (1<<BIT)) /*CHECK IF BIT IS SET, USED WITH IF STATEMENT*/
#define isBITCLR(REG,BIT) (!(REG & (1<<BIT))) /*CHECK IF BIT IS CLEARED, USED WITH IF STATEMENT*/ 
#define ROR(REG,BIT) (REG = (REG>>BIT) | (REG<<8-BIT)) /*ROTATE register RIGHT BY NO. OF BIT*/
#define ROL(REG,BIT) (REG = (REG<<BIT) | (REG<<8-BIT)) /*ROTATE register LEFT BY NO. OF BIT*/
#define SET_REG(REG) (REG |= 0xff)
#define CLR_REG(REG) (REG &= 0x00)
#define CPY_DATA(REG,VALUE) (REG = VALUE)
#define CPY_1ST_HAF(REG,VALUE) (REG = VALUE | (REG & 0xf0))
#define CPY_2ND_HAF(REG,VALUE) (REG = (VALUE << 4) | (REG & 0x0f))

#endif /* BIT_MATH_H_ */