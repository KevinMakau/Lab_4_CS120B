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


typedef enum States {init, outside, inside, waitZ, waitY, unlock, lockX, lockY, lockZ} States;
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
	unsigned char Z = PINA & 0x04;
	unsigned char inSide = PINA & 0x80;


	switch (state) {
		case init:
			state = inSide? inside: outside;
			PORTC = 1;
			break;
		case outside:
			state = Z? waitZ: init;
			PORTC = 2;
			break;
		case waitZ:
			state = Z? waitZ: waitY;
			PORTC = 3;
			break;
		case waitY:
			state = X? init: waitY;
			state = Z? waitZ: state;
			state = Y? unlock: state;
			PORTC = 4;
			break;
		case unlock:
			PORTB = 0X01;
			state = Y? unlock: init;
			PORTC = 5;
			break;
		case inside:
			state = Z? lockZ: init;
			state = X? lockX: state;
			state = Y? lockY: state;
			PORTC = 6;
			break;
		case lockX:
			PORTB = 0x00;
			state = X? lockX: init;
			PORTC = 7;
			break; 
		case lockY:
			PORTB = 0x00;
			state = Y? lockY: init;
			PORTC = 8;
			break; 
		case lockZ:
			PORTB = 0x00;
			state = Z? lockZ: waitY;
			PORTC = 9;
			break;

	}
	return state;
}

	
 
			




