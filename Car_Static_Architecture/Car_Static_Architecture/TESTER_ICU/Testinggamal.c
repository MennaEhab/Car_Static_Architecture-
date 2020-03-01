/*
 ============================================================================
 Name        : Testing.c
 Author      : muhammed gamal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ICU.h"


#define NONE_VALID_INT_CH 3
#define NONE_VALID_TIMER_CH 3
#define NONE_VALID_EDGE_STATE 3

extern volatile uint8_t g_fallingEdgeFlag ;

int main(void) {
	uint8_t u8_status;
	uint32_t u32_time;
	uint8_t u8_time;
	uint8_t* testcase5=NULL;
	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a valid data to "Icu_Init"
	* Expected OUTPUT: PASSED
	* Real OUTPUT: PASED
	************************************************************************************/
	Icu_cfg_s testcase1={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER2*/
	u8_status = Icu_Init(&testcase1);
	if(u8_status==E_OK)
	{
		printf("valid address with a valid data test case: PASSED\n");
	}
	else
	{
		printf("valid address with a valid data test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a valid data to "Icu_Init"
	* Expected OUTPUT: PASSED
	* Real OUTPUT: PASED
	************************************************************************************/
	Icu_cfg_s testcase2={ICU_CH0,ICU_TIMER_CH0};    /*INT0,TIMER0*/
	u8_status = Icu_Init(&testcase2);
	if(u8_status==E_ok)
	{
		printf("valid address with a valid data test case: PASSED\n");
	}
	else
	{
		printf("valid address with a valid data test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a none-valid data (Timer1) data to "Icu_Init"
	* NOTE THAT: timer1 shouldn't be handled due to hardware limitations
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/

	Icu_cfg_s testcase3={ICU_CH1,ICU_TIMER_CH1};    //INT1,TIMER1
	u8_status = Icu_Init(&testcase3);
	if(u8_status==E_ok)
	{
		printf("valid address with a none-valid data (Timer1) data test case: PASSED\n");
	}
	else
	{
		printf("valid address with a none-valid data (Timer1) data test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a valid data to "Icu_Init"
	* Expected OUTPUT: PASSED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase4={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER0*/
	u8_status = Icu_Init(&testcase4);
	if(u8_status==E_ok)
	{
		printf("valid address with a valid data test case: PASSED\n");
	}
	else
	{
		printf("valid address with a valid data test case: FAILED\n");
	}



	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a NULL pointer to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	u8_status = Icu_Init(testcase5);
	if(u8_status==E_ok)
	{
		printf("NULL pointer test case: PASSED\n");
	}
	else
	{
		printf("NULL pointer test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a wiled pointer to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: CODE CRASH
	* NOTE: this test case has to be commented while testing any other test case
	************************************************************************************/
/*
	char* testcase6;
	u8_status = Icu_Init(testcase6);
	if(u8_status==0)
	{
		printf("wiled pointer test case: PASSED\n");
	}
	else
	{
		printf("wiled pointer test case FAILED\n");
	}
*/

	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a variable address from different data type to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: passed
	************************************************************************************/
	int testcase7={ICU_CH2,ICU_TIMER_CH2};
	u8_status = Icu_Init(&testcase7);
	if(u8_status==E_ok)
	{
		printf("variable address from different data type test case: PASSED\n");
	}
	else
	{
		printf("variable address from different data type test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a none-valid interrupt number to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase8={NONE_VALID_INT_CH,ICU_TIMER_CH2};    /*INT2,TIMER2*/
	u8_status = Icu_Init(&testcase8);
	if(u8_status==E_ok)
	{
		printf("valid address with a none-valid interrupt number test case: PASSED\n");
	}
	else
	{
		printf("valid address with a none-valid interrupt number test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a none-valid timer number to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase9={ICU_CH2,NONE_VALID_TIMER_CH};    /*INT2,TIMER2*/
	u8_status = Icu_Init(&testcase9);
	if(u8_status==E_ok)
	{
		printf("valid address with a none-valid timer number test case: PASSED\n");
	}
	else
	{
		printf("valid address with a none-valid timer number test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a valid data after initialization to "Icu_ReadTime"
	* Expected OUTPUT: PASSED
	* Real OUTPUT: PASSED
	************************************************************************************/
	Icu_cfg_s testcase10 ={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER0*/
	u8_status |= Icu_Init(&testcase10);
	g_fallingEdgeFlag = TRUE ;

	u8_status |= Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&u32_time);
	if(u8_status==E_ok)
	{
		printf("valid data after initialization test case: PASSED\n");
	}
	else
	{
		printf("valid data after initialization test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a valid data without initialization to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
    g_fallingEdgeFlag = TRUE ;

	u8_status |= Icu_ReadTime(ICU_TIMER_CH2,ICU_RISE_TO_FALL,&u32_time);
	if(u8_status==E_ok)
	{
		printf("valid data without initialization test case: PASSED\n");
	}
	else
	{
		printf("valid data without initialization test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a none-valid data after initialization to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase12={ICU_CH2,ICU_TIMER_CH2};    /*INT2,TIMER2*/
	u8_status |= Icu_Init(&testcase12);
    g_fallingEdgeFlag = TRUE ;

	u8_status |= Icu_ReadTime(NONE_VALID_TIMER_CH,ICU_RISE_TO_FALL,&u32_time);
	if(u8_status==E_ok)
	{
		printf("none-valid data after initialization test case: PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a none-valid data after initialization to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase13={ICU_CH2,ICU_TIMER_CH2};    /*INT2,TIMER2*/
	u8_status |= Icu_Init(&testcase13);
    g_fallingEdgeFlag = TRUE ;

	u8_status |= Icu_ReadTime(Timer_0,NONE_VALID_EDGE_STATE,&u32_time);
	if(u8_status==E_ok)
	{
		printf("none-valid data after initialization test case: PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a none-valid data after initialization (an argument from different
	* data type) to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase14={ICU_CH2,ICU_TIMER_CH2};    /*INT2,TIMER2*/
	u8_status |= Icu_Init(&testcase14);
    g_fallingEdgeFlag = TRUE ;

	u8_status |= Icu_ReadTime(Timer_0,NONE_VALID_EDGE_STATE,&u8_time);
	if(u8_status==E_ok)
	{
		printf("none-valid data after initialization test case: PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization test case: FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a none-valid data after initialization (the 3rd argument with out
	* the address reference) to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase15={ICU_CH2,ICU_TIMER_CH2};    /*INT2,TIMER2*/
	u8_status |= Icu_Init(&testcase15);
    g_fallingEdgeFlag = TRUE ;

	u8_status |= Icu_ReadTime(Timer_0,NONE_VALID_EDGE_STATE,u32_time);
	if(u8_status==E_ok)
	{
		printf("none-valid data after initialization test case: PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization test case: FAILED\n");
	}
}




