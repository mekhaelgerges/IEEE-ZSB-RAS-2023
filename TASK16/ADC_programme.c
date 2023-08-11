      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include"ADC_config.h"
#include"ADC_interface.h"
#include"ADC_privet.h"
 static void (*ADC_pfnotfictation)(void)=NULL;
 static u8 ADC_u8Busyflag=0;
u8 ADC_voidint()
{
    CLR_BIT(ADC_u8_ADMUX_REG,ADC_REFS1_PIN);
    SET_BIT(ADC_u8_ADMUX_REG,ADC_REFS0_PIN);

    CLR_BIT(ADC_u8_ADMUX_REG,ADC_ADLAR_PIN);


    CLR_BIT(ADC_u8_ADCSRA_REG,ADC_ADATE_PIN);
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADPS2_PIN);
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADPS1_PIN);
    CLR_BIT(ADC_u8_ADCSRA_REG,ADC_ADPS0_PIN);
    SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADEN_PIN);


}
u8 ADC_u8_GetDigitalValueSynchNonBlocking(u8 copy_u8channeINb,u16 *copy_pu16Digitalvalue)
{
    u8 local_u8ErrorState=STD_TYBES_OK;
    u32 local_u32TimeOutCounter=0;
    if((copy_u8channeINb< 32)&&(copy_pu16Digitalvalue!=NULL))
    {
       /* Clear MUX4..0 */

ADC_u8_ADMUX_REG &= 0b11100000;

/* Select Channel */

ADC_u8_ADMUX_REG = copy_u8channeINb;

/* Start Conversion */

SET_BIT (ADC_u8_ADCSRA_REG, ADC_ADSC_PIN); /* Wait flag = 1 */

while ((GET_BIT (ADC_u8_ADCSRA_REG, ADC_ADIF_PIN) == 0)&& (local_u32TimeOutCounter <ADC_u32_TIME_OUT_MAX_VALUE))
{
 local_u32TimeOutCounter++;
}
if (GET_BIT(ADC_u8_ADCSRA_REG,ADC_ADIF_PIN)!=0){



  SET_BIT(ADC_u8_ADCSRA_REG, ADC_ADIF_PIN);


 *copy_pu16Digitalvalue = ADC_u16_ADC_REG;
}

    else{local_u8ErrorState=STD_TYBES_NOK;}
}

  else{local_u8ErrorState=STD_TYBES_NOK;}

return local_u8ErrorState;}
u8 ADC_u8GetDigitalValueAsynch           (u8 copy_u8channeINb,void(*Copy_pfNotification)(void))
{
    u8 local_u8ErrorState=STD_TYBES_OK;
    if((copy_u8channeINb < 32) && (Copy_pfNotification != NULL)&&(ADC_u8Busyflag==0))

{
    ADC_u8Busyflag=1;

/* update Global Pointer to a function */

ADC_pfnotfictation=Copy_pfNotification; /* Enable ADC Interrupt */

SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADIE_PIN); /* Clear MUX4..0 */

ADC_u8_ADMUX_REG &= 0b11100000;

/* Select Channel */

ADC_u8_ADMUX_REG |= copy_u8channeINb;

/* Start Conversion */

SET_BIT(ADC_u8_ADCSRA_REG,ADC_ADSC_PIN);

}
else{local_u8ErrorState=STD_TYBES_NOK;}

return local_u8ErrorState;}
ADC_u8GetADCRegValue                  (u16 * copy_pu16ADCvalue)
{
   u8 local_u8ErrorState=STD_TYBES_OK;
    if(copy_pu16ADCvalue!=NULL)
    {
        copy_pu16ADCvalue=ADC_u16_ADC_REG;
    }
    else{local_u8ErrorState=STD_TYBES_NOK;}
    return local_u8ErrorState;
}

void __vector_16(void)    __attribute__((signal))
void __vector_16(void)
{
    if(ADC_pfnotfictation!=NULL)
    {
        ADC_u8Busyflag=0;
        CLR_BIT(ADC_u8_ADCSRA_REG,ADC_ADIE_PIN);
        ADC_pfnotfictation(ADC_u16_ADC_REG);
    }

}
