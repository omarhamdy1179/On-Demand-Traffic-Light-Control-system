/*
 * Button.c
 *
 *  Created on: Nov 13, 2022
 *      Author: omar hamdii
 */


#include "Button.h"

#include "../../Utalities/std_types.h"


/*VARIABLE INDICATE STATE OF FUNCTION*/
uint8 return_value;


/*
 * Description :
 * SETTING BUTTON PIN
 * PORTD---PIN2
 */
uint8 Button_Fun (uint8 Port_num,uint8 Pin_num)
{
	return_value =Success_Button;

	/*CHECKING IF INPUT OF FUNCTION EXCEED NUMBER OF PIN AND PORT*/
	if(Port_num>3||Pin_num>7)
	{
		return_value=Error_Button;
	}
	else
	{
		/*CALLING GPIO DRIVER TO MAKE BUTTON INPUT PIN*/
		GPIO_setupPinDirection(Port_num, Pin_num,  PIN_INPUT);
	}
	/*RETURN STATE*/
	return return_value;
}
