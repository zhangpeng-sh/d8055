#include "sys.h"
#include "stdio.h"
u16 data;
void TIM4_CH1_Init(void);

int main(void)
{
	Stm32_Clock_Init();
	TIM4_CH1_Init();
	while(1)
	{
		printf("Pulse Width is: %d\r\n", data);
		delay_ms(1500);
	}	
}
