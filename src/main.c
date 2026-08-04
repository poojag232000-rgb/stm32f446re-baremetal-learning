#include <stdint.h>

volatile uint32_t counter = 0;

int main(void)
{
    while (1) {
        counter++;
        __asm__("nop");
    }
    return 0;
}
