#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "MACROS.h" 
#include "ADC.c"
#include "DIO.h"
volatile uint16 volt =0;
f32 x =0;
 uint16 counter = 0  ;


	 /*the main process*/
 void  ELECTRIC_WATER_HEATER(void)
	{
		DDRD=0xFF;  //set 7_segment as output
		 INPUT_MODULE(DDRB,3); //set increment temperature button to be input
		 INPUT_MODULE(DDRB,2); //set decrement temperature button to be input
		/* deceleration, initialize 7_segments by 60*/
		counter=0x60;
		PORTD=counter;
		
		
		
		//super loop for repeating this code infinitely
		while(1)  
		{
	/*	volt = ADC_readChannel(0); // read channel two where the temp sensor is connect
			x=(float)(5*volt)/1023; // to gain the ADC of temperature reading
			x=x*10;   // out of Temp equation*/
	
	if(PINB&(1<<3) )
	{
		counter++;
		PORTD=counter;
		while(PINB&(1<<3));
	
	}
	else if(PINB&(1<<2) )
	{
		counter--;
	PORTD=counter;
	while(PINB&(1<<2));
		
	}

	
		}
		
	}

