													//PWM(Pulse Width Modulation)
//C_file for PWM Header File


#include <avr/io.h>

unsigned char count =0;

void PWM0_init(void)
{
	TCCR0 &=~ ((1<<CS00) | (1<<CS01));	//clkI/O/256 (From prescaler)
	TCCR0 |=  (1<<CS02);					//clkI/O/256 (From prescaler)
	
	TCCR0 |=(1<<WGM00);		//Fast PWM
	TCCR0 |=(1<<WGM01);		//Fast PWM
	
	TCCR0 &=~ (1<<COM00);		//Clear OC0 on Compare Match when up-counting. 
	TCCR0 |=  (1<<COM01);		//Clear OC0 on Compare Match when up-counting. 
	
}


void Start_PWM0(char unsigned Duty_Cycle)
{
	if(Duty_Cycle > 100) Duty_Cycle =100;
	
	OCR0 = ((255*Duty_Cycle)/100);
}
