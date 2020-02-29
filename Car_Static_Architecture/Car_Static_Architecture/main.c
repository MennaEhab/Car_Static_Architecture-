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


timerDelayMs(1000);




	DIO_Cfg_s dioCfgrem;
	
	dioCfgrem.GPIO = GPIOB;
	dioCfgrem.pins = BIT7|BIT6|BIT5|BIT4;
	dioCfgrem.dir =OUTPUT;
	
	DIO_init(&dioCfgrem);

	
	
	Car_SM_Init();
	
    while(1)
    {
		Car_SM_Update();

    }

}


