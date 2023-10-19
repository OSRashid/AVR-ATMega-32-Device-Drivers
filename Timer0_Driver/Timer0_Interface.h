/*
 * Timer_Interface.h
 *
 * Created: 7/20/2023 11:41:54 PM
 *  Author: Omar
 */ 

//This is the driver of Timer0 of the AVR_ATMega32

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

// Timer 0 mode definitions
#define	Tim0_Normal_Mode	0
#define Tim0_PWM_Mode		1

// Timer 0 Interrupt definitions
#define INTRPT2 __vector_11	//definition of Timer 0 Interrupt

//ISR function definition
#define ISR(x)	void x(void) __attribute__((signal, used));\
void x(void)


// Timer 0 Pre-scaler definitions
#define Tim0_PS_1		1
#define Tim0_PS_8		2
#define Tim0_PS_64		3
#define Tim0_PS_256		4
#define Tim0_PS_1024	5


// Get timer value
u8 Tim0_vidGetTimVal(void);

// Set timer value
void Tim0_vidSetTimVal(u8 u8TimVal);

// Timer initiation function 
void Tim0_vidInit(u8 u8Mode);

// Stop the timer
void Tim0_vidTimStop(void);

// Generate delay function in Milliseconds
void Tim0_vidDelay_MS(u8 u8MS_Delay, u8 u8PreScaler);

// Generate PWM with a certain duty cycle "Percentage"
void Tim0_vidPWMStart(u8 u8DutyCycle, u8 u8PreScaler);





#endif /* TIMER_INTERFACE_H_ */