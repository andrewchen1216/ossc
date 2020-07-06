/*
 * KeypadDecoder.c
 * Created: 02.07.2020 10:36:52
 * Author : memecian
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <util/twi.h>
#include <util/delay.h>

int sendbtn(int x, int y)
{
    // send button coordinates to master chip via i2c
	
	// if x and y == 0x0f, send nothing
}



int main(void)
{    

	
    bool row[9];
	
	TWAR	= 0x24;
	
    DDRB	= 0x0F; // Enable PORTB0...4 (columns) as output.
    DDRD	= 0x00;	// Better safe than sorry.
	DDRC	= 0x00; // Ditto.   
    
    while (1) 
    {
        row[0] = PINB5; // Update row data
        row[1] = PINB6; 
        row[2] = PINB7;
        row[3] = PIND0;
        row[4] = PIND1;
        row[5] = PIND2;
        row[6] = PIND3;
        row[7] = PIND4;
        row[8] = PIND5;
        
        for (int i = 0; i < 5; i++)
        {
            PORTB|=(1<<i);
            for (int j = 0; j < 9; j++)
            {
                if (row[j] == 0)
                {
                    sendbtn(i,j);
                }
				else
				{
					sendbtn(0x0f, 0x0f);
				}
            }
            PORTB&=~(1<<i);
        }
    }
}