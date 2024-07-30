#ifndef UART_H_
#define UART_H_
/********************* Includes & Definitions **************************/
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
#define USART_BAUDRATE 9600

/************************* Functions Prototypes ************************/
void UART0_init(void);
void UART0_sendByte(const unsigned char data);
unsigned char UART0_recieveByte(void);
void UART0_sendString(char *Str);
void UART0_receiveString(unsigned char *Str);

void UART1_init(void);
void UART1_sendByte(const unsigned char data);
unsigned char UART1_recieveByte(void);
void UART1_sendString(const unsigned char *Str);
void UART1_receiveString(unsigned char *Str);

void UART2_init(void);
void UART2_sendByte(const unsigned char data);
unsigned char UART2_recieveByte(void);
void UART2_sendString(const unsigned char *Str);
void UART2_receiveString(unsigned char *Str);

void UART3_init(void);
void UART3_sendByte(const unsigned char data);
unsigned char UART3_recieveByte(void);
void UART3_sendString(const unsigned char *Str);
void UART3_receiveString(unsigned char *Str);

#endif
