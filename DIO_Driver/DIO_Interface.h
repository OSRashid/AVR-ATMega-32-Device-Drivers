/*
 * DIO_Interface.h
 *
 *  Created on: May 28, 2023
 *      Author: Omar
 */

//This is the driver of Digital I/O of the AVR_ATMega32

#ifndef MCAL_LAYER_DIO_DRIVER_DIO_INTERFACE_H_
#define MCAL_LAYER_DIO_DRIVER_DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Input argument for function with argument u8Port_Id */
#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7

#define DIO_INPUT    0x00
#define DIO_OUTPUT   0xFF

#define DIO_LOW      0x00
#define DIO_HIGH     0xFF
/**/
#define DIO_PIN_IN	0
#define DIO_PIN_OUT	1

#define DIO_UNDEF_VAL 0xFF



void DIO_vidSetPinDir(u8 u8PortId,u8 u8PinId,u8 u8PinDir);

void DIO_vidSetPinVal(u8 u8PortId,u8 u8PinId,u8 u8PinVal);

void DIO_vidTogglePinVal(u8 u8PortId,u8 u8PinId);

void DIO_vidEnablePullUpRes(u8 u8PortId,u8 u8PinId);

u8 DIO_u8GetPinVal(u8 u8PortId,u8 u8PinId);

void DIO_vidSetPortDir(u8 u8PortId,u8 u8PortDir);

void DIO_vidSetPortVal(u8 u8PortId,u8 u8PortVal);

void DIO_vidShiftLeft(u8 u8PortId);

#endif /* MCAL_LAYER_DIO_DRIVER_DIO_INTERFACE_H_ */
