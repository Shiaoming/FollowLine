/*
文件名：sys_ini.h
作者：北京交通大学 思源0702 杨孜
功能：STM32专用的初始化文件，完成基本初始化功能，达到简化主函数的目的

*/
#ifndef SYS_INI_H
#define SYS_INI_H

#include "main.h"
#include "stm32f10x_conf.h"

void RCC_Configuration(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);

#endif
