/******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: DIO_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
 /*LIB layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
  /*MCAL layer*/
#include "DIO_interface.h"
#include "DIO_privat.h"
#include "DIO_config.h"

void DIO_voidInit (void)
{
DIO_u8_DDRA_REG=  conc(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,
                     DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);

DIO_u8_DDRD_REG= conc(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,
                     DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);

DIO_u8_DDRC_REG=conc(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,
                     DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);

DIO_u8_DDRB_REG=conc(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,
                     DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION);


DIO_u8_PORTA_REG=conc(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,
                     DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);

DIO_u8_PORTD_REG=conc(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,
                     DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);

DIO_u8_PORTC_REG= conc( DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,
                     DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);

DIO_u8_PORTB_REG= conc( DIO_u8_PB7_INTIAL_VALUE, DIO_u8_PB6_INTIAL_VALUE, DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,
                     DIO_u8_PB3_INTIAL_VALUE, DIO_u8_PB2_INTIAL_VALUE, DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);
}
u8 DIO_u8SetPinDirection        (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8pinDirection){
	u8 Local_u8ErrorState=STD_TYBES_OK ;
	if ((copy_u8portID<=DIO_u8_PORTD )&&(copy_u8pinID <=DIO_u8_PIN7 )&&((copy_u8pinDirection>=DIO_u8_OUTPUT)||(copy_u8pinDirection<=DIO_u8_INPUT)))
    {


		switch(copy_u8portID)
		{
			case DIO_u8_PORTA:
			switch(copy_u8pinDirection)
			{
			case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRA_REG,copy_u8pinID); break;
			case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRA_REG,copy_u8pinID); break;
			}break;
			case DIO_u8_PORTB:
			switch(copy_u8pinDirection)
			{
			case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRB_REG,copy_u8pinID); break;
			case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRB_REG,copy_u8pinID); break;
			}break;
			case DIO_u8_PORTC:
			switch(copy_u8pinDirection)
			{
			case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRC_REG,copy_u8pinID); break;
			case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRC_REG,copy_u8pinID); break;
			}break;
			case DIO_u8_PORTD:
			switch(copy_u8pinDirection)
			{
			case DIO_u8_OUTPUT:SET_BIT(DIO_u8_DDRD_REG,copy_u8pinID); break;
			case DIO_u8_INPUT:CLR_BIT(DIO_u8_DDRD_REG,copy_u8pinID); break;
		}
		break;
	}
	}
	else{Local_u8ErrorState=STD_TYBES_NOK;}

	return Local_u8ErrorState ;}

u8 DIO_u8SetpinValue             (u8 copy_u8portID,u8 copy_u8pinID,u8 copy_u8pinValue)
{
    u8 Local_u8ErrorState =STD_TYBES_OK;
    if(copy_u8pinID <=DIO_u8_PIN7 ){
    switch (copy_u8portID)
    {
    case DIO_u8_PORTA:
        switch(copy_u8pinValue)
        {
            case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTA_REG,copy_u8pinID);break;
            case DIO_u8_LOW :CLR_BIT(DIO_u8_PORTA_REG,copy_u8pinID);break;
            default :Local_u8ErrorState=STD_TYBES_NOK;
        }
        break;
        case DIO_u8_PORTB:
        switch(copy_u8pinValue)
        {
            case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTB_REG,copy_u8pinID);break;
            case DIO_u8_LOW :CLR_BIT(DIO_u8_PORTB_REG,copy_u8pinID);break;
            default :Local_u8ErrorState=STD_TYBES_NOK;
        }break;
        case DIO_u8_PORTC:
        switch(copy_u8pinValue)
        {
            case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTC_REG,copy_u8pinID);break;
            case DIO_u8_LOW :CLR_BIT(DIO_u8_PORTC_REG,copy_u8pinID);break;
            default :Local_u8ErrorState=STD_TYBES_NOK;
        }break;
        case DIO_u8_PORTD:
        switch(copy_u8pinValue)
        {
            case DIO_u8_HIGH:SET_BIT(DIO_u8_PORTD_REG,copy_u8pinID);break;
            case DIO_u8_LOW :CLR_BIT(DIO_u8_PORTD_REG,copy_u8pinID);break;
            default :Local_u8ErrorState=STD_TYBES_NOK;
        }break;
    default:Local_u8ErrorState=STD_TYBES_NOK;}

    }
    else{Local_u8ErrorState=STD_TYBES_NOK;}
	return Local_u8ErrorState ;}

u8 DIO_u8GetPinValue             (u8 copy_u8portID,u8 copy_u8pinID,u8 * copy_pu8Returnedpinvalue)
{
   u8 Local_u8ErrorState=STD_TYBES_OK;
    u8 local_pinvalue;
   if ((copy_u8portID<=DIO_u8_PORTD )&&(copy_u8pinID <=DIO_u8_PIN7 )&&(copy_pu8Returnedpinvalue !=NULL))
    {switch(copy_u8portID){
    case DIO_u8_PORTA:local_pinvalue=GET_BIT(DIO_u8_PINA_REG,copy_u8pinID);
   if(local_pinvalue==0)
   {
     * copy_pu8Returnedpinvalue   =DIO_u8_LOW;
    }
    else
    {
         * copy_pu8Returnedpinvalue   =DIO_u8_HIGH;
    }
       break;
    case DIO_u8_PORTB:local_pinvalue=GET_BIT(DIO_u8_PINB_REG,copy_u8pinID);
   if(local_pinvalue==0)
   {
     * copy_pu8Returnedpinvalue   =DIO_u8_LOW;
    }
    else
    {
         * copy_pu8Returnedpinvalue   =DIO_u8_HIGH;
    }
    break;

    case DIO_u8_PORTC:local_pinvalue=GET_BIT(DIO_u8_PINC_REG,copy_u8pinID);
   if(local_pinvalue==0)
   {
     * copy_pu8Returnedpinvalue   =DIO_u8_LOW;
    }
    else
    {
         * copy_pu8Returnedpinvalue   =DIO_u8_HIGH;
    }break;

    case DIO_u8_PORTD:local_pinvalue=GET_BIT(DIO_u8_PIND_REG,copy_u8pinID);
   if(local_pinvalue==0)
   {
     * copy_pu8Returnedpinvalue   =DIO_u8_LOW;
    }
    else
    {
         * copy_pu8Returnedpinvalue   =DIO_u8_HIGH;
    }
    break;
}}	return Local_u8ErrorState ;}

u8 DIO_u8setPortDirection       (u8 copy_u8portID,u8 copy_u8PortDirection)
{
    	   u8 Local_u8ErrorState=STD_TYBES_OK;
    	    if((copy_u8PortDirection==DIO_u8_OUTPUT)||(copy_u8PortDirection==DIO_u8_INPUT))
                {
                    switch(copy_u8portID)
                    {
                    case DIO_u8_PORTA:
                        switch(copy_u8PortDirection)
                        {case DIO_u8_OUTPUT :DIO_u8_DDRA_REG=0xff;break;
                        case DIO_u8_INPUT :DIO_u8_DDRA_REG=0x00;break;
                        }
                        break;
                        case DIO_u8_PORTB:
                        switch(copy_u8PortDirection)
                        {case DIO_u8_OUTPUT :DIO_u8_DDRB_REG=0xff;break;
                        case DIO_u8_INPUT :DIO_u8_DDRB_REG=0x00;break;
                        }
                        break;
                        case DIO_u8_PORTC:
                        switch(copy_u8PortDirection)
                        {case DIO_u8_OUTPUT :DIO_u8_DDRC_REG=0xff;break;
                        case DIO_u8_INPUT :DIO_u8_DDRC_REG=0x00;break;
                        }
                        break;
                        case DIO_u8_PORTD:
                        switch(copy_u8PortDirection)
                        {case DIO_u8_OUTPUT :DIO_u8_DDRD_REG=0xff;break;
                        case DIO_u8_INPUT :DIO_u8_DDRD_REG=0x00;break;
                        }
                        break;
                    }
                }
            else{Local_u8ErrorState=STD_TYBES_OK;}
    	return Local_u8ErrorState ;
}

u8 DIO_u8SetPortValue           (u8 copy_u8portID,u8 copy_u8PortValue)
{
  u8  Local_u8ErrorState=STD_TYBES_OK;
  switch(copy_u8portID)
  {
      case DIO_u8_PORTA: DIO_u8_PORTA_REG=copy_u8PortValue;break;
      case DIO_u8_PORTB: DIO_u8_PORTB_REG=copy_u8PortValue;break;
      case DIO_u8_PORTC: DIO_u8_PORTC_REG=copy_u8PortValue;break;
      case DIO_u8_PORTD: DIO_u8_PORTD_REG=copy_u8PortValue;break;
      default:Local_u8ErrorState=STD_TYBES_NOK;
  }
    return Local_u8ErrorState ;
}

u8 DIO_u8GetPortValue           (u8 copy_u8portID,u8 * copy_pu8ReturenedPortValue)
{
        	 u8   Local_u8ErrorState=STD_TYBES_OK;
        	 if (copy_pu8ReturenedPortValue!= NULL)
             {
                 switch(copy_u8portID)
  {
      case DIO_u8_PORTA:*copy_pu8ReturenedPortValue=DIO_u8_PINA_REG;break;
      case DIO_u8_PORTB:*copy_pu8ReturenedPortValue=DIO_u8_PINB_REG;break;
      case DIO_u8_PORTC:*copy_pu8ReturenedPortValue=DIO_u8_PINC_REG;break;
      case DIO_u8_PORTD:*copy_pu8ReturenedPortValue=DIO_u8_PIND_REG;break;
      default:Local_u8ErrorState=STD_TYBES_NOK;
             }
             }
              else{Local_u8ErrorState=STD_TYBES_OK;}
        	 return Local_u8ErrorState;

}


