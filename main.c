/*
 * main.c

 *
 *  Created on: Oct 4, 2019
 *      Author: William

*/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "Smart_home_interface.h"
#include "avr/delay.h"
int main (void)
{
	//Set direction of Tx --> output / Rx-->inputol
	DIO_voidSetPinDirection(UART_PORT,UART_Tx_Pin,DIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(UART_PORT,UART_Rx_Pin,DIO_DIRECTION_INPUT);
	UART_Init();
    Smart_Home_init();
	int flag=0;
	while(1)
	{
            Smart_Door_close();
            int user_number;
			int u=0;
            char password[5];
			char x[4][20]={"william","marine","ashraf","dalia"};
			char pass [4][4]={"5555","5847" ,"9875","3254"};
			char user[20] ;
			Smart_Get_Name(user);
			Smart_Check_Name(user,x,&u,&user_number);
			if (u==0)
			{
			    if(flag <= 2 )
			    {   flag++;
			    	Smart_Error();
			    	_delay_ms(500);
			    }
			    else if (flag > 2)
			    {
			    	Smart_Siren_Open();
			    }
			}
			else if (u==1)
			{
			Smart_User();
			Smart_Siren_close();
			Smart_Get_password(password);
			u=Smart_Check_password(password,pass,user_number);
			 if (u==4)
			 {
				Smart_Door_Open();
				 _delay_ms(3000);
				 flag=0;
			 }
			 else
			 {
				 if(flag <= 2 )
				 {flag++;
				 Smart_Error();
				 _delay_ms(500);
				 }
				 else if (flag > 2)
				 {
				 Smart_Siren_Open();
				 }
			 }
			}
	}
return 0 ;}
