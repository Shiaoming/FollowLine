/*
systime.c

北京交通大学 思源0702 杨孜
15:40 2010-2-8

使用systick作为系统时钟
*/
#include "includes.h"

void systime_initial(void)
{
  /* SysTick end of count event each 10ms with input clock equal to 9MHz (HCLK/8, default) */
  SysTick_SetReload(90000);
  /* Enable SysTick interrupt */
  SysTick_ITConfig(ENABLE);
  SysTick_CounterCmd(SysTick_Counter_Enable);
}
void SysTickHandler(void)
{
//  SYS_time++;   //时钟运行
//  SYS_idle_dis=SYS_idle;
//  SYS_idle=0;
//  if(!(SYS_time & 7))
//  {
//    PCo+=0x00000010;
//  }
}


