
#include "main.h"

//usart GPIOA
#define   TX   GPIO_Pin_9
#define   RX   GPIO_Pin_10

void USART_Configuration(void);
void Send_Char(u8 Char);
void Send_String(u8 *pData,char len);