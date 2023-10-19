/*
 * SPI_Interface.h
 *
 * Created: 7/29/2023 1:45:22 PM
 *  Author: Omar
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "STD_TYPES.h"


// ADC interrupt definitions
#define ADC_INTRPT __vector_17
//ISR function definition
#define ISR(x)	void x(void) __attribute__((signal, used));\
void x(void)


/******************************************************/
// Master/slave definitions 
#define ADC_Master 1
#define ADC_Slave 0


/******************************************************/
// Pre-Scaler definitions

#define ADC_PreScaler_2		0
#define ADC_PreScaler_4		1
#define ADC_PreScaler_8		2
#define ADC_PreScaler_16	3
#define ADC_PreScaler_32	4
#define ADC_PreScaler_64	5
#define ADC_PreScaler_128	6


/******************************************************/
//ADC functions
//ADC initiation function
void vidADC_Init(u8 u8MstrSlv, u8 u8PreScaler);
//ADC send byte function
void vidADC_Send(u8 u8Data);
//ADC receive byte function
u8 u8ADC_Rec();



#endif /* SPI_INTERFACE_H_ */