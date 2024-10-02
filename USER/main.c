#include "delay.h"
#include "key.h"
#include "usart.h"
#include "timer.h"
#include "oled.h"
#include "stdlib.h"

//GND  接电源地
//VCC  接5V或3.3v电源
//b5  接(SCL)
//b6  接(SDA)

//void SystemClock_Config(void); // 时钟配置声明

int Key_Scan()
{
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)==1)
	{
				return 1;
		}

	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==1)
	{
			return 2;
		}
	return 0;
}

int main(void)
{		
	unsigned char key_num = 0;
	unsigned char cactus_category = 0;
	unsigned char cactus_length = 8;
	unsigned int score = 0;
	unsigned int highest_score = 0;
	int height = 0;
	int cactus_pos = 128;
	unsigned char cur_speed = 30;
	char failed = 0;
	char reset = 0;
	
	 delay_init();	    	 //延时函数初始化	  
	 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	 OLED_Init(); //OLED初始化
	 KEY_Init();
  OLED_ShowString(0,0,"Test",4);
	OLED_DrawCover();
   while(Key_Scan()!=2);
	delay_ms(100);
	OLED_Clear();
  while (1)
  {
    /* USER CODE END WHILE */


		if (failed == 1)
		{
			OLED_DrawRestart();

			key_num = Key_Scan();
			if (key_num == 2)
			{
				if(score > highest_score) highest_score = score;
				score = 0;
				failed = 0;
				height = 0;
				reset = 1;
				OLED_DrawDinoJump(reset);
				OLED_DrawCactusRandom(cactus_category, reset);
				OLED_Clear();
			}
			continue;
		}


		score ++;
		if (height <= 0) key_num = Key_Scan();

		OLED_DrawGround();
		OLED_DrawCloud();

		if (height>0 || key_num == 1) height = OLED_DrawDinoJump(reset);
		else OLED_DrawDino();

		cactus_pos = OLED_DrawCactusRandom(cactus_category, reset);
		if(cactus_category == 0) cactus_length = 8;
		else if(cactus_category == 1) cactus_length = 16;
		else cactus_length = 24;

		if (cactus_pos + cactus_length < 0)
		{
		  cactus_category = rand()%4;
			OLED_DrawCactusRandom(cactus_category, 1);
		}

		if ((height < 16) && ( (cactus_pos>=16 && cactus_pos <=32) || (cactus_pos + cactus_length>=16 && cactus_pos + cactus_length <=32)))
		{
			failed = 1;
		}

		OLED_ShowString(35, 0, "HI:", 12);
		OLED_ShowNum(58, 0, highest_score, 5, 12);
		OLED_ShowNum(98, 0, score, 5, 12);


		reset = 0;

		cur_speed = score/20;
		if (cur_speed > 29) cur_speed = 29;
		delay_ms(30 - cur_speed);
		key_num = 0;

  }

}


 

