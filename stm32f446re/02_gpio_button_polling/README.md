# STM32F446RE: GPIO Button Polling

## Board connections

- NUCLEO-F446RE blue user button B1: PC13
- NUCLEO-F446RE green onboard LED LD2: PA5

## Goal

Read the state of PC13 repeatedly and turn the LED on while the blue button is held.

## Concepts practiced

- GPIO input mode (`00` in `MODER`)
- GPIO output mode (`01` in `MODER`)
- GPIO input-data register (`IDR`)
- `if` / `else` program flow
- Bit-test expression: `GPIOC->IDR & (1U << 13)`
- Polling: the CPU continually checks an input in the `while (1)` loop

## Result

Holding the blue button turns the green LED on. Releasing it turns the LED off.

## Next improvement

Polling keeps the CPU repeatedly checking the button. A GPIO interrupt will let the hardware notify the CPU only when the button state changes.
