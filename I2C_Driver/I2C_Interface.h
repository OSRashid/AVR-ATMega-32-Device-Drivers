/*
 * I2C_Interface.h
 *
 * Created: 7/31/2023 11:14:04 AM
 *  Author: Omar
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
#include "STD_TYPES.h"


// I2C prescaler definitions 
#define I2C_PS_1	0
#define I2C_PS_4	1
#define I2C_PS_16	2
#define I2C_PS_64	3

// Status enum for function returns
typedef enum {
	NoAck = 0,      // Status code 0 represents no acknowledgment received
	Success = 1,    // Status code 1 represents success
	LostArb = 2,	// Status code 2 represent lost arbitration of the bus
}Status;

// I2C initiation function
void vidI2C_Init( u8 u8PreScaler);

// I2C send byte
Status statusI2C_SendByte(u8 u8Address, u8 u8Data);


// I2C receive byte
Status statusI2C_Receive(u8 u8Address);






#endif /* I2C_INTERFACE_H_ */