/*
 * Led.c
 *
 *  Created on: Nov 13, 2022
 *      Author: omar hamdii
 */


#include "led.h"

#include "../../Utalities/common_macros.h" /* To use the macros like SET_BIT */

/*VARIABLE INDICATE STATE OF FUNCTION*/
uint8 return_value ;

/*
 * Description :
 *INTIALIZING OF LED
 * MAKING PIN OUTPUT PIN
 */
uint8 Led_Init (uint8 Port_num,uint8 Pin_num)
{
	return_value =Success_LED ;

	/*CHECKING IF INPUT OF FUNCTION EXCEED NUMBER OF PIN AND PORT*/
	if (Pin_num>7||Port_num>3)
	{
		return Error_LED;
	}
	else
	{
		GPIO_setupPinDirection(Port_num,Pin_num,PIN_OUTPUT);
	}

	return return_value;
}


/*
 * Description :
 * Function that will make led on at certain port and pin
 */
uint8 Turn_Led_On (uint8 Port_num,uint8 Pin_num)
{
	return_value  =Success_LED ;

	/*CHECKING IF INPUT OF FUNCTION EXCEED NUMBER OF PIN AND PORT*/
	if (Pin_num>7||Port_num>3)
	{
		return Error_LED;
	}
	else
	{
		GPIO_writePin(Port_num, Pin_num, LOGIC_HIGH);
	}
	return return_value;
}


/*
 * Description :
 * Function that will make led off at certain port and pin
 */
uint8 Turn_Led_Off (uint8 Port_num,uint8 Pin_num)
{
	return_value  =Success_LED ;

	/*CHECKING IF INPUT OF FUNCTION EXCEED NUMBER OF PIN AND PORT*/
	if (Pin_num>7||Port_num>3)
	{
		return Error_LED;
	}
	else
	{
		GPIO_writePin(Port_num, Pin_num, LOGIC_LOW);
	}
	return return_value;
}







