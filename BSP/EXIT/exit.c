#include "exit.h"
#include "delay.h"
#include "led.h"

/*********************************
�������ƣ�void EXTI_INIT()
�������ܣ���ʼ��PE3 PE4���ж�����
**********************************/
void EXTI_INIT()
{
	GPIO_InitTypeDef 		GPIO_InitStructure;//GPIO�Ľṹ�嶨��
	EXTI_InitTypeDef 		EXTI_InitStructure;//�жϵĽṹ�嶨��
	NVIC_InitTypeDef	  NVIC_InitStructure;//�жϿ������ṹ�嶨��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_AFIO,ENABLE);//ʹ��ʱ��GPIOE�͸���ʱ��
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//ʹ��GPIO��������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;		//GPIO����������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;		//GPIO���ŵ�����
	GPIO_Init(GPIOE,&GPIO_InitStructure);		//��ʼ��GPIOE.4
	
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//ʹ��GPIO��������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;//GPIO����������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//GPIO���ŵ�����
	GPIO_Init(GPIOE,&GPIO_InitStructure);//��ʼ��GPIOE.3
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);//�����Ÿ��ж���ϵ������һ�������������PA9������ط�����GPIO_PortSourceGPIOA��GPIO_PinSource9
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource3);//�����Ÿ��ж���ϵ������һ��������
	
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;//�жϷ�ʽ���ⲿ�ж�
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//�жϵķ�ʽ���½���
	EXTI_InitStructure.EXTI_Line=EXTI_Line4;//�ж��� line4
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;//�ж�ʹ��
	EXTI_Init(&EXTI_InitStructure);//��ʼ���ж�
	
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;//�жϷ�ʽ���ⲿ�ж�
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;//�жϵķ�ʽ���½���
	EXTI_InitStructure.EXTI_Line=EXTI_Line3;//�ж��� line3
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;//�ж�ʹ��
	EXTI_Init(&EXTI_InitStructure);//��ʼ���ж�
	

	NVIC_InitStructure.NVIC_IRQChannel=EXTI4_IRQn;//�жϵ���
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//�жϿ�����ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�Ϊ0������Խ�ͣ��ж����ȼ�Խ��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;//��Ӧ���ȼ�
	NVIC_Init(&NVIC_InitStructure);//��ʼ���жϿ�����
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI3_IRQn;//�жϵ���
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//�жϿ�����ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�Ϊ0������Խ�ͣ��ж����ȼ�Խ��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=2;//��Ӧ���ȼ�
	NVIC_Init(&NVIC_InitStructure);//��ʼ���жϿ�����
}
/*********************************
�������ƣ�void EXTI4_IRQHandler()
�������ܣ�PE4���жϷ�����
**********************************/

void EXTI4_IRQHandler()
{
		delay_ms(10);
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)//�ж�PE4�Ƿ���İ���
		{
			delay_ms(10);//����
			if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)
			{
				LED0_ON;
				EXTI_ClearITPendingBit(EXTI_Line4); //����жϱ�־λ
			}
				
		}
}
/*********************************
�������ƣ�void EXTI3_IRQHandler()
�������ܣ�PE3���жϷ�����
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




