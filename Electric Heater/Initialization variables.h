#ifndef INITIALIZATION_VARIABLES_H 
#define INITIALIZATION_VARIABLES_H 

/* deceleration, initialize 7_segments by 60*/
#define PORTD 0x60 

/* initialization cooling fan,heater,heater LED to be off */
#define INIT_ENABLE2_7SEGMENT_OFF OUTPUT_MODULE_OFF(PORTB,4)
#define INIT_FAN_OFF OUTPUT_MODULE_OFF(PORTB,5)
#define INIT_HEATER_OFF OUTPUT_MODULE_OFF(PORTB,6)

// initialization Enables of 7 segments to be off as active low
#define INIT_ENABLE1_7SEGMENT_OFF OUTPUT_MODULE_ON(PORTB,0)
#define INIT_ENABLE2_7SEGMENT_OFF OUTPUT_MODULE_ON(PORTA,7)

void initialization_variables(void);
#endif



