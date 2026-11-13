//assignment_class12_C_file
//enable_interrupt_1


void Init_INT_1(void)
{
	sei();
	MCUCR &=~ ((1<<ISC10) | (1<<ISC11)); //The low level of INT1 generates an interrupt request
	GICR |= (1<<INT1);
}

ISR(INT1_vect)
{
		int i;
		for(i=7;i>=0;i--)
		{
			PORTC |= (1<<i);
			_delay_ms(500);
			PORTC &=~(1<<i);
			_delay_ms(500);
		}
