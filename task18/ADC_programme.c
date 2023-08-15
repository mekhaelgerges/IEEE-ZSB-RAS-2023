      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#include "BIT_Math.h"
#include "STD_TYPES.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_privet.h"

static void(*ADC_pfNotification)(u16) = NULL;
/*ADC busy flag*/
static u8 ADC_u8BusyFlag = 0;


void ADC_voidInit(void)
{
    /*1- select Vref=AVCC
      2- right adjust
      3- disable autotrigger
      4- select CLk/64
      5- enable ADc
    */
   CLR_BIT(ADC_u8_ADMUX_REG,7);
   SET_BIT(ADC_u8_ADMUX_REG,6);

   CLR_BIT(ADC_u8_ADMUX_REG,5);

   CLR_BIT(ADC_u8_ADCSRA_REG,5);

   SET_BIT(ADC_u8_ADCSRA_REG,2);
   SET_BIT(ADC_u8_ADCSRA_REG,1);
   CLR_BIT(ADC_u8_ADCSRA_REG,0);

   SET_BIT(ADC_u8_ADCSRA_REG,7);
}

u8 ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNb, u16 * Copy_pu16DigitalValue)
{
    u8 Local_u8ErrorState = STD_TYBES_OK;
    u32 Local_u32TimeOutCounter = 0;
    if((Copy_u8ChannelNb < 32) && (Copy_pu16DigitalValue !=NULL))
    {
        /*clear mux4..0*/
        ADC_u8_ADMUX_REG &= 0b11100000;
        /*selct channel*/
        ADC_u8_ADMUX_REG != Copy_u8ChannelNb;
        /*start conversion*/
        SET_BIT(ADC_u8_ADCSRA_REG,6);
        /*wait flag=1*/
        while ((GET_BIT(ADC_u8_ADCSRA_REG,4) == 0) && (Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE ))
        {
            Local_u32TimeOutCounter++;
        }
        if(GET_BIT(ADC_u8_ADCSRA_REG,4) == 0) //(Local_u32TimeOutCounter < ADC_u32_TIME_OUT_MAX_VALUE )
        {/*clear flag*/
        SET_BIT(ADC_u8_ADCSRA_REG,4);
        /*reaad the digital value*/
        *Copy_pu16DigitalValue = ADC_u16_ADC_REG;
        }
        else{
            Local_u8ErrorState = STD_TYBES_NOK;
        }
    }
    else
    {
        Local_u8ErrorState = STD_TYBES_NOK;
    }



    return Local_u8ErrorState;
}

u8 ADC_u8GetDigitalValueAsynch           (u8 copy_u8channeINb,void(*Copy_pfNotification)(void))
{
    u8 Local_u8ErrorState = STD_TYBES_OK;

    if((copy_u8channeINb < 32) && (Copy_pfNotification != NULL) && (ADC_u8BusyFlag ==0))
    {
        /*set flag to make ADC is busy*/
        ADC_u8BusyFlag = 1;
        /*update global pointer to a function*/
        ADC_pfNotification = Copy_pfNotification;
        /*enable ADC interrupt*/
        SET_BIT(ADC_u8_ADCSRA_REG,3);
        /*clear mux4..0*/
        ADC_u8_ADMUX_REG &= 0b11100000;
        /*selct channel*/
        ADC_u8_ADMUX_REG != copy_u8channeINb;
        /*start conversion*/
        SET_BIT(ADC_u8_ADCSRA_REG,6);


    }
    else
    {
        Local_u8ErrorState = STD_TYBES_NOK;
    }

    return Local_u8ErrorState;
}

u8 ADC_u8GetADCRegvalue(u16 * Copy_pu16ADCValue)
{
    u8 Local_ErrorState = STD_TYBES_OK;
    if(Copy_pu16ADCValue !=NULL)
    {
        /*read ADC register*/
        *Copy_pu16ADCValue = ADC_u16_ADC_REG;

    }
    else
    {
        Local_ErrorState = STD_TYBES_NOK;
    }
    return Local_ErrorState;
}

/*prototype for ADC ISR*/
void __vector_16(void)         __attribute__((signal));
void __vector_16(void)
{
    if(ADC_pfNotification != NULL)
    {
        /*clear flag*/
        ADC_u8BusyFlag = 0;
        /*clear PIE for ADC*/
        CLR_BIT(ADC_u8_ADCSRA_REG,3);
        /*calling notifiction function*/
        ADC_pfNotification(ADC_u16_ADC_REG);
    }

}
