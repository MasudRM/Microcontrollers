//Creating_Header_file_class12
//C_file

#include"Creating_HEADER_file.h"

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>


void Init_INT_0 (void);

void main(void)
{	
	DDRC |=0xff;
	Init_INT_0 ();


	while (1)
	{
	
	}

}



//
//
//
//


void Init_INT_0 (void)
{
	sei(); //SREG |= (1<<0);
	MCUCR &=~ ((1<<ISC00) |(1<<ISC01));
	GICR |= (1<<INT0);
	
}

ISR(INT0_vect)
{
	PORTC |=0xff;
	_delay_ms(100);
	PORTC &=~0xff;
	_delay_ms(100);

}


