/*
* gpio.c
*
* Created: 1/17/2020 2:26:19 PM
*  Author: MENA
*/
#include "DIO.h"
#include "std_types.h"



ERROR_STATUS DIO_init (DIO_Cfg_s *DIO_info){
	
	 //uint8_t temp ;
	 if (DIO_info->dir == HIGH )
	{
		switch(DIO_info->GPIO){
			
			case GPIOA :
			
			PORTA_DIR = PORTA_DIR | DIO_info->pins ;
			break;
			
			case GPIOB :
			
			PORTB_DIR = PORTB_DIR | DIO_info->pins ;
			break;
			
			case GPIOC :
			
			PORTC_DIR = PORTC_DIR | DIO_info->pins ;
			break;

			case GPIOD :
			
			PORTD_DIR = PORTD_DIR | DIO_info->pins ;
			break;
			
			default :
			return E_NOK ;
		}
		
	} else if (DIO_info->dir == LOW)
	{
		switch(DIO_info->GPIO){
		PORTA_DIR = PORTA_DIR & ~(DIO_info->pins) ;
		break;
		
		case GPIOB :
		
		PORTB_DIR = PORTB_DIR & ~(DIO_info->pins) ;
		break;
		
		case GPIOC :
		
		PORTC_DIR = PORTC_DIR & ~(DIO_info->pins) ;
		break;

		case GPIOD :
		
		PORTD_DIR = PORTD_DIR & ~(DIO_info->pins) ;
		break;	
		
		default :
		return E_NOK ;	
			
		}
		
	}else
		return E_NOK;
	
	return E_OK ;
	
	 
	
}


ERROR_STATUS DIO_Write (uint8_t GPIO, uint8_t pins, uint8_t value){
	uint8_t temp;
	if (value == HIGH ){
		switch(GPIO)
		{
			case GPIOA :
			
			PORTA_DATA  |=  pins ;
			break;
			
			case GPIOB :
			PORTB_DATA |=  (PORTB_DATA  & ~(pins) )| (value& pins) ;
			 
			 //PORTB_DATA =value;
			break;
			
			case GPIOC :
			
			PORTC_DATA |= pins ;
			break;

			case GPIOD :
			
			PORTD_DATA |=  pins ;
			break;
			
			 default :
			return E_NOK ;

		}
		}else if(value == LOW) {
			
		switch(GPIO){	
		
		case GPIOA :
		
		PORTA_DATA &= ~(pins) ;
		break;
		
		case GPIOB :
		
		PORTB_DATA &=  ~(pins) ;
		break;
		
		case GPIOC :
		
		PORTC_DATA &= ~(pins) ;
		break;

		case GPIOD :
		
		PORTD_DATA &= ~(pins) ;
		break;
		
		 default :
		return E_NOK ;
		
			} 
		}else 
		return E_NOK ;
	return E_OK ;
}



ERROR_STATUS DIO_Read (uint8_t GPIO,uint8_t pins, uint8_t *data){
	if (data == NULL) 
	 return E_NOK;  
	
	switch(GPIO)
	{
		case GPIOA : 
			*data = PORTA_PIN &  (pins) ;
			break;
		case GPIOB : 
			*data = (PORTB_PIN &  (pins)) ;
			break;
		case GPIOC : 
			*data = PORTC_PIN &  (pins) ;
			break;
		case GPIOD : 
			*data = PORTD_PIN &  (pins) ;
			break;
		 default:
			return E_NOK ;
	}
	return E_OK ;
	
}



ERROR_STATUS DIO_Toggle (uint8_t GPIO, uint8_t pins){
	
	switch(GPIO)
	{
		case GPIOA : PORTA_DATA ^= (pins) ;
		break;
		case GPIOB : PORTB_DATA ^= (pins) ;
		break;
		case GPIOC : PORTC_DATA ^= (pins) ;
		break;
		case GPIOD : PORTD_DATA ^= (pins) ;
		break;
		 default :
		return E_NOK ;
	}
	
	return E_OK;
}


