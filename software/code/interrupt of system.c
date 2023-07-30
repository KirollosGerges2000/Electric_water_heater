#include "MACROS.h"  //macros library
extern unsigned char g_Interrupt_Flag = 0;
/*Interrupt service vector  must be active , when interrupt declared*/ 
ISR(INT0_vect)
{
	g_Interrupt_Flag = 1;
	interupt_function();
}
// External INT0 enable and configuration function
void INT0_Init(void)
{
		SREG  &= ~(1<<7);      // Disable interrupts by clearing I-bit
		SREG  |= (1<<7);       // Enable interrupts by setting I-bit
      
	DDRD  &= (~(1<<2));  // Configure INT0/PD2 as input pin
	PORTD |= (1<<2);     // Enable the internal pull up resistor at PD2 pin
	GICR  |= (1<<6);    // Enable external interrupt pin INT0
	// Trigger INT0 with the rising edge
	MCUCR |= (1<<6);
	MCUCR |= (1<<7);
}

//The process of interrupt in this project  
void interupt_function(void)
{
	if(g_Interrupt_Flag ==1)
	{
		
		disablegreenLED();
		yellow_traffic();
		operatingredLED();
		TRAFFIC_OFF_FOR_PEOPLE();
		operatinggreenLED();
		g_Interrupt_Flag = 0;
	}
}
//function for alert car drivers that this a time for people passing
void yellow_traffic (void)
{
	u8 counter=4;
	while(counter!=0)
{
	PORTC = 0x00;
	counter--;
	PORTA=counter;
	if(counter<=4)
	{
		disablegreenLED();
		operatingyellowLED();
		BUZZER();
		
	}
_delay_ms(810); //delay time for counting
}
disableyellowLED();
operatingredLED();
}
