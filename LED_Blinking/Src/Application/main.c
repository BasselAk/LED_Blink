#include "newheader.h"
#include "Interrupt.h"
#include "Port.h"
#include "Timer.h"
#include "BlinkLed.h"

int main(void)
{
	SystemInit();
	IntCrtl_Init(ISRs);
	Port_Init(Channels);
	BlinkLed_Init();
	BlinkLed_SetOnTime(4); //time in sec
	BlinkLed_SetOffTime(2);//time in sec
	BlinkLed_Start();
	while(1)
	{
		BlinkLed_Run();

	}
	return 0;
}
