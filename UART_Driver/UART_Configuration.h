/*
 * UART_Configuration.h
 *
 * Created: 7/27/2023 1:38:39 AM
 *  Author: Omar
 */ 


#ifndef UART_CONFIGURATION_H_
#define UART_CONFIGURATION_H_


//UART reeceive enable 0 = Disable , 1 = Enable
#define	UART_REC	1

//UART transmit enable 0 = Disable , 1 = Enable
#define	UART_TRANS	1

//define the baud rate of the Trans/Receive "Get it from datasheet"
#define UART_Baud_Rate_UBRR	51

//Receive interrupt enable 0 = Disable , 1 = Enable
#define	REC_INTRPT	0

//Transmit interrupt enable 0 = Disable , 1 = Enable
#define	REC_INTRPT	0




#endif /* UART_CONFIGURATION_H_ */