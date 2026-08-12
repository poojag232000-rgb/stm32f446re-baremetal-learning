#include <stdint.h>
#include "stm32f446xx.h"

int main(void)
{
    RCC->AHB1ENR |= (1U << 0); /* GPIOA clock */
    RCC->AHB1ENR |= (1U << 2); /* GPIOC clock */

    /* PA5 is an output for the onboard LED. */
    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |= (1U << 10);

    /* PC13 is an input from the onboard blue button. */
    GPIOC->MODER &= ~(3U << 26);

    while (1)
    {
        if (GPIOC->IDR & (1U << 13))
        {
            /* Let the mechanical button contact settle. */
            for (volatile uint32_t i = 0; i < 100000U; i++)
            {
            }

            if (GPIOC->IDR & (1U << 13))
            {
                /* XOR changes PA5 from 0 to 1 or from 1 to 0. */
                GPIOA->ODR ^= (1U << 5);

                /* A held button counts as one press. */
                while (GPIOC->IDR & (1U << 13))
                {
                }

                for (volatile uint32_t i = 0; i < 100000U; i++)
                {
                }
            }
        }
    }
}
