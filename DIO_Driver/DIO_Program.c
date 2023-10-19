/*
 * DIO_Program.c
 *
 *  Created on: May 28, 2023
 *      Author: Omar
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_Configuration.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"


Status_Type DIO_enuInit(void){

	Status_Type Local_enuStatus = Success ;

	DDRA_REG = CONC(DIO_PORTA_PIN7_INIT_DIREC,
					DIO_PORTA_PIN6_INIT_DIREC,
					DIO_PORTA_PIN5_INIT_DIREC,
					DIO_PORTA_PIN4_INIT_DIREC,
					DIO_PORTA_PIN3_INIT_DIREC,
					DIO_PORTA_PIN2_INIT_DIREC,
					DIO_PORTA_PIN1_INIT_DIREC,
					DIO_PORTA_PIN0_INIT_DIREC) ;

	DDRB_REG = CONC(DIO_PORTB_PIN7_INIT_DIREC,
					DIO_PORTB_PIN6_INIT_DIREC,
					DIO_PORTB_PIN5_INIT_DIREC,
					DIO_PORTB_PIN4_INIT_DIREC,
					DIO_PORTB_PIN3_INIT_DIREC,
					DIO_PORTB_PIN2_INIT_DIREC,
					DIO_PORTB_PIN1_INIT_DIREC,
					DIO_PORTB_PIN0_INIT_DIREC) ;

	DDRC_REG = CONC(DIO_PORTC_PIN7_INIT_DIREC,
					DIO_PORTC_PIN6_INIT_DIREC,
					DIO_PORTC_PIN5_INIT_DIREC,
					DIO_PORTC_PIN4_INIT_DIREC,
					DIO_PORTC_PIN3_INIT_DIREC,
					DIO_PORTC_PIN2_INIT_DIREC,
					DIO_PORTC_PIN1_INIT_DIREC,
					DIO_PORTC_PIN0_INIT_DIREC) ;

	DDRD_REG = CONC(DIO_PORTD_PIN7_INIT_DIREC,
					DIO_PORTD_PIN6_INIT_DIREC,
					DIO_PORTD_PIN5_INIT_DIREC,
					DIO_PORTD_PIN4_INIT_DIREC,
					DIO_PORTD_PIN3_INIT_DIREC,
					DIO_PORTD_PIN2_INIT_DIREC,
					DIO_PORTD_PIN1_INIT_DIREC,
					DIO_PORTD_PIN0_INIT_DIREC) ;

	return Local_enuStatus;
}

void DIO_vidSetPinDir(u8 u8PortId,u8 u8PinId,u8 u8PinDir)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		if(u8PinDir == DIO_OUTPUT)
		{
			switch(u8PortId)
			{
			case DIO_PORTA : SET_BIT(DDRA_REG,u8PinId);break;
			case DIO_PORTB : SET_BIT(DDRB_REG,u8PinId);break;
			case DIO_PORTC : SET_BIT(DDRC_REG,u8PinId);break;
			case DIO_PORTD : SET_BIT(DDRD_REG,u8PinId);break;
			}
		}
		else if(u8PinDir == DIO_INPUT)
		{
			switch(u8PortId)
			{
			case DIO_PORTA : CLR_BIT(DDRA_REG,u8PinId);break;
			case DIO_PORTB : CLR_BIT(DDRB_REG,u8PinId);break;
			case DIO_PORTC : CLR_BIT(DDRC_REG,u8PinId);break;
			case DIO_PORTD : CLR_BIT(DDRD_REG,u8PinId);break;
			}
		}
		else
		{
			/* Wrong Port direction please check direction argument */
		}
	}
	else
	{
		/* Wrong Port Id or Pin Id please check function arguments */
	}
}

void DIO_vidSetPinVal(u8 u8PortId,u8 u8PinId,u8 u8PinVal)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		if(u8PinVal == DIO_HIGH)
		{
			switch(u8PortId)
			{
			case DIO_PORTA : SET_BIT(PORTA_REG,u8PinId);break;
			case DIO_PORTB : SET_BIT(PORTB_REG,u8PinId);break;
			case DIO_PORTC : SET_BIT(PORTC_REG,u8PinId);break;
			case DIO_PORTD : SET_BIT(PORTD_REG,u8PinId);break;
			}
		}
		else if(u8PinVal == DIO_LOW)
		{
			switch(u8PortId)
			{
			case DIO_PORTA : CLR_BIT(PORTA_REG,u8PinId);break;
			case DIO_PORTB : CLR_BIT(PORTB_REG,u8PinId);break;
			case DIO_PORTC : CLR_BIT(PORTC_REG,u8PinId);break;
			case DIO_PORTD : CLR_BIT(PORTD_REG,u8PinId);break;
			}
		}
		else
		{
			/* Wrong Port direction please check direction argument */
		}
	}
	else
	{
		/* Wrong Port Id or Pin Id please check function arguments */
	}
}

void DIO_vidTogglePinVal(u8 u8PortId,u8 u8PinId)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		switch(u8PortId)
		{
		case DIO_PORTA : TOG_BIT(PORTA_REG,u8PinId);break;
		case DIO_PORTB : TOG_BIT(PORTB_REG,u8PinId);break;
		case DIO_PORTC : TOG_BIT(PORTC_REG,u8PinId);break;
		case DIO_PORTD : TOG_BIT(PORTD_REG,u8PinId);break;
		}
	}
	else
	{
		/* Wrong Port Id or Pin Id please check function arguments */
	}
}

void DIO_vidEnablePullUpRes(u8 u8PortId,u8 u8PinId)
{
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		switch(u8PortId)
		{
		case DIO_PORTA : SET_BIT(PORTA_REG,u8PinId);break;
		case DIO_PORTB : SET_BIT(PORTB_REG,u8PinId);break;
		case DIO_PORTC : SET_BIT(PORTC_REG,u8PinId);break;
		case DIO_PORTD : SET_BIT(PORTD_REG,u8PinId);break;
		}
	}
	else
	{
		/* Wrong Port Id or Pin Id please check function arguments */
	}
}

u8 DIO_u8GetPinVal(u8 u8PortId,u8 u8PinId)
{
	u8 u8ResultLoc;
	if(u8PortId <= DIO_PORTD && u8PinId <= DIO_PIN7)
	{
		switch(u8PortId)
		{
		case DIO_PORTA : u8ResultLoc = GET_BIT(PINA_REG,u8PinId);break;
		case DIO_PORTB : u8ResultLoc = GET_BIT(PINB_REG,u8PinId);break;
		case DIO_PORTC : u8ResultLoc = GET_BIT(PINC_REG,u8PinId);break;
		case DIO_PORTD : u8ResultLoc = GET_BIT(PIND_REG,u8PinId);break;
		}
	}
	else
	{
		/* Wrong Port Id or Pin Id please check function arguments */
		u8ResultLoc = DIO_UNDEF_VAL;
	}
	return u8ResultLoc;
}

void DIO_vidSetPortDir(u8 u8PortId,u8 u8PortDir)
{
	switch(u8PortId)
	{
	case DIO_PORTA : DDRA_REG = u8PortDir;break;
	case DIO_PORTB : DDRB_REG = u8PortDir;break;
	case DIO_PORTC : DDRC_REG = u8PortDir;break;
	case DIO_PORTD : DDRD_REG = u8PortDir;break;
	default : /* Wrong Port ID */         break;
	}
}

void DIO_vidSetPortVal(u8 u8PortId,u8 u8PortVal)
{
	switch(u8PortId)
	{
	case DIO_PORTA : PORTA_REG = u8PortVal;break;
	case DIO_PORTB : PORTB_REG = u8PortVal;break;
	case DIO_PORTC : PORTC_REG = u8PortVal;break;
	case DIO_PORTD : PORTD_REG = u8PortVal;break;
	default : /* Wrong Port ID */          break;
	}
}

void DIO_vidShiftLeft(u8 u8PortId)
{
	switch(u8PortId)
	{
	case DIO_PORTA : PORTA_REG = SHL_BIT(PORTA_REG);break;
	case DIO_PORTB : PORTB_REG = SHL_BIT(PORTB_REG);break;
	case DIO_PORTC : PORTC_REG = SHL_BIT(PORTB_REG);break;
	case DIO_PORTD : PORTD_REG = SHL_BIT(PORTB_REG);break;
	default : /* Wrong Port ID */          break;
	}
}

void DIO_vidShiftRight(u8 u8PortId)
{
	switch(u8PortId)
	{
	case DIO_PORTA : PORTA_REG = SHR_BIT(PORTA_REG);break;
	case DIO_PORTB : PORTB_REG = SHR_BIT(PORTB_REG);break;
	case DIO_PORTC : PORTC_REG = SHR_BIT(PORTB_REG);break;
	case DIO_PORTD : PORTD_REG = SHR_BIT(PORTB_REG);break;
	default : /* Wrong Port ID */          break;
	}
}
