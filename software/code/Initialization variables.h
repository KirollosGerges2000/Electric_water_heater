#ifndef initialization_variables
#define INITIALIZATION_VARIABLES_H initialization_variables()
void initialization_variables(void);
#endif



void initialization_variables(void)
{
	INT_interrupt();  /* initialize internally interrupt Timer1*/
ADC_init(); /* initialize ADC driver */

/* deceleration, initialize 7_segments by 60*/
PORTD=0x60;

/* initialization cooling fan,heater ,heater LED to be off */
OUTPUT_MODULE_OFF(PORTB,4);
OUTPUT_MODULE_OFF(PORTB,5);
OUTPUT_MODULE_OFF(PORTB,6);
// initialization Enables of 7 segments to be off as active low
OUTPUT_MODULE_ON(PORTB,0);
OUTPUT_MODULE_ON(PORTA,7);

}

