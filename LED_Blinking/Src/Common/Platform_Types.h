#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#define WORD_LENGTH_BITS      32u
#define WORD_LENGTH_BYTES     4u
#define MSB_FIRST             0u    /* big endian bit ordering */
#define LSB_FIRST        1u    /* little endian bit ordering */

#define HIGH_BYTE_FIRST  0u    /* big endian byte ordering */
#define LOW_BYTE_FIRST   1u    /* little endian byte ordering */

#ifndef TRUE
   #define TRUE   1u
#endif

#ifndef FALSE
   #define FALSE  0u
#endif

#define EN    1u
#define DIS   0u

#define CPU_BIT_ORDER    LSB_FIRST        
#define CPU_BYTE_ORDER   LOW_BYTE_FIRST   

typedef unsigned char         boolean;    

typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;

typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;

typedef float                 float32;
typedef double                float64;

#ifdef PLATFORM_SUPPORT_SINT64_UINT64
typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
#endif
#endif