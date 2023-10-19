/*
 * UART_Interface.h
 *
 * Created: 7/26/2023 6:05:09 PM
 *  Author: Omar
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "STD_TYPES.h"


//UART receive interrupt definition
#define UART_REC_INTRPT		__vector_14
//UART transmit interrupt definition
#define UART_TRANS_INTRPT	__vector_16

//UART ISR definition
#define ISR(x)	void x(void) __attribute__((signal, used));\
void x(void)


/***********************************************/
//UART parity definitions

//values to be ANDed with UCSRC Register directly 
#define UART_Parity_Disabled	0xCF
#define UART_Parity_Reserved	0xDF
#define UART_Parity_Even		0xEF
#define UART_Parity_Odd			0xFF
 
/***********************************************/
//UART stop bit definitions

#define UART_1StopBit	0
#define UART_2StopBit	1


/***********************************************/
//UART functions


//UART initiation function
void vidUART_Init(u8 u8Parity, u8 u8StopBit);
//UART send byte function
void vidUART_Send(u8 u8UARTData);
//UART receive byte function
u8 u8UART_Rec();



#endif /* UART_INTERFACE_H_ */