/*
 * TimerDelay.h
 *
 * Created: 2/17/2020 5:16:15 PM
 *  Author: MENA
 */


#ifndef TIMERDELAY_H_
#define TIMERDELAY_H_

#include "std_types.h"


/**
 * Input: nothing
 * Output: nothing
 * In/Out:	nothing
 * Return: The error status of the function.
 * Description: Initiates the module , initialize MOTOR_1 & MOTOR_2
 *
 */

ERROR_STATUS timerDelayMs(uint16_t u16_delay_in_ms);




#endif /* TIMERDELAY_H_ */
