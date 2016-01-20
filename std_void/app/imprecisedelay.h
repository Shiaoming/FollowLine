#ifndef __IMPRESISEDELAY_H
#define __UIMPRESISEDELAY_H

#include "main.h"

extern u32 systime;

void Delay_Us(u16 myUs);
void Delay_Ms(u16 myMs);
void TIM2_Init(u16 arr,u16 psc);

#endif /* __IMPRESISEDELAY_H*/