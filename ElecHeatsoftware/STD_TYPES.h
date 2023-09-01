/*STD_TYPES.h
Header File
Author:Kirollos Gerges */

/*The #define _STD_TYPES_H  creates a macro, which is the association of an identifier or parameterized identifier with a token string*/
#define _STD_TYPES_H

/*
The @typedef tag is useful for documenting custom types, particularly if you wish to refer to them repeatedly. 
These types can then be used within other tags expecting a type, such as @type or @param.
 Use the @callback tag to document the type of callback functions.
*/

 /*provide unsigned char with a "u8" that represent unsigned_8_bits*/
typedef unsigned char     u8;
 /*provide unsigned short with a "u16" that represent unsigned_16_bits*/
typedef unsigned short    u16;
 /*provide unsigned long with a "u32" that represent unsigned_32_bits*/
typedef unsigned long     u32;
 /*provide unsigned long long with a "u64" that represent unsigned_64_bits*/
typedef unsigned long long   u64;
 /*provide float with a "f32" that represent 32_bits*/
typedef float f32;
 /*provide double with a "f64" that represent 64_bits*/
typedef double f64;
 /*provide signed char with a "s8" that represent signed_8_bits*/
typedef signed char     s8;
 /*provide signed short with a "s16" that represent signed_16_bits*/
typedef signed short    s16;
 /*provide signed long with a "s32" that represent signed_32_bits*/
typedef signed long    s32;
 /*provide signed long long with a "s64" that represent signed_64_bits*/
typedef signed long long    s64;

/*
For int is compiler independent
 C programs are machine-independent which means that you can run 
 the fraction of a code created in C on various machines with none or some machine-specific changes.
  Hence, it provides the functionality of using a single code on multiple systems depending on the requirement.
  But, we use the more standardize id 4 bits depend on compiler 
  so we determine it
  */

/*provide unsigned int with a "uint16" that represent unsigned_16_bits*/
typedef unsigned int  uint16;

 /*provide signed int with a "int16" that represent signed_16_bits*/
typedef signed int   int16;

