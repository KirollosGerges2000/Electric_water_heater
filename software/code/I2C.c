/*
 * I2C.c
 *
 * Created: 7/24/2023 1:24:50 PM
 * Author : Kirollos Gerges Asaad
 */ 
#include "I2C.h"
/*I2C initialization function*/
 void I2C_Init()   
 {
 	TWSR=0;
	 /*Get Bit rate register value by formula */
	 TWBR =((F_CPU/100000)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))));
 }
 
 /*I2C start function*/
 uint8_t I2C_Start(char Write_address)   
 {
	 /*Enable TWI, generate start condition and clear interrupt flag*/
	TWCR =(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	/*wait until TWI finish its job*/
	while(!(TWCR & (1<<TWINT)));
	TWDR =Write_address;  //if finish it job ; write SLA,W in Data register.
	TWCR = (1<<TWINT)|(1<<TWEN); // Enable TWI , disable interrupt flag.
	/*wait until TWI finish its job*/ 
	while(!(TWCR & (1<<TWINT)));
 }
 
 uint8_t I2C_Repeated_Start(char read_address)
 {
	  /*Enable TWI, generate start condition and clear interrupt flag*/
	  TWCR =(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	  /*wait until TWI finish its job*/
	  while(!(TWCR & (1<<TWINT)));
	  TWDR =read_address;  //if finish it job ; write SLA,W in Data register.
	  TWCR = (1<<TWINT)|(1<<TWEN); // Enable TWI , disable interrupt flag.
	  /*wait until TWI finish its job*/
	  while(!(TWCR & (1<<TWINT)));
 }
 
 /*I2c read Acknowledgment function */
 char I2C_Read_Ack()
 {
	 /*Clear TWINT Flag , Enable Acknowledge Bit ,TWI Bit */
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while(!(TWCR&(1<<TWINT)));// wait until TWI finish its job
	return TWDR;   //return Received data 
 }
 
  /*I2c read non_Acknowledgment function */
 char I2C_Read_Nack()
 {
	 /*Clear TWINT Flag , TWI Bit */
	 TWCR=(1<<TWEN)|(1<<TWINT);
	 while(!(TWCR&(1<<TWINT))); // wait until TWI finish its job
	 return TWDR; //return Received data 
	 }
	 
	 /* I2C write function */
	 uint8_t I2C_Write (char data)
	 {
		 /*copy data in TWI data register*/
		 TWDR= decimal_to_bcd(data);
		  /*Clear TWINT Flag ,Enable TWEN Bit */
		 TWCR=(1<<TWEN)|(1<<TWINT);
		 while(!(TWCR&(1<<TWINT))); // wait until TWI finish its job "Write operation"
		 }
		 /*I2C Stop function */
		 void I2C_Stop()
		 {  
			 /* Clear TWINT Flag , Enable TWI Bit , Generate stop condition */                                  
			 TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
			 while(TWCR & (1&TWSTO));  // wait until stop condition execution 
		 }
		 
		 /* Converting from Hexa_decimal into ASCII character function*/
		 void hex_to_ascii (u8 value)
		 {
			 u8 bcd;
			 bcd = value;
			 bcd=bcd &0xf0;
			 bcd=bcd>>4;
			 bcd=bcd|0x30;
			 /*the function out that message sent to it */
			 bcd =value;
			 bcd=bcd &0x0f;
			 bcd=bcd|0x30;
			  /*the function out that message sent to it */
			 }
			 /* converting from decimal  to Binary_coded_decimal*/
			 char decimal_to_bcd(u8 value)
			 {
				 u8 msb,lsb,hex;
				 msb=value/10;
				 lsb=value%10;
				 hex=((msb<<4)+lsb);
				 return hex;
			 }