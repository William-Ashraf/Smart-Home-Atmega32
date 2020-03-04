/*
 * Smart_home_interface.h
 *
 *  Created on: Feb 16, 2020
 *      Author: William
 */

#ifndef SMART_HOME_INTERFACE_H_
#define SMART_HOME_INTERFACE_H_

#define Smart_Alarm_Pin PIN2
#define Smart_Door_Pin PIN4
#define Smart_User_Pin PIN0
#define Smart_Error_Pin PIN1
#define Smart_Home_PORT PORT_A
void Smart_Home_init(void);
void Smart_Door_Open(void);
void Smart_Door_close(void);
void Smart_Siren_Open(void);
void Smart_Siren_close(void);
void Smart_Error(void);
void Smart_User(void);
void Smart_Get_Name(char *user);
void Smart_Check_Name(char *user,char x[][20],int *u,int *user_number);
void Smart_Get_password(char *password);
int Smart_Check_password(char *password,char pass[][4],int user_number);


#endif /* SMART_HOME_INTERFACE_H_ */
