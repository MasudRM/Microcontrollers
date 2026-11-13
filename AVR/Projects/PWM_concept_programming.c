/*
 * PWMConceptandProgramming.c
 *
 * Created: 23-Mar-18 09:11:56 AM
 * Author : FAHIM REAZA
 */ 

#define F_CPU 16000000UL 	//Using 16MHz External Clock 
#include <avr/io.h> 		//AVR Input-Output Header File 
#include <util/delay.h> 	//Header file for AVR Delay Function 
#include <avr/interrupt.h>  //AVR Interrupt Header File 

void Init_PWM (void); 

void main(void)
{
	DDRD |= ((1<<PD4) | (1<<PD5)); //PORTD_bit_4 PORTD_bit_5 as PWM_Output for OC1B and OC1A 
	
	Init_PWM (); //Initializing PWM 

	while(1) //Infinite loop 
	{
		OCR1A=250;   //1ms = (1 x 10^3)us = 1000us / 4 = 250;     
		OCR1B=250;
		_delay_ms(500); 
		
		OCR1A=375;   //1.5ms = (1.5 x 10^3)us = 1500us / 4 = 375  
		OCR1B=375;
		_delay_ms(500);
		
		OCR1A=500;   //2ms = (2 x 10^3)us = 2000us / 4 = 500
		OCR1B=500;
		_delay_ms(500);
	}
}


void Init_PWM (void)
{
	/*
	* 01. Configure "Fast PWM (non-inverting mode)" = Table-45 = Page-108  
	* 02. Select Waveform Generation Mode "Fast PWM" = Table 47 = Page-109 
	* 03. Prescaler Selection = Table-45 = Page-110 
	* 04. Calculate the "Frequency" and Set "TOP value" for "ICR1". 
	
				             F_CPU
				F_pwm = --------------- 
				         N ( 1 + TOP ) 
						 
				          16 000 000 Hz
			 >> 50 Hz = ---------------  //For 50Hz PWM Frequency, F_CPU = 16MHz, Prescaler = 64.  
						 64 ( 1 + TOP )   
						 
			           16 000 000 Hz 
			 >> TOP = ---------------  -  1 
			             50 x 64  
						 
					= 4999 
						 
	   	     # Now after prescaler, when counter register count = 1, then 16000000/64 = 250000Hz pulse passed. So T = 1/250000Hz = 0.000004 = 0.000004 x 10^6 = 4us. 
	
	* 05. Calculate the width of the pulse in time sequence on "OCR1A" or "OCR1B". [if require pulse width of 2ms(2000uS), so value of OCR1A = 2000us/4us = 500] 
	* 06. Get your desired output from OC1A or OC1B pin of ATmega32. 
	*/
	
	TCCR1A &= ~(1<<COM1A0); //Non-Inverting Mode. 
	TCCR1A |= (1<<COM1A1); //Non-Inverting Mode. 
	
	TCCR1A &= ~(1<<COM1B0); //Non-Inverting Mode. 
	TCCR1A |= (1<<COM1B1); //Non-Inverting Mode. 
	
	TCCR1A &= ~(1<<WGM10); //Fast PWM 
	TCCR1A |= (1<<WGM11); //Fast PWM 
	TCCR1B |= (1<<WGM12); //Fast PWM 
	TCCR1B |= (1<<WGM13); //Fast PWM 
	
	TCCR1B |= (1<<CS10); //clkI/O/64 (From prescaler) 
	TCCR1B |= (1<<CS11); //clkI/O/64 (From prescaler) 
	TCCR1B &= ~(1<<CS12); //clkI/O/64 (From prescaler) 
	
	ICR1 = 4999; //For F_pwm=50Hz, Prescaler=64, F_CPU=16MHz; TOP = ICR1 = 4999. 
}
