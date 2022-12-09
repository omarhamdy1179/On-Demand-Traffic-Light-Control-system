/*
 * Led.h
 *
 *  Created on: Nov 13, 2022
 *      Author: omar hamdii
 */

#ifndef ECUAL_LED_LED_H_
#define ECUAL_LED_LED_H_

#include "../../MCAL/gpio/gpio.h"
#include "../../Utalities/std_types.h"


#define Error_LED   0
#define Success_LED 1


#define LED_Pin0 0
#define LED_Pin1 1
#define LED_Pin2 2
#define LED_Pin3 3
#define LED_Pin4 4
#define LED_Pin5 5
#define LED_Pin6 6
#define LED_Pin7 7

/*
 * Description :
 *INTIALIZING OF LED
 * MAKING PIN OUTPUT PIN
 */
uint8 Led_Init (uint8 Port_num,uint8 Pin_num);


/*
 * Description :
 * Function that will make led on at certain port and pin
 */
uint8 Led_On (uint8 Port_num,uint8 Pin_num);

/*
 * Description :
 * Function that will make led off at certain port and pin
 */
uint8 Led_Off (uint8 Port_num,uint8 Pin_num);

/*
 * Description :
 * Function that will make led Toggle at certain port and pin
 */
uint8 Toggle_Led (uint8 Port_num,uint8 Pin_num);


#endif /* ECUAL_LED_LED_H_ */
