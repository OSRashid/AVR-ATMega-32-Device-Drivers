/*
 * ADC_Program.c
 *
 * Created: 7/24/2023 1:56:19 PM
 *  Author: Omar
 */ 

#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_private.h"
#include "ADC_Configuration.h"


//ADC initiation function
void ADC_vidInit(u8 u8VRef , u8 u8PreScaler)
{
	
	//Setting Vref
	switch(u8VRef)
	{
	case 0: CLR_BIT(ADMUX , 6); break;
	case 1: SET_BIT(ADMUX , 6); break;
	default: break;
	}
	
	//Enable or Disable interrupt
	switch(ADC_INT_Enable)
	{
	case 0: CLR_BIT(ADCSRA , 3); break;
	case 1: SET_BIT(ADCSRA , 3); break;
	default: break;
	}
	
	//Setting Pre-scaler for ADC frequency
	ADCSRA &= ~(0x07);
	ADCSRA |= u8PreScaler; 
	
}


//ADC Start Conversion function in case of polling
u16 ADC_u16Conv(u8 u8Channel)
{
	// ADC channel selection
	ADMUX &= ~(0x0F);
	ADMUX |= u8Channel;
	
	//left adjust
	CLR_BIT(ADMUX, 5);
	
	// ADC enable 
	SET_BIT(ADCSRA, 7);
	
	// ADC start conversion
	SET_BIT(ADCSRA, 6);
	
	// Wait for conversion to complete
	while(READ_BIT(ADCSRA , 4) == 0);
	
	//storing and returning result
	u16 Result = 0;
	Result |= (u16)ADCL;
	Result |= (u16)(ADCH<<8);
	return Result;
	
}


//ADC Start Conversion function in case of interrupt
void ADC_vidConvINT(u8 u8Channel)
{
		// ADC channel selection
		ADMUX &= ~(0x0F);
		ADMUX |= u8Channel;
		
		//left adjust
		CLR_BIT(ADMUX, 5);
		
		// ADC enable
		SET_BIT(ADCSRA, 7);
		
		// ADC start conversion
		SET_BIT(ADCSRA, 6);
}