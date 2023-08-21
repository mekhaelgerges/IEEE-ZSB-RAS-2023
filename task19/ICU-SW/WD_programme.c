#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WD_interface.h"
#define WDTCR   *((volatile u8*)0x41)
void WD_voidEnable(void)
{
	WDTCR=0b00001111;
}
void WD_voidDisEnable(void)
{
WDTCR|=((1<<4)|(1<<3));
WDTCR=0x00;
}
