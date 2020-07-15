/*
 * kp_controller_new.cpp
 *
 * Created: 15.07.2020 12:25:07
 * Author : Administrator
 */ 
#ifndef F_CPU
#define F_CPU 8000000
#endif

#define bit_get(p,m) ((p) & (m))
#define bit_set(p,m) ((p) |= (m))
#define bit_clear(p,m) ((p) &= ~(m))
#define bit_flip(p,m) ((p) ^= (m))
#define bit_write(c,p,m) (c ? bit_set(p,m) : bit_clear(p,m))
#define BIT(x) (0x01 << (x))
#define LONGBIT(x) ((unsigned long)0x00000001 << (x))

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
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
	DDRC	= 0x01;			// Enable PC0 as output, everything else as input
	
	PORTC.bit0 = 1;
	
	while (1)
	{
		
		
		for (int i = 0; i < 6; i++)
		{
			PORTB|=(1<<i);
			
			for (int j = 0; j < 8)
			{
			
			}
			/*row[0] = PINB6; // Update row data
			row[1] = PINB7;
			row[2] = PIND0;
			row[3] = PIND1;
			row[4] = PIND2;
			row[5] = PIND3;
			row[6] = PIND4;
			row[7] = PIND5;
			*/
			sendbtn(row);
			
			PORTB&=~(1<<i);
		}
	}
}