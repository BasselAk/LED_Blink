#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"
#include "GPIO_Types.h"
#include "Port_Types.h"

extern const Port_ConfigType Dio_Config;

Dio_LevelType Dio_ReadChannel(Port_ChannelType ChannelId);
void Dio_WriteChannel(Port_ChannelType ChannelId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
Dio_LevelType Dio_FlipChannel(Port_ChannelType ChannelId);


#endif  