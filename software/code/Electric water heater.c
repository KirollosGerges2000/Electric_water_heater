#include <avr/io.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "MACROS.h" 
#include "ADC.c"
#include "DIO.h"
#include "interrupt.c"
#include "I2C.c"
#include "delay.h"
volatile uint16 volt =0;
volatile f32 x = 0;
 static f32  average;
  f32 sum;
int16 counter = 0;
u8 i=0;
u8 flag=0;
uint16 counter_for_Timer=0;

	 /*the main process*/
 void  ELECTRIC_WATER_HEATER(void)
	{	 	
		INT_interrupt();  /* initialize internally interrupt Timer1*/
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
			
			 on_off_mode();
			 while(flag==1)
			 {
			current_water_temperature();
					   ELEMENTS();
					  on_off_mode();
					if((INPUT_BIT(PINB,3) || INPUT_BIT(PINB,2)))
			 {
				 setting_temp();
					ELEMENTS();
					on_off_mode();	
			 }
						
			
				
		}
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




void setting_temp(void)
{
	 
		                                  
	//	if((INPUT_BIT(PINB,3) || INPUT_BIT(PINB,2)))
		
	 {
		 
		//counter=EEPROM_read();
		 if(PINB&(1<<3)&&counter<3 )
			 	{
				 	counter++;
					 counter_for_Timer=0;
			 	}
			 	else if(PINB&(1<<2)&&counter>-5)
			 	{
				 	counter--;
					  counter_for_Timer=0;
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
	EEPROM_write_read(counter);   // store value of counter.
	
	}	
	
}

void ELEMENTS (void)
{

	{
		switch(counter)
	{
		case 1:
		ACTIVATION(1,70,60);
		break;
		case -1:
		ACTIVATION(-1,60,50);
		break;
		case 2:
		ACTIVATION(2,75,65);
		break;
		case -2:
		ACTIVATION(-2,55,45);
		break;
		case 3:
		ACTIVATION(3,80,70);
		break;
		case -3:
		ACTIVATION(-3,50,40);
		break;
		case 0:
		ACTIVATION(0,65,55);
		break;
		case -4:
		ACTIVATION(-4,45,35);
		break;
		case -5:
		ACTIVATION(-5,40,30);
		break;
	}
	}
	
}
		
		void ACTIVATION(uint16 value,u8 max, u8 min)
		{
			if(counter == value)
			{
				if(average>=max)
				{
					OUTPUT_MODULE_ON(PORTB,5);  //cooling element activate
					OUTPUT_MODULE_OFF(PORTB,6);  //Heating element disactivate
						OUTPUT_MODULE_ON(PORTB,4); //LED
				}
				else if(average<=min)
				{
					OUTPUT_MODULE_OFF(PORTB,5);  //cooling element disactivate
					OUTPUT_MODULE_ON(PORTB,6);  //Heating element activate
					TOGGLe_BIT(PORTB,4);
						_delay_ms(700);
					
					
				}
		}
	
	}
	
	void on_off_mode(void)
	{
		
		if(INPUT_BIT(PINB,1) && flag==0)
		{
			TOGGLe_BIT(PORTB,0);
			TOGGLe_BIT(PORTA,7);
			flag=1;
			while(INPUT_BIT(PINB,1));
		}
		else if(INPUT_BIT(PINB,1) && flag==1)
		{
			flag=0;
			TOGGLe_BIT(PORTB,0);
			TOGGLe_BIT(PORTA,7);
			OUTPUT_MODULE_OFF(PORTB,4);
			OUTPUT_MODULE_OFF(PORTB,5);
			OUTPUT_MODULE_OFF(PORTB,6);
			
			while(INPUT_BIT(PINB,1));
		}
	}
	
	
	void current_water_temperature(void)
	{
		
		 
			  OUTPUT_MODULE_OFF(PORTB,0);
		OUTPUT_MODULE_OFF(PORTA,7);
		PORTD=decimal_to_bcd(x);
		 
		
	}
	

	