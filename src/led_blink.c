#include <stdint.h>

volatile uint32_t counter = 0;

void delay(uint32_t time)
{
    while (time--) {
        __asm__("nop");
    }
}

int main(void)
{
    while (1) {
        counter++;
        delay(1000000);
    }
    return 0;
}
