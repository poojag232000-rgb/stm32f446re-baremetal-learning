# Topic 2: GPIO and LED Blink

## 1. What is GPIO?
GPIO stands for General Purpose Input/Output.
It is the simplest way to interact with hardware.

You can use GPIO pins to:
- drive an LED
- read a button
- control a relay
- communicate with sensors

## 2. Why is GPIO important?
GPIO is the first practical topic in embedded systems because it teaches you how to:
- configure hardware pins
- write to output pins
- read input pins
- understand register-based programming

## 3. Basic GPIO idea
A GPIO pin can work in two main modes:
- output mode: the MCU drives the pin high or low
- input mode: the MCU reads the state of the pin

## 4. LED blink concept
To blink an LED:
1. configure the pin as output
2. set the pin high to turn LED on
3. delay for some time
4. set the pin low to turn LED off
5. repeat

## 5. Register-level understanding
In bare-metal programming, you often work with registers such as:
- data register
- direction register
- control register

These registers are memory-mapped, meaning they are accessed like normal memory locations.

## 6. Important embedded idea
In embedded systems, you are not just writing C logic.
You are controlling hardware through memory-mapped registers.

## 7. Practical example
A simple LED blink program does this:
- enable the clock for the GPIO port
- set the pin direction as output
- toggle the pin state
- wait

## 8. Interview-style summary
You can say:
- GPIO is used for basic digital input/output in embedded systems.
- In bare-metal firmware, GPIO pins are configured using memory-mapped registers.
- A simple LED blink example is the first step to understanding hardware control.
