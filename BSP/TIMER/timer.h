#ifndef __TIMER_H
#define __TIMER_H

#include "stm32f10x.h"

void TIM3_Init(u16 arr,u16 psc);
void TIM3_PWM_Init(u16 arr,u16 psc);
void TIM5_Cap_Init(u16 arr,u16 psc);
#endif
