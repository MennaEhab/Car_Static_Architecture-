/*
 * Steering.c
 *
 * Created: 2/18/2020 7:32:11 PM
 *  Author: MENA
 */ 

#include "Steering.h"
#include "motor.h"

ERROR_STATUS Steering_Init(void){
	
	Motor_Init(MOTOR_1);
	Motor_Init(MOTOR_2);
	return E_OK ;
}


ERROR_STATUS Steering_SteerCar(uint8_t Steering_CarCmd, uint8_t speed){
	
	ERROR_STATUS state_error = E_OK ;
	

	
	switch(Steering_CarCmd){
		case CAR_STOP:
		Motor_Direction(MOTOR_1,MOTOR_STOP);
		Motor_Direction(MOTOR_2,MOTOR_STOP);
		break;
		case CAR_FORWARD:
		Motor_Direction(MOTOR_1,MOTOR_FORWARD);
		Motor_Direction(MOTOR_2,MOTOR_FORWARD);
		break;
		case CAR_BACKWARD:
		Motor_Direction(MOTOR_1,MOTOR_BACKWARD);
		Motor_Direction(MOTOR_2,MOTOR_BACKWARD);
		break;
		case CAR_RIGHT:
		Motor_Direction(MOTOR_1,MOTOR_FORWARD);
		Motor_Direction(MOTOR_2,MOTOR_BACKWARD);
		break;
		case CAR_LEFT:
		Motor_Direction(MOTOR_2,MOTOR_BACKWARD);
		Motor_Direction(MOTOR_1,MOTOR_FORWARD);
		break;
		default:
		state_error=E_NOK;
		
	}
		Motor_Start(MOTOR_1,speed);
		Motor_Start(MOTOR_2,speed);
		return state_error ;
	
}
