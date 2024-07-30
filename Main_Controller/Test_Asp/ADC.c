#include <avr/io.h>
#include "ADC.h"

void ADC_init(void){//initialize ADC Registers
ADMUX=0b01000000;
ADCSRA=0b10000011;
}
//4 flag   6 start
float Temp_ADC_read(void){//Read Analog Value
	volatile signed int volt; 
	ADMUX=0b01000000;
	setbit(ADCSRA,4); // clear flag
	setbit(ADCSRA,6); //start conversion bit register
	while(readbit(ADCSRA,4)==0){ }; //wait for coversion til flag became one
	volt=ADC;

   return volt;
}

int Smoke_ADC_read()
{
	/* set input channel to read */
	ADMUX=0b01000001;
	/* Start ADC conversion */
	ADCSRA |= (1<<ADSC);
	/* Wait until end of conversion by polling ADC interrupt flag */
	while (!(ADCSRA & (1<<ADIF)));
	/* Clear interrupt flag */
	ADCSRA |= (1<<ADIF);               
	/* Return ADC word */
	return ADCW;
}