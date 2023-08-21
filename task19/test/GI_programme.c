      /******************************************************/
     /********** name: mekhael   ***************************/
    /***********date: 30/4/20222***************************/
   /****************swc: GI  *****************************/
  /**************** Version 1.0   ***********************/
 /******************************************************/
 #include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GI_interface.h"

#define   SREG      *((volatile u8 *)0x5F)
 void GI_voidenable(void)
 {
     SET_BIT(SREG,7);
 }
void GI_voidDisable(void)
{
    CLR_BIT(SREG,7);
}
