//C_file_for_Header
//Interrupt"0"

void Init_INT_0 (void)
{
	sei(); //SREG |= (1<<0);
	MCUCR &=~ ((1<<ISC00) |(1<<ISC01));
	GICR |= (1<<INT0);
	
}

ISR(INT0_vect)
{
	PORTB |=(1<<0);
	_delay_ms(100);
	PORTB &=~(1<<0);
	_delay_ms(100);

}
