//Macros.h Library
//Author:Kirollos Gerges 

/*The #ifndef directive is one of the widely used used directives in C.
 It allows conditional compilations. During the compilation process.
 the preprocessor is supposed to determine if any provided macros exist before any subsequent code is included.*/
#ifndef _MACROS_H
/*The #define _MACROS_H creates a macro, which is the association of an identifier or parameterized identifier with a token string*/
#define _MACROS_H

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT_N) REG|=(1<<BIT_N)

/* Clear a certain bit in any register */
#define CLR_BIT(REG,BIT_N) REG&=~(1<<BIT_N)

/* Toggle a certain bit in any register */
#define TOGGLe_BIT(REG,BIT_N) REG=REG^(1<<BIT_N) 

/* Read a certain bit in any register */
#define READBIT_BIT(REG,BIT_N) (REG>>BIT_N)&1

/* read an input signal from sensors or button of a certain bit in any register */
#define INPUT_BIT(PIN_SYMBOL,BIT_N)  PIN_SYMBOL&(1<<BIT_N)  

/* In case of no_reading an input signal from sensors or button of a certain bit in any register */
#define NOT_INPUT_BIT(PIN_SYMBOL,BIT_N)  ~(PIN_SYMBOL&(1<<BIT_N))  

/* Activate this module of a certain bit in any register */
#define OUTPUT_MODULE_ON(PORT_SYMBOL,BIT_N)   PORT_SYMBOL|=1<<BIT_N 

/* Disable this module of a certain bit in any register */
#define OUTPUT_MODULE_OFF(PORT_SYMBOL,BIT_N)   PORT_SYMBOL&=~(1<<BIT_N) 

#endif