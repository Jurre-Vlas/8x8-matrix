#define F_CPU 8E6
#include <avr/io.h>
#include <util/delay.h>
#include "matrix.h"
#include "lcd.h"


void twi_init(void) // initialiseer code
{
	TWSR = 0;
	TWBR = 32;	 // TWI clock set to 100kHz, prescaler = 0
}

void twi_start(void) // ontwikkeld de start conditie
{
	TWCR = (0x80 | 0x20 | 0x04);
	while( 0x00 == (TWCR & 0x80) );
}

/******************************************************************/
void twi_stop(void) // ontwikkeld de stop conditie 

{
	TWCR = (0x80 | 0x10 | 0x04);
}


void twi_tx(unsigned char data) // verzenden van 8 bits data



{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while( 0 == (TWCR & 0x80) );
}



void start_init(void){ // het initialiseren van de display
	
	twi_init();		// Init TWI interface

	// Init HT16K22. Page 32 datasheet
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x21);	// Internal osc on (page 10 HT16K33)
	twi_stop();

	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0xA0);	// HT16K33 pins all output
	twi_stop();

	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0xE3);	// Display Dimming 4/16 duty cycle
	twi_stop();

	twi_start();
	twi_tx(0xE0);	// Display I2C address + R/W bit
	twi_tx(0x81);	// Display OFF - Blink On
	twi_stop();
	
	
	//het dimmen van alle lampen
	twi_start();
	twi_tx(0xE0);
	twi_tx(0x00);
	for(int i=0; i < 16; i++){
		twi_tx(0x00);	// data
	}
	
	twi_stop();
	
	
}

void decision(int good){  // smiley goed of fout
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x00);	// Row
	twi_tx(0b0011110);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x02);	// Row
	twi_tx(0b0100001);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x04);	// Row
	twi_tx(0b11010010);	// data
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x06);	// Row
	twi_tx(0b11000000);	// data
	twi_stop();
	
	
	if (good){
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x08);	// Row
		twi_tx(0b11010010);	// data
		twi_stop();
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x0A);	// Row
		twi_tx(0b11001100);	// data
		twi_stop();
	}
	
	else{
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x08);	// Row
		twi_tx(0b11001100);	// data
		twi_stop();
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x0A);	// Row
		twi_tx(0b11010010);	// data
		twi_stop();
		
	}
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x0C);	// Row
	twi_tx(0b0100001);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x0E);	// Row
	twi_tx(0b0011110);	// data
	twi_stop();
}

void three(){		// drie op display
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x00);	// Row
	twi_tx(0b0011110);	// data
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x02);	// Row
	twi_tx(0b0010000);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x04);	// Row
	twi_tx(0b0010000);	// data;
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x06);	// Row
	twi_tx(0b0011110);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x08);	// Row
	twi_tx(0b0011110);	// data
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x0A);	// Row
	twi_tx(0b0010000);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x0C);	// Row
	twi_tx(0b0010000);	// data;
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x0E);	// Row
	twi_tx(0b0011110);	// data
	twi_stop();
}

void two(){		// twee op display
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x00);	// Row
		twi_tx(0b0011110);	// data
		twi_stop();
		
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x02);	// Row
		twi_tx(0b0010000);	// data
		twi_stop();
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x04);	// Row
		twi_tx(0b0010000);	// data;
		twi_stop();
		
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x06);	// Row
		twi_tx(0b0011110);	// data
		twi_stop();
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x08);	// Row
		twi_tx(0b0000010);	// data
		twi_stop();
		
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x0A);	// Row
		twi_tx(0b0000010);	// data
		twi_stop();
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x0C);	// Row
		twi_tx(0b0000010);	// data;
		twi_stop();
		
		
		twi_start();
		twi_tx(0xE0);	// Display I2C addres + R/W bit
		twi_tx(0x0E);	// Row
		twi_tx(0b0011110);	// data
		twi_stop();
}

void one(){ 		// een op display
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x00);	// Row
	twi_tx(0b0001000);	// data
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x02);	// Row
	twi_tx(0b001100);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x04);	// Row
	twi_tx(0b0001000);	// data;
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x06);	// Row
	twi_tx(0b0001000);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x08);	// Row
	twi_tx(0b0001000);	// data
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x0A);	// Row
	twi_tx(0b0001000);	// data
	twi_stop();
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x0C);	// Row
	twi_tx(0b0001000);	// data;
	twi_stop();
	
	
	twi_start();
	twi_tx(0xE0);	// Display I2C addres + R/W bit
	twi_tx(0x0E);	// Row
	twi_tx(0b0011110);	// data
	twi_stop();
}


void countToDecision(int good){  // het aftellen van 3 naar 1 -> smiley
	three();
	
	wait(1000);
	
	two();
	
	wait(1000);
	
	one();
	 
	wait(1000);
	
	decision(good);
}
