/*
 * UART_Program.c
 *
 * Created: 7/26/2023 6:05:41 PM
 *  Author: Omar
 */ 

#include "UART_Configuration.h"
#include "UART_Interface.h"
#include "UART_Private.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

void vidUART_Init(u8 u8Parity, u8 u8StopBit)
{
	//Enable or disable Transmission / Reception
	ASSIGN_BIT(UCSRB, 4, UART_REC);
	ASSIGN_BIT(UCSRB, 3, UART_TRANS);
	
	//Enable or disable Transmission / Reception interrupt
	ASSIGN_BIT(UCSRB, 7, UART_REC);
	ASSIGN_BIT(UCSRB, 6, UART_TRANS);

	//Assign size to be 1-Byte
	ASSIGN_BIT(UCSRC, 7, 1);
	ASSIGN_BIT(UCSRC, 1, 1);
	ASSIGN_BIT(UCSRC, 2, 1);
	
	//Assign mode to Asynchronous
	ASSIGN_BIT(UCSRC, 6, 0);
	
	//Assign Parity mode
	UCSRC &= u8Parity;
	
	//Assign stop bit
	ASSIGN_BIT(UCSRC, 3, u8StopBit);
	
	//Assign baud rate
	u16 Baud = 0x0FFF;
	Baud &= UART_Baud_Rate_UBRR;
	Baud |= (0x000F<<12); 
	
	ASSIGN_BIT(UCSRC, 7, 0);
	UBRRH |= 0x0FFF;
	UBRRH &= Baud;	
}

void vidUART_Send(u8 u8UARTData)
{
	//Check the data register is empty 
	while (READ_BIT(UCSRA,5) != 1);
	//Start sending data by putting it in data register
	UDR = u8UARTData;
	
}


u8 u8UART_Rec()
{
	//Check that data register has received new data 
	while (READ_BIT(UCSRA,7) != 1);
	//Return data 
	return (UDR >> 8);
}