#ifndef TIMER_H_
#define TIMER_H_

/************** Includes & Definitions *******************/

#include <avr/io.h>
#include "StandredMacros.h"

/********************* ProtoTypes ************************/
void timer0_init(void);
void timer2_init(void);

void timer0_low();
void timer0_med();
void timer0_high();
void timer2_low();
void timer2_med();
void timer2_high();

#endif 
