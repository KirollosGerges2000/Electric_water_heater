#include <avr/interrupt.h>
u8 g_Interrupt_Flag = 0;
ISR(INT0_vect)
{
	g_Interrupt_Flag = 1;
	TEMPERature_sensor();
	g_Interrupt_Flag = 0;
}

