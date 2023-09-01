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





/* the main function that executes in this project*/
int main(void)
{
	DATA_DIRECTION_REGISTER('O','I'); //Determine 
INT_interrupt();
ADC_init();
Init_VARIABLES();
    /* Replace with your application code */
    while (1) 
    {
		on_off_mode();
		if(flag==1)
		{
			ON_MODE_Process ();
			on_off_mode();
		}
		
}
return 0;
}









