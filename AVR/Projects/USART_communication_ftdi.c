//USART comunication with FTDI

#include <avr/io.h>
#include <stdio.h>
#include <util.h>
#include "USART.h"

void main(void)
{
	DDRC = 0xFF;
	
	USART_Init();
	
	while(1)
	{
		char NewData = USART_Receive ();
		
		USART_Transmit_String(NewData);
		USART_Transmit_String("\r\n");
		
		if(NewData > 0)
		{
			if(NewData == 'F')
			{
			PORTC |=(1<<0);
			}
		
			else if(NewData == 'B')
			{
			PORTC |=(1<<1);
			}
		
			//so on...
		
		}
		
		
		
	
	}
}
