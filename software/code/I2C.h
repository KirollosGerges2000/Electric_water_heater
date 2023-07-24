/*
 * I2C.h
 *
 * Created: 7/24/2023 3:22:50 PM
 * Author : Kirollos Gerges Asaad
 */ 

#ifndef I2C_H_
#define I2C_H_
 /*I2C Prototypes*/
 void I2C_Init();
  uint8_t I2C_Start(char Write_address);
  uint8_t I2C_Repeated_Start(char read_address);
   char I2C_Read_Ack();
    char I2C_Read_Nack();
	  uint8_t I2C_Write (u8 data);
	void I2C_Stop();
	void hex_to_ascii (u8 value);
	 char decimal_to_bcd(u8 value);
	u8 Bcd_to_decimal ();
	#endif // _DEBUG