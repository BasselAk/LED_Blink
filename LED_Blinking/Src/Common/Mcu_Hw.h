/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "TM4C123GH6PM.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_APB	1
#define PERI_BASE 0x40000000
#define BITBAND_PERI_BASE 0x42000000
#define BITBAND_PERI(a,b) (((BITBAND_PERI_BASE + (a-PERI_BASE)*32 + (b*4))))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*****************/
/* System Control Registers*/
/*****************/
#define SYS_CTRL_BASE_ADD			0x400FE000UL


/****************************
*		NVICT
*******************************/
/* -------------------------  Interrupt Number Definition  ------------------------ */


typedef struct 
{
    uint32_t VECACT   :8;
    uint32_t          :3;
    uint32_t RETBASE  :1;
    uint32_t VECPEND  :8;
    uint32_t          :2;
    uint32_t ISRPEND  :1;
    uint32_t ISRPRE   :1;
    uint32_t          :1;
    uint32_t PENDSTCLR:1;
    uint32_t PENDSTSET:1;
    uint32_t UNPENDSV :1;
    uint32_t PENDSV   :1;
    uint32_t          :2;
    uint32_t NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32_t R;
    INTCTRL_BF B;
}INTCTRL_Tag;
/*
typedef struct
{
	uint32_t 						:1;	//VECTRESET   This bit must be written as a 0
	uint32_t 						:1;	//VECTCLRACT  This bit must be written as a 0
	uint32_t SYSRESREQ	:1;
	uint32_t 						:5;
	uint32_t PRIGROUP		:3;
	uint32_t 						:4;
	uint32_t 						:1; //ENDIANESS	  The Tiva� C Series implementation uses only little-endian mode so this is cleared to 0
	uint32_t VECTKEY		:16;
}APINT_BF;

typedef union 
{
	uint32_t R;
	APINT_BF B;
}APINT_Tag;
*/
typedef struct
{
	uint32_t 						:1;
	uint32_t	SLEEPEXIT	:1;
	uint32_t	SLEEPDEEP	:1;
	uint32_t						:1;
	uint32_t	SEVONPEND	:1;
	uint32_t						:0;
}SYSCTRL_BF;
typedef union 
{
	uint32_t R;
	SYSCTRL_BF B;
}SYSCTRL_Tag;
typedef struct
{
	uint32_t BASETHR		:1;
	uint32_t MAINPEND		:1;
	uint32_t 						:1;
	uint32_t UNALIGNED	:1;
	uint32_t DIV0				:1;
	uint32_t						:3;
	uint32_t BFHFNMIGN	:1;
	uint32_t STKALIGN		:1;
	uint32_t						:0;
}CFGCTRL_BF;
typedef union 
{
	uint32_t R;
	CFGCTRL_BF B;
}CFGCTRL_Tag;

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000UL
#define APINT                                  ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                ((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define VTABLE                                 ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0xD08))//10 LSB BITS RESERVED
#define CFGCTRL                                ((volatile CFGCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14))
#define ENABLE_BASE(x)														 ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x100+x*4))
#define EN0                                    ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define EN1                                    ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define EN2                                    ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define EN3                                    ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define EN4                                    ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))
#define DIS0                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define DIS1                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define DIS2                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define DIS3                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define DIS4                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))
#define PEND0                                  ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))
#define PEND1                                  ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x204))
#define PEND2                                  ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x208))
#define PEND3                                  ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C))
#define PEND4                                  ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x210))
#define PRI0                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define PRI1                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define PRI2                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define PRI3                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
#define PRI4                                   ((volatile uint32_t*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define WATCHDOG0_BASE                  			 ((volatile uint32_t*)(0x40000000UL+0x410))
#define WATCHDOG1_BASE                  			 ((volatile uint32_t*)(0x40001000UL+0x410))
#define TIMER_OFFSET(x)												 (x<8?(0x40030000UL+(x)*0x1000):(0x4004C000UL+(x-8)*0x1000))
#define TIMER_BASE(x)                     		 ((TIMER0_Type*)(TIMER_OFFSET(x)))
#ifdef PORT_APB
#define PORT_OFFSET(x)			(x<4?(0x40004000+(x)*0x1000):(0x40024000+(x-4)*0x1000))
#elif PORT_AHB
#define PORT_OFFSET(x)			((0x40058000)+((x)*0x1000))
#else
#error "Please choose a bus for PORTs"
#endif

#define GPIO_BASE(x)                           ((GPIOA_Type *) PORT_OFFSET(x))

#define PORTDATA(x)			*((volatile uint32_t*)(PORT_OFFSET(x)))
#define PORTDIR(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0400))
#define PORTIS(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0404)) /**< PORT Interrupt Sense>*/
#define PORTIBE(x)      	*((volatile uint32_t*)(PORT_OFFSET(x)+0x0408)) /**< PORT Interrupt Both Edges>*/
#define PORTIEV(x)      	*((volatile uint32_t*)(PORT_OFFSET(x)+0x040C)) /**< PORT Interrupt Event>*/
#define GPDIM(x)        	*((volatile uint32_t*)(PORT_OFFSET(x)+0x0410)) /**< PORT Interrupt Mask>*/
#define PORTRIS(x)      	*((volatile uint32_t*)(PORT_OFFSET(x)+0x0414)) /**< PORT Raw Interrupt Status>*/
#define PORTMIS(x)      	*((volatile uint32_t*)(PORT_OFFSET(x)+0x0418)) /**< PORT Masked Interrupt Status>*/
#define PORTICR(x)      	*((volatile uint32_t*)(PORT_OFFSET(x)+0x041C)) /**< PORT Interrupt Clear>*/
#define PORTAFSEL(x)    	*((volatile uint32_t*)(PORT_OFFSET(x)+0x0420)) /**< PORT Alternate Function Select>*/
#define PORTDR2R(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0500)) /**< PORT 2-mA Drive Select>*/
#define PORTDR4R(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0504)) /**< PORT 4-mA Drive Select>*/
#define PORTDR8R(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0508)) /**< PORT 8-mA Drive Select>*/                  
#define PORTODR(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x050c)) /**< PORT Open Drain Select>*/
#define PORTPUR(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0510)) /**< PORT Pull-Up Select>*/
#define PORTPDR(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0514)) /**< PORT Pull-Down Select>*/
#define PORTSLR(X)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0518)) /**< PORT Slew Rate Control Select>*/
#define PORTDEN(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x051C)) /**< PORT Digital Enable>*/
#define PORTLOCK(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0520)) /**< PORT Lock>*/
#define PORTCR(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x0524)) /**< PORT Commit>*/
#define PORTAMSEL(x)		*((volatile uint32_t*)(PORT_OFFSET(x)+0x0528)) /**< PORT Analog Mode Select>*/                        
#define PORTPCTL(x)			*((volatile uint32_t*)(PORT_OFFSET(x)+0x052C)) /**< PORT Port Control>*/
#define PORTADCCTL(x)		*((volatile uint32_t*)(PORT_OFFSET(x)+0x0530)) /**< PORT ADC Control>*/                     

#endif