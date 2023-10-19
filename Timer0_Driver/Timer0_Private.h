/*
 * Timer_Priv.h
 *
 * Created: 7/20/2023 11:33:14 PM
 *  Author: Omar
 */ 


#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_

#define TIFR	*((volatile u8*)(0x58))
#define TCNT0	*((volatile u8*)(0x52))
#define TCCR0	*((volatile u8*)(0x53))
#define OCR0	*((volatile u8*)(0x5C))
#define TIMSK	*((volatile u8*)(0x59))

#endif /* TIMER_PRIV_H_ */