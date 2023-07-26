 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
#define F_CPU  1000000UL
#include <util/delay.h>
 /* MCAL*/
 #include "DIO_interface.h"
/*HAL*/
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "DC_MOTOR_interface.h"

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
	 		 LCD_sendString("1dc motor 3exist");
	 		 LCD_u8GoToXY(2,0);
	 		 LCD_sendString("2stepper motor");
	 		while(1){
	 	 		KPD_u8GetKeyState(&Local_u8Key);
	 	 		if(Local_u8Key !=  KPD_KEY_NOT_PRESSED )
	 	 					 {
	 	 						if(Local_u8Key=='1')
	 	 						{LCD_voidInit();
	 	 						 LCD_sendString("1 CW");
	 	 						 LCD_u8GoToXY(2,0);
	 	 						 LCD_sendString("2 CCW");
	 	 				 		 while(1)
	 	 				 		 {
	 	 				 			KPD_u8GetKeyState(&Local_u8Key);
	 	 				 				 		if(Local_u8Key !=  KPD_KEY_NOT_PRESSED )
	 	 				 				 		{
	 	 				 				 			if(Local_u8Key=='1')
	 	 				 				 			{
	 	 				 				 				DC_MOTOR_u8rotatedirection(DC_MOTOR_FORWARD);
	 	 				 				 				break;
	 	 				 				 			}
	 	 				 				 			else if(Local_u8Key=='2')
	 	 				 				 			{
	 	 				 				 				DC_MOTOR_u8rotatedirection(DC_MOTOR_REVERSE);
	 	 				 				 				break;
	 	 				 				 			}
	 	 				 				 		}
	 	 				 		 }

	 	 	}
	 	 		else if(Local_u8Key=='2')
	 	 		{
	 	 			LCD_voidInit();
	 	 		 LCD_sendString("1 CW");
	 	 		 LCD_u8GoToXY(2,0);
	 	 		 LCD_sendString("2 CCW");
	 	 				 	 					 while(1)
	 	 				 	 						 	 				 		 {
	 	 				 	 						 	 				 			KPD_u8GetKeyState(&Local_u8Key);
	 	 				 	 						 	 				 				 		if(Local_u8Key !=  KPD_KEY_NOT_PRESSED )
	 	 				 	 						 	 				 				 		{
	 	 				 	 						 	 				 				 			if(Local_u8Key=='1')
	 	 				 	 						 	 				 				 			{LCD_voidInit();
	 	 				 	 						 	 				 				 				LCD_sendString("1-90 2-180 3-270");
	 	 				 	 						 	 				 				 				LCD_u8GoToXY(2,0);
	 	 				 	 						 	 				 				 				LCD_sendString("4-360");
	 	 				 	 						 	 				 				 		 while(1)
	 	 				 	 						 	 				 				 			 	 				 		 {
	 	 				 	 						 	 				 				 			 	 				 			KPD_u8GetKeyState(&Local_u8Key);
	 	 				 	 						 	 				 				 			 	 				 				 		if(Local_u8Key !=  KPD_KEY_NOT_PRESSED )
	 	 				 	 						 	 				 				 			 	 				 				 		{
	 	 				 	 						 	 				 				 			 	 				 				 			if(Local_u8Key=='1')
	 	 				 	 						 	 				 				 			 	 				 				 			{
	 	 				 	 						 	 				 				 			 	 				 				 				DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 				 				_delay_ms(200);
	 	 				 	 						 	 				 				 			 	 				 				 	            DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 				 				break;
	 	 				 	 						 	 				 				 			 	 				 				 			}
	 	 				 	 						 	 				 				 			 	 				 				 			else if(Local_u8Key=='2')
	 	 				 	 						 	 				 				 			 	 				 				 			{


	 	 				 	 						 	 				 				 			 	 				 			                    DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);





	 	 				 	 						 	 				 				 			 	 				 				 				break;
	 	 				 	 						 	 				 				 			 	 				 				 			}
	 	 				 	 						 	 				 				 			 	 				 				 			else if(Local_u8Key=='3')
	 	 				 	 						 	 				 				 			 	 				 				 			{

	 	 				 	 						 	 				 				 			 	 				 			                    DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 			                    DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 			                   _delay_ms(2000);
	 	 				 	 						 	 				 				 			 	 				 			                   DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_LOW);
	 	 				 	 						 	 				 				 			 	 				 			                   DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);


	 	 				 	 						 	 				 				 			 	 				 				 				break;
	 	 				 	 						 	 				 				 			 	 				 				 			}
	 	 				 	 						 	 				 				 			 	 				 				           else if(Local_u8Key=='4')
	 	 				 	 						 	 				 				 			 	 				 				           {
	 	 				 	 						 	 				 				 			 	 				 				        	   DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
	 				 	 						 	 				 				 			 	 				 			                       DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
	 				 	 						 	 				 				 			 	 				 			                       _delay_ms(2000);
	 	 				 	 						 	 				 				 			 	 				 			                    DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 			                   _delay_ms(200);
	 	 				 	 						 	 				 				 			 	 				 			                    DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_LOW);
	 	 				 	 						 	 				 				 			 	 				 			                    DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 			                    _delay_ms(2000);
	 	 				 	 						 	 				 				 			 	 				 			                     DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 			                     DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_LOW);
	 	 				 	 						 	 				 				 			 	 				 			                     break;



	 	 				 	 						 	 				 				 			 	 				 				           }


	 	 				 	 						 	 				 				 			 	 				 				 		}
	 	 				 	 						 	 				 				 			 	 				 		 }

	 	 				 	 						 	 				 				 				break;
	 	 				 	 						 	 				 				 			}
	 	 				 	 						 	 				 				 			else if(Local_u8Key=='2')
	 	 				 	 						 	 				 				 			{LCD_voidInit();
	 	 				 	 						 	 				 				 		       LCD_sendString("1-90 2-180 3-270");
	 	 				 	 						 	 				 				 		       LCD_u8GoToXY(2,0);
	 	 				 	 						 	 				 				 		       LCD_sendString("4-360");
	 	 				 	 						 	 				 				 		 while(1)
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 				 		 {
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 				 			KPD_u8GetKeyState(&Local_u8Key);
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 				 				 		if(Local_u8Key !=  KPD_KEY_NOT_PRESSED )
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 				 				 		{if(Local_u8Key=='1')
	 	 				 	 						 	 				 					 	 				 	 						 	 				 				 			 	 				 				 			    {
	 	 				 	 						 	 				 					 	 				 	 						 	 				 				 			 	 				 				 				DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
	 	 				 	 						 	 				 					 	 				 	 						 	 				 				 			 	 				 				 				_delay_ms(200);
	 	 				 	 						 	 				 					 	 				 	 						 	 				 				 			 	 				 				 	            DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
	 	 				 	 						 	 				 					 	 				 	 						 	 				 				 			 	 				 				 				break;
	 	 				 	 						 	 				 					 	 				 	 						 	 				 				 			 	 				 				 			    }
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 				 		        else if(Local_u8Key=='2')
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 				 		{DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 		                 DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 		                 break;
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 				 		}
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 		                        else if(Local_u8Key=='3')
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 		                        {DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                         DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                         _delay_ms(2000);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                         DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_LOW);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                         DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_HIGH);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                         break;
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 		                        }
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 		                       else if(Local_u8Key=='4')
	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 		                       {DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);
	 	 				 	 						 	 				 		 				 	 						 	 				 				 			 	 				 			                            DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
	 	 				 	 						 	 				 		 				 	 						 	 				 				 			 	 				 			                            _delay_ms(2000);
	 	 				 	 						 	 				 		 				 	 						 	 				 				 			 	 				 			                             DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_HIGH);
	 	 				 	 						 	 				 		 				 	 						 	 				 				 			 	 				 			                             _delay_ms(200);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                         DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_LOW);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                          DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN2,DIO_u8_HIGH);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                          _delay_ms(2000);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                     DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN5,DIO_u8_HIGH);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                     DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN3,DIO_u8_LOW);
	 	 				 	 						 	 				 		 	 				 	 						 	 				 				 			 	 				 			                     break;


	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 		                       }

	 	 				 	 						 	 				 				 			 	 				 	 						 	 				 				 			 	 				 				 		}}

	 	 				 	 						 	 				 				 		       break;
	 	 				 	 						 	 				 				 			}
	 	 				 	 						 	 				 				 		}
	 	 				 	 						 	 				 		 }
	 	 		}

	 		}}}
	 else
		 	 {      LCD_voidInit();
		 		 		         LCD_sendString("incorrect password");
		 		 		 		 break;}}}







