
#include"led.h"
u8 VolValue[16];

//延时,测试表明，350比较合适
u16 dt1 = 350;
//u16 dt2 = 0;

// LED引脚初始化
void led_init(void)
{ 
	//打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE,ENABLE);    


	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);  //开启AFIO时钟
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE); //禁止JTAG功能
	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;

	// 	初始化所有引脚
	GPIO_InitStructure.GPIO_Pin = OPR0|OPR1|OPR2|OPR8|OPR9|OPB0|OPB1|OPB2|OPB8|OPB9;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = OPR6|OPR7|OPR14|OPR15|OPB7|OPB14|OPB15;  
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = OPR10|OPR11|OPR12|OPR13|OPB10|OPB11|OPB12|OPB13;  
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = OPR3|OPR4|OPR5|OPB3|OPB4|OPB5|OPB6;  
	GPIO_Init(GPIOE, &GPIO_InitStructure);
  
	// 初始化关闭所有LED
	LED_RALL_OFF();
	LED_BALL_OFF();  
}

void Zero_Fifteen_Blue(void)     //16蓝灯连续扫描
{   
	LED_B0_ON();
	Delay_Us(dt1);
	VolValue[0] = Get_Adc_Average(10)>>4;
	//Delay_Us(dt2);
	LED_B0_OFF();

	LED_B1_ON();
	Delay_Us(dt1);
	VolValue[1] = Get_Adc_Average(11)>>4;
	//Delay_Us(dt2);
	LED_B1_OFF();

	LED_B2_ON();
	Delay_Us(dt1);
	VolValue[2] = Get_Adc_Average(12)>>4;
	//Delay_Us(dt2);
	LED_B2_OFF();

	LED_B3_ON();
	Delay_Us(dt1);
	VolValue[3] = Get_Adc_Average(13)>>4;
	//Delay_Us(dt2);
	LED_B3_OFF();

	LED_B4_ON();
	Delay_Us(dt1);
	VolValue[4] = Get_Adc_Average(0)>>4;
	//Delay_Us(dt2);
	LED_B4_OFF();

	LED_B5_ON();
	Delay_Us(dt1);
	VolValue[5] = Get_Adc_Average(1)>>4;
	//Delay_Us(dt2);
	LED_B5_OFF();

	LED_B6_ON();
	Delay_Us(dt1);
	VolValue[6] = Get_Adc_Average(2)>>4;
	//Delay_Us(dt2);
	LED_B6_OFF();

	LED_B7_ON();
	Delay_Us(dt1);
	VolValue[7] = Get_Adc_Average(3)>>4;
	//Delay_Us(dt2);
	LED_B7_OFF();

	LED_B8_ON();
	Delay_Us(dt1);
	VolValue[8] = Get_Adc_Average(4)>>4;
	//Delay_Us(dt2);
	LED_B8_OFF();

	LED_B9_ON();
	Delay_Us(dt1);
	VolValue[9] = Get_Adc_Average(5)>>4;
	//Delay_Us(dt2);
	LED_B9_OFF();

	LED_B10_ON();
	Delay_Us(dt1);
	VolValue[10] = Get_Adc_Average(6)>>4;
	//Delay_Us(dt2);
	LED_B10_OFF();

	LED_B11_ON();
	Delay_Us(dt1);
	VolValue[11] = Get_Adc_Average(7)>>4;
	//Delay_Us(dt2);
	LED_B11_OFF();

	LED_B12_ON();
	Delay_Us(dt1);
	VolValue[12] = Get_Adc_Average(14)>>4;
	//Delay_Us(dt2);
	LED_B12_OFF();

	LED_B13_ON();
	Delay_Us(dt1);
	VolValue[13] = Get_Adc_Average(15)>>4;
	//Delay_Us(dt2);
	LED_B13_OFF();

	LED_B14_ON();
	Delay_Us(dt1);
	VolValue[14] = Get_Adc_Average(8)>>4;
	//Delay_Us(dt2);
	LED_B14_OFF();

	LED_B15_ON();
	Delay_Us(dt1);
	VolValue[15] = Get_Adc_Average(9)>>4;
	//Delay_Us(dt2);
	LED_B15_OFF(); 
}

void Zero_Fifteen_Red(void)     //16红灯连续扫描
{   
	LED_R0_ON();
	Delay_Us(dt1);
	VolValue[0] = Get_Adc_Average(10)>>4;
	//Delay_Us(dt2);
	LED_R0_OFF();

	LED_R1_ON();
	Delay_Us(dt1);
	VolValue[1] = Get_Adc_Average(11)>>4;
	//Delay_Us(dt2);
	LED_R1_OFF();

	LED_R2_ON();
	Delay_Us(dt1);
	VolValue[2] = Get_Adc_Average(12)>>4;
	//Delay_Us(dt2);
	LED_R2_OFF();

	LED_R3_ON();
	Delay_Us(dt1);
	VolValue[3] = Get_Adc_Average(13)>>4;
	//Delay_Us(dt2);
	LED_R3_OFF();

	LED_R4_ON();
	Delay_Us(dt1);
	VolValue[4] = Get_Adc_Average(0)>>4;
	//Delay_Us(dt2);
	LED_R4_OFF();

	LED_R5_ON();
	Delay_Us(dt1);
	VolValue[5] = Get_Adc_Average(1)>>4;
	//Delay_Us(dt2);
	LED_R5_OFF();

	LED_R6_ON();
	Delay_Us(dt1);
	VolValue[6] = Get_Adc_Average(2)>>4;
	//Delay_Us(dt2);
	LED_R6_OFF();

	LED_R7_ON();
	Delay_Us(dt1);
	VolValue[7] = Get_Adc_Average(3)>>4;
	//Delay_Us(dt2);
	LED_R7_OFF();

	LED_R8_ON();
	Delay_Us(dt1);
	VolValue[8] = Get_Adc_Average(4)>>4;
	//Delay_Us(dt2);
	LED_R8_OFF();

	LED_R9_ON();
	Delay_Us(dt1);
	VolValue[9] = Get_Adc_Average(5)>>4;
	//Delay_Us(dt2);
	LED_R9_OFF();

	LED_R10_ON();
	Delay_Us(dt1);
	VolValue[10] = Get_Adc_Average(6)>>4;
	//Delay_Us(dt2);
	LED_R10_OFF();

	LED_R11_ON();
	Delay_Us(dt1);
	VolValue[11] = Get_Adc_Average(7)>>4;
	//Delay_Us(dt2);
	LED_R11_OFF();

	LED_R12_ON();
	Delay_Us(dt1);
	VolValue[12] = Get_Adc_Average(14)>>4;
	//Delay_Us(dt2);
	LED_R12_OFF();

	LED_R13_ON();
	Delay_Us(dt1);
	VolValue[13] = Get_Adc_Average(15)>>4;
	//Delay_Us(dt2);
	LED_R13_OFF();

	LED_R14_ON();
	Delay_Us(dt1);
	VolValue[14] = Get_Adc_Average(8)>>4;
	//Delay_Us(dt2);
	LED_R14_OFF();

	LED_R15_ON();
	Delay_Us(dt1);
	VolValue[15] = Get_Adc_Average(9)>>4;
	//Delay_Us(dt2);
	LED_R15_OFF(); 
}
