#ifndef GPS_H_
#define GPS_H_

/********************* Includes & Definitions **************************/
#include "std_types.h"
#include "UART.h"

#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <util/delay.h>
#include <stdbool.h>

/************************* Functions Prototypes ************************/
void gps_init();
void receive();
void get_google_maps_url(double latitude, double longitude, char *url_buffer);
void send_data();
void gps_send_sms_data();

#endif /* GPS_H_ */
