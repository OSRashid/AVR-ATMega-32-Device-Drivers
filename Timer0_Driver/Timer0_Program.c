/*
 * Timer_Program.c
 *
 * Created: 7/20/2023 11:42:26 PM
 *  Author: Omar
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"

#include "Timer0_Interface.h"
#include "Timer0_Private.h"
#include "Timer0_Configuration.h"

// Get timer value
u8 Tim0_vidGetTimVal(void)
{
	return TCNT0;
}

// Set timer value
void Tim0_vidSetTimVal(u8 u8TimVal)
{
	TCNT0 = u8TimVal;
}

// Timer initiation function
void Tim0_vidInit(u8 u8Mode)
{
	// Assigning Mode
	switch(u8Mode)
	{
		case 0:
			CLR_BIT(TCCR0,6);
			CLR_BIT(TCCR0,3);
			break;
		case 1:
			SET_BIT(TCCR0,6);
			SET_BIT(TCCR0,3);
			
		default:
			//Wrong input
			break;
	}

}

// Stop the timer
void Tim0_vidTimStop(void)
{
	TCCR0 &= ~(0x07);
}

// Generate delay function in milliseconds
void Tim0_vidDelay_MS(u8 u8MS_Delay, u8 u8PreScaler)
{
	//initializing overflows counter
	u32 u32OverflowsCounter = 0;
	
	// Calculating delays and Timer initial value
	u8 u8PSValue;
	switch(u8PreScaler)
	{
		case 1:
			u8PSValue = 1;
		case 2:
			u8PSValue = 8;		
		case 3:
			u8PSValue = 54;		
		case 4:
			u8PSValue = 256;		
		case 5:
			u8PSValue = 1024;
	}
	
	u8 u8T_Tick = 1/(UC_F_CPU/u8PSValue);  // time of each tick
	u8 u8T_MaxDelay = u8T_Tick * (2^8); // maximum capacity of each overflow
	u8T_MaxDelay /= 1000;	//get max delay in Milliseconds
	
	u8 Tim0_NumOverflows = (u8MS_Delay + u8T_MaxDelay -1) / u8T_MaxDelay ;		//Getting the ceil() of T_delay/T_maxDelay
	
	// Add initial value to the timer counter
	u8 Tim0_initValue = (2^8) - (u8MS_Delay/(u8T_Tick/1000))/Tim0_NumOverflows;
	Tim0_vidSetTimVal(Tim0_initValue);
	
	//Timer start
	// Assigning Pre-scaler
	TCCR0 &= ~(0x07);			//clearing first two bits
	TCCR0 |= u8PreScaler;
	
	while(u32OverflowsCounter < Tim0_NumOverflows)
	{
		//Polling the overflow flag
		while (READ_BIT(TIFR,0) == 0);
		
		//Reset the Overflow flag
		SET_BIT(TIFR,0);
		
		//Set the initial value
		Tim0_vidSetTimVal(Tim0_initValue);
		
		//Incrementing the overflows counter
		u32OverflowsCounter++;
	}
	u32OverflowsCounter = 0;
	Tim0_vidTimStop();

}

// Generate PWM with a certain duty cycle
void Tim0_vidPWMStart(u8 u8DutyCycle, u8 u8PreScaler)
{
	// Set the PWM at non-inverting mode
	CLR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
	
	// Add the corresponding value of the duty cycle to OCR Register
	u8 u8DutyValue = (u8DutyCycle/100) * 255;
	OCR0 = u8DutyValue;
	
	// Setting the corresponding pin direction to op
	DIO_vidSetPinDir(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);
	
	// Setting Pre-scaler and staring operation
	TCCR0 &= ~(0x07);			//clearing first two bits
	TCCR0 |= u8PreScaler;
}

