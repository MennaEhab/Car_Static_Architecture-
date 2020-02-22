/*
 * TimerDelay.c
 *
 * Created: 2/17/2020 5:16:33 PM
 *  Author: MENA
 */ 
#include "Timer.h"
#include "TimerDelay.h"

ERROR_STATUS timerDelayMs(uint16_t u16_delay_in_ms){
	
	ERROR_STATUS state_error = E_OK ;
	
	uint8_t ovf_flag = ZERO_VALUE ;
	Timer_cfg_s Timer_cfg ;
	Timer_cfg.Timer_CH_NO = TIMER_CH2 ;
	Timer_cfg.Timer_Mode = TIMER_MODE ;
	Timer_cfg.Timer_Polling_Or_Interrupt = TIMER_POLLING_MODE ;
	Timer_cfg.Timer_Prescaler = TIMER_PRESCALER_64 ;
	
	state_error |= Timer_Init(&Timer_cfg) ;
	
	/************************************************************************/
	/* 250 number of tick  for 1 millisecond - 11 ticks error due to function calls*/
	/************************************************************************/
		
		state_error |= Timer_Start(Timer_cfg.Timer_CH_NO , 239 );
		
		/* delay required in millisecond */
		
		while (u16_delay_in_ms)
		{
			/* polling on ovf flag */
			
			state_error |= Timer_GetStatus (Timer_cfg.Timer_CH_NO , &ovf_flag);
			if(ovf_flag == TRUE)
			{
				u16_delay_in_ms -- ;
			}
			
		}
		state_error |= Timer_Stop(Timer_cfg.Timer_CH_NO);
	
	return state_error ;
}