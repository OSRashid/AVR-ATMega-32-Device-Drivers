/*
 * Intrpt_Program.c
 *
 * Created: 7/22/2023 12:41:09 AM
 *  Author: Omar
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Intrpt_Interface.h"
#include "Intrpt_Private.h"

void Intrpt_vidIntrptInit(u8 u8IntNum , u8 u8IntSense)
{
	//Enable global interrupt
	SET_BIT(SREG,7);
	
	switch(u8IntNum)
	{
	case 0:
		//setting interrupt sense
		MCUCR |= (u8IntSense);
		//enabling interrupt
		SET_BIT(GICR, 6);
		break;
	case 1:
		//setting interrupt sense
		MCUCR |= (u8IntSense << 2);
		//enabling interrupt
		SET_BIT(GICR, 7);	
		break;
	case 2:
		//Disabling interrupt
		CLR_BIT(GICR, 5);
		//setting interrupt sense
		if (2 == u8IntSense )
		{
			CLR_BIT(MCUCSR,6);
		}	
		if (3 == u8IntSense )
		{
			SET_BIT(MCUCSR,6);
		}
		//enabling interrupt
		SET_BIT(GICR, 5);
		break;	
	default:
		break;
	}
		
}