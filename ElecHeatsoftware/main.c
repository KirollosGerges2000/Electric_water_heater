/*
 * ElecHeatsoftware.c
 *
 * Created: 8/15/2023 12:17:29 PM
 * Author : Kirollos
 */ 

//includes and complex drivers
#include <avr/io.h> //General purpose Input/output library  
#include <util/delay.h>  //Sys_Ticks library that has 16MHZ crystal frequency
#include <stdlib.h>  //converting Hexa_decimal library
#include "DIO.h"   // Digital Input/Output Library for determine pin is Out/IN
#include "Data Direction registers.h" // Deceleration of Input/output modules library by Data Direction Registers
#include "MACROS.h"  //controlling inputs/Outputs Library
#include "STD_TYPES.h" //Definition of using data types for more readability  Library
#include "Initialization variables.h" //initialization the variables that used in this project Library
#include "Prototypes.h" // Deceleration of all Functions that used in this project Library
#include "I2C.h"  // External EEPROM Driver library to save and fetch the setting temperature 
#include "ADC.h" //  Analog_Digital_converter Driver library to read the temperature from sensor.
#include "interrupt.h" //Internal Timer1 interrupt Driver Library for reading temperature each 100 ms during running of program.

/*
The main() function is the first function in your program that is executed when it begins executing, but it's not the first function
 executed. The first function is _start(), which is typically provided by the C runtime library, linked in automatically 
 when your program is compiled.

the main function that executes in this project*/
int main(void)
{
	DATA_DIRECTION_REGISTER('O','I'); //Activate all input/Outputs sensors,actuators Pins 
INT_interrupt(); //Initialize the internal Timer 1 Driver
ADC_init(); //Initialize the Analog/Digital converter Driver
Init_VARIABLES(); //Initialize All variables that used in this project by required values.
    /* super loop for repeating process infinitely number of cycles */
    while (1) 
    {
		on_off_mode();  // wait until user switch on the Heater.
		if(flag==1) 
		/*When Flag is set that mean that Heater is activate
		; so that It will execute this scope*/
		{
			/*The main Process will execute that covered all requirements of project
			with asking user if the Heater is set/Reset for each cycle Until the Flag 
			reset terminates this scope. */
			ON_MODE_Process (); 
			/*Monitoring On/OFF mode the change the state of flag according to On/OFF switch*/
			on_off_mode();
		}
		
}
/*Return 0 to terminates Function */
return 0;
}









