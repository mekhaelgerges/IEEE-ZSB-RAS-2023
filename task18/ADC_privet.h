      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#ifndef ADC_PRIVET_H
#define  ADC_PRIVET_H
#define ADC_u8_ADMUX_REG                   *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG                   *((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG                   *((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG                   *((volatile u8 *)0x24)
#define ADC_u16_ADC_REG                   *((volatile u8 *)0x24)

#define ADC_u8_SFIOR_REG                   *((volatile u8 *)0x50)

#define ADC_REFS1_PIN                        7
#define ADC_REFS0_PIN                        6
#define ADC_ADLAR_PIN                        5
#define ADC_ADATE_PIN                        5
#define ADC_ADPS2_PIN                        2
#define ADC_ADPS1_PIN                        1
#define ADC_ADPS0_PIN                        0
#define ADC_ADEN_PIN                         7
#define ADC_ADSC_PIN                         6
#define ADC_ADIF_PIN                         4
#define ADC_ADIE_PIN                         3

#endif
