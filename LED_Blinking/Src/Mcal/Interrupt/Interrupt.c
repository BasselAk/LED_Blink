#include "Std_Types.h"
#include "Macros.h"
#include "Interrupt.h"
#include "Mcu_Hw.h"

void IntCrtl_Init(const IntCtrl_ConfigType*ConfigPtr)
{	
	for(uint8_t i=0;i<INT_CONFIGURED;i++){		
			if(ConfigPtr[i].ISR < 32)
			{
				SET_BIT(*ENABLE_BASE(0),ConfigPtr[0].ISR);
			}else if(ConfigPtr[i].ISR >= 32&&ConfigPtr[0].ISR < 64)
			{
				SET_BIT(*ENABLE_BASE(1),(ConfigPtr[0].ISR - 32));
			}else if(ConfigPtr[i].ISR >= 64 && ConfigPtr[i].ISR < 96)
			{
				SET_BIT(*ENABLE_BASE(2),(ConfigPtr[0].ISR - 64));
			}else if(ConfigPtr[i].ISR >= 96 &&ConfigPtr[0].ISR < 128)
			{
				SET_BIT(*ENABLE_BASE(3),(ConfigPtr[0].ISR - 96));
			}else if(ConfigPtr[i].ISR >= 128 &&ConfigPtr[0].ISR <= 138)
			{
				SET_BIT(*ENABLE_BASE(4),(ConfigPtr[0].ISR - 128));
			}
	}

}