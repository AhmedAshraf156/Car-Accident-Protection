#include "App.h"

unsigned char rxdata;

void Registers_init()
{
	timer2_init();
	timer0_init();
	SPI_init_Slave();
	//sei();
	setbit(DDRA,0);
	setbit(DDRA,1);
	setbit(DDRB,3);
	setbit(DDRD,7);
	SREG |= (1<<7);  //global interrupt enable
	clearbit(DDRD,2);
	GICR |=(1<<6);  //External Interrupt Request 0 Enable

}

void app()
{
		switch(rxdata)
		{
			case'x': move_forward_low();break;
			case'y': move_forward_mid();break;
			case'z': move_forward_high();break;
			case'd': move_backward_low();break;
			case'e': move_backward_mid();break;
			case'f': move_backward_high();break;
			case'g': rotate_left();break;
			case'h': rotate_right();break;
			case'i': stop();break;
			default: break;
		}
	if (readbit(PIND,2)==0)
	{
		while(readbit(PIND,2)==0)
		{
			;
		}
	}
}

void move_forward_low()
{
	setbit(PORTA,0);
	clearbit(PORTA,1);
	timer0_low();
	timer2_low();
}
void move_forward_mid()
{
	setbit(PORTA,0);
	clearbit(PORTA,1);
	timer0_med();
	timer2_med();
}
void move_forward_high()
{
	setbit(PORTA,0);
	clearbit(PORTA,1);
	timer0_high();
	timer2_high();
}
void move_backward_low()
{
	setbit(PORTA,1);
	clearbit(PORTA,0);
	timer0_low();
	timer2_low();
}
void move_backward_mid()
{
	setbit(PORTA,1);
	clearbit(PORTA,0);
	timer0_med();
	timer2_med();
}
void move_backward_high()
{
	setbit(PORTA,1);
	clearbit(PORTA,0);
	timer0_high();
	timer2_high();
}
void rotate_left()
{
	timer0_med();
	OCR2=0;
}
void rotate_right()
{
	OCR0=0;
	timer2_med();
}
void stop()
{
	OCR2=0;
	OCR0=0;
	clearbit(PORTA,0);
	clearbit(PORTA,1);
}

ISR(SPI_STC_vect)
{
	rxdata=SPDR;
}
ISR(INT0_vect)
{
	clearbit(PORTA,0);
	clearbit(PORTA,1);
}
