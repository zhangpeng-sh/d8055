#ifndef __SYS_H
#define __SYS_H	  
#include <stm32f10x.h>   

#define PAout(n)   *(vu32*)(0x42000000+(0x1080C<<5)+(n<<2))  //��� 
#define PAin(n)    *(vu32*)(0x42000000+(0x10808<<5)+(n<<2))  //���� 

#define PBout(n)   *(vu32*)(0x42000000+(0x10C0C<<5)+(n<<2))  //��� 
#define PBin(n)    *(vu32*)(0x42000000+(0x10C08<<5)+(n<<2))  //����  

								   
void Stm32_Clock_Init(void);  //ʱ�ӳ�ʼ��  
void delay_ms(u16 nms);
void delay_us(u32 nus);
#endif
