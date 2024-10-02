#include "exit.h"
#include "delay.h"
#include "led.h"

/*********************************
函数名称：void EXTI_INIT()
函数功能：初始化PE3 PE4的中断配置
**********************************/
void EXTI_INIT()
{
	GPIO_InitTypeDef 		GPIO_InitStructure;//GPIO的结构体定义
	EXTI_InitTypeDef 		EXTI_InitStructure;//中断的结构体定义
	NVIC_InitTypeDef	  NVIC_InitStructure;//中断控制器结构体定义
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO,ENABLE);//使能时钟GPIOE和复用时钟
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//使用GPIO引脚上拉
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;		//GPIO的引脚设置
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;		//GPIO引脚的速率
	GPIO_Init(GPIOE,&GPIO_InitStructure);		//初始化GPIOE.4
	
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//使用GPIO引脚上拉
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;//GPIO的引脚设置
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//GPIO引脚的速率
	GPIO_Init(GPIOE,&GPIO_InitStructure);//初始化GPIOE.3
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);//把引脚跟中断联系起来的一个函数，如果是PA9，这个地方就是GPIO_PortSourceGPIOA，GPIO_PinSource9
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);//把引脚跟中断联系起来的一个函数，
	
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;//中断方式，外部中断
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//中断的方式，下降沿
	EXTI_InitStructure.EXTI_Line=EXTI_Line4;//中断线 line4
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;//中断使能
	EXTI_Init(&EXTI_InitStructure);//初始化中断
	
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;//中断方式，外部中断
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//中断的方式，下降沿
	EXTI_InitStructure.EXTI_Line=EXTI_Line3;//中断线 line3
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;//中断使能
	EXTI_Init(&EXTI_InitStructure);//初始化中断
	

	NVIC_InitStructure.NVIC_IRQChannel=EXTI4_IRQn;//中断的组
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//中断控制器使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;//抢占优先级为0，数字越低，中断优先级越高
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;//响应优先级
	NVIC_Init(&NVIC_InitStructure);//初始化中断控制器
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI3_IRQn;//中断的组
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//中断控制器使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;//抢占优先级为0，数字越低，中断优先级越高
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;//响应优先级
	NVIC_Init(&NVIC_InitStructure);//初始化中断控制器
}
/*********************************
函数名称：void EXTI4_IRQHandler()
函数功能：PE4的中断服务函数
**********************************/

void EXTI4_IRQHandler()
{
		delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)//判断PE4是否真的按下
		{
			delay_ms(10);//消抖
			if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)
			{
				LED0_ON;
				EXTI_ClearITPendingBit(EXTI_Line4); //清楚中断标志位
			}
				
		}
}
/*********************************
函数名称：void EXTI3_IRQHandler()
函数功能：PE3的中断服务函数
**********************************/
void EXTI3_IRQHandler()
{
		delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)
		{
			delay_ms(10);
			if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)
			{
				LED0_OFF;
				EXTI_ClearITPendingBit(EXTI_Line3); 
			}
				
		}
		
}




