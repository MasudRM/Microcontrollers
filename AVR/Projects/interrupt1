#include <Assignment.h> //named as enable_interrupt

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void Init_INT_1 (void);

void main(void)
{
	DDRC |= ((1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7));
	//PORTC |= ((1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7)); 

	Init_INT_1();

	while(1)
	{
		int i;
		for(i=0;i<=7;i++)
		{
			PORTC |= (1<<i);
			_delay_ms(20);
			PORTC &=~(1<<i);
			_delay_ms(20);
		}
	}

}

void Init_INT_1(void)
{
	sei();
	MCUCR &=~ ((1<<ISC10) | (1<<ISC11)); //The low level of INT1 generates an interrupt request
	GICR |= (1<<INT1);
}

ISR(INT1_vect)
{
	while(1)
	{
		int i;
		for(i=7;i>=0;i--)
		{
			PORTC ^= (1<<i);
			_delay_ms(30);
			PORTC &=~(1<<i);
			_delay_ms(30);
		}
		
		
	}	
}
