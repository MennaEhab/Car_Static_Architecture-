/*
 * Car_Static_Architecture.c
 *
 * Created: 2/17/2020 11:04:36 AM
 * Author : MENA
 */ 

//#include <avr/io.h>
//#include "dcMotor.h"
//
//#include "led.h"

//#include "SwICU.h"
//#include "Ultrasonic.h"
//#include "UART__.h"
//#include "timers.h"
//#include "SPI__.h"

#include "DIO.h"
#include "PWM.h"
#include "motor.h"
#include "ICU.h"
#include "Us.h"
#include "TimerDelay.h"
#include "Steering.h"
#include "car_sm.h"

int main(void)
{
    /* Replace with your application code */
/*
DIO_Cfg_s dioCfg;
dioCfg.GPIO=GPIOA;
dioCfg.pins=BIT0|BIT5;
dioCfg.dir=OUTPUT;

DIO_init(&dioCfg);

DIO_Write(GPIOA,BIT0,LOW);
DIO_Write(GPIOA,BIT5,HIGH);


timerDelayMs(1000);

DIO_Write(GPIOA,BIT0,HIGH);
DIO_Write(GPIOA,BIT5,LOW);
*/

//while(1){

//DIO_Write(GPIOA,BIT0,LOW);
//DIO_Write(GPIOA,BIT5,HIGH);
//
//timerDelayMs(1000);
//DIO_Write(GPIOA,BIT0,HIGH);
//DIO_Write(GPIOA,BIT5,LOW);
//timerDelayMs(1000);

//}

//Steering_Init();
//
//Steering_SteerCar(CAR_FORWARD,40);

/*
Pwm_Cfg_s pwm_cfgA ;
pwm_cfgA.Channel = PWM_CH1A ;
pwm_cfgA.Prescaler = PWM_PRESCALER_1024 ;


Pwm_Cfg_s pwm_cfgB ;
pwm_cfgB.Channel = PWM_CH1B ;
pwm_cfgB.Prescaler = PWM_PRESCALER_1024 ;

Pwm_Init(&pwm_cfgA);

Pwm_Init(&pwm_cfgB);

Pwm_Start(PWM_CH1A,50,100) ;
Pwm_Start(PWM_CH1B,50,100) ;*/



timerDelayMs(1000);

sei();

//Icu_cfg_s icuCfg;
	DIO_Cfg_s dioCfgrem;
	
	dioCfgrem.GPIO = GPIOB;
	dioCfgrem.pins = BIT7|BIT6|BIT5|BIT4;
	dioCfgrem.dir =OUTPUT;
	
	DIO_init(&dioCfgrem);
	
	/*icuCfg.ICU_Ch_Timer = ICU_TIMER_CH0;
	icuCfg.ICU_Ch_No = ICU_CH2;
	Icu_Init(&icuCfg);*/
	
	
	//uint16_t distance;
	/*
	Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&time_);*/
	//Us_Init();
	
	Car_SM_Init();
	
    while(1)
    {
		Car_SM_Update();
		//Us_Trigger();
		//Us_GetDistance(&distance);
			
		

		//DIO_Write(GPIOB,(BIT7|BIT6|BIT5|BIT4),15<<4);
		
		//PORTB_DATA = distance<<4;
		
		//
		//timerDelayMs(10);
		//if (distance<30){
			//
			//Steering_SteerCar(CAR_STOP,40);
		//}else{
			//Steering_SteerCar(CAR_FORWARD,40);
			//
		//}
		//Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL,&time_);
		
    }

}


void carcontrol(void){
	
	 /*
	 
	 uint16_t Distance ;
	 //////////// icu ////////////////////
	 
	 ///// enable global interrupt
	 SREG |=0x80;
	 /////external interrupt1 pin
	 gpioPinDirection(GPIOB , BIT2 , INPUT );
	 
	 ///for protus
	 gpioPinWrite(GPIOB,BIT2,HIGH);
	 
	 Led_Init(LED_0);
	 Led_Init(LED_1);
	 Led_Init(LED_2);
	 Led_Init(LED_3);
	 
	 
	 SwICU_Init(SwICU_EdgeRisiging);
	 
	 /// direction of trigger
	 
	 gpioPinDirection(GPIOC , BIT0 ,OUTPUT);
	 
	 timer2DelayMs(20);
	 
	 //////////motor///////////////
	 
	 /// set direction
	 MotorDC_Init(MOT_1);
	 MotorDC_Init(MOT_2);
	 
	 MotorDC_Dir(MOT_1,FORWARD);
	 MotorDC_Dir(MOT_2,FORWARD);
	 
	 /// set speed
	 
	 MotorDC_Speed_HwPWM(50) ;
	 
	 while (1)
	 {
		 // read the distance between the car and any obstacle infront of it
		 
		 Distance = ultrasonic_init ();
		 
		 /// if the distance between the object and the car less than 5 cm the car stops
		 
		 if( Distance<= 5 ){
			 
			 MotorDC_Dir(MOT_1,STOP);
			 MotorDC_Dir(MOT_2,STOP);
			 }else {
			 MotorDC_Dir(MOT_1,FORWARD);
			 MotorDC_Dir(MOT_2,FORWARD);
			 
		 }
		 
		 
	 }*/

}