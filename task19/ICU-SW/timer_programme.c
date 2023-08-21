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
void TIMERS_VoidTimer1Init(void)
{
	/*select timer1 mode =>14 ICR TOP VALUE*/
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	/*SELECT HW ACTION ON OC1A PIN =>NON INVERTING*/
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,6);
	/*SET TOP VALUE IN ICR1*/
	TIMERS_u8_ICR1_REG=2499;
	/*SET ANGLE OF THE SERVO MOTOR*/
	/*set prescaler value */
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
    SET_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,0);

}
u8 TIMER_u8Timer1channelACompareMatchValue(u16 copy_u16OCRValue)
{
	TIMERS_u16_OCR1A_REG=copy_u16OCRValue;
}

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

#elif  TIMER_MODE==TIMER_PWM_MODE
    /*select mode=>PWM mode*/
        SET_BIT(TIMERS_u8_TCCR0_REG,6);
        SET_BIT(TIMERS_u8_TCCR0_REG,3);
        /*SELECT HW Action on oc0pin ==> Non Inverting */
        SET_BIT(TIMERS_u8_TCCR0_REG,5);
        CLR_BIT(TIMERS_u8_TCCR0_REG,4);
#elif   TIMER_MODE==TIMER_PHASE_CORRECT_PWM_MODE
        /*select mode=> PHASE CORRECT PWM mode*/
                CLR_BIT(TIMERS_u8_TCCR0_REG,6);
                SET_BIT(TIMERS_u8_TCCR0_REG,3);
                /*SELECT HW Action on oc0pin ==> Non Inverting */
                SET_BIT(TIMERS_u8_TCCR0_REG,5);
                CLR_BIT(TIMERS_u8_TCCR0_REG,4);

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
void TIMERS_voidTimer0StCompareMatchvalue(u8 copy_u8OCR0Value)
{
	TIMERS_u8_OCR0_REG=copy_u8OCR0Value;
}
u16 TIMER1_u16ReadTimerValue(void)
{
	return TIMERS_u16_TCNT1_REG;
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
