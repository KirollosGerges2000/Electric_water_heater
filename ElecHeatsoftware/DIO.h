/*DIO.h 
Header File
Author:Kirollos Gerges */

/*The #ifndef directive is one of the widely used used directives in C.
 It allows conditional compilations. During the compilation process.
 the preprocessor is supposed to determine if any provided macros exist before any subsequent code is included.*/
#ifndef DIO_H
/*The #define DIO_H creates a macro, which is the association of an identifier or parameterized identifier with a token string*/
#define DIO_H

/*defines to creation Input/Output Functions that is used in Data Direction registers for more readability*/ 
#define INPUT_MODULE(DATA_DIRECTION_REGISTER,BIT_N)  DATA_DIRECTION_REGISTER&=(~(1<<BIT_N)); 
#define OUTPUT_MODULE(DATA_DIRECTION_REGISTER,BIT_N)  DATA_DIRECTION_REGISTER|=1<<BIT_N;  

#endif