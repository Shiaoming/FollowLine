#include"main.h"


void can1_init(void);
char Can1_Send_Msg(unsigned char* msg,u8 len,u8 num);
void CAN1_TX_IRQHandler(void);
void CAN1_RX0_IRQHandler(void);
extern char color_sensor_infor(u8 Num1,u8 Num2);


