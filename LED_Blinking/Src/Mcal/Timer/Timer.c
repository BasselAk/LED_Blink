#include "Std_Types.h"
#include "Macros.h"
#include "Timer.h"
#include "Mcu_Hw.h"

#define	MCU_CLK							16000000UL

typedef void (*CallBack)(void);
static CallBack GptCallbackFunction[12] = {NULL_PTR};
static uint32_t NumOfTicksPerUserTick[12] = {0};

void Gpt_Init(const Gpt_ConfigType*ConfigPtr)
{
	SET_BIT(SYSCTL->RCGCTIMER,ConfigPtr->GptChannelId);
	CLEAR_BIT(TIMER_BASE(ConfigPtr->GptChannelId)->CTL,0);
	TIMER_BASE(ConfigPtr->GptChannelId)->CFG = 0x00000000;
	if(GPT_MODE_SLEEP == ConfigPtr->Mode)
		SET_BIT(TIMER_BASE(ConfigPtr->GptChannelId)->TAMR,0);
	else if(GPT_MODE_NORMAL == ConfigPtr->Mode)
		SET_BIT(TIMER_BASE(ConfigPtr->GptChannelId)->TAMR,1);
	SET_BIT(TIMER_BASE(ConfigPtr->GptChannelId)->TAMR , 4);
	SET_BIT(TIMER_BASE(ConfigPtr->GptChannelId)->CTL,1);
	NumOfTicksPerUserTick[ConfigPtr->GptChannelId] = MCU_CLK/(ConfigPtr->GptChannelTickFrequency);
	uint32_t ActualMaxTicks = NumOfTicksPerUserTick[ConfigPtr->GptChannelId] * ConfigPtr->GptChannelTickValueMax; 
	TIMER_BASE(ConfigPtr->GptChannelId)->TAILR = ActualMaxTicks;
}

Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
		return TIMER_BASE(Channel)->TAR/NumOfTicksPerUserTick[Channel];	 
}
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
	return (TIMER_BASE(Channel)->TAILR -TIMER_BASE(Channel)->TAR)/NumOfTicksPerUserTick[Channel];	 
}
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value)
{
	uint32_t ActualMaxTicks = NumOfTicksPerUserTick[Channel] * Value; 
	TIMER_BASE(Channel)->TAILR = ActualMaxTicks;
	SET_BIT(TIMER_BASE(Channel)->CTL,0);//A
}
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
	CLEAR_BIT(TIMER_BASE(Channel)->CTL,0); 
}
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
	SET_BIT(TIMER_BASE(Channel)->IMR,0);
}
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
	CLEAR_BIT(TIMER_BASE(Channel)->IMR,0);
}
void Gpt_CallbackRegister(Gpt_ChannelType Channel,void (*InterruptHandler)(void))
{
	GptCallbackFunction[Channel] = InterruptHandler;
}
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer,uint32_t*TimeValuePtr)
{
	
}
Std_ReturnType Gpt_PollTimer(Gpt_ChannelType Channel)
{
	return GET_BIT(TIMER_BASE(Channel)->RIS,0);
}
void Gpt_ClrFlag(Gpt_ChannelType Channel)
{
	uint32_t u32status = TIMER_BASE(Channel)->MIS;
	SET_BIT(TIMER_BASE(Channel)->ICR,u32status>>1);
}
void TIMER0A_Handler(void)
{
	Gpt_ClrFlag(0);
	if(NULL_PTR != GptCallbackFunction[0])
	{
		GptCallbackFunction[0]();
	}
}
void TIMER1A_Handler(void)
{
	Gpt_ClrFlag(1);
	if(NULL_PTR == GptCallbackFunction[1])
	{
		GptCallbackFunction[1]();
	}
}
void TIMER2A_Handler(void)
{
	Gpt_ClrFlag(2);
	if(NULL_PTR == GptCallbackFunction[2])
	{
		GptCallbackFunction[2]();
	}
}
void TIMER3A_Handler(void)
{
	Gpt_ClrFlag(3);
	if(NULL_PTR == GptCallbackFunction[3])
	{
		GptCallbackFunction[3]();
	}
}
void TIMER4A_Handler(void)
{
	Gpt_ClrFlag(4);
	if(NULL_PTR == GptCallbackFunction[4])
	{
		GptCallbackFunction[4]();
	}
}
void TIMER5A_Handler(void)
{
	Gpt_ClrFlag(5);
	if(NULL_PTR == GptCallbackFunction[5])
	{
		GptCallbackFunction[5]();
	}
}
void WTIMER0A_Handler(void)
{
	Gpt_ClrFlag(6);
	if(NULL_PTR == GptCallbackFunction[6])
	{
		GptCallbackFunction[6]();
	}
}
void WTIMER1A_Handler(void)
{
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
	{
		GptCallbackFunction[0]();
	}
}
void WTIMER2A_Handler(void)
{
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
	{
		GptCallbackFunction[0]();
	}
}
void WTIMER3A_Handler(void)
{
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
	{
		GptCallbackFunction[0]();
	}
}
void WTIMER4A_Handler(void)
{
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
	{
		GptCallbackFunction[0]();
	}
}
void WTIMER5A_Handler(void)
{
	Gpt_ClrFlag(0);
	if(NULL_PTR == GptCallbackFunction[0])
	{
		GptCallbackFunction[0]();
	}
}