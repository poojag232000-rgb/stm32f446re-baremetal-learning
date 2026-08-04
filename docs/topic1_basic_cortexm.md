# Topic 1: Basics of Cortex-M and Bare-Metal Startup

## 1. What is Cortex-M?
Cortex-M is a family of 32-bit ARM processors designed for embedded systems.
They are used in microcontrollers because they are:
- low power
- real-time
- efficient
- suitable for small and medium embedded products

Cortex-M4F is a popular version because it includes:
- Cortex-M4 core
- Floating Point Unit (FPU)
- good performance for control applications

## 2. What is bare-metal programming?
Bare-metal programming means you write firmware without an operating system.
You directly control the hardware using registers and low-level code.

This means you must understand:
- startup code
- memory layout
- interrupts
- peripherals
- linker behavior

## 3. What happens when the board powers on?
When the MCU starts, the processor does this:
1. reads the initial stack pointer from the vector table
2. jumps to the reset handler
3. startup code runs
4. .data is copied to SRAM
5. .bss is zeroed
6. main() is called

This is the basic boot sequence of a Cortex-M system.

## 4. What is the vector table?
The vector table is a table of addresses used by the CPU for exceptions and interrupts.
The first entries are usually:
- initial stack pointer
- reset handler
- NMI handler
- HardFault handler

## 5. Why do we need startup code?
Startup code prepares the system before your C program can run.
It usually:
- sets the stack pointer
- copies initialized global variables to RAM
- initializes uninitialized variables to zero
- calls main()

## 6. Why do we need a linker script?
The linker script tells the linker:
- where code and data should be placed in memory
- which sections belong to FLASH or SRAM
- where the stack should be placed

Without a linker script, the program may not know how to place its sections correctly on the target MCU.

## 7. Memory sections you should know
- .text: program code
- .rodata: read-only data
- .data: initialized global/static variables
- .bss: uninitialized global/static variables

## 8. Very important idea
Cortex-M code is not like a normal PC program.
You are not running under an OS.
You are directly controlling the hardware from reset until the program ends.

## 9. Practical understanding
For your MSP432E401Y board, this means:
- your code is placed in flash
- your variables may live in SRAM
- startup code bridges the gap between hardware reset and your main function

## 10. Interview-style summary
You can say:
- Cortex-M is a family of ARM processors optimized for embedded real-time systems.
- Bare-metal programming means writing firmware without an OS and directly controlling hardware.
- The startup code and linker script are essential because they prepare memory and hand control to main().
