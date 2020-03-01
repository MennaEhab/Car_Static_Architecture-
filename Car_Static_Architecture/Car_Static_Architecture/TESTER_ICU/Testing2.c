/*
 ============================================================================
 Name        : Testing.c
 Author      : Muhammed Gamal
 Description : this file test the ICU driver
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../ICU.h"
#include "Testing2.h"

#define NONE_VALID_INT_CH 3
#define NONE_VALID_TIMER_CH 3
#define NONE_VALID_EDGE_STATE 3

extern volatile uint8_t g_fallingEdgeFlag ;


int Tester_ICU(void) {
	uint8_t u8_status1;
	uint8_t u8_status2;
	uint8_t u8_status3;
	uint8_t u8_status4;
	uint8_t u8_status5;
	uint8_t u8_status6;
	uint8_t u8_status7;
	uint8_t u8_status8;
	uint8_t u8_status9;
	uint8_t u8_status10;
	uint8_t u8_status11;
	uint8_t u8_status12;
	uint8_t u8_status13;
	uint8_t u8_status14;
	uint8_t u8_status15;
	uint8_t u8_status16;
	uint8_t u8_status17;


	uint32_t u32_time;
	uint8_t u8_time;
	uint8_t* testcase5=NULL;


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a valid data to "Icu_Init"
	* Expected OUTPUT: passed
	* Real OUTPUT: PASSED
	************************************************************************************/
	Icu_cfg_s testcase1={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER0*/
	u8_status1 = Icu_Init(&testcase1);
	if(u8_status1==E_ok)
	{
		printf("valid address with a valid data (test case 1): PASSED\n");
	}
	else
	{
		printf("valid address with a valid data test (test case 1): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a non valid data (timer 2)to "Icu_Init"
	* Note that : timer2 is used in time delay functions
	* Expected OUTPUT: PASSED
	* Real OUTPUT: FAILED due to the other use of timer2
	************************************************************************************/
	Icu_cfg_s testcase2={ICU_CH2,ICU_TIMER_CH2};    /*INT2,TIMER2*/
	u8_status2 = Icu_Init(&testcase2);
	if(u8_status2==E_ok)
	{
		printf("valid address with a valid data (test case 2): PASSED\n");
	}
	else
	{
		printf("valid address with a valid data (test case 2): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a none-valid data (Timer1) data to "Icu_Init"
	* NOTE THAT: timer1 shouldn't be handled due to hardware limitations
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/

	Icu_cfg_s testcase3={ICU_CH2,ICU_TIMER_CH1};    //INT1,TIMER1
	u8_status3 = Icu_Init(&testcase3);
	if(u8_status3==E_ok)
	{
		printf("valid address with a none-valid data (Timer1) data (test case 3): PASSED\n");
	}
	else
	{
		printf("valid address with a none-valid data (Timer1) data (test case 3): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a valid data to "Icu_Init"
	* Expected OUTPUT: PASSED
	* Real OUTPUT: PASSED
	************************************************************************************/

	Icu_cfg_s testcase4={ICU_CH2,ICU_TIMER_CH0};    //INT2,TIMER0
	u8_status4 = Icu_Init(&testcase4);
	if(u8_status4==E_ok)
	{
		printf("valid address with a valid data (test case 4): PASSED\n");
	}
	else
	{
		printf("valid address with a valid data (test case 4): FAILED\n");
	}



	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a NULL pointer to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	u8_status5 = Icu_Init(testcase5);
	if(u8_status5==E_ok)
	{
		printf("NULL pointer (test case 5) PASSED\n");
	}
	else
	{
		printf("NULL pointer (test case 5): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a wiled pointer to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: CODE CRASH
	* NOTE: this test case has to be commented while testing any other test case
	************************************************************************************/
/*
	uint8_t* testcase6;
	u8_status6 = Icu_Init(testcase6);
	if(u8_status6==0)
	{
		printf("wiled pointer (test case 6): PASSED\n");
	}
	else
	{
		printf("wiled pointer (test case 6) FAILED\n");
	}
*/

	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a variable address from different data type to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	int testcase7={ICU_CH2,ICU_TIMER_CH2};
	u8_status7 = Icu_Init(&testcase7);
	if(u8_status7==E_ok)
	{
		printf("variable address from different data type (test case 7): PASSED\n");
	}
	else
	{
		printf("variable address from different data type (test case 7): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a none-valid interrupt number to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase8={NONE_VALID_INT_CH,ICU_TIMER_CH2};    /*INT2,TIMER2*/
	u8_status8 = Icu_Init(&testcase8);
	if(u8_status8==E_ok)
	{
		printf("valid address with a none-valid interrupt number (test case 8): PASSED\n");
	}
	else
	{
		printf("valid address with a none-valid interrupt number (test case 8): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_Init
	* Test Case: send a valid address with a none-valid timer number to "Icu_Init"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase9={ICU_CH2,NONE_VALID_TIMER_CH};    /*INT2,TIMER2*/
	u8_status9 = Icu_Init(&testcase9);
	if(u8_status9==E_ok)
	{
		printf("valid address with a none-valid timer number (test case 9): PASSED\n");
	}
	else
	{
		printf("valid address with a none-valid timer number (test case 9): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a valid data after initialization to "Icu_ReadTime"
	* Expected OUTPUT: PASSED
	* Real OUTPUT: PASSED
	************************************************************************************/
	Icu_cfg_s testcase10={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER2*/
	u8_status10 |= Icu_Init(&testcase10);
    g_fallingEdgeFlag = TRUE ;

	u8_status10 |= Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&u32_time);
	if(u8_status10==E_ok)
	{
		printf("valid data after initialization (test case 10): PASSED\n");
	}
	else
	{
		printf("valid data after initialization (test case 10): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a valid data without initialization to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
    g_fallingEdgeFlag = TRUE ;
	u8_status11 |= Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&u32_time);
	if(u8_status11==E_ok)
	{
		printf("valid data without initialization (test case 11): PASSED\n");
	}
	else
	{
		printf("valid data without initialization (test case 11): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a none-valid data after initialization to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase12={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER0*/
	u8_status12 |= Icu_Init(&testcase12);
    g_fallingEdgeFlag = TRUE ;
	u8_status12 |= Icu_ReadTime(NONE_VALID_TIMER_CH,ICU_RISE_TO_FALL,&u32_time);
	if(u8_status12==E_ok)
	{
		printf("none-valid data after initialization (test case 12): PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization (test case 12): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a none-valid data after initialization to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: FAILED
	************************************************************************************/
	Icu_cfg_s testcase13={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER0*/
	u8_status13 |= Icu_Init(&testcase13);
	g_fallingEdgeFlag = TRUE ;
	u8_status13 |= Icu_ReadTime(ICU_TIMER_CH0,NONE_VALID_EDGE_STATE,&u32_time);
	if(u8_status13==E_ok)
	{
		printf("none-valid data after initialization (test case 13): PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization (test case 13): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a none-valid data after initialization (an argument from different
	* data type) to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: PASSED
	************************************************************************************/
	Icu_cfg_s testcase14={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER2*/
	u8_status14 |= Icu_Init(&testcase14);
	g_fallingEdgeFlag = TRUE ;
	u8_status14 |= Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&u8_time);
	if(u8_status14==E_ok)
	{
		printf("none-valid data after initialization (test case 14): PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization (test case 14): FAILED\n");
	}


	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send a none-valid data after initialization (the 3rd argument with out
	* the address reference) to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: Code Crash
	* NOTE: this test case has to be commented while testing any other test case
	************************************************************************************/
/*
	Icu_cfg_s testcase15={ICU_CH2,ICU_TIMER_CH0};    //INT2,TIMER2
	u8_status15 |= Icu_Init(&testcase15);
	g_fallingEdgeFlag = TRUE ;
	u8_status15 |= Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,u32_time);
	if(u8_status15==E_ok)
	{
		printf("none-valid data after initialization (test case 15): PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization (test case 15): FAILED\n");
	}

*/

	/************************************************************************************
	* Target Function: Icu_ReadTime
	* Test Case: send an uninitialized timer channel to "Icu_ReadTime"
	* Expected OUTPUT: FAILED
	* Real OUTPUT: PASSED
	************************************************************************************/
	Icu_cfg_s testcase16={ICU_CH2,ICU_TIMER_CH0};    /*INT2,TIMER0*/
	u8_status16 |= Icu_Init(&testcase16);
	g_fallingEdgeFlag = TRUE ;
	u8_status16 |= Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&u32_time);
	if(u8_status16==E_ok)
	{
		printf("none-valid data after initialization (test case 16): PASSED\n");
	}
	else
	{
		printf("none-valid data after initialization (test case 16): FAILED\n");
	}



	return 0;
}




