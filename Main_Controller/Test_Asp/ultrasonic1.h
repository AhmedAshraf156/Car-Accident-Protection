#ifndef _ULTRA_H_
#define _ULTRA_H_

/********************* Includes & Definitions **************************/
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "timer.h"
#include "StandredMacros.h"
#include "STD.h"
#include "UART.h"

/************************* Functions Prototypes ************************/
void ultra1_init(void);
void enable_ex1_interrupt(void);
void ultra1_triger(void);

#endif
