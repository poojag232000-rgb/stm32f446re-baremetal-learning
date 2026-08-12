#include <stdint.h>
#include "stm32f446xx.h"

volatile uint32_t ticks = 0U;

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF;
        ticks++;

        if (ticks >= 50U)
        {
            ticks = 0U;
            GPIOA->ODR ^= (1U << 5);
        }
    }
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    /* PA5: onboard LED output. */
    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |= (1U << 10);

    /* 16 MHz / 16000 = 1 kHz counter (1 count per ms).
       ARR = 9 produces one update interrupt every 10 ms. */
    TIM2->PSC = 15999U;
    TIM2->ARR = 9U;
    TIM2->CNT = 0U;
    TIM2->EGR = TIM_EGR_UG;
    TIM2->SR = 0U;

    TIM2->DIER |= TIM_DIER_UIE;
    NVIC_EnableIRQ(TIM2_IRQn);
    TIM2->CR1 |= TIM_CR1_CEN;

    while (1)
    {
        /* The CPU remains available between timer interrupts. */
    }
}
