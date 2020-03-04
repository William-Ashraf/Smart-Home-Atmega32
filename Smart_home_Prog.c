/*
 * Smart_home_Prog.c

 *
 *  Created on: Feb 16, 2020
 *      Author: William
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "UART_interface.h"
#include "Smart_home_interface.h"

void Smart_Home_init(void)
{
	DIO_voidSetPinDirection(Smart_Home_PORT,Smart_User_Pin,DIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(Smart_Home_PORT,Smart_Door_Pin,DIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(Smart_Home_PORT,Smart_Alarm_Pin,DIO_DIRECTION_OUTPUT);
	DIO_voidSetPinDirection(Smart_Home_PORT,Smart_Error_Pin,DIO_DIRECTION_OUTPUT);
	UART_SendString("Enter the name please (you have 3 trials only) \n\n");
}
void Smart_Door_Open(void)
{
   DIO_SetPinValue(Smart_Home_PORT,Smart_Door_Pin,HIGH);
   UART_SendString("WELCOME HOME!! \n\n");
}
void Smart_Door_close(void)
{
	DIO_SetPinValue(Smart_Home_PORT,Smart_Door_Pin,LOW);
	DIO_SetPinValue(Smart_Home_PORT,Smart_User_Pin,LOW);
	DIO_voidSetPinDirection(Smart_Home_PORT,Smart_Error_Pin,LOW);
}
void Smart_Siren_Open(void)
{
	DIO_SetPinValue(Smart_Home_PORT,Smart_Alarm_Pin,HIGH);
	UART_SendString("To close the siren enter the right name please \n\n");
}
void Smart_Siren_close(void)
{
	DIO_SetPinValue(Smart_Home_PORT,Smart_Alarm_Pin,LOW);
}
void Smart_Error(void)
{
	DIO_SetPinValue(Smart_Home_PORT,Smart_Error_Pin,HIGH);
	UART_SendString("Wrong entry!!!!! \n\n");
}
void Smart_User(void)
{
	DIO_SetPinValue(Smart_Home_PORT,Smart_User_Pin,HIGH);
}
void Smart_Get_Name(char *user)
{ UART_SendString("Enter the Name ended by space:");
	u8 value;
  int i=0 ;
	 do //getting string
				    {
					 if (UART_RecieveChar(&value)== OK)
					{
				       user[i]=value;
				       UART_SendChar(value);
				        i++;
					}


				 }while(user[i-1] != ' ');
	 UART_SendString("\n\n");
}
void Smart_Check_Name(char *user,char x[][20],int *u,int *user_number)
{  int z,h=0;
	 for (z=0;z<4;z++)
				 {
				    while (user[h]== x[z][h])
				     {
				        if (x[z][h+1]== 0 )
				      {
				        *u=1;
				        *user_number=z;
				      }
				      h++;
				     }
				  }
}
void Smart_Get_password(char *password)
{ UART_SendString("Please enter the password:");
	u8 value ;
	int h=0;
				 do {
					 if (UART_RecieveChar(&value)== OK)
					 {
				       password[h]=value;
				       UART_SendChar(value);
					   h++;
					 }
	                 }while(h!=4);
				 UART_SendString("\n\n");
}
int Smart_Check_password(char *password,char pass[][4],int user_number)
{
	int h=0;
	int u=0;
				 while (password[h]== pass[user_number][h])
				 			    {
				 			     u++;
				 			     h++;
				 			    }
				 return u ;
}


