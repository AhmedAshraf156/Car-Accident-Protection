#include "gps.h"

unsigned char value,lati_value[15],longi_value[15],lati_dir,longi_dir;
uint8 i,j=0;
//uint8 done=0;

void gps_init()
{
	UART1_init();
	UART0_init();
}

void receive()
{

	value=UART1_recieveByte();
	if(value=='$')
	{
		value=UART1_recieveByte();
		if(value=='G')
		{
			value=UART1_recieveByte();
			if(value=='P')
			{
				value=UART1_recieveByte();
				if(value=='G')
				{
					value=UART1_recieveByte();
					if(value=='G')
					{
						value=UART1_recieveByte();
						if(value=='A')
						{
							value=UART1_recieveByte();
							if(value==',')
							{
								value=UART1_recieveByte();
								while(value!=',')
								{
									value=UART1_recieveByte();
								}
								lati_value[0]=UART1_recieveByte();
								value=lati_value[0];
								for(i=1;value!=',';i++)
								{
									lati_value[i]=UART1_recieveByte();
									value=lati_value[i];
								}
								lati_value[i-1]=' ';
								lati_dir=UART1_recieveByte();
								value=UART1_recieveByte();
								while(value!=',')
								{
									value=UART1_recieveByte();
								}
								longi_value[0]=UART1_recieveByte();
								value=longi_value[0];
								for(i=1;value!=',';i++)
								{
									longi_value[i]=UART1_recieveByte();
									value=longi_value[i];
								}
								longi_value[i-1]=' ';
								longi_dir=UART1_recieveByte();
								
								_delay_ms(100);
								//Sent Data to Mobile
								return 0;
							}	
						}
					}
				}
			}
		}
	}
}

void send_data()
{
								int i=0;
								UART0_sendString("w,");
								while(lati_value[i]!='\0')
								{
									UART0_sendByte(lati_value[i]);
									i++;
									if (i==2)
									{
										UART0_sendByte('*');
									}
								}
								UART0_sendByte('`');
								UART0_sendByte(lati_dir);
								UART0_sendString("\n");

								i=1;
								while(longi_value[i]!='\0')
								{
									UART0_sendByte(longi_value[i]);
									i++;
									if (i==3)
									{
										UART0_sendByte('*');
									}
								}
								UART0_sendByte('`');
								UART0_sendByte(longi_dir);
								UART0_sendString("\n\r");
}
gps_send_sms_data()
{
								int i=0;
								while(lati_value[i]!='\0')
								{
									UART2_sendByte(lati_value[i]);
									i++;
									if (i==2)
									{
										UART2_sendByte('*');
									}
								}
								UART2_sendByte('`');
								UART2_sendByte(lati_dir);
								UART2_sendString("\n");

								i=1;
								while(longi_value[i]!='\0')
								{
									UART2_sendByte(longi_value[i]);
									i++;
									if (i==3)
									{
										UART2_sendByte('*');
									}
								}
								UART2_sendByte('`');
								UART2_sendByte(longi_dir);
								UART2_sendString("\n");	
}
void get_google_maps_url(double latitude, double longitude, char *url_buffer) 
{
	// Format the URL string with the latitude and longitude data
	sprintf(url_buffer, "https://www.google.com/maps/search/?api=1&query=%lf,%lf", latitude, longitude);
}





