#include  "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer_interface.h"
#include "DIO_interface.h"
#include "GI_interface.h"
#include"LCD_interface.h"
void app_voidTogle(void);

int main ()
{
	 u16 count=1;

	DIO_voidInit();
	LCD_voidInit();
	LCD_sendString("count=");
	LCD_voidSendNum(count);
	count++;

	DIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
	/*enable globale interrupt*/
	GI_voidenable();
	/*set call back*/
	TIMER_u8Timer0SetcallBack(&app_voidTogle);
	/*start timer*/
	TIMERS_VoidTimer0Init();
	/*superloop*/
	while(1);


}
void app_voidTogle(void)
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
	}

