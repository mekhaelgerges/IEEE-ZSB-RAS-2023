      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
#define TIMER_u8_PreloadValue     72
void TIMERS_VoidTimer0Init(void);

void TIMERS_VoidTimer1Init(void);
u8 TIMER_u8Timer0SetcallBack(void(*Copy_pf)(void));
u8 TIMER_u8Timer0CTCSetcallBack(void(*Copy_pf)(void));
u8 TIMER_u8Timer1channelACompareMatchValue(u16 copy_u16OCRValue);
void TIMERS_voidTimer0StCompareMatchvalue(u8 copy_u8OCR0Value);
u16 TIMER1_u16ReadTimerValue(void);


#endif
