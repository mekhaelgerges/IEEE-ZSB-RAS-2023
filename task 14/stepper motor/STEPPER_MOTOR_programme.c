      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: STEPPER MOTOR  ******************/
  /**************** Version 2.0   ***********************/
 /******************************************************/
 /*Lib*/
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #define F_CPU 1000000UL
#include<util/delay.h>
 /* MCAL*/
 #include "DIO_interface.h"
 /*HAL*/
 #include "STEPPER_MOTOR_config.h"
 #include"STEPPER_MOTOR_interface.h"
 #include"STEPPER_MOTOR_privet.h"
u8 stepper_motor_init ()
{
	DIO_u8SetPinDirection(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_OUTPUT);
	DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_LOW);
	DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_LOW);
	DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_LOW);
	DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_LOW);

}
u8 STEPPER_MOTOR_u8move(u8 copy_u8direction , u8 copy_u8angle)
 {u8 localErrorState = STD_TYBES_OK;
 u8 local_u8steps=(copy_u8angle*DEGREE_PER_STEP)/360;
 if((0<=copy_u8angle && copy_u8angle<=360) &&(copy_u8direction==STEPPER_MOTOR_CW || copy_u8direction==STEPPER_MOTOR_CCW ))
    {
        if(copy_u8direction==STEPPER_MOTOR_CW)
            {
            for(int count=0;count>=local_u8steps;count++)
                {
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_LOW);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_LOW);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_LOW);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_LOW);
                    _delay_ms(10);
                }
            }
            else if(copy_u8direction==STEPPER_MOTOR_CCW)
            {
            for(int count=0;count>=local_u8steps;count++)
                {
                     DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_LOW);
                    _delay_ms(10);
                      DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_LOW);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_LOW);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN1,DIO_u8_LOW);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN2,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN3,DIO_u8_HIGH);
                    DIO_u8SetpinValue(STEPPER_MOTOR_PORT,STEPPER_MOTOR_PIN4,DIO_u8_HIGH);
                    _delay_ms(10);
                }
                }

    }
 else{localErrorState = STD_TYBES_NOK;}
 return localErrorState; }
