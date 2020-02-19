/*
 * car_sm.c
 *
 * Created: 2/18/2020 8:02:47 PM
 *  Author: MENA
 */ 

#include "car_sm.h"
#include "Steering.h"
#include "TimerDelay.h"
#include "Us.h"
/*******************       States of state machine       *********/

#define FORWARD_STATE 0
#define BACKWARD_STATE 1
#define TURNING_STATE 2
#define STOP_STATE 3

uint8_t g_state ;



ERROR_STATUS Car_SM_Init(void){
	
	ERROR_STATUS state_error = E_OK ;
	
	state_error |= Steering_Init();
	
	state_error |= Us_Init();
	
	g_state=STOP_STATE ;
	
	return state_error ;
}


ERROR_STATUS Car_SM_Update(void){
	
	uint16_t distance;
	ERROR_STATUS state_error = E_OK ;
	
	state_error |= Us_Trigger();
	state_error |= Us_GetDistance(&distance);
	
	//timerDelayMs(10);
	

	
	switch(g_state){
		
		case STOP_STATE :
			if (distance<20){
				
				g_state = BACKWARD_STATE ;
			}
			else if ((distance<=40) && (distance>=20)){
				
				g_state =TURNING_STATE ;
			}else
				g_state = FORWARD_STATE ;
			break;
			
		case FORWARD_STATE :
		
			if (distance<20){
				g_state = BACKWARD_STATE;
			}else if ( distance<=40 && distance>=20 )
			{
				g_state=TURNING_STATE;
			}
			else
				state_error |= Steering_SteerCar(CAR_FORWARD,30);
			break;
				
		case BACKWARD_STATE:
		
			if (distance<20){
				state_error |= Steering_SteerCar(CAR_BACKWARD,30);
			}else if (distance<=40&&distance>=20)
			{
				g_state=TURNING_STATE;
			}
			 else{
				g_state = FORWARD_STATE ;
			}
			break;
			
		case TURNING_STATE :
		
			if (distance<=40&&distance>=20)
			{
				state_error |= Steering_SteerCar(CAR_LEFT,30);
			}else if (distance <20){
				g_state = BACKWARD_STATE ;
			}
			else
			g_state = FORWARD_STATE ;
			
			break;
		
	}
	
	
	return state_error ;
	
}

