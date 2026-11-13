//toogle_switch_class10//

#include <avr/io.h> //AVR input-output header file 
#include <util/delay.h> //AVR header file for delay funcion 

void main(void)
{

DDRC |= ((1<<0) | (1<<1) | (1<<2) | (1<<3) | (1<<4) | (1<<5) | (1<<6) | (1<<7));//Declare all Data_Direction_Registor_Of_PORTC as output pin. 

DDRD &= ~((1<<2) | (1<<3));//Declare Data_Direction_Register_Of_PORTD_Bit_2_&_3 as input pin. 


	while(1)
	{
		if(bit_is_clear(PIND, 2))
		{
			while(bit_is_clear(PIND, 2));
			PORTC ^= (1<<0);
		}
		
		else if(bit_is_clear(PIND, 3))
		{
			while(bit_is_clear(PIND, 3));
			PORTC ^= (1<<7);
		}
		
	}
}
