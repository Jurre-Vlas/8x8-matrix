/*
 * lcd.h
 *
 * Created: 4-4-2021 16:09:21
 *  Author: kroelie woelie
 */ 
#ifndef LCDH
#define LCDH
void init();
void display_text(char *str);
void cmdSend(char cmd);
void charSend(char character);
void displaySend(char bytes, int rs);
void blinkE();
void return_home();
void set_cursor(int position);
void clear();
void wait( int ms );
#endif