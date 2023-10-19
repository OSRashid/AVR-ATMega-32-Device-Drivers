/*
 * I2C_Private.h
 *
 * Created: 7/31/2023 11:15:11 AM
 *  Author: Omar
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define TWBR	*((volatile u8*)0x20)
#define TWCR	*((volatile u8*)0x56)
#define TWSR	*((volatile u8*)0x21)
#define TWDR	*((volatile u8*)0x23)
#define TWAR	*((volatile u8*)0x22)


#endif /* I2C_PRIVATE_H_ */