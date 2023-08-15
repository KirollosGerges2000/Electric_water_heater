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
#include "Global variables.h"
#include "MACROS.h"
#include "STD_TYPES.h"
#include "Initialization variables.h"
#include "Prototypes.h"
#include "I2C.h"  //7l mashaklik m3 2linker 
#include "ADC.h" 
#include "interrupt.h"

GLOBAL_VARIABLES_H;
int main(void)
{
	DATA_DIRECTION_REGISTER_H;
	INITIALIZATION_VARIABLES_H;
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

