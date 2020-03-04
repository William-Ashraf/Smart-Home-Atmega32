/*
 * UART_Prog.c
 *
 *  Created on: Oct 4, 2019
 *      Author: William
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "UART_interface.h"
#include "UART_Reg.h"


void UART_Init(void)
{ u8 temp_var=0b10000110;
  u16 Baud_rate_value=51;
  //baud_rate = 9600 UBRR = 51-8 dat PINs - No Parity Bits -1 Stop Bits - Rising edge
  CLR_BIT(UCSRA,4);
  CLR_BIT(UCSRA,3);

  SET_BIT(UCSRB,4); //RXEN
  SET_BIT(UCSRB,3); //TXEN
  CLR_BIT(UCSRB,2); //8 bits data

  UCSRC=temp_var ;

  CLR_BIT(UCSRB,7);//accessing UBRRH
  UBRRL= (u8) Baud_rate_value ;
  UBRRH= (u8) (Baud_rate_value>>8);
  SET_BIT(UCSRB,7); //Accessing UCSRC

}
void UART_SendChar(u8 data )
{
//poll on the flag of the empty register
	while(!GET_BIT(UCSRA,5));
    UDR=data ;
}
void UART_SendString(char *word)
{ int p=0;
while (word[p]!=0)
{
UART_SendChar(word[p]);
p++;
}

}
Recieve_Status UART_RecieveChar(u8 * ptr)
{
	Recieve_Status state = NOTOK ;
	if(GET_BIT(UCSRA,7))
	{
		*ptr= UDR ;
		state= OK ;
	}
	return state ;
}

