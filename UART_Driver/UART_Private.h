/*
 * UART_Private.h
 *
 * Created: 7/26/2023 6:05:24 PM
 *  Author: Omar
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define	UDR		*((volatile u16*)0x2C)	
#define	UCSRA	*((volatile u8*)0x2B)	
#define	UCSRB	*((volatile u8*)0x2A)
#define	UCSRC	*((volatile u8*)0x40)
#define	UBRRH	*((volatile u16*)0x40)


#endif /* UART_PRIVATE_H_ */