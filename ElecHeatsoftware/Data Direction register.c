/*
 * Data_Direction_register.c
 *
 * Created: 9/3/2023 1:05:07 PM
 *  Author: Kirollos


//Data Direction registers Library that contains the  pre_processing definitive and prototypes
#include "Data Direction registers.h"






// all functions must be written to return a specific TYPE of information 
//and to take in specific types of data (parameters).
//That Set, reset the INPUT/OUTPUT Data Directory
// This information is communicated to the compiler via a function prototype.
 // The function prototype is also used at the beginning of the code for the function. 
 void DATA_DIRECTION_REGISTER(char SET_OUT,char SET_IN)
 {
  
// In case of putting 'O' parameter as an output activation
	if(SET_OUT=='O') 
	{
		//Set All OUTPUTS Modules 
		//	7 segment Data OUTPUTS
	PORTD0_OUT   //the PIN that is defined data on 7 segments  "PinD0"
	PORTD1_OUT    //the PIN that is defined data on 7 segments  "PinD1"
	PORTD2_OUT      //the PIN that is defined data on 7 segments  "PinD2"
	PORTD3_OUT        //the PIN that is defined data on 7 segments  "PinD3"
	PORTD4_OUT          //the PIN that is defined data on 7 segments  "PinD4"
	PORTD5_OUT            //the PIN that is defined data on 7 segments  "PinD5"
	PORTD6_OUT               //the PIN that is defined data on 7 segments  "PinD6"
	PORTD7_OUT                 //the PIN that is defined data on 7 segments  "PinD7"
	 
	
	 PORTB0_OUT    //the PIN that is defined to set the first segment "PinB0"
	 PORTB7_OUT     //the PIN that is defined to set the Second segment "PinB7"
	 PORTB5_OUT      //the PIN that is defined to set the Cooling Element "PinB5"
	 PORTB6_OUT       //the PIN that is defined to set the Heater Element "PinB6"
     PORTB4_OUT        //the PIN that is defined to set the Heating Element LED "PinB4"
	}
  
	// In case of putting 'I' parameter as an Input activation
	else if(SET_IN=='I')
	{
		 //Set All INPUTS Modules 
	 PORTB3_IN  //the PIN that is defined to set the upper Button that raise the setting temperature"PinB3"
	 PORTB2_IN   //the PIN that is defined to set the Lower Button that descend the setting temperature"PinB2"
	 PORTB1_IN  // the PIN that is defined to set the ON/OFF state of Electric water Heater"PinB1"
	}
  
	//In case of putting any data
	else
	{
		//Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		// the final else if shall be followed by an else statement.
		//  In the case of a simple if statement then the else statement need not be included.
		//   The requirement for a final else statement is defensive programming.
      //Implement any instruction rather than for updates
		
	}
	 
}
 */ 