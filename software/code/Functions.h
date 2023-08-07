
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
		average=(sum)/9.105;  //In testing and validation ,calibration 9.1125
		i=0;
		sum=0;
	}
	
}




void setting_temp(void)

{
	
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
	
	else if (PINB&(1<<3) || PINB&(1<<2))
	{
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
	
	EEPROM_write_read(counter);   // store value of counter to read it in EEPROM
	
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
		
		#define Start_Mode 1
		flag=1;
		while(INPUT_BIT(PINB,1));
	}
	else if(INPUT_BIT(PINB,1) && flag==1)
	{
		while(INPUT_BIT(PINB,1));
		
		flag=0;
		OFF_MODE();
		
		
	}
}


void current_water_temperature(void)
{
	on_off_7_segment(1);
	PORTD=decimal_to_bcd(x);
	
	
}
void on_off_7_segment(u8 Mode)
{
	if(Mode==1)
	{
		OUTPUT_MODULE_OFF(PORTB,0);
		OUTPUT_MODULE_OFF(PORTA,7);
	}
	else if(Mode==0)
	{
		OUTPUT_MODULE_ON(PORTB,0);
		OUTPUT_MODULE_ON(PORTA,7);
	}
	
}

void ON_MODE_Process (void)
{
	while(flag==1)
	{
		
		current_water_temperature();
		ELEMENTS();
		on_off_mode();
		if(((INPUT_BIT(PINB,3) || INPUT_BIT(PINB,2))))
		{
			
			while( counter_for_Timer<10 &&flag==1 ) //In testing and validation ,calibration
			{
				on_off_7_segment(1);
				setting_temp();
				ELEMENTS();
				on_off_mode();
				counter_for_Timer++;
				on_off_7_segment(0);
				setting_temp();
				ELEMENTS();
				on_off_mode();
				counter_for_Timer++;
				
				
				
			}
			counter_for_Timer=0;
		}
	}
}


void OFF_MODE(void)
{

	OUTPUT_MODULE_OFF(PORTB,5);  //cooling element activate
	OUTPUT_MODULE_OFF(PORTB,6);  //Heating element disactivate
	OUTPUT_MODULE_OFF(PORTB,4); //LED
	on_off_7_segment(0);
	
}

#endif