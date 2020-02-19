/*
 * motor.c
 *
 * Created: 2/18/2020 10:07:19 AM
 *  Author: MENA
 */ 

#include "motor.h"
#include "PWM.h"

 ERROR_STATUS Motor_Init(uint8_t Motor_Number){
	 
	 
	 
	 DIO_Cfg_s dioCfg_M;
	  Pwm_Cfg_s pwm_cfgA ;
	 Pwm_Cfg_s pwm_cfgB ;
	 
	 	switch (Motor_Number)
	 	{
		 	case MOTOR_1:
			
			 pwm_cfgA.Channel = PWM_CH1A ;
			 pwm_cfgA.Prescaler = PWM_PRESCALER_1024 ;
			 Pwm_Init(&pwm_cfgA);
			 dioCfg_M.GPIO=MOTOR_OUT_1A_GPIO;
			 dioCfg_M.pins=MOTOR_OUT_1A_BIT|MOTOR_OUT_1B_BIT|MOTOR_EN_1_BIT;
			 dioCfg_M.dir=OUTPUT;
			 
			 
		 	 DIO_init (&dioCfg_M);

		 	 DIO_Write (dioCfg_M.GPIO, dioCfg_M.pins , LOW);

		 	
		 	break;
		 	
		 	case MOTOR_2:
			 
			 pwm_cfgB.Channel = PWM_CH1B ;
			 pwm_cfgB.Prescaler = PWM_PRESCALER_1024 ;
			 Pwm_Init(&pwm_cfgB);
			 dioCfg_M.GPIO=MOTOR_OUT_2A_GPIO;
			 dioCfg_M.pins=MOTOR_OUT_2A_BIT|MOTOR_OUT_2B_BIT|MOTOR_EN_2_BIT;
			 dioCfg_M.dir=OUTPUT;
			 
			 
			 DIO_init (&dioCfg_M);

			 DIO_Write (dioCfg_M.GPIO, dioCfg_M.pins , LOW);

			 break;

			 default:
			 return E_NOK ;
			 break;
	 	}
	 return E_OK ;
 }


ERROR_STATUS Motor_Direction(uint8_t Motor_Number, uint8_t Motor_Direction){
	
	
	
		switch (Motor_Number)
		{
			//////////motor1///////////
			case MOTOR_1:
			switch (Motor_Direction)
			{
				case MOTOR_FORWARD:
				DIO_Write (MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT , LOW);
				DIO_Write (MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT , HIGH);
				break;
				
				case MOTOR_BACKWARD:
				
				DIO_Write (MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT , HIGH);
				DIO_Write (MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT , LOW);
				break;
				
				case MOTOR_STOP:
				
				DIO_Write (MOTOR_OUT_1A_GPIO, MOTOR_OUT_1A_BIT , LOW);
				DIO_Write (MOTOR_OUT_1B_GPIO, MOTOR_OUT_1B_BIT , LOW);
				break;
				
				default:
				break;
			}
			break;
			
			////////motor2//////////
			case MOTOR_2:
			switch (Motor_Direction)
			{
				case MOTOR_FORWARD:
				DIO_Write (MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT , HIGH);
				DIO_Write (MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT , LOW);
				break;
				case MOTOR_BACKWARD:
				DIO_Write (MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT , LOW);
				DIO_Write (MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT , HIGH);
				break;
				case MOTOR_STOP:
				DIO_Write (MOTOR_OUT_2A_GPIO, MOTOR_OUT_2A_BIT , LOW);
				DIO_Write (MOTOR_OUT_2B_GPIO, MOTOR_OUT_2B_BIT , LOW);
				break;
				default:
				return E_NOK ;
				break;
			}
			break;
			
			default:
			return E_NOK ;
			break;
		}
		
		return E_OK ;
}

ERROR_STATUS Motor_Start(uint8_t Motor_Number, uint8_t Mot_Speed){
	switch(Motor_Number){
		
		case MOTOR_1 :
		Pwm_Start(PWM_CH1A,Mot_Speed,100);
		case MOTOR_2 :
		Pwm_Start(PWM_CH1B,Mot_Speed,100);
		default :
		return E_NOK ;
	}
	return E_OK ;
}


ERROR_STATUS Motor_SpeedUpdate(uint8_t Motor_Number, uint8_t Speed){
	
		switch(Motor_Number){
			
			case MOTOR_1 :
			Pwm_Update(PWM_CH1A,Speed,100);
			case MOTOR_2 :
			Pwm_Update(PWM_CH1B,Speed,100);
			default: 
			return E_NOK ;
		}
		
		return E_OK ;
}
