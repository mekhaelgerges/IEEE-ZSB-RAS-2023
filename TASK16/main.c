 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
#include <util/delay.h>
#define F_CPU  1000000UL
 /* MCAL*/
 #include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"
/*HAL*/
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "DC_MOTOR_interface.h"
#include "timer_interface.h"

#define   SREG      *((volatile u8 *)0x5F)

void security (void);
int main()
{

while(1){
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetpinValue(DIO_u8_PORTD,DIO_u8_PIN0,DIO_u8_HIGH);
	DIO_voidInit();
	GI_voidenable();
	SET_BIT(SREG,7);
	DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_INPUT);
	EXTI_u8EXTIEnable(EXTI_u8_INT1,EXTI_u8_RAISING_EDGE);

	EXTI_u8EXTISetCallBack(EXTI_u8_INT1,&security);


    }

}
void security ()
{
	u8 passcode[3]={'1','2','3','4'};

	u8 z,i;
	u8 Local_u8Key;
	DIO_voidInit();
	LCD_voidInit();

	while(1)
	{LCD_u8GoToXY(2,1);
	i=4;



	 if (i>=4)
	 	 {
		 LCD_voidInit();
	 		 LCD_sendString("1dc 3servo 4exist");
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
	 	 				 	 						 	 				 				 			 	 				 			                    DIO_u8SetpinValue(DIO_u8_PORTC,DIO_u8_PIN4,DIO_u8_HIGH);





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
	 	 		else if(Local_u8Key=='3')
	 	 		{
	 	 			LCD_voidInit();
	 	 			LCD_sendString("ANGLE =");
	 	 			LCD_u8GoToXY(2,0);
	 	 			LCD_sendString("1-45 2-90 3-135");
	 	 			while(1){
	 	 				KPD_u8GetKeyState(&Local_u8Key);
	 	 						 if(Local_u8Key !=  KPD_KEY_NOT_PRESSED )
	 	 						 {
	 	 							 if (Local_u8Key=='1')
	 	 							 {LCD_voidInit();
	 	 			LCD_sendString("servo motor");
	 	 			while(1)
	 	 			{
	 	 				TIMERS_VoidTimer1Init();
	 	 				TIMERS_voidservo(45);
	 	 			}
	 	 							 }
	 	 							 else if (Local_u8Key=='2')

	 	 									 	 								 	 							{LCD_voidInit();
	 	 									 	 								 	 								 	 			LCD_sendString("servo motor");
	 	 									 	 								 	 								 	 			while(1)
	 	 									 	 								 	 								 	 			{
	 	 									 	 								 	 								 	 				TIMERS_VoidTimer1Init();
	 	 									 	 								 	 								 	 				TIMERS_voidservo(90);
	 	 									 	 								 	 								 	 			}
	 	 									 	 								 	 						 }
	 								 else if (Local_u8Key=='3')

	 		 	 									 	 								 	 							{LCD_voidInit();
	 		 	 									 	 								 	 								 	 			LCD_sendString("servo motor");
	 		 	 									 	 								 	 								 	 			while(1)
	 		 	 									 	 								 	 								 	 			{
	 		 	 									 	 								 	 								 	 				TIMERS_VoidTimer1Init();
	 		 	 									 	 								 	 								 	 				TIMERS_voidservo(135);
	 		 	 									 	 								 	 								 	 			}
	 		 	 									 	 								 	 						 }

	 	 						 }
	 	 			}}
	 		}}}
	 else
		 	 {      LCD_voidInit();
		 		 		         LCD_sendString("incorrect password");
		 		 		 		 break;}}}







