#include "Std_Types.h"
#include "Macros.h"
#include "GPIO.h"
#include "Mcu_Hw.h"

Dio_LevelType Dio_ReadChannel(Port_ChannelType ChannelId){
	return  (Dio_LevelType)PORTDATA(ChannelId.Port+ChannelId.Pin);
}

void Dio_WriteChannel(Port_ChannelType ChannelId,Dio_LevelType Level){
	if (Level == HIGH)
		SET_BIT(PORTDATA(ChannelId.Port),ChannelId.Pin);
	else CLEAR_BIT(PORTDATA(ChannelId.Port),ChannelId.Pin);
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){
	return (Dio_PortLevelType)PORTDATA(PortId);
}

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level){
	PORTDATA(PortId) = Level;
}

Dio_LevelType Dio_FlipChannel(Port_ChannelType ChannelId){
  Toggle_BIT(PORTDATA(ChannelId.Port),ChannelId.Pin);
	return GET_BIT(PORTDATA(ChannelId.Port),ChannelId.Pin);
}
