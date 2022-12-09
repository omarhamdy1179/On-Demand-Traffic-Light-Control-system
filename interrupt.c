/*
 * interrupt.c
 *
 *  Created on: Dec 5, 2022
 *      Author: omar hamdii
 */


#include "interrupt.h"



void INT0_Init(void)
{
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
}
