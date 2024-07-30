#include "timer.h"

void timer0_init(void)
{
	    	/* Disable Timer 0 */
	    	TCCR0A =  0x00;
	    	/* Setting pre scaler /1 */
	    	TCCR0B = 0x01;
	    	/* Initializing the timer with zero */
	    	TCNT0 = 0x00;
			/* Timer overflow interrupt enable*/
			TIMSK0 |=(1<<TOIE0);

	return;
}
void timer2_init(void)
{
	/* Disable Timer 0 */
	TCCR2A =  0x00;
	/* Setting pre scaler /1 */
	TCCR2B = 0x01;
	/* Initializing the timer with zero */
	TCNT2 = 0x00;
	/* Timer overflow interrupt enable*/
	TIMSK2 |=(1<<TOIE2);

	return;
}

void timer1_init(void)
{
    TCCR1A=0b10000001;
    TCCR1B=0b00001001;
	/*setbit(TCCR1A,COM1A1);
    setbit(TCCR1A,WGM11);
	setbit(TCCR1B,WGM12);
	setbit(TCCR1B,WGM13);
	setbit(TCCR1B,CS10);*/
}

void timer3_init(void)
{
	TCCR3A=0b10000001;
	TCCR3B=0b00001001;
	/*setbit(TCCR3A,COM3A1);
    setbit(TCCR3A,WGM31);
	setbit(TCCR3B,WGM32);
	setbit(TCCR3B,WGM33);
    setbit(TCCR3B,CS30);*/
}