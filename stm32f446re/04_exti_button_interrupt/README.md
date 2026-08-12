# STM32F446RE: Button External Interrupt

## Goal

Toggle the onboard LED in response to a button press without polling PC13 in the main loop.

## Interrupt flow

```text
PC13 rising edge -> EXTI line 13 -> NVIC -> EXTI15_10_IRQHandler() -> LED toggle
```

## Concepts practiced

- External interrupt/event controller (EXTI)
- System configuration controller (SYSCFG) pin-to-EXTI routing
- Interrupt mask register (`IMR`)
- Rising-trigger selection register (`RTSR`)
- Pending register (`PR`) and write-one-to-clear behavior
- Nested Vectored Interrupt Controller (NVIC)
- Interrupt handler / interrupt service routine (ISR)

## Important detail

EXTI lines 10 through 15 share one interrupt handler, so line 13 uses `EXTI15_10_IRQHandler`.

## Limitation

A mechanical button can bounce and create more than one rising edge. The next lesson will debounce it without using a blocking delay inside the ISR.
