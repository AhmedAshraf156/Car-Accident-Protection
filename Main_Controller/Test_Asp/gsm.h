#ifndef GSM_H_
#define GSM_H_

/************** Includes & Definitions *******************/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "StandredMacros.h"
#include "STD.h"
#include "UART.h"
#include "gps.h"
#include "App.h"
#define F_CPU 8000000UL

/********************* ProtoTypes ************************/
void gsm_init();
void gsm_send_accident_message();
void drowsy_smoke_alcohol_message();

#endif