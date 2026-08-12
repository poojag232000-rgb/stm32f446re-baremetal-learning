#include <stdint.h>
#include "stm32f446xx.h"

int main(void)
{
    /* Enable the peripheral clock for GPIO port A. */
    RCC->AHB1ENR |= (1U << 0);

    /* PA5 drives the NUCLEO-F446RE onboard green LED.
       Its GPIO mode bits are MODER[11:10]; 01 means output. */
    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |= (1U << 10);

    while (1)
    {
        GPIOA->ODR |= (1U << 5);
        for (volatile uint32_t i = 0; i < 1000000U; i++)
        {
        }

        GPIOA->ODR &= ~(1U << 5);
        for (volatile uint32_t i = 0; i < 1000000U; i++)
        {
        }
    }
}
