#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer_interface.h"
#include "DIO_interface.h"
#include "GI_interface.h"
#include"LCD_interface.h"
#include "ADC_interface.h"
#define F_CPU  1000000UL
#include <util/delay.h>
//void app_voidTogle(void);

int main ()
{

	u8 local_u8comparematchvalue=0;
	u8 DigitalValue,AnalogValue;
DIO_voidInit();
TIMERS_VoidTimer0Init();

while(1)
{
	ADC_u8GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&DigitalValue);
				AnalogValue = (DigitalValue * 5000UL) / 1024;
	TIMERS_voidTimer0StCompareMatchvalue(AnalogValue);
	_delay_ms(50);
}
return 0;
}
/*void app_voidTogle(void)
{
	static u8 flag=0;




	if(flag==0)
	{
		DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		flag=1;





	}
	else
	{
		DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		flag=0;





	}
}*/


