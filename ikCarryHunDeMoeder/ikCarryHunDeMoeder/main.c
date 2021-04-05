#define F_CPU 8E6

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "lcd/lcd.h"
#include "matrix/matrix.h"


int counter = 0;


void vraag1(char *vraag1, char *antwoord1, char *antwoord2, int nummer ){
	
	display_text(vraag1);
	set_cursor(40);
	
	display_text(antwoord1);
	set_cursor(50);
	display_text(antwoord2);
	
}


int main( void )
{
	
	start_init();
	
	DDRA = 0xFF;
	PORTA = 0x01;
	init();
	
	clear();
	

	display_text("welkom, druk op");
	set_cursor(40);
	display_text("B1 om te starten");
	
	PORTB = 0x00; 

	while (1)
	{
		
		

		if (PINB & 0x02){						// b2 indrukken dan komt hij hier in
			counter++;
			wait(1000);
		} 
		
		if (PINB & 0x04){						// b2 indrukken dan komt hij hier in
			display_text("B");
		}
		
		
		if (counter == 1)
		{
			clear();
			vraag1("Hoe heet ik?", "Jurre", "Jan", 0);
			counter++;
		}
		
	}

	return 1;
}
