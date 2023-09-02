/*
 * Data Direction registers.h
 *
 * Created: 8/14/2023 6:15:30 PM
 * Author: Kirollos
 */

/*The #ifndef directive is one of the widely used used directives in C.
 It allows conditional compilations. During the compilation process.
 the preprocessor is supposed to determine if any provided macros exist before any subsequent code is included.*/
#ifndef DATA_DIRECTION_REGISTER_H
/*The #define DATA_DIRECTION_REGISTER_H creates a macro, 
which is the association of an identifier or parameterized identifier with a token string*/
#define DATA_DIRECTION_REGISTER_H


//	OUTPUTS preprocessing definitions
#define  PORTD0_OUT  OUTPUT_MODULE(DDRD,0) //set data that write on 7 segment as output "Pin0"
#define  PORTD1_OUT  OUTPUT_MODULE(DDRD,1) //set data that write on 7 segment as output "Pin1"
#define  PORTD2_OUT  OUTPUT_MODULE(DDRD,2) //set data that write on 7 segment as output "Pin2"
#define  PORTD3_OUT  OUTPUT_MODULE(DDRD,3) //set data that write on 7 segment as output "Pin3"
#define  PORTD4_OUT  OUTPUT_MODULE(DDRD,4) //set data that write on 7 segment as output "Pin4"
#define  PORTD5_OUT  OUTPUT_MODULE(DDRD,5) //set data that write on 7 segment as output "Pin5"
#define  PORTD6_OUT  OUTPUT_MODULE(DDRD,6) //set data that write on 7 segment as output "Pin6"
#define  PORTD7_OUT  OUTPUT_MODULE(DDRD,7) //set data that write on 7 segment as output "Pin7"


#define  PORTB0_OUT  OUTPUT_MODULE(DDRB,0) //set Enable of first 7 segment as output
#define  PORTB7_OUT OUTPUT_MODULE(DDRB,7)//set Enable of second 7 segment as output
#define  PORTB5_OUT OUTPUT_MODULE(DDRB,5) //set cooling fan as output
#define  PORTB6_OUT OUTPUT_MODULE(DDRB,6) //set Heater as output
#define  PORTB4_OUT OUTPUT_MODULE(DDRB,4) //set Heater LED as output

//INPUTS preprocessing definitions
#define  PORTB3_IN INPUT_MODULE(DDRB,3) //set increment temperature button to be input
#define  PORTB2_IN INPUT_MODULE(DDRB,2) //set decrement temperature button to be input
#define  PORTB1_IN INPUT_MODULE(DDRB,1) //set OFF/ON button to be input*/


#endif


/*
The function prototypes are used to inform the compiler about the number of arguments,
 the needed data types of a function parameter, and the function's return type. 
 The compiler uses this information to cross-check function signatures before invoking them
*/
void DATA_DIRECTION_REGISTER(char SET_OUT,char SET_IN);


/* all functions must be written to return a specific TYPE of information 
and to take in specific types of data (parameters).
That Set, reset the INPUT/OUTPUT Data Directory
 This information is communicated to the compiler via a function prototype.
  The function prototype is also used at the beginning of the code for the function. */
 void DATA_DIRECTION_REGISTER(char SET_OUT,char SET_IN)
 {
  
/* In case of putting 'O' parameter as an output activation*/
	if(SET_OUT=='O') 
	{
		/*Set All OUTPUTS Modules */
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
  
	/* In case of putting 'I' parameter as an Input activation*/
	else if(SET_IN=='I')
	{
		 /*Set All INPUTS Modules */
	 PORTB3_IN  //the PIN that is defined to set the upper Button that raise the setting temperature"PinB3"
	 PORTB2_IN   //the PIN that is defined to set the Lower Button that descend the setting temperature"PinB2"
	 PORTB1_IN  // the PIN that is defined to set the ON/OFF state of Electric water Heater"PinB1"
	}
  
	/*In case of putting any data*/
	else
	{
		/*Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		 the final else if shall be followed by an else statement.
		  In the case of a simple if statement then the else statement need not be included.
		   The requirement for a final else statement is defensive programming.*/
     /* Implement any instruction rather than for updates*/
		
	}
	 
}









