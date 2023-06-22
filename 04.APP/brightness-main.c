int main(void)
{
	ADC_voidInit(AVCC, SINGLE_ADC0, DIV_BY_128);
	LCD_voidInit4bit();
	u16 adc_read;
	ADC_voidAutoTrig();
	u8 duty;
	TMR0_voidInit(PRESCALER_1024, FPWM_CLR_OC);
	
	DIO_voidSetPinDirection(PORT_C, PIN6, OUT);
	DIO_voidSetPinDirection(PORT_B, PIN3, OUT);
	TMR0_voidStartCount(0);
    while(1)
    {
		LCD_voidClrScrn();
		ADC_voidStartConv();
		ADC_voidReadRes(&adc_read);
		adc_read = (adc_read * 100) / 1023;
		LCD_voidIntgertoStr(adc_read);
		TMR0_voidCompVal(adc_read);
		_delay_ms(100);
        //TODO:: Please write your application code 
    }
}