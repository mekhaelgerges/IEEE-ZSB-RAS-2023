      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: EXTI_programme ******************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
 /*Lib*/
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "EXTI_interface.h"
#include "EXTI_ privet.h"
#include "EXTI_ config.h"
static void(*EXTI_ApfEXTI[NUM])(void)={NULL,NULL,NULL};

 u8 EXTI_u8EXTIEnable(u8 copy_u8EXTIIndex,u8 copy_u8EXTIEdgeIndex)
 {
     u8 Local_u8ErrorState =STD_TYBES_OK;
     switch(copy_u8EXTIIndex)
     {
     case EXTI_u8_INT0:
        switch(copy_u8EXTIEdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,ISC1);
            SET_BIT(EXTI_u8_MCUCR,ISC0);
            SET_BIT(EXTI_u8_GICR,PIN6);
            break;
            case EXTI_u8_FALLING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,ISC1);
            CLR_BIT(EXTI_u8_MCUCR,ISC0);
            SET_BIT(EXTI_u8_GICR,PIN6);
            break;
            case EXTI_u8_LOGICAL_CHANGE:
            CLR_BIT(EXTI_u8_MCUCR,ISC1);
            SET_BIT(EXTI_u8_MCUCR,ISC0);
            SET_BIT(EXTI_u8_GICR,PIN6);
            break;
            case EXTI_u8_LOW_LEVEL:
            CLR_BIT(EXTI_u8_MCUCR,ISC1);
            CLR_BIT(EXTI_u8_MCUCR,ISC0);
            SET_BIT(EXTI_u8_GICR,PIN6);
            break;
            default:Local_u8ErrorState=STD_TYBES_NOK;

        }
        break;
        case EXTI_u8_INT1:
        switch(copy_u8EXTIEdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,ISC11);
            SET_BIT(EXTI_u8_MCUCR,ISC10);
            SET_BIT(EXTI_u8_GICR,PIN7);
            break;
            case EXTI_u8_FALLING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,ISC11);
            CLR_BIT(EXTI_u8_MCUCR,ISC10);
            SET_BIT(EXTI_u8_GICR,PIN7);
            break;
            case EXTI_u8_LOGICAL_CHANGE:
            CLR_BIT(EXTI_u8_MCUCR,ISC11);
            SET_BIT(EXTI_u8_MCUCR,ISC10);
            SET_BIT(EXTI_u8_GICR,PIN7);
            break;
            case EXTI_u8_LOW_LEVEL:
            CLR_BIT(EXTI_u8_MCUCR,ISC11);
            CLR_BIT(EXTI_u8_MCUCR,ISC10);
            SET_BIT(EXTI_u8_GICR,PIN7);
            break;
            default:Local_u8ErrorState=STD_TYBES_NOK;

     }
     break;
     case EXTI_u8_INT2:
        switch(copy_u8EXTIEdgeIndex)
        {
        case EXTI_u8_RAISING_EDGE:
            SET_BIT(EXTI_u8_MCUCR,ISC6);
            SET_BIT(EXTI_u8_GICR,PIN5);
            break;
            case EXTI_u8_FALLING_EDGE:
            CLR_BIT(EXTI_u8_MCUCR,ISC6);
            SET_BIT(EXTI_u8_GICR,PIN5);
            break;
            default:Local_u8ErrorState=STD_TYBES_NOK;

     }
     break;
     default:Local_u8ErrorState=STD_TYBES_NOK;
     }
     return Local_u8ErrorState;

 }
u8 EXTI_u8EXTIDisable(u8 copy_u8EXTIIndex)
{
    u8 local_u8ErrorState=STD_TYBES_OK;
    switch (copy_u8EXTIIndex){
    case EXTI_u8_INT0:
        switch(copy_u8EXTIIndex)
        {
        case EXTI_u8_INT0:
            CLR_BIT(EXTI_u8_GICR,PIN6);
            break;
            case EXTI_u8_INT1:
            CLR_BIT(EXTI_u8_GICR,PIN7);
            break;
            case EXTI_u8_INT2:
            CLR_BIT(EXTI_u8_GICR,PIN5);
            break;
            default:local_u8ErrorState=STD_TYBES_NOK;}
}
return local_u8ErrorState;
}
u8 EXTI_u8EXTISetCallBack(u8 copy_u8EXTIIndex,void(*copy_pf)(void))
{
    u8 local_u8Errorstate= STD_TYBES_OK;
    if((copy_u8EXTIIndex <= EXTI_u8_INT2) && (copy_pf=! NULL))
        {
         EXTI_ApfEXTI[copy_u8EXTIIndex]=copy_pf;
        }
    else{local_u8Errorstate=STD_TYBES_NOK;}
    return local_u8Errorstate;
}
/*PROTOTYPE FOR EXTI0*/
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT0]!=NULL){
    EXTI_ApfEXTI[EXTI_u8_INT0]();
    }
}
/*PROTOTYPE FOR EXTI1*/
void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT1]!=NULL){
    EXTI_ApfEXTI[EXTI_u8_INT1]();
    }
}
/*PROTOTYPE FOR EXTI2*/
void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
    if (EXTI_ApfEXTI[EXTI_u8_INT2]!=NULL){
    EXTI_ApfEXTI[EXTI_u8_INT2]();
    }
}
