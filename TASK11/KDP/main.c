 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 /* MCAL*/
 #include "DIO_interface.h"
/*HAL*/
#include "LCD_interface.h"
#include "KPD_interface.h"

int main(void)
{
	u8 passcode[3]={'1','2','3','4'};

	u8 z,i;
	u8 Local_u8Key;
	DIO_voidInit();
	LCD_voidInit();
	                     LCD_voidSendChar('E');
	                     LCD_voidSendChar('N');
	                     LCD_voidSendChar('T');
	                     LCD_voidSendChar('E');
	                     LCD_voidSendChar('R');
	                     LCD_voidSendChar(' ');
	                     LCD_voidSendChar('P');
		 		 		 LCD_voidSendChar('A');
		 		 		 LCD_voidSendChar('S');
		 		 		 LCD_voidSendChar('S');
		 		 		 LCD_voidSendChar('W');
		 		 		 LCD_voidSendChar('O');
		 		 		 LCD_voidSendChar('R');
		 		 		 LCD_voidSendChar('D');
	while(1)
	{LCD_u8GoToXY(2,1);


	 while (i<4)
	 {
		     KPD_u8GetKeyState(&Local_u8Key);
			 if(Local_u8Key !=  KPD_KEY_NOT_PRESSED )
			 {
				 LCD_voidSendChar(Local_u8Key);
				 if(passcode[i] == Local_u8Key){
				 i++;}
				 else{break;}
			 }

	 }
	 if (i>=4)
	 	 {
		 LCD_voidInit();
	 		 LCD_voidSendChar('C');
	 		 LCD_voidSendChar('O');
	 		 LCD_voidSendChar('R');
	 		 LCD_voidSendChar('R');
	 		 LCD_voidSendChar('E');
	 		 LCD_voidSendChar('C');
	 		 LCD_voidSendChar('T');
	 		 LCD_voidSendChar(' ');
	 		 LCD_voidSendChar('P');
	 		 LCD_voidSendChar('A');
	 		 LCD_voidSendChar('S');
	 		 LCD_voidSendChar('S');
	 		 LCD_voidSendChar('W');
	 		 LCD_voidSendChar('O');
	 		 LCD_voidSendChar('R');
	 		 LCD_voidSendChar('D');
	 		 break;
	 	 }
	 	 else
	 	 {      LCD_voidInit();
	 		         LCD_voidSendChar('i');
	 				 LCD_voidSendChar('n');
	 		         LCD_voidSendChar('C');
	 		 		 LCD_voidSendChar('O');
	 		 		 LCD_voidSendChar('R');
	 		 		 LCD_voidSendChar('R');
	 		 		 LCD_voidSendChar('E');
	 		 		 LCD_voidSendChar('C');
	 		 		 LCD_voidSendChar('T');
	 		 		 LCD_voidSendChar(' ');
	 		 		 LCD_voidSendChar('P');
	 		 		 LCD_voidSendChar('A');
	 		 		 LCD_voidSendChar('S');
	 		 		 LCD_voidSendChar('S');
	 		 		 LCD_voidSendChar('W');
	 		 		 LCD_voidSendChar('O');
	 		 		 LCD_voidSendChar('R');
	 		 		 LCD_voidSendChar('D');
	 		 		 break;
	 	 }


	}
}
