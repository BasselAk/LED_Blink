#ifndef STD_TYPES_H
#define STD_TYPES_H

# include "Platform_Types.h"
# include "Compiler.h"

# define STD_HIGH     1u 
# define STD_LOW      0u 

# define STD_ACTIVE   1u 
# define STD_IDLE     0u 

# define STD_ON       1u
# define STD_OFF      0u

#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       
#endif
#define     __O     volatile             
#define     __IO    volatile             
#define     __IM     volatile const      
#define     __OM     volatile            
#define     __IOM    volatile            
	
typedef uint8_t Std_ReturnType;
#define E_OK          0u
#define E_NOT_OK      1u

#endif