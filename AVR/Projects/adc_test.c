//ADC_test


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
			
			sprintf(line,"AutoCust.com");
			LCDGotoXY(5,2);
			LCDString(line);
		}
}
