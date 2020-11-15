#include "sys.h" 
void Stm32_Clock_Init(void)
{
	RCC->APB1RSTR = 0;			RCC->APB2RSTR = 0;
	RCC->AHBENR = 0x00000014;	RCC->CR = 0x00000081;	
	RCC->CIR = 0x0;				SCB->VTOR = 0x08000000;
 	RCC->CR|= 1<<16;			while(!(RCC->CR>>17));
	RCC->CFGR=0X001D0400; 		FLASH->ACR|=0x32;
	RCC->CR|=	1<<24;			while(!(RCC->CR>>25));
	RCC->CFGR|=0x02;			while((RCC->CFGR&0x08)!=0x08);
//	SCB->AIRCR = 0x05FA0500;
}	
void delay_ms(u16 nms)
{
	SysTick->LOAD = 9000*nms;
	SysTick->VAL  = 0;
	SysTick->CTRL = 1;
	while(!(SysTick->CTRL&1<<16) && SysTick->CTRL & 1);
	SysTick->CTRL = 0;
	
}
void delay_us(u32 nus)
{
	SysTick->LOAD = 9000*nus;
	SysTick->VAL  = 0;
	SysTick->CTRL = 1;
	while(!(SysTick->CTRL&1<<16) && SysTick->CTRL & 1);
	SysTick->CTRL = 0;	
}
