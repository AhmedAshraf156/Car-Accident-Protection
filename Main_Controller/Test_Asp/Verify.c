#include "Verify.h"

extern char receivedData[10];
extern char raspberryData[10];

void Verify_App()
{
	bool ras_check;
	bool auto_detect;
	
	ras_check=raspi_check();
	if (ras_check==true)
	{
		UART0_sendString("r\n\r");
		_delay_ms(1500);
		auto_detect=auto_authorization();
		if (auto_detect==false)
		{
			manual_authorization();
		}
	}
	else if(ras_check==false)
	{
		manual_authorization();
	}
}

bool raspi_check()
{
	unsigned int timer;
	int count;
	UART0_sendString("t,Raspberry check !\n\r");
	_delay_ms(3000);
	UART3_sendString("Hello pi\n\r");

	for (count=0;count<40;count++)
	{
		_delay_ms(3000);
		UART3_sendString("Hello pi\n\r");
		
		for (timer=0;timer<60000;timer++)
		{
			if (!(strcmp(raspberryData,"Hello AVR")))
			{
				UART0_sendString("r\n\r");
				UART0_sendString("r\n\r");
				UART0_sendString("r\n\r");
				UART0_sendString("r\n\r");	
				_delay_ms(2500);
				return true;
			}
		}
	}
	_delay_ms(3000);
	UART0_sendString("t,Raspberry not Detected !\n\r");
	_delay_ms(15000);
	UART0_sendString("t,Enter Code Manually !\n\r");
	_delay_ms(10000);
	return false;
}
bool Interupt_raspi_check()
{
	unsigned int timer;
	int count;
	UART3_sendString("Hello pi\n\r");
	for (count=0;count<3;count++)
	{			
		for (timer=0;timer<60000;timer++)
		{
			if (!(strcmp(raspberryData,"Hello AVR")))
			{
				UART0_sendString("r\n\r");
				UART0_sendString("r\n\r");
				_delay_ms(1000);
				UART0_sendString("r\n\r");
				UART0_sendString("r\n\r");		
				_delay_ms(1000);

				return true;
			}
		}
	}
	return false;
}

bool auto_authorization()
{
	unsigned int timer;
	int count;
	_delay_ms(6000);
	UART3_sendString("Open_face\n\r");
	for (count=0;count<50;count++)
	{
		for (timer=0;timer<50000;timer++)  //counter to detect face
		{
			if (!(strcmp(raspberryData,"Ahmed")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(5000);
				UART0_sendString("q,Ahmed\n\r");
				_delay_ms(5000);
				UART3_sendString("Close_face");
				_delay_ms(4000);
				return true;
			}
			else if (!(strcmp(raspberryData,"Anas")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(5000);
				UART0_sendString("q,Anas\n\r");
				_delay_ms(5000);
				UART3_sendString("Close_face\n\r");
				_delay_ms(4000);
				return true;
			}
			else if (!(strcmp(raspberryData,"Gamal")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(5000);
				UART0_sendString("q,Gamal\n\r");
				_delay_ms(5000);
				UART3_sendString("Close_face\n\r");
				_delay_ms(4000);
				return true;
			}
			else if (!(strcmp(raspberryData,"Toka")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(5000);
				UART0_sendString("q,Toka\n\r");
				_delay_ms(5000);
				UART3_sendString("Close_face\n\r");
				_delay_ms(4000);
				return true;
			}
			else if (!(strcmp(raspberryData,"Rawan")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(5000);
				UART0_sendString("q,Rawan\n\r");
				_delay_ms(5000);
				UART3_sendString("Close_face\n\r");
				_delay_ms(4000);
				return true;
			}
		}
	}
	UART0_sendString("t,Face not Detected !\n\r");
	_delay_ms(10000);
	UART0_sendString("Enter code Manually !\n\r");
	_delay_ms(10000);
	UART3_sendString("Close_Face\n\r");
	_delay_ms(6000);
	return false;
}

bool manual_authorization()
{
	unsigned int timer;
	int count;
	for (count=0;count<20;count++)
	{
		for (timer=0;timer<50000;timer++)  //counter to detect face
		{
			if (!(strcmp(receivedData,"6752")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(4000);
				UART0_sendString("q,Ahmed\n\r");
				_delay_ms(4000);
				return true;
			}
			else if (!(strcmp(receivedData,"2874")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(4000);
				UART0_sendString("q,Anas\n\r");
				_delay_ms(4000);
				return true;
			}
			else if (!(strcmp(receivedData,"1436")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(4000);
				UART0_sendString("q,Gamal\n\r");
				_delay_ms(4000);
				return true;
			}
			else if (!(strcmp(receivedData,"4763")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(4000);
				UART0_sendString("q,Toka\n\r");
				_delay_ms(4000);
				return true;
			}
			else if (!(strcmp(receivedData,"9615")))
			{
				UART0_sendString("t,User verified\n\r");
				_delay_ms(4000);
				UART0_sendString("q,Rawan\n\r");
				_delay_ms(4000);
				return true;
			}
		}
	}
	

	UART0_sendString("t,Face not Detected !\n\r");
	_delay_ms(10000);
	UART0_sendString("Car Blocked !\n\r");
	_delay_ms(2000);
	while (1)
	{
		;
	}
	return false;
	
}