#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include "StandredMacros.h"
void SPI_init_Master(void);
void SPI_init_Slave(void);
void SPI_sendByte(unsigned char data);
unsigned char SPI_recieveByte(void);
void SPI_sendString(const unsigned char *Str);
void SPI_receiveString(char *Str);




#endif /* SPI_H_ */