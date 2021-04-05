#define F_CPU 8E6
#include <avr/io.h>
#include <util/delay.h>
#include "matrix.h"
#include "main.h"

/******************************************************************/
void twi_init(void)
/*
short:			Init AVR TWI interface and set bitrate
inputs:
outputs:
notes:			TWI clock is set to 100 kHz
Version :    	DMK, Initial code
*******************************************************************/
{
	TWSR = 0;
	TWBR = 32;	 // TWI clock set to 100kHz, prescaler = 0
}

/******************************************************************/
void twi_start(void)
/*
short:			Generate TWI start condition
inputs:
outputs:
notes:
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x20 | 0x04);
	while( 0x00 == (TWCR & 0x80) );
}

/******************************************************************/
void twi_stop(void)
/*
short:			Generate TWI stop condition
inputs:
outputs:
notes:
Version :    	DMK, Initial code
*******************************************************************/
{
	TWCR = (0x80 | 0x10 | 0x04);
}

/******************************************************************/
void twi_tx(unsigned char data)
/*
short:			transmit 8 bits data
inputs:
outputs:
notes:
Version :    	DMK, Initial code
*******************************************************************/
{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while( 0 == (TWCR & 0x80) );
}

/******************************************************************/





void start_init(void){
	
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
	
	
	//dimming all leds
	twi_start();
	twi_tx(0xE0);	
	twi_tx(0x00);	
	for(int i=0; i < 16; i++){	
	twi_tx(0x00);	// data
	}
	
	twi_stop();
	
	
}

void decision(int good){
	
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
