# Topic 3: CCS-style MSP432E401Y LED Blink

## 1. What you need in CCS
For a CCS bare-metal project, you need:
- a C source file (`src/main.c`)
- a startup file (`src/startup.c`)
- a linker script (`ld/linker.ld`)
- a project settings file inside CCS (managed by CCS)

## 2. MSP432E401Y board-specific LED example
On MSP432E401Y, the board LED is usually connected to a GPIO pin such as P1.0 or the specific kit LED pin.

Simplified steps:
1. Enable the GPIO peripheral clock
2. Configure the LED pin as output
3. Toggle the pin
4. Use delay loops

## 3. Code structure
This example uses bare-metal register access.

### src/main.c
```c
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
```

## 4. Notes
- This code is a board-level LED blink and is already placed in `src/main.c`.
- The actual P1.0 address is based on the MSP432 GPIO register map.
- In CCS, create a new project, add `src/main.c`, `src/startup.c`, and `ld/linker.ld`, then build and run the image on the MSP432E401Y.

## 5. What to do next
- Create a new CCS project for MSP432E401Y.
- Add `src/main.c`, `src/startup.c`, and `ld/linker.ld`.
- Build and debug on the hardware.
