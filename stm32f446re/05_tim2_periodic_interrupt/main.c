#include <stdint.h>
#include "stm32f446xx.h"

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF;
        GPIOA->ODR ^= (1U << 5);
    }
}

int main(void)
{
    /* Enable GPIOA for the onboard LED and TIM2 on APB1. */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    /* PA5: general-purpose output. */
    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |= (1U << 10);

    /* TIM2 clock is 16 MHz with the reset clock configuration.
       Divide it to a 1 kHz counter, then overflow after 1000 counts. */
    TIM2->PSC = 15999U;
    TIM2->ARR = 999U;
    TIM2->CNT = 0U;

    /* Load the prescaler immediately, then discard the generated event. */
    TIM2->EGR = TIM_EGR_UG;
    TIM2->SR = 0U;

    TIM2->DIER |= TIM_DIER_UIE;
    NVIC_EnableIRQ(TIM2_IRQn);
    TIM2->CR1 |= TIM_CR1_CEN;

    while (1)
    {
        /* TIM2 continues counting while the CPU is free. */
    }
}
