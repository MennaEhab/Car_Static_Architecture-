/*
 * Us.c
 *
 * Created: 2/18/2020 4:09:24 PM
 *  Author: MENA
 */ 

#include "Us.h"
#include "TimerDelay.h"

ERROR_STATUS Us_Init(void){
	
		Icu_cfg_s icuCfg;
		icuCfg.ICU_Ch_Timer = ICU_TIMER_CH0;
		icuCfg.ICU_Ch_No = ICU_CH2;
		Icu_Init(&icuCfg);
		return E_OK ;
}

ERROR_STATUS Us_Trigger(void){
	DIO_Cfg_s dioCfgtrig;
	
	dioCfgtrig.GPIO = GPIOC;
	dioCfgtrig.pins = BIT7;
	dioCfgtrig.dir =OUTPUT;
	DIO_init(&dioCfgtrig);
	
	//trigger
DIO_Write(GPIOC,BIT7,HIGH)	;
	timerDelayMs(10);
	
DIO_Write(GPIOC,BIT7,LOW)	;
	
	return E_OK ;
	
}



ERROR_STATUS Us_GetDistance(uint16_t *Distance){
	
		
		uint32_t timerOfTicks_Us  ;
		
		Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&timerOfTicks_Us);
		
		
		*Distance = timerOfTicks_Us/58 ;
	
		//Distance = 3 ;
		return E_OK;
	
}