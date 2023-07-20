#include <avr/interrupt.h>
u8 g_Interrupt_Flag = 0;

ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	TEMPERature_sensor();
	TCNT1 = 63974;   // for 1 sec at 16 MHz

	
	
}

void INT_interrupt (void)
{
	TCNT1 = 63974;   // for 1 sec at 16 MHz
	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);;  // Timer mode with 1024 pre_scaler
	TIMSK = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}