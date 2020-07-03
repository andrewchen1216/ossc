/*
 * KeypadDecoder.c
 * Created: 02.07.2020 10:36:52
 * Author : memecian
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <util/twi.h>

int sendbtn(int x, int y)
{
    // send button coordinates to master chip via i2c
	
	// if x and y == 0x0f, send nothing
}



int main(void)
{    
	TWSA	= 0x24;
	TWSCRA	= 0xFF;
	
    bool row[9];
    
    DDRA	= 0b00011111;    //0 stands for input, 1 stands for output
    DDRB	= 0b00001111;
    DDRC	= 0b00100100;    
    
    while (1) 
    {
        row[0] = PORTA7; //rows top to bottom 
        row[1] = PORTA6; //
        row[2] = PORTA5;
        row[3] = PORTC5;
        row[4] = PORTC2;
        row[5] = PORTB3;
        row[6] = PORTB2;
        row[7] = PORTB1;
        row[8] = PORTB0;
        
        for (int i = 0; i < 5; i++)
        {
            PORTA|=(1<<i);
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
            PORTA&=~(1<<i);
        }
    }
}