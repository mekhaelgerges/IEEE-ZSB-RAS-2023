      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
 #include "BIT_MATH.h"
#include "STD_TYPES.h"
#include"timer_config.h"
#include"timer_interface.h"
#include"timer_privet.h"
/*global pointer*/
static void(*TIMERS_pfTimer0OVF)(void)=NULL;
static void(*TIMERS_pfTimer0CTC)(void)=NULL;
void TIMERS_VoidTimer0Init(void)
{
#if     TIMER_MODE==TIMER_OVF_MODE
    /*select mode=>normal mode*/
    CLR_BIT(TIMERS_u8_TCCR0_REG,6);
    CLR_BIT(TIMERS_u8_TCCR0_REG,3);
    /*ENABLE OVAR FLOW INTERRUPT*/
    SET_BIT(TIMERS_u8_TIMSK_REG,0);
    /*SET PRELOAD VALUE*/
    TIMERS_u8_TCNT0_REG=TIMER_u8_PreloadValue;
#elif  TIMER_MODE==TIMER_CTC_MODE
    /*select mode=>CTC mode*/
    CLR_BIT(TIMERS_u8_TCCR0_REG,6);
    SET_BIT(TIMERS_u8_TCCR0_REG,3);


    /*ENABLE CTC INTERRUPT*/
    SET_BIT(TIMERS_u8_TIMSK_REG,1);
    /*SET COMPARE MATCH UNIT REGISTER*/
    TIMERS_u8_OCR0_REG=99;
    TIMERS_u8_TCCR0_REG=6;

#endif
    /*set prescaler value */
    CLR_BIT(TIMERS_u8_TCCR0_REG,2);
    SET_BIT(TIMERS_u8_TCCR0_REG,1);
    CLR_BIT(TIMERS_u8_TCCR0_REG,0);
}
u8 TIMER_u8Timer0SetcallBack(void(*Copy_pf)(void))
{
    u8 local_u8EroorState=STD_TYBES_OK;
    if ((Copy_pf!=NULL))
    {
        TIMERS_pfTimer0OVF=Copy_pf;
    }
    else{local_u8EroorState=STD_TYBES_NOK;}
    return local_u8EroorState;
}

/*prototype for ISR of timer0 ovf*/
void __vector_11(void)    __attribute__((signal));
void __vector_11(void)
{
if ((TIMERS_u8_TCCR0_REG==6)||(TIMERS_u8_TCCR0_REG==7))
{
	 if(TIMERS_pfTimer0OVF!=NULL)
	        {
	            TIMERS_pfTimer0OVF();
	        }}
else{
    static u16 local_u16CounterOVF=0;

    local_u16CounterOVF++;
    if(local_u16CounterOVF==488)
    {
        /*update preloadevalue*/
        TIMERS_u8_TCNT0_REG=TIMER_u8_PreloadValue;
        /*clear_u16countovf*/
        local_u16CounterOVF=0;
        /*call applection function*/
        if(TIMERS_pfTimer0OVF!=NULL)
        {
            TIMERS_pfTimer0OVF();
        }

    }
}
}
void __vector_10(void)    __attribute__((signal));
void __vector_10(void)
{
if ((TIMERS_u8_TCCR0_REG==6)||(TIMERS_u8_TCCR0_REG==7)){
	 if(TIMERS_pfTimer0CTC!=NULL)
	        {
		     TIMERS_pfTimer0CTC();
	        }
}
else{
    static u16 local_u16CounterCTC=0;

    local_u16CounterCTC++;
    if(local_u16CounterCTC==10000)
    {
    	local_u16CounterCTC=0;
    	/*CALL BACK FUNCTOIN*/
    	  if(TIMERS_pfTimer0CTC!=NULL)
    	        {
    	            TIMERS_pfTimer0CTC();
    	        }
    }
}
}
