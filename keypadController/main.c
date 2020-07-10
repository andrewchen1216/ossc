/*
 * KeypadDecoder.c
 * Created: 02.07.2020 10:36:52
 * Author : memecian
 */ 

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <stdint.h>
#include <avr/io.h>
#include <stdbool.h>
#include <util/twi.h>
#include <util/delay.h>

int sendbtn(bool colData[8])
{	
	int8_t toMaster = 0x00;
	for (int i = 0; i < 8; i++)
	{
		if (colData[i])
		{
			toMaster |= (1 << i);
		}
	}
}



int main(void)
{    

	
    bool row[8];
	
	TWAR	= 0x24;
	
    DDRB	= 0b00011111;	// Enable PORTB0...5 (columns) as output.
    DDRD	= 0x00;			// Better safe than sorry.
	DDRC	= 0x00;			// Ditto.   
    
    while (1) 
    {
		
		        
        for (int i = 0; i < 5; i++)
        {
            PORTB|=(1<<i);
			
			row[0] = PINB6; // Update row data
			row[1] = PINB7;
			row[2] = PIND0;
			row[3] = PIND1;
			row[4] = PIND2;
			row[5] = PIND3;
			row[6] = PIND4;
			row[7] = PIND5;
            
			sendbtn(row);
			
			PORTB&=~(1<<i);
        }
    }
}