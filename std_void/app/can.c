#include"can.h"

#define MAX_MAIL_NUM2  3
static u8 CAN1_msg_num[MAX_MAIL_NUM2];   // 发送邮箱标记

void can1_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap1_CAN,ENABLE);
	
	/* Configure CAN pin: RX */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	/* Configure CAN pin: TX */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	
//	NVIC_InitTypeDef NVIC_InitStructure;
//	NVIC_InitStructure.NVIC_IRQChannel =USB_LP_CAN_RX0_IRQChannel;//CAN_RX1_IRQChannel;//(yougaidong)
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	NVIC_Init(&NVIC_InitStructure);
	
	
	CAN_InitTypeDef CAN_InitStructure;
	CAN_FilterInitTypeDef CAN_FilterInitStructure;
	//  CAN_DeInit(CAN); 
	CAN_StructInit(&CAN_InitStructure);
	CAN_InitStructure.CAN_TTCM=DISABLE;
	CAN_InitStructure.CAN_ABOM=DISABLE; 
	CAN_InitStructure.CAN_AWUM=DISABLE;
	CAN_InitStructure.CAN_NART=DISABLE;
	CAN_InitStructure.CAN_RFLM=DISABLE;
	CAN_InitStructure.CAN_TXFP=ENABLE;
	CAN_InitStructure.CAN_Mode=CAN_Mode_Normal;//CAN_Mode_Silent;//CAN_Mode_Normal;//CAN_Mode_LoopBack;//
	CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;
	CAN_InitStructure.CAN_BS1=CAN_BS1_10tq;
	CAN_InitStructure.CAN_BS2=CAN_BS2_1tq;
	CAN_InitStructure.CAN_Prescaler=3;//（36/(1+10+1)/3）
	CAN_Init(&CAN_InitStructure);
	
	
	
	CAN_FilterInitStructure.CAN_FilterNumber=0;
	CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;//CAN_FilterMode_IdList; 
	//CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdList;
	CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit; 
	CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000; //适用TxMessage.StdId=0x13;
	
	CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000; 
	CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
	/*屏蔽寄存器0 表示屏蔽，1 表示不屏蔽*/
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FIFO0;
	CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;
	CAN_FilterInit(&CAN_FilterInitStructure);
	
	CAN_ITConfig(CAN_IT_FMP0,ENABLE);
	
}
/*******************************************************************************
函 数 名：Can1_Send_Msg(char* msg,u8 len,u8 num)
描    述：CAN发送一组数据(固定格式:ID为0X600+num,标准帧,数据帧)
输入参数： 	msg:待发送的发送数据结构体的地址
		len:发送数据的长度
		num:运动控制器编号
返 回 值： 	0,成功；
			-4,NO MailBox
*******************************************************************************/
char Can1_Send_Msg(unsigned char* msg,u8 len,u8 num)
{

	CanTxMsg TxMessage;
	u8 mbox;
	u32 i=0;

	TxMessage.StdId = num;	// 标准标识符
	TxMessage.ExtId = 0x00000000;	// 设置扩展标示符（29位）
	TxMessage.IDE = CAN_ID_STD;		// 使用标准标识符
	TxMessage.RTR = CAN_RTR_DATA;	// 消息类型为数据帧，一帧8位
	TxMessage.DLC = len;			// 发送信息的长度
	for(i = 0;i < len;i++)
		TxMessage.Data[i] = msg[i];


	// 等待一个空的CAN发送邮箱
	//while(((CAN2->TSR&CAN_TSR_TME0) != CAN_TSR_TME0)\
		&&((CAN2->TSR&CAN_TSR_TME1) != CAN_TSR_TME1)\
		&&((CAN2->TSR&CAN_TSR_TME1) != CAN_TSR_TME1));

	mbox = CAN_Transmit(&TxMessage);


	CAN1_msg_num[mbox] = 1;
	

	CAN_ITConfig( CAN_IT_TME, ENABLE);


	return 0;
}




/*******************************************************************************
函 数 名：CAN1_TX_IRQHandler(void)
描    述：CAN1发送中断
*******************************************************************************/
void CAN1_TX_IRQHandler(void)
{
	
    if(CAN1_msg_num[0])
    {
        if(SET == CAN_GetITStatus(CAN_IT_RQCP0))
        {
            CAN_ClearITPendingBit(CAN_IT_RQCP0);
            CAN_ITConfig( CAN_IT_TME, DISABLE);
            CAN1_msg_num[0] = 0;
        }
    }

    if(CAN1_msg_num[1])
    {
        if(SET == CAN_GetITStatus(CAN_IT_RQCP1))
        {
            CAN_ClearITPendingBit(CAN_IT_RQCP1);
            CAN_ITConfig(CAN_IT_TME, DISABLE);
            CAN1_msg_num[1] = 0;
        }
    }

    if(CAN1_msg_num[2])
    {
        if(SET == CAN_GetITStatus(CAN_IT_RQCP2))
        {
            CAN_ClearITPendingBit(CAN_IT_RQCP2);
            CAN_ITConfig(CAN_IT_TME, DISABLE);
            CAN1_msg_num[2] = 0;
        }
    }
   
}

/*******************************************************************************
函 数 名：CAN1_RX0_IRQHandler(void)
描    述：CAN接收数据中断
*******************************************************************************/
void CAN1_RX0_IRQHandler(void)
{


	if(SET == CAN_GetITStatus(CAN_IT_FF0))
   	{
        CAN_ClearITPendingBit(CAN_IT_FF0);
   	}
   	else if(SET == CAN_GetITStatus(CAN_IT_FOV0))
   	{
        CAN_ClearITPendingBit(CAN_IT_FOV0);
   	}
   	else
  	{
		CanRxMsg RxMessage;
		CAN_Receive( CAN_FIFO0, &RxMessage);
    }

}
/*******************************************************************************
函 数 名：color_sensor_infor(u8 Num1,u8 Num2)
描    述：颜色传感器信息传输
输入参数：	Num1：巡线板编号
                Num2：巡线板硬件信息
		
返 回 值：0:成功，-1：发送失败，-2：等待接收超时，-3：接收数据错误
*******************************************************************************/
char color_sensor_infor(u8 Num1,u8 Num2)
{
	unsigned char tmp[8];

	if((Num2&0x20)==0x00)    //低8位
	{
		tmp[0] = VolValue[0];tmp[1] = VolValue[1];tmp[2] = VolValue[2];
		tmp[3] = VolValue[3];tmp[4] = VolValue[4];tmp[5] = VolValue[5];
		tmp[6] = VolValue[6];tmp[7] = VolValue[7];
	}
	else                     //高8位
	{
		tmp[0] = VolValue[8];tmp[1] = VolValue[9];tmp[2] = VolValue[10];
		tmp[3] = VolValue[11];tmp[4] = VolValue[12];tmp[5] = VolValue[13];
		tmp[6] = VolValue[14];tmp[7] = VolValue[15];
	}
	Can1_Send_Msg(tmp,8,0x400 + Num1 + Num2);

	return 0;
}
