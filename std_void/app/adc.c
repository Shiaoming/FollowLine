
#include"adc.h"

#include <stdint.h>


//#define ADC1_DR_Address  ((uint32_t)0X4001244C)

//#define  N   10      //每通道采10次 
//#define  M   16      //为16个通道   
//vu16  AD_Value[N][M];   //用来存放ADC转换结果，也是DMA的目标地址

void ADC_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;  //设置ADC1中IN0的管脚	 
	//DMA_InitTypeDef  DMA_InitStructure;    
	ADC_InitTypeDef ADC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|
						   RCC_APB2Periph_GPIOC|RCC_APB2Periph_ADC1,
						   ENABLE);//打开ADC1的时钟和输入通道时钟	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);//DMA时钟	
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);//配置ADC预分频值，72MHz/8 = 9MHz
	
	// ADC采集通道引脚初始化
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|
									GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;  
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;  
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|
									GPIO_Pin_4|GPIO_Pin_5;  
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	// ADC初始化
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	
	// ADC规则组初始化，ADC时钟9MHz
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,2,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_2,3,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_3,4,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_4,5,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_5,6,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_6,7,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_7,8,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_8,9,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_9,10,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_10,11,ADC_SampleTime_239Cycles5);
//    ADC_RegularChannelConfig(ADC1,ADC_Channel_11,12,ADC_SampleTime_239Cycles5);
//    ADC_RegularChannelConfig(ADC1,ADC_Channel_12,13,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_13,14,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_14,15,ADC_SampleTime_239Cycles5);
//	ADC_RegularChannelConfig(ADC1,ADC_Channel_15,16,ADC_SampleTime_239Cycles5);
    
	//使能ADC1模块DMA
//    ADC_DMACmd(ADC1, ENABLE);  
	
	/*使能ADC1*/
	ADC_Cmd(ADC1, ENABLE); 
	/*复位ADC1的校准寄存器*/
	ADC_ResetCalibration(ADC1);
	/*等待ADC1校准寄存器复位完成*/
	while(ADC_GetResetCalibrationStatus(ADC1));
	/*开始ADC1校准*/
	ADC_StartCalibration(ADC1);
	/*等待ADC1校准完成*/
	while(ADC_GetCalibrationStatus(ADC1));
	/*启动ADC1转换*/
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);	
	
	// DMA1_Channel1初始化
//	DMA_DeInit(DMA1_Channel1);	
//	DMA_InitStructure.DMA_BufferSize = M*N;
//	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
//	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&AD_Value;//定义DMA通道存储器地址
//	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//定义存储器数据宽度16位
//	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;//DMA_MemoryInc_Enable
//	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;//DMA通道操作模式位环形缓冲模式
//	DMA_InitStructure.DMA_PeripheralBaseAddr =ADC1_DR_Address;  //ADC->DR地址
//	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//定义外设数据宽度16位
//	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;//禁止DMA通道存储器到存储器传输
//	DMA_Init(DMA1_Channel1,&DMA_InitStructure);
//	DMA_Cmd(DMA1_Channel1,ENABLE);
}


u16 Get_Adc(u8 ch)  
{
	//设置指定ADC的规则组通道，一个序列，采样时间
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5 );              
	/*设置ADC1使用1-16转换通道，转换顺序1，采样时间为55.5周期*/
	ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5);
	// 等待转换完成
	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);
	
	return ADC_GetConversionValue(ADC1); 
}


u16 Get_Adc_Average(u8 ch)
{
	u32 temp_val=0;
	u8 t;
	for(t=0;t<10;t++)
	{
		temp_val += Get_Adc(ch);
	}
	return temp_val/10;
} 