
      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: KPD  ****************************/
  /**************** Version 2.0   ***********************/
 /******************************************************/
 /*Lib*/
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
#define F_CPU 8000000UL
#include<util/delay.h>

 /* MCAL*/
 #include "DIO_interface.h"
 /*HAL*/
 #include "KPD_config.h"
 #include"KPD_interface.h"
 #include"KPD_private.h"
const u8 KPD_Au8Keys[4][4]=KPD_KEYS;

const u8 KDP_Au8RowsPins[4]={KDP_u8_R1_PIN,KDP_u8_R2_PIN,KDP_u8_R3_PIN,KDP_u8_R4_PIN};
const u8 KDP_Au8ColsPins[4]={KDP_u8_C1_PIN,KDP_u8_C2_PIN,KDP_u8_C3_PIN,KDP_u8_C4_PIN};

u8 KPD_u8GetKeyState(u8* copy_pu8ReturnedKey)
{u8 localErrorState = STD_TYBES_OK;
 u8 local_u8RowsCounter,local_u8ColsCounter,Local_u8PinValue,Local_u8Flag=0;
 if(copy_pu8ReturnedKey!=NULL)
 {
	 *copy_pu8ReturnedKey = KPD_KEY_NOT_PRESSED;
     /*Activate Each row =>For loop on the pin of the rows*/
     for(local_u8RowsCounter=0;local_u8RowsCounter<=3;local_u8RowsCounter++)
     {
         DIO_u8SetpinValue(KDP_u8_PORT,KDP_Au8RowsPins[local_u8RowsCounter],DIO_u8_LOW);
         /*Check Which input pins Has a zero*/
         for(local_u8ColsCounter=0;local_u8ColsCounter<=3;local_u8ColsCounter++)
         {
         DIO_u8GetPinValue(KDP_u8_PORT,KDP_Au8ColsPins[local_u8ColsCounter],&Local_u8PinValue);
             if(Local_u8PinValue==DIO_u8_LOW)/*Switch is pressed*/
                  {
                /*Debouncing*/
            _delay_ms(20);
            DIO_u8GetPinValue(KDP_u8_PORT,KDP_Au8ColsPins[local_u8ColsCounter],&Local_u8PinValue);
            /*CHEACK if the pin is still equal low*/
            while(Local_u8PinValue==DIO_u8_LOW)
            {
                DIO_u8GetPinValue(KDP_u8_PORT,KDP_Au8ColsPins[local_u8ColsCounter],&Local_u8PinValue);
            }
            *copy_pu8ReturnedKey=KPD_Au8Keys[local_u8RowsCounter][local_u8ColsCounter];
            Local_u8Flag=1;
            break;

                   }

            }
                 DIO_u8SetpinValue(KDP_u8_PORT,KDP_Au8RowsPins[local_u8RowsCounter],DIO_u8_HIGH);
                       if(Local_u8Flag==1)
                         {
                         	 break;
                          }
     }
}
 else{u8 localErrorState = STD_TYBES_NOK;}
}
