#include "Std_Types.h"
#include "Macros.h"
#include "Port.h"
#include "Mcu_Hw.h"

void Port_Init(const Port_ConfigType*ConfigPtr)
{
	
	if(NULL_PTR == ConfigPtr)
	{
		ConfigPtr = Channels; 
	}
	for(uint8_t i=0;i<DIO_CONFIGURED_CHANNLES;i++)
	{
			SET_BIT(SYSCTL->RCGCGPIO,(ConfigPtr[i].Channel.Port));
			if( DIRECTION_OUTPUT == (ConfigPtr[i].Direction))
				SET_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->DIR,ConfigPtr[i].Channel.Pin);
			else if(DIRECTION_INPUT == (ConfigPtr[i].Direction))
					CLEAR_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->DIR,ConfigPtr[i].Channel.Pin);
			if(ConfigPtr[i].Mode == SPECIAL_MODE)
			{
				PORTAFSEL(ConfigPtr[i].Channel.Port) |= SPECIAL_MODE;
				PORTPCTL(ConfigPtr[i].Channel.Port);/* TODO: config this register*/
			}
			if(ConfigPtr[i].Current == R2R)
			{
				SET_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->DR2R,ConfigPtr[i].Channel.Pin);
			}
			else if(ConfigPtr[i].Current == R4R)
			{
				SET_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->DR4R,ConfigPtr[i].Channel.Pin);
			}
			else if(ConfigPtr[i].Current == R8R)
			{
				SET_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->DR8R,ConfigPtr[i].Channel.Pin);
			}
			if(ConfigPtr[i].Attach == PULL_DOWN)
			{
				SET_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->PDR,ConfigPtr[i].Channel.Pin);
			}
			else if(ConfigPtr[i].Attach == PULL_UP)
			{
				SET_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->PUR,ConfigPtr[i].Channel.Pin);
			}
			else if((ConfigPtr[i].Attach) == OPEN_DRAIN)
			{
				SET_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->ODR,ConfigPtr[i].Channel.Pin);
			}
			SET_BIT(GPIO_BASE(ConfigPtr[i].Channel.Port)->DEN,ConfigPtr[i].Channel.Pin);
		}	
}