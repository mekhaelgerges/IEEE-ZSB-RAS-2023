/******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: KPD  ****************************/
  /**************** Version 2.0   ***********************/
 /******************************************************/
 #ifndef KDP_CONFIG_H
 #define KDP_CONFIG_H

 #define KDP_u8_PORT     DIO_u8_PORTA

 #define KDP_u8_R1_PIN   DIO_u8_PIN0
 #define KDP_u8_R2_PIN   DIO_u8_PIN1
 #define KDP_u8_R3_PIN   DIO_u8_PIN2
 #define KDP_u8_R4_PIN   DIO_u8_PIN3

 #define KDP_u8_C1_PIN   DIO_u8_PIN4
 #define KDP_u8_C2_PIN   DIO_u8_PIN5
 #define KDP_u8_C3_PIN   DIO_u8_PIN6
 #define KDP_u8_C4_PIN   DIO_u8_PIN7

 #define KPD_KEYS    {{'1','2','3','/'},   \
                      {'4','5','6','*'},    \
                      {'7','8','9','-'},     \
                      {'on','0','=','+'}}

 #endif // KDP_CONFIG_H
