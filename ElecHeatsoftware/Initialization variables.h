

//#ifndef INITIALIZATION_VARIABLES_H 
#define INITIALIZATION_VARIABLES_H 

#define Start_Mode 0  //start up the device

 //deceleration, initialize 7_segments by 60
#define PORTD7 OUTPUT_MODULE_OFF(PORTD,7);
#define PORTD6 OUTPUT_MODULE_ON(PORTD,6);
#define PORTD5 OUTPUT_MODULE_ON(PORTD,5);
#define PORTD4 OUTPUT_MODULE_OFF(PORTD,4);
#define PORTD3 OUTPUT_MODULE_OFF(PORTD,3);
#define PORTD2 OUTPUT_MODULE_OFF(PORTD,2);
#define PORTD1 OUTPUT_MODULE_OFF(PORTD,1);
#define PORTD0 OUTPUT_MODULE_OFF(PORTD,0);

 //initialization cooling fan,heater, heater LED to be off 
#define  PORTB4  OUTPUT_MODULE_OFF(PORTB,4);
#define  PORTB5  OUTPUT_MODULE_OFF(PORTB,5);
#define  PORTB6   OUTPUT_MODULE_OFF(PORTB,6);

// initialization Enables of 7 segments to be off as active low
#define  PORTB0     OUTPUT_MODULE_ON(PORTB,0);
#define  PORTB7     OUTPUT_MODULE_ON(PORTB,7);


//#endif

void Init_VARIABLES(void)
{ 
	 //deceleration, initialize 7_segments by 60
PORTD7
PORTD6
PORTD5
PORTD4
PORTD3
PORTD2
PORTD1
PORTD0


//initialization cooling fan,heater, heater LED to be off 
PORTB4
PORTB5
PORTB6

// initialization Enables of 7 segments to be off as active low
PORTB0
PORTB7


}


	


