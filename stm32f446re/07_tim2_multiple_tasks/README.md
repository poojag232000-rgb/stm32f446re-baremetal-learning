# STM32F446RE: Multiple Tasks From One Timer

## Goal

Use one 10 ms TIM2 interrupt as a simple scheduler for multiple independent time-based tasks.

## Tasks

- Toggle the onboard LED every 500 ms.
- Increment `seconds` every 1 second.

## Timing

```text
Timer interrupt period: 10 ms
50 ticks: 500 ms
100 ticks: 1 second
```

## Concepts practiced

- Multiple software counters driven by one hardware timer
- Independent periodic tasks
- `volatile` variables shared between an ISR and foreground code
- Basic cooperative scheduling concept

## Debugging check

Add `seconds` to CubeIDE's Expressions view, pause the target after several seconds, and verify that it has increased approximately once per second.
