/*
 ============================================================================
 Name        : interrupt.c
 Author      : Muhammed Gamal
 Description : 
 ============================================================================
 */
#include "external_interrupts.h"

#define NULL_Ptr ((void*)0)


volatile uint8_t g8_state;
volatile uint8_t g8_interrupt_zero_flag=0;
volatile uint8_t g8_echo_flag=0;

/************************INT0*****************************************/
ERROR_STATUS INT0_Init(EN_Edge_t en_edge_selection)
{
	uint8_t u8_status;


	switch(en_edge_selection)
	{
	case LOW_LEVEL:

		u8_status |= E_ok;
		break;

	case ANY_CHANGE:

		u8_status |= E_ok;
		break;

	case FALLING_EDGE:

		u8_status |= E_ok;
		break;

	case RISIGING_EDGE:

		u8_status |= E_ok;
		break;

	default:
		u8_status |= E_NOk;
		break;
	}


	if(u8_status == E_ok)
	{
		u8_status=E_ok;
	}
	else
	{
		u8_status = E_NOk;
	}

	return u8_status;
}


ERROR_STATUS INT0_DeInit(void)
{
	uint8_t u8_status;

	u8_status |= E_ok;
	return u8_status;
}

/****************************INT1*******************************************/
ERROR_STATUS INT1_Init(EN_Edge_t en_edge_selection)
{
	uint8_t u8_status;

	switch(en_edge_selection)
	{
	case LOW_LEVEL:

		u8_status |= E_ok;
		break;

	case ANY_CHANGE:

		u8_status |= E_ok;
		break;

	case FALLING_EDGE:

		u8_status |= E_ok;
		break;

	case RISIGING_EDGE:

		u8_status |= E_ok;
		break;

	default:
		u8_status |= E_NOk;
		break;
	}

	if(u8_status == E_ok)
	{
		u8_status = E_ok;
	}
	else
	{
		u8_status = E_NOk;
	}

	return u8_status;
}

ERROR_STATUS INT1_DeInit(void)
{
	uint8_t u8_status;

	u8_status |= E_ok;
	return u8_status;
}

/****************************INT2*******************************************/
ERROR_STATUS INT2_Init(EN_Edge_t en_edge_selection)
{
	uint8_t u8_status;

	switch(en_edge_selection)
	{
	case LOW_LEVEL:
										/*this case is not exist*/
		u8_status |= E_NOk;
		break;

	case ANY_CHANGE:
										/*this case is not exist*/
		u8_status |= E_NOk;
		break;

	case FALLING_EDGE:

		u8_status |= E_ok;
		break;

	case RISIGING_EDGE:

		u8_status|= E_ok;
		break;

	default:
		u8_status |= E_NOk;
		break;
	}

	if(u8_status == E_ok)
	{
		u8_status=E_ok;
	}
	else
	{
		u8_status = E_NOk;
	}

	return u8_status;
}

ERROR_STATUS INT2_DeInit(void)
{
	uint8_t u8_status;

	u8_status |= E_ok;
	return u8_status;
}

ERROR_STATUS INT2_SetEdge(EN_Edge_t en_edge_selection)
{
	uint8_t u8_status;
	/*I have to check first if it is enabled or not*/
	switch(en_edge_selection)
	{
	case LOW_LEVEL:
		                                /*this case is not exist*/
		break;

	case ANY_CHANGE:
		                                /*this case is not exist*/
		break;

	case FALLING_EDGE:

		break;

	case RISIGING_EDGE:

		break;

	default:
		u8_status |= E_NOk;
		break;
	}

	if(u8_status == E_ok)
	{
		u8_status=E_ok;
	}
	else
	{
		u8_status = E_NOk;
	}
	return u8_status;
}
/***************************************************************************/


/********************************ISRS***************************************/

ISR(INT2_vect)
{
	if(g_callBackPtr != NULL_Ptr)
	{
		// Call the Call Back function in the application after the edge is detected
		(*g_callBackPtr)(); // another method to call the function using pointer to function g_callBackPtr();
	}

}

/******************************************************************************/
