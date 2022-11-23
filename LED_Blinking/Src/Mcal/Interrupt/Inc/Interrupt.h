#ifndef IntCrtl_H
#define IntCrtl_H

#include "Std_Types.h"
#include "Interrupt_Types.h"
#include "Interrupt_Cfg.h"

extern IntCtrl_ConfigType ISRs[INT_CONFIGURED];

void IntCrtl_Init(const IntCtrl_ConfigType*ConfigPtr);
 
#endif  