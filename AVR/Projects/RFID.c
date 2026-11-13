
/*
 * RFID.c
 *
 * Created	: 22/4/2018 12:50:53 AM
 * Author	: MD.MASUD RANA
 */ 
//**************************************************************//
//Microcontroller			:ATmega32
//System Clock				:16MHz 
//Project					:RFID BASED AUTOMOBILE DOOR LOCK-UNLOCK SYSTEM;
//Software					:WinAVR,Hercules, AVRDUDES;
//LCD Data Interfacing		:8-Bit
//USART Baud Rate			:9600
//USART Data Bits			:8
//**************************************************************//





#include<avr/io.h>
#include<util/delay.h>
#include"USART.h"


int main(void)
{
	DDRB |=0xFF;		//all pins of port B declared as output pin
	DDRC |=0xFF;		//all pins of port C declared as output pin
	
	unsigned char RFID_data[50]; //variable declaration for RFID data
	unsigned char data = 0;
	unsigned char ID_1[] = {'8','1','0','0','2','5','D','8','5','9','2','5'};		//UNIQUE ID OF MY RFID TAG
	
	
	USART_Init(); //USART initialization
	
	
	
	while(1)
	{
		do
		{
			data=USART_Receive();
		}
		while (data != 2);		//This loop will be executed until <STX> that is 02 is found
	
		
		for(unsigned char i=0;i<=13;i++)
		{
			RFID_data[i] = USART_Receive();  //Receives data from RFID Reader through USART and stores it in the array
		}
	
		
		
		char x=1;
		for(int i=0; i<=11; i++)
		{
			x = x * (RFID_data[i]==ID_1[i]); //compares requested id of the tag to the pre defined tag ID_1
			_delay_ms(1);
		}
	
		_delay_ms(1);
		if (x==0)		//if the ccompared ID does not match_
		{
			PORTB = (1<<3); 	//bit 3 of port b set to high to on the buzzer
			_delay_ms(10);
			PORTC &=~0xFF;		//suspend previous ID
			_delay_ms(500);
			PORTB &=~(1<<3); 	//TURN OFF THE BUZZER AFTER 500ms
		}
		
	
		else 
		{
			PORTC |=0xFF; 			//all bits of port c set to high to turn on the led's 
			_delay_ms(10);
			PORTB &=~ (1<<3);		//suspend previous ID
			_delay_ms(1000);
			PORTC &=~0XFF; 			//TURN OFF THE LED's AFTER 1sec
			
			
		}
		_delay_ms(10);
		
		
	
	}
	
}
