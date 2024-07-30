#include "timer.h"

void timer0_init(void)
{
	TCCR0 = 0b01101001;
}
void timer2_init(void)
{
	TCCR2 = 0b01101001;
}

void timer0_low()
{
	OCR0=180;
}
void timer0_med()
{
	OCR0=195;
}
void timer0_high()
{
	OCR0=210;
}
void timer2_low()
{
	OCR2=180;
}
void timer2_med()
{
	OCR2=195;
}
void timer2_high()
{
	OCR2=210;
}