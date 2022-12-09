/*
 * App.c
 *
 *  Created on: Nov 13, 2022
 *      Author: omar hamdii
 */
#include "App.h"
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "../MCAL/Timer1/Timers.h" /* To use the macros like SET_BIT */

/*Indicate red LED is on or off*/
uint8 flag_red=0;

/*Indicate Green LED is on or off*/
uint8 flag_green=0;

/*Indicate Yellow LED is on or off*/
uint8 flag_yellow=0;

uint8 flag_main=0;

/********************************INT0_Decleration*******************************/

/*
 * PORTA (CAR TRAFFIC LIGHT)
 * PIN0----->GREEN LED
 * PIN1----->YELLOW LED
 * PIN2----->RED LED
 *
 * PORTB  (pedestrians TRAFFIC LIGHT)
 * PIN0----->GREEN LED
 * PIN1----->YELLOW LED
 * PIN2----->RED LED
 */

ISR(INT0_vect)
{
	/*If RED car traffic Led is open
	 * Opening green led of pedestrians
	 * waiting 5 sec and close it
	 */
	if (flag_red==1)
	{
		/*opening green led and closing yellow and red led */
		Turn_Led_On(PORTB_ID,PIN0_ID);
		Turn_Led_Off(PORTB_ID, PIN1_ID);
		Turn_Led_Off(PORTB_ID, PIN2_ID);

		/*setting timer 1
		 * waiting 5 sec
		 */
		Timer (5);

     /*CLOSING GREEN AND RED LED*/
		Turn_Led_Off(PORTB_ID, PIN0_ID);
		Turn_Led_Off(PORTB_ID, PIN2_ID);


	}
	else if (flag_yellow==1||flag_green==1)
	{
		/*OPENING RED LED AND CLOSSING GREEN LED*/
		Turn_Led_On(PORTB_ID, PIN2_ID);
		Turn_Led_Off(PORTB_ID, PIN0_ID);


		/*OPENNING RED LED
		 * CLOSING ALL LED OF CAR TRAFFIC LIGHT
		 */
		Turn_Led_On(PORTB_ID,PIN2_ID);
		Turn_Led_Off(PORTA_ID, PIN0_ID);
		Turn_Led_Off(PORTA_ID, PIN2_ID);
		Turn_Led_Off(PORTA_ID, PIN1_ID);

		for(uint8 counter=0;counter<5;counter++)
		{
			/*Toggling Yellow LED OF CAR AND PRED TRAFFIC LIGHT*/
			GPIO_TogglePin(PORTA_ID,PIN1_ID);
			GPIO_TogglePin(PORTB_ID,PIN1_ID);

			/*setting timer */
			Timer (1);

		}
		Turn_Led_Off(PORTB_ID, PIN1_ID);
		Turn_Led_Off(PORTB_ID, PIN2_ID);
		Turn_Led_Off(PORTA_ID, PIN1_ID);

		Turn_Led_On(PORTB_ID,PIN0_ID);
		Turn_Led_On(PORTA_ID,PIN2_ID);


		/*setting timer 1
		 * waiting 5 sec
		 */
		Timer (5);

/*TURNING OF RED LED*/
		Turn_Led_Off(PORTB_ID,PIN0_ID);


	}
	/*RETURN ALL FLAG TO INTIAL VALUE*/
	flag_red=0;
	flag_yellow=0;
	flag_green=0;
}


/********************************Application_Function****************************/

void app_start()
{
	/*Enable interrupts by setting I-bit*/
	SREG  |= (1<<7);


	/*LED Intialization
	 * PORTA , PIN 0,1,2
	 * PORTB , PIN 0.1,2
	 */
	Led_Init(PORTA_ID,PIN0_ID);
	Led_Init(PORTA_ID,PIN1_ID);
	Led_Init(PORTA_ID,PIN2_ID);
	Led_Init(PORTB_ID,PIN0_ID);
	Led_Init(PORTB_ID,PIN1_ID);
	Led_Init(PORTB_ID,PIN2_ID);

	/*Turning off of led as intial value
	 * PORTA , PIN 0,1,2
	 * PORTB , PIN 0.1,2
	 */
	Turn_Led_Off(PORTA_ID, PIN0_ID);
	Turn_Led_Off(PORTA_ID, PIN1_ID);
	Turn_Led_Off(PORTA_ID, PIN2_ID);
	Turn_Led_Off(PORTB_ID, PIN0_ID);
	Turn_Led_Off(PORTB_ID, PIN1_ID);
	Turn_Led_Off(PORTB_ID, PIN2_ID);

	/*Intializing Button Pin
	 * PORTD
	 * PIN2
	 */
	Button_Fun(PORTD_ID,PIN2_ID);

	/*Intializing INT0*/
	INT0_Init();

	flag_main=1;
	while (1)
	{

		/*Opening Green LED and waiting 5 sec then Turn it OFF*/
		Turn_Led_On(PORTA_ID, PIN0_ID);
		flag_green=1;

		/*setting timer 1
		 * waiting 5 sec
		 */
		Timer2 (5);


		Turn_Led_Off(PORTA_ID, PIN0_ID);
		flag_green=0;

		/*Opening Yellow LED and waiting 5 sec then Turn it OFF*/
		Turn_Led_On(PORTA_ID, PIN1_ID);
		flag_yellow=1;

		/*setting timer 1
		 * waiting 5 sec
		 */
		Timer2 (5);

		Turn_Led_Off(PORTA_ID, PIN1_ID);
		flag_yellow=0;

		/*Opening Red LED and waiting 5 sec then Turn it OFF*/
		Turn_Led_On(PORTA_ID, PIN2_ID);
		flag_red=1;

		/*setting timer 1
		 * waiting 5 sec
		 */
		Timer2 (5);

		Turn_Led_Off(PORTA_ID, PIN2_ID);
		flag_red=0;

	}




}
