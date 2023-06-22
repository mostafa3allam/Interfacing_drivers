int main(void)
{	
	TMR0_voidCompVal(duty);
	DIO_voidSetPinDirection(PORT_C, PIN6, OUT);
	DIO_voidSetPinDirection(PORT_B, PIN3, OUT);
	TMR0_voidStartCount(0);
	while(1)
	{
		TMR0_voidCompVal(75);
		_delay_ms(1000);
		
		TMR0_voidCompVal(20);
		_delay_ms(1000);
	}
}