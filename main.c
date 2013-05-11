#include <stdio.h>
#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>
#include <hc595.h>

//Define functions
//======================
void ioinit(void);      // initializes IO
static int uart_putchar(char c, FILE *stream);
uint8_t uart_getchar(void);
static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
uint8_t uart_rxready(void);

int main(void)
{
	//uint16_t j, jj;
	/******************************************/
	#define FOSC 16000000
	#define BAUD 9600
	#define MYUBRR (FOSC/16/BAUD-1)


	//======================
	//USART Baud rate: 9600
	UBRR0H = MYUBRR >> 8;
	UBRR0L = MYUBRR;
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	stdout = &mystdout; //Required for printf init
	printf("\nboot\n");
	
	hc595_init();
	/*
	hc595_serwr(0);
	hc595_oelwr(0);
	hc595_rclkwr(0);
	hc595_srclklwr(0);
	hc595_srclrwr(0);
	*/

	while(1)
	{
		hc595_wr(0x01);
		hc595_wr(0x01);
		hc595_store();
		hc595_enable();
		hc595_clear();
		hc595_wr(0x01);
		hc595_wr(0x02);
		hc595_store();
		hc595_enable();
	}
	
	return 0;
}

static int uart_putchar(char c, FILE *stream)
{
    if (c == '\n') uart_putchar('\r', stream);
  
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    
    return 0;
}

uint8_t uart_rxready(void)
{
	return (UCSR0A & (1<<RXC0));
}

uint8_t uart_getchar(void)
{
    while( !(UCSR0A & (1<<RXC0)) );
    return(UDR0);
};