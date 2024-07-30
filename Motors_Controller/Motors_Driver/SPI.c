#include "SPI.h"
void SPI_init_Master()
{
	setbit(DDRB,5);
	setbit(DDRB,4);
	clearbit(DDRB,6);
	setbit(DDRB,7);
    
	SPCR=0b01010000;
	
}
void SPI_init_Slave()
{
	clearbit(DDRB,5);
	clearbit(DDRB,4);
	setbit(DDRB,6);
	clearbit(DDRB,7);
	
	SPCR=0b11000000;

}
void SPI_sendByte(unsigned char data)
{
	SPDR=data;
	while(readbit(SPSR,SPIF)==0){};//wait till it be sent
}
unsigned char SPI_recieveByte(void)
{
	while(readbit(SPSR,SPIF)==0){} //wait till it be received
    return SPDR;
}

void SPI_sendString(const unsigned char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		SPI_sendByte(Str[i]);
		i++;
	}

}

void SPI_receiveString(char *Str)
{
	unsigned char i = 0;
	Str[i] = SPI_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = SPI_recieveByte();
	}
	Str[i] = '\0';
}
