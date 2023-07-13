/*Lib*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#define  F_CPU     1000000UL
#include <util/delay.h>
/*MCAL*/
#include "DIO_interface.h"
#include "DIO_privat.h"

int main(void){
	/*config Pc7 output*/
	DIO_u8setPortDirection(DIO_u8_PORTC,DIO_u8_OUTPUT);
	while(1)
	{

		/*turn on led*/
		DIO_u8SetPortValue  (DIO_u8_PORTC,0xff);
		_delay_ms(500);

		/*turn off led*/
		DIO_u8SetPortValue  (DIO_u8_PORTC,0x00);
			_delay_ms(500);
	}

	return 0;

}


