#include "ultrasonic.h"

uint8_t sensor_working0=0;
uint8_t rising_edge0=0;
uint32_t timer_counter0=0;
uint32_t distance0;

void ultra0_init(void)
{
	setbit(DDRC,3);
	clearbit(DDRE,5);
	setbit(PORTE,5);
	enable_ex0_interrupt();
	timer2_init();
}

void enable_ex0_interrupt(void)
{
	EICRB |= (1<<ISC40);   		// Trigger INT1 on any logic change.
	EIMSK  |= (1<<INT4);			// Enable INT1 interrupts.
}

void ultra0_triger(void)
{
	if(!sensor_working0)
	{
		setbit(PORTC,3);
		_delay_us(20);
		clearbit(PORTC,3);
		sensor_working0=1;
	}
}

ISR(INT5_vect)
{
	if(sensor_working0==1)
	{
		if(rising_edge0==0)
		{
			TCNT2=0x00;
			rising_edge0=1;
			timer_counter0=0;
		}
		else
		{
			distance0=(timer_counter0*256+TCNT2)/466;
		}
	}
}

ISR(TIMER2_OVF_vect)
{
	timer_counter0++;
	if(timer_counter0 >730)
	{
		TCNT2=0x00;
		sensor_working0=0;
		rising_edge0=0;
		timer_counter0=0;
	}
}
