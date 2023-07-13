      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
 #ifndef LCD_CONFIG_H
 #define LCD_CONFIG_H
 /*OPTION : 1- DIO_u8_PORTA
            2- DIO_u8_PORTB
            1- DIO_u8_PORTC
            1- DIO_u8_PORTD*/

 #define LCD_u8_control_PORT     DIO_u8_PORTA
 #define LCD_u8_RS_PIN           DIO_u8_PIN0
 #define LCD_u8_RW_PIN           DIO_u8_PIN1
 #define LCD_u8_E_PIN            DIO_u8_PIN2

 #define LCD_u8_DATA_PORT        DIO_u8_PORTD
 #endif // LCD_CONFIG_H
