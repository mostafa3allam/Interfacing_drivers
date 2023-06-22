volatile u8 flag=0;
volatile void ISRI2();

int main(void)
{
	Switch_init(PORT_D,PIN7);
	DIO_voidSetPinDirection(PORT_C,PIN6,OUT);
	DIO_voidSetPinValue(PORT_C,PIN6,LOW);
	u8 read1;
	GIE_voidEnable();
	EXTI1_voidInterruptInit(EXTI1_RISING_EDGE);
	EXTI1_voidInterruptEnable();
	EXTI1_voidCallBack(ISRI2);
    while(1)
    {
		Switch_read(PORT_D,PIN7,&read1);
		if (read1 == LOW)
		{
			flag = 0;
			LCD_voidInit4bit();
			for (u8 i=10; i>0;i--)
			{
				if (flag == 0)
				{
					LCD_voidIntgertoStr(i);
					_delay_ms(1000);
				}
				LCD_voidClrScrn();
			}
			if (flag == 0)
			{
				DIO_voidSetPinValue(PORT_C,PIN6,HIGH);
			}
			else if (flag == 1)
			{
				DIO_voidSetPinValue(PORT_C,PIN6,LOW);
			}
		}
		
        //TODO:: Please write your application code 
    }
}

volatile void ISRI2(void)
{
	flag =1;
	DIO_voidSetPinValue(PORT_C,PIN6,LOW);
}