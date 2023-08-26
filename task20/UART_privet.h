/******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: UART_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#ifndef UART_PRIVET_H_
#define UART_PRIVET_H_


#define UART_u8_UBRRH_REG         *((volatile u8*)0X40)
#define UART_u8_UCSRC_REG         *((volatile u8*)0X40)

#define UART_u8_UDR_REG         *((volatile u8*)0X2C)
#define UART_u8_UCSRA_REG         *((volatile u8*)0X2B)
#define UART_u8_UCSRB_REG         *((volatile u8*)0X2A)

#define UART_u8_UBRRL_REG         *((volatile u8*)0X29)


#endif /* UART_PRIVET_H_ */
