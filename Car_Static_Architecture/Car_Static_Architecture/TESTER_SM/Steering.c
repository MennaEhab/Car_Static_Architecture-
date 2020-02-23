/*
 * Steering.c
 *
 * Created: 2/18/2020 7:32:11 PM
 *  Author: MENA
 */

#include "Steering.h"


/**
 * Input: nothing
 * Output: nothing
 * In/Out:	nothing
 * Return: The error status of the function.
 * Description: Initiates the module , initialize MOTOR_1 & MOTOR_2
 *
 */



 uint8_t a_u8_error_state_Steering_Init = E_OK ;

uint8_t a_u8_error_state_Steering_SteerCar = E_OK ;



ERROR_STATUS Steering_Init(void){


	return a_u8_error_state_Steering_Init;
}


/**
 * Input:
 * 	carDirection: The direction of the car from the predefined states of the module:
																					-> car_STOP
																					->CAR_FOTWARD
																					->CAR_BACKWARD
																					->CAR_RIGHT
																					->CAR_LEFT
 * 	speed: The speed of the car from 0% to 100%.
 * Output: nothing
 * In/Out:
 * Return: The error status of the function.
 * Description: This function controls the command and the speed of the car.
 *
 */

ERROR_STATUS Steering_SteerCar(uint8_t Steering_CarCmd, uint8_t speed){



/****************************  set motor direction ********************************************/


	switch(Steering_CarCmd){
		case CAR_STOP:
		a_u8_error_state_Steering_SteerCar = E_OK ;
		break;
		case CAR_FORWARD:
		a_u8_error_state_Steering_SteerCar = E_OK ;
		break;
		case CAR_BACKWARD:
		a_u8_error_state_Steering_SteerCar = E_OK ;
		break;
		case CAR_RIGHT:
		a_u8_error_state_Steering_SteerCar = E_OK ;
		break;
		case CAR_LEFT:
		a_u8_error_state_Steering_SteerCar = E_OK ;
		break;
		default:
		a_u8_error_state_Steering_SteerCar = E_NOK ;

	}

	/****************************  start motor direction ********************************************/


		return a_u8_error_state_Steering_SteerCar ;

}
