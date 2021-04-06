#define F_CPU 8E6

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "lcd/lcd.h"
#include "matrix/matrix.h"


int counter = 0;
int questionAsked = 1;

int pressedB1 = 0;
int pressedB2 = 0;


void questions(char *vraag1, char *antwoord1, char *antwoord2, int nummer ){
	
	display_text(vraag1);
	set_cursor(40);
	
	display_text(antwoord1);
	set_cursor(50);
	display_text(antwoord2);
	
	while (questionAsked)
	{
		if (pressedB1 && !nummer )
		{
			display_text("Goed");
			
			
		} else if (pressedB1 && nummer)
		{
				display_text("Fout");
				questionAsked--;
			
		}	else if (pressedB2 && !nummer)
		{
				display_text("Fout");
				questionAsked--;
			
		}	else if (pressedB2 && nummer)
		{
				display_text("Goed");
				questionAsked--;
		} else{
			
		}
	}
	
}

void pressedButtonB1(void){
	
	if (PINB & 0x02){						// b2 indrukken dan komt hij hier in
		pressedB1++;
		wait(1000);

	}

}

void pressedButtonB2(void){
	
	if (PINB & 0x04){						// b2 indrukken dan komt hij hier in
		pressedB2++;
		wait(1000);
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
			counter++;
			wait (200);
		} 
		
		if (PINB & 0x02 && counter == 1){						// b2 indrukken dan komt hij hier in
			clear();
			questions("wat doe ik?", "TI", "BIM", 1);
			counter++;
		}
		
		if (PINB & 0x02 && counter == 2){						// b2 indrukken dan komt hij hier in
			clear();
			questions("wat doe ik?", "TI", "BIM", 1);
			counter++;
		}
		
		
		
	}

	return 1;
}
