#include "stm32f4xx.h"                


void timer3_init(void);
int main(void)
{
	RCC->AHB1ENR |= 1U<<1;  
	GPIOB->MODER = 0x00004000; 
	timer3_init() ;
	while(1)
	{
		while(!(TIM3->SR & (1<<0))){}
			TIM3->SR  &=~ 1;
			GPIOB->ODR ^= (1U << 7);
			
	}
	
}

void timer3_init(void){
	RCC->APB1ENR |= 0x00000002;   /*Tim3 clock enabled */ 
	TIM3->PSC = 16000-1;   /* 16MHZ/16000   */
	TIM3->ARR = 200 -1;         /* 1000/200 = 5hz frequency  */
	TIM3->CNT=0 ;  
  TIM3->CR1 |= 1<<0;  /* Enable Counter*/
}
