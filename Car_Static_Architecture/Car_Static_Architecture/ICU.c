/*
 * ICU.c
 *
 * Created: 2/18/2020 11:59:36 AM
 *  Author: MENA
 */ 
#include "ICU.h"

#define SwICU_EdgeRisiging 0
#define SwICU_EdgeFalling 1

#define  INT2_EN_GPIO GICR
#define  INT2_EN_BIT 5

#define  INT2_EDGE_GPIO MCUCSR
#define  INT2_EDGE_BIT 6
#define  tickTimeUs 64

uint8_t g_interruptCH_No = 0 ;
static volatile uint8_t g_interruptEdge ;
static volatile uint8_t g_timerCH ;
static volatile uint8_t g_fallingEdgeFlag = 0 ;

//volatile uint8_t 

ERROR_STATUS SetExternal_INT_Edge( uint8_t SwICU_Edge ,uint8_t interruptCH_No ){
	
	DIO_Cfg_s dioCfg_INT2;
	switch(interruptCH_No){
		case ICU_CH0 :
		break;
		case ICU_CH1:
		break;
		case ICU_CH2:
			
			
			dioCfg_INT2.GPIO = GPIOB;
			dioCfg_INT2.pins = BIT2;
			dioCfg_INT2.dir =INPUT;
			
			DIO_init(&dioCfg_INT2);
			
			if(SwICU_Edge== ICU_RISE_TO_FALL){
				
				SET_BIT(INT2_EDGE_GPIO , INT2_EDGE_BIT);
				}
			else if(SwICU_Edge== ICU_FALE_TO_RISE)
			CLEAR_BIT(INT2_EDGE_GPIO , INT2_EDGE_BIT);
			else
			return E_NOK ;
		break;
		default:
		return E_NOK ;
		
	}
	return E_OK ;
}

ERROR_STATUS SetExternal_INT_enable( uint8_t SwICU_Edge ,uint8_t interruptCH_No ){
		switch(interruptCH_No){
			case ICU_CH0 :
			break;
			case ICU_CH1:
			break;
			case ICU_CH2:
				//SET_BIT(INT2_EN_GPIO , INT2_EN_BIT);
				INT2_EN_GPIO|= 1<<INT2_EN_BIT ;
			break;
			default:return E_NOK ;
	
		}
		return E_OK ;
}

ERROR_STATUS Icu_Init(Icu_cfg_s * Icu_Cfg){
	
		Timer_cfg_s Timer_cfg ;
		
		if (Icu_Cfg == NULL)
		{
			return E_NOK;
		}
		
		g_interruptCH_No = Icu_Cfg->ICU_Ch_No ;
/*
		switch(Icu_Cfg->ICU_Ch_No){
					//case ICU_CH0:
					//g_interruptCH_No = INT0_vect ;
					//break;
					//case ICU_CH1:
					//g_interruptCH_No = INT1_vect ;
					//break;
					//case ICU_CH2:
					//g_interruptCH_No = INT2_vect ;
					//break;
					//default:
					//return E_NOK ;
					//
					//
				//}
*/
		
		switch(Icu_Cfg->ICU_Ch_Timer){
			case ICU_TIMER_CH0 :
			
			Timer_cfg.Timer_CH_NO = TIMER_CH0 ;
			Timer_cfg.Timer_Mode = TIMER_MODE ;
			Timer_cfg.Timer_Polling_Or_Interrupt = TIMER_POLLING_MODE ;
			Timer_cfg.Timer_Prescaler = TIMER_PRESCALER_1024 ;
			
			Timer_Init(&Timer_cfg);
			
			break;
			case ICU_TIMER_CH1 :
			break;
			case ICU_TIMER_CH2 :
			break;
			default:return E_NOK ;
			
		}
		return E_OK ;
}

ERROR_STATUS Icu_ReadTime(uint8_t Icu_Channel, uint8_t Icu_EdgeToEdge, uint32_t * Icu_Time){
	uint16_t no_of_ticks = 0 ;
	uint16_t timerOfTicks_Us  ;
	
	g_interruptEdge = SwICU_EdgeRisiging;
	g_timerCH = Icu_Channel ;
	switch(Icu_Channel){
			case ICU_TIMER_CH0:
			
			SetExternal_INT_Edge(Icu_EdgeToEdge,g_interruptCH_No);
			SetExternal_INT_enable(Icu_EdgeToEdge,g_interruptCH_No) ;
			
			break;
			case ICU_TIMER_CH1 :
			break;
			case ICU_TIMER_CH2 :
			break;
			default:return E_NOK ;
	}
	
	while(!g_fallingEdgeFlag) ;
	Timer_GetValue(g_timerCH ,&no_of_ticks) ;
	timerOfTicks_Us = no_of_ticks * tickTimeUs ;
	*Icu_Time = timerOfTicks_Us ;
	return E_OK ;
}


ISR(INT2_vect){
	
		switch (g_interruptEdge){
///////////////////////////rising//////////////////////////////////////////////////////////		
			case SwICU_EdgeRisiging :
			DIO_Write(GPIOA,BIT1,HIGH);
			
			switch(g_timerCH){
				case ICU_TIMER_CH0 :
				//timer_Start();
				Timer_Start(TIMER_CH0,256);
				//update the control to start at faling edge
				MCUCSR &= ~(1<<6) ;
				//Led_On(LED_0) ;
				g_interruptEdge = SwICU_EdgeFalling;
				break;
				
			}
			
			break;
/////////////////////////////falling/////////////////////////////////////////////////////			
			case SwICU_EdgeFalling :
			DIO_Write(GPIOA,BIT1,LOW);
			switch(g_timerCH){
				
				case ICU_TIMER_CH0 :
				Timer_Stop(TIMER_CH0);
				MCUCSR |= 1<<6 ;
				//Led_Off(LED_0) ;
				g_interruptEdge = SwICU_EdgeRisiging;
				g_fallingEdgeFlag = 1 ;
				break;
		}
	
}
}