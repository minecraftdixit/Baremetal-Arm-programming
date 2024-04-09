#include "stm32f4xx.h"                
#define Avg_Slope 0.0025
#define V25 0.76  
int main(void)
	{
	volatile  float vsense; 
  volatile uint32_t temp;
	volatile  float temp_celsius;
	RCC->APB2ENR |= 0x100;  /*  //enable clock for ADC1*/  
	
 	ADC1->SQR3 |=(1U<<4);               /*: 1st conversion in regular sequence*/
	ADC1->SQR1 = 0x00;               /* conversion length 1 sequence */
	  ADC->CCR |=ADC_CCR_TSVREFE;    /* temperature sensor activate */
	ADC1->CR2 |=ADC_CR2_ADON;               /*enable adc conversion */
	 
 
	 

ADC1->CR2 |= 1U<<1 ; /*enable continuous conversion  */
 
ADC1->CR2 |= 0x40000000;  /*start the adc conversion */
 
 
	while (1)
	{
	   while(!(ADC1->SR & ADC_SR_EOC)){};
      temp = ADC1->DR;
vsense = ((float)temp / 4095) * 3.3;   /*typical Vdd=3.3V */
			 temp_celsius = ((vsense - V25) / Avg_Slope) + 25;
 
}
	}