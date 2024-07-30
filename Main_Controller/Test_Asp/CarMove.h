#ifndef CARMOVE_H_
#define CARMOVE_H_

/********************* Includes & Definitions **************************/
#include "timer.h"
#include "StandredMacros.h"
#include "STD.h"
#include <avr/io.h>

/************************* Functions Prototypes ************************/
void Car_Init();
void Car_Stop();
void Car_Forward();
void Car_Right();
void Car_Left();
void Car_Backward();
void Car_Forward_slow();

#endif