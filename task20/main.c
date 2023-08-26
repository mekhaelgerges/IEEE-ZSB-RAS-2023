#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "UART_interface.h"

int main ()
{
	u8 local_u8Date;
	DIO_voidInit();
	UART_voidInit();



	while(1)
	{
		UART_Sendchar("a/b/c/s");

		UART_u8RecieveByte(&local_u8Date);
		if(local_u8Date == 'a')
		{
			DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		else if(local_u8Date == 'b')
		{
			DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
		}
		else if(local_u8Date == 'c')
				{
					DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
				}
		else if(local_u8Date == 's')
						{

			                DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
			                DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
							DIO_u8SetpinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
						}

	}

	return 0;
}
