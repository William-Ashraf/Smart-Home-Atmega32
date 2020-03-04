/*
 * DIO_PROG.c
 *
 *  Created on: Aug 30, 2019
 *      Author: William
 */
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "DIO_Reg.h"

void DIO_voidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Direction)
{

	if (( Copy_u8PortId <= PORT_D)&&(Copy_u8PinId <= PIN7  )&&(Copy_u8Direction <= 1)){
	switch(Copy_u8Direction)
	{
	   case DIO_DIRECTION_INPUT :

		   switch(Copy_u8PortId){

		   case PORT_A :  CLR_BIT(DDRA ,Copy_u8PinId);
		               break;
		   case PORT_B :  CLR_BIT(DDRB ,Copy_u8PinId);
		 		               break;
		   case PORT_C :  CLR_BIT(DDRC ,Copy_u8PinId);
		 		               break;
		   case PORT_D :  CLR_BIT(DDRD ,Copy_u8PinId);
		 		               break;         }break;



		   case DIO_DIRECTION_OUTPUT :

		  		   switch(Copy_u8PortId){

		  		   case PORT_A :  SET_BIT(DDRA ,Copy_u8PinId);
		  		               break;
		  		   case PORT_B :  SET_BIT(DDRB ,Copy_u8PinId);
		  		 		               break;
		  		   case PORT_C :  SET_BIT(DDRC ,Copy_u8PinId);
		  		 		               break;
		  		   case PORT_D :  SET_BIT(DDRD ,Copy_u8PinId);
		  		 		               break;
		  		                       }

	}


		   }

}

  u8 DIO_u8GETPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId){

	u8 LOCAL_u8RetVar;
	if (( Copy_u8PortId <=  PORT_D)&&(Copy_u8PinId <= PIN7  )){


		 switch(Copy_u8PortId){

				   case PORT_A : LOCAL_u8RetVar = GET_BIT(DDRA ,Copy_u8PinId);
				               break;
				   case PORT_B : LOCAL_u8RetVar = GET_BIT(DDRB ,Copy_u8PinId);
				 		               break;
				   case PORT_C : LOCAL_u8RetVar = GET_BIT(DDRC ,Copy_u8PinId);
				 		               break;
				   case PORT_D : LOCAL_u8RetVar = GET_BIT(DDRD ,Copy_u8PinId);
				 		               break;         }
				                                                }
	else {LOCAL_u8RetVar = 0xFF ; }

                                        return  LOCAL_u8RetVar;    }
  void DIO_voidSetPORTDirection(u8 Copy_u8PortId,u8 Copy_u8Direction){

	 if(Copy_u8PortId <=  PORT_D){
	 switch(Copy_u8PortId){

	 				   case PORT_A : DDRA = Copy_u8Direction ;
	 				               break;
	 				   case PORT_B : DDRB = Copy_u8Direction ;
	 				 		               break;
	 				   case PORT_C : DDRC = Copy_u8Direction ;
	 				 		               break;
	 				   case PORT_D : DDRD = Copy_u8Direction ;
	 				 		               break;         }} }




 /* u8 DIO_u8GetPORTValue(u8 Copy_u8PortId,u8 Copy_u8Direction){
 	u8 LOCAL_u8RetVar;

 	if(Copy_u8PortId <=  PORT_D){
 		 switch(Copy_u8PortId){

 		 				   case PORT_A : DDRA = Copy_u8Direction ;
 		 				               break;
 		 				   case PORT_B : DDRB = Copy_u8Direction ;
 		 				 		               break;
 		 				   case PORT_C : DDRC = Copy_u8Direction ;
 		 				 		               break;
 		 				   case PORT_D : DDRD = Copy_u8Direction ;
 		 				 		               break;         }}



 return LOCAL_u8RetVar;
 }*/




 void DIO_SetPinValue(u8 Copy_u8PortId , u8 Copy_u8PinId, u8 Copy_u8PinVal)
 {
 	/* Make sure that the Port ID and Pin ID are in the valid range */
 	if ((Copy_u8PortId <= PORT_D) && ( Copy_u8PinId <= PIN7))
 	{
 		if (Copy_u8PinVal == HIGH)
 		{
 			/* Check on the Required PORT Number */
 			switch (Copy_u8PortId)
 			{
 				case PORT_A: SET_BIT(PORTA, Copy_u8PinId); break;
 				case PORT_B: SET_BIT(PORTB, Copy_u8PinId); break;
 				case PORT_C: SET_BIT(PORTC, Copy_u8PinId); break;
 				case PORT_D: SET_BIT(PORTD, Copy_u8PinId); break;
 			}

 		}

 		else if (Copy_u8PinVal == LOW)
 		{
 			/* Check on the Required PORT Number */
 			switch (Copy_u8PortId)
 			{
 				case PORT_A: CLR_BIT(PORTA,Copy_u8PinId); break;
 				case PORT_B: CLR_BIT(PORTB,Copy_u8PinId); break;
 				case PORT_C: CLR_BIT(PORTC,Copy_u8PinId); break;
 				case PORT_D: CLR_BIT(PORTD,Copy_u8PinId); break;
 			}
 		}

 		else
 		{
 			/* Do nothing, Wrong value to set */
 		}
 	}

 	else
 	{
 		/* Do nothing, Error in the Pin ID or PORT ID */
 	}
 }


 void DIO_SetPortValue (u8 u8PortId, u8 u8PortVal)
 {
 	/* Check on the Required PORT Number */
 	switch (u8PortId)
 	{
 		case     PORT_A : PORTA = u8PortVal; break;
 		case     PORT_B : PORTB = u8PortVal; break;
 		case     PORT_C : PORTC = u8PortVal; break;
 		case     PORT_D : PORTD = u8PortVal; break;
 		default: /* Wrong Port ID */       break;
 	}
 }



