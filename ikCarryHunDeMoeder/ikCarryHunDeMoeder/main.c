#define F_CPU 8E6

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "tools/lcd.h"
#include "tools/matrix.h"


int counter = 0;
int questionAsked = 0;

int pressedB1 = 0;
int pressedB2 = 0;







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
			clear();
			countToDecision(0);
			questionAsked--;
			counter++;
			
			
		} else if (PINB & 0x02 && nummer)
		{
				clear();
				countToDecision(1);
				questionAsked--;
				counter++;
			
		}	else if (PINB & 0x04 && !nummer)
		{
				clear();
				countToDecision(1);
				questionAsked--;
				counter++;
			
		}	else if (PINB & 0x04 && nummer)
		{
				clear();
				countToDecision(0);
				questionAsked--;
				counter++;
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
		}
		
		while ( counter == 2){						// b2 indrukken dan komt hij hier in
			questions("wat is gezond?", "patat", "Peer", 1);
		}
		
			while (counter == 3)
		{
			clear();
			display_text("klaar is kees");
			set_cursor(40);
			display_text("restart op B1");
			counter++;
		}
			while(counter == 4){
				if(PINB & 0x02){
					counter = 0;
				}
			}
	}

	return 1;
}
