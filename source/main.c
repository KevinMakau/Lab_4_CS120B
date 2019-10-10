/*	Author: kmaka003
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


#define 
typedef enum States {init, outside, inside, wait#, waitY, unlock, lockX, lockY, lockZ} States;
int buttonState (int);

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	DDRB = 0xFF; PORTB = 0x00;



	

    /* Insert your solution below */
	States state = init;
	
    while (1) {
	state = buttonState(state);
    }
    return 1;
}

int buttonState (int state){
	unsigned char X = PINA & 0x01;
	unsigned char Y = PINA & 0x02;
	unsigned char # = PINA & 0x04;
	unsigned char inSide = PINA & 0x80;


	switch (state) {
		case init:
			state = inSide? inside: outside;
			break;
		case outside:
			state = #? wait#: init;
			break;
		case wait#:
			state = #? wait#: waitY;
			break;
		case waitY:
			state = X? init: waitY;
			state = #? wait#: state;
			state = Y? lock: state;
			break;
		case unlock:
			PORTB = 0X01;
			state = Y? unlock: init;
			break;
		case inside:
			state = #? lock#: init;
			state = X? lockX: state;
			state = Y? lockY: state;
			break;
		case lockX:
			PORTB = 0x00;
			state = X? lockX: init
			break; 
		case lockY:
			PORTB = 0x00;
			state = Y? lockY: init;
			break; 
		case lock#:
			PORTB = 0x00;
			state = #? lock#: waitY;
			break;

	}
	return state;
}

	
 
			




