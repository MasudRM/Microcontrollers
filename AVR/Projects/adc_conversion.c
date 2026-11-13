/*
			ADC
	RULES:
#1; Reffereence Voltage Selection
#2; Prescaller Selection
#3; Enable ADC
#4; Channel Selection
#5; Start Conversion
#6; Read Data

ADMUX|=(1<<REFS0);		//AVCC with external capacitor at AREF pin
ADMUX&=~(1<<REFS1);	//AVCC with external capacitor at AREF pin

ADCRA&=~(1<<ADPS0);	//Division factor=64; 8000000/64=125000=125KHz ADC Frequency
ADCRA|=(1<<ADPS1);		//Division factor=64; 8000000/64=125000=125KHz ADC Frequency
ADCRA|=(1<<ADPS2);		//Division factor=64; 8000000/64=125000=125KHz ADC Frequency

ADCSRA |= (1<<ADEN);	//ADC Enable.

ADMUX &=~(1<<MUX0);	//ADCC0 Channel Selection.
ADMUX &=~(1<<MUX1);	//ADCC0 Channel Selection.
ADMUX &=~(1<<MUX2);	//ADCC0 Channel Selection.
ADMUX &=~(1<<MUX3);	//ADCC0 Channel Selection.
ADMUX &=~(1<<MUX4);	//ADCC0 Channel Selection.

ADCSRA |=(1<<ADSC);	//Start cconversion

ADMUX &=~(1<<ADLAR);	//ADLAR to right adjust the result.


while(ADCSRA & (1<<ADSC));		//ADC is ccompleted or not?

return ADCCW;

*/


#include<stdio.h>
#include<avr/io.h>
#include<util/delay.h>

#include"lcd.h"
#include"adc_header.h"


void ADC_Init(void);
uint16_t ADC_Read_Data(void);

int main(void)
{
	char line[16];
	
	uint16_t ADC_Value = 0;
	float ADC_Volt = 0.0;
	
	LCDInit(); //Initializing LCD display.
	ADC_Init();	//Initializing ADC.
	
		while(1)
		{
			ADC_Value = ADC_Read_Data();
			ADC_Volt = ((ADC_Value * 5.0) /1023);	//Convert ADC Value to voltage.
			
			sprintf(line, "ADC Value: %0.4f", ADC_Volt);	
			LCDGotoXY(1,1);
			LCDString(line);
			
			sprintf(line,"..AutoCust");
			LCDGotoXY(6,2);
			LCDString(line);
		}
}





/*
void ADC_Init(void)
{
	ADMUX|=(1<<REFS0);		//AVCC with external capacitor at AREF pin
	ADMUX&=~(1<<REFS1);	//AVCC with external capacitor at AREF pin

	ADCSRA&=~(1<<ADPS0);	//Division factor=64; 8000000/64=125000=125KHz ADC Frequency
	ADCSRA|=(1<<ADPS1);		//Division factor=64; 8000000/64=125000=125KHz ADC Frequency
	ADCSRA|=(1<<ADPS2);		//Division factor=64; 8000000/64=125000=125KHz ADC Frequency

	ADCSRA |= (1<<ADEN);	//ADC Enable.
	
}


uint16_t ADC_Read_Data(void)
{
	
	ADMUX &=~(1<<MUX0);	//ADCC0 Channel Selection.
	ADMUX &=~(1<<MUX1);	//ADCC0 Channel Selection.
	ADMUX &=~(1<<MUX2);	//ADCC0 Channel Selection.
	ADMUX &=~(1<<MUX3);	//ADCC0 Channel Selection.
	ADMUX &=~(1<<MUX4);	//ADCC0 Channel Selection.

	ADCSRA |=(1<<ADSC);	//Start cconversion

	ADMUX &=~(1<<ADLAR);	//ADLAR to right adjust the result.


	while(ADCSRA & (1<<ADSC));		//ADC is completed or not?

	return ADCW;

}*/


