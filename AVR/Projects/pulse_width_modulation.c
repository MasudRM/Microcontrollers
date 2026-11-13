//main file for PWM

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "lcd.h"
#include "adc_header.h"
#include "PWM.h"


void main()
{
DDRA = 0xFF;
DDRB |= (1<<3);

char line[16];
int value=0;


LCDInit();
ADC_Init();

PWM0_init();

	
	while(1)
	{
		for(int i=0; i<10; i++)
		{
			value = value+10;
			Start_PWM0(value);
			_delay_ms(500);
			
			sprintf(line, "LED_Bright: %d", value);
			LCDGotoXY(1,1);
			LCDString(line);
			
			sprintf(line, "''", value);
			LCDGotoXY(7,2);
			LCDString(line);
		}
	
		value = 0;
	}


}
