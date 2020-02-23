/*
 * TimerDelay.c
 *
 * Created: 2/17/2020 5:16:33 PM
 *  Author: MENA
 */

 #include "TimerDelay.h"

uint8_t a_u8_error_state_timerDelayMs = E_OK ;


ERROR_STATUS timerDelayMs(uint16_t u16_delay_in_ms){

	return a_u8_error_state_timerDelayMs ;
}
