#include "App.h"

int main(void)
{
    Init_Reg();
	Verify_App();
	/************************Start Drownis check*************************/
	_delay_ms(6000);
	UART3_sendString("Drowsy Start\n\r");
	_delay_ms(3000);    //Ensure message is sent completely
    while(1)
	{
        Application();
	}
}

