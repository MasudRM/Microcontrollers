/*
TIMER SELECTION:
#1: Presceller Selection(CS00,CS01,CS02),
#2: Enable Global Interrupt function. sei(),
#3: Enable Timer overflow Function(TIMSK),
#4: Clear Timer Counter Register Value.(TCNT0),
#5: Writing an ISR function.
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//void timer0_init (void);
//void start_timer0(void);

unsigned int count =0; 

void main(void)
{

DDRC = 0xFF;	//declairing all pin of port C as input pin



TCCR0 &=~ (1<<CS00);	//clkI/0/256(from prescaler)
TCCR0 &=~ (1<<CS01);	//clkI/0/256(from prescaler)
TCCR0 |=  (1<<CS02);	//clkI/0/256(from prescaler)

sei();		//enable global interrupt function

TIMSK |= (1<<TOIE0);	//enable timer overflow interrupt function.(TIMSK)

TCNT0 =0;		//Clear Timer Counter Register Value.(TCNT0)
	while(1)
	{
	
	}
	
}


ISR(TIMER0_OVF_vect) 	//writing an ISR funcction
{
	count++;
	
	if(count == 122)
	{
		PORTC =~ PORTC;
		
		count=0;
	}

}

