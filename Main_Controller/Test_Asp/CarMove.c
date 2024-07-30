#include "CarMove.h"

void Car_Init()
{
    setbit(DDRA,0);	
	setbit(DDRA,4);
    setbit(DDRA,1);
	setbit(DDRA,5);
    setbit(DDRB,5);
    setbit(DDRE,3);
	//timer1_init();
	//timer3_init();
	
}
void Car_Stop()
{
    clearbit(PORTB,5);
	clearbit(PORTE,3);
	//OCR1A=1;
	//OCR3A=1;
}
void Car_Forward()
{
	setbit(PORTB,5);
	setbit(PORTE,3);
	setbit(PORTA,0);
	setbit(PORTA,4);
	clearbit(PORTA,1);
	clearbit(PORTA,5);
	//OCR1A=240;
	//OCR3A=240;
}
void Car_Backward()
{
	setbit(PORTE,3);
	setbit(PORTB,5);
	setbit(PORTA,1);
	setbit(PORTA,5);
	clearbit(PORTA,0);
	clearbit(PORTA,4);
	//OCR1A=240;
	//OCR3A=240;
}
void Car_Left()
{
	setbit(PORTE,3);
	clearbit(PORTB,5);
    //OCR1A=250;
	//OCR3A=200;
}
void Car_Right()
{
	clearbit(PORTE,3);
	setbit(PORTB,5);
	//OCR1A=200;
	//OCR3A=250;
}
/*
void Car_Forward_slow()
{
	setbit(PORTA,0);
	clearbit(PORTA,1);
	OCR1A=200;
	OCR3A=200;
}
void Car_Backward_slow()
{
	clearbit(PORTA,0);
	setbit(PORTA,1);
	OCR1A=200;
	OCR3A=200;
}
*/