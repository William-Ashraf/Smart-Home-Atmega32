/*
 * DIO_interface.h
 *
 *  Created on: Aug 30, 2019
 *      Author: William
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#define DIO_DIRECTION_INPUT   0
#define DIO_DIRECTION_OUTPUT  1


#define PORT_A   0
#define PORT_B   1
#define PORT_C   2
#define PORT_D   3


#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7


#define HIGH 1
#define LOW  0

void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Direction);
u8 DIO_u8GETPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId);
void DIO_voidSetPORTDirection(u8 Copy_u8PortId,u8 Copy_u8Direction);


void DIO_SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId, u8 Copy_u8PinVal);
void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal);






#endif /* DIO_INTERFACE_H_ */
