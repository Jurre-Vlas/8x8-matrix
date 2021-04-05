#define F_CPU 8E6

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "lcd/lcd.h"
#include "matrix/matrix.h"






int main( void )
{
	
	start_init();
	
	DDRA = 0xFF;
	PORTA = 0x01;
	init();
	
	clear();
	display_text("Hello");
	
	set_cursor(10);
	display_text("World!");


	
	while (1)
	{
		decision(1);
		wait(1000);
		
		decision(0);
		wait(500);
		

		
	}

	return 1;
}