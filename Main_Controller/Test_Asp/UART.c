#include "UART.h"


void UART0_init(void)
{
    // U2X = 0 For double transmission speed	
	UCSR0A |= (1<<U2X0);  
	// RXCIE = 1 Enable USART RX Complete Interrupt Enable
	// RXEN  = 1 Receiver Enable
	// RXEN  = 1 Transmitter Enable
	UCSR0B = (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0);
	// URSEL   = 1 The URSEL must be one when writing the UCSRC
    // UCSZ1:0 = 11 For 8-bit data mode
	UCSR0C = (1<<UCSZ00) | (1<<UCSZ01);

	// Baud rate
	UBRR0L =51;  	
}
void UART1_init(void)
{
	UCSR1A |= (1<<U2X1);
	UCSR1B = (1<<RXEN1) | (1<<TXEN1);
	UCSR1C = (1<<UCSZ10) | (1<<UCSZ11);
	UBRR1L =103;
}
void UART2_init(void)
{
	UCSR2A |= (1<<U2X2);
	UCSR2B = (1<<RXEN2) | (1<<TXEN2)| (1<<RXCIE2);
	UCSR2C = (1<<UCSZ20) | (1<<UCSZ21);
	UBRR2L =103;
}
void UART3_init(void)
{
	UCSR3A |= (1<<U2X3);
	UCSR3B = (1<<RXEN3) | (1<<TXEN3) | (1<<RXCIE3);
	UCSR3C = (1<<UCSZ30) | (1<<UCSZ31);
	UBRR3L =103;
}

/***************************UART0******************************/
void UART0_sendByte(const unsigned char data)
{
	while(BIT_IS_CLEAR(UCSR0A,UDRE0))
	{
		;
	}
	UDR0 = data;
}
unsigned char UART0_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSR0A,7))
	{
		;
	}
    return UDR0;
}
void UART0_sendString(char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		UART0_sendByte(Str[i]);
		i++;
	}
}

void UART0_receiveString(unsigned char *Str)
{
	unsigned char i = 0;
	Str[i] = UART0_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART0_recieveByte();
	}
	Str[i] = '\0';
}
/***************************UART1******************************/
void UART1_sendByte(const unsigned char data)
{
	while(BIT_IS_CLEAR(UCSR1A,UDRE1))
	{
		;
	}
	UDR1 = data;
}

unsigned char UART1_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSR1A,7))
	{
		;
	}
	return UDR1;
}

void UART1_sendString(const unsigned char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		UART1_sendByte(Str[i]);
		i++;
	}

}
void UART1_receiveString(unsigned char *Str)
{
	unsigned char i = 0;
	Str[i] = UART1_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART1_recieveByte();
	}
	Str[i] = '\0';
}

/***************************UART2******************************/
void UART2_sendByte(const unsigned char data)
{
	while(BIT_IS_CLEAR(UCSR2A,UDRE2))
	{
		;
	}
	UDR2 = data;
}

unsigned char UART2_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSR2A,7))
	{
		;
	}
	return UDR2;
}

void UART2_sendString(const unsigned char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		UART2_sendByte(Str[i]);
		i++;
	}

}
void UART2_receiveString(unsigned char *Str)
{
	unsigned char i = 0;
	Str[i] = UART2_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART2_recieveByte();
	}
	Str[i] = '\0';
}


/***************************UART3******************************/
void UART3_sendByte(const unsigned char data)
{
	while(BIT_IS_CLEAR(UCSR3A,UDRE3))
	{
		;
	}
	UDR3 = data;
}

unsigned char UART3_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSR3A,7))
	{
		;
	}
	return UDR3;
}

void UART3_sendString(const unsigned char *Str)
{
	unsigned char i = 0;
	while(Str[i] != '\0')
	{
		UART3_sendByte(Str[i]);
		i++;
	}

}
void UART3_receiveString(unsigned char *Str)
{
	unsigned char i = 0;
	Str[i] = UART3_recieveByte();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART3_recieveByte();
	}
	Str[i] = '\0';
}