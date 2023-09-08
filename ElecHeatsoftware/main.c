/*
 * ElecHeatsoftware.c
 *
 * Created: 8/15/2023 12:17:29 PM
 * Author : Kirollos
 */ 

/********Abstract of Electric water Heater Project ********/
/*
.Heating water in your home can account for up to 20% of your monthly energy bills,
 according to the U.S. Department of Energy. You might not think about your water heater much
  (unless you suddenly run out of hot water!) but if your water heater isn't efficient, 
  you could be wasting a lot of money. By switching to an electric water heater, you can save on energy costs, 
  and make the most of your solar power investment.

.In this guide, we will explain what an electric water heater is, the pros and cons of electric water heaters,
 the benefits over gas water heaters, a buyers guide with tips on how to shop for an electric water heater, 
 and why you should invest in electric water heating for your home, especially if you are going solar.
*/


/********About Safety and security , Misra Rule "C99" 2012********/
/*
.Fast Water Heater Company performs installations as safely as possible to protect you and your family.
 Due to various injuries and accidents related to water heaters over the last ten years, 
 most cities and counties have adopted either the 2006, 2009 or 2012 Uniform Plumbing Code
  (or in the case of California, the California Plumbing Code).

.When we perform your installation, we will inspect your water heater and ensure it is up to date on all relevant safety codes.

.Also, on the back of your invoice, you will find a list of all of the state codes that are relevant for your installation
*/

/********Data about presenters and Deliverable this project********/
/*This Project is presented to AMIT campony as a Graduation project  for Embedded software Diploma _Group Nasr_53 
Developed by,Designed "Static ,Dynamic" by , Testing"static,Dynamic" by , integrated , calibration by :         
Eng/Kirollos Gerges Asaad  Email:191800006@ecu.edu.eg                                                            */


/*                                  
An int is a keyword that references an integer data type. 
An int data type used with the main() function that indicates the function should return an integer value.
 When we use an int main() function, it is compulsory to write return 0; statement at the end of the main() function.
  The return 0; statement represents that the program has been successfully executed,
   whereas any other statement represents the unsuccessful termination of the program.
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
Init_VARIABLES('S','S','I','R','R','R'); //Initialize All variables that used in this project by required values.
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
		
		/*In case of putting any data in new versions*/
		else
		{
			 /*Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		 the final else if shall be followed by an else statement.
		  In the case of a simple if statement then the else statement need not be included.
		   The requirement for a final else statement is defensive programming.*/
  /* Implement any instruction rather than for updates*/
		}
		
}
/*Return 0 to terminates Function */
return 0;
}









