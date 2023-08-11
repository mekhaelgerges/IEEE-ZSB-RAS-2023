      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#ifndef DIO_INTERFACE_H
#define  DIO_INTERFACE_H
#include "STD_TYPES.h"
#include "DIO_privat.h"
/*macros for ports*/
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3
/*MACROS for pins */
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7

/*MACROS for pindirections */
#define DIO_u8_OUTPUT  1
#define DIO_u8_INPUT  0
/*MACROS for pin values*/
#define DIO_u8_HIGH     1
#define  DIO_u8_LOW    0

void DIO_voidInit(void);

u8 DIO_u8SetPinDirection        (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8pinDirection);

u8 DIO_u8SetpinValue             (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8pinValue);

u8 DIO_u8GetPinValue             (u8 copy_u8portID,u8 copy_u8pinID,u8 * copy_pu8Returnedpinvalue);

u8 DIO_u8setPortDirection       (u8 copy_u8portID,u8 copy_u8PortDirection);

u8 DIO_u8SetPortValue           (u8 copy_u8portID,u8 copy_u8PortValue);

u8 DIO_u8GetPortValue           (u8 copy_u8portID,u8 * copy_pu8ReturenedPortValue);
#endif
