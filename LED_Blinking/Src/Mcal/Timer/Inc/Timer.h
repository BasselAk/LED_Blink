#include "Std_Types.h"
#include "Timer_Types.h"
#include "Timer_Cfg.h"

void Gpt_Init(const Gpt_ConfigType*ConfigPtr);
void Gpt_DisableNotification(Gpt_ChannelType Channel); void Gpt_EnableNotification(Gpt_ChannelType Channel);
void Gpt_CallbackRegister(Gpt_ChannelType Channel,void (*InterruptHandler)(void));
void Gpt_StartTimer(Gpt_ChannelType Channel,Gpt_ValueType Value);
void Gpt_StopTimer(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer,uint32_t*TimeValuePtr);
Std_ReturnType Gpt_PollTimer(Gpt_ChannelType Channel);
void Gpt_ClrFlag(Gpt_ChannelType Channel);

void TIMER0A_Handler(void);
void TIMER1A_Handler(void);
void TIMER2A_Handler(void);
void TIMER3A_Handler(void);
void TIMER4A_Handler(void);
void TIMER5A_Handler(void);
void WTIMER0A_Handler(void);
void WTIMER1A_Handler(void);
void WTIMER2A_Handler(void);
void WTIMER3A_Handler(void);
void WTIMER4A_Handler(void);
void WTIMER5A_Handler(void);
