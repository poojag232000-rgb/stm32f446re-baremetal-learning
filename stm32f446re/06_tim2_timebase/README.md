# STM32F446RE: TIM2 10 ms Time Base

## Goal

Create a periodic hardware time base, then use a software counter to run a task every 500 ms.

## Timing calculation

```text
TIM2 source clock = 16 MHz
PSC = 15999       -> counter ticks every 1 ms
ARR = 9           -> update event every 10 ticks = 10 ms
```

The interrupt increments `ticks` every 10 ms. When it reaches 50, the LED is toggled.

```text
50 x 10 ms = 500 ms
```

## Concepts practiced

- Periodic timer interrupt as a system time base
- `volatile` shared variable updated in an interrupt
- Software scheduling by counting hardware timer ticks
- Separating a timer's tick interval from an application's task interval

## Result

The green LED toggles every 500 ms without software delay loops.
