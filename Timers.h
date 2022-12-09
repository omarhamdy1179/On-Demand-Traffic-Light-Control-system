#ifndef  TIMERS_H_
#define  TIMERS_H_
#include "../../Utalities/std_types.h"

typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}TIMER0_Prescalar;

typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
}TIMER0_Mode_t;

void Timer_init (uint8 Mood,uint8 Prescaler );
void Timer (float num);
void Timer2 (float num);





#endif
