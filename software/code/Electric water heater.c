#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "MACROS.h" 
#include "ADC.c"
volatile uint16 volt =0;
f32 x =0;
f32 y =0;
uint16 counter_1 =0;
uint16 counter_2 =0;

	 /*the main process*/
 void  ELECTRIC_WATER_HEATER(void)
	{
		DDRC=0xFF;
		DDRD=0xFF;
		PORTD=0x60;
		PORTC=0x00;
		//super loop for repeating this code infinitely
		while(1)  
		{
		volt = ADC_readChannel(0); // read channel two where the temp sensor is connect
			x=(float)(5*volt)/1023; // to gain the ADC of temperature reading
			x=x*10;   // out of Temp equation
			y=x*10;
			PORTD=x;
			PORTC=y;
		}
		
	}

