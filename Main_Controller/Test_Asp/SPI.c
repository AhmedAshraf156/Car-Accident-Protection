#include "SPI.h"
void SPI_init_Master(void)
{
	setbit(DDRB,0);
	setbit(DDRB,1);
	clearbit(DDRB,3);
	setbit(DDRB,2);
    
	SPCR=0b01010000;
}
void SPI_init_Slave()
{
	clearbit(DDRB,0);
	clearbit(DDRB,1);
	setbit(DDRB,3);
	clearbit(DDRB,2);
	
	SPCR=0b01000000;
}
void SPI_sendByte(unsigned char data)
{
	SPDR=data;
	while(readbit(SPSR,SPIF)==0){}; //wait until SPI interrupt flag=1 (data is sent correctly)
}
unsigned char SPI_recieveByte(void)
{
	while(readbit(SPSR,SPIF)==0){}  //wait until SPI interrupt flag=1 (data is sent correctly)
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
