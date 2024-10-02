#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

#define LED0_ON  GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define LED0_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_5)

void LED_Init(void);//≥ı ºªØ

		 				    
#endif
