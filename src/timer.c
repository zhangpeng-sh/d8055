#include "sys.h"
#include "stdio.h"
extern u16 data;

struct __FILE 
{ 
	int handle; 
}; 
FILE __stdout;        
void _sys_exit(int x) 
{ 
	x = x; 
} 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//等待上一次串口数据发送完成  
	USART1->DR = (u8) ch;      	//写DR,串口1将发送数据
	return ch;
}

void TIM4_CH1_Init(void)
{
 	RCC->APB1ENR|=1<<2;		RCC->APB2ENR|=3<<2|1<<14; NVIC->ISER[0] = 1<<30;
	USART1->BRR = 0x271;	USART1->CR1 = 0x2008;	GPIOA->CRH = 0x444444B4;
 	TIM4->ARR=0xFFFF;		TIM4->PSC=71;	TIM4->CCMR1|=1<<0;		TIM4->CCER = 1<<0;	TIM4->DIER = 2;	TIM4->CR1|=0x01;
}


void TIM4_IRQHandler(void)
{
	if(!PBin(6))		//捕获了下降沿
	{
		TIM4->CNT = 0;
		TIM4->CCER &= ~(1<<1);
	}
	else				//捕获了上升沿
	{
		data = TIM4->CCR1;
		TIM4->CCER |= 1<<1;
	}
	TIM4->SR = 0;
}
