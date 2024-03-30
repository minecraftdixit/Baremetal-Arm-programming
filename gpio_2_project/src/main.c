#include "stm32f4xx.h"                  
 void initGPIO(void);
void delay(int) ; 
void initGPIO(void)
	{
		/*for gpio B
		*/
	RCC->AHB1ENR |= 1U<<1;  
		/*for gpio c
	 */
		RCC->AHB1ENR |= 1U<<2;
    /*Set GPIOA->MODER to a specific value  */
    GPIOC->MODER = 0x00000000; 

  /*Set GPIOB->MODER to a specific value */
    GPIOB->MODER = 0x00004000; 
	}
	 
	int main (void){
		 int btnp= 0 ; 
		initGPIO() ;
		 
		while(!btnp){
			btnp= (GPIOC->IDR & (1U<< 13));
		 }
		 
		 GPIOB->ODR |= (1U << 7);
		
 	
	}