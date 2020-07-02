/*
 * KeypadDecoder.c
 * Created: 02.07.2020 10:36:52
 * Author : memecian
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <util/twi.h>
int fuckit(int x, int y)
{
	// do some code that sends button code per i²c
}


int main(void)
{	

	bool row[9];
	bool col[5] = {PORTA0, PORTA1, PORTA2, PORTA3, PORTA4}; //columns left to right
	TWSAM = 0x24;		//set I²C address mask
	
	DDRA = 0b00011111;	//0 stands for input, 1 stands for output
	DDRB = 0b00001111;
	DDRC = 0b00100100;	
	
    while (1) 
    {
		row[] = {PORTA7, PORTA6, PORTA5, PORTC5, PORTC2, PORTB3, PORTB2, PORTB1, PORTB0}; //rows top to bottom 
		for (int i = 0; i < 5; i++)
		{
			col[i] = 1;
			for (int j = 0; j < 9; j++)
			{
				if (row[j] == 0)
				{
					fuckit(i,j);
				}
			}
			col[i] = 0;
		}
	}
}

