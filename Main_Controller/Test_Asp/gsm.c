#include "gsm.h"
bool drown=false;
bool smoke=false;
bool alcohol=false;

void gsm_init()
{
	UART2_init();
}

void gsm_send_accident_message()
{
	if (readbit(PINB,4)==1)
	{
		drown=true;
	}
	else if(readbit(PINB,4)==0)
	{
		drown=false;
	}
	if (readbit(PINA,2)==0)
	{
		smoke=true;
	}
	else if(readbit(PINA,2)==1)
	{
		smoke=false;
	}
	if (readbit(PINA,3)==0)
	{
		alcohol=true;
	}
	else if(readbit(PINA,3)==1)
	{
		alcohol=false;
	}
	UART2_sendString("AT\n\r");
	_delay_ms(1000);
	UART2_sendString("AT+CREG?\n\r");
	_delay_ms(1000);
	UART2_sendString("AT+CMGF=1\n\r");
	_delay_ms(1000);
	UART2_sendString("AT+CMGS=\"+201013982361\"\n\r");
	_delay_ms(1000);
	/********************message**************************/
	UART2_sendString("Accident occur to car 5748 and that is its condition\n\r");
	if (smoke==true)
	{
		UART2_sendString("smoke detected\n\r");
	}
	else
	{
		UART2_sendString("smoke not detected\n\r");
	}
	if (alcohol==true)
	{
		UART2_sendString("alcohol detected\n\r");
	}
	else
	{
		UART2_sendString("alcohol not detected\n\r");
	}
	if (drown==true)
	{
		UART2_sendString("drown detected\n\r");
	}
	else
	{
		UART2_sendString("drown not detected\n\r");
	}
	UART2_sendString("Car Location is : \n");
	gps_send_sms_data();
	/*****************************************************/
	_delay_ms(1000);
	while(BIT_IS_CLEAR(UCSR2A,UDRE2))
	{
		;
	}
	UDR2 = 0x1A;
	_delay_ms(10000);
}
void drowsy_smoke_alcohol_message()
{
	if (readbit(PINB,4)==1)
	{
		drown=true;
	}
	else if(readbit(PINB,4)==0)
	{
		drown=false;
	}
	if (readbit(PINA,2)==0)
	{
		smoke=true;
	}
	else if(readbit(PINA,2)==1)
	{
		smoke=false;
	}
	if (readbit(PINA,3)==0)
	{
		alcohol=true;
	}
	else if(readbit(PINA,3)==1)
	{
		alcohol=false;
	}
	
	UART2_sendString("AT\n\r");
	_delay_ms(1000);
	UART2_sendString("AT+CREG?\n\r");
	_delay_ms(1000);
	UART2_sendString("AT+CMGF=1\n\r");
	_delay_ms(1000);
	UART2_sendString("AT+CMGS=\"+201013982361\"\n\r");
	_delay_ms(1000);
	
	/********************message**************************/
	if (drown==true)
	{
		UART2_sendString("Driver of car 5748 fell asleep while driving and that is over the car condition : \n\r");
	}
	else if (smoke==true)
	{
		UART2_sendString("Smoke Detected in car 5748 and that is the overall car condition : \n\r");
	}
	else if (alcohol==true)
	{
		UART2_sendString("Alcohol Detected in car 5748 and that is the overall car condition : \n\r");
	}
	if (smoke==true)
	{
		UART2_sendString("smoke detected\n\r");
	}
	else
	{
		UART2_sendString("smoke not detected\n\r");
	}
	if (alcohol==true)
	{
		UART2_sendString("alcohol detected\n\r");
	}
	else
	{
		UART2_sendString("alcohol not detected\n\r");
	}
	if (drown==true)
	{
		UART2_sendString("drown detected\n\r");
	}
	else
	{
		UART2_sendString("drown not detected\n\r");
	}
	UART2_sendString("Car Location is : \n");
	gps_send_sms_data();
	/*****************************************************/
	_delay_ms(1000);
	while(BIT_IS_CLEAR(UCSR2A,UDRE2))
	{
		;
	}
	UDR2 = 0x1A;
	_delay_ms(10000);
}

ISR(USART2_RX_vect)
{
	unsigned char data=UDR2;
	UART0_sendByte(data);
}
