/*
 * registers.h
 *
 *  Created on: Oct 21, 2019
 *      Author: Sprints
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "std_types.h"

/*
 * General RegistersMCUCSR
 */
 uint8_t MCUCR  ;
 uint8_t MCUCSR ;
 uint8_t GICR  ;
 uint8_t GIFR	;
 uint8_t SREG	 ;
/*
 * PORTx registers
 */

 uint8_t PORTA_DATA	 ;
 uint8_t PORTA_DIR ;
 uint8_t PORTA_PIN ;

 uint8_t PORTB_DATA ;

uint8_t PORTB_DIR;
 uint8_t PORTB_PIN;

 uint8_t PORTC_DATA;
 uint8_t PORTC_DIR ;
 uint8_t PORTC_PIN ;


 uint8_t PORTD_DATA	 ;
 uint8_t PORTD_DIR ;
 uint8_t PORTD_PIN ;


/*
 * General Timer registers
 */
 uint8_t TIMSK		;
 uint8_t TIFR		;

/*
 * Timer 0 Registers
 */

 uint8_t TCCR0	;
 uint8_t TCNT0	;
uint8_t OCR0;
#define TOV0      0
#define OCF0      1
#define TOV1      2
#define OCF1B     3
#define OCF1A     4
#define ICF1      5
#define TOV2      6
#define OCF2      7
/***************************************************/
/* OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0<<TIFRReg */
/***************************************************/
/*
 * Timer 1 Registers
 */

 uint8_t TCCR1A	;
 uint8_t TCCR1B	;
 uint16_t TCCR1	;

 uint8_t TCNT1H	;
 uint8_t TCNT1L	;
 uint16_t TCNT1	;


 uint8_t OCR1AH	;
 uint8_t OCR1AL	;
 uint8_t OCR1A	;

 uint8_t OCR1BH	;
 uint8_t OCR1BL	;
 uint8_t OCR1B;

 uint8_t ICR1H;
 uint8_t ICR1L;
 uint16_t ICR1;


/*
 * Timer 2 Registers
 */
 uint8_t TCCR2;
 uint8_t TCNT2;
 uint8_t OCR2	;
 uint8_t ASSR ;
#endif /* REGISTERS_H_ */
