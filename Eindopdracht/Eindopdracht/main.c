/*
 * main.c
 *
 * Created: 4/4/2021 4:05:53 PM
 *  Author: kroelie woelie
 */ 

#define F_CPU 8E6
#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "matrix.h"
#include "main.h"
#include "lcd.h"



/******************************************************************/ 
void wait( int ms )
/* 
short:			Busy wait number of millisecs
inputs:			int ms (Number of millisecs to busy wait)
outputs:	
notes:			Busy wait, not very accurate. Make sure (external)
				clock value is set. This is used by _delay_ms inside
				util/delay.h
Version :    	DMK, Initial code
*******************************************************************/
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

int main( void )
{
	
	start_init();
	
	// Init I/O
	DDRE = 0xFF;			// PORTD(7) output, PORTD(6:0) input

	// Init LCD
	init_4bits_mode();

	// Write sample string


	
	while (1)
	{
			decision(1);
			wait(1000);
			
			decision(0);
			
			wait(1000);
			
	}

	return 1;
}



