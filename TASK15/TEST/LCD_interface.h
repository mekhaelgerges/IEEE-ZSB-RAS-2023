      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/


 #ifndef LCD_INTERFACE_H
 #define LCD_INTERFACE_H
 #define LCD_u8_LINE1   1
 #define LCD_u8_LINE2   2



 void LCD_voidInit(void);
void LCD_voidSendCmnd(u8 copy_u8cmnd);

void LCD_voidSendChar(u8 copy_u8Char);

u8 LCD_u8GoToXY (u8 COPY_u8LineNum,u8 Copy_u8location);

void LCD_sendString(const char *str);
#endif // LCD_INTERFACE_H
