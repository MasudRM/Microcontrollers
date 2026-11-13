//+Buzzer Project
#include<avr/io.h>
#include<util/delay.h>


void main(void)

{
	//first declair the Data Direction Register(DDRx) of Port C
	//declairing all bits of port c to be set(1) to Output.
	//DDRC |=((1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7));
	DDRB |= (1<<3);//using this port to turn on/off the buzzer on trainer board which is connected to PB3
	
	
	while(1)
	{
		//declaring Port C bit wisely(0-7) to be set High
		//PORTC |=((1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7));
		
		//declaring port C bits to be ser as low
		//PORTC &=~((1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7));
		
		
		
		PORTB |= (1<<3);//Buzzer on
		_delay_ms(500);
		
		PORTB &=~(1<<3);//Buzzer off
		_delay_ms(200);
		
	}

	
return 0;	
	
