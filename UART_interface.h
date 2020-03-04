/*
 * UART_interface.h
 *
 *  Created on: Oct 4, 2019
 *      Author: William
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#define UART_PORT PORT_D
#define UART_Tx_Pin PIN1
#define UART_Rx_Pin PIN0
void UART_Init(void);
void UART_SendChar(u8 data);
typedef enum
{
	OK=0,
	NOTOK
}Recieve_Status;
Recieve_Status UART_RecieveChar(u8 * ptr);
void UART_SendString(char *word);

#endif /* UART_INTERFACE_H_ */
