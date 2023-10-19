/*
 * Intrpt_interface.h
 *
 * Created: 7/22/2023 12:39:45 AM
 *  Author: Omar
 */ 

//This is the driver of external interrupts of the AVR_ATMega32


#ifndef INTRPT_INTERFACE_H_
#define INTRPT_INTERFACE_H_

#include	"STD_TYPES.h"

//Vector table definitions
#define INTRPT0 __vector_1	//definition of external interrupt ISR 0
#define INTRPT1 __vector_2	//definition of external interrupt ISR 1
#define INTRPT2 __vector_3	//definition of external interrupt ISR 2

//ISR function definition
#define ISR(x)	void x(void) __attribute__((signal, used));\
void x(void)


//interrupt pins definitions
#define Intrpt_INT0		0
#define Intrpt_INT1		1
#define Intrpt_INT2		2	//for interrupt 2 only falling edge and rising edge sense are available

//interrupt sense definitions
#define Intrpt_LowLvl	0	//interrupt on low level
#define	Intrpt_Any		1	//interrupt on any logical change
#define Intrpt_FalEdg	2	//interrupt on falling edge
#define	Intrpt_RisEdg	3	//interrupt on rising edge


void Intrpt_vidIntrptInit(u8 u8IntNum , u8 u8IntSense);





#endif /* INTRPT_INTERFACE_H_ */