#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU_1000000UL
#include "util/delay.h"
#include "DIO_interface.h"
#include"LCD_interface.h"
int main ()
{
 DIO_voidInit();

	DIO_u8SetPinDirection (DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_INPUT);
LCD_voidInit();

LCD_voidSendCmnd(0B01000000);

LCD_voidSendChar(0b00000100);
LCD_voidSendChar(0B00000100);
LCD_voidSendChar(0B00001110);
LCD_voidSendChar(0B00010101);
LCD_voidSendChar(0B00001110);
LCD_voidSendChar(0B00010101);
LCD_voidSendChar(0B00010001);
LCD_voidSendChar(0B00000000);

LCD_voidSendCmnd(0b01010000);

LCD_voidSendChar(0B00001100);
LCD_voidSendChar(0B00011110);
LCD_voidSendChar(0B00011111);
LCD_voidSendChar(0B00011111);
LCD_voidSendChar(0B00001110);
LCD_voidSendChar(0B00000110);
LCD_voidSendChar(0B00010001);
LCD_voidSendChar(0B00011111);



u8 copy_u8_Returnedpinvalue;
u8 copy_u8_Returnedpinvalue1;
LCD_u8GoToXY(LCD_u8_LINE1,0);
int counter;
while(1)
{

	DIO_u8GetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,&copy_u8_Returnedpinvalue);
DIO_u8GetPinValue(DIO_u8_PORTC,DIO_u8_PIN1,&copy_u8_Returnedpinvalue1);
_delay_ms(25);
	if(copy_u8_Returnedpinvalue)
	{

       counter++;
		LCD_voidSendChar(0);
		_delay_ms(500);
	}

	else if(copy_u8_Returnedpinvalue1)
	{

		counter++;
	LCD_voidSendChar(2);
	_delay_ms(500);}

	if(counter==13)
	{
		LCD_u8GoToXY(LCD_u8_LINE2,0);
	_delay_ms(200);
	}
	else if (counter>34)
	{
		LCD_voidSendCmnd(0x01);
		counter=0;
		_delay_ms(100);
	}
}}




