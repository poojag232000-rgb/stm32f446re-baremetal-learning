# STM32F446RE: GPIO LED Blink

## Board

- NUCLEO-F446RE
- Onboard green LED (LD2) connected to PA5

## Goal

Blink the onboard LED using direct STM32 register access. No CubeMX-generated peripheral configuration and no HAL calls are used.

## Concepts practiced

- Peripheral clock enable with `RCC->AHB1ENR`
- GPIO pin mode with `GPIOA->MODER`
- GPIO output control with `GPIOA->ODR`
- Bit masks, shifts, `|=`, `&=`, and `~`
- Why a software-delay counter is declared `volatile`

## Result

The green LED turns on and off repeatedly after the program is built and flashed from STM32CubeIDE.

## Note

The delay loop is only a first experiment. Its timing depends on the compiler and clock speed, and it blocks the CPU. A hardware timer will replace it in a later lesson.
