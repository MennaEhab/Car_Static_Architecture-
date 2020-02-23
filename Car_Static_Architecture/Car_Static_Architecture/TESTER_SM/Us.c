/*
 * Us.c
 *
 * Created: 2/18/2020 4:09:24 PM
 *  Author: MENA
 */
#include "Us.h"

/****************************************************************************************************
 * Function Name   : Us_Init.                                                                       *
 * Input Parameters : None.                                                                         *                                                                   *                                                                                                *
 * Output Parameters: None.                                                                         *
 * In_Out Parameters: None.                                                                         *
 * Return           : ERROR_STATUS.                                                                 *
 * Description      : This function initiate the UltraSonic by initiate the ICU to use it to calculate the *
 *                    On time of the ECHO signal.                                                   *
 *                                                                                                  *
 *                                                                                                  *
 ***************************************************************************************************/

uint8_t a_u8_error_state_Us_init = E_OK ;
uint8_t a_u8_error_stateUs_trigger = E_OK ;
uint8_t a_u8_error_stateUs_GetDistance = E_OK ;
uint8_t g_test_distance = 0 ;
ERROR_STATUS Us_Init(void){


		return a_u8_error_state_Us_init ;
}




/**************************************************************************************************
 * Function Name    : Us_Trigger.                                                                 *
 * Input Parameters : None.                                                                       *                                                                              *                                                                                                *
 * Output Parameters: None.                                                                       *
 * In_Out Parameters: None.                                                                       *
 * Return           : ERROR_STATUS                                                                *
 * Description      : This function initialize the trigger by set the value of the Dio_Dirction of *
 *                    the pin trigger as an output then send the  pulse, to trigger pin of the UltraSonic to enhance  *
 *                    the  EChO signal                                                            *
 *************************************************************************************************/




ERROR_STATUS Us_Trigger(void){



	return a_u8_error_stateUs_trigger ;

}



/**************************************************************************************************
 * Function Name    : Us_GetDistance.                                                             *
 * Input Parameters : pointer to uint16 that will return the distance on it.                      *                                                                                              *                                                                                                *
 * Output Parameters: Distance.                                                                   *
 * In_Out Parameters: None.                                                                       *
 * Return           : ERROR_STATUS.                                                               *
 * Description      : This function get the time of high signal of ECUO pulse, then               *
 *                    use it to calculate the distance, then return the value in the              *
 *                    Distance parameter.                                                         *
 *************************************************************************************************/


ERROR_STATUS Us_GetDistance(uint16_t *Distance){


		if (Distance==NULL)
		{
			 a_u8_error_stateUs_GetDistance |= E_NOK ;
		}else{

			a_u8_error_stateUs_GetDistance |= E_OK ;
            *Distance = g_test_distance ;
		}

		return a_u8_error_stateUs_GetDistance ;

}
