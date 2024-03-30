#include "stm32f4xx.h"                  
 void initGPIO(void);
void delay(int) ; 
void initGPIO(void)
	{
		/*for gpio B
		*/
	RCC->AHB1ENR |= 1U<<1;  
		/*for gpio A
	 
		RCC->AHB1ENR |= 1U<<0;
    Set GPIOA->MODER to a specific value  
    GPIOA->MODER = 0x00000000; 

  Set GPIOB->MODER to a specific value */
    GPIOB->MODER = 0x00004000; 
	}
	void delay(int ms)
{ int i ; 
 
    for(  i=0; i<ms*4000; i++);
}
	int main (void){
		 
		initGPIO() ;
		 
			/* btnp= (GPIOA-> IDR & (1U<< 0));
		 }
		 
		 GPIOB->ODR |= (1U << 7);
		*/
		
		 while(1)
    {
        /* Toggle GPIOB pin 7 */
        GPIOB->ODR ^= (1U << 7);

        /* Delay for 500 ms */
        delay(100);
    }
 	
	}