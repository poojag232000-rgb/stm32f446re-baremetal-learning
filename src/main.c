#include <stdint.h>

#define GPIO_PORT_P1_BASE 0x40004C00U
#define GPIO_DIR_OFFSET    0x04U
#define GPIO_OUT_OFFSET    0x02U

#define P1DIR (*(volatile uint8_t *)(GPIO_PORT_P1_BASE + GPIO_DIR_OFFSET))
#define P1OUT (*(volatile uint8_t *)(GPIO_PORT_P1_BASE + GPIO_OUT_OFFSET))

void delay(volatile uint32_t count)
{
    while (count--) {
        __asm__("nop");
    }
}

int main(void)
{
    // Configure P1.0 as output for the MSP432E401Y onboard LED
    P1DIR |= 0x01;

    while (1) {
        P1OUT |= 0x01;  // LED on
        delay(100000);
        P1OUT &= ~0x01; // LED off
        delay(100000);
    }
    return 0;
}
