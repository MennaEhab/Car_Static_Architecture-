/*
 ============================================================================
 Name        : std_types.h
 Author      : Muhammed Gamal
 Description :
 ============================================================================
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/************************************************************************/
/*                   typedefs for standard types                        */
/************************************************************************/

#define NULL	((void *)0)

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed int sint16_t;
typedef signed long int sint32_t;
typedef signed long long sint64_t;
typedef volatile uint8_t* const reg_type8_t;
typedef volatile uint16_t* const reg_type16_t;

typedef uint8_t  ERROR_STATUS;
typedef uint8_t  bool_t;
/************************************************************************/
/*				 		defining boolean values                         */
/************************************************************************/
#define FALSE 	0	// defines boolean false
#define TRUE 	1	// defines boolean true


/************************************************************************/
/*						 LOW/HIGH defines                               */
/************************************************************************/
#define LOW  0		// defines LOW value for a bit
#define HIGH 0xFF	// defines HIGH value for a bit

#define E_OK 0     // error status is OK
#define E_NOK 1    // error status is not OK



#define ZERO_VALUE 0

#define SET_BIT(REG,BIT) REG|=(1<<BIT)

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT) REG&=(~(1<<BIT))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))


#endif /* STD_TYPES_H_ */
