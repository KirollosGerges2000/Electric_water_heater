#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "MACROS.h" 
#include "ADC.c"
#include "DIO.h"
volatile uint16 volt =0;
f32 x =0;
int16 counter = 0;


	 /*the main process*/
 void  ELECTRIC_WATER_HEATER(void)
	{
		DDRD=0xFF;
		OUTPUT_MODULE(DDRB,0); //set Enable of first 7 segment as output
		OUTPUT_MODULE(DDRA,7); //set Enable of second 7 segment as output  
		OUTPUT_MODULE(DDRB,5); //set cooling fan as output 
		OUTPUT_MODULE(DDRB,6); //set Heater as output 
		 INPUT_MODULE(DDRB,3); //set increment temperature button to be input
		 INPUT_MODULE(DDRB,2); //set decrement temperature button to be input
		 INPUT_MODULE(DDRB,1); //set OFF/ON button to be input
		/* deceleration, initialize 7_segments by 60*/
     PORTD=0x60;  
		/* initialization cooling fan,heater to be off */	
	OUTPUT_MODULE_OFF(PORTB,5);
    OUTPUT_MODULE_OFF(PORTB,6);
		/* initialization Enables of 7 segments to be on as active low */
		OUTPUT_MODULE_ON(PORTB,0);
		OUTPUT_MODULE_ON(PORTA,7);
		//super loop for repeating this code infinitely
		while(1)  
		{
			
				if(INPUT_BIT(PINB,1) )
				{ 
					 TOGGLe_BIT(PORTB,6);
					TOGGLe_BIT(PORTB,0);
					TOGGLE_BIT(PORTA,7);
				while(INPUT_BIT(PINB,1));
			
				}		
		else if(INPUT_BIT(PINB,1) )
		{
			 TOGGLe_BIT(PORTB,6);
			 TOGGLe_BIT(PORTB,0);
			 TOGGLE_BIT(PORTA,7);
			while(INPUT_BIT(PINB,1));
		}


	}

		
	}
	
	
	
void TEMPERature_sensor(void)
{
	volt = ADC_readChannel(0); // read channel two where the temp sensor is connect
			x=(float)(5*volt)/1023; // to gain the ADC of temperature reading
			x=x*10;   // out of Temp equation
}




void seven_segments_on(void)
{
	  
	
		while (INPUT_BIT(PINB,3)  || INPUT_BIT(PINB,2) )
	{
		
		if(PINB&(1<<3))
		{
			counter++;
		}
		else if(PINB&(1<<2))
		{
			counter--;
		}

		switch(counter)
		{
			case 1:
			PORTD=0x65;
			break;
			case -1:
			PORTD=0x55;
			break;
			case 2:
			PORTD=0x70;
			break;
			case -2:
			PORTD=0x50;
			break;
			case 3:
			PORTD=0x75;
			break;
			case -3:
			PORTD=0x45;
			break;
			case 0:
			PORTD=0x60;
			break;
			case -4:
			PORTD=0x40;
			break;
			case -5:
			PORTD=0x35;
			break;
		}
		while(PINB&(1<<2) || PINB&(1<<3));
	} 
	  
	
}


