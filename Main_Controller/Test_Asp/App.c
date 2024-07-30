#include "App.h"
char status='0';
char car_status='0';
extern distance0;
extern distance1;
int speed=0;
int dataIndex = 0;
char receivedData[10]; 
char raspberryData[10];

void Init_Reg()
{
	SPI_init_Master();
	gsm_init();
	gps_init();
	ultra0_init();
	ultra1_init();
	UART0_init();
	UART3_init();
    Car_Init();
	ADC_init();
	sei();			  //global interrupt enable
	clearbit(DDRE,3); //for accident sensing
	ultra0_triger();
	ultra1_triger();
	clearbit(DDRB,4); //for drownis sent by raspberry

	UART0_sendString("y,no\n\r");
	UART0_sendString("\n\r");
	_delay_ms(2000);
	UART0_sendString("x,no\n\r");
	UART0_sendString("\n\r");
	_delay_ms(2000);
}

void Application()
{
	char i;      //For GPS trials
	status='1';  //Car can move
	
	/************************ UltraSonic Check ***************************/
	if (car_status=='1')    //Car Move Backward
	{
		Back_ultra_trigge();
	}
	else if (car_status=='2')   //Car Move Forward
	{
		Front_ultra_trigger();
	}
	/********************************************************************/
	
	_delay_ms(120);
	
	/************************ Temperature check ***************************/
    Temp_read();
	/********************************************************************/
	_delay_ms(120);
	/************************ Speed check ***************************/
    speed_check();
	/********************************************************************/
	_delay_ms(100);
	/*************************** Smoke Check ****************************/
    Smoke_check();
	/************************** Alcohol Check ***************************/
	Alcohol_check();
	/************************** Drownis Check ***************************/
	Drownis_check();
	
	/************************ UltraSonic Check ***************************/
	if (car_status=='1')    //Car Move Backward
	{
		Back_ultra_trigge();
	}
	else if (car_status=='2')   //Car Move Forward
	{
		Front_ultra_trigger();
	}
	/********************************************************************/
	
	_delay_ms(120);
	
	/************************* GPS Check ********************************/
	for(i=0;i<120;i++)
	{
		receive();
	}
	send_data();
	/*******************************************************************/
	
	_delay_ms(120);
	
	/************************ UltraSonic Check ***************************/
	if (car_status=='1')    //Car Move Backward
	{
		Back_ultra_trigge();
	}
	else if (car_status=='2')   //Car Move Forward
	{
		Front_ultra_trigger();
	}
	/********************************************************************/
	
	_delay_ms(120);
	
	/********************************************************************/
}

void Accident_Detect()
{
	if (readbit(PINE,3)==1)
	{
		gsm_send_accident_message();
	}
}

void Temp_read()
{
	float RES;
	float volt;
	char RES_Str[10];
	volt=Temp_ADC_read();
	RES=(float)(5*volt)/1023;//conversation for LM45 Sensor
	RES*=100;
	itoa(RES,RES_Str,10);
    UART0_sendString("z,");
	UART0_sendString(RES_Str);
	UART0_sendString(" c\n");
	UART0_sendString(" \n\r");
	Accident_Detect();/***********acident check*************/
	
	if(RES>60)
	{
		Accident_Detect();
		SPI_sendByte('i');
		_delay_ms(700);
		UART0_sendString("t,High Temp\n\r");
		status='0';
		_delay_ms(3000);	
		Temp_read();
	}
	UART0_sendString("t,No Error\n\r");
	_delay_ms(3000);
	status='1';
}
/****************************************************************************/
void Front_ultra_trigger()
{
	uint8_t distance_str1[10];

	ultra1_triger();
	
	itoa(distance1,distance_str1,10);
	UART0_sendString("u,");
	UART0_sendString(distance_str1);
	UART0_sendString(" Cm.\n");
	UART0_sendString(" \n\r");
	_delay_ms(50);
	Accident_Detect();/***********acident check*************/
	
	if (distance1<120 && distance1>75)
	{
			UART0_sendString("o\n\r");
			UART0_sendString("o\n\r");
	}
	else if (distance1<=75)
	{
		SPI_sendByte('i');
		_delay_ms(500);
		UART0_sendString("n\n\r");
		_delay_ms(1000);
		UART0_sendString("n\n\r");
		_delay_ms(1500);
		UART0_sendString("u,");
		UART0_sendString(distance_str1);
		UART0_sendString(" Cm.\n\r");
		_delay_ms(2500);
	}
	else
	{
		UART0_sendString("p\n\r");
		_delay_ms(500);
		UART0_sendString("p\n\r");
		_delay_ms(500);

	}
}
/*****************************************************************************/
void Alcohol_check()
{
	if (readbit(PINA,3)==0)
	{
		Accident_Detect();/***********acident check*************/
		UART0_sendString("x,Yes\n\r");
		SPI_sendByte('i');
		status='0';
		_delay_ms(1000);
		UART0_sendString("x,Yes\n\r");
		_delay_ms(2000);
		UART0_sendString("t,Alcohol Detected\n\r");
		_delay_ms(1000);
		drowsy_smoke_alcohol_message();/************send message************/
		while (readbit(PINA,3)==0)
		{
		Accident_Detect();/***********acident check*************/
		}	
		UART0_sendString("x,no\n\r");
        _delay_ms(2500);
		UART0_sendString("t,No Error\n\r");
        _delay_ms(2500);
		status='1';
	}
}

/***************************************************************************/
void Back_ultra_trigge()
{
	uint8_t distance_str0[10];

	ultra0_triger();
	
	itoa(distance0,distance_str0,10);
	UART0_sendString("v,");
	UART0_sendString(distance_str0);
	UART0_sendString(" Cm.\n");
	UART0_sendString(" \n\r");
	_delay_ms(50);
	Accident_Detect();/***********acident check*************/
	
	if (distance0<120 && distance0>70)
	{
		UART0_sendString("o\n\r");
		UART0_sendString("o\n\r");
	}
	else if (distance0<=70)
	{
		SPI_sendByte('i');
		_delay_ms(500);
		UART0_sendString("n,\n\r");
		_delay_ms(1000);
		UART0_sendString("n,\n\r");
		_delay_ms(1000);
		UART0_sendString("v,");
		UART0_sendString(distance_str0);
		UART0_sendString(" Cm.\n\r");
		_delay_ms(1500);
	}
	else
	{
		UART0_sendString("p\n\r");
		UART0_sendString("p\n\r");
	}
}
/*****************************************************************************/

void Smoke_check()
{
	if (readbit(PINA,2)==0)
	{
		SPI_sendByte('i');
		_delay_ms(500);
		UART0_sendString("y,yes\n\r");
		_delay_ms(1000);
		UART0_sendString("t,Smoke Detected\n\r");
		status='0';
		Accident_Detect();/***********acident check*************/
		drowsy_smoke_alcohol_message();/************send message************/
		while (readbit(PINA,2)==0)
		{
		Accident_Detect();/***********acident check*************/
		}
		UART0_sendString("y,no\n\r");
		_delay_ms(1000);
		UART0_sendString("t,No Error\r");
		Accident_Detect();/***********acident check*************/
		_delay_ms(1000);
		status='1';
		//smoke=false;
	}
}

/*****************************************************************************/

void Drownis_check()
{
	if (readbit(PINB,4)==1)
	{
		SPI_sendByte('i');
		_delay_ms(500);
		UART0_sendString("t,User is Sleepy\n\r");
		_delay_ms(3000);
		status='0';
		drowsy_smoke_alcohol_message();/************send message************/
		while (readbit(PINB,4)==1)
		{
			Accident_Detect();/***********acident check*************/
		}
		UART0_sendString("t,No Error\r");
		_delay_ms(3000);
		status='1';
		Accident_Detect();/***********acident check*************/
	}
}
void speed_check()
{
	unsigned char speed_str[10];
	int rx_speed;
	rx_speed=atoi(&receivedData);
	if (rx_speed>0 && rx_speed<300)
	{
		speed=rx_speed;
	}	
	itoa(speed,speed_str,10);
	UART0_sendString("s,");
	UART0_sendString(speed_str);
	UART0_sendString("\n\r");
}

/****************************************************************************/
ISR(USART0_RX_vect)
{
	unsigned char rxdata='0';
	rxdata=UDR0;
	if (rxdata == '\n' || rxdata == '\r' || rxdata=='#')  // Check if the received character is a newline or carriage return (end of the number)
	{
		receivedData[dataIndex] = '\0'; // Null-terminate the received data
		dataIndex = 0; // Reset the index for the next number
	}
	else
	{
		receivedData[dataIndex++] = rxdata;
		rxdata='0';
	}
	if (!(strcmp(receivedData,"c")) && status=='1')
	{
		SPI_sendByte('i');
		_delay_ms(1500);
		SPI_sendByte('z');
		car_status='1';
	}
	else if (!(strcmp(receivedData,"h")) && status=='1')
	{
		SPI_sendByte('h');
	}
	else if (!(strcmp(receivedData,"g")) && status=='1')
	{
		SPI_sendByte('g');
	}
	else if (!(strcmp(receivedData,"f")) && status=='1')
	{
		SPI_sendByte('i');
		_delay_ms(1500);
		SPI_sendByte('f');
		car_status='2';
	}
	else if (!(strcmp(receivedData,"i")))
	{
		SPI_sendByte('i');
	}
	else if (!(strcmp(receivedData,"a")) && status=='1')
	{
		SPI_sendByte('i');
		_delay_ms(800);
		SPI_sendByte('x');
		car_status='1';
		
	}
	else if (!(strcmp(receivedData,"b")) && status=='1')
	{
		_delay_ms(1000);
		SPI_sendByte('y');
		car_status='1';
	}
	else if (!(strcmp(receivedData,"d")) && status=='1')
	{
		SPI_sendByte('i');
		_delay_ms(800);
		SPI_sendByte('d');			
		car_status='2';
	}
	else if (!(strcmp(receivedData,"e")) && status=='1')
	{
		SPI_sendByte('i');
		_delay_ms(1000);
		SPI_sendByte('e');
		car_status='2';
	}
	else if (!(strcmp(receivedData,"r")))
	{
		if (Interupt_raspi_check()==1)
		{
			UART0_sendString("r\n\r");
			UART0_sendString("r\n\r");
			UART0_sendString("r\n\r");
			UART0_sendString("r\n\r");
			_delay_ms(2000);
		}
	}
}
ISR(USART3_RX_vect)
{
	unsigned char rxdata='0';
	rxdata=UDR3;
	if (rxdata == '\n' || rxdata == '\r' || rxdata=='#')  // Check if the received character is a newline or carriage return (end of the number)
	{
		raspberryData[dataIndex] = '\0'; // Null-terminate the received data
		dataIndex = 0;
	}
	else
	{
		raspberryData[dataIndex++] = rxdata;
		rxdata='0';
	}
}