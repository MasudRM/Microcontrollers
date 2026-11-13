//EEPROM

#include <avr/io.h> //AVR inpu-output header file 
#include <util/delay.h> //AVR header file for delay function 
#include "USART.h" //Header file USART communication 
#include <avr/eeprom.h>	//avr header file for eeprom programming


char line [100];

int eeprom_data=0;

void main (void)
{
	DDRC = 0xFF;
	
	USART_Init();
	
	
	//eeprom needed to be write only once
	/*
	eeprom_write_byte((uint8_t*)65, 100);
	USART_Transmit_String("Data write sucess!!");
	_delay_ms(500);
	*/
	
	eeprom_data = eeprom_read_byte((uint8_t*)85);
	
	sprintf(line, "The data is : %d", eeprom_data);
	USART_Transmit_String(line);
	USART_Transmit_String("\r\n");
	_delay_ms(500);
	
	
	while(1)
	{
	
	
	}

}
