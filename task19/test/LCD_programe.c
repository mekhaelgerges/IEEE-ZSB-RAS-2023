      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 2.0   ***********************/
 /******************************************************/
 /*Lib*/
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #define F_CPU 1000000UL
 #include <util/delay.h>
 /* MCAL*/
 #include "DIO_interface.h"
 /*HAL*/
 #include "LCD_config.h"
 #include"LCD_interface.h"
 #include"LCD_private.h"

  void LCD_voidInit(void)
  {
       _delay_ms(35);
       /*FUNCTION SET CMND*/
       LCD_voidSendCmnd(0B00111000);
       _delay_us(40);
       LCD_voidSendCmnd(0b00001111);
       _delay_us(40);
       LCD_voidSendCmnd(0x01);
       _delay_us(5);
       LCD_voidSendCmnd(0B00000110);


   }


 void LCD_voidSendCmnd(u8 copy_u8Cmnd)
 {
#if LCD_u8_MODE==LCD_u8_MODE_8_BIT
     /*step1 Rs=0*/
	 DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
     /*Rw=0*/
	 DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
     /*write comand*/
     DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Cmnd);
     /*E=1*/
     DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
     _delay_us(1);
     /*E=0*/
     DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
#elif LCD_u8_MODE==LCD_u8_MODE_4_BIT
	     /*step1 Rs=1*/
	      DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	    /*Rw=0*/
	   	  DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
       /*write comand*/
	  DIO_u8SetPortValue(LCD_u8_DATA_PORT, copy_u8Cmnd);
	  /*E=1*/
        DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
          _delay_us(1);
	  /*E=0*/
	     	     DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	     	    /*write comand*/
	     	    DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Cmnd <<4);
	     	   /*E=1*/
	     	    DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	     	  	 _delay_us(1);
	     	  /*E=0*/
	  DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
#endif


 }
 void LCD_voidSendChar(u8 copy_u8Char)
 {
#if LCD_u8_MODE==LCD_u8_MODE_8_BIT
	 /*step1 Rs=1*/
		 DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	     /*Rw=0*/
		 DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	     /*write comand*/
	     DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Char);
	     /*E=1*/
	     DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	     _delay_us(1);
	     /*E=0*/
	     DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_LOW);

#elif LCD_u8_MODE==LCD_u8_MODE_4_BIT
	     /*step1 Rs=1*/
	     		 DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	     	     /*Rw=0*/
	     		 DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	     	     /*write comand*/
	     	     DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Char);
	     	     /*E=1*/
	     	     DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	     	     _delay_us(1);
	     	     /*E=0*/
	     	     DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	     	    DIO_u8SetPortValue(LCD_u8_DATA_PORT,copy_u8Char <<4);
	     	   /*E=1*/
	     	    DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	     	  	 _delay_us(1);
	   	     /*E=0*/
	        	 DIO_u8SetpinValue(LCD_u8_control_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
#endif
 }

 u8 LCD_u8GoToXY(u8 COPY_u8LineNum,u8 Copy_u8location)
 {
     u8 local_u8Errorstate=STD_TYBES_OK;
     if(COPY_u8LineNum<=39){
     switch(COPY_u8LineNum)
     {
         case LCD_u8_LINE1: LCD_voidSendCmnd(0x80+Copy_u8location);  break;
         case LCD_u8_LINE2: LCD_voidSendCmnd(0xC0+Copy_u8location);  break;
         default :  local_u8Errorstate=STD_TYBES_OK;
     }
 }
 else { local_u8Errorstate=STD_TYBES_OK;}
 return local_u8Errorstate;}
 void LCD_sendString(const char *str)
 {
 	u8 i = 0;
 	while (str[i] != '\0')
 	{
 		LCD_voidSendChar(str[i]);
 		i++;
 	}}
void LCD_voidSendNum(u16 LCD_u8Num)
 {u8 len=0;
   u16  rem;
   u16 n,count;
    n=LCD_u8Num;
   char *str;
 while(n!=0)
 {
	 len++;
	 n/=10;
 }
 for(count =0;count<len;count++)
 {
	 rem=LCD_u8Num % 10;
	 LCD_u8Num/=10;
	 str[len-(count+1)] = rem + '0';
 }
 str[len] = '\0';
 LCD_sendString(str);
 }









