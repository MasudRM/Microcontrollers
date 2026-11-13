//BLINKING_LED_PROJECT_ON_BREADBOARD//

#include<avr/io.h>
#include<util/delay.h>

void main(void)
{
	DDRC |= (1<<0);
	
	while(1)
	{
		PORTC |= (1<<0);
		_delay_ms(500);
		PORTC &=~(1<<0);
		_delay_ms(500);
	}






}
