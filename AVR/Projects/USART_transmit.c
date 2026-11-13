#include <avr/io.h> //AVR inpu-output header file 
#include <util/delay.h> //AVR header file for delay function 
#include "USART.h" //Header file USART communication 
 
void main(void)
{
	USART_Init(); //Initializing USART Communication 
	
	 
	
	
	while(1)
	{
		USART_Transmit_String("AutoCust\r\n"); 
		USART_Transmit_String("mr_51\r\n");
		_delay_ms(500);
		
	}
}
