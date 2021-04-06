
#ifndef MATRIX_H_
#define MATRIX_H_

void twi_init(void);
void twi_start(void);
void twi_stop(void);
void twi_tx(unsigned char data);
void wait( int ms );
void start_init(void);
void decision(int good);
void countToDecision();


#endif /* MATRIX_H_ */