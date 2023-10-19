/*
 * ADC_Interface.h
 *
 * Created: 7/24/2023 1:55:58 PM
 *  Author: Omar
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "STD_TYPES.h"

//ADC interrupt definitions
#define ADC_INTRPT	__vector_17
//ADC ISR definition
#define ISR(x)	void x(void) __attribute__((signal, used));\
void x(void)


//ADC channel definitions
#define ADC_ch0	0
#define ADC_ch1	1	
#define ADC_ch2	2
#define ADC_ch3	3
#define ADC_ch4	4
#define ADC_ch5	5
#define ADC_ch6	6
#define ADC_ch7	7

//ADC pre-scalar definitions
#define ADC_PS_2	0x02	//divide the XTAL by 2
#define ADC_PS_4	0x03	//divide the XTAL by 4
#define ADC_PS_8	0x04	//divide the XTAL by 8
#define ADC_PS_16	0x05	//divide the XTAL by 16
#define ADC_PS_32	0x06	//divide the XTAL by 32
#define ADC_PS_64	0x07	//divide the XTAL by 64
#define ADC_PS_128	0x08	//divide the XTAL by 128

//ADC reference selection definitions
#define	ADC_AREF 0
#define ADC_AVCC 1


//ADC initiation function
void ADC_vidInit(u8 u8VRef , u8 u8PreScaler );
//ADC Start Conversion function in case of polling
u16 ADC_u16Conv(u8 u8Channel);
//ADC Start Conversion function in case of interrupt
void ADC_vidConvINT(u8 u8Channel);





#endif /* ADC_INTERFACE_H_ */