      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DC MOTOR  ***********************/
  /**************** Version 2.0   ***********************/
 /******************************************************/
 /*Lib*/
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #define F_CPU 1000000UL

 /* MCAL*/
 #include "DIO_interface.h"
 /*HAL*/
 #include "DC_MOTOR_config.h"
 #include"DC_MOTOR_interface.h"
 #include"DC_MOTOR_privat.h"
u8 DC_MOTOR_u8rotatedirection(u8 copy_u8direction)
{u8 local_u8ErrorState = STD_TYBES_OK;
if (copy_u8direction==DC_MOTOR_FORWARD)
    {
       DIO_u8SetpinValue(DC_MOTOR_PORT,DC_MOTOR_IN1,DIO_u8_HIGH);
       DIO_u8SetpinValue(DC_MOTOR_PORT,DC_MOTOR_IN2,DIO_u8_LOW);
       _delay_ms(200);
    }
else if (copy_u8direction==DC_MOTOR_REVERSE)
    {
        DIO_u8SetpinValue(DC_MOTOR_PORT,DC_MOTOR_IN1,DIO_u8_LOW);
       DIO_u8SetpinValue(DC_MOTOR_PORT,DC_MOTOR_IN2,DIO_u8_HIGH);
       _delay_ms(200);
    }
else{u8 local_u8ErrorState = STD_TYBES_NOK;}
}
