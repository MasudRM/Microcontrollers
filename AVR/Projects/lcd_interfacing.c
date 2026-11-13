//CLASS_15_LCD_INTERFACING

#include<avr/io.h>
#include<util/delay.h>
#include<interrupt.h>
#include<stdio.h>
#include"lcd.h"


void Init_INT_0 (void);

void main(void)

{
	char line[16];
	
	LCDInit();
	Init_INT_0 ();
	
	while(1)
	{
		sprintf(line, "BANGLADESH");
		LCDGotoXY(4,1);
		LCDString(line);
	}



}


void Init_INT_0 (void)
{
	//sei(); 
	SREG |= (1<<7);
	MCUCR &=~ ((1<<ISC00) |(1<<ISC01));
	GICR |= (1<<INT0);
	
}

ISR(INT0_vect)
{
	char line[16];
	
	
	
	while(1)
	{
		sprintf(line, "TECHSHOP");
		LCDGotoXY(1,1);
		LCDString(line);
		
	}

}
