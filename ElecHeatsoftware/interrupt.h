/*interrupt.h
Header File
Author:Kirollos Gerges */

/*The #ifndef directive is one of the widely used used directives in C.
 It allows conditional compilations. During the compilation process.
 the preprocessor is supposed to determine if any provided macros exist before any subsequent code is included.*/
#ifndef INTERRUPT_H

/*The #define INTERRUPT_H  creates a macro,
 which is the association of an identifier or parameterized identifier with a token string*/
#define INTERRUPT_H 
/*Deceleration of this Function to measure the temperature of water when call it           */
void Temperature_reading(void); 

/*Deceleration of this Function to initialized the internal interrupt Timer1             */
void INT_interrupt (void);
#endif



/* Interrupt service routine that activate each 100ms to read a temperature value */
ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	// for 100 ms at 16 MHz  in Bin "1111 1111 0110 0100" , in Hexa_decimal "FF64"
	TCNT1 = 65380; 
	
	  //read temperature each 100 ms 
		Temperature_reading(); 
	
		}


/*Function to initialized the internal interrupt Timer1                       */
void INT_interrupt (void)
{
	 // for 100 ms at 16 MHz  in Bin "1111 1111 0110 0100" , in Hexa_decimal "FF64" 
	TCNT1 = 65380;  
	//Reset TCCR1A register
	TCCR1A = 0x00; 
	// Timer mode with 1024 pre_scaler
	TCCR1B = (1<<CS10) | (1<<CS12);  
	// Enable timer1 overflow interrupt(TOIE1)
	TIMSK = (1 << TOIE1) ;  
	 // Enable global interrupts by setting global interrupt enable bit in SREG
	sei();        
	}


