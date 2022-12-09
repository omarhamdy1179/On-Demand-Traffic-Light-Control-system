/*
 * Button.h
 *
 *  Created on: Nov 13, 2022
 *      Author: omar hamdii
 */

#ifndef ECUAL_BUTTON_BUTTON_H_
#define ECUAL_BUTTON_BUTTON_H_
#include "../../MCAL/gpio/gpio.h"
#include "../../MCAL/Timer1/Timers.h" /*Using Timer1*/
#include "../../MCAL/Interrupt/interrupt.h" /* To use the macros like SET_BIT */



#define Success_Button 0
#define Error_Button   1

/*Enum making Driver_Button configrable
 * as choosing which port we want to connect Button
 */
typedef enum
{
	Button_PORTA,Button_PORTB,Button_PORTC,Button_PORTD
}Button_Ports;


/*
 * Description :
 * SETTING BUTTON PIN
 * PORTD---PIN2
 */
uint8 Button_Func (uint8 Port_num,uint8 Pin_num);




#endif /* ECUAL_BUTTON_BUTTON_H_ */
