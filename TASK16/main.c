#include "BIT_Math.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"
#include "GI_interface.h"


#include<util/delay.h>
#define F_CPU 1000000UL

void App_voidADCCallBack(u16 Copy_u16ADCValue);
static u16 App_u16DigitalValue;

u8 main(void)
{
	DIO_voidInit();
	LCD_voidInit();
	ADC_voidInit();
	GI_voidenable();

	 u16 DigitalValue, AnalogValue;
	u16 Res;

		void App_voidADCCallBack(u16 Copy_u16ADCValue);
		static u16 App_u16DigitalValue;


		ADC_u8_GetDigitalValueSynchNonBlocking(ADC_u8_CHANNEL_0,&DigitalValue);
		AnalogValue = ((DigitalValue * 5000UL) / 1024UL);
		Res = ((10000*1024UL)/DigitalValue) - 10000;



		LCD_voidSendNum(AnalogValue);
		LCD_sendString("  volt");

	return 0;
}

void App_voidADCCallBack(u16 Copy_u16ADCValue){
	App_u16DigitalValue = Copy_u16ADCValue;
}
