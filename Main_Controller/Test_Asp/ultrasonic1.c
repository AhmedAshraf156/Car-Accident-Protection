#include "ultrasonic1.h"


uint8_t sensor_working1=0;
uint8_t rising_edge1=0;
uint32_t timer_counter1=0;
uint32_t distance1;

void ultra1_init(void)
{
	setbit(DDRC,2);
	clearbit(DDRE,4);
	setbit(PORTE,4);
	enable_ex1_interrupt();
	timer0_init();
}

void enable_ex1_interrupt(void)
{
	EICRB |= (1<<ISC50);   		// Trigger INT1 on any logic change.
	EIMSK  |= (1<<INT5);			// Enable INT1 interrupts.
}

void ultra1_triger(void)
{
	if(!sensor_working1)
	{
		setbit(PORTC,2);
		_delay_us(20);
		clearbit(PORTC,2);
		sensor_working1=1;
	}
}

ISR(INT4_vect)
{
	if(sensor_working1==1)
	{
		if(rising_edge1==0)
		{
			TCNT0=0x00;
			rising_edge1=1;
			timer_counter1=0;
		}
		else
		{
			distance1=(timer_counter1*256+TCNT0)/466;
		}
	}
}

ISR(TIMER0_OVF_vect)
{
	timer_counter1++;
	if(timer_counter1 >730)
	{
		TCNT0=0x00;
		sensor_working1=0;
		rising_edge1=0;
		timer_counter1=0;
	}
}

