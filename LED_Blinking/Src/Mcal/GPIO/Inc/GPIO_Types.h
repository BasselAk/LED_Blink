#ifndef Dio_Types_H
#define Dio_Types_H

#include "Std_Types.h"
//API-Types
//-[Dio_ChannelType - Dio_PortType - Dio_LevelType - Dio_PortLevelType]
#define Dio_PortLevelType		uint8_t
typedef enum
{
	LOW =0,
	HIGH =1
}Dio_LevelType;
typedef enum
{
	PIN0 =0,
	PIN1 =1,
	PIN2 =2,
	PIN3 =3,
	PIN4 =4,
	PIN5 =5,
	PIN6 =6,
	PIN7 =7,
}Dio_ChannelType;
typedef enum
{
	PORTA =0 ,
	PORTB =1 ,
	PORTC =2 ,
	PORTD =3 ,
	PORTE =4 ,
	PORTF =5 
}Dio_PortType;
typedef struct
{
	Dio_PortType Port;
	Dio_ChannelType Pin;
}Dio_Channel;


#endif  /* Dio_Types_H */