# STM32F446RE: Button Toggle With Software Debounce

## Goal

Toggle the green LED exactly once for each blue-button press.

## Concepts practiced

- Mechanical switch bounce
- Software debounce using a short delay and a second input check
- Waiting for a button release before accepting another press
- Bitwise XOR (`^=`) to toggle one output bit

## Result

Each press-and-release of the blue button changes the LED state once.

## Limitation

This is a beginner-friendly polling solution. The delay loops block the CPU, so the next lesson will introduce interrupts: hardware will notify the CPU when the button changes state.
