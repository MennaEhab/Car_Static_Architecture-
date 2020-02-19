/*
 * TimerDelay.c
 *
 * Created: 2/17/2020 5:16:33 PM
 *  Author: MENA
 */ 
#include "Timer.h"
#include "TimerDelay.h"
void timerDelayMs(uint16_t u16_delay_in_ms){
	
	uint8_t ovf_flag = 0 ;
	Timer_cfg_s Timer_cfg ;
	Timer_cfg.Timer_CH_NO = TIMER_CH2 ;
	Timer_cfg.Timer_Mode = TIMER_MODE ;
	Timer_cfg.Timer_Polling_Or_Interrupt = TIMER_POLLING_MODE ;
	Timer_cfg.Timer_Prescaler = TIMER_PRESCALER_64 ;
	
	Timer_Init(&Timer_cfg) ;
	// base 5 since 250 tick is 1 milisec + error 12
		
		// no of ticks for one milli sec
		
		Timer_Start(Timer_cfg.Timer_CH_NO , 239 );
		
		while (u16_delay_in_ms)
		{
			Timer_GetStatus (Timer_cfg.Timer_CH_NO , &ovf_flag);
			if(ovf_flag == TRUE)
			{
				u16_delay_in_ms -- ;
			}
			
		}
		Timer_Stop(Timer_cfg.Timer_CH_NO);
	
	
}