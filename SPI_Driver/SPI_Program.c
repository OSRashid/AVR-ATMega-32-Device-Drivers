/*
 * SPI_Program.c
 *
 * Created: 7/29/2023 1:46:00 PM
 *  Author: Omar
 */ 

#include "SPI_Configuration.h"
#include "SPI_Interface.h"
#include "SPI_private.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"



void vidADC_Init(u8 u8MstrSlv, u8 u8PreScaler)
{
	switch (u8MstrSlv)
	{
	case 0:	
		// Master/Slave select
		ASSIGN_BIT(SPCR, 4, 0);
		// Make MOSI i/p
		DIO_vidSetPinDir(DIO_PORTD, DIO_PIN5, DIO_INPUT);
		// Make MISO 0/p
		DIO_vidSetPinDir(DIO_PORTD, DIO_PIN6, DIO_OUTPUT);
		// Make SS i/p
		DIO_vidSetPinDir(DIO_PORTD, DIO_PIN4, DIO_INPUT);
		break;
	case 1:
		// Master/Slave select
		ASSIGN_BIT(SPCR, 4, 1);
		// Make MOSI o/p
		DIO_vidSetPinDir(DIO_PORTD, DIO_PIN5, DIO_OUTPUT);
		// Make MISO i/p
		DIO_vidSetPinDir(DIO_PORTD, DIO_PIN6, DIO_INPUT);
		// Make SS o/p & set it high
		DIO_vidSetPinDir(DIO_PORTD, DIO_PIN4, DIO_OUTPUT);
		DIO_vidSetPinVal(DIO_PORTD, DIO_PIN4, DIO_HIGH);
		break;
	default:
		break;
		
	// Set clock prescalar
	}
	switch(u8PreScaler)
	{
		case 0: SET_BIT(SPSR,0); CLR_BIT(SPCR,0); CLR_BIT(SPCR,1); break;
		case 1: CLR_BIT(SPSR,0); CLR_BIT(SPCR,0); CLR_BIT(SPCR,1); break;
		case 2: SET_BIT(SPSR,0); CLR_BIT(SPCR,0); SET_BIT(SPCR,1); break;
		case 3: CLR_BIT(SPSR,0); CLR_BIT(SPCR,0); SET_BIT(SPCR,1); break;
		case 4: SET_BIT(SPSR,0); SET_BIT(SPCR,0); CLR_BIT(SPCR,1); break;
		case 5: SET_BIT(SPSR,0); SET_BIT(SPCR,0); SET_BIT(SPCR,1); break;
		case 6: CLR_BIT(SPSR,0); SET_BIT(SPCR,0); SET_BIT(SPCR,1); break;	
		default: break;
	}
	// ADC Interrupt Enable/Disable
	ASSIGN_BIT(SPCR, 7, ADC_INTRPT_ENABLE);
	// SPI enable
	SET_BIT(SPCR, 6);
	
}


void vidADC_Send(u8 u8Data )
{
	// Set CC to low
	DIO_vidSetPinVal(DIO_PORTD, DIO_PIN4, DIO_LOW);
	// Write data to data register
	SPDR = u8Data;
	// Wait until transmission is over
	while(READ_BIT(SPSR,7) != 1);
	// Flush the interrupt flag
	volatile u8 Flush_Variable = SPSR;
	Flush_Variable = SPDR;
	// Set CC to high 
	DIO_vidSetPinVal(DIO_PORTD, DIO_PIN4, DIO_HIGH);
}


u8 u8ADC_Rec()
{
	// Set dummy value
	SPDR = 0xFF;
	// Wait until transmission is over
	while(READ_BIT(SPSR,7) != 1);
	// Flush the interrupt flag
	u8 Flush_Variable = SPSR;
	Flush_Variable = SPDR;
	// Return Data register
	return Flush_Variable;
		
}
