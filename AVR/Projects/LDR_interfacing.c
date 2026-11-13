//LDR Controlled AC Lamp/Load//

#include<avr/io.h>
#include<util/delay.h>
#include "adc_header.h"

void ADC_Init(void);
uint16_t ADC_Read_Data(void);

	int LDR();
	void LDR_value();
	

int main(void)
{
	DDRA |=(1<<0);
	DDRC |=(1<<0);
	
	ADC_Init();
	//uint16_t ADC_Value=0;
	
	LDR_value=0;
	
	
	
	
	while(1)
	{
		if(LDR_value>=2)
		PORTC^=(1<<0);
		
		
		LDR_value=0;
	}
}
