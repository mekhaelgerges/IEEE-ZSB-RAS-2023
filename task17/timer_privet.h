      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
 #ifndef TIMER_PRIVET_H
#define  TIMER_PRIVET_H
/*register*/
#define  TIMERS_u8_TIMSK_REG        *((volatile u8*) 0x59)
#define  TIMERS_u8_TIFR_REG         *((volatile u8*) 0x58)
#define  TIMERS_u8_TCCR0_REG        *((volatile u8*) 0x53)
#define  TIMERS_u8_TCNT0_REG        *((volatile u8*) 0x52)
#define  TIMERS_u8_OCR0_REG         *((volatile u8*) 0x5C)

#endif
