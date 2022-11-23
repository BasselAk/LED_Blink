#include "newheader.h"
#include "Interrupt.h"
#include "Port.h"
#include "GPIO.h"
#include "Timer.h"
#include "BlinkLed.h"

volatile static uint8_t flag = FALSE;
static uint32_t SetOnTime = 0;
static uint32_t SetOffTime = 0;

typedef enum
{
	LED_OFF,
	LED_ON,
	STOP
}LedState;

void BlinkLed_Init(void)
{
	Gpt_Init(&Gpt_Cfg);
	Gpt_EnableNotification(T0);
	Gpt_CallbackRegister(T0,Timer0_Handler);
}

void BlinkLed_SetOnTime(uint32_t Time)
{
	SetOnTime = Time;
}

void BlinkLed_SetOffTime(uint32_t Time)
{
	SetOffTime = Time;
}

void BlinkLed_Start(void)
{
	Gpt_StartTimer(T0,1); //1 *(1/USER_FREQ_HZ) = 1ms
}

void BlinkLed_Stop(void)
{
	Gpt_StopTimer(T0);
}

void Timer0_Handler(void)
{
	flag = TRUE;
}

void BlinkLed_Run(void)
{	
	static uint32_t ms_Counter = 0;
	static uint32_t s_Counter = 0;
	static volatile uint8_t state;
	static uint32_t period = 0;
	period = SetOnTime + SetOffTime;
	if(TRUE == flag)
	{
		flag = FALSE;
		ms_Counter++;
	}
	if(ms_Counter == 1000)
	{
		ms_Counter = 0;
		s_Counter++;
	}
	if(s_Counter < SetOnTime)
	{
		state = LED_ON;
	}
	else if((s_Counter >= SetOnTime) && (s_Counter < period))
	{
		state = LED_OFF;
	}
	else if(s_Counter >= period)
	{
		s_Counter = 0;
		state = STOP;
	}
	switch(state)
	{
		case LED_OFF:
			Dio_WriteChannel(Channels[1].Channel,LOW);
			break;
		case LED_ON:
			Dio_WriteChannel(Channels[1].Channel,HIGH);
			break;
		case STOP:
			break;
		default:
			break;
	}
}
