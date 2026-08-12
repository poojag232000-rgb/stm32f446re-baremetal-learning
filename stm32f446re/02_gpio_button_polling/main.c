#include <stdint.h>
#include "stm32f446xx.h"

int main(void)
{
    /* Enable clocks for GPIO ports A and C. */
    RCC->AHB1ENR |= (1U << 0);
    RCC->AHB1ENR |= (1U << 2);

    /* PA5 is the onboard green LED: output mode (MODER[11:10] = 01). */
    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |= (1U << 10);

    /* PC13 is the onboard blue button: input mode (MODER[27:26] = 00). */
    GPIOC->MODER &= ~(3U << 26);

    while (1)
    {
        if (GPIOC->IDR & (1U << 13))
        {
            GPIOA->ODR |= (1U << 5);
        }
        else
        {
            GPIOA->ODR &= ~(1U << 5);
        }
    }
}
