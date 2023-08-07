#include "Electric water heater Libraries .h"
#include "Global variables.h"
#include "Data Direction registers.h"
#include "Initialization variables.h"
#include "Prototypes.h"
GLOBAL_VARIABLES_H;
PROTOTYPES_H;
	 /*the main process*/
 int  main (void)
	{	 	
	DATA_DIRECTION_REGISTERS_H;
INITIALIZATION_VARIABLES_H;
		//super loop for repeating this process infinitely
		while(1)  
		{
			 on_off_mode();
			 if(Start_Mode)
			 {
				 ON_MODE_Process();
			}
		
		}
		return 0;
	}

