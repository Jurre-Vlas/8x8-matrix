#define F_CPU 8E6

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "lcd/lcd.h"
#include "matrix/matrix.h"


int counter = 0;
int questionAsked = 0;

int pressedB1 = 0;
int pressedB2 = 0;



void goodBad(int goodOrBad){
	clear();
	set_cursor(5);
	display_text("3");
	wait(1000);
	set_cursor(5);
	display_text("2");
	wait(1000);
	set_cursor(5);
	display_text("1");
	
	wait(500);
	
	set_cursor(0);
	
	
	if(goodOrBad){
		decision(1);
		questionAsked--;
		counter++;
	} else if(!goodOrBad){
		decision(0);
		questionAsked--;
		counter++;
	}
	
}




void questions(char *vraag1, char *antwoord1, char *antwoord2, int nummer ){
	
	display_text(vraag1);
	set_cursor(40);
	
	display_text(antwoord1);

	set_cursor(50);
	display_text(antwoord2);
	
	if (questionAsked == 0){
		questionAsked++;
	}
	
	while (questionAsked)
	{
		if (PINB & 0x02 && !nummer )
		{
			goodBad(0);
			
			
		} else if (PINB & 0x02 && nummer)
		{
				goodBad(1);
			
		}	else if (PINB & 0x04 && !nummer)
		{
				goodBad(1);
			
		}	else if (PINB & 0x04 && nummer)
		{
				goodBad(0);
		} 
	}
	
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
		if (PINB & 0x02 && counter == 0){						// b2 indrukken dan komt hij hier in
			clear();
			questions("Hoe heet ik?", "Jurre", "Jan", 0);
			wait(1000);
		} 
		
		while (counter == 1){						// b2 indrukken dan komt hij hier in
			questions("wat doe ik?", "TI", "BIM", 0);
			wait(1000);
		}
		
		while ( counter == 2){						// b2 indrukken dan komt hij hier in
			questions("wat is gezond?", "patat", "Peer", 1);
			wait(1000);
		}
		
			while (counter == 3)
		{
			clear();
			wait(1000);

			display_text("klaar is kees");
			counter++;
		}
		
		
		
	}

	return 1;
}
