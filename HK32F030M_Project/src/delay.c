#include "delay.h"
#include "hk32f030m.h" 

volatile static uint32_t TimingDelay;

void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms????
	 * SystemFrequency / 100000	 10us????
	 * SystemFrequency / 1000000 1us????
	 */
	if (SysTick_Config(SystemCoreClock / 100000))	
	{ 
		/* Capture error */ 
		while (1);
	}
}

//延时毫秒
void Delay_ms(volatile uint32_t nms)
{
    //SYSTICK分频--1ms的系统时钟中断
	uint32_t i;	
	SysTick_Config(SystemCoreClock/1000);
	
	for(i=0;i<nms;i++)
	{
		// ?????????0???,CRTL?????16??1
		// ??1?,??????0
		while( !((SysTick->CTRL)&(1<<16)) );
	}
	// ??SysTick???
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}


//延时微妙
void Delay_10us(volatile uint32_t nus)
{
	TimingDelay = nus;	

	// ???????  
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;

	while(TimingDelay != 0);
}

void TimingDelay_Decrement(void){
	if(TimingDelay != 0x00){
		TimingDelay--;
	}
}
