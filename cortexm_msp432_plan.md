# Cortex-M4F Master Plan for MSP432E401Y

This is a practical one-day plan to move from “not very clear” to “interview-ready” on Cortex-M topics using an MSP432E401Y board.

## 1) What you should understand first

Your board is based on the Cortex-M4F architecture.

Key idea:
- Cortex-M4F = Cortex-M4 core + Floating Point Unit (FPU)
- It uses Thumb-2 instructions
- It has a vector table, exception model, NVIC, SysTick, and memory-mapped peripherals

You should be able to explain:
- What is the difference between ARM, Cortex-M, and STM32/MSP432?
- What is a vector table?
- What is the role of Reset_Handler?
- What is the difference between Flash, SRAM, and peripheral memory?
- What is the difference between MSP and PSP?
- Why interrupts are handled by the NVIC.

---

## 2) One-day topic-by-topic plan

### Topic 1: ARM and Cortex-M basics
What to learn:
- ARM architecture basics
- RISC vs CISC
- Thumb-2
- Cortex-M3/M4 differences
- Memory map basics

Practical work:
- Draw the memory map in your own words.
- Write a short note on why Cortex-M is used in embedded systems.

Interview point:
- “Cortex-M is popular because it gives low power, deterministic real-time behavior, and a compact ISA.”

---

### Topic 2: Startup code and linker script
What to learn:
- Vector table
- Reset_Handler
- .text, .data, .bss, .rodata
- Stack and heap
- Linker script basics

Practical work:
- Create a minimal bare-metal project with:
  - startup file
  - linker script
  - main.c
- Confirm that .data and .bss are initialized correctly.

Interview point:
- “The startup file sets up the stack, initializes memory sections, and jumps to main.”

---

### Topic 3: GPIO and basic I/O
What to learn:
- GPIO configuration
- Input/output modes
- Pull-up/pull-down
- Digital output and input

Practical work:
- Blink an onboard LED
- Read a push button and toggle LED
- Add a simple debouncing delay

Interview point:
- “GPIO is memory-mapped and configured using control registers.”

---

### Topic 4: Interrupts and NVIC
What to learn:
- Interrupt vs exception
- Vector table entries
- NVIC enable/disable
- Priority grouping
- Pending/active states

Practical work:
- Configure a button interrupt
- On each interrupt, toggle an LED and increment a counter
- Print the counter over UART

Interview point:
- “Interrupt latency depends on current execution, interrupt priority, and processor state.”

---

### Topic 5: SysTick timer
What to learn:
- SysTick registers
- Reload value
- Tick interrupt
- Delay generation

Practical work:
- Create a 1-second periodic task using SysTick
- Blink LED every second
- Use it for simple scheduler-style behavior

Interview point:
- “SysTick is often used as a simple RTOS tick or periodic scheduler.”

---

### Topic 6: UART communication
What to learn:
- UART configuration
- Baud rate
- TX/RX
- Polling vs interrupt-driven UART

Practical work:
- Send “Hello MSP432” over UART
- Echo back typed data from the terminal
- Print sensor values over UART

Interview point:
- “UART is widely used for debug logs, command interfaces, and sensor communication.”

---

### Topic 7: Timers and PWM
What to learn:
- Timer basics
- Compare match
- PWM generation
- Duty cycle and frequency

Practical work:
- Generate PWM to dim an LED
- Change brightness based on a variable or sensor input

Interview point:
- “PWM is used for motor control, LED brightness, and analog-like output.”

---

### Topic 8: ADC and sensor reading
What to learn:
- ADC channels
- Sampling and conversion
- Resolution and reference voltage
- Polling vs interrupt-based ADC

Practical work:
- Read a potentiometer or analog sensor value
- Convert it to LED brightness or UART output

Interview point:
- “ADC converts continuous analog signals into digital values for embedded control.”

---

### Topic 9: Faults and SCB basics
What to learn:
- HardFault, BusFault, MemManage
- SCB registers
- CFSR, HFSR, MMFAR, BFAR
- What a fault handler should do

Practical work:
- Create a simple HardFault trigger in a controlled way
- Implement a fault handler that logs the fault state

Interview point:
- “Fault analysis is important because embedded systems must be debugged under real hardware constraints.”

---

### Topic 10: Stack, context switching, and MSP vs PSP
What to learn:
- MSP vs PSP
- Thread mode vs Handler mode
- Stack frame basics
- Why RTOS uses PSP

Practical work:
- Write notes explaining the difference between the two stacks
- Understand how an exception saves context

Interview point:
- “MSP is used by the kernel/handler mode, while PSP is used by user tasks in RTOS systems.”

---

### Topic 11: CMSIS and driver style
What to learn:
- CMSIS core headers
- NVIC and SysTick CMSIS APIs
- Why CMSIS improves portability

Practical work:
- Rewrite one driver using CMSIS-like access patterns

Interview point:
- “CMSIS makes firmware more portable and easier to maintain across Cortex-M devices.”

---

### Topic 12: Low power and real-world embedded concepts
What to learn:
- Sleep modes
- WFI/WFE
- Why low power matters

Practical work:
- Put the MCU in sleep mode and wake it up using an interrupt

Interview point:
- “Low-power design is critical in battery-operated and industrial embedded products.”

---

## 3) Final project idea (portfolio-level)

### Project: Smart Embedded Sensor Gateway on MSP432E401Y

This project is good because it covers many Cortex-M topics in one real system.

### Features
- Blink status LED using GPIO
- Read sensor data from ADC
- Control LED brightness using PWM
- Send logs and sensor values over UART
- Use interrupts for a push-button or external event
- Use SysTick for periodic tasks
- Implement a fault handler for debugging
- Use a simple state machine

### Project flow
1. Boot sequence starts and initializes peripherals
2. GPIO toggles a status LED
3. SysTick triggers every 100 ms
4. ADC reads an analog input each second
5. PWM updates LED brightness based on the sensor value
6. UART prints sensor data and system status
7. Button interrupt changes system mode: normal / alert / calibration

### Why this is a strong portfolio project
It looks like real embedded work because it includes:
- Bare-metal firmware structure
- Peripheral drivers
- Interrupt-driven design
- Timing and scheduling
- Sensor interfacing
- Debugging and fault handling

### Project folder structure
- src/main.c
- src/startup.c
- src/system.c
- src/interrupts.c
- src/gpio.c
- src/uart.c
- src/adc.c
- src/pwm.c
- src/systick.c
- ld/linker.ld
- include/*.h

---

## 4) What to say in your resume

Use bullets like these:

- Developed a bare-metal Cortex-M4F firmware project on MSP432E401Y covering startup initialization, linker configuration, GPIO, UART, ADC, PWM, SysTick, and interrupt handling.
- Implemented interrupt-driven peripheral drivers and a state-machine-based control loop for sensor monitoring and LED control.
- Built a modular embedded firmware architecture with separate driver layers for GPIO, UART, ADC, PWM, and system timing.
- Designed and debugged low-level firmware using vector table, startup code, fault handling, and register-level programming.
- Gained hands-on experience with embedded C, memory-mapped registers, interrupt latency, and real-time task scheduling concepts.

If you want a stronger “3 years experience” style version, use this:

- Designed and delivered embedded firmware for a Cortex-M4F microcontroller platform, implementing robust low-level drivers and real-time control logic for sensor-based applications.
- Worked on bare-metal firmware development from startup initialization through peripheral abstraction, improving reliability, maintainability, and debugging visibility.
- Built interrupt-driven applications and timing-based control systems for industrial-style embedded use cases.

---

## 5) Keywords to include

Use these keywords in your resume and LinkedIn:

- Cortex-M4F
- ARMv7E-M
- Thumb-2
- Bare-metal firmware
- Embedded C
- MSP432E401Y
- GPIO
- UART
- ADC
- PWM
- SysTick
- NVIC
- Interrupts
- Vector table
- Startup code
- Linker script
- Memory-mapped registers
- Fault handling
- SCB
- Low-power embedded design
- Real-time systems
- Peripheral drivers
- Firmware development
- Debugging
- Embedded systems

---

## 6) Interview-ready explanation template

You can answer questions like this:

### Q1: What is the vector table?
Answer:
- The vector table is a table of exception and interrupt handlers.
- The processor uses it to jump to the correct handler when an exception or interrupt occurs.
- On Cortex-M, the first entry is the initial stack pointer and the second entry is the reset handler.

### Q2: Why do we need a startup file?
Answer:
- The startup file sets up the stack, initializes .data and .bss, and calls main.
- It prepares the system before your C code runs.

### Q3: What is the difference between MSP and PSP?
Answer:
- MSP is the main stack pointer and is usually used by the kernel or handler mode.
- PSP is the process stack pointer and is commonly used by tasks in RTOS systems.

### Q4: What is the role of the NVIC?
Answer:
- The NVIC manages interrupts and exceptions.
- It enables/disables interrupts, sets priorities, and handles pending states.

### Q5: What is SysTick used for?
Answer:
- SysTick is a simple timer used for periodic tasks, delays, and RTOS scheduling.

---

## 7) Suggested learning order for today

### Morning
1. Cortex-M basics
2. Startup and linker
3. GPIO and LED blink

### Afternoon
4. UART and debug prints
5. Interrupts and NVIC
6. SysTick and timers

### Evening
7. ADC and PWM
8. Fault handling and SCB basics
9. Build your project and prepare resume bullets

---

## 8) Final advice

If you want to look strong in interviews, do not just say “I studied Cortex-M.”
Say:
- “I built a Cortex-M4F firmware project from scratch on MSP432E401Y.”
- “I implemented startup code, GPIO, UART, ADC, PWM, interrupts, and SysTick.”
- “I understand the vector table, NVIC, system initialization, and fault handling.”

That sounds much stronger than just listing topics.
