/*
文件名：main.c
作者：北京交通大学 思源0702 杨孜
时间：2010 12-12
功能：
STM32应用规范主函数文件
*/


#include "includes.h"

u32 systime = 0;
u32 duty = 0;

//float VolValue;
int number = 3;
u8 ref[16];
u8 out[16];

int main(void)
{
	RCC_Configuration();  //最先初始化芯片时钟
	NVIC_Configuration();
	ADC_Configuration(); 
	can1_init();
	led_init();
	USART_Configuration();

	// 10us中断一次
	//TIM2_Init(90-1,8-1);

	while(1)
	{ 
		//蓝光
		Zero_Fifteen_Blue();
		color_sensor_infor(number,0);
		color_sensor_infor(number,0x20);
		
//		//回发上位机观察数据
//		Send_Char(0xaa);
//		Send_String(VolValue,16);	
//		Send_Char(0xbb);
		
		//红光
		Zero_Fifteen_Red();
		color_sensor_infor(number,0x40);
		color_sensor_infor(number,0x60);
		
//		//回发上位机观察数据
//		Send_Char(0xaa);
//		Send_String(VolValue,16);	
//		Send_Char(0xbb);
//					
//		Delay_Ms(10);					
    }
}
