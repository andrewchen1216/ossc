/*
 * KeypadDecoder.c
 *
 * Created: 02.07.2020 10:36:52
 * Author : memecian
 
 */ 

#include <avr/io.h>
#include <stdbool.h>


int main(void)
{	
	bool row[9];

	DDRA = 0b00011111; //0 stands for input, 1 stands for output
	DDRB = 0b00001111;
	DDRC = 0b00100100;	
	
    while (1) 
    {
		row[] = {PORTA7, PORTA6, PORTA5, PORTC5, PORTC2, PORTB3, PORTB2, PORTB1, PORTB0}; //rows top to bottom 
		PORTA0 = 1;
		for (int i = 0; i < 5; i++) 
		{
			if (row[0])
			{
				
			}
			if (row[1])
			{
				
			}
			if (row[2])
			{
				
			}
			if (row[3])
			{
				
			}
			if (row[4])
			{
				
			}
			if (row[5])
			{
				
			}
			if (row[6])
			{
				
			}
			if (row[7])
			{
				
			}
			if (row[8])
			{
				
			}

		}
    
	}
}

