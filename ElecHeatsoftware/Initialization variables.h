/*Initialization variables.h
Header File
Author:Kirollos Gerges */


/*The #ifndef directive is one of the widely used used directives in C.
 It allows conditional compilations. During the compilation process.
 the preprocessor is supposed to determine if any provided macros exist before any subsequent code is included.*/

//#ifndef INITIALIZATION_VARIABLES_H 

/*The #define INITIALIZATION_VARIABLES_H creates a macro,
 which is the association of an identifier or parameterized identifier with a token string*/
#define INITIALIZATION_VARIABLES_H 

/*initialize 7_segments by 60 Celsius that refer to binary 0110 0000*/
 //For Pin7 in PORT D initialize it by Reset
#define PORTD7 OUTPUT_MODULE_OFF(PORTD,7); 
//For Pin6 in PORT D initialize it by SET
#define PORTD6 OUTPUT_MODULE_ON(PORTD,6);
//For Pin5 in PORT D initialize it by SET
#define PORTD5 OUTPUT_MODULE_ON(PORTD,5);
//For Pin4 in PORT D initialize it by Reset
#define PORTD4 OUTPUT_MODULE_OFF(PORTD,4);
//For Pin3 in PORT D initialize it by Reset
#define PORTD3 OUTPUT_MODULE_OFF(PORTD,3);
//For Pin2 in PORT D initialize it by Reset
#define PORTD2 OUTPUT_MODULE_OFF(PORTD,2);
//For Pin1 in PORT D initialize it by Reset
#define PORTD1 OUTPUT_MODULE_OFF(PORTD,1);
//For Pin0 in PORT D initialize it by Reset
#define PORTD0 OUTPUT_MODULE_OFF(PORTD,0);

/*initialize Elements by requirements*/
 
 /* RESET Heating element LED*/
#define  PORTB4  OUTPUT_MODULE_OFF(PORTB,4);
 /* RESET Cooling Element*/
#define  PORTB5  OUTPUT_MODULE_OFF(PORTB,5);
 /* RESET Heating element*/
#define  PORTB6   OUTPUT_MODULE_OFF(PORTB,6);

 /* SET  7 segments to be initialize disactivate 
 element due to the presence of P-Channel MOSFET that 
 control on 7 segments powering*/
 
 /*SET first 7 segment*/
#define  PORTB0     OUTPUT_MODULE_ON(PORTB,0);
/*SET second 7 segment*/
#define  PORTB7     OUTPUT_MODULE_ON(PORTB,7);

/*
The function prototypes are used to inform the compiler about the number of arguments,
 the needed data types of a function parameter, and the function's return type. 
 The compiler uses this information to cross-check function signatures before invoking them
*/
void Init_VARIABLES(char STATE_OF_first_7_segment,char STATE_OF_second_7_segment,
char STATE_OF_7_segment_Data,char STATE_OF_Heating_element_LED
,char STATE_OF_Cooling_Element,char STATE_OF_Heating_element);


//#endif


/* all functions must be written to return a specific TYPE of information 
and to take in specific types of data (parameters).
That Set, reset the INPUT/OUTPUT Data Directory
 This information is communicated to the compiler via a function prototype.
  The function prototype is also used at the beginning of the code for the function. */

void Init_VARIABLES(char STATE_OF_first_7_segment,char STATE_OF_second_7_segment,
char STATE_OF_7_segment_Data,char STATE_OF_Heating_element_LED
,char STATE_OF_Cooling_Element,char STATE_OF_Heating_element)

{ 
  
  /* In case of putting 'S' parameter */
	 if(STATE_OF_first_7_segment == 'S')
{
  /*Disactivate initializing first 7 segment*/
 PORTB0  
}

 /* In case of putting 'S' parameter */
 if(STATE_OF_second_7_segment == 'S')
{
   /*Disactivate initializing second 7 segment*/
PORTB7
}

 /* In case of putting 'I' parameter on state of
 Data and The 2 seven segment is turned off to warranty that 
 initialize data not be sent until the seven segments is 
 turned off */
	else if(STATE_OF_7_segment_Data == 'I'&&
   STATE_OF_first_7_segment == 'S'&&
   STATE_OF_second_7_segment == 'S')
  { 
	//Sent initializing Data to 7 segments
PORTD7 PORTD6 PORTD5 PORTD4 PORTD3 PORTD2 PORTD1 PORTD0
  }
  /* In case of putting 'R' parameter */
  else if(STATE_OF_Heating_element_LED== 'R')
{
  /*Disactivate initializing Heating element Led*/
PORTB4
}

 /* In case of putting 'R' parameter */
else if(STATE_OF_Cooling_Element== 'R')
{
   /*Disactivate initializing cooling element*/
  PORTB5
}

 /* In case of putting 'R' parameter */
else if(STATE_OF_Heating_element== 'R')
{
     /*Disactivate initializing Heating element*/
  PORTB6
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


	


