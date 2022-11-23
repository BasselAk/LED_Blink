#ifndef GPT_CFG_H
#define GPT_CFG_H

#include "Timer.h"

#define USER_FREQ_HZ		1000
#define MAX_TICK_VAL		1000000

void Timer0_Handler(void);

extern Gpt_ConfigType Gpt_Cfg;

 
#endif