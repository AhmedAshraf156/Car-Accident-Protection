#ifndef VERIFY_H_
#define VERIFY_H_

/************** Includes & Definitions *******************/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "StandredMacros.h"
#include "STD.h"
#include "UART.h"

/********************* ProtoTypes ************************/
bool auto_authorization();
bool Interupt_raspi_check();
bool manual_authorization();
bool raspi_check();
void Verify_App();

#endif