#ifndef GPT_TYPES_H
#define GPT_TYPES_H

#include "Std_Types.h"

#define Gpt_ValueType			uint32_t

typedef enum
{
	T0,
	T1,
	T2,
	T3,
	T4,
	T5,
	T0W,
	T1W,
	T2W,
	T3W,
	T4W,
	T5W,	
}Gpt_ChannelType;
typedef enum
{
	GPT_COUNT_DOWN,
	GPT_COUNT_UP,
}Gpt_CountDir;
typedef enum
{
	GPT_MODE_NORMAL, 
	GPT_MODE_SLEEP,  
}Gpt_ModeType;
typedef enum
{
	GPT_PREDEF_TIMER_1US_16BIT = 0x00,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;

typedef struct
{
	Gpt_ChannelType GptChannelId;
	uint32_t GptChannelTickFrequency;
	uint32_t GptChannelTickValueMax;
	Gpt_ModeType Mode;
}Gpt_ConfigType;

#endif  