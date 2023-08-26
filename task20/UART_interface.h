/******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: UART_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
void UART_voidInit(void);
void UART_voidSendByte(u8 copy_u8dataByte);

u8 UART_u8RecieveByte(u8 * Copy_pu8RecByte);
u8 UART_Sendchar(u8 * Copy_u8String);



#endif /* UART_INTERFACE_H_ */
