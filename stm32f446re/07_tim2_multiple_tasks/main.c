#include <stdint.h>
#include "stm32f446xx.h"

volatile uint32_t led_ticks = 0U;
volatile uint32_t one_second_ticks = 0U;
volatile uint32_t seconds = 0U;

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF;

        led_ticks++;
        one_second_ticks++;

        if (led_ticks >= 50U)
        {
            led_ticks = 0U;
            GPIOA->ODR ^= (1U << 5);
        }

        if (one_second_ticks >= 100U)
        {
            one_second_ticks = 0U;
            seconds++;
        }
    }
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |= (1U << 10);

    /* 16 MHz / 16000 = 1 kHz; ARR = 9 gives a 10 ms interrupt. */
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
        /* Add foreground work here; the timer continues scheduling tasks. */
    }
}
