/*
 * Keypadprogram.c
 *
 * Created: 12-Jun-23 09:47:43 AM
 *  Author: mosta
 */ 
#include "Keypadconfigure.h"

u8 KyPadElmnts[ROW][COL]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
u8 R[ROW]={KEYPADPIN0,KEYPADPIN1,KEYPADPIN2,KEYPADPIN3};
u8 C[COL]={KEYPADC0,KEYPADC1,KEYPADC2,KEYPADC3};

void KEYPAD_voidInitKeypad()
{
	for (int i=0; i < ROW; i++)
	{
		DIO_voidSetPinDirection(KEYPADPORTR, R[i], OUT);
		DIO_voidSetPinValue(KEYPADPORTR, R[i], HIGH);
	}
	for (int i=0; i < COL; i++)
	{
		DIO_voidSetPinDirection(KEYPADPORTC, C[i], IN);
		DIO_voidSetPinValue(KEYPADPORTC, C[i], HIGH);
	}

}



void KEYPAD_voidPressedKeypad(u8 *pressedkey)
{
	u8 readpin=5;
	for (int i=0; i < ROW; i++)
	{
		DIO_voidSetPinValue(KEYPADPORTR, R[i], LOW);
		for (int y=0; y < COL; y++)
		{
			DIO_voidGetPinValue(KEYPADPORTC, C[y], &readpin);
			if (readpin == LOW)
			{
				*pressedkey = KyPadElmnts[i][y];
			}
		}
		DIO_voidSetPinValue(KEYPADPORTR, R[i], HIGH);
	}
}