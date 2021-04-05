/*
 * main.c
 *
 * Created: 4/4/2021 4:05:53 PM
 *  Author: kroelie woelie
 */ 

#define F_CPU 8E6
#include <avr/io.h>
#include <util/delay.h>
#include "matrix.h"


/******************************************************************/ 


int main( void )
{
	
	start_init();
	
	while (1)
	{
			decision(1);
			wait(1000);
			
			decision(0);
			
			wait(1000);
			
	}

	return 1;
}



