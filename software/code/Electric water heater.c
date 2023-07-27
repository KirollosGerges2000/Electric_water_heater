#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "MACROS.h" 
#include "ADC.c"
#include "DIO.h"
#include "interrupt.c"
#include "I2C.c"
volatile uint16 volt =0;
volatile f32 x = 0;
 static f32  average;
  f32 sum;
int16 counter = 0;
u8 i=0;

	 /*the main process*/
 void  ELECTRIC_WATER_HEATER(void)
	{	 	
		INT_interrupt();  /* initialize internally interrupt Timer0*/
		ADC_init(); /* initialize ADC driver */
		DDRD=0xFF;
		OUTPUT_MODULE(DDRB,0); //set Enable of first 7 segment as output
		OUTPUT_MODULE(DDRA,7); //set Enable of second 7 segment as output  
		OUTPUT_MODULE(DDRB,5); //set cooling fan as output 
		OUTPUT_MODULE(DDRB,6); //set Heater as output 
		OUTPUT_MODULE(DDRB,4); //set Heater LED as output
		 INPUT_MODULE(DDRB,3); //set increment temperature button to be input
		 INPUT_MODULE(DDRB,2); //set decrement temperature button to be input
		 INPUT_MODULE(DDRB,1); //set OFF/ON button to be input
		  /* deceleration, initialize 7_segments by 60*/
		PORTD=0x60;
		/* initialization cooling fan,heater ,heater LED to be off */	
		OUTPUT_MODULE_OFF(PORTB,4);
	OUTPUT_MODULE_OFF(PORTB,5);
    OUTPUT_MODULE_OFF(PORTB,6);
	// initialization Enables of 7 segments to be off as active low 
		OUTPUT_MODULE_ON(PORTB,0);
		OUTPUT_MODULE_ON(PORTA,7);
		

	
		//super loop for repeating this code infinitely
		while(1)  
		{
			
				if(INPUT_BIT(PINB,1))
				{ 
					 TOGGLe_BIT(PORTB,6);
					 TOGGLe_BIT(PORTB,0);
					 TOGGLe_BIT(PORTA,7);
					 TOGGLe_BIT(PORTB,4);
					while(INPUT_BIT(PINB,1));
					}
				
					seven_segments();
			ELEMENTS();
		
				
					
				}
			
				


	}

		
	
	void Temperature_reading(void)
	{
		volt = ADC_readChannel(0); // read channel two where the temp sensor is connect
			x=(float)(5*volt)/1023; // to gain the ADC of temperature reading
			x=x*100;   //the reading of temperature
			Avg_reading();  //the equations of average 10 temperature reading 
	}
	
	
void Avg_reading(void)
{
	  
sum=sum+x;
	i++;
	if(i==9)
	{
		 average=(sum)/10;
		i=0;
		sum=0;
	}
	
	}




void seven_segments(void)
{
	/*	if(NOT_INPUT_BIT(PINB,3) && READBIT_BIT(PINB,4) )
		{
			_delay_ms(3000);
			PORTD=0XFF;
		}*/
		/*                                       */
		while(INPUT_BIT(PINB,3) || INPUT_BIT(PINB,2))
		
	 {
		//counter=EEPROM_read();
		 if(PINB&(1<<3)&&counter<3)
			 	{
				 	counter++;
			 	}
			 	else if(PINB&(1<<2)&&counter>-5)
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
		while(INPUT_BIT(PINB,3) || INPUT_BIT(PINB,2));
	EEPROM_write(counter);  //write on it
	}	
	
		
	
}

void ELEMENTS (void)
{
	
	switch(counter)
	{
		case 1:
		ACTIVATION(0x65,70,60);
		break;
		case -1:
		ACTIVATION(0x55,60,50);
		break;
		case 2:
		ACTIVATION(0x70,75,65);
		break;
		case -2:
		ACTIVATION(0x50,55,45);
		break;
		case 3:
		ACTIVATION(0x75,80,70);
		break;
		case -3:
		ACTIVATION(0x45,50,40);
		break;
		case 0:
		ACTIVATION(0x60,65,55);
		break;
		case -4:
		ACTIVATION(0x40,45,35);
		break;
		case -5:
		ACTIVATION(0x35,40,30);
		break;
	}
}
		
		void ACTIVATION(u8 value,u8 max, u8 min)
		{
			if(PORTD == value)
			{
				if(average>=max)
				{
					OUTPUT_MODULE_ON(PORTB,5);  //cooling element activate
					OUTPUT_MODULE_OFF(PORTB,6);  //Heating element disactivate
				}
				else if(average<=min)
				{
					OUTPUT_MODULE_OFF(PORTB,5);  //cooling element disactivate
					OUTPUT_MODULE_ON(PORTB,6);  //Heating element activate
				}
		}
	
	}
	
				
				