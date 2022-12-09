/*
 * interrupt.h
 *
 *  Created on: Dec 5, 2022
 *      Author: omar hamdii
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_H_
#define MCAL_INTERRUPT_INTERRUPT_H_

#ifndef INTERUPT_H_
#define INTERUPT_H_

#include "../../MCAL/gpio/gpio.h"
#include "../../Utalities/std_types.h"
#include "../../Utalities/common_macros.h"
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>



/* External INT0 enable and configuration function */
void INT0_Init(void);



#endif


#endif /* MCAL_INTERRUPT_INTERRUPT_H_ */
