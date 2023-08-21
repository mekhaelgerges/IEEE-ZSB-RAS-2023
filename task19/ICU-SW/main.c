#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_config.h"
#include"DIO_interface.h"
#include "EXTI_interface.h"
#include"GI_interface.h"
#include"timer_privet.h"
#include"LCD_interface.h"
void ICU_SW(void);
volatile static u16 period_ticks=0;
volatile static u16 on_ticks=0;

int main()
{
	DIO_voidInit();
	EXTI_u8EXTIEnable(EXTI_u8_INT1,EXTI_u8_RAISING_EDGE);
	EXTI_u8EXTISetCallBack(EXTI_u8_INT1,&ICU_SW);
	LCD_voidInit();
	TIMERS_VoidTimer0Init();
	TIMERS_VoidTimer1Init();
	GI_voidenable();
	while(1)
	{
		while((period_ticks==0)&&(on_ticks==0))
		{
			LCD_u8GoToXY(0,1);
			LCD_sendString("period ticks =");
			LCD_voidSendNum(period_ticks);
		}


	}
}
void ICU_SW(void)
{
	static u8 local_u8counter=0;
	local_u8counter++;
	if(local_u8counter==1)
	{
		TIMERS_voidTimer0StCompareMatchvalue(0);

	}
	else if(local_u8counter==2)
	{
		period_ticks=TIMER1_u16ReadTimerValue();

		EXTI_u8EXTIEnable(EXTI_u8_INT1,EXTI_u8_FALLING_EDGE);
	}
	else if(local_u8counter==3)
	{
		on_ticks=TIMER1_u16ReadTimerValue();
		on_ticks=period_ticks;
		EXTI_u8EXTIDisable();

	}
}
