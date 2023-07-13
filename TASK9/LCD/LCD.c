#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LCD_interface.h"
int main ()
{DIO_voidInit();
LCD_voidInit();

LCD_u8GoToXY(LCD_u8_LINE1,5);
LCD_voidSendChar('H');
LCD_voidSendChar('E');
LCD_voidSendChar('L');
LCD_voidSendChar('L');
LCD_voidSendChar('O');
LCD_voidSendChar(' ');
LCD_voidSendChar('W');
LCD_voidSendChar('O');
LCD_voidSendChar('R');
LCD_voidSendChar('L');
LCD_voidSendChar('D');


while(1);

	}

