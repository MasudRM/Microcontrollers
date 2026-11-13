//Transmitting of LM35 data to EEPROM using USART

#include <avr/io.h>		//avr input output header file
#include <stdio.h>		//for sprintf function
#include <util/delay.h>	//header fle for delay function
#include <avr/eeprom.h>	//avr EEPROM header file
#include "USART.h"		//custom header file for USART communication
#include "adc.h"		//custom header file for ADC(Analog to Digital Conversion)


char line [100];

unsigned char eeprom_data = 0;

uint16_t adc_value =0;
float adc_voltage = 0.00;
uint16_t temp = 0;

unsigned char EEPROM_ADDRESS = 0;
unsigned char EEPROM_VALUE = 0;

void main(void)
{
	DDRC = 0xFF;
	DDRD &=~((1<<PD2) | (1<<PD3)); //for input switch
	
	USART_Init(); //USART initialization
	ADC_Init(); 	//ADC initialization
	
	while(1)
	{
		adc_value = ADC_Read_Data(0); //using adc channel_0(ADC0)
		adc_voltage = ((adc_value*5.00)/1023.00); //convert adc_value to voltage
		temp = ((adc_voltage * 1000)/10); //convert voltage to milivolt and temp
		
		
		sprintf(line, "Temperature is: %d", temp);
		USART_Transmit_String(line);
		USART_Transmit_String("\n\r");
		_delay_ms(100);
		
		
			if(bit_is_clear(PIND,2))
			{
				while(bit_is_clear(PIND,2));
				
				eeprom_write_byte((uint8_t*)EEPROM_ADDRESS, temp);
				EEPROM_ADDRESS++;
				
				if(EEPROM_ADDRESS > 255) EEPROM_ADDRESS = 0;
				_delay_ms(100);
				
			}
			
			else if(bit_is_clear(PIND,3))
			{
				while(bit_is_clear(PIND,3))
				{
					eeprom_data = eeprom_read_byte((uint8_t*) EEPROM_ADDRESS);
					
					EEPROM_ADDRESS++;
					
					if(EEPROM_ADDRESS > 255) EEPROM_ADDRESS =0;
					
					sprintf(line, "The data is: %d", eeprom_data);
					USART_Transmit_String(line);
					USART_Transmit_String("\r\n");
					
					_delay_ms(50);
				
				}
			
			}
		
	}


}
