#ifndef _oled_H
#define _oled_H

#include "sys.h"
#include "stdlib.h"	


#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64

#define u8 unsigned char
#define u32 unsigned int

//OLDE-IIC���߿��ƹܽŶ���
/********************************
���ſ��ԸĶ������ǸĶ���ʱ����Ҫע������ط������о��ǳ�ʼ�������Ǳ�ҲҪ�Ķ�	
********************************/
#define OLED_SCLK_Clr() GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_RESET) //GPIO_ResetBits(GPIOA,GPIO_Pin_5)//SCL
#define OLED_SCLK_Set() GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_SET) //GPIO_SetBits(GPIOA,GPIO_Pin_5)

#define OLED_SDIN_Clr() GPIO_WriteBit(GPIOB, GPIO_Pin_6, Bit_RESET) // GPIO_ResetBits(GPIOA,GPIO_Pin_7)//SDA
#define OLED_SDIN_Set() GPIO_WriteBit(GPIOB, GPIO_Pin_6, Bit_SET) // GPIO_SetBits(GPIOA,GPIO_Pin_7)


#define OLED_SCL  PBout(5)
#define OLED_SDA  PBout(6)

#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����


//OLED�����ú���
void OLED_WR_Byte(unsigned dat,unsigned cmd);
void OLED_DisplayOn(void);
void OLED_DisplayOff(void);
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y, u8 *p,u8 Char_Size);
void OLED_SetPos(unsigned char x, unsigned char y);

void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void Delay_50ms(unsigned int Del_50ms);
void Delay_1ms(unsigned int Del_1ms);
void OLED_FillPicture(unsigned char fill_Data);
void Picture(void);
void IIC_Start(void);
void IIC_Stop(void);
void IIC_WriteCommand(unsigned char IIC_Command);
void IIC_WriteData(unsigned char IIC_Data);
void IIC_WriteByte(unsigned char IIC_Byte);

void IIC_WaitAck(void);

// ���ٻ���ͼ��
void OLED_DrawBMPFast(const unsigned char BMP[]);

// ��ʾ����
void OLED_DrawGround(void);

// �����ƶ�
void OLED_DrawCloud(void);

// ����С����
void OLED_DrawDino(void);

// �����������ϰ���
void OLED_DrawCactus(void);

// ������ԾС����
int OLED_DrawDinoJump(char reset);

// ����������ֵ��������ϰ���
int OLED_DrawCactusRandom(unsigned char ver, unsigned char reset);

// ��������
void OLED_DrawRestart(void);
// ���Ʒ���
void OLED_DrawCover(void);
#endif



