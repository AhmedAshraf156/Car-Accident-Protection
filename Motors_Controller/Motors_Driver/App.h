#ifndef APP_H_
#define APP_H_

#include "SPI.h"
#include "timer.h"
#include "StandredMacros.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL

void Registers_init();
void app();
void move_forward_low();
void move_forward_mid();
void move_forward_high();
void move_backward_low();
void move_backward_mid();
void move_backward_high();
void rotate_left();
void rotate_right();
void stop();

#endif