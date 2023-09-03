/*
 * Initialization_variables.c
 *
 * Created: 9/3/2023 1:07:10 PM
 *  Author: Kirollos
 */ 


/*
//Initialization variables Library that contains the  pre_processing definitive and prototypes
#include "Initialization variables.h"





void Init_VARIABLES(char STATE_OF_first_7_segment,char STATE_OF_second_7_segment,
char STATE_OF_7_segment_Data,char STATE_OF_Heating_element_LED
,char STATE_OF_Cooling_Element,char STATE_OF_Heating_element)

{ 
  
  //In case of putting 'S' parameter 
	 if(STATE_OF_first_7_segment == 'S')
{
  //Disactivate initializing first 7 segment
 PORTB0  
}

 // In case of putting 'S' parameter 
 if(STATE_OF_second_7_segment == 'S')
{
   //Disactivate initializing second 7 segment
PORTB7
}

 // In case of putting 'I' parameter on state of
 //Data and The 2 seven segment is turned off to warranty that 
 //initialize data not be sent until the seven segments is 
 //turned off 
	else if(STATE_OF_7_segment_Data == 'I'&&
   STATE_OF_first_7_segment == 'S'&&
   STATE_OF_second_7_segment == 'S')
  { 
	//Sent initializing Data to 7 segments
PORTD7 PORTD6 PORTD5 PORTD4 PORTD3 PORTD2 PORTD1 PORTD0
  }
 // In case of putting 'R' parameter
  else if(STATE_OF_Heating_element_LED== 'R')
{
  //Disactivate initializing Heating element Led
PORTB4
}

 // In case of putting 'R' parameter 
else if(STATE_OF_Cooling_Element== 'R')
{
   //Disactivate initializing cooling element
  PORTB5
}

 // In case of putting 'R' parameter 
else if(STATE_OF_Heating_element== 'R')
{
     //Disactivate initializing Heating element
  PORTB6
}


	//In case of putting any data
else
{
  //Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
	//	 the final else if shall be followed by an else statement.
	//	  In the case of a simple if statement then the else statement need not be included.
	//	   The requirement for a final else statement is defensive programming.
  //Implement any instruction rather than for updates
}

}

*/

	


