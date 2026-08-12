# STM32F446RE: TIM2 Periodic Interrupt

## Goal

Use TIM2 to toggle the onboard LED once per second without a software delay loop.

## Clock calculation

With the reset clock configuration, TIM2 receives a 16 MHz clock.

```text
Counter frequency = 16,000,000 / (PSC + 1)
                  = 16,000,000 / 16,000
                  = 1,000 Hz

Update frequency  = 1,000 / (ARR + 1)
                  = 1,000 / 1,000
                  = 1 Hz
```

The update interrupt therefore occurs once each second.

## Concepts practiced

- TIM2 clock gate on APB1
- prescaler (`PSC`)
- auto-reload register (`ARR`)
- counter (`CNT`)
- update flag (`UIF`) in status register (`SR`)
- timer interrupt enable (`DIER`)
- NVIC interrupt enable
- timer ISR: `TIM2_IRQHandler`

## Debug proof

At a breakpoint in the ISR, `PSC` was 15999 and `ARR` was 999. `CNT` changed between stops, proving the timer was counting. The `UIF` flag was zero after it had been cleared in the ISR.

## Why use a timer?

The timer keeps accurate time in hardware while the CPU can perform other work. A software delay loop blocks the CPU and varies with compiler optimization and clock speed.
