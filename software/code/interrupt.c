ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	TCNT1 = 65380;  // for 100 ms at 16 MHz  in Bin "1111 1111 0110 0100" , in Hexa_decimal "FF64"
		Temperature_reading();  //read temperature each 100 ms 
	
		}



void INT_interrupt (void)
{
	TCNT1 = 65380;   // for 100 ms at 16 MHz  in Bin "1111 1111 0110 0100" , in Hexa_decimal "FF64" 
	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);;  // Timer mode with 1024 pre_scaler
	TIMSK = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
	
}


