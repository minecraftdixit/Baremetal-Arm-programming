#include "stm32f4xx.h"                
int Period; 
int Last=0;
float frequency;
int Current =0;
//////////////////////////function prototype//////////////////////////
void generate(void);
void measure(void);

int main(void)
{
	generate();
	measure(); 
	
while(1)
{
	while(!(TIM3->SR & (1<<3))){}
		Current= TIM3->CCR3;  
		Period = Current-Last;
		Last = Current;
		frequency= 1000.0f /Period ;
}

}
////////////////////////////function for generation of frequency/////// 
void generate(void){
	RCC->AHB1ENR |= (1<<0);  	/*for PIN PA0=Timer2 channel 1  gpioA   */
	GPIOA->MODER |= 0x00000002 ; 
	GPIOA->AFR[0] |= (1<<0);  
	
	RCC->APB1ENR |= 1<<0;   /*Tim2 clock enabled */ 
	TIM2->PSC = 16000-1;   /* 16MHZ/16000   */
	TIM2->ARR = 50 -1;         /* 1000/50 = 20hz frequency  */
	
	TIM2->CCMR1 = (3<<4); 
	TIM2->CCR1 = 0 ;  
	TIM2->CCER |= (1<<0);  
	
	TIM2->CNT=0 ; 
	TIM2->CR1 |= (1<<0);  /* Enable Counter*/
}
////////////////////////////function for measurement of frequency/////// 
void measure(void){   
	RCC->AHB1ENR |= 1U<<1;   //for gpio B ( PB0 pin TIM3 channel 3 ) 
	GPIOB->MODER |= 0x00000002; // Set PB0 to alternate function mode
	GPIOB->AFR[0] |= (1<<1);   //setting AF1 pin high  
	
	RCC->APB1ENR |= 1<<1;       //Timer 3 clock enabled 
  
	TIM3->PSC = 16000-1;    //16MHZ/16000 =1000   
	TIM3->CCMR2 |= (1<<0);  //   for Channel 3
	TIM3->CCMR2 |= 1<<6;    
	TIM3->CCER |=0x0B00;     
	TIM3->CR1 = 1<<0 ;     //enable counter 
}
