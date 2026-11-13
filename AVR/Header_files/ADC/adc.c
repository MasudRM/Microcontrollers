//ADC_using_16MHz_external_CrystalOscilator

#include "adc.h"
#include<avr/io.h>

void ADC_Init(void)
{
	ADMUX |= (1<<REFS0);		//AVCC with external capacitor at AREF pin
	ADMUX &=~(1<<REFS1);		//AVCC with external capacitor at AREF pin

	ADCSRA |= (1<<ADPS0);		//Division factor=128; 16000000/128=125000=125KHz ADC Frequency
	ADCSRA |= (1<<ADPS1);		//Division factor=128; 16000000/128=125000=125KHz ADC Frequency
	ADCSRA |= (1<<ADPS2);		//Division factor=128; 16000000/128=125000=125KHz ADC Frequency

	ADCSRA |= (1<<ADEN);		//ADC Enable.
	
}


uint16_t ADC_Read_Data(char adc_channel)//instead of "void" use "char adc_channel"//
{
	//to change bit number that we want to read data from//
	adc_channel &= 0b00000111;
	ADMUX=((ADMUX & 0b11111000) | adc_channel);
	
	ADMUX &=~ (1<<MUX0);	//ADCC0 Channel Selection.
	ADMUX &=~ (1<<MUX1);	//ADCC0 Channel Selection.
	ADMUX &=~ (1<<MUX2);	//ADCC0 Channel Selection.
	ADMUX &=~ (1<<MUX3);	//ADCC0 Channel Selection.
	ADMUX &=~ (1<<MUX4);	//ADCC0 Channel Selection.

	ADCSRA |= (1<<ADSC);	//Start cconversion

	ADMUX &=~ (1<<ADLAR);	//ADLAR to right adjust the result.


	while(ADCSRA & (1<<ADSC));		//ADC is completed or not?

	return ADCW;

}
