     /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: UART_INTERFACE_H  ****************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "UART_interface.h"
#include "UART_privet.h"
#include "UART_config.h"

void UART_voidInit(void)
{
	u16 local_u16baudrate = 51;
	u8 Local_u8UCSRCValue = 0b10000000;
	/*baud rate=9600*/
	UART_u8_UBRRL_REG = (u8)local_u16baudrate;
	UART_u8_UBRRH_REG = (u8)(local_u16baudrate >> 8);

	/*normal speed*/
	CLR_BIT(UART_u8_UCSRA_REG,1);
	/*DISABLE MPM*/
	CLR_BIT(UART_u8_UCSRA_REG,0);
	/*ENABLE RX TX*/
	SET_BIT(UART_u8_UCSRB_REG,4);
	SET_BIT(UART_u8_UCSRB_REG,3);
	/*SELECT 8 bit date*/
	CLR_BIT(UART_u8_UCSRB_REG,2);
	SET_BIT(Local_u8UCSRCValue,2);
	SET_BIT(Local_u8UCSRCValue,1);
	/*select Asynch Mode*/
	CLR_BIT(Local_u8UCSRCValue,6);
	/*no parity bit*/
	CLR_BIT(Local_u8UCSRCValue,5);
	CLR_BIT(Local_u8UCSRCValue,4);
	/*EEnable 2 stop bits*/
	SET_BIT(Local_u8UCSRCValue,3);
	/*UPDATE UCSRC REG*/
	UART_u8_UCSRC_REG = Local_u8UCSRCValue;

}
void UART_voidSendByte(u8 copy_u8dataByte)
{
	/*wait until the transmet reg is empty*/
	while((GET_BIT(UART_u8_UCSRA_REG,5))==0);
	{
		/*send date byte*/
		UART_u8_UDR_REG = copy_u8dataByte;
	}
}

u8 UART_u8RecieveByte(u8 * Copy_pu8RecByte)
{
	u8 local_u8Errorstate = STD_TYBES_NOK;
	if(Copy_pu8RecByte != NULL)
	{
		/* wait until date is recieved */
		while((GET_BIT(UART_u8_UCSRA_REG,7)) == 0);
		/*READ data*/
		*Copy_pu8RecByte = UART_u8_UDR_REG;
		local_u8Errorstate = STD_TYBES_OK;
	}
	return local_u8Errorstate;
}

u8 UART_Sendchar(u8 * Copy_u8String)
 {
	u8 count;
	 for(u8 count =0 ; Copy_u8String[count] != '\0' ; count++ )
	 {

		 while(GET_BIT(UART_u8_UCSRA_REG,5)==0);

		 UART_u8_UDR_REG=Copy_u8String[count];
	 }
	 return STD_TYBES_OK ;
 }




