/*
 * PWM.c
 *
 * Created: 2/17/2020 7:07:19 PM
 *  Author: MENA
 */ 

#include "PWM.h"
#include "PWMconfig.h"

uint16_t g_Prescale_mask = 0 ;
#define PWM_PRE_SCALE 1024
#define PWM_PRE_scale_MASK T1_PRESCALER_1024


extern ERROR_STATUS Pwm_Init(Pwm_Cfg_s *Pwm_Cfg){
	
		if (Pwm_Cfg==NULL)
		{
			return E_NOK ;
		}
	
		DIO_Cfg_s dioCfg;
		dioCfg.GPIO=PWM_GPIO1;
		dioCfg.pins=PWM_BIT1|PWM_BIT2;
		dioCfg.dir=OUTPUT;
		DIO_init(&dioCfg);
		
		//gpioPinDirection(PWM_GPIO1 ,PWM_BIT1 , OUTPUT);
		//gpioPinDirection(PWM_GPIO2 ,PWM_BIT2 , OUTPUT);
	
	
	switch(Pwm_Cfg->Prescaler){
		case PWM_PRESCALER_NO :
		break;
		case PWM_PRESCALER_8:
		break;
		case PWM_PRESCALER_32 :
		break;
		case PWM_PRESCALER_64 :
		break;
		case PWM_PRESCALER_128 :
		break; 
		case PWM_PRESCALER_256 :
		
		break;
		case PWM_PRESCALER_1024 :
		g_Prescale_mask = TIMER1_PRESCALER_1024_MASK ;
		break;
		default: 
		return E_NOK ;
	}
	
	switch(Pwm_Cfg->Channel){
		case PWM_CH0:
		
		break;
		case PWM_CH1A :
		
		TCCR1 |= T1_PHASE_CORRECT_ICR1 ;
		TCCR1 |= T1_OC1A_CLEAR ;
		
		
		break;
		case PWM_CH1B :
		
		TCCR1 |= T1_PHASE_CORRECT_ICR1 ;
		TCCR1 |= T1_OC1B_CLEAR ;
		
		break;
		case PWM_CH2 :
		
		break;
		default:
		return E_NOK ;
		
		
	}
	
	return E_OK ;
	
	
}

extern ERROR_STATUS Pwm_Start(uint8_t Channel,uint8_t Duty,uint32_t Frequncy){
	
		
	uint16_t ICR_TOP ;
	uint16_t duty_cycle_tick ;
	
	ICR_TOP = F_CPU / (2.0 * PWM_PRE_SCALE * Frequncy) ;
	
	
	duty_cycle_tick = ICR_TOP *Duty/100.0 ;
	
		
		switch(Channel){
			case PWM_CH0:
			
			break;
			case PWM_CH1A :
			
			ICR1 = ICR_TOP ;
			OCR1A = duty_cycle_tick ;
			
			TCCR1|=g_Prescale_mask ;
			
			
			break;
			case PWM_CH1B :
			
			ICR1 = ICR_TOP ;
			OCR1B = duty_cycle_tick ;
			TCCR1|=g_Prescale_mask ;
			
			break;
			case PWM_CH2 :
			
			break;
			default:
			return E_NOK ;
			
			
		}
		return E_OK ;
	
	
}


extern ERROR_STATUS Pwm_Update( uint8_t Channel, uint8_t Duty, uint32_t Frequncy){
	
	uint16_t ICR_TOP ;
	uint16_t duty_cycle_tick ;
	
	ICR_TOP = F_CPU / (2.0 * PWM_PRE_SCALE * Frequncy) ;
	
	
	duty_cycle_tick = ICR_TOP *Duty/100.0 ;
	
	
	switch(Channel){
		case PWM_CH0:
		
		break;
		case PWM_CH1A :
		
		ICR1 = ICR_TOP ;
		OCR1A = duty_cycle_tick ;
		
		TCCR1|=g_Prescale_mask ;
		
		
		break;
		case PWM_CH1B :
		
		ICR1 = ICR_TOP ;
		OCR1B = duty_cycle_tick ;
		TCCR1|=g_Prescale_mask ;
		
		break;
		case PWM_CH2 :
		
		break;
		default:
		return E_NOK ;
		
		
	}
	return E_OK ;
	
	
}

extern ERROR_STATUS Pwm_Stop( uint8_t Channel){
	
	switch(Channel){
		case PWM_CH0:
		
		break;
		case PWM_CH1A :
		
		TCCR1 &= TIMER1_NO_CLOCK_MASK ;
		
		
		
		break;
		case PWM_CH1B :
		
		TCCR1 &= TIMER1_NO_CLOCK_MASK ;
		
		break;
		case PWM_CH2 :
		
		break;
		default:return E_NOK ;
			
	}
	
	return E_OK ;
	
}
