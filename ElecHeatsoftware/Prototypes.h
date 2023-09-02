
/*Prototypes.h
Header File
Author:Kirollos Gerges */


/*initialize all variables with zero for Default state 
that needed in thisProject by appropriate data types
 and keywords for its specific functions
*/


 /*Deceleration about input milli_volt 
 that processed it
 to be temperature value ; 
 must to be volatile  as  the value changes 
 each time the cell is calculated.*/
volatile uint16 volt=0;

/*After processing volt ; variable 'x' will 
be the temperature reading than processed from measured 
milli_volt and convert it to temperature_reading by analog 
Digital converter Driver; must to be volatile  as  
the value changes each time the cell is calculated.*/
volatile f32 x=0 ;

/*
According to requirements, Specifications of Temperature sensing.5
"The decision to turn ON or OFF either the “Heating Element” 
or the “Cooling Element” based on the average of 
the last 10 temperature readings " that measured from
 temperature sensor and using static makes the variable retain its 
 value among multiple function calls.; 
*/
static f32  average=0;

/*
Deceleration The Sum of 10 temperature reading that divide on 10 
to be result of average
*/
f32 sum=0;

/*
Deceleration about counter that carry the value of the 
temperature that will be setting by user from requirements
range 35_75 CELESIUS that point to its sequence in counter 
from 91_0 below 60 "original value" 0_3 above the original.
*/
int16 counter= 0;

/*
Deceleration about 'i' that indicates to 
counting from 0_9 to get the 
sum of 10 temperature reading 
*/
u8 i=0;

/*
Deceleration about flag that indicates 
the mode of Electric water Heater is Mode 
ON or OFF, 
OFF indicates to 0
ON indicates to 1
*/
u8 flag=0;

/*
Deceleration about Start_Mode is not
Mandatory,But indicates for flag
To remove This warning!!!
Put "//" on these statement 
to be not read about compiler
*/
u8 Start_Mode=0;

/*
According to requirements in specification.5 of seven segments
 "The 2 seven segment display should exit the temperature setting mode,
  if the “UP” and “Down” buttons are not pressed for 5 seconds."
  Deceleration about it to counting 5 counts each count with 1 second 
  then terminates these function.
*/
s64 counter_for_Timer=0;



/*The #ifndef directive is one of the widely used used directives in C.
 It allows conditional compilations. During the compilation process.
 the preprocessor is supposed to determine if any provided macros exist before any subsequent code is included.*/
#ifndef PROTOTYPES_H

/*The #define PROTOTYPES_H creates a macro,
which is the association of an identifier 
or parameterized identifier with a token string*/
#define PROTOTYPES_H

/*
The function prototypes are used to inform the compiler about the number of arguments,
 the needed data types of a function parameter, 
 and the function's return type. 
 The compiler uses this information to
  cross-check function signatures before invoking them*/

/*
Deceleration about the function that 
convert from the output milli_volt to 
Temperature reading in Celsius 
*/
void Temperature_reading(void);

/*
Deceleration about the function that
Take the temperature reading then get 
Sum of this readings by using arrays 
then dividing them on 10 to get average.
*/
void Avg_reading(void);

/*
Deceleration about the function that
permit user to control setting Mode
 by setting the temperature according to 
 raise,lower temperature in 
the Electric water Heater.
*/
void setting_temp(void);

/*
Deceleration about the function that
control in activation of Elements on 
Electric water Heater according
to the requirements "Specifications 
–Heating/Cooling Elements"
 of setting temperature,
Fluctions.
*/
void ELEMENTS (void);

/*
Deceleration about the Driver function 
of Electric water Heater device run ,as
integration to all of layers is done in
This function.
so we named it a system layer
*/
void ON_MODE_Process (void);

/*Deceleration about the Driver function
 that control in Activate or disactivate 
 the all layers of system.
*/
void On_off_mode (void);

/*
According to requirements,• Specifications 
–Temperature Setting.7|8
"7. The “External E2PROM” should save the set temperature once set.
8. If the electric water heater is turned OFF then ON, 
the stored set temperature
should be retrieved from the “External E2PROM”."
by using IIC protocol for communication between
Communication protocol and Micro controller abstraction layer.
*/
u8 EEPROM_write_read(u8 stored_data);

/*
Deceleration about the function that
use it in current water to display 
temperature on seven segments and 
EEPROM driver to store and retrieve 
the setting temperature value.
*/
char decimal_to_bcd(u8 val);

/*
Deceleration about the function that
permits the developers to put which pin
be input of ADC driver on PORTA that used to monitor 
Temperature of water.
*/
unsigned short ADC_readChannel(unsigned char channel_num);

/*
Deceleration about the function that
integrate with elements Function that tend to
the Driver of "void ELEMNTS(void)" Function
*/
void ACTIVATION(uint16 value,u8 max, u8 min);

/*
Deceleration about the function that
controlling the powering of seven segments
according to requirements.
*/
void on_off_7_segment(u8 Mode);

/*
According to requirements, Specifications –Seven Segments.1|2
"1. Seven segment by defaults how the current water temperature
 or the set temperature.
2. By default, the 2 seven segment display are show the 
current water temperature."
*/
void current_water_temperature(void);

/*
Deceleration about the function that
Make the system in sleep Mode 
Disabling all of system layer by 
calling it.
*/
void OFF_MODE(void);


#endif








/*function that
convert from the output milli_volt to
Temperature reading in Celsius
*/
void Temperature_reading(void)
{
	volt = ADC_readChannel(0); // read channel two where the temp sensor is connect
	/*Casting to convert from integer into float after processing*/
	x=(float)(5*volt)/1023; // to gain the ADC of temperature reading 
	x=x*100;   //the reading of temperature
	Avg_reading();  //the equations of average 10 temperature reading
}

/*function thatTake the temperature
 reading then getSum of this readings
  by using arrays then dividing them 
  on 10 to get average.*/
void Avg_reading(void)
{
	//For calculate the cumulative sum of last 10 temperature readings
	sum=sum+x; 
	i++;//For each reading increment i
	/*In case of 'i'=9 */
	if(i==9)
	{
		/*Calculate the average to send to the Activation Mode*/
		/*For 9.105 for more accuracy , less tolerance,error of average readings*/
		average=(sum)/9.105;  
		/*Then Make 'i' and the 'sum' to its original value
		waiting for new average Temperature reading calculations*/
		i=0;
		sum=0;
	}
	}

/*the function that
permit user to control setting Mode
by setting the temperature according to
raise,lower temperature in
the Electric water Heater.
*/
void setting_temp(void)
{
	/*
	In case user press upper switch 
	and the counter does not reach its top value"3"
	*/
	if(PINB&(1<<3)&&counter<3 )
	{
		//increment counter by 1
		counter++;
		//Begin counting From 0 in Setting Mode.
		counter_for_Timer=0;   
	}
	/*
	In case user press Lower switch 
	and the counter does not reach its lower value"-5"
	*/
	else if(PINB&(1<<2)&&counter>-5)
	{
		//decrement counter by 1
		counter--;
		//Begin counting From 0 in Setting Mode.
		counter_for_Timer=0;
	}
	/*
	For more Safety ,In case user press Lower switch 
	and upper switch together.
	*/
	else if (PINB&(1<<3) || PINB&(1<<2))
	{
		/*Begin counting From 0 in Setting Mode,
		waiting releasing each or both buttons.
		*/
		counter_for_Timer=0;
	}
	
		/*
	For more Safety ,In case of non_executing any
	statements of each other .
	*/
	else
	{
		/*Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		 the final else if shall be followed by an else statement.
		  In the case of a simple if statement then the else statement need not be included.
		   The requirement for a final else statement is defensive programming.*/
     /* Implement any instruction rather than for updates*/
	}
	
	/*After take the decision , the setting temperature driver 
	service will sent the data that chosen user by to 7 segments
	*/
	switch(counter) //For counter statement
	{
		/*
		The break statement is used inside the switch to terminate a statement sequence.
		 The break statement is optional. If omitted, execution will continue on into the next case.
		  The default statement is optional and can appear any where inside the switch block.
		*/
		
		/* In case of counter=1;     
		 65 Celisuis sent to 7segments*/
		case 1:
		PORTD=0x65;
		break;
		
		/* In case of counter=-1;     
		 55 Celisuis sent to 7segments*/
		case -1:
		PORTD=0x55;
		break;
		
		/* In case of counter=2;     
		 70 Celisuis sent to 7segments*/
		case 2:
		PORTD=0x70;
		break;
		
		/* In case of counter=-2;     
		 50 Celisuis sent to 7segments*/
		case -2:
		PORTD=0x50;
		break;
		
		/* In case of counter=3;     
		 75 Celisuis sent to 7segments*/
		case 3:
		PORTD=0x75;
		break;
		
		/* In case of counter=-3;     
		 45 Celisuis sent to 7segments*/
		case -3:
		PORTD=0x45;
		break;
		
		/* In case of counter=0;     
		 60 Celisuis sent to 7segments*/
		case 0:
		PORTD=0x60;
		break;
		
		/* In case of counter=-4;     
		 40 Celisuis sent to 7segments*/
		case -4:
		PORTD=0x40;
		break;
		
		/* In case of counter=-5;     
		 35 Celisuis sent to 7segments*/
		case -5:
		PORTD=0x35;
		break;
		
		/*
		MISRA C Rule 15.3 (required): The final clause of a switch statement shall be the default clause. 
		The requirement for a final default clause is defensive programming. 
		This clause shall either take appropriate action or contain a suitable comment
		 as to why no action is taken.
		*/
		default:
		/*
		For any values want to sent in updates versions.
		*/
		break;
		
		
	}
	/* 
	EEPROM Driver using IIC protocol
	to write value of counter that store 
	it in external Read only memory
	then retrieve the storing value of counter
	 to set on the system and display in setting mode.
*/
EEPROM_write_read(counter);   
}

/*
Deceleration about the function that
control in activation of Elements on 
Electric water Heater according
to the requirements "Specifications 
–Heating/Cooling Elements"
 of setting temperature,
Fluctions.
*/

void ELEMENTS (void)
{
	{
		/*After take the decision of each counter is chosen
		;Each of counter value has a control strategy according to 
		Requirements */
		switch(counter) //For counter statements
		{
			/*
		The break statement is used inside the switch to terminate a statement sequence.
		 The break statement is optional. If omitted, execution will continue on into the next case.
		  The default statement is optional and can appear any where inside the switch block.
		*/
			
			/* In case of counter=1;     
		its specific instructions sent to Elements*/
			case 1:
			ACTIVATION(1,70,60);
			break;
			
			/* In case of counter=-1;     
		its specific instructions sent to Elements*/
			case -1:
			ACTIVATION(-1,60,50);
			break;
			
			/* In case of counter=2;     
		its specific instructions sent to Elements*/
			case 2:
			ACTIVATION(2,75,65);
			break;
			
			/* In case of counter=-2;     
		its specific instructions sent to Elements*/
			case -2:
			ACTIVATION(-2,55,45);
			break;
			
			/* In case of counter=3;     
		its specific instructions sent to Elements*/
			case 3:
			ACTIVATION(3,80,70);
			break;
			
			/* In case of counter=-3;     
		its specific instructions sent to Elements*/
			case -3:
			ACTIVATION(-3,50,40);
			break;
			
			/* In case of counter=0;     
		its specific instructions sent to Elements*/
			case 0:
			ACTIVATION(0,65,55);
			break;
			
			/* In case of counter=-4;     
		its specific instructions sent to Elements*/
			case -4:
			ACTIVATION(-4,45,35);
			break;
			
			/* In case of counter=-5;     
		its specific instructions sent to Elements*/
			case -5:
			ACTIVATION(-5,40,30);
			break;
			
			/*
		MISRA C Rule 15.3 (required): The final clause of a switch statement shall be the default clause. 
		The requirement for a final default clause is defensive programming. 
		This clause shall either take appropriate action or contain a suitable comment
		 as to why no action is taken.
		*/
			
			default:
			/*
		For any values want to sent in updates versions.
		*/
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
		
		flag=1;
		Start_Mode=flag;
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
		OUTPUT_MODULE_OFF(PORTB,7);
	}
	else if(Mode==0)
	{
		OUTPUT_MODULE_ON(PORTB,0);
		OUTPUT_MODULE_ON(PORTB,7);
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


