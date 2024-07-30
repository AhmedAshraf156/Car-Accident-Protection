#ifndef APP_H_
#define APP_H_

/************** Includes & Definitions *******************/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "StandredMacros.h"
#include "STD.h"
#include "SPI.h"
#include "ultrasonic.h"
#include "ultrasonic1.h"
#include "CarMove.h"
#include "ADC.h"
#include "UART.h"
#include "gps.h"
#include "gsm.h"
#include "Verify.h"

#define F_CPU 8000000UL
#include <string.h>

/********************* ProtoTypes ************************/
void Init_Reg();
void Application();
void Temp_read();
void Smoke_read(float Ro);
void Front_ultra_trigger();
void Back_ultra_trigge();
void Smoke_check();
void Alcohol_check();
void Drownis_check();
void speed_check();
void Accident_Detect();




#endif
