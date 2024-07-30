#ifndef ADC_H_
#define ADC_H_

/********************* Includes & Definitions **************************/
#include "StandredMacros.h"
#include "STD.h"

/************************* Functions Prototypes ************************/
float Temp_ADC_read();
void ADC_init(void);
int Smoke_ADC_read();

#endif