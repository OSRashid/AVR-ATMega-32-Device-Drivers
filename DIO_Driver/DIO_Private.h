/*
 * DIO_Private.h
 *
 *  Created on: May 28, 2023
 *      Author: Omar
 */

#ifndef MCAL_LAYER_DIO_DRIVER_DIO_PRIVATE_H_
#define MCAL_LAYER_DIO_DRIVER_DIO_PRIVATE_H_


/* PORT A Register Definition */
#define PORTA_REG      *((volatile u8*)0x3B)
#define DDRA_REG       *((volatile u8*)0x3A)
#define PINA_REG       *((volatile u8*)0x39)

/* PORT B Register Definition */
#define PORTB_REG      *((volatile u8*)0x38)
#define DDRB_REG       *((volatile u8*)0x37)
#define PINB_REG       *((volatile u8*)0x36)

/* PORT C Register Definition */
#define PORTC_REG      *((volatile u8*)0x35)
#define DDRC_REG       *((volatile u8*)0x34)
#define PINC_REG       *((volatile u8*)0x33)

/* PORT D Register Definition */
#define PORTD_REG      *((volatile u8*)0x32)
#define DDRD_REG       *((volatile u8*)0x31)
#define PIND_REG       *((volatile u8*)0x30)


//this function to concatenate the bits one by one
#define CONC(p7,p6,p5,p4,p3,p2,p1,p0)		CONC_TMP(p7,p6,p5,p4,p3,p2,p1,p0)
#define CONC_TMP(p7,p6,p5,p4,p3,p2,p1,p0)	0b##p7##p6##p5##p4##p3##p2##p1##p0
#endif /* MCAL_LAYER_DIO_DRIVER_DIO_PRIVATE_H_ */
