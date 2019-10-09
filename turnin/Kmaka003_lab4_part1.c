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

typedef enum States {init, waitA0, pressA0, pressA0_2 } States;
int ledState (int);

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x01;



	

    /* Insert your solution below */
	States state = init;
	
    while (1) {
	state = ledState(state);
    }
    return 1;
}

int ledState (int state){
	unsigned char A0 = PINA & 0x01;
	switch (state) {
		case init:
			state = A0? pressA0: init;
			break;
		case pressA0:
			state = A0? pressA0: waitA0;
			PORTB = 0x02;
			break;
		case waitA0:
			state = A0? pressA0_2: waitA0;
			break;
		case pressA0_2:
			state = A0? pressA0_2: init;
			PORTB = 0x01;
			break;
	}
	return state;
}

	
 
			




