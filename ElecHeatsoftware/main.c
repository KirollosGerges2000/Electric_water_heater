/*
 * ElecHeatsoftware.c
 *
 * Created: 8/15/2023 12:17:29 PM
 * Author : Kirollos
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include <stdarg.h>
#include <stdlib.h>
#include "DIO.h"
#include "Data Direction registers.h"
#include "MACROS.h"
#include "STD_TYPES.h"
#include "Initialization variables.h"
#include "Prototypes.h"
#include "I2C.h"  //7l mashaklik m3 2linker 
#include "ADC.h" //7l mashaklik m3 2linker 
#include "interrupt.h"











int main(void)
{
	DATA_DIRECTION_REGISTER();
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
}









