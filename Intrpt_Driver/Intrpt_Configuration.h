/*
 * Intrpt_Configuration.h
 *
 * Created: 7/22/2023 7:20:05 PM
 *  Author: Omar
 */ 


#ifndef INTRPT_CONFIGURATION_H_
#define INTRPT_CONFIGURATION_H_


#define INTRPT0 __vector_1 
#define INTRPT1 __vector_2
#define INTRPT2 __vector_3

#define ISR(x)	void x(void) __attribute__((signal, used));	\
void x(void)



ISR(INTRPT0)
{
	// Write your ISR for Intrpt 0 Here
	extern int NumIntrpts;
	NumIntrpts++;

}

ISR(INTRPT1)
{
	// Write your ISR for Intrpt 0 Here
}

ISR(INTRPT2)
{
	// Write your ISR for Intrpt 0 Here
}


#endif /* INTRPT_CONFIGURATION_H_ */