#include <stdint.h>
#include "stm32f446xx.h"

void EXTI15_10_IRQHandler(void)
{
    if (EXTI->PR & (1U << 13))
    {
        /* Write 1 to clear EXTI line 13's pending flag. */
        EXTI->PR = (1U << 13);
        GPIOA->ODR ^= (1U << 5);
    }
}

int main(void)
{
    /* Enable GPIOA, GPIOC, and the System Configuration controller. */
    RCC->AHB1ENR |= (1U << 0);
    RCC->AHB1ENR |= (1U << 2);
    RCC->APB2ENR |= (1U << 14);

    /* PA5 is the LED output. */
    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |= (1U << 10);

    /* PC13 is the blue-button input. */
    GPIOC->MODER &= ~(3U << 26);

    /* Route PC13 to external-interrupt line 13. */
    SYSCFG->EXTICR[3] &= ~(0xFU << 4);
    SYSCFG->EXTICR[3] |= (2U << 4);

    /* Unmask EXTI13 and trigger it when PC13 rises from 0 to 1. */
    EXTI->IMR |= (1U << 13);
    EXTI->RTSR |= (1U << 13);

    EXTI->PR = (1U << 13);
    NVIC_EnableIRQ(EXTI15_10_IRQn);

    while (1)
    {
        /* The CPU is free until a hardware event needs attention. */
    }
}
