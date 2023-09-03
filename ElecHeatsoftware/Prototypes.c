/*
 * Prototypes.c
 *
 * Created: 9/3/2023 1:09:34 PM
 *  Author: Kirollos
 */ 


/*
//All Functions  Library that contains the  pre_processing definitive and prototypes
#include "Prototypes.h"



//function that
//convert from the output milli_volt to
//Temperature reading in Celsius

void Temperature_reading(void)
{
	volt = ADC_readChannel(0); // read channel two where the temp sensor is connect
	//Casting to convert from integer into float after processing
	x=(float)(5*volt)/1023; // to gain the ADC of temperature reading 
	x=x*100;   //the reading of temperature
	Avg_reading();  //the equations of average 10 temperature reading
}

//function thatTake the temperature
// reading then getSum of this readings
//  by using arrays then dividing them 
//  on 10 to get average.
void Avg_reading(void)
{
	//For calculate the cumulative sum of last 10 temperature readings
	sum=sum+x; 
	i++;//For each reading increment i
	//In case of 'i'=9 
	if(i==9)
	{
		//Calculate the average to send to the Activation Mode
		//For 9.105 for more accuracy , less tolerance,error of average readings
		average=(sum)/9.105;  
		//Then Make 'i' and the 'sum' to its original value
	//	waiting for new average Temperature reading calculations
		i=0;
		sum=0;
	}
	}

//the function that
//permit user to control setting Mode
// by setting the temperature according to
//raise,lower temperature in
//the Electric water Heater.

void setting_temp(void)
{
	
	//In case user press upper switch 
//	and the counter does not reach its top value"3"

	if(PINB&(1<<3)&&counter<3 )
	{
		//increment counter by 1
		counter++;
		//Begin counting From 0 in Setting Mode.
		counter_for_Timer=0;   
	}
	
	//In case user press Lower switch 
	//and the counter does not reach its lower value"-5"
	
	else if(PINB&(1<<2)&&counter>-5)
	{
		//decrement counter by 1
		counter--;
		//Begin counting From 0 in Setting Mode.
		counter_for_Timer=0;
	}
	
	//For more Safety ,In case user press Lower switch 
	//and upper switch together.
	
	else if (PINB&(1<<3) || PINB&(1<<2))
	{
		//Begin counting From 0 in Setting Mode,
		//waiting releasing each or both buttons.
		
		counter_for_Timer=0;
	}
	
		
	//For more Safety ,In case of non_executing any
//	statements of each other .
	
	else
	{
		//Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		// the final else if shall be followed by an else statement.
		 // In the case of a simple if statement then the else statement need not be included.
		//   The requirement for a final else statement is defensive programming.
     // Implement any instruction rather than for updates
	}
	
	//After take the decision , the setting temperature driver 
	//service will sent the data that chosen user by to 7 segments
	
	switch(counter) //For counter statement
	{
		
		//The break statement is used inside the switch to terminate a statement sequence.
		// The break statement is optional. If omitted, execution will continue on into the next case.
		//  The default statement is optional and can appear any where inside the switch block.
		
		
		// In case of counter=1;     
		// 65 Celisuis sent to 7segments
		case 1:
		PORTD=0x65;
		break;
		
		// In case of counter=-1;     
		// 55 Celisuis sent to 7segments
		case -1:
		PORTD=0x55;
		break;
		
		//In case of counter=2;     
		// 70 Celisuis sent to 7segments
		case 2:
		PORTD=0x70;
		break;
		
		// In case of counter=-2;     
		// 50 Celisuis sent to 7segments
		case -2:
		PORTD=0x50;
		break;
		
		//In case of counter=3;     
		 //75 Celisuis sent to 7segments
		case 3:
		PORTD=0x75;
		break;
		
		// In case of counter=-3;     
		 //45 Celisuis sent to 7segments
		case -3:
		PORTD=0x45;
		break;
		
		// In case of counter=0;     
		 //60 Celisuis sent to 7segments
		case 0:
		PORTD=0x60;
		break;
		
		// In case of counter=-4;     
		 //40 Celisuis sent to 7segments
		case -4:
		PORTD=0x40;
		break;
		
		// In case of counter=-5;     
		 //35 Celisuis sent to 7segments
		case -5:
		PORTD=0x35;
		break;
		
		
		//MISRA C Rule 15.3 (required): The final clause of a switch statement shall be the default clause. 
		//The requirement for a final default clause is defensive programming. 
		//This clause shall either take appropriate action or contain a suitable comment
		// as to why no action is taken.
		
		default:
		
		//For any values want to sent in updates versions.
		
		break;
		
		
	}
	 
	//EEPROM Driver using IIC protocol
	//to write value of counter that store 
	//it in external Read only memory
	//then retrieve the storing value of counter
	// to set on the system and display in setting mode.

EEPROM_write_read(counter);   
}


//Deceleration about the function that
//control in activation of Elements on 
//Electric water Heater according
//to the requirements "Specifications 
//–Heating/Cooling Elements"
// of setting temperature,
//Fluctions.

void ELEMENTS (void)
{
	{
		//After take the decision of each counter is chosen
		//;Each of counter value has a control strategy that 
		//integrate with Activation Function according to 
		//Requirements 
		switch(counter) //For counter statements
		{
		
		//The break statement is used inside the switch to terminate a statement sequence.
		// The break statement is optional. If omitted, execution will continue on into the next case.
		//  The default statement is optional and can appear any where inside the switch block.
		
			
			// In case of counter=1;     
		//its specific instructions sent to Elements
			case 1:
			ACTIVATION(1,70,60);
			break;
			
			// In case of counter=-1;     
		//its specific instructions sent to Elements
			case -1:
			ACTIVATION(-1,60,50);
			break;
			
			// In case of counter=2;     
		//its specific instructions sent to Elements
			case 2:
			ACTIVATION(2,75,65);
			break;
			
		//In case of counter=-2;     
		//its specific instructions sent to Elements
			case -2:
			ACTIVATION(-2,55,45);
			break;
			
			// In case of counter=3;     
		//its specific instructions sent to Elements
			case 3:
			ACTIVATION(3,80,70);
			break;
			
			// In case of counter=-3;     
		//its specific instructions sent to Elements
			case -3:
			ACTIVATION(-3,50,40);
			break;
			
			// In case of counter=0;     
		//its specific instructions sent to Elements
			case 0:
			ACTIVATION(0,65,55);
			break;
			
			// In case of counter=-4;     
		//its specific instructions sent to Elements
			case -4:
			ACTIVATION(-4,45,35);
			break;
			
			// In case of counter=-5;     
		//its specific instructions sent to Elements
			case -5:
			ACTIVATION(-5,40,30);
			break;
			
			
		//MISRA C Rule 15.3 (required): The final clause of a switch statement shall be the default clause. 
		//The requirement for a final default clause is defensive programming. 
		//This clause shall either take appropriate action or contain a suitable comment
		// as to why no action is taken.
		
			
			default:
			
		//For any values want to sent in updates versions.
		
			break;
		}
	}
	}


//function that integrate with elements Function that tend to
//the Driver of "void ELEMNTS(void)" Function.

void ACTIVATION(uint16 value,u8 max, u8 min)
{
	// In case of counter must be specified value determined by 
	//developer for more accuracy *
	if(counter == value)
	{
		//Control in Elements according specific decisions 
		//specified by developer
		
	
	  // In case of average is more than the  specified
		 //value determined by developer for more accuracy 
		
		if(average>=max)
		{
			//Execute Heating Mode decision
			OUTPUT_MODULE_ON(PORTB,5);  //SET cooling Element
			OUTPUT_MODULE_OFF(PORTB,6);  //RESET Heating Element 
			OUTPUT_MODULE_ON(PORTB,4); //SET Heating LED Element
		}
		// In case of average  is less than the specified 
		//value determined by developer for more accuracy 
		else if(average<=min)
		{
			//Execute Cooling Mode decision
			OUTPUT_MODULE_OFF(PORTB,5);  //RESET cooling Element
			OUTPUT_MODULE_ON(PORTB,6);  //SET Heating Element
			TOGGLe_BIT(PORTB,4);   // Toggle Heating Element LED
			_delay_ms(700);    //Blink this Led each 1 second .
			}
				
	//For more Safety ,In case of non_executing any
	//statements of each other .
	
			else
			{
			//	Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		// the final else if shall be followed by an else statement.
		//  In the case of a simple if statement then the else statement need not be included.
		//   The requirement for a final else statement is defensive programming.
     // Implement any instruction rather than for updates
			}
	}
				
	//For more Safety ,In case of non_executing any
	//statements of each other .
	
	else
	{
		//Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		// the final else if shall be followed by an else statement.
		//  In the case of a simple if statement then the else statement need not be included.
		//   The requirement for a final else statement is defensive programming.
     // Implement any instruction rather than for updates
		
	}
	}

//Deceleration about the Driver function
 //that control in Activate or disactivate 
 //the all layers of system.

void on_off_mode(void)
{
	// In case of user pressed ON/OFF Button and 
	//must the flag to be 0 that proved the Electric 
	//water Heater is in OFF MODE for more accuracy 
	if(INPUT_BIT(PINB,1) && flag==0)
	{
		//SET Flag by 1
		flag=1;
		//Start_Mode is not
		//Mandatory,But indicates state of flag   
		Start_Mode=flag;
		
		//According to requirements
		//• Specifications –ON/OFF Behavior
		//1. If power is connected to the heater,the electric water heater is in OFF state.
		//2. If the “ON/OFF” button is released and the electric water heater is in OFF state,
		//the electric water heater goes to ON state.
		//3. If the “ON/OFF” button is released and the electric water heater is in ON state,
		//the electric water heater goes to OFF state.
		//4. In the OFF state, all display should be turned OFF.
	
		while(INPUT_BIT(PINB,1));
	}
	// In case of user pressed ON/OFF Button and 
	//must the flag to be 1 that proved the Electric 
	//water Heater is in ON MODE for more accuracy 
	else if(INPUT_BIT(PINB,1) && flag==1)
	{
		// According to Specifications –ON/OFF Behavior.3 
		while(INPUT_BIT(PINB,1));
		//RESET Flag by 0
		flag=0;
		
		//Execute the sleep Mode Function to  
		//Reset all Elements.
		
		OFF_MODE();
		}
				
	//For more Safety ,In case of non_executing any
	//statements of each other .
	
		else
		{
			//Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		// the final else if shall be followed by an else statement.
		 // In the case of a simple if statement then the else statement need not be included.
		 //  The requirement for a final else statement is defensive programming.
		 
     // Implement any instruction rather than for updates
		}
}


//According to requirements, Specifications –Seven Segments.1|2
//"1. Seven segment by defaults how the current water temperature
// or the set temperature.
//2. By default, the 2 seven segment display are show the 
//current water temperature."

void current_water_temperature(void)
{
	//SET seven segments powering
	on_off_7_segment(1);
	//Convert from Temperature reading value into the 
	//hexa_decimal value to be readable for user as 
	//meaningful value
	PORTD=decimal_to_bcd(x);
	}
	
	
	// The function that controlling the powering
	// of seven segments according to requirements.
	
void on_off_7_segment(u8 Mode)
{ 
	
	//In case of developer Set the Parameter of
//	This Function by 1 .
	
	if(Mode==1)
	{
		//SET the seven_Segments that added to it 
		//P_Mosfet .
		
		OUTPUT_MODULE_OFF(PORTB,0);
		OUTPUT_MODULE_OFF(PORTB,7);
	}
	
//	In case of developer Reset the Parameter of
	//This Function by 0 .
	
	else if(Mode==0)
	{
		//RESET the seven_Segments that added to it 
		//P_Mosfet .
		
		OUTPUT_MODULE_ON(PORTB,0);
		OUTPUT_MODULE_ON(PORTB,7);
	}
	
	
	//For more Safety ,In case of non_executing any
	//statements of each other .
	
	else
	{
		//Rule 15.7 in Misra rules applies whenever an if statement is followed by one or more else if statements;
		 //the final else if shall be followed by an else statement.
		 // In the case of a simple if statement then the else statement need not be included.
		 //  The requirement for a final else statement is defensive programming.
		   
     // Implement any instruction rather than for updates
		}
	}


//The Driver function
//of Electric water Heater device run ,as
//integration to all of layers is done in
//This function.
//so we named it a system layer

void ON_MODE_Process (void)
{
	
	//While The Electric water Heater set;
	//Execute The System.
	
	while(flag==1)
	{
		//According to requirements, Specifications –Seven Segments.1|2
		current_water_temperature();
		
		
		//control in activation of Elements on
		//Electric water Heater according
		//to the requirements "Specifications
		//–Heating/Cooling Elements"
		//of setting temperature,
		//Fluctions.
		
		ELEMENTS();
		
		//waiting until user pressed ON/OFF Button.
		//To disactivate the Electric water Heater.
		on_off_mode();
		
		
		//In case user press upper or lower buttons
		
		if(((INPUT_BIT(PINB,3) || INPUT_BIT(PINB,2))))
		{
			//Execute the setting temperature Mode.
			
			//while counter does not exceeded 5 second  
		    //and For more safety must have evidence that
			//Electric water Heater is activate.
			
			while( counter_for_Timer<10 &&flag==1 ) 
			{
		//Execute the setting temperature Mode in absence of 
	//	pressing both setting buttons.
		
		
		//First___half____cycle
		
		
	//SET the powering of seven segments .
              on_off_7_segment(1);
			  
			//  permit user to control setting Mode
			//  by setting the temperature according to
			//  raise,lower temperature in
			//  the Electric water Heater.
			  
				setting_temp();
			//control in activation of Elements on
			//	Electric water Heater according
				//to the requirements "Specifications
				//–Heating/Cooling Elements"
			//	of setting temperature,
				//Fluctions.
				ELEMENTS();
				//waiting until user pressed ON/OFF Button.
				//To disactivate the Electric water Heater.
				on_off_mode();
				//per half cycle increment count by 1
				counter_for_Timer++;
				
				// Second___half____cycle
				
				//SET the powering of seven segments.
				//Toggle it seven segments is from requirements of specifications.
				on_off_7_segment(0);
				//Setting temperature Mode again
				setting_temp();
				//Controlling Elements again
				ELEMENTS();
				//waiting until user pressed ON/OFF Button.
				//To disactivate the Electric water Heater.
				on_off_mode();
				//per half cycle increment count by 1
				counter_for_Timer++;
				}
				//After terminates the scope and the setting_tempereture mode is Exited.
				//return The counter_for_Timer to its original initialization "0"
			counter_for_Timer=0;
		}
	}
}


//Make the system in sleep Mode
	//	Disabling all of system layer by
		//calling it.
void OFF_MODE(void)
{

	OUTPUT_MODULE_OFF(PORTB,5);  //RESET Cooling Element
	OUTPUT_MODULE_OFF(PORTB,6); //RESET Heating Element
	OUTPUT_MODULE_OFF(PORTB,4); //RESET Heating Element LED
	on_off_7_segment(0); //Powering OFF seven segments
	
}




*/