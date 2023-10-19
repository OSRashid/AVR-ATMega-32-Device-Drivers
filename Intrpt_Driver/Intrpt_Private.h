/*
 * Intrpt_Private.h
 *
 * Created: 7/22/2023 12:40:19 AM
 *  Author: Omar
 */ 


#ifndef INTRPT_PRIVATE_H_
#define INTRPT_PRIVATE_H_

#define	SREG	*((volatile u8*)0x5F) 
#define	MCUCR	*((volatile u8*)0x55) 
#define	GICR	*((volatile u8*)0x5B) 
#define MCUCSR	*((volatile u8*)0x54)
#define GIFR	*((volatile u8*)0x5A)

#endif /* INTRPT_PRIVATE_H_ */