      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: EXTI_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#ifndef EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H
#define EXTI_u8_INT0               0
#define EXTI_u8_INT1               1
#define EXTI_u8_INT2               2
/*MACROS FOR EDGE SOURCE*/
#define EXTI_u8_RAISING_EDGE       0
#define EXTI_u8_FALLING_EDGE       1
#define EXTI_u8_LOGICAL_CHANGE     3
#define EXTI_u8_LOW_LEVEL          4


u8 EXTI_u8EXTIEnable(u8 copy_u8EXTIIndex,u8 copy_u8EXTIEdgeIndex);
u8 EXTI_u8EXTIDisable(u8 copy_u8EXTIIndex);
u8 EXTI_u8EXTISetCallBack(u8 copy_u8EXTIIndex,void(*copy_pf)(void));
#endif
