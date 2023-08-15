      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#ifndef ADC_INTERFACE_H
#define  ADC_INTERFACE_H

#define ADC_u8_CHANNEL_0             0
#define ADC_u8_CHANNEL_1             1
#define ADC_u8_CHANNEL_2             2
#define ADC_u8_CHANNEL_3             3
#define ADC_u8_CHANNEL_4             4
#define ADC_u8_CHANNEL_5             5
#define ADC_u8_CHANNEL_6             6
#define ADC_u8_CHANNEL_7             7


void ADC_voidInit(void);
u8 ADC_u8_GetDigitalValueSynchNonBlocking(u8 copy_u8channeINb,u16 *copy_pu16Digitalvalue);
u8 ADC_u8GetDigitalValueAsynch           (u8 copy_u8channeINb,void(*Copy_pfNotification)(void));
u8 ADC_u8GetADCRegValue                  (u16 *copy_pu16ADCvalue);
#endif
