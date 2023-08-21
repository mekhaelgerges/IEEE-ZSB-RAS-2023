   /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: EXTI_PRIVET_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#ifndef EXTI_PRIVET_H
#define  EXTI_PRIVET_H

#define EXTI_u8_MCUCR       *((volatile u8 *)0x55)
#define EXTI_u8_MCUCSR       *((volatile u8 *)0x54)
#define EXTI_u8_GICR       *((volatile u8 *)0x5B)
#define EXTI_u8_GIFR       *((volatile u8 *)0x5A)
#define ISC0                   0
#define ISC1                   1
#define ISC10                  2
#define ISC11                  3
#define ISC6                   6
#define PIN6                   6
#define PIN7                   7
#define PIN5                   5
#define NUM                    3

#endif
