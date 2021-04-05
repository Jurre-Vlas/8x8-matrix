#ifndef LCDH
#define LCDH
void lcd_write_command(unsigned char byte);
void lcd_write_data(unsigned char byte);
void lcd_write_string(char *str);
void init_4bits_mode(void);
void lcd_strobe_lcd_e(void);



#endif