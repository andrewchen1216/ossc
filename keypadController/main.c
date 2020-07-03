/*
 * KeypadDecoder.c
 * Created: 02.07.2020 10:36:52
 * Author : memecian
 */ 

#include <avr/io.h>
#include <stdbool.h>
#include <util/twi.h>
#include "twislave.h"

int fuckit(int x, int y)
{
    // send button coordinates to master chip via i2c
}


int main(void)
{    

    bool row[9];
    bool col[5] = {PORTA0, PORTA1, PORTA2, PORTA3, PORTA4}; //columns left to right
    
    DDRA = 0b00011111;    //0 stands for input, 1 stands for output
    DDRB = 0b00001111;
    DDRC = 0b00100100;    
    
    while (1) 
    {
        row[0] = PORTA7; //rows top to bottom 
        row[1] = PORTA6;
        row[2] = PORTA5;
        row[3] = PORTC5;
        row[4] = PORTC2;
        row[5] = PORTB3;
        row[6] = PORTB2;
        row[7] = PORTB1;
        row[8] = PORTB0;
        
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