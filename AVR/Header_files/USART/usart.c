
#define F_CPU 16000000UL 
#include "USART.h" 
#include <avr/io.h> 

#define BAUDRATE 9600 //Set baud rate  
#define BAUD_PRESCALER ((F_CPU/16/BAUDRATE) - 1) 


void USART_Init(void)
{
	UCSRA &= ~(1<<U2X); //Asynchronous Normal mode (U2X = 0) 
	
	UCSRB |= ((1<<TXEN) | (1<<RXEN)); //Enable RX and TX of USART 
	
	UBRRL = BAUD_PRESCALER; 
	UBRRH = (BAUD_PRESCALER >> 8);
	
	
	UCSRC |= ((1<<UCSZ0) | (1<<UCSZ1) | (1<<URSEL)); //8-bit Character Size 
	UCSRB &= ~(1<<UCSZ2); //8-bit Character Size  
}

void USART_Transmit(char data)
{
	while(!(UCSRA & (1<<UDRE)));//Wait for empty transmit buffer 
	UDR = data; //Put data into buffer, sends the data 
}

char USART_Receive(void)
{
	while(!(UCSRA & (1<<RXC))); //Wait for data to be received 
	return UDR; //Get and return received data from buffer 
}




void USART_Transmit_String(char *String)	/*this code is for transmiting string via the avr,
											coz the avr cant transmit more then 1 character at once*/

{
	while(*String)
	{
		USART_Transmit(*String++);
	}
}
