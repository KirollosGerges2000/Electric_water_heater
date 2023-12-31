/*
 * I2C.c
 *
 * Created: 8/15/2023 12:22:32 PM
 *  Author: Kirollos
 
*/
/*

//IIC Library that contains the  pre_processing definitive and prototypes
#include "I2C.h"




//I2C initialization function
void I2C_Init()
{
// Reset TWSR Register   
TWSR=0;
//Get Bit rate register value by formula 
TWBR =((F_CPU/100000)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1)))));
}


//I2C start function
uint8_t I2C_Start(char Write_address)
{
//Enable TWI, generate start condition and clear interrupt flag
TWCR =(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
//wait until TWI finish its job/
while(!(TWCR & (1<<TWINT)));
TWDR =Write_address;  //if finish it job ; write SLA,W in Data register.
TWCR = (1<<TWINT)|(1<<TWEN); // Enable TWI , disable interrupt flag.
//wait until TWI finish its job
while(!(TWCR & (1<<TWINT)));
return 0;
}


//Function to start again that permit developer to read the data that write it in Start mode
//communication between EEPROM Module and  MCAL                                      
uint8_t I2C_Repeated_Start(char read_address)
{
//Enable TWI, generate start condition and clear interrupt flag
TWCR =(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
//wait until TWI finish its job
while(!(TWCR & (1<<TWINT)));
TWDR =read_address;  //if finish it job ; write SLA,W in Data register.
TWCR = (1<<TWINT)|(1<<TWEN); // Enable TWI , disable interrupt flag.
//wait until TWI finish its job
while(!(TWCR & (1<<TWINT)));
return 0;
}

//I2c read Acknowledgment function 
char I2C_Read_Ack()
{
//Clear TWINT Flag , Enable Acknowledge Bit ,TWI Bit 
TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
while(!(TWCR&(1<<TWINT)));// wait until TWI finish its job
return TWDR;   //return Received data
}

//I2c read non_Acknowledgment function 
char I2C_Read_Nack()
{
//Clear TWINT Flag , TWI Bit 
TWCR=(1<<TWEN)|(1<<TWINT);
while(!(TWCR&(1<<TWINT))); // wait until TWI finish its job
return TWDR; //return Received data
}

// I2C write function 
void I2C_Write (u8 data)
{
//copy data in TWI data register
TWDR = decimal_to_bcd(data);
//Clear TWINT Flag ,Enable TWEN Bit 
TWCR=(1<<TWEN)|(1<<TWINT);
while(!(TWCR&(1<<TWINT))); // wait until TWI finish its job "Write operation"
//return 0;
}

//I2C Stop function 
void I2C_Stop()
{
// Clear TWINT Flag , Enable TWI Bit , Generate stop condition 
TWCR=(1<<TWSTO)|(1<<TWINT)|(1<<TWEN);
while(TWCR & (1&TWSTO));  // wait until stop condition execution
}

// Converting from Hexa_decimal into ASCII character function
void hex_to_ascii (u8 VALUE)
{
u8 bcd;
bcd = VALUE;
bcd=bcd &0xf0;
bcd=bcd>>4;
bcd=bcd|0x30;
//the function out that message sent to it 

bcd =VALUE;
bcd=bcd &0x0f;
bcd=bcd|0x30;
//  PORTD= bcd;
//the function out that message sent to it 
}

//converting from decimal  to Binary_coded_decimal
char decimal_to_bcd(u8 val)
{
//decelerations about msb,lsb,hex variables
u8 msb,lsb,hex;
//Process of converting
msb=val/10;
lsb=val%10;
hex=((msb<<4)+lsb);
return hex;
}

// turns a BCD-encoded byte back into a standard one
u8 Bcd_to_decimal (u8 value)
{
value=TWDR;
//return the BCD_TO_DECIMAL process
return( ((value>>4)*10)+(value &0xF));
}

//Driver Function  that stored data on EEPROM as a parameter then retrieve it by return it stored value.
u8 EEPROM_write_read(u8 stored_data)
{
// Declaration about Data that we will fetching it from EEPROM
u8 data;
//initialize the IIC Protocol
I2C_Init();
//Start IIC protocol with its address"0xA0"
I2C_Start(0xA0);
//Stored the required Data.
I2C_Write(stored_data);
//Restart to read this Data that user stored it @ FIRST
I2C_Repeated_Start(0xA1);
//Retrieve data at this variable .
data=I2C_Read_Nack ();
//Stop COM between Layers.
I2C_Stop();
//return the data that stored From this function.
return data;

}


*/