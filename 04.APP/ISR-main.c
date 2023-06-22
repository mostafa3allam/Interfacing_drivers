void ISRINT1(void);
void ISRINT0(void);
u8 onescounter=0,tenscounter=0;

int main(void)
{
	EXTI0_voidInterruptInit(EXTI0_RISING_EDGE);
	EXTI0_voidCallBack(&ISRINT0);
	EXTI0_voidInterruptEnable();
	EXTI1_voidCallBack(&ISRINT1);
	EXTI1_voidInterruptInit(EXTI1_FALLING_EDGE);
	EXTI1_voidInterruptEnable();
	GIE_voidEnable();
	while(1)
    {
		
        //TODO:: Please write your application code 
    }
}

void ISRINT1(void)
{
	/*body*/
	SSEG_Init();
	SECSSEG_Init();
	onescounter++;
	if (onescounter == 10)
	{
		onescounter=0;
		tenscounter++;
		if (tenscounter == 10)
		{
			tenscounter=0;
		}
	}
	SSEG_Display(tenscounter);
	SECSSEG_Display(onescounter);
	_delay_ms(200);
}


void ISRINT0(void)
{
	tenscounter=0;
	onescounter=0;
	SSEG_Display(tenscounter);
	SECSSEG_Display(onescounter);
	_delay_ms(200);
}