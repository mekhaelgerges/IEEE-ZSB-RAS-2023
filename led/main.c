/*Lib*/

#include "STD_TYPES.h"
#include "BIT_Math.h"
#include <util/delay.h>
/*MCAL*/
#include "DIO_interface.h"

int main(void)
{
	/*config Pc7 output*/
	DIO_voidInit();

	while(1)
	{
		/*turn on led*/
		DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_HIGH);
		_delay_ms(500);

		/*turn off led*/
			DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_LOW);
			_delay_ms(500);
	}

	return 0;

}


