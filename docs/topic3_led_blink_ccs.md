# Topic 3: LED Blink in CCS Style

## Goal
Build a simple LED blink program for the MSP432E401Y board using a CCS-style bare-metal workflow.

## What the program does
- configures a GPIO pin as output
- turns the LED on
- waits for a short time
- turns the LED off
- repeats forever

## CCS workflow
1. Create a CCS project for the target MCU
2. Add the source files
3. Build the project
4. Flash it to the board
5. Run or debug it on hardware

## Minimal program idea
The firmware will:
- set the LED pin as output
- toggle the pin state
- use a simple delay loop

## Important note
In CCS, you do not run the program like a normal desktop app. You build, flash, and run it on the target board.
