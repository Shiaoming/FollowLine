#include"main.h"



/// LED引脚宏定义
//GPIOB
#define   OPB0    GPIO_Pin_4
#define   OPB1    GPIO_Pin_6
#define   OPB2    GPIO_Pin_8
#define   OPB8    GPIO_Pin_12
#define   OPB9    GPIO_Pin_14

#define   OPR0    GPIO_Pin_5
#define   OPR1    GPIO_Pin_7
#define   OPR2    GPIO_Pin_9
#define   OPR8    GPIO_Pin_13
#define   OPR9    GPIO_Pin_15

//GPIOC
#define   OPB7   GPIO_Pin_14
#define   OPB14   GPIO_Pin_6
#define   OPB15   GPIO_Pin_8

#define   OPR6    GPIO_Pin_13
#define   OPR7    GPIO_Pin_15
#define   OPR14    GPIO_Pin_7
#define   OPR15    GPIO_Pin_9

//GPIOD
#define   OPB10   GPIO_Pin_8
#define   OPB11   GPIO_Pin_10
#define   OPB12   GPIO_Pin_12
#define   OPB13   GPIO_Pin_14

#define   OPR10    GPIO_Pin_9
#define   OPR11    GPIO_Pin_11
#define   OPR12    GPIO_Pin_13
#define   OPR13    GPIO_Pin_15

//GPIOE
#define   OPB3    GPIO_Pin_0
#define   OPB4    GPIO_Pin_2
#define   OPB5    GPIO_Pin_4
#define   OPB6    GPIO_Pin_6

#define   OPR3    GPIO_Pin_1
#define   OPR4    GPIO_Pin_3
#define   OPR5    GPIO_Pin_5


/// 不同LED开关宏定义
// 红灯开
#define 	LED_R0_ON()			GPIO_ResetBits(GPIOB,OPR0)
#define 	LED_R1_ON()			GPIO_ResetBits(GPIOB,OPR1)
#define 	LED_R2_ON()			GPIO_ResetBits(GPIOB,OPR2)
#define 	LED_R3_ON()			GPIO_ResetBits(GPIOE,OPR3)
#define 	LED_R4_ON()			GPIO_ResetBits(GPIOE,OPR4)
#define 	LED_R5_ON()			GPIO_ResetBits(GPIOE,OPR5)
#define 	LED_R6_ON()			GPIO_ResetBits(GPIOC,OPR6)
#define 	LED_R7_ON()			GPIO_ResetBits(GPIOC,OPR7)
#define 	LED_R8_ON()			GPIO_ResetBits(GPIOB,OPR8)
#define 	LED_R9_ON()			GPIO_ResetBits(GPIOB,OPR9)
#define 	LED_R10_ON()		GPIO_ResetBits(GPIOD,OPR10)
#define 	LED_R11_ON()		GPIO_ResetBits(GPIOD,OPR11)
#define 	LED_R12_ON()		GPIO_ResetBits(GPIOD,OPR12)
#define 	LED_R13_ON()		GPIO_ResetBits(GPIOD,OPR13)
#define 	LED_R14_ON()		GPIO_ResetBits(GPIOC,OPR14)
#define 	LED_R15_ON()		GPIO_ResetBits(GPIOC,OPR15)
#define 	LED_RALL_ON()		{GPIO_ResetBits(GPIOB,OPR0|OPR1|OPR2|OPR8|OPR9);\
								GPIO_ResetBits(GPIOC,OPR6|OPR7|OPR14|OPR15);\
								GPIO_ResetBits(GPIOD,OPR10|OPR11|OPR12|OPR13);\
								GPIO_ResetBits(GPIOE,OPR3|OPR4|OPR5);}
// 红灯关
#define 	LED_R0_OFF()		GPIO_SetBits(GPIOB,OPR0)
#define 	LED_R1_OFF()		GPIO_SetBits(GPIOB,OPR1)
#define 	LED_R2_OFF()		GPIO_SetBits(GPIOB,OPR2)
#define 	LED_R3_OFF()		GPIO_SetBits(GPIOE,OPR3)
#define 	LED_R4_OFF()		GPIO_SetBits(GPIOE,OPR4)
#define 	LED_R5_OFF()		GPIO_SetBits(GPIOE,OPR5)
#define 	LED_R6_OFF()		GPIO_SetBits(GPIOC,OPR6)
#define 	LED_R7_OFF()		GPIO_SetBits(GPIOC,OPR7)
#define 	LED_R8_OFF()		GPIO_SetBits(GPIOB,OPR8)
#define 	LED_R9_OFF()		GPIO_SetBits(GPIOB,OPR9)
#define 	LED_R10_OFF()		GPIO_SetBits(GPIOD,OPR10)
#define 	LED_R11_OFF()		GPIO_SetBits(GPIOD,OPR11)
#define 	LED_R12_OFF()		GPIO_SetBits(GPIOD,OPR12)
#define 	LED_R13_OFF()		GPIO_SetBits(GPIOD,OPR13)
#define 	LED_R14_OFF()		GPIO_SetBits(GPIOC,OPR14)
#define 	LED_R15_OFF()		GPIO_SetBits(GPIOC,OPR15)
#define 	LED_RALL_OFF()		{GPIO_SetBits(GPIOB,OPR0|OPR1|OPR2|OPR8|OPR9);\
								GPIO_SetBits(GPIOC,OPR6|OPR7|OPR14|OPR15);\
								GPIO_SetBits(GPIOD,OPR10|OPR11|OPR12|OPR13);\
								GPIO_SetBits(GPIOE,OPR3|OPR4|OPR5);}
// 蓝灯开
#define 	LED_B0_ON()			GPIO_ResetBits(GPIOB,OPB0)
#define 	LED_B1_ON()			GPIO_ResetBits(GPIOB,OPB1)
#define 	LED_B2_ON()			GPIO_ResetBits(GPIOB,OPB2)
#define 	LED_B3_ON()			GPIO_ResetBits(GPIOE,OPB3)
#define 	LED_B4_ON()			GPIO_ResetBits(GPIOE,OPB4)
#define 	LED_B5_ON()			GPIO_ResetBits(GPIOE,OPB5)
#define 	LED_B6_ON()			GPIO_ResetBits(GPIOE,OPB6)
#define 	LED_B7_ON()			GPIO_ResetBits(GPIOC,OPB7)
#define 	LED_B8_ON()			GPIO_ResetBits(GPIOB,OPB8)
#define 	LED_B9_ON()			GPIO_ResetBits(GPIOB,OPB9)
#define 	LED_B10_ON()		GPIO_ResetBits(GPIOD,OPB10)
#define 	LED_B11_ON()		GPIO_ResetBits(GPIOD,OPB11)
#define 	LED_B12_ON()		GPIO_ResetBits(GPIOD,OPB12)
#define 	LED_B13_ON()		GPIO_ResetBits(GPIOD,OPB13)
#define 	LED_B14_ON()		GPIO_ResetBits(GPIOC,OPB14)
#define 	LED_B15_ON()		GPIO_ResetBits(GPIOC,OPB15)
#define 	LED_BALL_ON()		{GPIO_ResetBits(GPIOB,OPB0|OPB1|OPB2|OPB8|OPB9);\
								GPIO_ResetBits(GPIOC,OPB7|OPB14|OPB15);\
								GPIO_ResetBits(GPIOD,OPB10|OPB11|OPB12|OPB13);\
								GPIO_ResetBits(GPIOE,OPB3|OPB4|OPB5|OPB6);}
// 蓝灯关
#define 	LED_B0_OFF()		GPIO_SetBits(GPIOB,OPB0)
#define 	LED_B1_OFF()		GPIO_SetBits(GPIOB,OPB1)
#define 	LED_B2_OFF()		GPIO_SetBits(GPIOB,OPB2)
#define 	LED_B3_OFF()		GPIO_SetBits(GPIOE,OPB3)
#define 	LED_B4_OFF()		GPIO_SetBits(GPIOE,OPB4)
#define 	LED_B5_OFF()		GPIO_SetBits(GPIOE,OPB5)
#define 	LED_B6_OFF()		GPIO_SetBits(GPIOE,OPB6)
#define 	LED_B7_OFF()		GPIO_SetBits(GPIOC,OPB7)
#define 	LED_B8_OFF()		GPIO_SetBits(GPIOB,OPB8)
#define 	LED_B9_OFF()		GPIO_SetBits(GPIOB,OPB9)
#define 	LED_B10_OFF()		GPIO_SetBits(GPIOD,OPB10)
#define 	LED_B11_OFF()		GPIO_SetBits(GPIOD,OPB11)
#define 	LED_B12_OFF()		GPIO_SetBits(GPIOD,OPB12)
#define 	LED_B13_OFF()		GPIO_SetBits(GPIOD,OPB13)
#define 	LED_B14_OFF()		GPIO_SetBits(GPIOC,OPB14)
#define 	LED_B15_OFF()		GPIO_SetBits(GPIOC,OPB15)
#define 	LED_BALL_OFF()		{GPIO_SetBits(GPIOB,OPB0|OPB1|OPB2|OPB8|OPB9);\
								GPIO_SetBits(GPIOC,OPB7|OPB14|OPB15);\
								GPIO_SetBits(GPIOD,OPB10|OPB11|OPB12|OPB13);\
								GPIO_SetBits(GPIOE,OPB3|OPB4|OPB5|OPB6);}

extern u8 VolValue[16];
void led_init(void);
void Zero_Fifteen_Blue(void);
void Zero_Fifteen_Red(void) ;