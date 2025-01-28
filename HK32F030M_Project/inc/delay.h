#ifndef __DELAY_H
#define __DELAY_H

#include <stdio.h>
#include <stdint.h>

void SysTick_Init(void);
void Delay_ms(volatile uint32_t nms);
void Delay_10us(volatile uint32_t nus);
void TimingDelay_Decrement(void);

#endif
