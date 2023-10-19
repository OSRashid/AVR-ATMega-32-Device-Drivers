/*
 * I2C_Program.c
 *
 * Created: 7/31/2023 11:15:33 AM
 *  Author: Omar
 */ 

#include "I2C_Configuration.h"
#include "I2C_Private.h"
#include "I2C_Interface.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"


// I2C initiation function
void vidI2C_Init(u8 u8PreScaler)
{
	// Assign bitrate
	TWBR = I2C_BitRate;
	
	// Assign address
	TWAR = I2C_Address;
	
	// Assign general call recognition
	ASSIGN_BIT(TWAR,1,I2C_GCR);
	
	// Assign I2C interrupt enable/disable
	ASSIGN_BIT(TWCR, 0, I2C_Int);
	
	// Enable Acknowledge bit
	SET_BIT(TWCR, 6);
	
	// Assigning the prescaler
	CLR_BIT(TWDR,0);
	CLR_BIT(TWDR,1);
	TWSR |= (0 & u8PreScaler);
	
	// Enable the I2C
	SET_BIT(TWCR , 2);
	
}

// I2C send byte
Status statusI2C_Init(u8 u8Address, u8 u8Data)
{
	// Put address of device + write in data register
	TWDR = u8Address<<1;
	
	// Start condition to initiate transmission
	SET_BIT(TWCR, 5);
	
	// Wait till the sending start operation finish
	while (READ_BIT(TWCR, 7) != 0);
	SET_BIT(TWCR, 5)
	
	// Clear the interrupt flag
	SET_BIT(TWCR, 7);
	
	// Wait till bus master status granted
	while ((TWSR & 0b11111100) != 0x08 );

	// Clear the interrupt flag
	SET_BIT(TWCR, 7);
	
	// Wait till the sending address and receiving ack operation finish
	while (READ_BIT(TWCR,7) == 0);
	
	
	// Put data to be sent in data register
	TWDR = u8Data;
	
	// wait till the success of receiving ack after address sent
	while ((TWSR & 0b11111100) != 0x18)
	{
		// if no ack received return no ack status
		if ((TWSR & 0b11111100) != 0x20)
			return NoAck;
	}
	
	// Wait till the data sent and ack is received
	while (READ_BIT(TWCR, 7) == 0);
	
	// Clear the interrupt flag
	SET_BIT(TWCR, 7);
	
	// wait till the success of receiving ack after data sent
	while ((TWSR & 0b11111100) != 0x28 )
	{
		// if no ack received return no ack status
		if ((TWSR & 0b11111100) != 0x30)
			return NoAck;
	}
	
	// Send stop condition
	SET_BIT(TWCR, 4);
	
	//return success status
	return Success;
	
}



// I2C receive byte
Status statusI2C_Receive(u8 u8Address)
{
	// Put address of device + read in data register
	TWDR = ((u8Address<<1) & 0x01);
	
	// Start condition to initiate transmission
	SET_BIT(TWCR, 5);
	
	// Wait till the sending start operation finish
	while (READ_BIT(TWCR, 7) == 0);
	SET_BIT(TWCR, 5)
	
	// Clear the interrupt flag
	SET_BIT(TWCR, 7);
	
	// Wait till bus master status granted
	while ((TWSR & 0b11111100) != 0x08 );

	// Clear the interrupt flag
	SET_BIT(TWCR, 7);
	
	// Wait till the sending address and receiving ack operation finish
	while (READ_BIT(TWCR,7) == 0);
	
	
	// wait till the success of receiving ack after address sent or NoAck or lost arbitration 
	while ((TWSR & 0b11111100) != 0x18)
	{
		// if no ack received return no ack status
		if ((TWSR & 0b11111100) != 0x48)
			return NoAck;
		
		// if arbitration lost return return LostArb status
		if ((TWSR & 0b11111100) != 0x38)
			return LostArb;
	}
	
	// Wait till the has been received to the data register
	while (READ_BIT(TWCR, 7) == 0);
	
	// Clear the interrupt flag
	SET_BIT(TWCR, 7);
	
	// wait till the success of receiving data
	while (((TWSR & 0b11111100) != 0x58) | ((TWSR & 0b11111100) != 0x50) );
	
	// Send stop condition
	SET_BIT(TWCR, 4);
	
	//return success status and data can be read from data bus
	return Success;
}