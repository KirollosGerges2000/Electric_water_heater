/*
 * Electric Heater.c
 *
 * Created: 8/14/2023 6:15:30 PM
 * Author : Kirollos
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "ADC.h"
#include "MACROS.h"
#include "DIO.h"
#include "Global variables.h"
#include "STD_TYPES.h"
#include "Data Direction registers.h"
#include "initialization variables.h"
#include "I2C.h"

int main(void)
{
	DATA_DIRECTION_REGISTER_H;
initialization_variables();
    while (1) 
    {
    }
}

